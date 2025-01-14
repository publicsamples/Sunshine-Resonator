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

namespace modtest1_impl
{
// ==============================| Node & Parameter type declarations |==============================

using global_cable1_t_index = runtime_target::indexers::fix_hash<3357039>;

template <int NV>
using global_cable1_t = routing::global_cable<global_cable1_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, global_cable1_t<NV>>, 
                                 math::add<NV>>;
using global_cable2_t_index = runtime_target::indexers::fix_hash<3357040>;

template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable2_t<NV>>, 
                                  math::add<NV>>;
using global_cable3_t_index = runtime_target::indexers::fix_hash<3357041>;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable3_t<NV>>, 
                                  math::add<NV>>;
using global_cable4_t_index = runtime_target::indexers::fix_hash<3357042>;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable4_t<NV>>, 
                                  math::add<NV>>;
using global_cable5_t_index = runtime_target::indexers::fix_hash<3357043>;

template <int NV>
using global_cable5_t = routing::global_cable<global_cable5_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable5_t<NV>>, 
                                  math::add<NV>>;
using global_cable6_t_index = runtime_target::indexers::fix_hash<3357044>;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable6_t<NV>>, 
                                  math::add<NV>>;
using global_cable7_t_index = runtime_target::indexers::fix_hash<3357045>;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable7_t<NV>>, 
                                  math::add<NV>>;
using global_cable8_t_index = runtime_target::indexers::fix_hash<3357046>;

template <int NV>
using global_cable8_t = routing::global_cable<global_cable8_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable8_t<NV>>, 
                                   math::add<NV>>;
using global_cable10_t_index = runtime_target::indexers::fix_hash<3357047>;

template <int NV>
using global_cable10_t = routing::global_cable<global_cable10_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable10_t<NV>>, 
                                   math::add<NV>>;
using global_cable11_t_index = runtime_target::indexers::fix_hash<104068257>;

template <int NV>
using global_cable11_t = routing::global_cable<global_cable11_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable11_t<NV>>, 
                                   math::add<NV>>;
using global_cable12_t_index = runtime_target::indexers::fix_hash<104068258>;

template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable12_t<NV>>, 
                                   math::add<NV>>;
using global_cable13_t_index = runtime_target::indexers::fix_hash<104068259>;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable13_t<NV>>, 
                                   math::add<NV>>;
using global_cable14_t_index = runtime_target::indexers::fix_hash<104068260>;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable14_t<NV>>, 
                                   math::add<NV>>;
using global_cable15_t_index = runtime_target::indexers::fix_hash<104068261>;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable15_t<NV>>, 
                                   math::add<NV>>;
using global_cable16_t_index = runtime_target::indexers::fix_hash<104068262>;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   math::add<NV>>;
using global_cable17_t_index = runtime_target::indexers::fix_hash<104068263>;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain_t<NV>>, 
                                    chain2_t<NV>, 
                                    chain3_t<NV>, 
                                    chain4_t<NV>, 
                                    chain6_t<NV>, 
                                    chain7_t<NV>, 
                                    chain9_t<NV>, 
                                    chain10_t<NV>, 
                                    chain14_t<NV>, 
                                    chain15_t<NV>, 
                                    chain25_t<NV>, 
                                    chain17_t<NV>, 
                                    chain18_t<NV>, 
                                    chain19_t<NV>, 
                                    chain21_t<NV>, 
                                    chain22_t<NV>>;

namespace custom
{

struct expr7
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 2.0 * value * Math.PI) * (1 - Math.PI);
		;
	}
};
}

template <int NV>
using cable_table_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::table<0>>;

template <int NV>
using cable_pack_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                data::external::sliderpack<0>>;

template <int NV>
using ramp_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<math::expr<NV, custom::expr7>, 0>, 
                                  parameter::plain<cable_table_t<NV>, 0>, 
                                  parameter::plain<cable_pack_t<NV>, 0>>;

template <int NV>
using ramp_t = wrap::mod<ramp_mod<NV>, 
                         wrap::no_data<core::ramp<NV, false>>>;

template <int NV>
using oscillator1_t = wrap::no_data<core::oscillator<NV>>;
template <int NV>
using converter_t = control::converter<parameter::plain<oscillator1_t<NV>, 1>, 
                                       conversion_logic::ms2freq>;

template <int NV>
using tempo_sync_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<ramp_t<NV>, 0>, 
                                        parameter::plain<fx::sampleandhold<NV>, 0>, 
                                        parameter::plain<converter_t<NV>, 0>>;

template <int NV>
using tempo_sync_t = wrap::mod<tempo_sync_mod<NV>, 
                               control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(pma1_modRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using pma1_mod = parameter::from0To1<tempo_sync_t<NV>, 
                                     0, 
                                     pma1_modRange>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;
template <int NV>
using peak1_t = wrap::mod<parameter::plain<pma1_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch3_t<NV>>, 
                                   peak1_t<NV>, 
                                   math::clear<NV>>;
using global_cable19_t_index = global_cable1_t_index;

template <int NV>
using global_cable19_t = routing::global_cable<global_cable19_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable19_t<NV>>, 
                                   math::add<NV>>;
using global_cable20_t_index = global_cable2_t_index;

template <int NV>
using global_cable20_t = routing::global_cable<global_cable20_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable20_t<NV>>, 
                                   math::add<NV>>;
using global_cable21_t_index = global_cable3_t_index;

template <int NV>
using global_cable21_t = routing::global_cable<global_cable21_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable21_t<NV>>, 
                                   math::add<NV>>;
using global_cable22_t_index = global_cable4_t_index;

template <int NV>
using global_cable22_t = routing::global_cable<global_cable22_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable22_t<NV>>, 
                                   math::add<NV>>;
using global_cable23_t_index = global_cable5_t_index;

template <int NV>
using global_cable23_t = routing::global_cable<global_cable23_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable23_t<NV>>, 
                                   math::add<NV>>;
using global_cable24_t_index = global_cable6_t_index;

template <int NV>
using global_cable24_t = routing::global_cable<global_cable24_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable24_t<NV>>, 
                                   math::add<NV>>;
using global_cable25_t_index = global_cable7_t_index;

template <int NV>
using global_cable25_t = routing::global_cable<global_cable25_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable25_t<NV>>, 
                                   math::add<NV>>;
using global_cable26_t_index = global_cable8_t_index;

template <int NV>
using global_cable26_t = routing::global_cable<global_cable26_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable26_t<NV>>, 
                                   math::add<NV>>;
using global_cable27_t_index = global_cable10_t_index;

template <int NV>
using global_cable27_t = routing::global_cable<global_cable27_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable27_t<NV>>, 
                                   math::add<NV>>;
using global_cable28_t_index = global_cable11_t_index;

template <int NV>
using global_cable28_t = routing::global_cable<global_cable28_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable28_t<NV>>, 
                                   math::add<NV>>;
using global_cable29_t_index = global_cable12_t_index;

template <int NV>
using global_cable29_t = routing::global_cable<global_cable29_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable29_t<NV>>, 
                                   math::add<NV>>;
using global_cable30_t_index = global_cable13_t_index;

template <int NV>
using global_cable30_t = routing::global_cable<global_cable30_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable30_t<NV>>, 
                                   math::add<NV>>;
using global_cable31_t_index = global_cable14_t_index;

template <int NV>
using global_cable31_t = routing::global_cable<global_cable31_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable31_t<NV>>, 
                                   math::add<NV>>;
using global_cable32_t_index = global_cable15_t_index;

template <int NV>
using global_cable32_t = routing::global_cable<global_cable32_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable32_t<NV>>, 
                                   math::add<NV>>;
using global_cable33_t_index = global_cable16_t_index;

template <int NV>
using global_cable33_t = routing::global_cable<global_cable33_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable33_t<NV>>, 
                                   math::add<NV>>;
using global_cable34_t_index = global_cable17_t_index;

template <int NV>
using global_cable34_t = routing::global_cable<global_cable34_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable34_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain28_t<NV>>, 
                                    chain30_t<NV>, 
                                    chain31_t<NV>, 
                                    chain33_t<NV>, 
                                    chain34_t<NV>, 
                                    chain36_t<NV>, 
                                    chain37_t<NV>, 
                                    chain38_t<NV>, 
                                    chain39_t<NV>, 
                                    chain40_t<NV>, 
                                    chain42_t<NV>, 
                                    chain43_t<NV>, 
                                    chain52_t<NV>, 
                                    chain53_t<NV>, 
                                    chain54_t<NV>, 
                                    chain55_t<NV>>;

namespace custom
{

struct expr3
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 24.0 * value * input) * (2 - Math.PI);;
	}
};
}

namespace custom
{

struct expr5
{
	static float op(float input, float value)
	{
		return input * Math.asin(Math.PI * 1.0 * value * input) * (1 - Math.PI);;
	}
};
}

namespace custom
{

struct expr8
{
	static float op(float input, float value)
	{
		return input * Math.cos(Math.PI * 12.0 * value * input) * (1 - Math.PI);;
	}
};
}

namespace custom
{

struct expr9
{
	static float op(float input, float value)
	{
		return input * Math.log(Math.PI * 1.0 * value * input) * (1 - Math.PI);;
	}
};
}

DECLARE_PARAMETER_RANGE(pma_mod_0Range, 
                        0.01, 
                        1.);

template <int NV>
using pma_mod_0 = parameter::from0To1<math::expr<NV, custom::expr3>, 
                                      0, 
                                      pma_mod_0Range>;

DECLARE_PARAMETER_RANGE(pma_mod_1Range, 
                        0.02, 
                        1.);

template <int NV>
using pma_mod_1 = parameter::from0To1<math::expr<NV, custom::expr5>, 
                                      0, 
                                      pma_mod_1Range>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 pma_mod_0<NV>, 
                                 pma_mod_1<NV>, 
                                 parameter::plain<math::expr<NV, custom::expr8>, 0>, 
                                 parameter::plain<math::expr<NV, custom::expr9>, 0>>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;
template <int NV>
using peak4_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch5_t<NV>>, 
                                   peak4_t<NV>>;

template <int NV>
using input_toggle_mod = parameter::chain<ranges::Identity, 
                                          parameter::plain<ramp_t<NV>, 2>, 
                                          parameter::plain<oscillator1_t<NV>, 3>>;

template <int NV>
using input_toggle_t = control::input_toggle<input_toggle_mod<NV>>;
template <int NV>
using transport_t = wrap::mod<parameter::plain<input_toggle_t<NV>, 2>, 
                              control::transport<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<1, transport_t<NV>>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   converter_t<NV>, 
                                   oscillator1_t<NV>, 
                                   math::sig2mod<NV>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, wrap::no_process<math::pi<NV>>>, 
                                  math::rect<NV>>;

using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, core::empty>>;
using peak5_t = wrap::no_data<core::peak>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<1, wrap::no_process<math::clear<NV>>>, 
                                   math::expr<NV, custom::expr7>, 
                                   wrap::no_process<math::sig2mod<NV>>, 
                                   peak5_t>;
template <int NV> using oscillator_t = oscillator1_t<NV>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, oscillator_t<NV>>, 
                                   wrap::no_process<math::pi<NV>>, 
                                   fx::sampleandhold<NV>, 
                                   math::sig2mod<NV>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   cable_table_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   cable_pack_t<NV>, 
                                   math::add<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain23_t<NV>>, 
                                   chain8_t<NV>, 
                                   chain5_t, 
                                   chain41_t<NV>, 
                                   chain32_t<NV>, 
                                   chain20_t<NV>, 
                                   chain26_t<NV>>;

using chain1_t = chain5_t;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::expr<NV, custom::expr3>>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::expr<NV, custom::expr5>>>;

template <int NV>
using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::expr<NV, custom::expr8>>>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::expr<NV, custom::expr9>>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain1_t>, 
                                    chain29_t<NV>, 
                                    chain35_t<NV>, 
                                    chain44_t<NV>, 
                                    chain45_t<NV>>;
using peak2_t = wrap::data<core::peak, 
                           data::external::displaybuffer<0>>;

using global_cable_t_index = runtime_target::indexers::fix_hash<1750456703>;
using peak3_mod = parameter::plain<routing::global_cable<global_cable_t_index, parameter::empty>, 
                                   0>;
using peak3_t = wrap::mod<peak3_mod, 
                          wrap::no_data<core::peak>>;

using chain13_t = container::chain<parameter::empty, wrap::fix<1, peak3_t>>;

using global_cable39_t_index = runtime_target::indexers::fix_hash<1750456704>;
using peak9_mod = parameter::plain<routing::global_cable<global_cable39_t_index, parameter::empty>, 
                                   0>;
using peak9_t = wrap::mod<peak9_mod, 
                          wrap::no_data<core::peak>>;

using chain16_t = container::chain<parameter::empty, wrap::fix<1, peak9_t>>;

using global_cable38_t_index = runtime_target::indexers::fix_hash<1750456705>;
using peak8_mod = parameter::plain<routing::global_cable<global_cable38_t_index, parameter::empty>, 
                                   0>;
using peak8_t = wrap::mod<peak8_mod, 
                          wrap::no_data<core::peak>>;

using chain24_t = container::chain<parameter::empty, wrap::fix<1, peak8_t>>;

using global_cable37_t_index = runtime_target::indexers::fix_hash<1750456706>;
using peak7_mod = parameter::plain<routing::global_cable<global_cable37_t_index, parameter::empty>, 
                                   0>;
using peak7_t = wrap::mod<peak7_mod, 
                          wrap::no_data<core::peak>>;

using chain50_t = container::chain<parameter::empty, wrap::fix<1, peak7_t>>;
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain13_t>, 
                                    chain16_t, 
                                    chain24_t, 
                                    chain50_t>;

using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, routing::global_cable<global_cable_t_index, parameter::empty>>, 
                                 routing::global_cable<global_cable39_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable38_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable37_t_index, parameter::empty>>;

template <int NV>
using fix8_block_t = container::chain<parameter::empty, 
                                      wrap::fix<1, chain12_t<NV>>, 
                                      chain27_t<NV>, 
                                      math::clear<NV>, 
                                      math::clear<NV>, 
                                      pma1_t<NV>, 
                                      tempo_sync_t<NV>, 
                                      split1_t<NV>, 
                                      input_toggle_t<NV>, 
                                      ramp_t<NV>, 
                                      wrap::no_process<math::fmod<NV>>, 
                                      wrap::no_process<math::clear<NV>>, 
                                      branch_t<NV>, 
                                      pma_t<NV>, 
                                      branch1_t<NV>, 
                                      peak2_t, 
                                      branch2_t, 
                                      split_t>;

namespace modtest1_t_parameters
{
// Parameter list for modtest1_impl::modtest1_t ----------------------------------------------------

DECLARE_PARAMETER_RANGE(Tempo_InputRange, 
                        0., 
                        18.);
DECLARE_PARAMETER_RANGE(Tempo_0Range, 
                        5.55112e-17, 
                        1.);

template <int NV>
using Tempo_0 = parameter::from0To1<modtest1_impl::pma1_t<NV>, 
                                    2, 
                                    Tempo_0Range>;

template <int NV>
using Tempo = parameter::chain<Tempo_InputRange, Tempo_0<NV>>;

DECLARE_PARAMETER_RANGE(TempoSrc_InputRange, 
                        0., 
                        16.);
DECLARE_PARAMETER_RANGE_STEP(TempoSrc_0Range, 
                             0., 
                             15., 
                             1.);

template <int NV>
using TempoSrc_0 = parameter::from0To1<modtest1_impl::branch3_t<NV>, 
                                       0, 
                                       TempoSrc_0Range>;

template <int NV>
using TempoSrc = parameter::chain<TempoSrc_InputRange, TempoSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Shape_InputRange, 
                             1., 
                             7., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Shape_0Range, 
                             0., 
                             6., 
                             1.);

template <int NV>
using Shape_0 = parameter::from0To1<modtest1_impl::branch_t<NV>, 
                                    0, 
                                    Shape_0Range>;

template <int NV>
using Shape = parameter::chain<Shape_InputRange, Shape_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Modifiers_InputRange, 
                             1., 
                             5., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Modifiers_0Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using Modifiers_0 = parameter::from0To1<modtest1_impl::branch1_t<NV>, 
                                        0, 
                                        Modifiers_0Range>;

template <int NV>
using Modifiers = parameter::chain<Modifiers_InputRange, Modifiers_0<NV>>;

template <int NV>
using ModiferShape = parameter::from0To1<modtest1_impl::pma_t<NV>, 
                                         2, 
                                         Tempo_0Range>;

template <int NV>
using TempoMod = parameter::plain<modtest1_impl::pma1_t<NV>, 
                                  1>;
template <int NV>
using Div = parameter::plain<modtest1_impl::tempo_sync_t<NV>, 
                             1>;
template <int NV>
using oneshot = parameter::plain<modtest1_impl::ramp_t<NV>, 
                                 1>;
using OUTPUT = parameter::plain<modtest1_impl::branch2_t, 
                                0>;
template <int NV>
using Daw = parameter::plain<modtest1_impl::input_toggle_t<NV>, 
                             0>;
template <int NV>
using modtest1_t_plist = parameter::list<Tempo<NV>, 
                                         TempoMod<NV>, 
                                         TempoSrc<NV>, 
                                         Div<NV>, 
                                         Shape<NV>, 
                                         Modifiers<NV>, 
                                         ModiferShape<NV>, 
                                         oneshot<NV>, 
                                         OUTPUT, 
                                         Daw<NV>>;
}

template <int NV>
using modtest1_t_ = container::chain<modtest1_t_parameters::modtest1_t_plist<NV>, 
                                     wrap::fix<1, fix8_block_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public modtest1_impl::modtest1_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 1;
		static const int NumSliderPacks = 1;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 1;
		
		SNEX_METADATA_ID(modtest1);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(164)
		{
			0x005B, 0x0000, 0x5400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 
            0x9000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0001, 0x0000, 0x6554, 0x706D, 0x4D6F, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x253F, 0xF306, 0x003A, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0002, 0x0000, 0x6554, 0x706D, 0x536F, 0x6372, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0003, 0x0000, 0x6944, 0x0076, 0x0000, 0x3F80, 
            0x0000, 0x4200, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x045B, 0x0000, 0x5300, 0x6168, 0x6570, 0x0000, 0x8000, 0x003F, 
            0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0005, 0x0000, 0x6F4D, 0x6964, 0x6966, 0x7265, 0x0073, 0x0000, 
            0x3F80, 0x0000, 0x40A0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x065B, 0x0000, 0x4D00, 0x646F, 0x6669, 0x7265, 0x6853, 
            0x7061, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x80B6, 0x3F32, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x075B, 0x0000, 0x6F00, 0x656E, 
            0x6873, 0x746F, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0008, 0x0000, 0x554F, 
            0x5054, 0x5455, 0x0000, 0x0000, 0x0000, 0x4000, 0x0040, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0009, 0x0000, 0x6144, 
            0x0077, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& fix8_block = this->getT(0);                                      // modtest1_impl::fix8_block_t<NV>
		auto& chain12 = this->getT(0).getT(0);                                 // modtest1_impl::chain12_t<NV>
		auto& branch3 = this->getT(0).getT(0).getT(0);                         // modtest1_impl::branch3_t<NV>
		auto& chain = this->getT(0).getT(0).getT(0).getT(0);                   // modtest1_impl::chain_t<NV>
		auto& global_cable1 = this->getT(0).getT(0).getT(0).getT(0).getT(0);   // modtest1_impl::global_cable1_t<NV>
		auto& add2 = this->getT(0).getT(0).getT(0).getT(0).getT(1);            // math::add<NV>
		auto& chain2 = this->getT(0).getT(0).getT(0).getT(1);                  // modtest1_impl::chain2_t<NV>
		auto& global_cable2 = this->getT(0).getT(0).getT(0).getT(1).getT(0);   // modtest1_impl::global_cable2_t<NV>
		auto& add4 = this->getT(0).getT(0).getT(0).getT(1).getT(1);            // math::add<NV>
		auto& chain3 = this->getT(0).getT(0).getT(0).getT(2);                  // modtest1_impl::chain3_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(0).getT(2).getT(0);   // modtest1_impl::global_cable3_t<NV>
		auto& add5 = this->getT(0).getT(0).getT(0).getT(2).getT(1);            // math::add<NV>
		auto& chain4 = this->getT(0).getT(0).getT(0).getT(3);                  // modtest1_impl::chain4_t<NV>
		auto& global_cable4 = this->getT(0).getT(0).getT(0).getT(3).getT(0);   // modtest1_impl::global_cable4_t<NV>
		auto& add6 = this->getT(0).getT(0).getT(0).getT(3).getT(1);            // math::add<NV>
		auto& chain6 = this->getT(0).getT(0).getT(0).getT(4);                  // modtest1_impl::chain6_t<NV>
		auto& global_cable5 = this->getT(0).getT(0).getT(0).getT(4).getT(0);   // modtest1_impl::global_cable5_t<NV>
		auto& add7 = this->getT(0).getT(0).getT(0).getT(4).getT(1);            // math::add<NV>
		auto& chain7 = this->getT(0).getT(0).getT(0).getT(5);                  // modtest1_impl::chain7_t<NV>
		auto& global_cable6 = this->getT(0).getT(0).getT(0).getT(5).getT(0);   // modtest1_impl::global_cable6_t<NV>
		auto& add8 = this->getT(0).getT(0).getT(0).getT(5).getT(1);            // math::add<NV>
		auto& chain9 = this->getT(0).getT(0).getT(0).getT(6);                  // modtest1_impl::chain9_t<NV>
		auto& global_cable7 = this->getT(0).getT(0).getT(0).getT(6).getT(0);   // modtest1_impl::global_cable7_t<NV>
		auto& add9 = this->getT(0).getT(0).getT(0).getT(6).getT(1);            // math::add<NV>
		auto& chain10 = this->getT(0).getT(0).getT(0).getT(7);                 // modtest1_impl::chain10_t<NV>
		auto& global_cable8 = this->getT(0).getT(0).getT(0).getT(7).getT(0);   // modtest1_impl::global_cable8_t<NV>
		auto& add10 = this->getT(0).getT(0).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain14 = this->getT(0).getT(0).getT(0).getT(8);                 // modtest1_impl::chain14_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(0).getT(8).getT(0);  // modtest1_impl::global_cable10_t<NV>
		auto& add12 = this->getT(0).getT(0).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& chain15 = this->getT(0).getT(0).getT(0).getT(9);                 // modtest1_impl::chain15_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(0).getT(9).getT(0);  // modtest1_impl::global_cable11_t<NV>
		auto& add13 = this->getT(0).getT(0).getT(0).getT(9).getT(1);           // math::add<NV>
		auto& chain25 = this->getT(0).getT(0).getT(0).getT(10);                // modtest1_impl::chain25_t<NV>
		auto& global_cable12 = this->getT(0).getT(0).getT(0).getT(10).getT(0); // modtest1_impl::global_cable12_t<NV>
		auto& add14 = this->getT(0).getT(0).getT(0).getT(10).getT(1);          // math::add<NV>
		auto& chain17 = this->getT(0).getT(0).getT(0).getT(11);                // modtest1_impl::chain17_t<NV>
		auto& global_cable13 = this->getT(0).getT(0).getT(0).getT(11).getT(0); // modtest1_impl::global_cable13_t<NV>
		auto& add15 = this->getT(0).getT(0).getT(0).getT(11).getT(1);          // math::add<NV>
		auto& chain18 = this->getT(0).getT(0).getT(0).getT(12);                // modtest1_impl::chain18_t<NV>
		auto& global_cable14 = this->getT(0).getT(0).getT(0).getT(12).getT(0); // modtest1_impl::global_cable14_t<NV>
		auto& add16 = this->getT(0).getT(0).getT(0).getT(12).getT(1);          // math::add<NV>
		auto& chain19 = this->getT(0).getT(0).getT(0).getT(13);                // modtest1_impl::chain19_t<NV>
		auto& global_cable15 = this->getT(0).getT(0).getT(0).getT(13).getT(0); // modtest1_impl::global_cable15_t<NV>
		auto& add17 = this->getT(0).getT(0).getT(0).getT(13).getT(1);          // math::add<NV>
		auto& chain21 = this->getT(0).getT(0).getT(0).getT(14);                // modtest1_impl::chain21_t<NV>
		auto& global_cable16 = this->getT(0).getT(0).getT(0).getT(14).getT(0); // modtest1_impl::global_cable16_t<NV>
		auto& add18 = this->getT(0).getT(0).getT(0).getT(14).getT(1);          // math::add<NV>
		auto& chain22 = this->getT(0).getT(0).getT(0).getT(15);                // modtest1_impl::chain22_t<NV>
		auto& global_cable17 = this->getT(0).getT(0).getT(0).getT(15).getT(0); // modtest1_impl::global_cable17_t<NV>
		auto& add19 = this->getT(0).getT(0).getT(0).getT(15).getT(1);          // math::add<NV>
		auto& peak1 = this->getT(0).getT(0).getT(1);                           // modtest1_impl::peak1_t<NV>
		auto& clear = this->getT(0).getT(0).getT(2);                           // math::clear<NV>
		auto& chain27 = this->getT(0).getT(1);                                 // modtest1_impl::chain27_t<NV>
		auto& branch5 = this->getT(0).getT(1).getT(0);                         // modtest1_impl::branch5_t<NV>
		auto& chain28 = this->getT(0).getT(1).getT(0).getT(0);                 // modtest1_impl::chain28_t<NV>
		auto& global_cable19 = this->getT(0).getT(1).getT(0).getT(0).getT(0);  // modtest1_impl::global_cable19_t<NV>
		auto& add21 = this->getT(0).getT(1).getT(0).getT(0).getT(1);           // math::add<NV>
		auto& chain30 = this->getT(0).getT(1).getT(0).getT(1);                 // modtest1_impl::chain30_t<NV>
		auto& global_cable20 = this->getT(0).getT(1).getT(0).getT(1).getT(0);  // modtest1_impl::global_cable20_t<NV>
		auto& add22 = this->getT(0).getT(1).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain31 = this->getT(0).getT(1).getT(0).getT(2);                 // modtest1_impl::chain31_t<NV>
		auto& global_cable21 = this->getT(0).getT(1).getT(0).getT(2).getT(0);  // modtest1_impl::global_cable21_t<NV>
		auto& add23 = this->getT(0).getT(1).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain33 = this->getT(0).getT(1).getT(0).getT(3);                 // modtest1_impl::chain33_t<NV>
		auto& global_cable22 = this->getT(0).getT(1).getT(0).getT(3).getT(0);  // modtest1_impl::global_cable22_t<NV>
		auto& add24 = this->getT(0).getT(1).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& chain34 = this->getT(0).getT(1).getT(0).getT(4);                 // modtest1_impl::chain34_t<NV>
		auto& global_cable23 = this->getT(0).getT(1).getT(0).getT(4).getT(0);  // modtest1_impl::global_cable23_t<NV>
		auto& add25 = this->getT(0).getT(1).getT(0).getT(4).getT(1);           // math::add<NV>
		auto& chain36 = this->getT(0).getT(1).getT(0).getT(5);                 // modtest1_impl::chain36_t<NV>
		auto& global_cable24 = this->getT(0).getT(1).getT(0).getT(5).getT(0);  // modtest1_impl::global_cable24_t<NV>
		auto& add26 = this->getT(0).getT(1).getT(0).getT(5).getT(1);           // math::add<NV>
		auto& chain37 = this->getT(0).getT(1).getT(0).getT(6);                 // modtest1_impl::chain37_t<NV>
		auto& global_cable25 = this->getT(0).getT(1).getT(0).getT(6).getT(0);  // modtest1_impl::global_cable25_t<NV>
		auto& add27 = this->getT(0).getT(1).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain38 = this->getT(0).getT(1).getT(0).getT(7);                 // modtest1_impl::chain38_t<NV>
		auto& global_cable26 = this->getT(0).getT(1).getT(0).getT(7).getT(0);  // modtest1_impl::global_cable26_t<NV>
		auto& add28 = this->getT(0).getT(1).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain39 = this->getT(0).getT(1).getT(0).getT(8);                 // modtest1_impl::chain39_t<NV>
		auto& global_cable27 = this->getT(0).getT(1).getT(0).getT(8).getT(0);  // modtest1_impl::global_cable27_t<NV>
		auto& add29 = this->getT(0).getT(1).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& chain40 = this->getT(0).getT(1).getT(0).getT(9);                 // modtest1_impl::chain40_t<NV>
		auto& global_cable28 = this->getT(0).getT(1).getT(0).getT(9).getT(0);  // modtest1_impl::global_cable28_t<NV>
		auto& add30 = this->getT(0).getT(1).getT(0).getT(9).getT(1);           // math::add<NV>
		auto& chain42 = this->getT(0).getT(1).getT(0).getT(10);                // modtest1_impl::chain42_t<NV>
		auto& global_cable29 = this->getT(0).getT(1).getT(0).getT(10).getT(0); // modtest1_impl::global_cable29_t<NV>
		auto& add31 = this->getT(0).getT(1).getT(0).getT(10).getT(1);          // math::add<NV>
		auto& chain43 = this->getT(0).getT(1).getT(0).getT(11);                // modtest1_impl::chain43_t<NV>
		auto& global_cable30 = this->getT(0).getT(1).getT(0).getT(11).getT(0); // modtest1_impl::global_cable30_t<NV>
		auto& add32 = this->getT(0).getT(1).getT(0).getT(11).getT(1);          // math::add<NV>
		auto& chain52 = this->getT(0).getT(1).getT(0).getT(12);                // modtest1_impl::chain52_t<NV>
		auto& global_cable31 = this->getT(0).getT(1).getT(0).getT(12).getT(0); // modtest1_impl::global_cable31_t<NV>
		auto& add33 = this->getT(0).getT(1).getT(0).getT(12).getT(1);          // math::add<NV>
		auto& chain53 = this->getT(0).getT(1).getT(0).getT(13);                // modtest1_impl::chain53_t<NV>
		auto& global_cable32 = this->getT(0).getT(1).getT(0).getT(13).getT(0); // modtest1_impl::global_cable32_t<NV>
		auto& add34 = this->getT(0).getT(1).getT(0).getT(13).getT(1);          // math::add<NV>
		auto& chain54 = this->getT(0).getT(1).getT(0).getT(14);                // modtest1_impl::chain54_t<NV>
		auto& global_cable33 = this->getT(0).getT(1).getT(0).getT(14).getT(0); // modtest1_impl::global_cable33_t<NV>
		auto& add35 = this->getT(0).getT(1).getT(0).getT(14).getT(1);          // math::add<NV>
		auto& chain55 = this->getT(0).getT(1).getT(0).getT(15);                // modtest1_impl::chain55_t<NV>
		auto& global_cable34 = this->getT(0).getT(1).getT(0).getT(15).getT(0); // modtest1_impl::global_cable34_t<NV>
		auto& add36 = this->getT(0).getT(1).getT(0).getT(15).getT(1);          // math::add<NV>
		auto& peak4 = this->getT(0).getT(1).getT(1);                           // modtest1_impl::peak4_t<NV>
		auto& clear6 = this->getT(0).getT(2);                                  // math::clear<NV>
		auto& clear2 = this->getT(0).getT(3);                                  // math::clear<NV>
		auto& pma1 = this->getT(0).getT(4);                                    // modtest1_impl::pma1_t<NV>
		auto& tempo_sync = this->getT(0).getT(5);                              // modtest1_impl::tempo_sync_t<NV>
		auto& split1 = this->getT(0).getT(6);                                  // modtest1_impl::split1_t<NV>
		auto& transport = this->getT(0).getT(6).getT(0);                       // modtest1_impl::transport_t<NV>
		auto& input_toggle = this->getT(0).getT(7);                            // modtest1_impl::input_toggle_t<NV>
		auto& ramp = this->getT(0).getT(8);                                    // modtest1_impl::ramp_t<NV>
		auto& fmod1 = this->getT(0).getT(9);                                   // wrap::no_process<math::fmod<NV>>
		auto& clear1 = this->getT(0).getT(10);                                 // wrap::no_process<math::clear<NV>>
		auto& branch = this->getT(0).getT(11);                                 // modtest1_impl::branch_t<NV>
		auto& chain23 = this->getT(0).getT(11).getT(0);                        // modtest1_impl::chain23_t<NV>
		auto& clear4 = this->getT(0).getT(11).getT(0).getT(0);                 // math::clear<NV>
		auto& converter = this->getT(0).getT(11).getT(0).getT(1);              // modtest1_impl::converter_t<NV>
		auto& oscillator1 = this->getT(0).getT(11).getT(0).getT(2);            // modtest1_impl::oscillator1_t<NV>
		auto& sig2mod = this->getT(0).getT(11).getT(0).getT(3);                // math::sig2mod<NV>
		auto& chain8 = this->getT(0).getT(11).getT(1);                         // modtest1_impl::chain8_t<NV>
		auto& pi1 = this->getT(0).getT(11).getT(1).getT(0);                    // wrap::no_process<math::pi<NV>>
		auto& rect1 = this->getT(0).getT(11).getT(1).getT(1);                  // math::rect<NV>
		auto& chain5 = this->getT(0).getT(11).getT(2);                         // modtest1_impl::chain5_t
		auto& chain41 = this->getT(0).getT(11).getT(3);                        // modtest1_impl::chain41_t<NV>
		auto& clear13 = this->getT(0).getT(11).getT(3).getT(0);                // wrap::no_process<math::clear<NV>>
		auto& expr7 = this->getT(0).getT(11).getT(3).getT(1);                  // math::expr<NV, custom::expr7>
		auto& sig2mod9 = this->getT(0).getT(11).getT(3).getT(2);               // wrap::no_process<math::sig2mod<NV>>
		auto& peak5 = this->getT(0).getT(11).getT(3).getT(3);                  // modtest1_impl::peak5_t
		auto& chain32 = this->getT(0).getT(11).getT(4);                        // modtest1_impl::chain32_t<NV>
		auto& oscillator = this->getT(0).getT(11).getT(4).getT(0);             // modtest1_impl::oscillator_t<NV>
		auto& pi = this->getT(0).getT(11).getT(4).getT(1);                     // wrap::no_process<math::pi<NV>>
		auto& sampleandhold1 = this->getT(0).getT(11).getT(4).getT(2);         // fx::sampleandhold<NV>
		auto& sig2mod7 = this->getT(0).getT(11).getT(4).getT(3);               // math::sig2mod<NV>
		auto& chain20 = this->getT(0).getT(11).getT(5);                        // modtest1_impl::chain20_t<NV>
		auto& clear15 = this->getT(0).getT(11).getT(5).getT(0);                // math::clear<NV>
		auto& cable_table = this->getT(0).getT(11).getT(5).getT(1);            // modtest1_impl::cable_table_t<NV>
		auto& add = this->getT(0).getT(11).getT(5).getT(2);                    // math::add<NV>
		auto& chain26 = this->getT(0).getT(11).getT(6);                        // modtest1_impl::chain26_t<NV>
		auto& clear5 = this->getT(0).getT(11).getT(6).getT(0);                 // math::clear<NV>
		auto& cable_pack = this->getT(0).getT(11).getT(6).getT(1);             // modtest1_impl::cable_pack_t<NV>
		auto& add1 = this->getT(0).getT(11).getT(6).getT(2);                   // math::add<NV>
		auto& pma = this->getT(0).getT(12);                                    // modtest1_impl::pma_t<NV>
		auto& branch1 = this->getT(0).getT(13);                                // modtest1_impl::branch1_t<NV>
		auto& chain1 = this->getT(0).getT(13).getT(0);                         // modtest1_impl::chain1_t
		auto& chain29 = this->getT(0).getT(13).getT(1);                        // modtest1_impl::chain29_t<NV>
		auto& expr3 = this->getT(0).getT(13).getT(1).getT(0);                  // math::expr<NV, custom::expr3>
		auto& chain35 = this->getT(0).getT(13).getT(2);                        // modtest1_impl::chain35_t<NV>
		auto& expr5 = this->getT(0).getT(13).getT(2).getT(0);                  // math::expr<NV, custom::expr5>
		auto& chain44 = this->getT(0).getT(13).getT(3);                        // modtest1_impl::chain44_t<NV>
		auto& expr8 = this->getT(0).getT(13).getT(3).getT(0);                  // math::expr<NV, custom::expr8>
		auto& chain45 = this->getT(0).getT(13).getT(4);                        // modtest1_impl::chain45_t<NV>
		auto& expr9 = this->getT(0).getT(13).getT(4).getT(0);                  // math::expr<NV, custom::expr9>
		auto& peak2 = this->getT(0).getT(14);                                  // modtest1_impl::peak2_t
		auto& branch2 = this->getT(0).getT(15);                                // modtest1_impl::branch2_t
		auto& chain13 = this->getT(0).getT(15).getT(0);                        // modtest1_impl::chain13_t
		auto& peak3 = this->getT(0).getT(15).getT(0).getT(0);                  // modtest1_impl::peak3_t
		auto& chain16 = this->getT(0).getT(15).getT(1);                        // modtest1_impl::chain16_t
		auto& peak9 = this->getT(0).getT(15).getT(1).getT(0);                  // modtest1_impl::peak9_t
		auto& chain24 = this->getT(0).getT(15).getT(2);                        // modtest1_impl::chain24_t
		auto& peak8 = this->getT(0).getT(15).getT(2).getT(0);                  // modtest1_impl::peak8_t
		auto& chain50 = this->getT(0).getT(15).getT(3);                        // modtest1_impl::chain50_t
		auto& peak7 = this->getT(0).getT(15).getT(3).getT(0);                  // modtest1_impl::peak7_t
		auto& split = this->getT(0).getT(16);                                  // modtest1_impl::split_t
		auto& global_cable = this->getT(0).getT(16).getT(0);                   // routing::global_cable<global_cable_t_index, parameter::empty>
		auto& global_cable39 = this->getT(0).getT(16).getT(1);                 // routing::global_cable<global_cable39_t_index, parameter::empty>
		auto& global_cable38 = this->getT(0).getT(16).getT(2);                 // routing::global_cable<global_cable38_t_index, parameter::empty>
		auto& global_cable37 = this->getT(0).getT(16).getT(3);                 // routing::global_cable<global_cable37_t_index, parameter::empty>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma1); // Tempo -> pma1::Add
		
		this->getParameterT(1).connectT(0, pma1); // TempoMod -> pma1::Multiply
		
		this->getParameterT(2).connectT(0, branch3); // TempoSrc -> branch3::Index
		
		this->getParameterT(3).connectT(0, tempo_sync); // Div -> tempo_sync::Multiplier
		
		this->getParameterT(4).connectT(0, branch); // Shape -> branch::Index
		
		this->getParameterT(5).connectT(0, branch1); // Modifiers -> branch1::Index
		
		this->getParameterT(6).connectT(0, pma); // ModiferShape -> pma::Add
		
		this->getParameterT(7).connectT(0, ramp); // oneshot -> ramp::LoopStart
		
		this->getParameterT(8).connectT(0, branch2); // OUTPUT -> branch2::Index
		
		this->getParameterT(9).connectT(0, input_toggle); // Daw -> input_toggle::Input
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable1.getWrappedObject().getParameter().connectT(0, add2);       // global_cable1 -> add2::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, add4);       // global_cable2 -> add4::Value
		global_cable3.getWrappedObject().getParameter().connectT(0, add5);       // global_cable3 -> add5::Value
		global_cable4.getWrappedObject().getParameter().connectT(0, add6);       // global_cable4 -> add6::Value
		global_cable5.getWrappedObject().getParameter().connectT(0, add7);       // global_cable5 -> add7::Value
		global_cable6.getWrappedObject().getParameter().connectT(0, add8);       // global_cable6 -> add8::Value
		global_cable7.getWrappedObject().getParameter().connectT(0, add9);       // global_cable7 -> add9::Value
		global_cable8.getWrappedObject().getParameter().connectT(0, add10);      // global_cable8 -> add10::Value
		global_cable10.getWrappedObject().getParameter().connectT(0, add12);     // global_cable10 -> add12::Value
		global_cable11.getWrappedObject().getParameter().connectT(0, add13);     // global_cable11 -> add13::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, add14);     // global_cable12 -> add14::Value
		global_cable13.getWrappedObject().getParameter().connectT(0, add15);     // global_cable13 -> add15::Value
		global_cable14.getWrappedObject().getParameter().connectT(0, add16);     // global_cable14 -> add16::Value
		global_cable15.getWrappedObject().getParameter().connectT(0, add17);     // global_cable15 -> add17::Value
		global_cable16.getWrappedObject().getParameter().connectT(0, add18);     // global_cable16 -> add18::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add19);     // global_cable17 -> add19::Value
		cable_table.getWrappedObject().getParameter().connectT(0, add);          // cable_table -> add::Value
		cable_pack.getWrappedObject().getParameter().connectT(0, add1);          // cable_pack -> add1::Value
		ramp.getParameter().connectT(0, expr7);                                  // ramp -> expr7::Value
		ramp.getParameter().connectT(1, cable_table);                            // ramp -> cable_table::Value
		ramp.getParameter().connectT(2, cable_pack);                             // ramp -> cable_pack::Value
		converter.getWrappedObject().getParameter().connectT(0, oscillator1);    // converter -> oscillator1::Frequency
		tempo_sync.getParameter().connectT(0, ramp);                             // tempo_sync -> ramp::PeriodTime
		tempo_sync.getParameter().connectT(1, sampleandhold1);                   // tempo_sync -> sampleandhold1::Counter
		tempo_sync.getParameter().connectT(2, converter);                        // tempo_sync -> converter::Value
		pma1.getWrappedObject().getParameter().connectT(0, tempo_sync);          // pma1 -> tempo_sync::Tempo
		peak1.getParameter().connectT(0, pma1);                                  // peak1 -> pma1::Value
		global_cable19.getWrappedObject().getParameter().connectT(0, add21);     // global_cable19 -> add21::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, add22);     // global_cable20 -> add22::Value
		global_cable21.getWrappedObject().getParameter().connectT(0, add23);     // global_cable21 -> add23::Value
		global_cable22.getWrappedObject().getParameter().connectT(0, add24);     // global_cable22 -> add24::Value
		global_cable23.getWrappedObject().getParameter().connectT(0, add25);     // global_cable23 -> add25::Value
		global_cable24.getWrappedObject().getParameter().connectT(0, add26);     // global_cable24 -> add26::Value
		global_cable25.getWrappedObject().getParameter().connectT(0, add27);     // global_cable25 -> add27::Value
		global_cable26.getWrappedObject().getParameter().connectT(0, add28);     // global_cable26 -> add28::Value
		global_cable27.getWrappedObject().getParameter().connectT(0, add29);     // global_cable27 -> add29::Value
		global_cable28.getWrappedObject().getParameter().connectT(0, add30);     // global_cable28 -> add30::Value
		global_cable29.getWrappedObject().getParameter().connectT(0, add31);     // global_cable29 -> add31::Value
		global_cable30.getWrappedObject().getParameter().connectT(0, add32);     // global_cable30 -> add32::Value
		global_cable31.getWrappedObject().getParameter().connectT(0, add33);     // global_cable31 -> add33::Value
		global_cable32.getWrappedObject().getParameter().connectT(0, add34);     // global_cable32 -> add34::Value
		global_cable33.getWrappedObject().getParameter().connectT(0, add35);     // global_cable33 -> add35::Value
		global_cable34.getWrappedObject().getParameter().connectT(0, add36);     // global_cable34 -> add36::Value
		pma.getWrappedObject().getParameter().connectT(0, expr3);                // pma -> expr3::Value
		pma.getWrappedObject().getParameter().connectT(1, expr5);                // pma -> expr5::Value
		pma.getWrappedObject().getParameter().connectT(2, expr8);                // pma -> expr8::Value
		pma.getWrappedObject().getParameter().connectT(3, expr9);                // pma -> expr9::Value
		peak4.getParameter().connectT(0, pma);                                   // peak4 -> pma::Value
		input_toggle.getWrappedObject().getParameter().connectT(0, ramp);        // input_toggle -> ramp::Gate
		input_toggle.getWrappedObject().getParameter().connectT(1, oscillator1); // input_toggle -> oscillator1::Gate
		transport.getParameter().connectT(0, input_toggle);                      // transport -> input_toggle::Value2
		peak3.getParameter().connectT(0, global_cable);                          // peak3 -> global_cable::Value
		peak9.getParameter().connectT(0, global_cable39);                        // peak9 -> global_cable39::Value
		peak8.getParameter().connectT(0, global_cable38);                        // peak8 -> global_cable38::Value
		peak7.getParameter().connectT(0, global_cable37);                        // peak7 -> global_cable37::Value
		
		// Default Values --------------------------------------------------------------------------
		
		; // branch3::Index is automated
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add2::Value is automated
		
		global_cable2.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add4::Value is automated
		
		global_cable3.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add5::Value is automated
		
		global_cable4.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add6::Value is automated
		
		global_cable5.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add7::Value is automated
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add8::Value is automated
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add9::Value is automated
		
		global_cable8.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add10::Value is automated
		
		global_cable10.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add12::Value is automated
		
		global_cable11.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add13::Value is automated
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add14::Value is automated
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add15::Value is automated
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add16::Value is automated
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add17::Value is automated
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add18::Value is automated
		
		global_cable17.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add19::Value is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		branch5.setParameterT(0, 0.); // container::branch::Index
		
		global_cable19.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add21::Value is automated
		
		global_cable20.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add22::Value is automated
		
		global_cable21.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add23::Value is automated
		
		global_cable22.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add24::Value is automated
		
		global_cable23.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add25::Value is automated
		
		global_cable24.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add26::Value is automated
		
		global_cable25.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add27::Value is automated
		
		global_cable26.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add28::Value is automated
		
		global_cable27.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add29::Value is automated
		
		global_cable28.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add30::Value is automated
		
		global_cable29.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add31::Value is automated
		
		global_cable30.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add32::Value is automated
		
		global_cable31.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add33::Value is automated
		
		global_cable32.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add34::Value is automated
		
		global_cable33.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add35::Value is automated
		
		global_cable34.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add36::Value is automated
		
		clear6.setParameterT(0, 0.); // math::clear::Value
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		;                                  // tempo_sync::Tempo is automated
		;                                  // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                                  // input_toggle::Input is automated
		input_toggle.setParameterT(1, 1.); // control::input_toggle::Value1
		;                                  // input_toggle::Value2 is automated
		
		; // ramp::PeriodTime is automated
		; // ramp::LoopStart is automated
		; // ramp::Gate is automated
		
		fmod1.setParameterT(0, 0.614986); // math::fmod::Value
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		; // branch::Index is automated
		
		clear4.setParameterT(0, 0.); // math::clear::Value
		
		; // converter::Value is automated
		
		oscillator1.setParameterT(0, 0.);       // core::oscillator::Mode
		;                                       // oscillator1::Frequency is automated
		oscillator1.setParameterT(2, 0.956748); // core::oscillator::FreqRatio
		;                                       // oscillator1::Gate is automated
		oscillator1.setParameterT(4, 0.);       // core::oscillator::Phase
		oscillator1.setParameterT(5, 0.949092); // core::oscillator::Gain
		
		sig2mod.setParameterT(0, 0.); // math::sig2mod::Value
		
		pi1.setParameterT(0, 2.); // math::pi::Value
		
		rect1.setParameterT(0, 0.166743); // math::rect::Value
		
		clear13.setParameterT(0, 0.); // math::clear::Value
		
		; // expr7::Value is automated
		
		sig2mod9.setParameterT(0, 0.); // math::sig2mod::Value
		
		oscillator.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator.setParameterT(1, 220.); // core::oscillator::Frequency
		oscillator.setParameterT(2, 1.);   // core::oscillator::FreqRatio
		oscillator.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator.setParameterT(5, 1.);   // core::oscillator::Gain
		
		pi.setParameterT(0, 1.); // math::pi::Value
		
		; // sampleandhold1::Counter is automated
		
		sig2mod7.setParameterT(0, 0.); // math::sig2mod::Value
		
		clear15.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_table::Value is automated
		
		; // add::Value is automated
		
		clear5.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_pack::Value is automated
		
		; // add1::Value is automated
		
		;                         // pma::Value is automated
		pma.setParameterT(1, 0.); // control::pma::Multiply
		;                         // pma::Add is automated
		
		; // branch1::Index is automated
		
		; // expr3::Value is automated
		
		; // expr5::Value is automated
		
		; // expr8::Value is automated
		
		; // expr9::Value is automated
		
		; // branch2::Index is automated
		
		; // global_cable::Value is automated
		
		; // global_cable39::Value is automated
		
		; // global_cable38::Value is automated
		
		; // global_cable37::Value is automated
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 0.00185413);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 0.697276);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 0.);
		this->setParameterT(9, 0.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable1_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable2_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable3_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable4_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable5_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable6_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable7_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable8_t<NV>
		this->getT(0).getT(0).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable10_t<NV>
		this->getT(0).getT(0).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable11_t<NV>
		this->getT(0).getT(0).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable12_t<NV>
		this->getT(0).getT(0).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable13_t<NV>
		this->getT(0).getT(0).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable14_t<NV>
		this->getT(0).getT(0).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable15_t<NV>
		this->getT(0).getT(0).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable16_t<NV>
		this->getT(0).getT(0).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable17_t<NV>
		this->getT(0).getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable19_t<NV>
		this->getT(0).getT(1).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable20_t<NV>
		this->getT(0).getT(1).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable21_t<NV>
		this->getT(0).getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable22_t<NV>
		this->getT(0).getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable23_t<NV>
		this->getT(0).getT(1).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable24_t<NV>
		this->getT(0).getT(1).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable25_t<NV>
		this->getT(0).getT(1).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable26_t<NV>
		this->getT(0).getT(1).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable27_t<NV>
		this->getT(0).getT(1).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable28_t<NV>
		this->getT(0).getT(1).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable29_t<NV>
		this->getT(0).getT(1).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable30_t<NV>
		this->getT(0).getT(1).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable31_t<NV>
		this->getT(0).getT(1).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable32_t<NV>
		this->getT(0).getT(1).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable33_t<NV>
		this->getT(0).getT(1).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable34_t<NV>
		this->getT(0).getT(16).getT(0).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable_t_index, parameter::empty>
		this->getT(0).getT(16).getT(1).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable39_t_index, parameter::empty>
		this->getT(0).getT(16).getT(2).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable38_t_index, parameter::empty>
		this->getT(0).getT(16).getT(3).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable37_t_index, parameter::empty>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).setExternalData(b, index);          // modtest1_impl::peak1_t<NV>
		this->getT(0).getT(1).getT(1).setExternalData(b, index);          // modtest1_impl::peak4_t<NV>
		this->getT(0).getT(8).setExternalData(b, index);                  // modtest1_impl::ramp_t<NV>
		this->getT(0).getT(11).getT(0).getT(2).setExternalData(b, index); // modtest1_impl::oscillator1_t<NV>
		this->getT(0).getT(11).getT(3).getT(3).setExternalData(b, index); // modtest1_impl::peak5_t
		this->getT(0).getT(11).getT(4).getT(0).setExternalData(b, index); // modtest1_impl::oscillator_t<NV>
		this->getT(0).getT(11).getT(5).getT(1).setExternalData(b, index); // modtest1_impl::cable_table_t<NV>
		this->getT(0).getT(11).getT(6).getT(1).setExternalData(b, index); // modtest1_impl::cable_pack_t<NV>
		this->getT(0).getT(14).setExternalData(b, index);                 // modtest1_impl::peak2_t
		this->getT(0).getT(15).getT(0).getT(0).setExternalData(b, index); // modtest1_impl::peak3_t
		this->getT(0).getT(15).getT(1).getT(0).setExternalData(b, index); // modtest1_impl::peak9_t
		this->getT(0).getT(15).getT(2).getT(0).setExternalData(b, index); // modtest1_impl::peak8_t
		this->getT(0).getT(15).getT(3).getT(0).setExternalData(b, index); // modtest1_impl::peak7_t
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
using modtest1 = wrap::node<modtest1_impl::instance<NV>>;
}


