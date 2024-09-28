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

namespace OneAP_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using converter1_t = control::converter<parameter::plain<filters::allpass<NV>, 0>, 
                                        conversion_logic::pitch2cent>;
template <int NV>
using converter_t = control::converter<parameter::plain<converter1_t<NV>, 0>, 
                                       conversion_logic::st2pitch>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, filters::allpass<NV>>, 
                                   filters::allpass<NV>>;

namespace OneAP_t_parameters
{
// Parameter list for OneAP_impl::OneAP_t ----------------------------------------------------------

template <int NV>
using res = parameter::chain<ranges::Identity, 
                             parameter::plain<filters::allpass<NV>, 1>, 
                             parameter::plain<filters::allpass<NV>, 1>>;

template <int NV>
using frq = parameter::plain<filters::allpass<NV>, 0>;
template <int NV>
using freqquant = parameter::plain<OneAP_impl::converter_t<NV>, 
                                   0>;
template <int NV>
using quant = parameter::plain<OneAP_impl::branch_t<NV>, 
                               0>;
template <int NV>
using OneAP_t_plist = parameter::list<res<NV>, 
                                      frq<NV>, 
                                      freqquant<NV>, 
                                      quant<NV>>;
}

template <int NV>
using OneAP_t_ = container::chain<OneAP_t_parameters::OneAP_t_plist<NV>, 
                                  wrap::fix<2, converter_t<NV>>, 
                                  converter1_t<NV>, 
                                  branch_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public OneAP_impl::OneAP_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(OneAP);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(64)
		{
			0x005B, 0x0000, 0x7200, 0x7365, 0x9A00, 0x9999, 0x663E, 0x1E66, 
            0x6641, 0x1E66, 0x1841, 0x8789, 0x003E, 0x0000, 0x5B00, 0x0001, 
            0x0000, 0x7266, 0x0071, 0x0000, 0x41A0, 0x4000, 0x469C, 0x4000, 
            0x469C, 0x6C1A, 0x3E6B, 0x0000, 0x0000, 0x025B, 0x0000, 0x6600, 
            0x6572, 0x7171, 0x6175, 0x746E, 0x0000, 0x4000, 0x0026, 0x0000, 
            0x0043, 0xD000, 0x0041, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0003, 
            0x0000, 0x7571, 0x6E61, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& converter = this->getT(0);        // OneAP_impl::converter_t<NV>
		auto& converter1 = this->getT(1);       // OneAP_impl::converter1_t<NV>
		auto& branch = this->getT(2);           // OneAP_impl::branch_t<NV>
		auto& allpass = this->getT(2).getT(0);  // filters::allpass<NV>
		auto& allpass1 = this->getT(2).getT(1); // filters::allpass<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& res_p = this->getParameterT(0);
		res_p.connectT(0, allpass);  // res -> allpass::Q
		res_p.connectT(1, allpass1); // res -> allpass1::Q
		
		this->getParameterT(1).connectT(0, allpass); // frq -> allpass::Frequency
		
		this->getParameterT(2).connectT(0, converter); // freqquant -> converter::Value
		
		this->getParameterT(3).connectT(0, branch); // quant -> branch::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		converter1.getWrappedObject().getParameter().connectT(0, allpass1);  // converter1 -> allpass1::Frequency
		converter.getWrappedObject().getParameter().connectT(0, converter1); // converter -> converter1::Value
		
		// Default Values --------------------------------------------------------------------------
		
		; // converter::Value is automated
		
		; // converter1::Value is automated
		
		; // branch::Index is automated
		
		;                               // allpass::Frequency is automated
		;                               // allpass::Q is automated
		allpass.setParameterT(2, 0.);   // filters::allpass::Gain
		allpass.setParameterT(3, 0.01); // filters::allpass::Smoothing
		allpass.setParameterT(4, 0.);   // filters::allpass::Mode
		allpass.setParameterT(5, 1.);   // filters::allpass::Enabled
		
		;                                // allpass1::Frequency is automated
		;                                // allpass1::Q is automated
		allpass1.setParameterT(2, 0.);   // filters::allpass::Gain
		allpass1.setParameterT(3, 0.01); // filters::allpass::Smoothing
		allpass1.setParameterT(4, 0.);   // filters::allpass::Mode
		allpass1.setParameterT(5, 1.);   // filters::allpass::Enabled
		
		this->setParameterT(0, 9.9);
		this->setParameterT(1, 20000.);
		this->setParameterT(2, 26.);
		this->setParameterT(3, 0.);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
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
using OneAP = wrap::node<OneAP_impl::instance<NV>>;
}


