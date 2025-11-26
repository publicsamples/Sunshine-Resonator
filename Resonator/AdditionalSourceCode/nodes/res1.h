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

template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, filters::svf_eq<NV>>, 
                                   filters::svf_eq<NV>, 
                                   filters::svf_eq<NV>, 
                                   filters::svf_eq<NV>, 
                                   project::comb<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(comp5_mod_1Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using comp5_mod_1 = parameter::from0To1<wrap::no_process<core::gain<NV>>, 
                                        0, 
                                        comp5_mod_1Range>;

template <int NV>
using comp5_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   comp5_mod_1<NV>>;

template <int NV>
using comp5_t = wrap::mod<comp5_mod<NV>, 
                          wrap::no_data<dynamics::comp>>;

template <int NV>
using xfader_c0 = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      comp5_mod_1Range>;

template <int NV> using xfader_c1 = xfader_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::linear>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::clear<NV>>, 
                                   math::add<NV>, 
                                   math::rect<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain9_t<NV>>, 
                                 chain10_t<NV>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch_t<NV>>, 
                                   comp5_t<NV>, 
                                   xfader_t<NV>, 
                                   split_t<NV>>;

template <int NV>
using converter_mod = parameter::chain<ranges::Identity, 
                                       parameter::plain<core::fix_delay, 0>, 
                                       parameter::plain<jdsp::jdelay<NV>, 1>, 
                                       parameter::plain<core::fix_delay, 0>>;

template <int NV>
using converter_t = control::converter<converter_mod<NV>, 
                                       conversion_logic::freq2ms>;
using stereo_cable = cable::block<2>;

using comp_t = wrap::no_data<dynamics::comp>;
template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<comp_t, 0>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax_t<NV>>, 
                                  comp_t>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, routing::receive<stereo_cable>>, 
                                 core::fix_delay, 
                                 filters::one_pole<NV>, 
                                 fx::haas<NV>, 
                                 wrap::no_process<math::tanh<NV>>, 
                                 chain3_t<NV>, 
                                 routing::send<stereo_cable>>;

using comp3_t = comp_t;
template <int NV>
using minmax3_t = control::minmax<NV, 
                                  parameter::plain<comp3_t, 0>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax3_t<NV>>, 
                                  comp3_t>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<stereo_cable>>, 
                                   jdsp::jdelay<NV>, 
                                   fx::phase_delay<NV>, 
                                   filters::one_pole<NV>, 
                                   chain7_t<NV>, 
                                   routing::send<stereo_cable>>;

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

using comp2_t = comp_t;
template <int NV>
using minmax2_t = control::minmax<NV, 
                                  parameter::plain<comp2_t, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax2_t<NV>>, 
                                  comp2_t>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<stereo_cable>>, 
                                   core::fix_delay, 
                                   split1_t<NV>, 
                                   filters::one_pole<NV>, 
                                   chain6_t<NV>, 
                                   routing::send<stereo_cable>>;

using comp4_t = comp_t;
template <int NV>
using minmax4_t = control::minmax<NV, 
                                  parameter::plain<comp4_t, 0>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax4_t<NV>>, 
                                  comp4_t>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, filters::allpass<NV>>, 
                                  filters::one_pole<NV>, 
                                  chain8_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, wrap::no_process<core::gain<NV>>>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain_t<NV>>, 
                                    chain13_t<NV>, 
                                    chain14_t<NV>, 
                                    chain2_t<NV>, 
                                    chain1_t<NV>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, branch3_t<NV>>>;

template <int NV>
using dynamic_blocksize_t_ = container::chain<parameter::empty, 
                                              wrap::fix<2, converter_t<NV>>, 
                                              chain5_t<NV>>;

template <int NV>
using dynamic_blocksize_t = wrap::dynamic_blocksize<dynamic_blocksize_t_<NV>>;

namespace res1_t_parameters
{
// Parameter list for res1_impl::res1_t ------------------------------------------------------------

DECLARE_PARAMETER_RANGE_SKEW(feed_1Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using feed_1 = parameter::from0To1<filters::allpass<NV>, 
                                   1, 
                                   feed_1Range>;

template <int NV>
using feed = parameter::chain<ranges::Identity, 
                              parameter::plain<routing::receive<stereo_cable>, 0>, 
                              feed_1<NV>, 
                              parameter::plain<routing::receive<stereo_cable>, 0>, 
                              parameter::plain<routing::receive<stereo_cable>, 0>>;

template <int NV>
using Del = parameter::chain<ranges::Identity, 
                             parameter::plain<filters::allpass<NV>, 0>, 
                             parameter::plain<res1_impl::converter_t<NV>, 0>>;

template <int NV>
using LP = parameter::chain<ranges::Identity, 
                            parameter::plain<filters::one_pole<NV>, 0>, 
                            parameter::plain<filters::one_pole<NV>, 0>, 
                            parameter::plain<filters::one_pole<NV>, 0>, 
                            parameter::plain<filters::one_pole<NV>, 0>>;

DECLARE_PARAMETER_RANGE_SKEW(FbModifier_InputRange, 
                             20., 
                             20000., 
                             0.229905);
DECLARE_PARAMETER_RANGE_SKEW(FbModifier_0Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using FbModifier_0 = parameter::from0To1<fx::phase_delay<NV>, 
                                         0, 
                                         FbModifier_0Range>;

template <int NV> using FbModifier_1 = FbModifier_0<NV>;

DECLARE_PARAMETER_RANGE_STEP(FbModifier_2Range, 
                             -1., 
                             1., 
                             0.1);

template <int NV>
using FbModifier_2 = parameter::from0To1<fx::haas<NV>, 
                                         0, 
                                         FbModifier_2Range>;

DECLARE_PARAMETER_RANGE_SKEW(FbModifier_3Range, 
                             0., 
                             1000., 
                             0.30103);

template <int NV>
using FbModifier_3 = parameter::from0To1<jdsp::jdelay<NV>, 
                                         1, 
                                         FbModifier_3Range>;

template <int NV>
using FbModifier = parameter::chain<FbModifier_InputRange, 
                                    FbModifier_0<NV>, 
                                    FbModifier_1<NV>, 
                                    FbModifier_2<NV>, 
                                    FbModifier_3<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Mode_InputRange, 
                             1., 
                             5., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Mode_0Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using Mode_0 = parameter::from0To1<res1_impl::branch3_t<NV>, 
                                   0, 
                                   Mode_0Range>;

template <int NV>
using Mode = parameter::chain<Mode_InputRange, Mode_0<NV>>;

template <int NV>
using Comp = parameter::chain<ranges::Identity, 
                              parameter::plain<res1_impl::minmax_t<NV>, 0>, 
                              parameter::plain<res1_impl::minmax3_t<NV>, 0>, 
                              parameter::plain<res1_impl::minmax2_t<NV>, 0>, 
                              parameter::plain<res1_impl::minmax4_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_SKEW(FilterCut_0Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using FilterCut_0 = parameter::from0To1<filters::svf_eq<NV>, 
                                        0, 
                                        FilterCut_0Range>;

DECLARE_PARAMETER_RANGE_STEP(FilterCut_1Range, 
                             0., 
                             1024., 
                             1.);

template <int NV>
using FilterCut_1 = parameter::from0To1<project::comb<NV>, 
                                        1, 
                                        FilterCut_1Range>;

template <int NV> using FilterCut_2 = FilterCut_0<NV>;

template <int NV> using FilterCut_3 = FilterCut_0<NV>;

template <int NV> using FilterCut_4 = FilterCut_0<NV>;

template <int NV>
using FilterCut = parameter::chain<ranges::Identity, 
                                   FilterCut_0<NV>, 
                                   FilterCut_1<NV>, 
                                   FilterCut_2<NV>, 
                                   FilterCut_3<NV>, 
                                   FilterCut_4<NV>>;

template <int NV>
using FilterQ_0 = parameter::from0To1<filters::svf_eq<NV>, 
                                      1, 
                                      feed_1Range>;

template <int NV> using FilterQ_2 = FilterQ_0<NV>;

template <int NV> using FilterQ_3 = FilterQ_0<NV>;

template <int NV> using FilterQ_4 = FilterQ_0<NV>;

template <int NV>
using FilterQ = parameter::chain<ranges::Identity, 
                                 FilterQ_0<NV>, 
                                 parameter::plain<project::comb<NV>, 0>, 
                                 FilterQ_2<NV>, 
                                 FilterQ_3<NV>, 
                                 FilterQ_4<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FilterMode_InputRange, 
                             1., 
                             5., 
                             1.);
template <int NV>
using FilterMode_0 = parameter::from0To1<res1_impl::branch_t<NV>, 
                                         0, 
                                         Mode_0Range>;

template <int NV>
using FilterMode = parameter::chain<FilterMode_InputRange, FilterMode_0<NV>>;

template <int NV>
using Thresh = parameter::plain<res1_impl::comp5_t<NV>, 0>;
template <int NV>
using Atk = parameter::plain<res1_impl::comp5_t<NV>, 1>;
template <int NV>
using rel = parameter::plain<res1_impl::comp5_t<NV>, 2>;
template <int NV>
using Ratio = parameter::plain<res1_impl::comp5_t<NV>, 3>;
template <int NV>
using Trig = parameter::plain<res1_impl::xfader_t<NV>, 
                              0>;
template <int NV>
using block = parameter::plain<res1_impl::dynamic_blocksize_t<NV>, 
                               0>;
template <int NV>
using res1_t_plist = parameter::list<feed<NV>, 
                                     Del<NV>, 
                                     LP<NV>, 
                                     FbModifier<NV>, 
                                     Mode<NV>, 
                                     Comp<NV>, 
                                     FilterCut<NV>, 
                                     FilterQ<NV>, 
                                     FilterMode<NV>, 
                                     Thresh<NV>, 
                                     Atk<NV>, 
                                     rel<NV>, 
                                     Ratio<NV>, 
                                     Trig<NV>, 
                                     block<NV>>;
}

template <int NV>
using res1_t_ = container::chain<res1_t_parameters::res1_t_plist<NV>, 
                                 wrap::fix<2, chain17_t<NV>>, 
                                 filters::one_pole<NV>, 
                                 dynamic_blocksize_t<NV>>;

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
		SNEX_METADATA_ENCODED_PARAMETERS(236)
		{
			0x005B, 0x0000, 0x6600, 0x6565, 0x0064, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x015B, 
            0x0000, 0x4400, 0x6C65, 0x0000, 0xA000, 0x0041, 0x9C40, 0xFD46, 
            0x6B27, 0x1A44, 0x6B6C, 0x003E, 0x0000, 0x5B00, 0x0002, 0x0000, 
            0x504C, 0x0000, 0xA000, 0x0041, 0x9C40, 0x8F46, 0x5C9C, 0x1A46, 
            0x6B6C, 0x003E, 0x0000, 0x5B00, 0x0003, 0x0000, 0x6246, 0x6F4D, 
            0x6964, 0x6966, 0x7265, 0x0000, 0xA000, 0x0041, 0x9C40, 0x6746, 
            0x12B0, 0x1A46, 0x6B6C, 0xCD3E, 0xCCCC, 0x5B3D, 0x0004, 0x0000, 
            0x6F4D, 0x6564, 0x0000, 0x8000, 0x003F, 0xA000, 0x0040, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0005, 0x0000, 0x6F43, 
            0x706D, 0x0000, 0x0000, 0x0000, 0x8000, 0x3D3F, 0xDC5C, 0x003E, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0006, 0x0000, 0x6946, 0x746C, 
            0x7265, 0x7543, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 0xDE9C, 
            0x3E60, 0x0000, 0x3F80, 0x0000, 0x0000, 0x075B, 0x0000, 0x4600, 
            0x6C69, 0x6574, 0x5172, 0x0000, 0x0000, 0x0000, 0x8000, 0x7A3F, 
            0x77D3, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0008, 0x0000, 
            0x6946, 0x746C, 0x7265, 0x6F4D, 0x6564, 0x0000, 0x8000, 0x003F, 
            0xA000, 0x0040, 0xA000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0009, 0x0000, 0x6854, 0x6572, 0x6873, 0x0000, 0xC800, 0x00C2, 
            0x0000, 0x9900, 0xB599, 0x3EC1, 0xAD83, 0xCD40, 0xCCCC, 0x5B3D, 
            0x000A, 0x0000, 0x7441, 0x006B, 0x0000, 0x0000, 0x0000, 0x437A, 
            0x0000, 0x0000, 0x81A3, 0x3EDC, 0xCCCD, 0x3DCC, 0x0B5B, 0x0000, 
            0x7200, 0x6C65, 0x0000, 0x0000, 0x0000, 0x7A00, 0x9A43, 0xF999, 
            0xA340, 0xDC81, 0xCD3E, 0xCCCC, 0x5B3D, 0x000C, 0x0000, 0x6152, 
            0x6974, 0x006F, 0x0000, 0x3F80, 0x0000, 0x4200, 0x3333, 0x4123, 
            0xF69D, 0x3E97, 0xCCCD, 0x3DCC, 0x0D5B, 0x0000, 0x5400, 0x6972, 
            0x0067, 0x0000, 0x0000, 0x0000, 0x3F80, 0x9D2F, 0x3DF9, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0E5B, 0x0000, 0x6200, 0x6F6C, 0x6B63, 
            0x0000, 0x0000, 0x0000, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain17 = this->getT(0);                                                      // res1_impl::chain17_t<NV>
		auto& branch = this->getT(0).getT(0);                                               // res1_impl::branch_t<NV>
		auto& svf_eq = this->getT(0).getT(0).getT(0);                                       // filters::svf_eq<NV>
		auto& svf_eq1 = this->getT(0).getT(0).getT(1);                                      // filters::svf_eq<NV>
		auto& svf_eq2 = this->getT(0).getT(0).getT(2);                                      // filters::svf_eq<NV>
		auto& svf_eq3 = this->getT(0).getT(0).getT(3);                                      // filters::svf_eq<NV>
		auto& faust = this->getT(0).getT(0).getT(4);                                        // project::comb<NV>
		auto& comp5 = this->getT(0).getT(1);                                                // res1_impl::comp5_t<NV>
		auto& xfader = this->getT(0).getT(2);                                               // res1_impl::xfader_t<NV>
		auto& split = this->getT(0).getT(3);                                                // res1_impl::split_t<NV>
		auto& chain9 = this->getT(0).getT(3).getT(0);                                       // res1_impl::chain9_t<NV>
		auto& gain1 = this->getT(0).getT(3).getT(0).getT(0);                                // core::gain<NV>
		auto& chain10 = this->getT(0).getT(3).getT(1);                                      // res1_impl::chain10_t<NV>
		auto& clear = this->getT(0).getT(3).getT(1).getT(0);                                // math::clear<NV>
		auto& add = this->getT(0).getT(3).getT(1).getT(1);                                  // math::add<NV>
		auto& rect = this->getT(0).getT(3).getT(1).getT(2);                                 // math::rect<NV>
		auto& gain4 = this->getT(0).getT(3).getT(1).getT(3);                                // core::gain<NV>
		auto& one_pole = this->getT(1);                                                     // filters::one_pole<NV>
		auto& dynamic_blocksize = this->getT(2);                                            // res1_impl::dynamic_blocksize_t<NV>
		auto& converter = this->getT(2).getT(0);                                            // res1_impl::converter_t<NV>
		auto& chain5 = this->getT(2).getT(1);                                               // res1_impl::chain5_t<NV>
		auto& branch3 = this->getT(2).getT(1).getT(0);                                      // res1_impl::branch3_t<NV>
		auto& chain = this->getT(2).getT(1).getT(0).getT(0);                                // res1_impl::chain_t<NV>
		auto& receive = this->getT(2).getT(1).getT(0).getT(0).getT(0);                      // routing::receive<stereo_cable>
		auto& fix_delay = this->getT(2).getT(1).getT(0).getT(0).getT(1);                    // core::fix_delay
		auto& one_pole1 = this->getT(2).getT(1).getT(0).getT(0).getT(2);                    // filters::one_pole<NV>
		auto& haas = this->getT(2).getT(1).getT(0).getT(0).getT(3);                         // fx::haas<NV>
		auto& tanh = this->getT(2).getT(1).getT(0).getT(0).getT(4);                         // wrap::no_process<math::tanh<NV>>
		auto& chain3 = this->getT(2).getT(1).getT(0).getT(0).getT(5);                       // res1_impl::chain3_t<NV>
		auto& minmax = this->getT(2).getT(1).getT(0).getT(0).getT(5).getT(0);               // res1_impl::minmax_t<NV>
		auto& comp = this->getT(2).getT(1).getT(0).getT(0).getT(5).getT(1);                 // res1_impl::comp_t
		auto& send2 = this->getT(2).getT(1).getT(0).getT(0).getT(6);                        // routing::send<stereo_cable>
		auto& chain13 = this->getT(2).getT(1).getT(0).getT(1);                              // res1_impl::chain13_t<NV>
		auto& receive1 = this->getT(2).getT(1).getT(0).getT(1).getT(0);                     // routing::receive<stereo_cable>
		auto& jdelay2 = this->getT(2).getT(1).getT(0).getT(1).getT(1);                      // jdsp::jdelay<NV>
		auto& phase_delay1 = this->getT(2).getT(1).getT(0).getT(1).getT(2);                 // fx::phase_delay<NV>
		auto& one_pole146 = this->getT(2).getT(1).getT(0).getT(1).getT(3);                  // filters::one_pole<NV>
		auto& chain7 = this->getT(2).getT(1).getT(0).getT(1).getT(4);                       // res1_impl::chain7_t<NV>
		auto& minmax3 = this->getT(2).getT(1).getT(0).getT(1).getT(4).getT(0);              // res1_impl::minmax3_t<NV>
		auto& comp3 = this->getT(2).getT(1).getT(0).getT(1).getT(4).getT(1);                // res1_impl::comp3_t
		auto& send = this->getT(2).getT(1).getT(0).getT(1).getT(5);                         // routing::send<stereo_cable>
		auto& chain14 = this->getT(2).getT(1).getT(0).getT(2);                              // res1_impl::chain14_t<NV>
		auto& receive2 = this->getT(2).getT(1).getT(0).getT(2).getT(0);                     // routing::receive<stereo_cable>
		auto& fix_delay3 = this->getT(2).getT(1).getT(0).getT(2).getT(1);                   // core::fix_delay
		auto& split1 = this->getT(2).getT(1).getT(0).getT(2).getT(2);                       // res1_impl::split1_t<NV>
		auto& chain15 = this->getT(2).getT(1).getT(0).getT(2).getT(2).getT(0);              // res1_impl::chain15_t<NV>
		auto& jdelay3 = this->getT(2).getT(1).getT(0).getT(2).getT(2).getT(0).getT(0);      // jdsp::jdelay<NV>
		auto& gain2 = this->getT(2).getT(1).getT(0).getT(2).getT(2).getT(0).getT(1);        // core::gain<NV>
		auto& chain16 = this->getT(2).getT(1).getT(0).getT(2).getT(2).getT(1);              // res1_impl::chain16_t<NV>
		auto& phase_delay3 = this->getT(2).getT(1).getT(0).getT(2).getT(2).getT(1).getT(0); // fx::phase_delay<NV>
		auto& gain3 = this->getT(2).getT(1).getT(0).getT(2).getT(2).getT(1).getT(1);        // core::gain<NV>
		auto& one_pole147 = this->getT(2).getT(1).getT(0).getT(2).getT(3);                  // filters::one_pole<NV>
		auto& chain6 = this->getT(2).getT(1).getT(0).getT(2).getT(4);                       // res1_impl::chain6_t<NV>
		auto& minmax2 = this->getT(2).getT(1).getT(0).getT(2).getT(4).getT(0);              // res1_impl::minmax2_t<NV>
		auto& comp2 = this->getT(2).getT(1).getT(0).getT(2).getT(4).getT(1);                // res1_impl::comp2_t
		auto& send1 = this->getT(2).getT(1).getT(0).getT(2).getT(5);                        // routing::send<stereo_cable>
		auto& chain2 = this->getT(2).getT(1).getT(0).getT(3);                               // res1_impl::chain2_t<NV>
		auto& allpass = this->getT(2).getT(1).getT(0).getT(3).getT(0);                      // filters::allpass<NV>
		auto& one_pole149 = this->getT(2).getT(1).getT(0).getT(3).getT(1);                  // filters::one_pole<NV>
		auto& chain8 = this->getT(2).getT(1).getT(0).getT(3).getT(2);                       // res1_impl::chain8_t<NV>
		auto& minmax4 = this->getT(2).getT(1).getT(0).getT(3).getT(2).getT(0);              // res1_impl::minmax4_t<NV>
		auto& comp4 = this->getT(2).getT(1).getT(0).getT(3).getT(2).getT(1);                // res1_impl::comp4_t
		auto& chain1 = this->getT(2).getT(1).getT(0).getT(4);                               // res1_impl::chain1_t<NV>
		auto& gain5 = this->getT(2).getT(1).getT(0).getT(4).getT(0);                        // wrap::no_process<core::gain<NV>>
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& feed_p = this->getParameterT(0);
		feed_p.connectT(0, receive);  // feed -> receive::Feedback
		feed_p.connectT(1, allpass);  // feed -> allpass::Q
		feed_p.connectT(2, receive1); // feed -> receive1::Feedback
		feed_p.connectT(3, receive2); // feed -> receive2::Feedback
		
		auto& Del_p = this->getParameterT(1);
		Del_p.connectT(0, allpass);   // Del -> allpass::Frequency
		Del_p.connectT(1, converter); // Del -> converter::Value
		
		auto& LP_p = this->getParameterT(2);
		LP_p.connectT(0, one_pole146); // LP -> one_pole146::Frequency
		LP_p.connectT(1, one_pole147); // LP -> one_pole147::Frequency
		LP_p.connectT(2, one_pole149); // LP -> one_pole149::Frequency
		LP_p.connectT(3, one_pole1);   // LP -> one_pole1::Frequency
		
		auto& FbModifier_p = this->getParameterT(3);
		FbModifier_p.connectT(0, phase_delay3); // FbModifier -> phase_delay3::Frequency
		FbModifier_p.connectT(1, phase_delay1); // FbModifier -> phase_delay1::Frequency
		FbModifier_p.connectT(2, haas);         // FbModifier -> haas::Position
		FbModifier_p.connectT(3, jdelay3);      // FbModifier -> jdelay3::DelayTime
		
		this->getParameterT(4).connectT(0, branch3); // Mode -> branch3::Index
		
		auto& Comp_p = this->getParameterT(5);
		Comp_p.connectT(0, minmax);  // Comp -> minmax::Value
		Comp_p.connectT(1, minmax3); // Comp -> minmax3::Value
		Comp_p.connectT(2, minmax2); // Comp -> minmax2::Value
		Comp_p.connectT(3, minmax4); // Comp -> minmax4::Value
		
		auto& FilterCut_p = this->getParameterT(6);
		FilterCut_p.connectT(0, svf_eq);  // FilterCut -> svf_eq::Frequency
		FilterCut_p.connectT(1, faust);   // FilterCut -> faust::del
		FilterCut_p.connectT(2, svf_eq3); // FilterCut -> svf_eq3::Frequency
		FilterCut_p.connectT(3, svf_eq1); // FilterCut -> svf_eq1::Frequency
		FilterCut_p.connectT(4, svf_eq2); // FilterCut -> svf_eq2::Frequency
		
		auto& FilterQ_p = this->getParameterT(7);
		FilterQ_p.connectT(0, svf_eq);  // FilterQ -> svf_eq::Q
		FilterQ_p.connectT(1, faust);   // FilterQ -> faust::aN
		FilterQ_p.connectT(2, svf_eq3); // FilterQ -> svf_eq3::Q
		FilterQ_p.connectT(3, svf_eq2); // FilterQ -> svf_eq2::Q
		FilterQ_p.connectT(4, svf_eq1); // FilterQ -> svf_eq1::Q
		
		this->getParameterT(8).connectT(0, branch); // FilterMode -> branch::Index
		
		this->getParameterT(9).connectT(0, comp5); // Thresh -> comp5::Threshhold
		
		this->getParameterT(10).connectT(0, comp5); // Atk -> comp5::Attack
		
		this->getParameterT(11).connectT(0, comp5); // rel -> comp5::Release
		
		this->getParameterT(12).connectT(0, comp5); // Ratio -> comp5::Ratio
		
		this->getParameterT(13).connectT(0, xfader); // Trig -> xfader::Value
		
		this->getParameterT(14).connectT(0, dynamic_blocksize); // block -> dynamic_blocksize::BlockSize
		
		// Modulation Connections ------------------------------------------------------------------
		
		comp5.getParameter().connectT(0, add);   // comp5 -> add::Value
		comp5.getParameter().connectT(1, gain5); // comp5 -> gain5::Gain
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain1);                        // xfader -> gain1::Gain
		xfader_p.getParameterT(1).connectT(0, gain4);                        // xfader -> gain4::Gain
		converter.getWrappedObject().getParameter().connectT(0, fix_delay3); // converter -> fix_delay3::DelayTime
		converter.getWrappedObject().getParameter().connectT(1, jdelay2);    // converter -> jdelay2::DelayTime
		converter.getWrappedObject().getParameter().connectT(2, fix_delay);  // converter -> fix_delay::DelayTime
		minmax.getWrappedObject().getParameter().connectT(0, comp);          // minmax -> comp::Threshhold
		minmax3.getWrappedObject().getParameter().connectT(0, comp3);        // minmax3 -> comp3::Threshhold
		minmax2.getWrappedObject().getParameter().connectT(0, comp2);        // minmax2 -> comp2::Threshhold
		minmax4.getWrappedObject().getParameter().connectT(0, comp4);        // minmax4 -> comp4::Threshhold
		
		// Send Connections ------------------------------------------------------------------------
		
		send2.connect(receive);
		send.connect(receive1);
		send1.connect(receive2);
		
		// Default Values --------------------------------------------------------------------------
		
		; // branch::Index is automated
		
		;                              // svf_eq::Frequency is automated
		;                              // svf_eq::Q is automated
		svf_eq.setParameterT(2, 0.);   // filters::svf_eq::Gain
		svf_eq.setParameterT(3, 0.01); // filters::svf_eq::Smoothing
		svf_eq.setParameterT(4, 0.);   // filters::svf_eq::Mode
		svf_eq.setParameterT(5, 1.);   // filters::svf_eq::Enabled
		
		;                                  // svf_eq1::Frequency is automated
		;                                  // svf_eq1::Q is automated
		svf_eq1.setParameterT(2, 6.98434); // filters::svf_eq::Gain
		svf_eq1.setParameterT(3, 0.01);    // filters::svf_eq::Smoothing
		svf_eq1.setParameterT(4, 1.);      // filters::svf_eq::Mode
		svf_eq1.setParameterT(5, 1.);      // filters::svf_eq::Enabled
		
		;                               // svf_eq2::Frequency is automated
		;                               // svf_eq2::Q is automated
		svf_eq2.setParameterT(2, 18.);  // filters::svf_eq::Gain
		svf_eq2.setParameterT(3, 0.01); // filters::svf_eq::Smoothing
		svf_eq2.setParameterT(4, 2.);   // filters::svf_eq::Mode
		svf_eq2.setParameterT(5, 1.);   // filters::svf_eq::Enabled
		
		;                               // svf_eq3::Frequency is automated
		;                               // svf_eq3::Q is automated
		svf_eq3.setParameterT(2, 18.);  // filters::svf_eq::Gain
		svf_eq3.setParameterT(3, 0.01); // filters::svf_eq::Smoothing
		svf_eq3.setParameterT(4, 3.);   // filters::svf_eq::Mode
		svf_eq3.setParameterT(5, 1.);   // filters::svf_eq::Enabled
		
		; // faust::aN is automated
		; // faust::del is automated
		
		;                           // comp5::Threshhold is automated
		;                           // comp5::Attack is automated
		;                           // comp5::Release is automated
		;                           // comp5::Ratio is automated
		comp5.setParameterT(4, 0.); // dynamics::comp::Sidechain
		
		; // xfader::Value is automated
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // add::Value is automated
		
		rect.setParameterT(0, 0.); // math::rect::Value
		
		;                            // gain4::Gain is automated
		gain4.setParameterT(1, 20.); // core::gain::Smoothing
		gain4.setParameterT(2, 0.);  // core::gain::ResetValue
		
		one_pole.setParameterT(0, 55.);  // filters::one_pole::Frequency
		one_pole.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // dynamic_blocksize::BlockSize is automated
		
		; // converter::Value is automated
		
		; // branch3::Index is automated
		
		; // receive::Feedback is automated
		
		;                                  // fix_delay::DelayTime is automated
		fix_delay.setParameterT(1, 1024.); // core::fix_delay::FadeTime
		
		;                                 // one_pole1::Frequency is automated
		one_pole1.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole1.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole1.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole1.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole1.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // haas::Position is automated
		
		tanh.setParameterT(0, 1.); // math::tanh::Value
		
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
		
		; // receive1::Feedback is automated
		
		jdelay2.setParameterT(0, 1000.); // jdsp::jdelay::Limit
		;                                // jdelay2::DelayTime is automated
		
		; // phase_delay1::Frequency is automated
		
		;                                   // one_pole146::Frequency is automated
		one_pole146.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole146.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole146.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole146.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole146.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                  // minmax3::Value is automated
		minmax3.setParameterT(1, -100.);   // control::minmax::Minimum
		minmax3.setParameterT(2, 0.);      // control::minmax::Maximum
		minmax3.setParameterT(3, 5.42227); // control::minmax::Skew
		minmax3.setParameterT(4, 0.1);     // control::minmax::Step
		minmax3.setParameterT(5, 1.);      // control::minmax::Polarity
		
		;                              // comp3::Threshhold is automated
		comp3.setParameterT(1, 25.9);  // dynamics::comp::Attack
		comp3.setParameterT(2, 109.7); // dynamics::comp::Release
		comp3.setParameterT(3, 2.8);   // dynamics::comp::Ratio
		comp3.setParameterT(4, 0.);    // dynamics::comp::Sidechain
		
		; // receive2::Feedback is automated
		
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
		
		;                                   // one_pole147::Frequency is automated
		one_pole147.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole147.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole147.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole147.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole147.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                  // minmax2::Value is automated
		minmax2.setParameterT(1, -100.);   // control::minmax::Minimum
		minmax2.setParameterT(2, 0.);      // control::minmax::Maximum
		minmax2.setParameterT(3, 5.42227); // control::minmax::Skew
		minmax2.setParameterT(4, 0.1);     // control::minmax::Step
		minmax2.setParameterT(5, 1.);      // control::minmax::Polarity
		
		;                              // comp2::Threshhold is automated
		comp2.setParameterT(1, 25.9);  // dynamics::comp::Attack
		comp2.setParameterT(2, 109.7); // dynamics::comp::Release
		comp2.setParameterT(3, 2.8);   // dynamics::comp::Ratio
		comp2.setParameterT(4, 0.);    // dynamics::comp::Sidechain
		
		;                               // allpass::Frequency is automated
		;                               // allpass::Q is automated
		allpass.setParameterT(2, 0.);   // filters::allpass::Gain
		allpass.setParameterT(3, 0.01); // filters::allpass::Smoothing
		allpass.setParameterT(4, 0.);   // filters::allpass::Mode
		allpass.setParameterT(5, 1.);   // filters::allpass::Enabled
		
		;                                   // one_pole149::Frequency is automated
		one_pole149.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole149.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole149.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole149.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole149.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                  // minmax4::Value is automated
		minmax4.setParameterT(1, -100.);   // control::minmax::Minimum
		minmax4.setParameterT(2, 0.);      // control::minmax::Maximum
		minmax4.setParameterT(3, 5.42227); // control::minmax::Skew
		minmax4.setParameterT(4, 0.1);     // control::minmax::Step
		minmax4.setParameterT(5, 1.);      // control::minmax::Polarity
		
		;                              // comp4::Threshhold is automated
		comp4.setParameterT(1, 25.9);  // dynamics::comp::Attack
		comp4.setParameterT(2, 109.7); // dynamics::comp::Release
		comp4.setParameterT(3, 2.8);   // dynamics::comp::Ratio
		comp4.setParameterT(4, 0.);    // dynamics::comp::Sidechain
		
		;                            // gain5::Gain is automated
		gain5.setParameterT(1, 20.); // core::gain::Smoothing
		gain5.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 940.625);
		this->setParameterT(2, 14119.1);
		this->setParameterT(3, 9388.1);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 0.430391);
		this->setParameterT(6, 0.219599);
		this->setParameterT(7, 0.968071);
		this->setParameterT(8, 5.);
		this->setParameterT(9, -22.);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 7.8);
		this->setParameterT(12, 10.2);
		this->setParameterT(13, 0.121882);
		this->setParameterT(14, 1.);
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
		
		this->getT(0).getT(1).setExternalData(b, index);                                 // res1_impl::comp5_t<NV>
		this->getT(2).getT(1).getT(0).getT(0).getT(5).getT(1).setExternalData(b, index); // res1_impl::comp_t
		this->getT(2).getT(1).getT(0).getT(1).getT(4).getT(1).setExternalData(b, index); // res1_impl::comp3_t
		this->getT(2).getT(1).getT(0).getT(2).getT(4).getT(1).setExternalData(b, index); // res1_impl::comp2_t
		this->getT(2).getT(1).getT(0).getT(3).getT(2).getT(1).setExternalData(b, index); // res1_impl::comp4_t
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


