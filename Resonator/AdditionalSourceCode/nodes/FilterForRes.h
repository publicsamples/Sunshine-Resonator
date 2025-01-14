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

namespace FilterForRes_impl
{
// ===========================| Node & Parameter type declarations |===========================

template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, filters::svf<NV>>, 
                                   filters::svf<NV>, 
                                   filters::svf<NV>, 
                                   project::Salen2ndLPF<NV>, 
                                   project::Salen2ndHPF<NV>, 
                                   project::Salen2ndBPF<NV>, 
                                   project::ObLfp<NV>, 
                                   project::ObHfp<NV>, 
                                   project::ObBpf<NV>, 
                                   project::MoogLadder<NV>, 
                                   project::klp2<NV>, 
                                   project::khp2<NV>, 
                                   project::DiodeLPF<NV>>;

namespace FilterForRes_t_parameters
{
// Parameter list for FilterForRes_impl::FilterForRes_t --------------------------------------

DECLARE_PARAMETER_RANGE_SKEW(Cut_InputRange, 
                             0., 
                             1., 
                             0.239104);
DECLARE_PARAMETER_RANGE_SKEW(Cut_0Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using Cut_0 = parameter::from0To1<filters::svf<NV>, 
                                  0, 
                                  Cut_0Range>;

template <int NV> using Cut_1 = Cut_0<NV>;

template <int NV> using Cut_2 = Cut_0<NV>;

template <int NV>
using Cut = parameter::chain<Cut_InputRange, 
                             Cut_0<NV>, 
                             Cut_1<NV>, 
                             Cut_2<NV>, 
                             parameter::plain<project::Salen2ndHPF<NV>, 1>, 
                             parameter::plain<project::Salen2ndBPF<NV>, 1>, 
                             parameter::plain<project::ObLfp<NV>, 1>, 
                             parameter::plain<project::ObHfp<NV>, 1>, 
                             parameter::plain<project::ObBpf<NV>, 1>, 
                             parameter::plain<project::DiodeLPF<NV>, 1>, 
                             parameter::plain<project::MoogLadder<NV>, 1>, 
                             parameter::plain<project::Salen2ndLPF<NV>, 1>, 
                             parameter::plain<project::klp2<NV>, 1>, 
                             parameter::plain<project::khp2<NV>, 1>>;

DECLARE_PARAMETER_RANGE_SKEW(Res_0Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using Res_0 = parameter::from0To1<filters::svf<NV>, 
                                  1, 
                                  Res_0Range>;

template <int NV> using Res_1 = Res_0<NV>;

template <int NV> using Res_2 = Res_0<NV>;

DECLARE_PARAMETER_RANGE_STEP(Res_3Range, 
                             0.5, 
                             10., 
                             0.01);

template <int NV>
using Res_3 = parameter::from0To1<project::Salen2ndLPF<NV>, 
                                  0, 
                                  Res_3Range>;

template <int NV>
using Res_4 = parameter::from0To1<project::Salen2ndHPF<NV>, 
                                  0, 
                                  Res_3Range>;

template <int NV>
using Res_5 = parameter::from0To1<project::Salen2ndBPF<NV>, 
                                  0, 
                                  Res_3Range>;

template <int NV>
using Res_6 = parameter::from0To1<project::ObLfp<NV>, 
                                  0, 
                                  Res_3Range>;

template <int NV>
using Res_7 = parameter::from0To1<project::ObHfp<NV>, 
                                  0, 
                                  Res_3Range>;

DECLARE_PARAMETER_RANGE_STEP(Res_8Range, 
                             0.5, 
                             1, 
                             0.01);

template <int NV>
using Res_8 = parameter::from0To1<project::ObBpf<NV>, 
                                  0, 
                                  Res_8Range>;

DECLARE_PARAMETER_RANGE_STEP(Res_9Range, 
                             0.7072, 
                             25., 
                             0.01);

template <int NV>
using Res_9 = parameter::from0To1<project::MoogLadder<NV>, 
                                  0, 
                                  Res_9Range>;

DECLARE_PARAMETER_RANGE_STEP(Res_10Range, 
                             0.71, 
                             25, 
                             0.01);

template <int NV>
using Res_10 = parameter::from0To1<project::DiodeLPF<NV>, 
                                   0, 
                                   Res_10Range>;

template <int NV>
using Res_11 = parameter::from0To1<project::klp2<NV>, 
                                   0, 
                                   Res_3Range>;

template <int NV>
using Res_12 = parameter::from0To1<project::khp2<NV>, 
                                   0, 
                                   Res_8Range>;

template <int NV>
using Res = parameter::chain<ranges::Identity, 
                             Res_0<NV>, 
                             Res_1<NV>, 
                             Res_2<NV>, 
                             Res_3<NV>, 
                             Res_4<NV>, 
                             Res_5<NV>, 
                             Res_6<NV>, 
                             Res_7<NV>, 
                             Res_8<NV>, 
                             Res_9<NV>, 
                             Res_10<NV>, 
                             Res_11<NV>, 
                             Res_12<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Mode_InputRange, 
                             1., 
                             13., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Mode_0Range, 
                             0., 
                             12., 
                             1.);

template <int NV>
using Mode_0 = parameter::from0To1<FilterForRes_impl::branch_t<NV>, 
                                   0, 
                                   Mode_0Range>;

template <int NV>
using Mode = parameter::chain<Mode_InputRange, Mode_0<NV>>;

template <int NV>
using FilterForRes_t_plist = parameter::list<Cut<NV>, 
                                             Res<NV>, 
                                             Mode<NV>>;
}

template <int NV>
using FilterForRes_t_ = container::chain<FilterForRes_t_parameters::FilterForRes_t_plist<NV>, 
                                         wrap::fix<2, branch_t<NV>>>;

// ==============================| Root node initialiser class |==============================

template <int NV> struct instance: public FilterForRes_impl::FilterForRes_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(FilterForRes);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(46)
		{
			0x005B, 0x0000, 0x4300, 0x7475, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x743F, 0xA3C7, 0xB53D, 0x74D7, 0x003E, 0x0000, 0x5B00, 0x0001, 
            0x0000, 0x6552, 0x0073, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 0x0000, 0x4D00, 
            0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 0x4150, 0x0000, 0x40C0, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------
		
		auto& branch = this->getT(0);          // FilterForRes_impl::branch_t<NV>
		auto& svf = this->getT(0).getT(0);     // filters::svf<NV>
		auto& svf1 = this->getT(0).getT(1);    // filters::svf<NV>
		auto& svf2 = this->getT(0).getT(2);    // filters::svf<NV>
		auto& faust1 = this->getT(0).getT(3);  // project::Salen2ndLPF<NV>
		auto& faust = this->getT(0).getT(4);   // project::Salen2ndHPF<NV>
		auto& faust2 = this->getT(0).getT(5);  // project::Salen2ndBPF<NV>
		auto& faust3 = this->getT(0).getT(6);  // project::ObLfp<NV>
		auto& faust4 = this->getT(0).getT(7);  // project::ObHfp<NV>
		auto& faust5 = this->getT(0).getT(8);  // project::ObBpf<NV>
		auto& faust7 = this->getT(0).getT(9);  // project::MoogLadder<NV>
		auto& faust8 = this->getT(0).getT(10); // project::klp2<NV>
		auto& faust9 = this->getT(0).getT(11); // project::khp2<NV>
		auto& faust6 = this->getT(0).getT(12); // project::DiodeLPF<NV>
		
		// Parameter Connections -------------------------------------------------------------
		
		auto& Cut_p = this->getParameterT(0);
		Cut_p.connectT(0, svf);     // Cut -> svf::Frequency
		Cut_p.connectT(1, svf1);    // Cut -> svf1::Frequency
		Cut_p.connectT(2, svf2);    // Cut -> svf2::Frequency
		Cut_p.connectT(3, faust);   // Cut -> faust::freq
		Cut_p.connectT(4, faust2);  // Cut -> faust2::freq
		Cut_p.connectT(5, faust3);  // Cut -> faust3::freq
		Cut_p.connectT(6, faust4);  // Cut -> faust4::freq
		Cut_p.connectT(7, faust5);  // Cut -> faust5::freq
		Cut_p.connectT(8, faust6);  // Cut -> faust6::freq
		Cut_p.connectT(9, faust7);  // Cut -> faust7::freq
		Cut_p.connectT(10, faust1); // Cut -> faust1::freq
		Cut_p.connectT(11, faust8); // Cut -> faust8::freq
		Cut_p.connectT(12, faust9); // Cut -> faust9::freq
		
		auto& Res_p = this->getParameterT(1);
		Res_p.connectT(0, svf);     // Res -> svf::Q
		Res_p.connectT(1, svf1);    // Res -> svf1::Q
		Res_p.connectT(2, svf2);    // Res -> svf2::Q
		Res_p.connectT(3, faust1);  // Res -> faust1::Q
		Res_p.connectT(4, faust);   // Res -> faust::Q
		Res_p.connectT(5, faust2);  // Res -> faust2::Q
		Res_p.connectT(6, faust3);  // Res -> faust3::Q
		Res_p.connectT(7, faust4);  // Res -> faust4::Q
		Res_p.connectT(8, faust5);  // Res -> faust5::Q
		Res_p.connectT(9, faust7);  // Res -> faust7::Q
		Res_p.connectT(10, faust6); // Res -> faust6::Q
		Res_p.connectT(11, faust8); // Res -> faust8::Q
		Res_p.connectT(12, faust9); // Res -> faust9::Q
		
		this->getParameterT(2).connectT(0, branch); // Mode -> branch::Index
		
		// Default Values --------------------------------------------------------------------
		
		; // branch::Index is automated
		
		;                           // svf::Frequency is automated
		;                           // svf::Q is automated
		svf.setParameterT(2, 0.);   // filters::svf::Gain
		svf.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf.setParameterT(4, 0.);   // filters::svf::Mode
		svf.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf1::Frequency is automated
		;                            // svf1::Q is automated
		svf1.setParameterT(2, 0.);   // filters::svf::Gain
		svf1.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf1.setParameterT(4, 1.);   // filters::svf::Mode
		svf1.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf2::Frequency is automated
		;                            // svf2::Q is automated
		svf2.setParameterT(2, 0.);   // filters::svf::Gain
		svf2.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf2.setParameterT(4, 2.);   // filters::svf::Mode
		svf2.setParameterT(5, 1.);   // filters::svf::Enabled
		
		; // faust1::Q is automated
		; // faust1::freq is automated
		
		; // faust::Q is automated
		; // faust::freq is automated
		
		; // faust2::Q is automated
		; // faust2::freq is automated
		
		; // faust3::Q is automated
		; // faust3::freq is automated
		
		; // faust4::Q is automated
		; // faust4::freq is automated
		
		; // faust5::Q is automated
		; // faust5::freq is automated
		
		; // faust7::Q is automated
		; // faust7::freq is automated
		
		; // faust8::Q is automated
		; // faust8::freq is automated
		
		; // faust9::Q is automated
		; // faust9::freq is automated
		
		; // faust6::Q is automated
		; // faust6::freq is automated
		
		this->setParameterT(0, 0.0799703);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 6.);
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
// ===================================| Public Definition |===================================

namespace project
{
// polyphonic template declaration

template <int NV>
using FilterForRes = wrap::node<FilterForRes_impl::instance<NV>>;
}


