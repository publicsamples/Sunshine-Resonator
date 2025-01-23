#pragma once

#include "FilterForRes.h"
#include "res1.h"
#include "res1.h"
#include "res1.h"
#include "FilterForRes.h"
// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace ResStage_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, math::add<NV>>, 
                                    math::add<NV>, 
                                    math::add<NV>>;

DECLARE_PARAMETER_RANGE(peak_modRange, 
                        5.55112e-17, 
                        1.);

template <int NV>
using peak_mod = parameter::from0To1<control::pma<NV, parameter::empty>, 
                                     2, 
                                     peak_modRange>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch3_t<NV>>, 
                                   peak_t<NV>, 
                                   control::pma<NV, parameter::empty>>;
template <int NV> using branch5_t = branch3_t<NV>;

DECLARE_PARAMETER_RANGE_SKEW(pma3_mod_1Range, 
                             0., 
                             1., 
                             0.30103);

template <int NV>
using pma3_mod_1 = parameter::from0To1<filters::allpass<NV>, 
                                       3, 
                                       pma3_mod_1Range>;

DECLARE_PARAMETER_RANGE_SKEW(pma3_mod_3Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma3_mod_3 = parameter::from0To1<project::res1<NV>, 
                                       4, 
                                       pma3_mod_3Range>;

template <int NV> using pma3_mod_4 = pma3_mod_3<NV>;

template <int NV>
using pma3_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<control::smoothed_parameter<NV, smoothers::low_pass<NV>>, 0>, 
                                  pma3_mod_1<NV>, 
                                  parameter::plain<project::res1<NV>, 7>, 
                                  pma3_mod_3<NV>, 
                                  pma3_mod_4<NV>, 
                                  parameter::plain<project::res1<NV>, 7>>;

template <int NV>
using pma3_t = control::pma<NV, pma3_mod<NV>>;
template <int NV>
using peak2_mod = parameter::from0To1<pma3_t<NV>, 
                                      2, 
                                      peak_modRange>;

template <int NV>
using peak2_t = wrap::mod<peak2_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch5_t<NV>>, 
                                   peak2_t<NV>, 
                                   pma3_t<NV>, 
                                   control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
template <int NV> using branch7_t = branch3_t<NV>;

DECLARE_PARAMETER_RANGE_SKEW(pma5_modRange, 
                             0., 
                             1., 
                             0.239104);

template <int NV>
using pma5_mod = parameter::from0To1<project::FilterForRes<NV>, 
                                     0, 
                                     pma5_modRange>;

template <int NV>
using pma5_t = control::pma<NV, pma5_mod<NV>>;
template <int NV>
using peak5_mod = parameter::from0To1<pma5_t<NV>, 
                                      2, 
                                      peak_modRange>;

template <int NV>
using peak5_t = wrap::mod<peak5_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch7_t<NV>>, 
                                   peak5_t<NV>, 
                                   pma5_t<NV>>;
template <int NV> using branch8_t = branch3_t<NV>;

DECLARE_PARAMETER_RANGE_STEP(pma6_modRange, 
                             1., 
                             11., 
                             1.);

template <int NV>
using pma6_mod = parameter::from0To1<project::FilterForRes<NV>, 
                                     2, 
                                     pma6_modRange>;

template <int NV>
using pma6_t = control::pma<NV, pma6_mod<NV>>;
template <int NV>
using peak6_mod = parameter::from0To1<pma6_t<NV>, 
                                      2, 
                                      peak_modRange>;

template <int NV>
using peak6_t = wrap::mod<peak6_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch8_t<NV>>, 
                                   peak6_t<NV>, 
                                   pma6_t<NV>>;
template <int NV> using branch9_t = branch3_t<NV>;

template <int NV>
using oscillator_t = wrap::no_data<core::oscillator<NV>>;
DECLARE_PARAMETER_RANGE_SKEW(comp_mod_2Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using comp_mod_2 = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       comp_mod_2Range>;

template <int NV>
using comp_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<math::add<NV>, 0>, 
                                  parameter::plain<oscillator_t<NV>, 3>, 
                                  comp_mod_2<NV>>;

template <int NV>
using comp_t = wrap::mod<comp_mod<NV>, 
                         wrap::no_data<dynamics::comp>>;
DECLARE_PARAMETER_RANGE_SKEW(pma7_modRange, 
                             1, 
                             32., 
                             0.296803);

template <int NV>
using pma7_mod = parameter::from0To1<comp_t<NV>, 
                                     3, 
                                     pma7_modRange>;

template <int NV>
using pma7_t = control::pma<NV, pma7_mod<NV>>;
template <int NV>
using peak7_mod = parameter::from0To1<pma7_t<NV>, 
                                      2, 
                                      peak_modRange>;

template <int NV>
using peak7_t = wrap::mod<peak7_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch9_t<NV>>, 
                                   peak7_t<NV>, 
                                   pma7_t<NV>>;
template <int NV> using branch10_t = branch3_t<NV>;

DECLARE_PARAMETER_RANGE_STEP(pma8_modRange, 
                             1., 
                             32., 
                             1.);

template <int NV>
using pma8_mod = parameter::from0To1<control::tempo_sync<NV>, 
                                     1, 
                                     pma8_modRange>;

template <int NV>
using pma8_t = control::pma<NV, pma8_mod<NV>>;
template <int NV>
using peak8_mod = parameter::from0To1<pma8_t<NV>, 
                                      2, 
                                      peak_modRange>;

template <int NV>
using peak8_t = wrap::mod<peak8_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch10_t<NV>>, 
                                   peak8_t<NV>, 
                                   pma8_t<NV>>;

template <int NV>
using split16_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain29_t<NV>>, 
                                   chain30_t<NV>, 
                                   chain32_t<NV>, 
                                   chain33_t<NV>, 
                                   chain34_t<NV>, 
                                   chain35_t<NV>>;

template <int NV>
using modchain2_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split16_t<NV>>>;

template <int NV>
using modchain2_t = wrap::control_rate<modchain2_t_<NV>>;

template <int NV>
using chain431_t = container::chain<parameter::empty, 
                                    wrap::fix<2, modchain2_t<NV>>>;

template <int NV>
using converter_mod = parameter::chain<ranges::Identity, 
                                       parameter::plain<project::PitchShifter2<NV>, 1>, 
                                       parameter::plain<project::PitchShifter2<NV>, 2>>;

template <int NV>
using converter_t = control::converter<converter_mod<NV>, 
                                       conversion_logic::ms2samples>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<converter_t<NV>, 0>, 
                               control::tempo_sync<NV>>;

template <int NV> using xfader_c0 = comp_mod_2<NV>;

DECLARE_PARAMETER_RANGE_SKEW(xfader_c1Range, 
                             -114., 
                             0., 
                             0.687642);

template <int NV>
using xfader_c1 = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      xfader_c1Range>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::overlap>;

using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::empty>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<2, comp_t<NV>>, 
                                   math::clear<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain9_t>, 
                                 chain14_t<NV>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>>;
using peak10_t = wrap::no_data<core::peak>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::clear<NV>>, 
                                   oscillator_t<NV>, 
                                   core::gain<NV>, 
                                   math::pi<NV>, 
                                   wrap::no_process<math::tanh<NV>>, 
                                   wrap::no_process<filters::one_pole<NV>>, 
                                   peak10_t, 
                                   core::gain<NV>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain13_t<NV>>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain21_t<NV>>, 
                                   wrap::no_process<math::clear<NV>>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain11_t<NV>>, 
                                  chain12_t<NV>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>, 
                                  filters::one_pole<NV>, 
                                  control::minmax<NV, parameter::empty>>;

template <int NV>
using converter1_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<project::res1<NV>, 1>, 
                                        parameter::plain<project::res1<NV>, 1>, 
                                        parameter::plain<project::res1<NV>, 1>>;

template <int NV>
using converter1_t = control::converter<converter1_mod<NV>, 
                                        conversion_logic::freq2ms>;

template <int NV>
using minmax3_mod = parameter::chain<ranges::Identity, 
                                     parameter::plain<filters::allpass<NV>, 0>, 
                                     parameter::plain<project::res1<NV>, 5>, 
                                     parameter::plain<converter1_t<NV>, 0>>;

template <int NV>
using minmax3_t = control::minmax<NV, minmax3_mod<NV>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, minmax3_t<NV>>, 
                                  converter1_t<NV>, 
                                  math::clear<NV>>;

template <int NV>
using Pitch_t = container::chain<parameter::empty, 
                                 wrap::fix<1, chain3_t<NV>>>;
using peak3_t = wrap::data<core::peak, 
                           data::external::displaybuffer<0>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, Pitch_t<NV>>, 
                                     math::clear<NV>, 
                                     math::add<NV>, 
                                     math::pi<NV>, 
                                     peak3_t, 
                                     math::clear<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;
using peak9_t = peak10_t;

template <int NV>
using pma10_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<project::res1<NV>, 0>, 
                                   parameter::plain<project::res1<NV>, 0>, 
                                   parameter::plain<project::res1<NV>, 0>>;

template <int NV>
using pma10_t = control::pma<NV, pma10_mod<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, filters::allpass<NV>>, 
                                  filters::one_pole<NV>, 
                                  filters::one_pole<NV>, 
                                  wrap::no_process<core::gain<NV>>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, project::res1<NV>>>;

template <int NV> using chain8_t = chain5_t<NV>;

template <int NV> using chain7_t = chain5_t<NV>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain4_t<NV>>, 
                                   chain5_t<NV>, 
                                   chain8_t<NV>, 
                                   chain7_t<NV>>;

namespace ResStage_t_parameters
{
// Parameter list for ResStage_impl::ResStage_t ----------------------------------------------------

DECLARE_PARAMETER_RANGE_SKEW(CutOffA_InputRange, 
                             0., 
                             1., 
                             0.239104);

template <int NV>
using CutOffA = parameter::chain<CutOffA_InputRange, 
                                 parameter::plain<math::add<NV>, 0>>;

DECLARE_PARAMETER_RANGE_SKEW(CompRel_InputRange, 
                             1., 
                             32., 
                             0.430677);

template <int NV>
using CompRel = parameter::chain<CompRel_InputRange, 
                                 parameter::plain<math::add<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(Rate_0Range, 
                             -24., 
                             24., 
                             1.);

template <int NV>
using Rate_0 = parameter::from0To1<project::PitchShifter2<NV>, 
                                   0, 
                                   Rate_0Range>;

DECLARE_PARAMETER_RANGE_STEP(Rate_1Range, 
                             0., 
                             18., 
                             1.);

template <int NV>
using Rate_1 = parameter::from0To1<ResStage_impl::tempo_sync_t<NV>, 
                                   0, 
                                   Rate_1Range>;

template <int NV>
using Rate = parameter::chain<ranges::Identity, 
                              Rate_0<NV>, 
                              Rate_1<NV>>;

DECLARE_PARAMETER_RANGE_STEP(ResMode_InputRange, 
                             1., 
                             4., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(ResMode_0Range, 
                             0., 
                             3., 
                             1.);

template <int NV>
using ResMode_0 = parameter::from0To1<ResStage_impl::branch_t<NV>, 
                                      0, 
                                      ResMode_0Range>;

template <int NV>
using ResMode = parameter::chain<ResMode_InputRange, ResMode_0<NV>>;

template <int NV>
using ResLP = parameter::chain<ranges::Identity, 
                               parameter::plain<filters::one_pole<NV>, 0>, 
                               parameter::plain<project::res1<NV>, 3>, 
                               parameter::plain<project::res1<NV>, 3>, 
                               parameter::plain<project::res1<NV>, 3>>;

DECLARE_PARAMETER_RANGE_SKEW(ResFeed_0Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using ResFeed_0 = parameter::from0To1<filters::allpass<NV>, 
                                      1, 
                                      ResFeed_0Range>;

template <int NV>
using ResFeed_1 = parameter::from0To1<ResStage_impl::pma10_t<NV>, 
                                      2, 
                                      ResStage_impl::peak_modRange>;

template <int NV>
using ResFeed = parameter::chain<ranges::Identity, 
                                 ResFeed_0<NV>, 
                                 ResFeed_1<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Fmode1_InputRange, 
                             1., 
                             11., 
                             1.);

template <int NV>
using Fmode1 = parameter::chain<Fmode1_InputRange, 
                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using qA = parameter::plain<project::FilterForRes<NV>, 
                            1>;
template <int NV>
using CompThresh = parameter::plain<ResStage_impl::comp_t<NV>, 
                                    0>;
template <int NV>
using CompAtk = parameter::plain<ResStage_impl::comp_t<NV>, 
                                 1>;
template <int NV>
using CompRatio = parameter::plain<ResStage_impl::comp_t<NV>, 
                                   2>;
template <int NV>
using InputTrig = parameter::plain<ResStage_impl::xfader_t<NV>, 
                                   0>;
template <int NV>
using InputHP = parameter::plain<filters::one_pole<NV>, 0>;
template <int NV>
using ResFreq = parameter::plain<ResStage_impl::minmax3_t<NV>, 
                                 0>;
template <int NV>
using ResMin = parameter::plain<ResStage_impl::minmax3_t<NV>, 
                                1>;
template <int NV>
using ResMax = parameter::plain<ResStage_impl::minmax3_t<NV>, 
                                2>;
template <int NV>
using ResStep = parameter::plain<ResStage_impl::minmax3_t<NV>, 
                                 4>;
template <int NV>
using PostCut = parameter::plain<project::FilterForRes<NV>, 
                                 0>;
template <int NV> using PostRes = qA<NV>;
template <int NV>
using PostMode = parameter::plain<project::FilterForRes<NV>, 
                                  2>;
template <int NV>
using Phase = parameter::plain<math::add<NV>, 0>;
template <int NV>
using ResStage_t_plist = parameter::list<CutOffA<NV>, 
                                         qA<NV>, 
                                         CompThresh<NV>, 
                                         CompAtk<NV>, 
                                         CompRel<NV>, 
                                         CompRatio<NV>, 
                                         InputTrig<NV>, 
                                         InputHP<NV>, 
                                         Rate<NV>, 
                                         ResFreq<NV>, 
                                         ResMin<NV>, 
                                         ResMax<NV>, 
                                         ResStep<NV>, 
                                         ResMode<NV>, 
                                         ResLP<NV>, 
                                         ResFeed<NV>, 
                                         PostCut<NV>, 
                                         PostRes<NV>, 
                                         PostMode<NV>, 
                                         Fmode1<NV>, 
                                         Phase<NV>>;
}

template <int NV>
using ResStage_t_ = container::chain<ResStage_t_parameters::ResStage_t_plist<NV>, 
                                     wrap::fix<2, chain431_t<NV>>, 
                                     tempo_sync_t<NV>, 
                                     converter_t<NV>, 
                                     project::PitchShifter2<NV>, 
                                     xfader_t<NV>, 
                                     split_t<NV>, 
                                     split5_t<NV>, 
                                     control::tempo_sync<NV>, 
                                     chain6_t<NV>, 
                                     modchain_t<NV>, 
                                     peak9_t, 
                                     project::FilterForRes<NV>, 
                                     pma10_t<NV>, 
                                     branch_t<NV>, 
                                     wrap::no_process<math::tanh<NV>>, 
                                     project::FilterForRes<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public ResStage_impl::ResStage_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 1;
		
		SNEX_METADATA_ID(ResStage);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(344)
		{
			0x005B, 0x0000, 0x4300, 0x7475, 0x664F, 0x4166, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0xB53F, 0x74D7, 0x003E, 0x0000, 
            0x5B00, 0x0001, 0x0000, 0x4171, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0002, 
            0x0000, 0x6F43, 0x706D, 0x6854, 0x6572, 0x6873, 0x0000, 0xC800, 
            0x00C2, 0x0000, 0x6600, 0xDA66, 0x3EC1, 0xAD83, 0xCD40, 0xCCCC, 
            0x5B3D, 0x0003, 0x0000, 0x6F43, 0x706D, 0x7441, 0x006B, 0x0000, 
            0x0000, 0x0000, 0x437A, 0x0000, 0x0000, 0x81A3, 0x3EDC, 0xCCCD, 
            0x3DCC, 0x045B, 0x0000, 0x4300, 0x6D6F, 0x5270, 0x6C65, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0042, 0xB400, 0xA341, 0xDC81, 0xCD3E, 
            0xCCCC, 0x5B3D, 0x0005, 0x0000, 0x6F43, 0x706D, 0x6152, 0x6974, 
            0x006F, 0x0000, 0x0000, 0x0000, 0x437A, 0xCCCD, 0x41E4, 0x81A3, 
            0x3EDC, 0xCCCD, 0x3DCC, 0x065B, 0x0000, 0x4900, 0x706E, 0x7475, 
            0x7254, 0x6769, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0007, 0x0000, 0x6E49, 
            0x7570, 0x4874, 0x0050, 0x0000, 0x41A0, 0x4000, 0x469C, 0xB3E5, 
            0x44E8, 0x6C1A, 0x3E6B, 0x0000, 0x0000, 0x085B, 0x0000, 0x5200, 
            0x7461, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x095B, 0x0000, 0x5200, 0x7365, 
            0x7246, 0x7165, 0x0000, 0x0000, 0x0000, 0x8000, 0xA73F, 0xC637, 
            0x003E, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000A, 0x0000, 0x6552, 
            0x4D73, 0x6E69, 0x0000, 0x5C00, 0x0043, 0x5C00, 0xF345, 0xA55E, 
            0x1A43, 0x6B6C, 0x003E, 0x0000, 0x5B00, 0x000B, 0x0000, 0x6552, 
            0x4D73, 0x7861, 0x0000, 0x5C00, 0x0043, 0x5C00, 0x0045, 0x5C00, 
            0x1A45, 0x6B6C, 0x003E, 0x0000, 0x5B00, 0x000C, 0x0000, 0x6552, 
            0x5373, 0x6574, 0x0070, 0x0000, 0x0000, 0x0000, 0x4380, 0x0000, 
            0x435C, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0D5B, 0x0000, 0x5200, 
            0x7365, 0x6F4D, 0x6564, 0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 
            0x0000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x000E, 0x0000, 
            0x6552, 0x4C73, 0x0050, 0x0000, 0x41A0, 0x4000, 0x469C, 0x4000, 
            0x469C, 0x6C1A, 0x3E6B, 0x0000, 0x0000, 0x0F5B, 0x0000, 0x5200, 
            0x7365, 0x6546, 0x6465, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0010, 0x0000, 
            0x6F50, 0x7473, 0x7543, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x1504, 0x3F1B, 0xD7B5, 0x3E74, 0x0000, 0x0000, 0x115B, 0x0000, 
            0x5000, 0x736F, 0x5274, 0x7365, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0012, 
            0x0000, 0x6F50, 0x7473, 0x6F4D, 0x6564, 0x0000, 0x8000, 0x003F, 
            0x5000, 0x0041, 0xA000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0013, 0x0000, 0x6D46, 0x646F, 0x3165, 0x0000, 0x8000, 0x003F, 
            0x3000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0014, 0x0000, 0x6850, 0x7361, 0x0065, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x8591, 0x3EB0, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain431 = this->getT(0);                                           // ResStage_impl::chain431_t<NV>
		auto& modchain2 = this->getT(0).getT(0);                                  // ResStage_impl::modchain2_t<NV>
		auto& split16 = this->getT(0).getT(0).getT(0);                            // ResStage_impl::split16_t<NV>
		auto& chain29 = this->getT(0).getT(0).getT(0).getT(0);                    // ResStage_impl::chain29_t<NV>
		auto& branch3 = this->getT(0).getT(0).getT(0).getT(0).getT(0);            // ResStage_impl::branch3_t<NV>
		auto& add20 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);      // math::add<NV>
		auto& add21 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1);      // math::add<NV>
		auto& add42 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2);      // math::add<NV>
		auto& peak = this->getT(0).getT(0).getT(0).getT(0).getT(1);               // ResStage_impl::peak_t<NV>
		auto& pma1 = this->getT(0).getT(0).getT(0).getT(0).getT(2);               // control::pma<NV, parameter::empty>
		auto& chain30 = this->getT(0).getT(0).getT(0).getT(1);                    // ResStage_impl::chain30_t<NV>
		auto& branch5 = this->getT(0).getT(0).getT(0).getT(1).getT(0);            // ResStage_impl::branch5_t<NV>
		auto& add40 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0);      // math::add<NV>
		auto& add41 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1);      // math::add<NV>
		auto& add43 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(2);      // math::add<NV>
		auto& peak2 = this->getT(0).getT(0).getT(0).getT(1).getT(1);              // ResStage_impl::peak2_t<NV>
		auto& pma3 = this->getT(0).getT(0).getT(0).getT(1).getT(2);               // ResStage_impl::pma3_t<NV>
		auto& smoothed_parameter = this->getT(0).getT(0).getT(0).getT(1).getT(3); // control::smoothed_parameter<NV, smoothers::low_pass<NV>>
		auto& chain32 = this->getT(0).getT(0).getT(0).getT(2);                    // ResStage_impl::chain32_t<NV>
		auto& branch7 = this->getT(0).getT(0).getT(0).getT(2).getT(0);            // ResStage_impl::branch7_t<NV>
		auto& add47 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(0);      // math::add<NV>
		auto& add48 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(1);      // math::add<NV>
		auto& add49 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(2);      // math::add<NV>
		auto& peak5 = this->getT(0).getT(0).getT(0).getT(2).getT(1);              // ResStage_impl::peak5_t<NV>
		auto& pma5 = this->getT(0).getT(0).getT(0).getT(2).getT(2);               // ResStage_impl::pma5_t<NV>
		auto& chain33 = this->getT(0).getT(0).getT(0).getT(3);                    // ResStage_impl::chain33_t<NV>
		auto& branch8 = this->getT(0).getT(0).getT(0).getT(3).getT(0);            // ResStage_impl::branch8_t<NV>
		auto& add50 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(0);      // math::add<NV>
		auto& add51 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(1);      // math::add<NV>
		auto& add52 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(2);      // math::add<NV>
		auto& peak6 = this->getT(0).getT(0).getT(0).getT(3).getT(1);              // ResStage_impl::peak6_t<NV>
		auto& pma6 = this->getT(0).getT(0).getT(0).getT(3).getT(2);               // ResStage_impl::pma6_t<NV>
		auto& chain34 = this->getT(0).getT(0).getT(0).getT(4);                    // ResStage_impl::chain34_t<NV>
		auto& branch9 = this->getT(0).getT(0).getT(0).getT(4).getT(0);            // ResStage_impl::branch9_t<NV>
		auto& add53 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(0);      // math::add<NV>
		auto& add54 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(1);      // math::add<NV>
		auto& add55 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(2);      // math::add<NV>
		auto& peak7 = this->getT(0).getT(0).getT(0).getT(4).getT(1);              // ResStage_impl::peak7_t<NV>
		auto& pma7 = this->getT(0).getT(0).getT(0).getT(4).getT(2);               // ResStage_impl::pma7_t<NV>
		auto& chain35 = this->getT(0).getT(0).getT(0).getT(5);                    // ResStage_impl::chain35_t<NV>
		auto& branch10 = this->getT(0).getT(0).getT(0).getT(5).getT(0);           // ResStage_impl::branch10_t<NV>
		auto& add56 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(0);      // math::add<NV>
		auto& add57 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(1);      // math::add<NV>
		auto& add58 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(2);      // math::add<NV>
		auto& peak8 = this->getT(0).getT(0).getT(0).getT(5).getT(1);              // ResStage_impl::peak8_t<NV>
		auto& pma8 = this->getT(0).getT(0).getT(0).getT(5).getT(2);               // ResStage_impl::pma8_t<NV>
		auto& tempo_sync = this->getT(1);                                         // ResStage_impl::tempo_sync_t<NV>
		auto& converter = this->getT(2);                                          // ResStage_impl::converter_t<NV>
		auto& faust = this->getT(3);                                              // project::PitchShifter2<NV>
		auto& xfader = this->getT(4);                                             // ResStage_impl::xfader_t<NV>
		auto& split = this->getT(5);                                              // ResStage_impl::split_t<NV>
		auto& chain9 = this->getT(5).getT(0);                                     // ResStage_impl::chain9_t
		auto& chain14 = this->getT(5).getT(1);                                    // ResStage_impl::chain14_t<NV>
		auto& comp = this->getT(5).getT(1).getT(0);                               // ResStage_impl::comp_t<NV>
		auto& clear5 = this->getT(5).getT(1).getT(1);                             // math::clear<NV>
		auto& split5 = this->getT(6);                                             // ResStage_impl::split5_t<NV>
		auto& chain11 = this->getT(6).getT(0);                                    // ResStage_impl::chain11_t<NV>
		auto& gain = this->getT(6).getT(0).getT(0);                               // core::gain<NV>
		auto& chain12 = this->getT(6).getT(1);                                    // ResStage_impl::chain12_t<NV>
		auto& chain21 = this->getT(6).getT(1).getT(0);                            // ResStage_impl::chain21_t<NV>
		auto& chain13 = this->getT(6).getT(1).getT(0).getT(0);                    // ResStage_impl::chain13_t<NV>
		auto& clear4 = this->getT(6).getT(1).getT(0).getT(0).getT(0);             // math::clear<NV>
		auto& oscillator = this->getT(6).getT(1).getT(0).getT(0).getT(1);         // ResStage_impl::oscillator_t<NV>
		auto& gain1 = this->getT(6).getT(1).getT(0).getT(0).getT(2);              // core::gain<NV>
		auto& pi = this->getT(6).getT(1).getT(0).getT(0).getT(3);                 // math::pi<NV>
		auto& tanh1 = this->getT(6).getT(1).getT(0).getT(0).getT(4);              // wrap::no_process<math::tanh<NV>>
		auto& one_pole1 = this->getT(6).getT(1).getT(0).getT(0).getT(5);          // wrap::no_process<filters::one_pole<NV>>
		auto& peak10 = this->getT(6).getT(1).getT(0).getT(0).getT(6);             // ResStage_impl::peak10_t
		auto& gain76 = this->getT(6).getT(1).getT(0).getT(0).getT(7);             // core::gain<NV>
		auto& clear2 = this->getT(6).getT(1).getT(1);                             // wrap::no_process<math::clear<NV>>
		auto& tempo_sync1 = this->getT(7);                                        // control::tempo_sync<NV>
		auto& chain6 = this->getT(8);                                             // ResStage_impl::chain6_t<NV>
		auto& gain5 = this->getT(8).getT(0);                                      // core::gain<NV>
		auto& one_pole30 = this->getT(8).getT(1);                                 // filters::one_pole<NV>
		auto& minmax = this->getT(8).getT(2);                                     // control::minmax<NV, parameter::empty>
		auto& modchain = this->getT(9);                                           // ResStage_impl::modchain_t<NV>
		auto& Pitch = this->getT(9).getT(0);                                      // ResStage_impl::Pitch_t<NV>
		auto& chain3 = this->getT(9).getT(0).getT(0);                             // ResStage_impl::chain3_t<NV>
		auto& minmax3 = this->getT(9).getT(0).getT(0).getT(0);                    // ResStage_impl::minmax3_t<NV>
		auto& converter1 = this->getT(9).getT(0).getT(0).getT(1);                 // ResStage_impl::converter1_t<NV>
		auto& clear = this->getT(9).getT(0).getT(0).getT(2);                      // math::clear<NV>
		auto& clear1 = this->getT(9).getT(1);                                     // math::clear<NV>
		auto& add7 = this->getT(9).getT(2);                                       // math::add<NV>
		auto& pi3 = this->getT(9).getT(3);                                        // math::pi<NV>
		auto& peak3 = this->getT(9).getT(4);                                      // ResStage_impl::peak3_t
		auto& clear3 = this->getT(9).getT(5);                                     // math::clear<NV>
		auto& peak9 = this->getT(10);                                             // ResStage_impl::peak9_t
		auto& FilterForRes1 = this->getT(11);                                     // project::FilterForRes<NV>
		auto& pma10 = this->getT(12);                                             // ResStage_impl::pma10_t<NV>
		auto& branch = this->getT(13);                                            // ResStage_impl::branch_t<NV>
		auto& chain4 = this->getT(13).getT(0);                                    // ResStage_impl::chain4_t<NV>
		auto& allpass1 = this->getT(13).getT(0).getT(0);                          // filters::allpass<NV>
		auto& one_pole4 = this->getT(13).getT(0).getT(1);                         // filters::one_pole<NV>
		auto& one_pole3 = this->getT(13).getT(0).getT(2);                         // filters::one_pole<NV>
		auto& gain3 = this->getT(13).getT(0).getT(3);                             // wrap::no_process<core::gain<NV>>
		auto& chain5 = this->getT(13).getT(1);                                    // ResStage_impl::chain5_t<NV>
		auto& res3 = this->getT(13).getT(1).getT(0);                              // project::res1<NV>
		auto& chain8 = this->getT(13).getT(2);                                    // ResStage_impl::chain8_t<NV>
		auto& res4 = this->getT(13).getT(2).getT(0);                              // project::res1<NV>
		auto& chain7 = this->getT(13).getT(3);                                    // ResStage_impl::chain7_t<NV>
		auto& res5 = this->getT(13).getT(3).getT(0);                              // project::res1<NV>
		auto& tanh2 = this->getT(14);                                             // wrap::no_process<math::tanh<NV>>
		auto& FilterForRes = this->getT(15);                                      // project::FilterForRes<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, add47); // CutOffA -> add47::Value
		
		this->getParameterT(1).connectT(0, FilterForRes1); // qA -> FilterForRes1::Res
		
		this->getParameterT(2).connectT(0, comp); // CompThresh -> comp::Threshhold
		
		this->getParameterT(3).connectT(0, comp); // CompAtk -> comp::Attack
		
		this->getParameterT(4).connectT(0, add53); // CompRel -> add53::Value
		
		this->getParameterT(5).connectT(0, comp); // CompRatio -> comp::Release
		
		this->getParameterT(6).connectT(0, xfader); // InputTrig -> xfader::Value
		
		this->getParameterT(7).connectT(0, one_pole30); // InputHP -> one_pole30::Frequency
		
		auto& Rate_p = this->getParameterT(8);
		Rate_p.connectT(0, faust);      // Rate -> faust::shiftsemitones
		Rate_p.connectT(1, tempo_sync); // Rate -> tempo_sync::Tempo
		
		this->getParameterT(9).connectT(0, minmax3); // ResFreq -> minmax3::Value
		
		this->getParameterT(10).connectT(0, minmax3); // ResMin -> minmax3::Minimum
		
		this->getParameterT(11).connectT(0, minmax3); // ResMax -> minmax3::Maximum
		
		this->getParameterT(12).connectT(0, minmax3); // ResStep -> minmax3::Step
		
		this->getParameterT(13).connectT(0, branch); // ResMode -> branch::Index
		
		auto& ResLP_p = this->getParameterT(14);
		ResLP_p.connectT(0, one_pole3); // ResLP -> one_pole3::Frequency
		ResLP_p.connectT(1, res3);      // ResLP -> res3::LP
		ResLP_p.connectT(2, res5);      // ResLP -> res5::LP
		ResLP_p.connectT(3, res4);      // ResLP -> res4::LP
		
		auto& ResFeed_p = this->getParameterT(15);
		ResFeed_p.connectT(0, allpass1); // ResFeed -> allpass1::Q
		ResFeed_p.connectT(1, pma10);    // ResFeed -> pma10::Add
		
		this->getParameterT(16).connectT(0, FilterForRes); // PostCut -> FilterForRes::Cut
		
		this->getParameterT(17).connectT(0, FilterForRes); // PostRes -> FilterForRes::Res
		
		this->getParameterT(18).connectT(0, FilterForRes); // PostMode -> FilterForRes::Mode
		
		this->getParameterT(19).connectT(0, add50); // Fmode1 -> add50::Value
		
		this->getParameterT(20).connectT(0, add40); // Phase -> add40::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		peak.getParameter().connectT(0, pma1);                                  // peak -> pma1::Add
		pma3.getWrappedObject().getParameter().connectT(0, smoothed_parameter); // pma3 -> smoothed_parameter::Value
		pma3.getWrappedObject().getParameter().connectT(1, allpass1);           // pma3 -> allpass1::Smoothing
		pma3.getWrappedObject().getParameter().connectT(2, res3);               // pma3 -> res3::Comp
		pma3.getWrappedObject().getParameter().connectT(3, res3);               // pma3 -> res3::FbModifier
		pma3.getWrappedObject().getParameter().connectT(4, res5);               // pma3 -> res5::FbModifier
		pma3.getWrappedObject().getParameter().connectT(5, res4);               // pma3 -> res4::Comp
		peak2.getParameter().connectT(0, pma3);                                 // peak2 -> pma3::Add
		pma5.getWrappedObject().getParameter().connectT(0, FilterForRes1);      // pma5 -> FilterForRes1::Cut
		peak5.getParameter().connectT(0, pma5);                                 // peak5 -> pma5::Add
		pma6.getWrappedObject().getParameter().connectT(0, FilterForRes1);      // pma6 -> FilterForRes1::Mode
		peak6.getParameter().connectT(0, pma6);                                 // peak6 -> pma6::Add
		comp.getParameter().connectT(0, add7);                                  // comp -> add7::Value
		comp.getParameter().connectT(1, oscillator);                            // comp -> oscillator::Gate
		comp.getParameter().connectT(2, gain1);                                 // comp -> gain1::Gain
		pma7.getWrappedObject().getParameter().connectT(0, comp);               // pma7 -> comp::Ratio
		peak7.getParameter().connectT(0, pma7);                                 // peak7 -> pma7::Add
		pma8.getWrappedObject().getParameter().connectT(0, tempo_sync1);        // pma8 -> tempo_sync1::Multiplier
		peak8.getParameter().connectT(0, pma8);                                 // peak8 -> pma8::Add
		converter.getWrappedObject().getParameter().connectT(0, faust);         // converter -> faust::windowsamples
		converter.getWrappedObject().getParameter().connectT(1, faust);         // converter -> faust::xfadesamples
		tempo_sync.getParameter().connectT(0, converter);                       // tempo_sync -> converter::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);                       // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain76);                     // xfader -> gain76::Gain
		converter1.getWrappedObject().getParameter().connectT(0, res3);    // converter1 -> res3::Del
		converter1.getWrappedObject().getParameter().connectT(1, res4);    // converter1 -> res4::Del
		converter1.getWrappedObject().getParameter().connectT(2, res5);    // converter1 -> res5::Del
		minmax3.getWrappedObject().getParameter().connectT(0, allpass1);   // minmax3 -> allpass1::Frequency
		minmax3.getWrappedObject().getParameter().connectT(1, res4);       // minmax3 -> res4::Freq
		minmax3.getWrappedObject().getParameter().connectT(2, converter1); // minmax3 -> converter1::Value
		pma10.getWrappedObject().getParameter().connectT(0, res3);         // pma10 -> res3::feed
		pma10.getWrappedObject().getParameter().connectT(1, res4);         // pma10 -> res4::feed
		pma10.getWrappedObject().getParameter().connectT(2, res5);         // pma10 -> res5::feed
		
		// Default Values --------------------------------------------------------------------------
		
		branch3.setParameterT(0, 0.); // container::branch::Index
		
		add20.setParameterT(0, 0.); // math::add::Value
		
		add21.setParameterT(0, 0.); // math::add::Value
		
		add42.setParameterT(0, 0.); // math::add::Value
		
		pma1.setParameterT(0, 0.); // control::pma::Value
		pma1.setParameterT(1, 0.); // control::pma::Multiply
		;                          // pma1::Add is automated
		
		branch5.setParameterT(0, 0.); // container::branch::Index
		
		; // add40::Value is automated
		
		add41.setParameterT(0, 0.); // math::add::Value
		
		add43.setParameterT(0, 0.); // math::add::Value
		
		pma3.setParameterT(0, 0.); // control::pma::Value
		pma3.setParameterT(1, 0.); // control::pma::Multiply
		;                          // pma3::Add is automated
		
		;                                          // smoothed_parameter::Value is automated
		smoothed_parameter.setParameterT(1, 125.); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter.setParameterT(2, 1.);   // control::smoothed_parameter::Enabled
		
		branch7.setParameterT(0, 0.); // container::branch::Index
		
		; // add47::Value is automated
		
		add48.setParameterT(0, 0.); // math::add::Value
		
		add49.setParameterT(0, 0.); // math::add::Value
		
		pma5.setParameterT(0, 0.); // control::pma::Value
		pma5.setParameterT(1, 0.); // control::pma::Multiply
		;                          // pma5::Add is automated
		
		branch8.setParameterT(0, 0.); // container::branch::Index
		
		; // add50::Value is automated
		
		add51.setParameterT(0, 0.); // math::add::Value
		
		add52.setParameterT(0, 0.); // math::add::Value
		
		pma6.setParameterT(0, 0.); // control::pma::Value
		pma6.setParameterT(1, 0.); // control::pma::Multiply
		;                          // pma6::Add is automated
		
		branch9.setParameterT(0, 0.); // container::branch::Index
		
		; // add53::Value is automated
		
		add54.setParameterT(0, 0.); // math::add::Value
		
		add55.setParameterT(0, 0.); // math::add::Value
		
		pma7.setParameterT(0, 0.); // control::pma::Value
		pma7.setParameterT(1, 0.); // control::pma::Multiply
		;                          // pma7::Add is automated
		
		branch10.setParameterT(0, 0.); // container::branch::Index
		
		add56.setParameterT(0, 0.); // math::add::Value
		
		add57.setParameterT(0, 0.); // math::add::Value
		
		add58.setParameterT(0, 0.); // math::add::Value
		
		pma8.setParameterT(0, 0.); // control::pma::Value
		pma8.setParameterT(1, 0.); // control::pma::Multiply
		;                          // pma8::Add is automated
		
		;                                  // tempo_sync::Tempo is automated
		tempo_sync.setParameterT(1, 1.);   // control::tempo_sync::Multiplier
		tempo_sync.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // converter::Value is automated
		
		; // faust::shiftsemitones is automated
		; // faust::windowsamples is automated
		; // faust::xfadesamples is automated
		
		; // xfader::Value is automated
		
		;                          // comp::Threshhold is automated
		;                          // comp::Attack is automated
		;                          // comp::Release is automated
		;                          // comp::Ratio is automated
		comp.setParameterT(4, 0.); // dynamics::comp::Sidechain
		
		clear5.setParameterT(0, 0.); // math::clear::Value
		
		;                             // gain::Gain is automated
		gain.setParameterT(1, 0.);    // core::gain::Smoothing
		gain.setParameterT(2, -100.); // core::gain::ResetValue
		
		clear4.setParameterT(0, 0.218947); // math::clear::Value
		
		oscillator.setParameterT(0, 3.);   // core::oscillator::Mode
		oscillator.setParameterT(1, 76.4); // core::oscillator::Frequency
		oscillator.setParameterT(2, 0.);   // core::oscillator::FreqRatio
		;                                  // oscillator::Gate is automated
		oscillator.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator.setParameterT(5, 1.);   // core::oscillator::Gain
		
		;                           // gain1::Gain is automated
		gain1.setParameterT(1, 0.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.); // core::gain::ResetValue
		
		pi.setParameterT(0, 1.); // math::pi::Value
		
		tanh1.setParameterT(0, 0.511827); // math::tanh::Value
		
		one_pole1.setParameterT(0, 22.7884); // filters::one_pole::Frequency
		one_pole1.setParameterT(1, 1.);      // filters::one_pole::Q
		one_pole1.setParameterT(2, 0.);      // filters::one_pole::Gain
		one_pole1.setParameterT(3, 0.01);    // filters::one_pole::Smoothing
		one_pole1.setParameterT(4, 0.);      // filters::one_pole::Mode
		one_pole1.setParameterT(5, 1.);      // filters::one_pole::Enabled
		
		;                               // gain76::Gain is automated
		gain76.setParameterT(1, 0.);    // core::gain::Smoothing
		gain76.setParameterT(2, -100.); // core::gain::ResetValue
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		tempo_sync1.setParameterT(0, 0.);     // control::tempo_sync::Tempo
		;                                     // tempo_sync1::Multiplier is automated
		tempo_sync1.setParameterT(2, 1.);     // control::tempo_sync::Enabled
		tempo_sync1.setParameterT(3, 9736.6); // control::tempo_sync::UnsyncedTime
		
		gain5.setParameterT(0, -11.);  // core::gain::Gain
		gain5.setParameterT(1, 0.);    // core::gain::Smoothing
		gain5.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                  // one_pole30::Frequency is automated
		one_pole30.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole30.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole30.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole30.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole30.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		minmax.setParameterT(0, 0.);   // control::minmax::Value
		minmax.setParameterT(1, -48.); // control::minmax::Minimum
		minmax.setParameterT(2, 48.);  // control::minmax::Maximum
		minmax.setParameterT(3, 1.);   // control::minmax::Skew
		minmax.setParameterT(4, 0.);   // control::minmax::Step
		minmax.setParameterT(5, 0.);   // control::minmax::Polarity
		
		;                             // minmax3::Value is automated
		;                             // minmax3::Minimum is automated
		;                             // minmax3::Maximum is automated
		minmax3.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax3::Step is automated
		minmax3.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // converter1::Value is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		; // add7::Value is automated
		
		pi3.setParameterT(0, 0.42405); // math::pi::Value
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		; // FilterForRes1::Cut is automated
		; // FilterForRes1::Res is automated
		; // FilterForRes1::Mode is automated
		
		pma10.setParameterT(0, 0.);          // control::pma::Value
		pma10.setParameterT(1, 5.55112e-17); // control::pma::Multiply
		;                                    // pma10::Add is automated
		
		; // branch::Index is automated
		
		;                              // allpass1::Frequency is automated
		;                              // allpass1::Q is automated
		allpass1.setParameterT(2, 0.); // filters::allpass::Gain
		;                              // allpass1::Smoothing is automated
		allpass1.setParameterT(4, 0.); // filters::allpass::Mode
		allpass1.setParameterT(5, 1.); // filters::allpass::Enabled
		
		one_pole4.setParameterT(0, 20.);  // filters::one_pole::Frequency
		one_pole4.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole4.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole4.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole4.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole4.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                 // one_pole3::Frequency is automated
		one_pole3.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole3.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole3.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole3.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole3.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		gain3.setParameterT(0, -7);  // core::gain::Gain
		gain3.setParameterT(1, 20.); // core::gain::Smoothing
		gain3.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                             // res3::feed is automated
		;                             // res3::Del is automated
		res3.setParameterT(2, 3.);    // project::res1::Block
		;                             // res3::LP is automated
		;                             // res3::FbModifier is automated
		res3.setParameterT(5, 188.2); // project::res1::Freq
		res3.setParameterT(6, 0.);    // project::res1::Mode
		;                             // res3::Comp is automated
		res3.setParameterT(8, 0.);    // project::res1::ga
		
		;                              // res4::feed is automated
		;                              // res4::Del is automated
		res4.setParameterT(2, 3.);     // project::res1::Block
		;                              // res4::LP is automated
		res4.setParameterT(4, 20000.); // project::res1::FbModifier
		;                              // res4::Freq is automated
		res4.setParameterT(6, 1.);     // project::res1::Mode
		;                              // res4::Comp is automated
		res4.setParameterT(8, 0.);     // project::res1::ga
		
		;                                // res5::feed is automated
		;                                // res5::Del is automated
		res5.setParameterT(2, 1.);       // project::res1::Block
		;                                // res5::LP is automated
		;                                // res5::FbModifier is automated
		res5.setParameterT(5, 447.9);    // project::res1::Freq
		res5.setParameterT(6, 2.);       // project::res1::Mode
		res5.setParameterT(7, 0.500463); // project::res1::Comp
		res5.setParameterT(8, 0.);       // project::res1::ga
		
		tanh2.setParameterT(0, 0.985261); // math::tanh::Value
		
		; // FilterForRes::Cut is automated
		; // FilterForRes::Res is automated
		; // FilterForRes::Mode is automated
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, -27.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 22.5);
		this->setParameterT(5, 28.6);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 1861.62);
		this->setParameterT(8, 0.);
		this->setParameterT(9, 0.387143);
		this->setParameterT(10, 330.742);
		this->setParameterT(11, 3520.);
		this->setParameterT(12, 220.);
		this->setParameterT(13, 2.);
		this->setParameterT(14, 20000.);
		this->setParameterT(15, 1.);
		this->setParameterT(16, 0.605789);
		this->setParameterT(17, 0.);
		this->setParameterT(18, 5.);
		this->setParameterT(19, 1.);
		this->setParameterT(20, 0.344769);
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
		
		this->getT(0).getT(0).getT(0).getT(0).getT(1).setExternalData(b, index); // ResStage_impl::peak_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(1).setExternalData(b, index); // ResStage_impl::peak2_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(1).setExternalData(b, index); // ResStage_impl::peak5_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(1).setExternalData(b, index); // ResStage_impl::peak6_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(1).setExternalData(b, index); // ResStage_impl::peak7_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(1).setExternalData(b, index); // ResStage_impl::peak8_t<NV>
		this->getT(5).getT(1).getT(0).setExternalData(b, index);                 // ResStage_impl::comp_t<NV>
		this->getT(6).getT(1).getT(0).getT(0).getT(1).setExternalData(b, index); // ResStage_impl::oscillator_t<NV>
		this->getT(6).getT(1).getT(0).getT(0).getT(6).setExternalData(b, index); // ResStage_impl::peak10_t
		this->getT(9).getT(4).setExternalData(b, index);                         // ResStage_impl::peak3_t
		this->getT(10).setExternalData(b, index);                                // ResStage_impl::peak9_t
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
using ResStage = wrap::node<ResStage_impl::instance<NV>>;
}


