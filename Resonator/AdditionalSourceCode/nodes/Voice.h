#pragma once

// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace Voice_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV> struct OneShot
{
	// This node will implement a file playback using some of the
	// more complex classes in SNEX to implement
	// - polyphony
	// - interpolation
	SNEX_NODE(OneShot);
	// We're using the Index types from SNEX for the
	// buffer lookup. We want to clamp the index to the upper
	// position so that it will not loop
	using IndexType = index::clamped<0, false>;
	// Now we convert it to an unscaled double precision float
	// index (you could also switch to normalized 0...1 domain here
	// but we want the actual sample indexes from 0...sample end)
	using FloatIndex = index::unscaled<double, IndexType>;
	// with a floating point index we can add another wrapper that
	// automatically performs interpolation at the []-operator access
	// (here we're using linear interpolation, but you could also use
	//  cubic (with index::hermite) or none if you simply use the type
	//  from above)
	using InterpolatorType = index::lerp<FloatIndex>;
	// Let's assume stereo processing (mono samples will be converted to
	// dual mono on loading)
	static const int NUM_CHANNELS = 2;
	// This holds a reference to the external data object
	// and will be used to lock the data buffer during rendering
	// (so that it will not reload the sample and play it back at the
	//  same time).
	ExternalData data;
	// This will hold the sample data as multidimensional array of float
	// numbers
	span<dyn<float>, NUM_CHANNELS> sample;
	double sr = 0.0;
	double file_sr = 0.0;
	// Now we define our voice data model.
	struct VoiceData
	{
		// We need the current sample position
		double uptime = 0.0;
		// And the playback speed (how much the counter should increase
		// per sample).
		double delta = 0.01;
		// We'll call this from the reset callback of the note
		// This is being called whenever a new voice is started so
		// we need to reset the playback position.
		void reset()
		{
			uptime = 0.0;
		}
		double bump()
		{
			const auto rv = uptime;
			uptime += delta;
			return rv;
		}
	};
	// The polydata template will duplicate the voice data model
	// defined above for each voice. This allows you to use stateful
	// voice variables to implement polyphony (in our example, the uptime
	// needs to be at different positions when multiple voices are played)
	PolyData<VoiceData, NV> voiceData;
	void prepare(PrepareSpecs ps)
	{
		// The PolyData object needs to be initialised here
		// (it grabs the voice index from the ps object to handle
		//  all the voice allocation logic)
		voiceData.prepare(ps);
		sr = ps.sampleRate;
	}
	// Reset the processing pipeline here
	void reset()
	{
		for(auto& v: voiceData)
			v.reset();
	}
	// This function will be called by both processFrame and the normal
	// process callback and do the actual calculation. The reason we
	// split this up and not only call processFrame directly from process
	// is because there is some overhead involved with locking the data
	// and fetching the voice data for the currently rendered voice.
	//
	// All the book-keeping and error checks are done in the outer functions
	// so we can concentrate on the actual logic in this method
	void processInternal(span<float, NUM_CHANNELS>& fd, VoiceData& v)
	{
		const auto thisUptime = v.bump();
		InterpolatorType idx(thisUptime);
		for(int i = 0; i < NUM_CHANNELS; i++)
		{
			// we just write the sample content to the audio buffer
			// Note how the interpolation is neatly wrapped behind
			// a single []-access!
			fd[i] = sample[i][idx];
		}
	}
	// Here we lock the data and grab the voice once per buffer callback
	// These are not trivial operations so being able to shuffle them
	// outside of the main loop will be much more efficient.
	template <typename ProcessDataType> void process(ProcessDataType& pd)
	{
		// if the data is empty there's nothing to do...
		if(data.numSamples == 0)
			return;
		// The DataReadLock object will synchronise access to the sample
		// resource
		DataReadLock sl(data);
		// fetch the voice data for the current object.
		auto& v = voiceData.get();
		// Now we use the frame processor object for
		// interleaved processing of the channels (so that)
		// we have to calculate the index only once per frame
		auto fd = pd.toFrameData();
		// The frame processor converts the multichannel audio signal
		// into chunks of interleaved samples and processes it on a
		// frame basis
		while(fd.next())
		{
			// Forward to the internal processing method.
			processInternal(fd.toSpan(), v);
		}
		// This updates the playback position ruler on the UI
		data.setDisplayedValue(v.uptime);
		// Now we check if the sample is played all the way through
		auto isPlaying = (int)v.uptime <= data.numSamples;
		// And set the gate that will send out the mod signal
		// (this will internally check if the value changed and only
		// send the message in handleModulation when there's a change).
		gate.setModValueIfChanged((double)isPlaying);
	}
	// Here we lock the data and grab the voice once per sample.
	// This is not ideal from a performance perspective, but you most
	// likely do not need to call this on a sample basis anyways.
	void processFrame(span<float, NUM_CHANNELS>& fd)
	{
		if(data.numSamples == 0)
			return;
		DataReadLock sl(data);
		auto& v = voiceData.get();
		processInternal(fd, v);
	}
	// Process the MIDI events here
	void handleHiseEvent(HiseEvent& e)
	{
	}
	// Use this function to setup the external data
	void setExternalData(const ExternalData& ed, int index)
	{
		data = ed;
		ed.referBlockTo(sample[0], 0);
		ed.referBlockTo(sample[1], 1);
		if(data.numSamples > 0 && sr != 0.0)
		{
			const auto delta = data.sampleRate / sr;
			for(auto& v: voiceData)
			{
				v.delta = delta;
			}
		}
	}
	// Now we implement the logic that sends a gate message to
	// the outside world when the sample has finished playing.
	ModValue gate;
	// As soon as you define this callback, SNEX will pick it up and
	// add a modulation dragger. This callback is then executed after
	// each process call and lets you send out a modulation value
	// by returning true and setting the value reference to the value
	// you want to send out.
	bool handleModulation(double& value)
	{
		// The ModValue class is a helper tool that nicely fits into
		// this concept so you just need to call this one function here
		return gate.getChangedValue(value);
	}
	// Set the parameters here
	template <int P> void setParameter(double v)
	{
	}
};

template <int NV>
using snex_node_t = wrap::mod<parameter::plain<envelope::voice_manager, 0>, 
                              wrap::data<OneShot<NV>, data::external::audiofile<0>>>;
template <int NV>
using repitch_t_ = container::chain<parameter::empty, 
                                    wrap::fix<2, snex_node_t<NV>>, 
                                    envelope::voice_manager>;

template <int NV>
using repitch_t = wrap::repitch<repitch_t_<NV>, interpolators::dynamic>;
template <int NV>
using converter_t = control::converter<parameter::plain<repitch_t<NV>, 0>, 
                                       conversion_logic::st2pitch>;

namespace Voice_t_parameters
{
}

template <int NV>
using Voice_t_ = container::chain<parameter::plain<Voice_impl::converter_t<NV>, 0>, 
                                  wrap::fix<2, converter_t<NV>>, 
                                  repitch_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public Voice_impl::Voice_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 1;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(Voice);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(18)
		{
			0x005B, 0x0000, 0x7400, 0x6172, 0x736E, 0x6F70, 0x6573, 0x0000, 
            0x4000, 0x00C1, 0x4000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x003F
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& converter = this->getT(0);             // Voice_impl::converter_t<NV>
		auto& repitch = this->getT(1);               // Voice_impl::repitch_t<NV>
		auto& snex_node = this->getT(1).getT(0);     // Voice_impl::snex_node_t<NV>
		auto& voice_manager = this->getT(1).getT(1); // envelope::voice_manager
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, converter); // transpose -> converter::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		snex_node.getParameter().connectT(0, voice_manager);              // snex_node -> voice_manager::KillVoice
		converter.getWrappedObject().getParameter().connectT(0, repitch); // converter -> repitch::RepitchFactor
		
		// Default Values --------------------------------------------------------------------------
		
		; // converter::Value is automated
		
		;                             // repitch::RepitchFactor is automated
		repitch.setParameterT(1, 0.); // container::chain::Interpolation
		
		; // voice_manager::KillVoice is automated
		
		this->setParameterT(0, 1.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(1).getT(0).setExternalData(b, index); // Voice_impl::snex_node_t<NV>
	}
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ======================================| Public Definition |======================================

namespace project
{
// polyphonic template declaration

template <int NV>
using Voice = wrap::node<Voice_impl::instance<NV>>;
}


