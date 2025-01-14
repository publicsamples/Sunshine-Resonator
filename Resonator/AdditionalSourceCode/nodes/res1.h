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

namespace res1_impl
{
// ==============================| Node & Parameter type declarations |==============================

using stereo_cable = cable::block<2>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, jdsp::jdelay<NV>>, 
                                   fx::phase_delay<NV>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<2, jdsp::jdelay<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<2, fx::phase_delay<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain15_t<NV>>, 
                                  chain16_t<NV>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::fix_delay>, 
                                   split1_t<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<2, core::fix_delay>, 
                                    chain13_t<NV>, 
                                    chain14_t<NV>>;

using comp_t = wrap::no_data<dynamics::comp>;
template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<comp_t, 0>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, routing::receive<stereo_cable>>, 
                                  branch3_t<NV>, 
                                  filters::one_pole<NV>, 
                                  minmax_t<NV>, 
                                  comp_t, 
                                  routing::send<stereo_cable>, 
                                  core::gain<NV>>;

template <int NV>
using dynamic_blocksize1_t_ = container::chain<parameter::empty, 
                                               wrap::fix<2, chain5_t<NV>>>;

template <int NV>
using dynamic_blocksize1_t = wrap::dynamic_blocksize<dynamic_blocksize1_t_<NV>>;

namespace res1_t_parameters
{
// Parameter list for res1_impl::res1_t ------------------------------------------------------------

DECLARE_PARAMETER_RANGE_SKEW(Del_InputRange, 
                             0., 
                             1000., 
                             0.30103);
DECLARE_PARAMETER_RANGE_SKEW(Del_0Range, 
                             0., 
                             1000., 
                             0.30103);

using Del_0 = parameter::from0To1<core::fix_delay, 
                                  0, 
                                  Del_0Range>;

DECLARE_PARAMETER_RANGE_SKEW(Del_1Range, 
                             0., 
                             1000., 
                             0.30103);

template <int NV>
using Del_1 = parameter::from0To1<jdsp::jdelay<NV>, 
                                  1, 
                                  Del_1Range>;

using Del_2 = Del_0;

template <int NV> using Del_3 = Del_1<NV>;

template <int NV>
using Del = parameter::chain<Del_InputRange, 
                             Del_0, 
                             Del_1<NV>, 
                             Del_2, 
                             Del_3<NV>>;

using feed = parameter::plain<routing::receive<stereo_cable>, 
                              0>;
template <int NV>
using Block = parameter::plain<res1_impl::dynamic_blocksize1_t<NV>, 
                               0>;
template <int NV>
using LP = parameter::plain<filters::one_pole<NV>, 0>;
template <int NV>
using FbModifier = parameter::plain<fx::phase_delay<NV>, 0>;
template <int NV> using Freq = FbModifier<NV>;
template <int NV>
using Mode = parameter::plain<res1_impl::branch3_t<NV>, 
                              0>;
template <int NV>
using Comp = parameter::plain<res1_impl::minmax_t<NV>, 
                              0>;
template <int NV>
using ga = parameter::plain<core::gain<NV>, 0>;
template <int NV>
using res1_t_plist = parameter::list<feed, 
                                     Del<NV>, 
                                     Block<NV>, 
                                     LP<NV>, 
                                     FbModifier<NV>, 
                                     Freq<NV>, 
                                     Mode<NV>, 
                                     Comp<NV>, 
                                     ga<NV>>;
}

template <int NV>
using res1_t_ = container::chain<res1_t_parameters::res1_t_plist<NV>, 
                                 wrap::fix<2, dynamic_blocksize1_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public res1_impl::res1_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(res1);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(138)
		{
			0x005B, 0x0000, 0x6600, 0x6565, 0x0064, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x015B, 
            0x0000, 0x4400, 0x6C65, 0x0000, 0x0000, 0x0000, 0x7A00, 0x0044, 
            0x0000, 0x9B40, 0x9A20, 0xCD3E, 0xCCCC, 0x5B3D, 0x0002, 0x0000, 
            0x6C42, 0x636F, 0x006B, 0x0000, 0x0000, 0x0000, 0x40E0, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x035B, 0x0000, 0x4C00, 
            0x0050, 0x0000, 0x41A0, 0x4000, 0x469C, 0x2E6A, 0x45EE, 0x6C1A, 
            0x3E6B, 0x0000, 0x0000, 0x045B, 0x0000, 0x4600, 0x4D62, 0x646F, 
            0x6669, 0x6569, 0x0072, 0x0000, 0x41A0, 0x4000, 0x469C, 0x6667, 
            0x43D9, 0x6C1A, 0x3E6B, 0xCCCD, 0x3DCC, 0x055B, 0x0000, 0x4600, 
            0x6572, 0x0071, 0x0000, 0x41A0, 0x4000, 0x469C, 0xB19A, 0x452B, 
            0x6C1A, 0x3E6B, 0xCCCD, 0x3DCC, 0x065B, 0x0000, 0x4D00, 0x646F, 
            0x0065, 0x0000, 0x0000, 0x0000, 0x4000, 0x0000, 0x4000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x075B, 0x0000, 0x4300, 0x6D6F, 0x0070, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x2164, 0x3EE7, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x085B, 0x0000, 0x6700, 0x0061, 0x0000, 0xC2C8, 
            0x0000, 0x0000, 0x9998, 0xC151, 0x833E, 0x40AD, 0xCCCD, 0x3DCC, 
            0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& dynamic_blocksize1 = this->getT(0);                                           // res1_impl::dynamic_blocksize1_t<NV>
		auto& chain5 = this->getT(0).getT(0);                                               // res1_impl::chain5_t<NV>
		auto& receive = this->getT(0).getT(0).getT(0);                                      // routing::receive<stereo_cable>
		auto& branch3 = this->getT(0).getT(0).getT(1);                                      // res1_impl::branch3_t<NV>
		auto& fix_delay = this->getT(0).getT(0).getT(1).getT(0);                            // core::fix_delay
		auto& chain13 = this->getT(0).getT(0).getT(1).getT(1);                              // res1_impl::chain13_t<NV>
		auto& jdelay2 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                      // jdsp::jdelay<NV>
		auto& phase_delay1 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                 // fx::phase_delay<NV>
		auto& chain14 = this->getT(0).getT(0).getT(1).getT(2);                              // res1_impl::chain14_t<NV>
		auto& fix_delay3 = this->getT(0).getT(0).getT(1).getT(2).getT(0);                   // core::fix_delay
		auto& split1 = this->getT(0).getT(0).getT(1).getT(2).getT(1);                       // res1_impl::split1_t<NV>
		auto& chain15 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0);              // res1_impl::chain15_t<NV>
		auto& jdelay3 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(0);      // jdsp::jdelay<NV>
		auto& gain2 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(1);        // core::gain<NV>
		auto& chain16 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(1);              // res1_impl::chain16_t<NV>
		auto& phase_delay3 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(1).getT(0); // fx::phase_delay<NV>
		auto& gain3 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(1).getT(1);        // core::gain<NV>
		auto& one_pole145 = this->getT(0).getT(0).getT(2);                                  // filters::one_pole<NV>
		auto& minmax = this->getT(0).getT(0).getT(3);                                       // res1_impl::minmax_t<NV>
		auto& comp = this->getT(0).getT(0).getT(4);                                         // res1_impl::comp_t
		auto& send2 = this->getT(0).getT(0).getT(5);                                        // routing::send<stereo_cable>
		auto& gain = this->getT(0).getT(0).getT(6);                                         // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, receive); // feed -> receive::Feedback
		
		auto& Del_p = this->getParameterT(1);
		Del_p.connectT(0, fix_delay);  // Del -> fix_delay::DelayTime
		Del_p.connectT(1, jdelay2);    // Del -> jdelay2::DelayTime
		Del_p.connectT(2, fix_delay3); // Del -> fix_delay3::DelayTime
		Del_p.connectT(3, jdelay3);    // Del -> jdelay3::DelayTime
		
		this->getParameterT(2).connectT(0, dynamic_blocksize1); // Block -> dynamic_blocksize1::BlockSize
		
		this->getParameterT(3).connectT(0, one_pole145); // LP -> one_pole145::Frequency
		
		this->getParameterT(4).connectT(0, phase_delay3); // FbModifier -> phase_delay3::Frequency
		
		this->getParameterT(5).connectT(0, phase_delay1); // Freq -> phase_delay1::Frequency
		
		this->getParameterT(6).connectT(0, branch3); // Mode -> branch3::Index
		
		this->getParameterT(7).connectT(0, minmax); // Comp -> minmax::Value
		
		this->getParameterT(8).connectT(0, gain); // ga -> gain::Gain
		
		// Modulation Connections ------------------------------------------------------------------
		
		minmax.getWrappedObject().getParameter().connectT(0, comp); // minmax -> comp::Threshhold
		
		// Send Connections ------------------------------------------------------------------------
		
		send2.connect(receive);
		
		// Default Values --------------------------------------------------------------------------
		
		; // dynamic_blocksize1::BlockSize is automated
		
		; // receive::Feedback is automated
		
		; // branch3::Index is automated
		
		;                               // fix_delay::DelayTime is automated
		fix_delay.setParameterT(1, 0.); // core::fix_delay::FadeTime
		
		jdelay2.setParameterT(0, 1000.); // jdsp::jdelay::Limit
		;                                // jdelay2::DelayTime is automated
		
		; // phase_delay1::Frequency is automated
		
		;                                   // fix_delay3::DelayTime is automated
		fix_delay3.setParameterT(1, 1024.); // core::fix_delay::FadeTime
		
		jdelay3.setParameterT(0, 1000.); // jdsp::jdelay::Limit
		;                                // jdelay3::DelayTime is automated
		
		gain2.setParameterT(0, -7.9); // core::gain::Gain
		gain2.setParameterT(1, 20.);  // core::gain::Smoothing
		gain2.setParameterT(2, 0.);   // core::gain::ResetValue
		
		; // phase_delay3::Frequency is automated
		
		gain3.setParameterT(0, -4);  // core::gain::Gain
		gain3.setParameterT(1, 20.); // core::gain::Smoothing
		gain3.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                   // one_pole145::Frequency is automated
		one_pole145.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole145.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole145.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole145.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole145.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                 // minmax::Value is automated
		minmax.setParameterT(1, -100.);   // control::minmax::Minimum
		minmax.setParameterT(2, 0.);      // control::minmax::Maximum
		minmax.setParameterT(3, 5.42227); // control::minmax::Skew
		minmax.setParameterT(4, 0.1);     // control::minmax::Step
		minmax.setParameterT(5, 1.);      // control::minmax::Polarity
		
		;                             // comp::Threshhold is automated
		comp.setParameterT(1, 25.9);  // dynamics::comp::Attack
		comp.setParameterT(2, 109.7); // dynamics::comp::Release
		comp.setParameterT(3, 2.8);   // dynamics::comp::Ratio
		comp.setParameterT(4, 0.);    // dynamics::comp::Sidechain
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 2);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 7621.8);
		this->setParameterT(4, 434.8);
		this->setParameterT(5, 2747.1);
		this->setParameterT(6, 2.);
		this->setParameterT(7, 0.451427);
		this->setParameterT(8, -13.);
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
		
		this->getT(0).getT(0).getT(4).setExternalData(b, index); // res1_impl::comp_t
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
using res1 = wrap::node<res1_impl::instance<NV>>;
}


