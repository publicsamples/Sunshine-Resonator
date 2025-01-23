template <int NV> struct OneShot
{
    SNEX_NODE(OneShot);

    using IndexType = index::clamped<0, false>;
    using FloatIndex = index::unscaled<double, IndexType>;
    using InterpolatorType = index::lerp<FloatIndex>;

    static const int NUM_CHANNELS = 2;

    ExternalData data;
    span<dyn<float>, NUM_CHANNELS> sample;

    double sr = 0.0;
    double file_sr = 0.0;
    double pitch = 0.5;
    bool loop = 0;

    struct VoiceData
    {
        double uptime = 0.0;
        double delta = 0.01;

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

    PolyData<VoiceData, NV> voiceData;

    void prepare(PrepareSpecs ps)
    {
        voiceData.prepare(ps);
        sr = ps.sampleRate;
    }

    void reset()
    {
        for(auto& v: voiceData)
            v.reset();
    }

    float bitcrush(float sample, int bitDepth) {
        int maxLevel = (1 < bitDepth) - 1;
        return sample;
    }

    void processInternal(span<float, NUM_CHANNELS>& fd, VoiceData& v)
    {
        const auto thisUptime = v.bump();

        if (thisUptime >= data.numSamples) 
        {
            if (loop) {
                v.reset(); // Reset uptime to 0 for looping
            } else {
                return; // Stop processing this voice if not looping
            }
        }

        InterpolatorType idx(thisUptime);

        for(int i = 0; i < NUM_CHANNELS; i++)
        {
            float sampleValue = sample[i][idx];
            fd[i] = sampleValue;
        }
    }

    template <typename ProcessDataType> void process(ProcessDataType& pd)
    {
        if(data.numSamples == 0)
            return;

        DataReadLock sl(data);
        auto& v = voiceData.get();
        auto fd = pd.toFrameData();

        while(fd.next())
        {
            processInternal(fd.toSpan(), v);
        }

        data.setDisplayedValue(v.uptime);
        auto isPlaying = (int)v.uptime <= data.numSamples;
        gate.setModValueIfChanged((double)isPlaying);
    }

    void processFrame(span<float, NUM_CHANNELS>& fd)
    {
        if(data.numSamples == 0)
            return;

        DataReadLock sl(data);        
        auto& v = voiceData.get();
        processInternal(fd, v);
    }

    void handleHiseEvent(HiseEvent& e)
    {
    }

    void updateDelta()
    {    
        double semitones = (pitch - 0.5) * 48.0;
        double pitch_mult = Math.pow(2.0, semitones / 12.0);

        if (data.numSamples > 0 && sr != 0.0) {
            const auto newDelta = (data.sampleRate / sr) * pitch_mult;
            for (auto& v : voiceData) {
                v.delta = newDelta;
            }
        }
    }

    void setExternalData(const ExternalData& ed, int index)
    {
        data = ed;
        ed.referBlockTo(sample[0], 0);
        ed.referBlockTo(sample[1], 1);

        if(data.numSamples > 0 && sr != 0.0)
        {
            const auto delta = (data.sampleRate / sr) * pitch;
            for(auto& v: voiceData)
            {
                v.delta = delta;
                updateDelta();
            }
        }

        reset(); // Ensure the playback state is reset when new data is set
    }

    ModValue gate;

    bool handleModulation(double& value)
    {
        return gate.getChangedValue(value);
    }

    template <int P> void setParameter(double v)
    {
        if (P == 0)
        {
            pitch = v;
            updateDelta();
        }

        if (P == 1)
        {
            loop = v;
        }
    }
};
