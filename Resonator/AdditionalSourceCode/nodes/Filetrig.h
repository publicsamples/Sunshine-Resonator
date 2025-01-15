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

namespace Filetrig_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using oscillator_t = wrap::no_data<core::oscillator<NV>>;
template <int NV>
using input_toggle_t = control::input_toggle<parameter::plain<oscillator_t<NV>, 1>>;
template <int NV>
using converter_t = control::converter<parameter::plain<input_toggle_t<NV>, 2>, 
                                       conversion_logic::ms2freq>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<converter_t<NV>, 0>, 
                               control::tempo_sync<NV>>;

template <int NV>
using minmax1_t = control::minmax<NV, 
                                  parameter::plain<oscillator_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_SKEW(xfader_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using xfader_c0 = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      xfader_c0Range>;

template <int NV> using xfader_c1 = xfader_c0<NV>;

template <int NV> using xfader_c2 = xfader_c0<NV>;

template <int NV> using xfader_c3 = xfader_c0<NV>;

template <int NV> using xfader_c4 = xfader_c0<NV>;

template <int NV> using xfader_c5 = xfader_c0<NV>;

template <int NV> using xfader_c6 = xfader_c0<NV>;

template <int NV> using xfader_c7 = xfader_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, 
                                        xfader_c1<NV>, 
                                        xfader_c2<NV>, 
                                        xfader_c3<NV>, 
                                        xfader_c4<NV>, 
                                        xfader_c5<NV>, 
                                        xfader_c6<NV>, 
                                        xfader_c7<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::switcher>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, math::add<NV>>, 
                                  core::gain<NV>>;

template <int NV> using chain108_t = chain1_t<NV>;

template <int NV> using chain107_t = chain1_t<NV>;

template <int NV> using chain106_t = chain1_t<NV>;

template <int NV> using chain105_t = chain1_t<NV>;

template <int NV> using chain104_t = chain1_t<NV>;

template <int NV> using chain103_t = chain1_t<NV>;

template <int NV> using chain102_t = chain1_t<NV>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain1_t<NV>>, 
                                  chain108_t<NV>, 
                                  chain107_t<NV>, 
                                  chain106_t<NV>, 
                                  chain105_t<NV>, 
                                  chain104_t<NV>, 
                                  chain103_t<NV>, 
                                  chain102_t<NV>>;

template <int NV>
using chain101_t = container::chain<parameter::empty, 
                                    wrap::fix<2, xfader_t<NV>>, 
                                    split1_t<NV>>;

template <int NV>
using soft_bypass_t_ = container::chain<parameter::empty, 
                                        wrap::fix<2, chain101_t<NV>>>;

template <int NV>
using soft_bypass_t = bypass::smoothed<20, soft_bypass_t_<NV>>;
template <int NV>
using xfader2_c0 = parameter::bypass<soft_bypass_t<NV>>;

template <int NV> using xfader1_c0 = xfader_c0<NV>;

template <int NV> using xfader1_c1 = xfader_c0<NV>;

template <int NV> using xfader1_c2 = xfader_c0<NV>;

template <int NV> using xfader1_c3 = xfader_c0<NV>;

template <int NV> using xfader1_c4 = xfader_c0<NV>;

template <int NV> using xfader1_c5 = xfader_c0<NV>;

template <int NV> using xfader1_c6 = xfader_c0<NV>;

template <int NV> using xfader1_c7 = xfader_c0<NV>;

template <int NV>
using xfader1_multimod = parameter::list<xfader1_c0<NV>, 
                                         xfader1_c1<NV>, 
                                         xfader1_c2<NV>, 
                                         xfader1_c3<NV>, 
                                         xfader1_c4<NV>, 
                                         xfader1_c5<NV>, 
                                         xfader1_c6<NV>, 
                                         xfader1_c7<NV>>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::switcher>;

template <int NV> using chain110_t = chain1_t<NV>;

template <int NV> using chain111_t = chain1_t<NV>;

template <int NV> using chain112_t = chain1_t<NV>;

template <int NV> using chain113_t = chain1_t<NV>;

template <int NV> using chain114_t = chain1_t<NV>;

template <int NV> using chain115_t = chain1_t<NV>;

template <int NV> using chain116_t = chain1_t<NV>;

template <int NV> using chain117_t = chain1_t<NV>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain110_t<NV>>, 
                                  chain111_t<NV>, 
                                  chain112_t<NV>, 
                                  chain113_t<NV>, 
                                  chain114_t<NV>, 
                                  chain115_t<NV>, 
                                  chain116_t<NV>, 
                                  chain117_t<NV>>;

template <int NV>
using chain109_t = container::chain<parameter::empty, 
                                    wrap::fix<2, xfader1_t<NV>>, 
                                    split2_t<NV>>;

template <int NV>
using soft_bypass1_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, chain109_t<NV>>>;

template <int NV>
using soft_bypass1_t = bypass::smoothed<20, soft_bypass1_t_<NV>>;
template <int NV>
using xfader2_c1 = parameter::bypass<soft_bypass1_t<NV>>;

template <int NV> using xfader3_c0 = xfader_c0<NV>;

template <int NV> using xfader3_c1 = xfader_c0<NV>;

template <int NV> using xfader3_c2 = xfader_c0<NV>;

template <int NV> using xfader3_c3 = xfader_c0<NV>;

template <int NV> using xfader3_c4 = xfader_c0<NV>;

template <int NV> using xfader3_c5 = xfader_c0<NV>;

template <int NV> using xfader3_c6 = xfader_c0<NV>;

template <int NV> using xfader3_c7 = xfader_c0<NV>;

template <int NV>
using xfader3_multimod = parameter::list<xfader3_c0<NV>, 
                                         xfader3_c1<NV>, 
                                         xfader3_c2<NV>, 
                                         xfader3_c3<NV>, 
                                         xfader3_c4<NV>, 
                                         xfader3_c5<NV>, 
                                         xfader3_c6<NV>, 
                                         xfader3_c7<NV>>;

template <int NV>
using xfader3_t = control::xfader<xfader3_multimod<NV>, faders::switcher>;

template <int NV> using chain119_t = chain1_t<NV>;

template <int NV> using chain120_t = chain1_t<NV>;

template <int NV> using chain121_t = chain1_t<NV>;

template <int NV> using chain122_t = chain1_t<NV>;

template <int NV> using chain123_t = chain1_t<NV>;

template <int NV> using chain124_t = chain1_t<NV>;

template <int NV> using chain125_t = chain1_t<NV>;

template <int NV> using chain126_t = chain1_t<NV>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain119_t<NV>>, 
                                  chain120_t<NV>, 
                                  chain121_t<NV>, 
                                  chain122_t<NV>, 
                                  chain123_t<NV>, 
                                  chain124_t<NV>, 
                                  chain125_t<NV>, 
                                  chain126_t<NV>>;

template <int NV>
using chain118_t = container::chain<parameter::empty, 
                                    wrap::fix<2, xfader3_t<NV>>, 
                                    split3_t<NV>>;

template <int NV>
using soft_bypass2_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, chain118_t<NV>>>;

template <int NV>
using soft_bypass2_t = bypass::smoothed<20, soft_bypass2_t_<NV>>;
template <int NV>
using xfader2_c2 = parameter::bypass<soft_bypass2_t<NV>>;

template <int NV> using xfader4_c0 = xfader_c0<NV>;

template <int NV> using xfader4_c1 = xfader_c0<NV>;

template <int NV> using xfader4_c2 = xfader_c0<NV>;

template <int NV> using xfader4_c3 = xfader_c0<NV>;

template <int NV> using xfader4_c4 = xfader_c0<NV>;

template <int NV> using xfader4_c5 = xfader_c0<NV>;

template <int NV> using xfader4_c6 = xfader_c0<NV>;

template <int NV> using xfader4_c7 = xfader_c0<NV>;

template <int NV>
using xfader4_multimod = parameter::list<xfader4_c0<NV>, 
                                         xfader4_c1<NV>, 
                                         xfader4_c2<NV>, 
                                         xfader4_c3<NV>, 
                                         xfader4_c4<NV>, 
                                         xfader4_c5<NV>, 
                                         xfader4_c6<NV>, 
                                         xfader4_c7<NV>>;

template <int NV>
using xfader4_t = control::xfader<xfader4_multimod<NV>, faders::switcher>;

template <int NV> using chain128_t = chain1_t<NV>;

template <int NV> using chain129_t = chain1_t<NV>;

template <int NV> using chain130_t = chain1_t<NV>;

template <int NV> using chain131_t = chain1_t<NV>;

template <int NV> using chain132_t = chain1_t<NV>;

template <int NV> using chain133_t = chain1_t<NV>;

template <int NV> using chain134_t = chain1_t<NV>;

template <int NV> using chain135_t = chain1_t<NV>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain128_t<NV>>, 
                                  chain129_t<NV>, 
                                  chain130_t<NV>, 
                                  chain131_t<NV>, 
                                  chain132_t<NV>, 
                                  chain133_t<NV>, 
                                  chain134_t<NV>, 
                                  chain135_t<NV>>;

template <int NV>
using chain127_t = container::chain<parameter::empty, 
                                    wrap::fix<2, xfader4_t<NV>>, 
                                    split4_t<NV>>;

template <int NV>
using soft_bypass3_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, chain127_t<NV>>>;

template <int NV>
using soft_bypass3_t = bypass::smoothed<20, soft_bypass3_t_<NV>>;
template <int NV>
using xfader2_c3 = parameter::bypass<soft_bypass3_t<NV>>;

template <int NV> using xfader5_c0 = xfader_c0<NV>;

template <int NV> using xfader5_c1 = xfader_c0<NV>;

template <int NV> using xfader5_c2 = xfader_c0<NV>;

template <int NV> using xfader5_c3 = xfader_c0<NV>;

template <int NV> using xfader5_c4 = xfader_c0<NV>;

template <int NV> using xfader5_c5 = xfader_c0<NV>;

template <int NV> using xfader5_c6 = xfader_c0<NV>;

template <int NV> using xfader5_c7 = xfader_c0<NV>;

template <int NV>
using xfader5_multimod = parameter::list<xfader5_c0<NV>, 
                                         xfader5_c1<NV>, 
                                         xfader5_c2<NV>, 
                                         xfader5_c3<NV>, 
                                         xfader5_c4<NV>, 
                                         xfader5_c5<NV>, 
                                         xfader5_c6<NV>, 
                                         xfader5_c7<NV>>;

template <int NV>
using xfader5_t = control::xfader<xfader5_multimod<NV>, faders::switcher>;

template <int NV> using chain137_t = chain1_t<NV>;

template <int NV> using chain138_t = chain1_t<NV>;

template <int NV> using chain139_t = chain1_t<NV>;

template <int NV> using chain140_t = chain1_t<NV>;

template <int NV> using chain141_t = chain1_t<NV>;

template <int NV> using chain142_t = chain1_t<NV>;

template <int NV> using chain143_t = chain1_t<NV>;

template <int NV> using chain144_t = chain1_t<NV>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain137_t<NV>>, 
                                  chain138_t<NV>, 
                                  chain139_t<NV>, 
                                  chain140_t<NV>, 
                                  chain141_t<NV>, 
                                  chain142_t<NV>, 
                                  chain143_t<NV>, 
                                  chain144_t<NV>>;

template <int NV>
using chain136_t = container::chain<parameter::empty, 
                                    wrap::fix<2, xfader5_t<NV>>, 
                                    split5_t<NV>>;

template <int NV>
using soft_bypass4_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, chain136_t<NV>>>;

template <int NV>
using soft_bypass4_t = bypass::smoothed<20, soft_bypass4_t_<NV>>;
template <int NV>
using xfader2_c4 = parameter::bypass<soft_bypass4_t<NV>>;

template <int NV> using xfader6_c0 = xfader_c0<NV>;

template <int NV> using xfader6_c1 = xfader_c0<NV>;

template <int NV> using xfader6_c2 = xfader_c0<NV>;

template <int NV> using xfader6_c3 = xfader_c0<NV>;

template <int NV> using xfader6_c4 = xfader_c0<NV>;

template <int NV> using xfader6_c5 = xfader_c0<NV>;

template <int NV> using xfader6_c6 = xfader_c0<NV>;

template <int NV> using xfader6_c7 = xfader_c0<NV>;

template <int NV>
using xfader6_multimod = parameter::list<xfader6_c0<NV>, 
                                         xfader6_c1<NV>, 
                                         xfader6_c2<NV>, 
                                         xfader6_c3<NV>, 
                                         xfader6_c4<NV>, 
                                         xfader6_c5<NV>, 
                                         xfader6_c6<NV>, 
                                         xfader6_c7<NV>>;

template <int NV>
using xfader6_t = control::xfader<xfader6_multimod<NV>, faders::switcher>;

template <int NV> using chain146_t = chain1_t<NV>;

template <int NV> using chain147_t = chain1_t<NV>;

template <int NV> using chain148_t = chain1_t<NV>;

template <int NV> using chain149_t = chain1_t<NV>;

template <int NV> using chain150_t = chain1_t<NV>;

template <int NV> using chain151_t = chain1_t<NV>;

template <int NV> using chain152_t = chain1_t<NV>;

template <int NV> using chain153_t = chain1_t<NV>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain146_t<NV>>, 
                                  chain147_t<NV>, 
                                  chain148_t<NV>, 
                                  chain149_t<NV>, 
                                  chain150_t<NV>, 
                                  chain151_t<NV>, 
                                  chain152_t<NV>, 
                                  chain153_t<NV>>;

template <int NV>
using chain145_t = container::chain<parameter::empty, 
                                    wrap::fix<2, xfader6_t<NV>>, 
                                    split6_t<NV>>;

template <int NV>
using soft_bypass5_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, chain145_t<NV>>>;

template <int NV>
using soft_bypass5_t = bypass::smoothed<20, soft_bypass5_t_<NV>>;
template <int NV>
using xfader2_c5 = parameter::bypass<soft_bypass5_t<NV>>;

template <int NV>
using xfader2_multimod = parameter::list<xfader2_c0<NV>, 
                                         xfader2_c1<NV>, 
                                         xfader2_c2<NV>, 
                                         xfader2_c3<NV>, 
                                         xfader2_c4<NV>, 
                                         xfader2_c5<NV>>;

template <int NV>
using xfader2_t = control::xfader<xfader2_multimod<NV>, faders::switcher>;

struct cable_table_t_data
{
	span<float, 512> data =
	{
		0.f, 0.0141121f, 0.0282241f, 0.0423362f, 0.0564483f, 0.0705603f,
		0.0846724f, 0.0987845f, 0.112897f, 0.127009f, 0.141121f, 0.155233f,
		0.169345f, 0.183457f, 0.197569f, 0.211681f, 0.225793f, 0.239905f,
		0.254017f, 0.268129f, 0.282241f, 0.296353f, 0.310466f, 0.324578f,
		0.33869f, 0.352802f, 0.366914f, 0.381026f, 0.395138f, 0.40925f,
		0.423362f, 0.437474f, 0.451586f, 0.465698f, 0.47981f, 0.493922f,
		0.508035f, 0.522147f, 0.536259f, 0.550371f, 0.564483f, 0.578595f,
		0.592707f, 0.606819f, 0.620931f, 0.635043f, 0.649155f, 0.663267f,
		0.677379f, 0.691491f, 0.705603f, 0.719716f, 0.733828f, 0.74794f,
		0.762052f, 0.776164f, 0.790276f, 0.804388f, 0.8185f, 0.832612f,
		0.846724f, 0.860836f, 0.874948f, 0.88906f, 0.903172f, 0.917285f,
		0.931397f, 0.945509f, 0.959621f, 0.973733f, 0.987845f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using cable_table_t = wrap::data<control::cable_table<parameter::plain<xfader_t<NV>, 0>>, 
                                 data::embedded::table<cable_table_t_data>>;

struct cable_table5_t_data
{
	span<float, 512> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.00212961f, 0.0168643f, 0.0315989f, 0.0463337f,
		0.0610682f, 0.075803f, 0.0905375f, 0.105272f, 0.120007f, 0.134742f,
		0.149476f, 0.164211f, 0.178946f, 0.19368f, 0.208415f, 0.22315f,
		0.237884f, 0.252619f, 0.267354f, 0.282088f, 0.296823f, 0.311558f,
		0.326292f, 0.341027f, 0.355761f, 0.370496f, 0.385231f, 0.399966f,
		0.4147f, 0.429435f, 0.444169f, 0.458904f, 0.473639f, 0.488373f,
		0.503108f, 0.517843f, 0.532577f, 0.547312f, 0.562047f, 0.576781f,
		0.591516f, 0.606251f, 0.620985f, 0.63572f, 0.650455f, 0.665189f,
		0.679924f, 0.694659f, 0.709393f, 0.724128f, 0.738863f, 0.753597f,
		0.768332f, 0.783067f, 0.797801f, 0.812536f, 0.827271f, 0.842005f,
		0.85674f, 0.871475f, 0.886209f, 0.900944f, 0.915679f, 0.930413f,
		0.945148f, 0.959883f, 0.974617f, 0.989352f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using cable_table5_t = wrap::data<control::cable_table<parameter::plain<xfader1_t<NV>, 0>>, 
                                  data::embedded::table<cable_table5_t_data>>;

struct cable_table4_t_data
{
	span<float, 512> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.00434208f, 0.0199976f,
		0.0356531f, 0.0513086f, 0.0669644f, 0.0826199f, 0.0982754f, 0.113931f,
		0.129587f, 0.145242f, 0.160898f, 0.176553f, 0.192209f, 0.207865f,
		0.22352f, 0.239176f, 0.254831f, 0.270487f, 0.286142f, 0.301798f,
		0.317454f, 0.333109f, 0.348765f, 0.36442f, 0.380076f, 0.395731f,
		0.411387f, 0.427042f, 0.442698f, 0.458354f, 0.474009f, 0.489665f,
		0.505321f, 0.520976f, 0.536632f, 0.552287f, 0.567943f, 0.583598f,
		0.599254f, 0.614909f, 0.630565f, 0.646221f, 0.661876f, 0.677532f,
		0.693187f, 0.708843f, 0.724499f, 0.740154f, 0.75581f, 0.771465f,
		0.787121f, 0.802776f, 0.818432f, 0.834088f, 0.849743f, 0.865399f,
		0.881054f, 0.89671f, 0.912365f, 0.928021f, 0.943677f, 0.959332f,
		0.974988f, 0.990643f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using cable_table4_t = wrap::data<control::cable_table<parameter::plain<xfader3_t<NV>, 0>>, 
                                  data::embedded::table<cable_table4_t_data>>;

struct cable_table3_t_data
{
	span<float, 512> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.00592852f, 0.0206631f, 0.0353977f, 0.0501323f,
		0.0648671f, 0.0796018f, 0.0943363f, 0.109071f, 0.123806f, 0.13854f,
		0.153275f, 0.16801f, 0.182744f, 0.197479f, 0.212214f, 0.226948f,
		0.241683f, 0.256418f, 0.271152f, 0.285887f, 0.300622f, 0.315356f,
		0.330091f, 0.344826f, 0.35956f, 0.374295f, 0.38903f, 0.403764f,
		0.418499f, 0.433234f, 0.447968f, 0.462703f, 0.477438f, 0.492172f,
		0.506907f, 0.521641f, 0.536376f, 0.551111f, 0.565845f, 0.58058f,
		0.595315f, 0.61005f, 0.624784f, 0.639519f, 0.654254f, 0.668988f,
		0.683723f, 0.698457f, 0.713192f, 0.727927f, 0.742661f, 0.757396f,
		0.772131f, 0.786865f, 0.8016f, 0.816335f, 0.83107f, 0.845804f,
		0.860539f, 0.875273f, 0.890008f, 0.904743f, 0.919478f, 0.934212f,
		0.948947f, 0.963681f, 0.978416f, 0.993151f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using cable_table3_t = wrap::data<control::cable_table<parameter::plain<xfader4_t<NV>, 0>>, 
                                  data::embedded::table<cable_table3_t_data>>;

struct cable_table2_t_data
{
	span<float, 512> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.00734514f, 0.0210705f,
		0.0347963f, 0.0485217f, 0.0622471f, 0.0759724f, 0.0896978f, 0.103423f,
		0.117149f, 0.130874f, 0.1446f, 0.158325f, 0.172051f, 0.185776f,
		0.199501f, 0.213227f, 0.226952f, 0.240677f, 0.254403f, 0.268129f,
		0.281854f, 0.295579f, 0.309305f, 0.32303f, 0.336756f, 0.350481f,
		0.364207f, 0.377932f, 0.391658f, 0.405383f, 0.419108f, 0.432834f,
		0.446559f, 0.460284f, 0.47401f, 0.487736f, 0.501461f, 0.515186f,
		0.528912f, 0.542637f, 0.556363f, 0.570088f, 0.583814f, 0.597539f,
		0.611265f, 0.62499f, 0.638715f, 0.652441f, 0.666166f, 0.679891f,
		0.693617f, 0.707343f, 0.721068f, 0.734793f, 0.748519f, 0.762244f,
		0.77597f, 0.789695f, 0.803421f, 0.817146f, 0.830872f, 0.844597f,
		0.858322f, 0.872048f, 0.885773f, 0.899499f, 0.913224f, 0.92695f,
		0.940675f, 0.9544f, 0.968126f, 0.981851f, 0.995577f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using cable_table2_t = wrap::data<control::cable_table<parameter::plain<xfader5_t<NV>, 0>>, 
                                  data::embedded::table<cable_table2_t_data>>;

struct cable_table1_t_data
{
	span<float, 512> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.00873119f, 0.0215767f, 0.0344223f, 0.0472678f, 0.0601134f, 0.0729589f,
		0.0858045f, 0.09865f, 0.111496f, 0.124341f, 0.137187f, 0.150033f,
		0.162878f, 0.175724f, 0.188569f, 0.201415f, 0.214261f, 0.227106f,
		0.239952f, 0.252797f, 0.265643f, 0.278489f, 0.291334f, 0.30418f,
		0.317026f, 0.329871f, 0.342717f, 0.355562f, 0.368408f, 0.381253f,
		0.394099f, 0.406944f, 0.41979f, 0.432636f, 0.445482f, 0.458327f,
		0.471173f, 0.484018f, 0.496864f, 0.509709f, 0.522555f, 0.535401f,
		0.548246f, 0.561092f, 0.573937f, 0.586783f, 0.599629f, 0.612474f,
		0.62532f, 0.638166f, 0.651011f, 0.663857f, 0.676702f, 0.689548f,
		0.702393f, 0.715239f, 0.728085f, 0.74093f, 0.753776f, 0.766621f,
		0.779467f, 0.792313f, 0.805158f, 0.818004f, 0.83085f, 0.843695f,
		0.856541f, 0.869386f, 0.882232f, 0.895077f, 0.907923f, 0.920768f,
		0.933614f, 0.94646f, 0.959306f, 0.972151f, 0.984997f, 0.997842f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using cable_table1_t = wrap::data<control::cable_table<parameter::plain<xfader6_t<NV>, 0>>, 
                                  data::embedded::table<cable_table1_t_data>>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 parameter::plain<xfader2_t<NV>, 0>, 
                                 parameter::plain<cable_table_t<NV>, 0>, 
                                 parameter::plain<cable_table5_t<NV>, 0>, 
                                 parameter::plain<cable_table4_t<NV>, 0>, 
                                 parameter::plain<cable_table3_t<NV>, 0>, 
                                 parameter::plain<cable_table2_t<NV>, 0>, 
                                 parameter::plain<cable_table1_t<NV>, 0>>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<2, cable_table_t<NV>>, 
                                  cable_table5_t<NV>, 
                                  cable_table4_t<NV>, 
                                  cable_table3_t<NV>, 
                                  cable_table2_t<NV>, 
                                  cable_table1_t<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, soft_bypass_t<NV>>, 
                                 soft_bypass1_t<NV>, 
                                 soft_bypass2_t<NV>, 
                                 soft_bypass3_t<NV>, 
                                 soft_bypass4_t<NV>, 
                                 soft_bypass5_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, pma_t<NV>>, 
                                 xfader2_t<NV>, 
                                 split8_t<NV>, 
                                 split_t<NV>>;
template <int NV>
using file_player_t = wrap::data<core::file_player<NV>, 
                                 data::external::audiofile<0>>;

namespace Filetrig_t_parameters
{
// Parameter list for Filetrig_impl::Filetrig_t ----------------------------------------------------

template <int NV>
using sync = parameter::chain<ranges::Identity, 
                              parameter::plain<Filetrig_impl::tempo_sync_t<NV>, 2>, 
                              parameter::plain<Filetrig_impl::minmax1_t<NV>, 0>, 
                              parameter::plain<Filetrig_impl::input_toggle_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE(PosRange, 
                        5.55112e-17, 
                        1.);

template <int NV>
using Pos = parameter::from0To1<Filetrig_impl::pma_t<NV>, 
                                2, 
                                PosRange>;

DECLARE_PARAMETER_RANGE(loopRange, 
                        0., 
                        0.02);

template <int NV>
using loop = parameter::from0To1<Filetrig_impl::oscillator_t<NV>, 
                                 5, 
                                 loopRange>;

template <int NV>
using input = parameter::from0To1<core::gain<NV>, 
                                  0, 
                                  Filetrig_impl::xfader_c0Range>;

template <int NV>
using gate = parameter::plain<Filetrig_impl::oscillator_t<NV>, 
                              3>;
template <int NV>
using freq = parameter::plain<Filetrig_impl::input_toggle_t<NV>, 
                              1>;
template <int NV>
using tempo = parameter::plain<Filetrig_impl::tempo_sync_t<NV>, 
                               0>;
template <int NV>
using div = parameter::plain<Filetrig_impl::tempo_sync_t<NV>, 
                             1>;
template <int NV>
using shape = parameter::plain<Filetrig_impl::oscillator_t<NV>, 
                               0>;
template <int NV>
using MS = parameter::plain<Filetrig_impl::tempo_sync_t<NV>, 
                            3>;
template <int NV>
using Filetrig_t_plist = parameter::list<gate<NV>, 
                                         sync<NV>, 
                                         freq<NV>, 
                                         Pos<NV>, 
                                         tempo<NV>, 
                                         div<NV>, 
                                         shape<NV>, 
                                         loop<NV>, 
                                         MS<NV>, 
                                         input<NV>>;
}

template <int NV>
using Filetrig_t_ = container::chain<Filetrig_t_parameters::Filetrig_t_plist<NV>, 
                                     wrap::fix<2, core::gain<NV>>, 
                                     tempo_sync_t<NV>, 
                                     converter_t<NV>, 
                                     input_toggle_t<NV>, 
                                     minmax1_t<NV>, 
                                     oscillator_t<NV>, 
                                     chain_t<NV>, 
                                     file_player_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public Filetrig_impl::Filetrig_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 1;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(Filetrig);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(150)
		{
			0x005B, 0x0000, 0x6700, 0x7461, 0x0065, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x015B, 
            0x0000, 0x7300, 0x6E79, 0x0063, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x025B, 0x0000, 
            0x6600, 0x6572, 0x0071, 0x0000, 0x41A0, 0x4000, 0x469C, 0x3400, 
            0x44BD, 0x6C1A, 0x3E6B, 0x0000, 0x0000, 0x035B, 0x0000, 0x5000, 
            0x736F, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0004, 0x0000, 0x6574, 0x706D, 
            0x006F, 0x0000, 0x0000, 0x0000, 0x4190, 0x0000, 0x4130, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x055B, 0x0000, 0x6400, 0x7669, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x0041, 0x4000, 0x0041, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x0006, 0x0000, 0x6873, 0x7061, 0x0065, 0x0000, 
            0x3F80, 0x0000, 0x4000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x075B, 0x0000, 0x6C00, 0x6F6F, 0x0070, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0xBD38, 0x3DA1, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x085B, 0x0000, 0x4D00, 0x0053, 0x0000, 0x0000, 0x0000, 0x447A, 
            0x0000, 0x42BB, 0x0000, 0x3F80, 0xCCCD, 0x3DCC, 0x095B, 0x0000, 
            0x6900, 0x706E, 0x7475, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& gain48 = this->getT(0);                                                 // core::gain<NV>
		auto& tempo_sync = this->getT(1);                                             // Filetrig_impl::tempo_sync_t<NV>
		auto& converter = this->getT(2);                                              // Filetrig_impl::converter_t<NV>
		auto& input_toggle = this->getT(3);                                           // Filetrig_impl::input_toggle_t<NV>
		auto& minmax1 = this->getT(4);                                                // Filetrig_impl::minmax1_t<NV>
		auto& oscillator = this->getT(5);                                             // Filetrig_impl::oscillator_t<NV>
		auto& chain = this->getT(6);                                                  // Filetrig_impl::chain_t<NV>
		auto& pma = this->getT(6).getT(0);                                            // Filetrig_impl::pma_t<NV>
		auto& xfader2 = this->getT(6).getT(1);                                        // Filetrig_impl::xfader2_t<NV>
		auto& split8 = this->getT(6).getT(2);                                         // Filetrig_impl::split8_t<NV>
		auto& cable_table = this->getT(6).getT(2).getT(0);                            // Filetrig_impl::cable_table_t<NV>
		auto& cable_table5 = this->getT(6).getT(2).getT(1);                           // Filetrig_impl::cable_table5_t<NV>
		auto& cable_table4 = this->getT(6).getT(2).getT(2);                           // Filetrig_impl::cable_table4_t<NV>
		auto& cable_table3 = this->getT(6).getT(2).getT(3);                           // Filetrig_impl::cable_table3_t<NV>
		auto& cable_table2 = this->getT(6).getT(2).getT(4);                           // Filetrig_impl::cable_table2_t<NV>
		auto& cable_table1 = this->getT(6).getT(2).getT(5);                           // Filetrig_impl::cable_table1_t<NV>
		auto& split = this->getT(6).getT(3);                                          // Filetrig_impl::split_t<NV>
		auto& soft_bypass = this->getT(6).getT(3).getT(0);                            // Filetrig_impl::soft_bypass_t<NV>
		auto& chain101 = this->getT(6).getT(3).getT(0).getT(0);                       // Filetrig_impl::chain101_t<NV>
		auto& xfader = this->getT(6).getT(3).getT(0).getT(0).getT(0);                 // Filetrig_impl::xfader_t<NV>
		auto& split1 = this->getT(6).getT(3).getT(0).getT(0).getT(1);                 // Filetrig_impl::split1_t<NV>
		auto& chain1 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(0);         // Filetrig_impl::chain1_t<NV>
		auto& add = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(0).getT(0);    // math::add<NV>
		auto& gain = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(0).getT(1);   // core::gain<NV>
		auto& chain108 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(1);       // Filetrig_impl::chain108_t<NV>
		auto& add106 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(1).getT(0); // math::add<NV>
		auto& gain7 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(1).getT(1);  // core::gain<NV>
		auto& chain107 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(2);       // Filetrig_impl::chain107_t<NV>
		auto& add105 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(2).getT(0); // math::add<NV>
		auto& gain6 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(2).getT(1);  // core::gain<NV>
		auto& chain106 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(3);       // Filetrig_impl::chain106_t<NV>
		auto& add104 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(3).getT(0); // math::add<NV>
		auto& gain5 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(3).getT(1);  // core::gain<NV>
		auto& chain105 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(4);       // Filetrig_impl::chain105_t<NV>
		auto& add103 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(4).getT(0); // math::add<NV>
		auto& gain4 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(4).getT(1);  // core::gain<NV>
		auto& chain104 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(5);       // Filetrig_impl::chain104_t<NV>
		auto& add102 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(5).getT(0); // math::add<NV>
		auto& gain3 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(5).getT(1);  // core::gain<NV>
		auto& chain103 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(6);       // Filetrig_impl::chain103_t<NV>
		auto& add101 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(6).getT(0); // math::add<NV>
		auto& gain2 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(6).getT(1);  // core::gain<NV>
		auto& chain102 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(7);       // Filetrig_impl::chain102_t<NV>
		auto& add100 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(7).getT(0); // math::add<NV>
		auto& gain1 = this->getT(6).getT(3).getT(0).getT(0).getT(1).getT(7).getT(1);  // core::gain<NV>
		auto& soft_bypass1 = this->getT(6).getT(3).getT(1);                           // Filetrig_impl::soft_bypass1_t<NV>
		auto& chain109 = this->getT(6).getT(3).getT(1).getT(0);                       // Filetrig_impl::chain109_t<NV>
		auto& xfader1 = this->getT(6).getT(3).getT(1).getT(0).getT(0);                // Filetrig_impl::xfader1_t<NV>
		auto& split2 = this->getT(6).getT(3).getT(1).getT(0).getT(1);                 // Filetrig_impl::split2_t<NV>
		auto& chain110 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(0);       // Filetrig_impl::chain110_t<NV>
		auto& add108 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(0).getT(0); // math::add<NV>
		auto& gain8 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(0).getT(1);  // core::gain<NV>
		auto& chain111 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(1);       // Filetrig_impl::chain111_t<NV>
		auto& add109 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(1).getT(0); // math::add<NV>
		auto& gain9 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(1).getT(1);  // core::gain<NV>
		auto& chain112 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(2);       // Filetrig_impl::chain112_t<NV>
		auto& add110 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(2).getT(0); // math::add<NV>
		auto& gain10 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(2).getT(1); // core::gain<NV>
		auto& chain113 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(3);       // Filetrig_impl::chain113_t<NV>
		auto& add111 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(3).getT(0); // math::add<NV>
		auto& gain11 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(3).getT(1); // core::gain<NV>
		auto& chain114 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(4);       // Filetrig_impl::chain114_t<NV>
		auto& add112 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(4).getT(0); // math::add<NV>
		auto& gain12 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(4).getT(1); // core::gain<NV>
		auto& chain115 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(5);       // Filetrig_impl::chain115_t<NV>
		auto& add113 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(5).getT(0); // math::add<NV>
		auto& gain13 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(5).getT(1); // core::gain<NV>
		auto& chain116 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(6);       // Filetrig_impl::chain116_t<NV>
		auto& add114 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(6).getT(0); // math::add<NV>
		auto& gain14 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(6).getT(1); // core::gain<NV>
		auto& chain117 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(7);       // Filetrig_impl::chain117_t<NV>
		auto& add115 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(7).getT(0); // math::add<NV>
		auto& gain15 = this->getT(6).getT(3).getT(1).getT(0).getT(1).getT(7).getT(1); // core::gain<NV>
		auto& soft_bypass2 = this->getT(6).getT(3).getT(2);                           // Filetrig_impl::soft_bypass2_t<NV>
		auto& chain118 = this->getT(6).getT(3).getT(2).getT(0);                       // Filetrig_impl::chain118_t<NV>
		auto& xfader3 = this->getT(6).getT(3).getT(2).getT(0).getT(0);                // Filetrig_impl::xfader3_t<NV>
		auto& split3 = this->getT(6).getT(3).getT(2).getT(0).getT(1);                 // Filetrig_impl::split3_t<NV>
		auto& chain119 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(0);       // Filetrig_impl::chain119_t<NV>
		auto& add116 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(0).getT(0); // math::add<NV>
		auto& gain16 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(0).getT(1); // core::gain<NV>
		auto& chain120 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(1);       // Filetrig_impl::chain120_t<NV>
		auto& add117 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(1).getT(0); // math::add<NV>
		auto& gain17 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(1).getT(1); // core::gain<NV>
		auto& chain121 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(2);       // Filetrig_impl::chain121_t<NV>
		auto& add118 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(2).getT(0); // math::add<NV>
		auto& gain18 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(2).getT(1); // core::gain<NV>
		auto& chain122 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(3);       // Filetrig_impl::chain122_t<NV>
		auto& add119 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(3).getT(0); // math::add<NV>
		auto& gain19 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(3).getT(1); // core::gain<NV>
		auto& chain123 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(4);       // Filetrig_impl::chain123_t<NV>
		auto& add120 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(4).getT(0); // math::add<NV>
		auto& gain20 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(4).getT(1); // core::gain<NV>
		auto& chain124 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(5);       // Filetrig_impl::chain124_t<NV>
		auto& add121 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(5).getT(0); // math::add<NV>
		auto& gain21 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(5).getT(1); // core::gain<NV>
		auto& chain125 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(6);       // Filetrig_impl::chain125_t<NV>
		auto& add122 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(6).getT(0); // math::add<NV>
		auto& gain22 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(6).getT(1); // core::gain<NV>
		auto& chain126 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(7);       // Filetrig_impl::chain126_t<NV>
		auto& add123 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(7).getT(0); // math::add<NV>
		auto& gain23 = this->getT(6).getT(3).getT(2).getT(0).getT(1).getT(7).getT(1); // core::gain<NV>
		auto& soft_bypass3 = this->getT(6).getT(3).getT(3);                           // Filetrig_impl::soft_bypass3_t<NV>
		auto& chain127 = this->getT(6).getT(3).getT(3).getT(0);                       // Filetrig_impl::chain127_t<NV>
		auto& xfader4 = this->getT(6).getT(3).getT(3).getT(0).getT(0);                // Filetrig_impl::xfader4_t<NV>
		auto& split4 = this->getT(6).getT(3).getT(3).getT(0).getT(1);                 // Filetrig_impl::split4_t<NV>
		auto& chain128 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(0);       // Filetrig_impl::chain128_t<NV>
		auto& add124 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(0).getT(0); // math::add<NV>
		auto& gain24 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(0).getT(1); // core::gain<NV>
		auto& chain129 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(1);       // Filetrig_impl::chain129_t<NV>
		auto& add125 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(1).getT(0); // math::add<NV>
		auto& gain25 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(1).getT(1); // core::gain<NV>
		auto& chain130 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(2);       // Filetrig_impl::chain130_t<NV>
		auto& add126 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(2).getT(0); // math::add<NV>
		auto& gain26 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(2).getT(1); // core::gain<NV>
		auto& chain131 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(3);       // Filetrig_impl::chain131_t<NV>
		auto& add127 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(3).getT(0); // math::add<NV>
		auto& gain27 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(3).getT(1); // core::gain<NV>
		auto& chain132 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(4);       // Filetrig_impl::chain132_t<NV>
		auto& add128 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(4).getT(0); // math::add<NV>
		auto& gain28 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(4).getT(1); // core::gain<NV>
		auto& chain133 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(5);       // Filetrig_impl::chain133_t<NV>
		auto& add129 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(5).getT(0); // math::add<NV>
		auto& gain29 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(5).getT(1); // core::gain<NV>
		auto& chain134 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(6);       // Filetrig_impl::chain134_t<NV>
		auto& add130 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(6).getT(0); // math::add<NV>
		auto& gain30 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(6).getT(1); // core::gain<NV>
		auto& chain135 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(7);       // Filetrig_impl::chain135_t<NV>
		auto& add131 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(7).getT(0); // math::add<NV>
		auto& gain31 = this->getT(6).getT(3).getT(3).getT(0).getT(1).getT(7).getT(1); // core::gain<NV>
		auto& soft_bypass4 = this->getT(6).getT(3).getT(4);                           // Filetrig_impl::soft_bypass4_t<NV>
		auto& chain136 = this->getT(6).getT(3).getT(4).getT(0);                       // Filetrig_impl::chain136_t<NV>
		auto& xfader5 = this->getT(6).getT(3).getT(4).getT(0).getT(0);                // Filetrig_impl::xfader5_t<NV>
		auto& split5 = this->getT(6).getT(3).getT(4).getT(0).getT(1);                 // Filetrig_impl::split5_t<NV>
		auto& chain137 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(0);       // Filetrig_impl::chain137_t<NV>
		auto& add132 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(0).getT(0); // math::add<NV>
		auto& gain32 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(0).getT(1); // core::gain<NV>
		auto& chain138 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(1);       // Filetrig_impl::chain138_t<NV>
		auto& add133 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(1).getT(0); // math::add<NV>
		auto& gain33 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(1).getT(1); // core::gain<NV>
		auto& chain139 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(2);       // Filetrig_impl::chain139_t<NV>
		auto& add134 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(2).getT(0); // math::add<NV>
		auto& gain34 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(2).getT(1); // core::gain<NV>
		auto& chain140 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(3);       // Filetrig_impl::chain140_t<NV>
		auto& add135 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(3).getT(0); // math::add<NV>
		auto& gain35 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(3).getT(1); // core::gain<NV>
		auto& chain141 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(4);       // Filetrig_impl::chain141_t<NV>
		auto& add136 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(4).getT(0); // math::add<NV>
		auto& gain36 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(4).getT(1); // core::gain<NV>
		auto& chain142 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(5);       // Filetrig_impl::chain142_t<NV>
		auto& add137 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(5).getT(0); // math::add<NV>
		auto& gain37 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(5).getT(1); // core::gain<NV>
		auto& chain143 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(6);       // Filetrig_impl::chain143_t<NV>
		auto& add138 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(6).getT(0); // math::add<NV>
		auto& gain38 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(6).getT(1); // core::gain<NV>
		auto& chain144 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(7);       // Filetrig_impl::chain144_t<NV>
		auto& add139 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(7).getT(0); // math::add<NV>
		auto& gain39 = this->getT(6).getT(3).getT(4).getT(0).getT(1).getT(7).getT(1); // core::gain<NV>
		auto& soft_bypass5 = this->getT(6).getT(3).getT(5);                           // Filetrig_impl::soft_bypass5_t<NV>
		auto& chain145 = this->getT(6).getT(3).getT(5).getT(0);                       // Filetrig_impl::chain145_t<NV>
		auto& xfader6 = this->getT(6).getT(3).getT(5).getT(0).getT(0);                // Filetrig_impl::xfader6_t<NV>
		auto& split6 = this->getT(6).getT(3).getT(5).getT(0).getT(1);                 // Filetrig_impl::split6_t<NV>
		auto& chain146 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(0);       // Filetrig_impl::chain146_t<NV>
		auto& add140 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(0).getT(0); // math::add<NV>
		auto& gain40 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(0).getT(1); // core::gain<NV>
		auto& chain147 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(1);       // Filetrig_impl::chain147_t<NV>
		auto& add141 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(1).getT(0); // math::add<NV>
		auto& gain41 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(1).getT(1); // core::gain<NV>
		auto& chain148 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(2);       // Filetrig_impl::chain148_t<NV>
		auto& add142 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(2).getT(0); // math::add<NV>
		auto& gain42 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(2).getT(1); // core::gain<NV>
		auto& chain149 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(3);       // Filetrig_impl::chain149_t<NV>
		auto& add143 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(3).getT(0); // math::add<NV>
		auto& gain43 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(3).getT(1); // core::gain<NV>
		auto& chain150 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(4);       // Filetrig_impl::chain150_t<NV>
		auto& add144 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(4).getT(0); // math::add<NV>
		auto& gain44 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(4).getT(1); // core::gain<NV>
		auto& chain151 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(5);       // Filetrig_impl::chain151_t<NV>
		auto& add145 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(5).getT(0); // math::add<NV>
		auto& gain45 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(5).getT(1); // core::gain<NV>
		auto& chain152 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(6);       // Filetrig_impl::chain152_t<NV>
		auto& add146 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(6).getT(0); // math::add<NV>
		auto& gain46 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(6).getT(1); // core::gain<NV>
		auto& chain153 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(7);       // Filetrig_impl::chain153_t<NV>
		auto& add147 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(7).getT(0); // math::add<NV>
		auto& gain47 = this->getT(6).getT(3).getT(5).getT(0).getT(1).getT(7).getT(1); // core::gain<NV>
		auto& file_player = this->getT(7);                                            // Filetrig_impl::file_player_t<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, oscillator); // gate -> oscillator::Gate
		
		auto& sync_p = this->getParameterT(1);
		sync_p.connectT(0, tempo_sync);   // sync -> tempo_sync::Enabled
		sync_p.connectT(1, minmax1);      // sync -> minmax1::Value
		sync_p.connectT(2, input_toggle); // sync -> input_toggle::Input
		
		this->getParameterT(2).connectT(0, input_toggle); // freq -> input_toggle::Value1
		
		this->getParameterT(3).connectT(0, pma); // Pos -> pma::Add
		
		this->getParameterT(4).connectT(0, tempo_sync); // tempo -> tempo_sync::Tempo
		
		this->getParameterT(5).connectT(0, tempo_sync); // div -> tempo_sync::Multiplier
		
		this->getParameterT(6).connectT(0, oscillator); // shape -> oscillator::Mode
		
		this->getParameterT(7).connectT(0, oscillator); // loop -> oscillator::Gain
		
		this->getParameterT(8).connectT(0, tempo_sync); // MS -> tempo_sync::UnsyncedTime
		
		this->getParameterT(9).connectT(0, gain48); // input -> gain48::Gain
		
		// Modulation Connections ------------------------------------------------------------------
		
		input_toggle.getWrappedObject().getParameter().connectT(0, oscillator); // input_toggle -> oscillator::Frequency
		converter.getWrappedObject().getParameter().connectT(0, input_toggle);  // converter -> input_toggle::Value2
		tempo_sync.getParameter().connectT(0, converter);                       // tempo_sync -> converter::Value
		minmax1.getWrappedObject().getParameter().connectT(0, oscillator);      // minmax1 -> oscillator::FreqRatio
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);  // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain7); // xfader -> gain7::Gain
		xfader_p.getParameterT(2).connectT(0, gain6); // xfader -> gain6::Gain
		xfader_p.getParameterT(3).connectT(0, gain5); // xfader -> gain5::Gain
		xfader_p.getParameterT(4).connectT(0, gain4); // xfader -> gain4::Gain
		xfader_p.getParameterT(5).connectT(0, gain3); // xfader -> gain3::Gain
		xfader_p.getParameterT(6).connectT(0, gain2); // xfader -> gain2::Gain
		xfader_p.getParameterT(7).connectT(0, gain1); // xfader -> gain1::Gain
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain8);  // xfader1 -> gain8::Gain
		xfader1_p.getParameterT(1).connectT(0, gain9);  // xfader1 -> gain9::Gain
		xfader1_p.getParameterT(2).connectT(0, gain10); // xfader1 -> gain10::Gain
		xfader1_p.getParameterT(3).connectT(0, gain11); // xfader1 -> gain11::Gain
		xfader1_p.getParameterT(4).connectT(0, gain12); // xfader1 -> gain12::Gain
		xfader1_p.getParameterT(5).connectT(0, gain13); // xfader1 -> gain13::Gain
		xfader1_p.getParameterT(6).connectT(0, gain14); // xfader1 -> gain14::Gain
		xfader1_p.getParameterT(7).connectT(0, gain15); // xfader1 -> gain15::Gain
		auto& xfader3_p = xfader3.getWrappedObject().getParameter();
		xfader3_p.getParameterT(0).connectT(0, gain16); // xfader3 -> gain16::Gain
		xfader3_p.getParameterT(1).connectT(0, gain17); // xfader3 -> gain17::Gain
		xfader3_p.getParameterT(2).connectT(0, gain18); // xfader3 -> gain18::Gain
		xfader3_p.getParameterT(3).connectT(0, gain19); // xfader3 -> gain19::Gain
		xfader3_p.getParameterT(4).connectT(0, gain20); // xfader3 -> gain20::Gain
		xfader3_p.getParameterT(5).connectT(0, gain21); // xfader3 -> gain21::Gain
		xfader3_p.getParameterT(6).connectT(0, gain22); // xfader3 -> gain22::Gain
		xfader3_p.getParameterT(7).connectT(0, gain23); // xfader3 -> gain23::Gain
		auto& xfader4_p = xfader4.getWrappedObject().getParameter();
		xfader4_p.getParameterT(0).connectT(0, gain24); // xfader4 -> gain24::Gain
		xfader4_p.getParameterT(1).connectT(0, gain25); // xfader4 -> gain25::Gain
		xfader4_p.getParameterT(2).connectT(0, gain26); // xfader4 -> gain26::Gain
		xfader4_p.getParameterT(3).connectT(0, gain27); // xfader4 -> gain27::Gain
		xfader4_p.getParameterT(4).connectT(0, gain28); // xfader4 -> gain28::Gain
		xfader4_p.getParameterT(5).connectT(0, gain29); // xfader4 -> gain29::Gain
		xfader4_p.getParameterT(6).connectT(0, gain30); // xfader4 -> gain30::Gain
		xfader4_p.getParameterT(7).connectT(0, gain31); // xfader4 -> gain31::Gain
		auto& xfader5_p = xfader5.getWrappedObject().getParameter();
		xfader5_p.getParameterT(0).connectT(0, gain32); // xfader5 -> gain32::Gain
		xfader5_p.getParameterT(1).connectT(0, gain33); // xfader5 -> gain33::Gain
		xfader5_p.getParameterT(2).connectT(0, gain34); // xfader5 -> gain34::Gain
		xfader5_p.getParameterT(3).connectT(0, gain35); // xfader5 -> gain35::Gain
		xfader5_p.getParameterT(4).connectT(0, gain36); // xfader5 -> gain36::Gain
		xfader5_p.getParameterT(5).connectT(0, gain37); // xfader5 -> gain37::Gain
		xfader5_p.getParameterT(6).connectT(0, gain38); // xfader5 -> gain38::Gain
		xfader5_p.getParameterT(7).connectT(0, gain39); // xfader5 -> gain39::Gain
		auto& xfader6_p = xfader6.getWrappedObject().getParameter();
		xfader6_p.getParameterT(0).connectT(0, gain40); // xfader6 -> gain40::Gain
		xfader6_p.getParameterT(1).connectT(0, gain41); // xfader6 -> gain41::Gain
		xfader6_p.getParameterT(2).connectT(0, gain42); // xfader6 -> gain42::Gain
		xfader6_p.getParameterT(3).connectT(0, gain43); // xfader6 -> gain43::Gain
		xfader6_p.getParameterT(4).connectT(0, gain44); // xfader6 -> gain44::Gain
		xfader6_p.getParameterT(5).connectT(0, gain45); // xfader6 -> gain45::Gain
		xfader6_p.getParameterT(6).connectT(0, gain46); // xfader6 -> gain46::Gain
		xfader6_p.getParameterT(7).connectT(0, gain47); // xfader6 -> gain47::Gain
		auto& xfader2_p = xfader2.getWrappedObject().getParameter();
		xfader2_p.getParameterT(0).connectT(0, soft_bypass);                 // xfader2 -> soft_bypass::Bypassed
		xfader2_p.getParameterT(1).connectT(0, soft_bypass1);                // xfader2 -> soft_bypass1::Bypassed
		xfader2_p.getParameterT(2).connectT(0, soft_bypass2);                // xfader2 -> soft_bypass2::Bypassed
		xfader2_p.getParameterT(3).connectT(0, soft_bypass3);                // xfader2 -> soft_bypass3::Bypassed
		xfader2_p.getParameterT(4).connectT(0, soft_bypass4);                // xfader2 -> soft_bypass4::Bypassed
		xfader2_p.getParameterT(5).connectT(0, soft_bypass5);                // xfader2 -> soft_bypass5::Bypassed
		cable_table.getWrappedObject().getParameter().connectT(0, xfader);   // cable_table -> xfader::Value
		cable_table5.getWrappedObject().getParameter().connectT(0, xfader1); // cable_table5 -> xfader1::Value
		cable_table4.getWrappedObject().getParameter().connectT(0, xfader3); // cable_table4 -> xfader3::Value
		cable_table3.getWrappedObject().getParameter().connectT(0, xfader4); // cable_table3 -> xfader4::Value
		cable_table2.getWrappedObject().getParameter().connectT(0, xfader5); // cable_table2 -> xfader5::Value
		cable_table1.getWrappedObject().getParameter().connectT(0, xfader6); // cable_table1 -> xfader6::Value
		pma.getWrappedObject().getParameter().connectT(0, xfader2);          // pma -> xfader2::Value
		pma.getWrappedObject().getParameter().connectT(1, cable_table);      // pma -> cable_table::Value
		pma.getWrappedObject().getParameter().connectT(2, cable_table5);     // pma -> cable_table5::Value
		pma.getWrappedObject().getParameter().connectT(3, cable_table4);     // pma -> cable_table4::Value
		pma.getWrappedObject().getParameter().connectT(4, cable_table3);     // pma -> cable_table3::Value
		pma.getWrappedObject().getParameter().connectT(5, cable_table2);     // pma -> cable_table2::Value
		pma.getWrappedObject().getParameter().connectT(6, cable_table1);     // pma -> cable_table1::Value
		
		// Default Values --------------------------------------------------------------------------
		
		;                             // gain48::Gain is automated
		gain48.setParameterT(1, 20.); // core::gain::Smoothing
		gain48.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		; // converter::Value is automated
		
		; // input_toggle::Input is automated
		; // input_toggle::Value1 is automated
		; // input_toggle::Value2 is automated
		
		;                             // minmax1::Value is automated
		minmax1.setParameterT(1, 0.); // control::minmax::Minimum
		minmax1.setParameterT(2, 1.); // control::minmax::Maximum
		minmax1.setParameterT(3, 1.); // control::minmax::Skew
		minmax1.setParameterT(4, 0.); // control::minmax::Step
		minmax1.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                                // oscillator::Mode is automated
		;                                // oscillator::Frequency is automated
		;                                // oscillator::FreqRatio is automated
		;                                // oscillator::Gate is automated
		oscillator.setParameterT(4, 0.); // core::oscillator::Phase
		;                                // oscillator::Gain is automated
		
		pma.setParameterT(0, 0.); // control::pma::Value
		pma.setParameterT(1, 0.); // control::pma::Multiply
		;                         // pma::Add is automated
		
		; // xfader2::Value is automated
		
		; // cable_table::Value is automated
		
		; // cable_table5::Value is automated
		
		; // cable_table4::Value is automated
		
		; // cable_table3::Value is automated
		
		; // cable_table2::Value is automated
		
		; // cable_table1::Value is automated
		
		; // xfader::Value is automated
		
		add.setParameterT(0, 0.); // math::add::Value
		
		;                          // gain::Gain is automated
		gain.setParameterT(1, 0.); // core::gain::Smoothing
		gain.setParameterT(2, 0.); // core::gain::ResetValue
		
		add106.setParameterT(0, 0.0167402); // math::add::Value
		
		;                           // gain7::Gain is automated
		gain7.setParameterT(1, 0.); // core::gain::Smoothing
		gain7.setParameterT(2, 0.); // core::gain::ResetValue
		
		add105.setParameterT(0, 0.0431013); // math::add::Value
		
		;                           // gain6::Gain is automated
		gain6.setParameterT(1, 0.); // core::gain::Smoothing
		gain6.setParameterT(2, 0.); // core::gain::ResetValue
		
		add104.setParameterT(0, 0.0623926); // math::add::Value
		
		;                           // gain5::Gain is automated
		gain5.setParameterT(1, 0.); // core::gain::Smoothing
		gain5.setParameterT(2, 0.); // core::gain::ResetValue
		
		add103.setParameterT(0, 0.0789702); // math::add::Value
		
		;                           // gain4::Gain is automated
		gain4.setParameterT(1, 0.); // core::gain::Smoothing
		gain4.setParameterT(2, 0.); // core::gain::ResetValue
		
		add102.setParameterT(0, 0.0953291); // math::add::Value
		
		;                           // gain3::Gain is automated
		gain3.setParameterT(1, 0.); // core::gain::Smoothing
		gain3.setParameterT(2, 0.); // core::gain::ResetValue
		
		add101.setParameterT(0, 0.122563); // math::add::Value
		
		;                           // gain2::Gain is automated
		gain2.setParameterT(1, 0.); // core::gain::Smoothing
		gain2.setParameterT(2, 0.); // core::gain::ResetValue
		
		add100.setParameterT(0, 0.144299); // math::add::Value
		
		;                           // gain1::Gain is automated
		gain1.setParameterT(1, 0.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.); // core::gain::ResetValue
		
		; // xfader1::Value is automated
		
		add108.setParameterT(0, 0.149446); // math::add::Value
		
		;                           // gain8::Gain is automated
		gain8.setParameterT(1, 0.); // core::gain::Smoothing
		gain8.setParameterT(2, 0.); // core::gain::ResetValue
		
		add109.setParameterT(0, 0.159247); // math::add::Value
		
		;                           // gain9::Gain is automated
		gain9.setParameterT(1, 0.); // core::gain::Smoothing
		gain9.setParameterT(2, 0.); // core::gain::ResetValue
		
		add110.setParameterT(0, 0.197779); // math::add::Value
		
		;                            // gain10::Gain is automated
		gain10.setParameterT(1, 0.); // core::gain::Smoothing
		gain10.setParameterT(2, 0.); // core::gain::ResetValue
		
		add111.setParameterT(0, 0.222837); // math::add::Value
		
		;                            // gain11::Gain is automated
		gain11.setParameterT(1, 0.); // core::gain::Smoothing
		gain11.setParameterT(2, 0.); // core::gain::ResetValue
		
		add112.setParameterT(0, 0.237415); // math::add::Value
		
		;                            // gain12::Gain is automated
		gain12.setParameterT(1, 0.); // core::gain::Smoothing
		gain12.setParameterT(2, 0.); // core::gain::ResetValue
		
		add113.setParameterT(0, 0.262987); // math::add::Value
		
		;                            // gain13::Gain is automated
		gain13.setParameterT(1, 0.); // core::gain::Smoothing
		gain13.setParameterT(2, 0.); // core::gain::ResetValue
		
		add114.setParameterT(0, 0.275864); // math::add::Value
		
		;                            // gain14::Gain is automated
		gain14.setParameterT(1, 0.); // core::gain::Smoothing
		gain14.setParameterT(2, 0.); // core::gain::ResetValue
		
		add115.setParameterT(0, 0.295312); // math::add::Value
		
		;                            // gain15::Gain is automated
		gain15.setParameterT(1, 0.); // core::gain::Smoothing
		gain15.setParameterT(2, 0.); // core::gain::ResetValue
		
		; // xfader3::Value is automated
		
		add116.setParameterT(0, 0.318877); // math::add::Value
		
		;                            // gain16::Gain is automated
		gain16.setParameterT(1, 0.); // core::gain::Smoothing
		gain16.setParameterT(2, 0.); // core::gain::ResetValue
		
		add117.setParameterT(0, 0.331393); // math::add::Value
		
		;                            // gain17::Gain is automated
		gain17.setParameterT(1, 0.); // core::gain::Smoothing
		gain17.setParameterT(2, 0.); // core::gain::ResetValue
		
		add118.setParameterT(0, 0.36126); // math::add::Value
		
		;                            // gain18::Gain is automated
		gain18.setParameterT(1, 0.); // core::gain::Smoothing
		gain18.setParameterT(2, 0.); // core::gain::ResetValue
		
		add119.setParameterT(0, 0.382902); // math::add::Value
		
		;                            // gain19::Gain is automated
		gain19.setParameterT(1, 0.); // core::gain::Smoothing
		gain19.setParameterT(2, 0.); // core::gain::ResetValue
		
		add120.setParameterT(0, 0.392459); // math::add::Value
		
		;                            // gain20::Gain is automated
		gain20.setParameterT(1, 0.); // core::gain::Smoothing
		gain20.setParameterT(2, 0.); // core::gain::ResetValue
		
		add121.setParameterT(0, 0.419798); // math::add::Value
		
		;                            // gain21::Gain is automated
		gain21.setParameterT(1, 0.); // core::gain::Smoothing
		gain21.setParameterT(2, 0.); // core::gain::ResetValue
		
		add122.setParameterT(0, 0.444758); // math::add::Value
		
		;                            // gain22::Gain is automated
		gain22.setParameterT(1, 0.); // core::gain::Smoothing
		gain22.setParameterT(2, 0.); // core::gain::ResetValue
		
		add123.setParameterT(0, 0.455223); // math::add::Value
		
		;                            // gain23::Gain is automated
		gain23.setParameterT(1, 0.); // core::gain::Smoothing
		gain23.setParameterT(2, 0.); // core::gain::ResetValue
		
		; // xfader4::Value is automated
		
		add124.setParameterT(0, 0.480969); // math::add::Value
		
		;                            // gain24::Gain is automated
		gain24.setParameterT(1, 0.); // core::gain::Smoothing
		gain24.setParameterT(2, 0.); // core::gain::ResetValue
		
		add125.setParameterT(0, 0.500359); // math::add::Value
		
		;                            // gain25::Gain is automated
		gain25.setParameterT(1, 0.); // core::gain::Smoothing
		gain25.setParameterT(2, 0.); // core::gain::ResetValue
		
		add126.setParameterT(0, 0.520477); // math::add::Value
		
		;                            // gain26::Gain is automated
		gain26.setParameterT(1, 0.); // core::gain::Smoothing
		gain26.setParameterT(2, 0.); // core::gain::ResetValue
		
		add127.setParameterT(0, 0.535245); // math::add::Value
		
		;                            // gain27::Gain is automated
		gain27.setParameterT(1, 0.); // core::gain::Smoothing
		gain27.setParameterT(2, 0.); // core::gain::ResetValue
		
		add128.setParameterT(0, 0.558241); // math::add::Value
		
		;                            // gain28::Gain is automated
		gain28.setParameterT(1, 0.); // core::gain::Smoothing
		gain28.setParameterT(2, 0.); // core::gain::ResetValue
		
		add129.setParameterT(0, 0.575557); // math::add::Value
		
		;                            // gain29::Gain is automated
		gain29.setParameterT(1, 0.); // core::gain::Smoothing
		gain29.setParameterT(2, 0.); // core::gain::ResetValue
		
		add130.setParameterT(0, 0.607482); // math::add::Value
		
		;                            // gain30::Gain is automated
		gain30.setParameterT(1, 0.); // core::gain::Smoothing
		gain30.setParameterT(2, 0.); // core::gain::ResetValue
		
		add131.setParameterT(0, 0.618705); // math::add::Value
		
		;                            // gain31::Gain is automated
		gain31.setParameterT(1, 0.); // core::gain::Smoothing
		gain31.setParameterT(2, 0.); // core::gain::ResetValue
		
		; // xfader5::Value is automated
		
		add132.setParameterT(0, 0.64); // math::add::Value
		
		;                            // gain32::Gain is automated
		gain32.setParameterT(1, 0.); // core::gain::Smoothing
		gain32.setParameterT(2, 0.); // core::gain::ResetValue
		
		add133.setParameterT(0, 0.66); // math::add::Value
		
		;                            // gain33::Gain is automated
		gain33.setParameterT(1, 0.); // core::gain::Smoothing
		gain33.setParameterT(2, 0.); // core::gain::ResetValue
		
		add134.setParameterT(0, 0.68); // math::add::Value
		
		;                            // gain34::Gain is automated
		gain34.setParameterT(1, 0.); // core::gain::Smoothing
		gain34.setParameterT(2, 0.); // core::gain::ResetValue
		
		add135.setParameterT(0, 0.7); // math::add::Value
		
		;                            // gain35::Gain is automated
		gain35.setParameterT(1, 0.); // core::gain::Smoothing
		gain35.setParameterT(2, 0.); // core::gain::ResetValue
		
		add136.setParameterT(0, 0.72); // math::add::Value
		
		;                            // gain36::Gain is automated
		gain36.setParameterT(1, 0.); // core::gain::Smoothing
		gain36.setParameterT(2, 0.); // core::gain::ResetValue
		
		add137.setParameterT(0, 0.74); // math::add::Value
		
		;                            // gain37::Gain is automated
		gain37.setParameterT(1, 0.); // core::gain::Smoothing
		gain37.setParameterT(2, 0.); // core::gain::ResetValue
		
		add138.setParameterT(0, 0.76); // math::add::Value
		
		;                            // gain38::Gain is automated
		gain38.setParameterT(1, 0.); // core::gain::Smoothing
		gain38.setParameterT(2, 0.); // core::gain::ResetValue
		
		add139.setParameterT(0, 0.78); // math::add::Value
		
		;                            // gain39::Gain is automated
		gain39.setParameterT(1, 0.); // core::gain::Smoothing
		gain39.setParameterT(2, 0.); // core::gain::ResetValue
		
		; // xfader6::Value is automated
		
		add140.setParameterT(0, 0.8); // math::add::Value
		
		;                            // gain40::Gain is automated
		gain40.setParameterT(1, 0.); // core::gain::Smoothing
		gain40.setParameterT(2, 0.); // core::gain::ResetValue
		
		add141.setParameterT(0, 0.819108); // math::add::Value
		
		;                            // gain41::Gain is automated
		gain41.setParameterT(1, 0.); // core::gain::Smoothing
		gain41.setParameterT(2, 0.); // core::gain::ResetValue
		
		add142.setParameterT(0, 0.836264); // math::add::Value
		
		;                            // gain42::Gain is automated
		gain42.setParameterT(1, 0.); // core::gain::Smoothing
		gain42.setParameterT(2, 0.); // core::gain::ResetValue
		
		add143.setParameterT(0, 0.860179); // math::add::Value
		
		;                            // gain43::Gain is automated
		gain43.setParameterT(1, 0.); // core::gain::Smoothing
		gain43.setParameterT(2, 0.); // core::gain::ResetValue
		
		add144.setParameterT(0, 0.883416); // math::add::Value
		
		;                            // gain44::Gain is automated
		gain44.setParameterT(1, 0.); // core::gain::Smoothing
		gain44.setParameterT(2, 0.); // core::gain::ResetValue
		
		add145.setParameterT(0, 0.900909); // math::add::Value
		
		;                            // gain45::Gain is automated
		gain45.setParameterT(1, 0.); // core::gain::Smoothing
		gain45.setParameterT(2, 0.); // core::gain::ResetValue
		
		add146.setParameterT(0, 0.923752); // math::add::Value
		
		;                            // gain46::Gain is automated
		gain46.setParameterT(1, 0.); // core::gain::Smoothing
		gain46.setParameterT(2, 0.); // core::gain::ResetValue
		
		add147.setParameterT(0, 0.941151); // math::add::Value
		
		;                            // gain47::Gain is automated
		gain47.setParameterT(1, 0.); // core::gain::Smoothing
		gain47.setParameterT(2, 0.); // core::gain::ResetValue
		
		file_player.setParameterT(0, 1.);   // core::file_player::PlaybackMode
		file_player.setParameterT(1, 1.);   // core::file_player::Gate
		file_player.setParameterT(2, 440.); // core::file_player::RootFrequency
		file_player.setParameterT(3, 1.);   // core::file_player::FreqRatio
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 1513.62);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 11.);
		this->setParameterT(5, 12.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 0.0789742);
		this->setParameterT(8, 93.5);
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
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(5).setExternalData(b, index);                 // Filetrig_impl::oscillator_t<NV>
		this->getT(6).getT(2).getT(0).setExternalData(b, index); // Filetrig_impl::cable_table_t<NV>
		this->getT(6).getT(2).getT(1).setExternalData(b, index); // Filetrig_impl::cable_table5_t<NV>
		this->getT(6).getT(2).getT(2).setExternalData(b, index); // Filetrig_impl::cable_table4_t<NV>
		this->getT(6).getT(2).getT(3).setExternalData(b, index); // Filetrig_impl::cable_table3_t<NV>
		this->getT(6).getT(2).getT(4).setExternalData(b, index); // Filetrig_impl::cable_table2_t<NV>
		this->getT(6).getT(2).getT(5).setExternalData(b, index); // Filetrig_impl::cable_table1_t<NV>
		this->getT(7).setExternalData(b, index);                 // Filetrig_impl::file_player_t<NV>
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
using Filetrig = wrap::node<Filetrig_impl::instance<NV>>;
}


