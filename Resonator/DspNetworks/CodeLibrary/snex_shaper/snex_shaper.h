template <int NumVoices> struct snex_shaper
{
	SNEX_NODE(snex_shaper);
	
	output = input * Math.asin(Math.PI * 1.0 * value * input) * (1 - Math.PI);
	
	// Implement the Waveshaper here...
	
	float getSample(float input)
	{
		return input;
	}
	// These functions are the glue code that call the function above
	template <typename T> void process(T& data)
	{
		for(auto ch: data)
		{
			for(auto& s: data.toChannelData(ch))
			{
				s = getSample(s);
			}
		}
	}
	template <typename T> void processFrame(T& data)
	{
		for(auto& s: data)
			s = getSample(s);
	}
	void reset()
	{
		
	}
	void prepare(PrepareSpecs ps)
	{
		
	}
	
	void setExternalData(const ExternalData& d, int index)
	{
	}
	template <int P> void setParameter(double v)
	{
	}
};
