#pragma once

#include "FilterForRes.h"
#include "FilterForRes.h"
#include "FilterForRes.h"
#include "FilterForRes.h"
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

namespace ResStage2_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using chain431_t = container::chain<parameter::empty, 
                                    wrap::fix<2, project::FilterForRes<NV>>, 
                                    project::FilterForRes<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, project::FilterForRes<NV>>, 
                                 project::FilterForRes<NV>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain431_t<NV>>, 
                                    split_t<NV>>;

using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::empty>>;

template <int NV>
using comp_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<math::add<NV>, 0>, 
                                  parameter::plain<math::add<NV>, 0>>;

template <int NV>
using comp_t = wrap::mod<comp_mod<NV>, 
                         wrap::data<dynamics::comp, data::external::displaybuffer<0>>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<2, comp_t<NV>>, 
                                   math::clear<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain11_t>, 
                                  chain12_t<NV>>;

template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<project::PitchShifter<NV>, 0>>;
using stereo_cable = cable::block<2>;

template <int NV>
using tempo_sync1_mod = parameter::chain<ranges::Identity, 
                                         parameter::plain<project::PitchShifter<NV>, 1>, 
                                         parameter::plain<project::PitchShifter<NV>, 2>>;

template <int NV>
using tempo_sync1_t = wrap::mod<tempo_sync1_mod<NV>, 
                                control::tempo_sync<NV>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>, 
                                  math::add<NV>, 
                                  wrap::no_process<math::tanh<NV>>, 
                                  wrap::no_process<core::gain<NV>>, 
                                  filters::one_pole<NV>, 
                                  minmax_t<NV>, 
                                  routing::receive<stereo_cable>, 
                                  tempo_sync1_t<NV>, 
                                  project::PitchShifter<NV>, 
                                  routing::send<stereo_cable>>;

template <int NV>
using converter_mod = parameter::chain<ranges::Identity, 
                                       parameter::plain<core::fix_delay, 0>, 
                                       parameter::plain<jdsp::jdelay_thiran<NV>, 0>, 
                                       parameter::plain<fx::phase_delay<NV>, 0>, 
                                       parameter::plain<jdsp::jdelay_thiran<NV>, 1>>;

template <int NV>
using converter_t = control::converter<converter_mod<NV>, 
                                       conversion_logic::freq2ms>;

template <int NV>
using minmax2_mod = parameter::chain<ranges::Identity, 
                                     parameter::plain<converter_t<NV>, 0>, 
                                     parameter::plain<filters::allpass<NV>, 0>>;

template <int NV>
using minmax2_t = control::minmax<NV, minmax2_mod<NV>>;
template <int NV>
using converter1_t = control::converter<parameter::plain<minmax2_t<NV>, 1>, 
                                        conversion_logic::pitch2cent>;
template <int NV>
using converter9_t = control::converter<parameter::plain<converter1_t<NV>, 0>, 
                                        conversion_logic::st2pitch>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, converter9_t<NV>>, 
                                  converter1_t<NV>>;

template <int NV>
using converter25_t = control::converter<parameter::plain<minmax2_t<NV>, 2>, 
                                         conversion_logic::pitch2cent>;
template <int NV>
using converter24_t = control::converter<parameter::plain<converter25_t<NV>, 0>, 
                                         conversion_logic::st2pitch>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, converter24_t<NV>>, 
                                  converter25_t<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain2_t<NV>>, 
                                  chain3_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split2_t<NV>>, 
                                     minmax2_t<NV>, 
                                     converter_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, filters::allpass<NV>>, 
                                  filters::one_pole<NV>>;

template <int NV>
using dynamic_blocksize1_t_ = container::chain<parameter::empty, 
                                               wrap::fix<2, routing::receive<stereo_cable>>, 
                                               core::fix_delay, 
                                               filters::one_pole<NV>, 
                                               routing::send<stereo_cable>, 
                                               filters::one_pole<NV>>;

template <int NV>
using dynamic_blocksize1_t = wrap::dynamic_blocksize<dynamic_blocksize1_t_<NV>>;

template <int NV>
using dynamic_blocksize72_t_ = container::chain<parameter::empty, 
                                                wrap::fix<2, routing::receive<stereo_cable>>, 
                                                jdsp::jdelay_thiran<NV>, 
                                                fx::phase_delay<NV>, 
                                                filters::one_pole<NV>, 
                                                routing::send<stereo_cable>, 
                                                filters::one_pole<NV>>;

template <int NV>
using dynamic_blocksize72_t = wrap::dynamic_blocksize<dynamic_blocksize72_t_<NV>>;

using chain1_t = chain11_t;

using simple_ar_multimod = parameter::list<parameter::empty, parameter::empty>;

template <int NV>
using simple_ar_t = wrap::no_data<envelope::simple_ar<NV, simple_ar_multimod>>;

template <int NV>
using peak_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<core::phasor<NV>, 0>, 
                                  parameter::plain<simple_ar_t<NV>, 2>>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, math::add<NV>>, 
                                  math::pi<NV>, 
                                  math::rect<NV>, 
                                  peak_t<NV>, 
                                  math::clear<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain1_t>, 
                                  chain5_t<NV>>;

template <int NV>
using converter2_t = control::converter<parameter::plain<core::phasor<NV>, 1>, 
                                        conversion_logic::ms2freq>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<converter2_t<NV>, 0>, 
                               control::tempo_sync<NV>>;
template <int NV>
using converter3_t = control::converter<parameter::plain<tempo_sync_t<NV>, 3>, 
                                        conversion_logic::freq2ms>;
template <int NV>
using file_player_t = wrap::data<core::file_player<NV>, 
                                 data::external::audiofile<0>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, split1_t<NV>>, 
                                 converter3_t<NV>, 
                                 tempo_sync_t<NV>, 
                                 converter2_t<NV>, 
                                 core::phasor<NV>, 
                                 file_player_t<NV>, 
                                 filters::one_pole<NV>, 
                                 simple_ar_t<NV>>;

template <int NV>
using dynamic_blocksize_t = container::chain<parameter::empty, 
                                             wrap::fix<2, chain_t<NV>>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain4_t<NV>>, 
                                   dynamic_blocksize1_t<NV>, 
                                   dynamic_blocksize72_t<NV>, 
                                   dynamic_blocksize_t<NV>>;

namespace ResStage2_t_parameters
{
// Parameter list for ResStage2_impl::ResStage2_t --------------------------------------------------

template <int NV>
using CutOffA = parameter::chain<ranges::Identity, 
                                 parameter::plain<project::FilterForRes<NV>, 0>, 
                                 parameter::plain<project::FilterForRes<NV>, 0>>;

template <int NV> using CutOffB = CutOffA<NV>;

template <int NV>
using qA = parameter::chain<ranges::Identity, 
                            parameter::plain<project::FilterForRes<NV>, 1>, 
                            parameter::plain<project::FilterForRes<NV>, 1>>;

template <int NV> using qB = qA<NV>;

DECLARE_PARAMETER_RANGE_SKEW(InputTrigRange, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using InputTrig = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      InputTrigRange>;

DECLARE_PARAMETER_RANGE_STEP(ResMode_InputRange, 
                             1., 
                             4., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(ResMode_0Range, 
                             0., 
                             3., 
                             1.);

template <int NV>
using ResMode_0 = parameter::from0To1<ResStage2_impl::branch_t<NV>, 
                                      0, 
                                      ResMode_0Range>;

template <int NV>
using ResMode = parameter::chain<ResMode_InputRange, ResMode_0<NV>>;

template <int NV>
using ResLP = parameter::chain<ranges::Identity, 
                               parameter::plain<filters::one_pole<NV>, 0>, 
                               parameter::plain<filters::one_pole<NV>, 0>, 
                               parameter::plain<filters::one_pole<NV>, 0>, 
                               parameter::plain<filters::one_pole<NV>, 0>>;

DECLARE_PARAMETER_RANGE_SKEW(ResFeed_0Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using ResFeed_0 = parameter::from0To1<filters::allpass<NV>, 
                                      1, 
                                      ResFeed_0Range>;

template <int NV>
using ResFeed = parameter::chain<ranges::Identity, 
                                 ResFeed_0<NV>, 
                                 parameter::plain<routing::receive<stereo_cable>, 0>, 
                                 parameter::plain<routing::receive<stereo_cable>, 0>>;

template <int NV>
using FmodeA = parameter::chain<ranges::Identity, 
                                parameter::plain<project::FilterForRes<NV>, 2>, 
                                parameter::plain<project::FilterForRes<NV>, 2>>;

template <int NV> using FmodeB = FmodeA<NV>;

template <int NV>
using InFilterParToSer = parameter::plain<ResStage2_impl::branch2_t<NV>, 
                                          0>;
template <int NV>
using CompThresh = parameter::plain<ResStage2_impl::comp_t<NV>, 
                                    0>;
template <int NV>
using CompAtk = parameter::plain<ResStage2_impl::comp_t<NV>, 
                                 1>;
template <int NV>
using CompRel = parameter::plain<ResStage2_impl::comp_t<NV>, 
                                 2>;
template <int NV>
using CompRatio = parameter::plain<ResStage2_impl::comp_t<NV>, 
                                   3>;
template <int NV>
using InputHP = parameter::plain<filters::one_pole<NV>, 0>;
template <int NV>
using Rate = parameter::plain<ResStage2_impl::minmax_t<NV>, 
                              0>;
template <int NV>
using RateWin = parameter::plain<ResStage2_impl::tempo_sync1_t<NV>, 
                                 0>;
template <int NV>
using RateWinDiv = parameter::plain<ResStage2_impl::tempo_sync1_t<NV>, 
                                    1>;
template <int NV>
using ResFreq = parameter::plain<ResStage2_impl::minmax2_t<NV>, 
                                 0>;
template <int NV>
using ResMin = parameter::plain<ResStage2_impl::converter9_t<NV>, 
                                0>;
template <int NV>
using ResMax = parameter::plain<ResStage2_impl::converter24_t<NV>, 
                                0>;
template <int NV>
using ResStep = parameter::plain<ResStage2_impl::minmax2_t<NV>, 
                                 4>;
template <int NV>
using PostCut = parameter::plain<project::FilterForRes<NV>, 
                                 0>;
template <int NV>
using PostRes = parameter::plain<project::FilterForRes<NV>, 
                                 1>;
template <int NV>
using PostMode = parameter::plain<project::FilterForRes<NV>, 
                                  2>;
using Fb = parameter::plain<routing::receive<stereo_cable>, 
                            0>;
template <int NV>
using SamplePhase = parameter::plain<core::phasor<NV>, 3>;
template <int NV>
using SampleRatio = parameter::plain<core::phasor<NV>, 2>;
template <int NV>
using SampleSync = parameter::plain<ResStage2_impl::tempo_sync_t<NV>, 
                                    2>;
template <int NV>
using SampleTempo = parameter::plain<ResStage2_impl::tempo_sync_t<NV>, 
                                     0>;
template <int NV>
using SampleDiv = parameter::plain<ResStage2_impl::tempo_sync_t<NV>, 
                                   1>;
template <int NV>
using Atk = parameter::plain<ResStage2_impl::simple_ar_t<NV>, 
                             0>;
template <int NV>
using Rel = parameter::plain<ResStage2_impl::simple_ar_t<NV>, 
                             1>;
template <int NV>
using ResStage2_t_plist = parameter::list<InFilterParToSer<NV>, 
                                          CutOffA<NV>, 
                                          CutOffB<NV>, 
                                          qA<NV>, 
                                          qB<NV>, 
                                          CompThresh<NV>, 
                                          CompAtk<NV>, 
                                          CompRel<NV>, 
                                          CompRatio<NV>, 
                                          InputTrig<NV>, 
                                          InputHP<NV>, 
                                          Rate<NV>, 
                                          RateWin<NV>, 
                                          RateWinDiv<NV>, 
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
                                          FmodeA<NV>, 
                                          FmodeB<NV>, 
                                          Fb, 
                                          SamplePhase<NV>, 
                                          SampleRatio<NV>, 
                                          SampleSync<NV>, 
                                          SampleTempo<NV>, 
                                          SampleDiv<NV>, 
                                          Atk<NV>, 
                                          Rel<NV>>;
}

template <int NV>
using ResStage2_t_ = container::chain<ResStage2_t_parameters::ResStage2_t_plist<NV>, 
                                      wrap::fix<2, branch2_t<NV>>, 
                                      split5_t<NV>, 
                                      chain6_t<NV>, 
                                      modchain_t<NV>, 
                                      branch_t<NV>, 
                                      project::FilterForRes<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public ResStage2_impl::ResStage2_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 1;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 1;
		
		SNEX_METADATA_ID(ResStage2);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(564)
		{
			0x005B, 0x0000, 0x4900, 0x466E, 0x6C69, 0x6574, 0x5072, 0x7261, 
            0x6F54, 0x6553, 0x0072, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x015B, 0x0000, 0x4300, 
            0x7475, 0x664F, 0x4166, 0x0000, 0x0000, 0x0000, 0x8000, 0x1F3F, 
            0x19E3, 0xB53E, 0x74D7, 0x003E, 0x0000, 0x5B00, 0x0002, 0x0000, 
            0x7543, 0x4F74, 0x6666, 0x0042, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0xEC18, 0x3E06, 0xD7B5, 0x3E74, 0x0000, 0x0000, 0x035B, 0x0000, 
            0x7100, 0x0041, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x045B, 0x0000, 0x7100, 0x0042, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x055B, 0x0000, 0x4300, 0x6D6F, 0x5470, 0x7268, 
            0x7365, 0x0068, 0x0000, 0xC2C8, 0x0000, 0x0000, 0x3333, 0xC1A7, 
            0x833E, 0x40AD, 0xCCCD, 0x3DCC, 0x065B, 0x0000, 0x4300, 0x6D6F, 
            0x4170, 0x6B74, 0x0000, 0x0000, 0x0000, 0x7A00, 0x0043, 0x0000, 
            0xA300, 0xDC81, 0xCD3E, 0xCCCC, 0x5B3D, 0x0007, 0x0000, 0x6F43, 
            0x706D, 0x6552, 0x006C, 0x0000, 0x0000, 0x0000, 0x437A, 0x3333, 
            0x428A, 0x81A3, 0x3EDC, 0xCCCD, 0x3DCC, 0x085B, 0x0000, 0x4300, 
            0x6D6F, 0x5270, 0x7461, 0x6F69, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x0042, 0x2000, 0x9D41, 0x97F6, 0xCD3E, 0xCCCC, 0x5B3D, 0x0009, 
            0x0000, 0x6E49, 0x7570, 0x5474, 0x6972, 0x0067, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0A5B, 0x0000, 0x4900, 0x706E, 0x7475, 0x5048, 0x0000, 0xA000, 
            0x0041, 0x9C40, 0x0046, 0xA000, 0x1A41, 0x6B6C, 0x003E, 0x0000, 
            0x5B00, 0x000B, 0x0000, 0x6152, 0x6574, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x000C, 0x0000, 0x6152, 0x6574, 0x6957, 0x006E, 0x0000, 0x0000, 
            0x0000, 0x4190, 0x0000, 0x4130, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0D5B, 0x0000, 0x5200, 0x7461, 0x5765, 0x6E69, 0x6944, 0x0076, 
            0x0000, 0x3F80, 0x0000, 0x4200, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0E5B, 0x0000, 0x5200, 0x7365, 0x7246, 0x7165, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x9C3F, 0xB0DE, 0x003D, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x000F, 0x0000, 0x6552, 0x4D73, 0x6E69, 
            0x0000, 0x4000, 0x0026, 0x0000, 0x0043, 0x4000, 0x0026, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0010, 0x0000, 0x6552, 0x4D73, 0x7861, 
            0x0000, 0x0000, 0x0000, 0x0000, 0xC843, 0x81C2, 0x0042, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0011, 0x0000, 0x6552, 0x5373, 0x6574, 
            0x0070, 0x0000, 0x2640, 0x0000, 0x4400, 0x0000, 0x2640, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x125B, 0x0000, 0x5200, 0x7365, 0x6F4D, 
            0x6564, 0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x5B3F, 0x0013, 0x0000, 0x6552, 0x4C73, 
            0x0050, 0x0000, 0x41A0, 0x4000, 0x469C, 0x8A86, 0x4579, 0x6C1A, 
            0x3E6B, 0x0000, 0x0000, 0x145B, 0x0000, 0x5200, 0x7365, 0x6546, 
            0x6465, 0x0000, 0x0000, 0x0000, 0x8000, 0x9E3F, 0x7DEF, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0015, 0x0000, 0x6F50, 0x7473, 
            0x7543, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 0x6969, 0x3F5C, 
            0xD7B5, 0x3E74, 0x0000, 0x0000, 0x165B, 0x0000, 0x5000, 0x736F, 
            0x5274, 0x7365, 0x0000, 0x0000, 0x0000, 0x8000, 0xE53F, 0x38D0, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0017, 0x0000, 0x6F50, 
            0x7473, 0x6F4D, 0x6564, 0x0000, 0x8000, 0x003F, 0x5000, 0x0041, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0018, 0x0000, 
            0x6D46, 0x646F, 0x4165, 0x0000, 0x8000, 0x003F, 0x5000, 0x0041, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0019, 0x0000, 
            0x6D46, 0x646F, 0x4265, 0x0000, 0x8000, 0x003F, 0x5000, 0x0041, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x001A, 0x0000, 
            0x6246, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x001B, 0x0000, 0x6153, 0x706D, 
            0x656C, 0x6850, 0x7361, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x1C5B, 0x0000, 
            0x5300, 0x6D61, 0x6C70, 0x5265, 0x7461, 0x6F69, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x0041, 0xA000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x001D, 0x0000, 0x6153, 0x706D, 0x656C, 0x7953, 0x636E, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x001E, 0x0000, 0x6153, 0x706D, 0x656C, 
            0x6554, 0x706D, 0x006F, 0x0000, 0x0000, 0x0000, 0x4190, 0x0000, 
            0x4040, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x1F5B, 0x0000, 0x5300, 
            0x6D61, 0x6C70, 0x4465, 0x7669, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x0041, 0x4000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0020, 
            0x0000, 0x7441, 0x006B, 0x0000, 0x0000, 0x0000, 0x447A, 0x0000, 
            0x0000, 0x209B, 0x3E9A, 0xCCCD, 0x3DCC, 0x215B, 0x0000, 0x5200, 
            0x6C65, 0x0000, 0x0000, 0x0000, 0x7A00, 0x6744, 0x9D66, 0x9B42, 
            0x9A20, 0xCD3E, 0xCCCC, 0x003D
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& branch2 = this->getT(0);                                       // ResStage2_impl::branch2_t<NV>
		auto& chain431 = this->getT(0).getT(0);                              // ResStage2_impl::chain431_t<NV>
		auto& FilterForRes1 = this->getT(0).getT(0).getT(0);                 // project::FilterForRes<NV>
		auto& FilterForRes2 = this->getT(0).getT(0).getT(1);                 // project::FilterForRes<NV>
		auto& split = this->getT(0).getT(1);                                 // ResStage2_impl::split_t<NV>
		auto& FilterForRes3 = this->getT(0).getT(1).getT(0);                 // project::FilterForRes<NV>
		auto& FilterForRes4 = this->getT(0).getT(1).getT(1);                 // project::FilterForRes<NV>
		auto& split5 = this->getT(1);                                        // ResStage2_impl::split5_t<NV>
		auto& chain11 = this->getT(1).getT(0);                               // ResStage2_impl::chain11_t
		auto& chain12 = this->getT(1).getT(1);                               // ResStage2_impl::chain12_t<NV>
		auto& comp = this->getT(1).getT(1).getT(0);                          // ResStage2_impl::comp_t<NV>
		auto& clear1 = this->getT(1).getT(1).getT(1);                        // math::clear<NV>
		auto& chain6 = this->getT(2);                                        // ResStage2_impl::chain6_t<NV>
		auto& gain74 = this->getT(2).getT(0);                                // core::gain<NV>
		auto& add = this->getT(2).getT(1);                                   // math::add<NV>
		auto& tanh1 = this->getT(2).getT(2);                                 // wrap::no_process<math::tanh<NV>>
		auto& gain5 = this->getT(2).getT(3);                                 // wrap::no_process<core::gain<NV>>
		auto& one_pole30 = this->getT(2).getT(4);                            // filters::one_pole<NV>
		auto& minmax = this->getT(2).getT(5);                                // ResStage2_impl::minmax_t<NV>
		auto& receive58 = this->getT(2).getT(6);                             // routing::receive<stereo_cable>
		auto& tempo_sync1 = this->getT(2).getT(7);                           // ResStage2_impl::tempo_sync1_t<NV>
		auto& faust = this->getT(2).getT(8);                                 // project::PitchShifter<NV>
		auto& send = this->getT(2).getT(9);                                  // routing::send<stereo_cable>
		auto& modchain = this->getT(3);                                      // ResStage2_impl::modchain_t<NV>
		auto& split2 = this->getT(3).getT(0);                                // ResStage2_impl::split2_t<NV>
		auto& chain2 = this->getT(3).getT(0).getT(0);                        // ResStage2_impl::chain2_t<NV>
		auto& converter9 = this->getT(3).getT(0).getT(0).getT(0);            // ResStage2_impl::converter9_t<NV>
		auto& converter1 = this->getT(3).getT(0).getT(0).getT(1);            // ResStage2_impl::converter1_t<NV>
		auto& chain3 = this->getT(3).getT(0).getT(1);                        // ResStage2_impl::chain3_t<NV>
		auto& converter24 = this->getT(3).getT(0).getT(1).getT(0);           // ResStage2_impl::converter24_t<NV>
		auto& converter25 = this->getT(3).getT(0).getT(1).getT(1);           // ResStage2_impl::converter25_t<NV>
		auto& minmax2 = this->getT(3).getT(1);                               // ResStage2_impl::minmax2_t<NV>
		auto& converter = this->getT(3).getT(2);                             // ResStage2_impl::converter_t<NV>
		auto& branch = this->getT(4);                                        // ResStage2_impl::branch_t<NV>
		auto& chain4 = this->getT(4).getT(0);                                // ResStage2_impl::chain4_t<NV>
		auto& allpass = this->getT(4).getT(0).getT(0);                       // filters::allpass<NV>
		auto& one_pole3 = this->getT(4).getT(0).getT(1);                     // filters::one_pole<NV>
		auto& dynamic_blocksize1 = this->getT(4).getT(1);                    // ResStage2_impl::dynamic_blocksize1_t<NV>
		auto& receive = this->getT(4).getT(1).getT(0);                       // routing::receive<stereo_cable>
		auto& fix_delay = this->getT(4).getT(1).getT(1);                     // core::fix_delay
		auto& one_pole145 = this->getT(4).getT(1).getT(2);                   // filters::one_pole<NV>
		auto& send1 = this->getT(4).getT(1).getT(3);                         // routing::send<stereo_cable>
		auto& one_pole147 = this->getT(4).getT(1).getT(4);                   // filters::one_pole<NV>
		auto& dynamic_blocksize72 = this->getT(4).getT(2);                   // ResStage2_impl::dynamic_blocksize72_t<NV>
		auto& receive2 = this->getT(4).getT(2).getT(0);                      // routing::receive<stereo_cable>
		auto& jdelay_thiran = this->getT(4).getT(2).getT(1);                 // jdsp::jdelay_thiran<NV>
		auto& phase_delay22 = this->getT(4).getT(2).getT(2);                 // fx::phase_delay<NV>
		auto& one_pole1 = this->getT(4).getT(2).getT(3);                     // filters::one_pole<NV>
		auto& send2 = this->getT(4).getT(2).getT(4);                         // routing::send<stereo_cable>
		auto& one_pole = this->getT(4).getT(2).getT(5);                      // filters::one_pole<NV>
		auto& dynamic_blocksize = this->getT(4).getT(3);                     // ResStage2_impl::dynamic_blocksize_t<NV>
		auto& chain = this->getT(4).getT(3).getT(0);                         // ResStage2_impl::chain_t<NV>
		auto& split1 = this->getT(4).getT(3).getT(0).getT(0);                // ResStage2_impl::split1_t<NV>
		auto& chain1 = this->getT(4).getT(3).getT(0).getT(0).getT(0);        // ResStage2_impl::chain1_t
		auto& chain5 = this->getT(4).getT(3).getT(0).getT(0).getT(1);        // ResStage2_impl::chain5_t<NV>
		auto& add1 = this->getT(4).getT(3).getT(0).getT(0).getT(1).getT(0);  // math::add<NV>
		auto& pi = this->getT(4).getT(3).getT(0).getT(0).getT(1).getT(1);    // math::pi<NV>
		auto& rect = this->getT(4).getT(3).getT(0).getT(0).getT(1).getT(2);  // math::rect<NV>
		auto& peak = this->getT(4).getT(3).getT(0).getT(0).getT(1).getT(3);  // ResStage2_impl::peak_t<NV>
		auto& clear = this->getT(4).getT(3).getT(0).getT(0).getT(1).getT(4); // math::clear<NV>
		auto& converter3 = this->getT(4).getT(3).getT(0).getT(1);            // ResStage2_impl::converter3_t<NV>
		auto& tempo_sync = this->getT(4).getT(3).getT(0).getT(2);            // ResStage2_impl::tempo_sync_t<NV>
		auto& converter2 = this->getT(4).getT(3).getT(0).getT(3);            // ResStage2_impl::converter2_t<NV>
		auto& phasor = this->getT(4).getT(3).getT(0).getT(4);                // core::phasor<NV>
		auto& file_player = this->getT(4).getT(3).getT(0).getT(5);           // ResStage2_impl::file_player_t<NV>
		auto& one_pole2 = this->getT(4).getT(3).getT(0).getT(6);             // filters::one_pole<NV>
		auto& simple_ar = this->getT(4).getT(3).getT(0).getT(7);             // ResStage2_impl::simple_ar_t<NV>
		auto& FilterForRes = this->getT(5);                                  // project::FilterForRes<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, branch2); // InFilterParToSer -> branch2::Index
		
		auto& CutOffA_p = this->getParameterT(1);
		CutOffA_p.connectT(0, FilterForRes1); // CutOffA -> FilterForRes1::Cut
		CutOffA_p.connectT(1, FilterForRes3); // CutOffA -> FilterForRes3::Cut
		
		auto& CutOffB_p = this->getParameterT(2);
		CutOffB_p.connectT(0, FilterForRes2); // CutOffB -> FilterForRes2::Cut
		CutOffB_p.connectT(1, FilterForRes4); // CutOffB -> FilterForRes4::Cut
		
		auto& qA_p = this->getParameterT(3);
		qA_p.connectT(0, FilterForRes1); // qA -> FilterForRes1::Res
		qA_p.connectT(1, FilterForRes3); // qA -> FilterForRes3::Res
		
		auto& qB_p = this->getParameterT(4);
		qB_p.connectT(0, FilterForRes2); // qB -> FilterForRes2::Res
		qB_p.connectT(1, FilterForRes4); // qB -> FilterForRes4::Res
		
		this->getParameterT(5).connectT(0, comp); // CompThresh -> comp::Threshhold
		
		this->getParameterT(6).connectT(0, comp); // CompAtk -> comp::Attack
		
		this->getParameterT(7).connectT(0, comp); // CompRel -> comp::Release
		
		this->getParameterT(8).connectT(0, comp); // CompRatio -> comp::Ratio
		
		this->getParameterT(9).connectT(0, gain74); // InputTrig -> gain74::Gain
		
		this->getParameterT(10).connectT(0, one_pole30); // InputHP -> one_pole30::Frequency
		
		this->getParameterT(11).connectT(0, minmax); // Rate -> minmax::Value
		
		this->getParameterT(12).connectT(0, tempo_sync1); // RateWin -> tempo_sync1::Tempo
		
		this->getParameterT(13).connectT(0, tempo_sync1); // RateWinDiv -> tempo_sync1::Multiplier
		
		this->getParameterT(14).connectT(0, minmax2); // ResFreq -> minmax2::Value
		
		this->getParameterT(15).connectT(0, converter9); // ResMin -> converter9::Value
		
		this->getParameterT(16).connectT(0, converter24); // ResMax -> converter24::Value
		
		this->getParameterT(17).connectT(0, minmax2); // ResStep -> minmax2::Step
		
		this->getParameterT(18).connectT(0, branch); // ResMode -> branch::Index
		
		auto& ResLP_p = this->getParameterT(19);
		ResLP_p.connectT(0, one_pole3);   // ResLP -> one_pole3::Frequency
		ResLP_p.connectT(1, one_pole145); // ResLP -> one_pole145::Frequency
		ResLP_p.connectT(2, one_pole1);   // ResLP -> one_pole1::Frequency
		ResLP_p.connectT(3, one_pole2);   // ResLP -> one_pole2::Frequency
		
		auto& ResFeed_p = this->getParameterT(20);
		ResFeed_p.connectT(0, allpass);  // ResFeed -> allpass::Q
		ResFeed_p.connectT(1, receive);  // ResFeed -> receive::Feedback
		ResFeed_p.connectT(2, receive2); // ResFeed -> receive2::Feedback
		
		this->getParameterT(21).connectT(0, FilterForRes); // PostCut -> FilterForRes::Cut
		
		this->getParameterT(22).connectT(0, FilterForRes); // PostRes -> FilterForRes::Res
		
		this->getParameterT(23).connectT(0, FilterForRes); // PostMode -> FilterForRes::Mode
		
		auto& FmodeA_p = this->getParameterT(24);
		FmodeA_p.connectT(0, FilterForRes1); // FmodeA -> FilterForRes1::Mode
		FmodeA_p.connectT(1, FilterForRes3); // FmodeA -> FilterForRes3::Mode
		
		auto& FmodeB_p = this->getParameterT(25);
		FmodeB_p.connectT(0, FilterForRes2); // FmodeB -> FilterForRes2::Mode
		FmodeB_p.connectT(1, FilterForRes4); // FmodeB -> FilterForRes4::Mode
		
		this->getParameterT(26).connectT(0, receive58); // Fb -> receive58::Feedback
		
		this->getParameterT(27).connectT(0, phasor); // SamplePhase -> phasor::Phase
		
		this->getParameterT(28).connectT(0, phasor); // SampleRatio -> phasor::FreqRatio
		
		this->getParameterT(29).connectT(0, tempo_sync); // SampleSync -> tempo_sync::Enabled
		
		this->getParameterT(30).connectT(0, tempo_sync); // SampleTempo -> tempo_sync::Tempo
		
		this->getParameterT(31).connectT(0, tempo_sync); // SampleDiv -> tempo_sync::Multiplier
		
		this->getParameterT(32).connectT(0, simple_ar); // Atk -> simple_ar::Attack
		
		this->getParameterT(33).connectT(0, simple_ar); // Rel -> simple_ar::Release
		
		// Modulation Connections ------------------------------------------------------------------
		
		comp.getParameter().connectT(0, add);                                   // comp -> add::Value
		comp.getParameter().connectT(1, add1);                                  // comp -> add1::Value
		minmax.getWrappedObject().getParameter().connectT(0, faust);            // minmax -> faust::shiftsemitones
		tempo_sync1.getParameter().connectT(0, faust);                          // tempo_sync1 -> faust::windowsamples
		tempo_sync1.getParameter().connectT(1, faust);                          // tempo_sync1 -> faust::xfadesamples
		converter.getWrappedObject().getParameter().connectT(0, fix_delay);     // converter -> fix_delay::DelayTime
		converter.getWrappedObject().getParameter().connectT(1, jdelay_thiran); // converter -> jdelay_thiran::Limit
		converter.getWrappedObject().getParameter().connectT(2, phase_delay22); // converter -> phase_delay22::Frequency
		converter.getWrappedObject().getParameter().connectT(3, jdelay_thiran); // converter -> jdelay_thiran::DelayTime
		minmax2.getWrappedObject().getParameter().connectT(0, converter);       // minmax2 -> converter::Value
		minmax2.getWrappedObject().getParameter().connectT(1, allpass);         // minmax2 -> allpass::Frequency
		converter1.getWrappedObject().getParameter().connectT(0, minmax2);      // converter1 -> minmax2::Minimum
		converter9.getWrappedObject().getParameter().connectT(0, converter1);   // converter9 -> converter1::Value
		converter25.getWrappedObject().getParameter().connectT(0, minmax2);     // converter25 -> minmax2::Maximum
		converter24.getWrappedObject().getParameter().connectT(0, converter25); // converter24 -> converter25::Value
		auto& simple_ar_p = simple_ar.getWrappedObject().getParameter();
		peak.getParameter().connectT(0, phasor);                              // peak -> phasor::Gate
		peak.getParameter().connectT(1, simple_ar);                           // peak -> simple_ar::Gate
		converter2.getWrappedObject().getParameter().connectT(0, phasor);     // converter2 -> phasor::Frequency
		tempo_sync.getParameter().connectT(0, converter2);                    // tempo_sync -> converter2::Value
		converter3.getWrappedObject().getParameter().connectT(0, tempo_sync); // converter3 -> tempo_sync::UnsyncedTime
		
		// Send Connections ------------------------------------------------------------------------
		
		send.connect(receive58);
		send1.connect(receive);
		send2.connect(receive2);
		
		// Default Values --------------------------------------------------------------------------
		
		; // branch2::Index is automated
		
		; // FilterForRes1::Cut is automated
		; // FilterForRes1::Res is automated
		; // FilterForRes1::Mode is automated
		
		; // FilterForRes2::Cut is automated
		; // FilterForRes2::Res is automated
		; // FilterForRes2::Mode is automated
		
		; // FilterForRes3::Cut is automated
		; // FilterForRes3::Res is automated
		; // FilterForRes3::Mode is automated
		
		; // FilterForRes4::Cut is automated
		; // FilterForRes4::Res is automated
		; // FilterForRes4::Mode is automated
		
		;                          // comp::Threshhold is automated
		;                          // comp::Attack is automated
		;                          // comp::Release is automated
		;                          // comp::Ratio is automated
		comp.setParameterT(4, 0.); // dynamics::comp::Sidechain
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		;                             // gain74::Gain is automated
		gain74.setParameterT(1, 0.9); // core::gain::Smoothing
		gain74.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add::Value is automated
		
		tanh1.setParameterT(0, 0.378558); // math::tanh::Value
		
		gain5.setParameterT(0, -6.4);  // core::gain::Gain
		gain5.setParameterT(1, 0.);    // core::gain::Smoothing
		gain5.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                  // one_pole30::Frequency is automated
		one_pole30.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole30.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole30.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole30.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole30.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                              // minmax::Value is automated
		minmax.setParameterT(1, -24.); // control::minmax::Minimum
		minmax.setParameterT(2, 24.);  // control::minmax::Maximum
		minmax.setParameterT(3, 1.);   // control::minmax::Skew
		minmax.setParameterT(4, 0.);   // control::minmax::Step
		minmax.setParameterT(5, 0.);   // control::minmax::Polarity
		
		; // receive58::Feedback is automated
		
		;                                     // tempo_sync1::Tempo is automated
		;                                     // tempo_sync1::Multiplier is automated
		tempo_sync1.setParameterT(2, 1.);     // control::tempo_sync::Enabled
		tempo_sync1.setParameterT(3, 9724.1); // control::tempo_sync::UnsyncedTime
		
		; // faust::shiftsemitones is automated
		; // faust::windowsamples is automated
		; // faust::xfadesamples is automated
		
		; // converter9::Value is automated
		
		; // converter1::Value is automated
		
		; // converter24::Value is automated
		
		; // converter25::Value is automated
		
		;                                   // minmax2::Value is automated
		;                                   // minmax2::Minimum is automated
		;                                   // minmax2::Maximum is automated
		minmax2.setParameterT(3, 0.978746); // control::minmax::Skew
		;                                   // minmax2::Step is automated
		minmax2.setParameterT(5, 0.);       // control::minmax::Polarity
		
		; // converter::Value is automated
		
		; // branch::Index is automated
		
		;                               // allpass::Frequency is automated
		;                               // allpass::Q is automated
		allpass.setParameterT(2, 0.);   // filters::allpass::Gain
		allpass.setParameterT(3, 0.01); // filters::allpass::Smoothing
		allpass.setParameterT(4, 0.);   // filters::allpass::Mode
		allpass.setParameterT(5, 1.);   // filters::allpass::Enabled
		
		;                                 // one_pole3::Frequency is automated
		one_pole3.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole3.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole3.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole3.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole3.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		dynamic_blocksize1.setParameterT(0, 1.); // container::chain::BlockSize
		
		; // receive::Feedback is automated
		
		;                                  // fix_delay::DelayTime is automated
		fix_delay.setParameterT(1, 1024.); // core::fix_delay::FadeTime
		
		;                                   // one_pole145::Frequency is automated
		one_pole145.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole145.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole145.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole145.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole145.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		one_pole147.setParameterT(0, 20.);  // filters::one_pole::Frequency
		one_pole147.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole147.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole147.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole147.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole147.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		dynamic_blocksize72.setParameterT(0, 1.); // container::chain::BlockSize
		
		; // receive2::Feedback is automated
		
		; // jdelay_thiran::Limit is automated
		; // jdelay_thiran::DelayTime is automated
		
		; // phase_delay22::Frequency is automated
		
		;                                 // one_pole1::Frequency is automated
		one_pole1.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole1.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole1.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole1.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole1.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		one_pole.setParameterT(0, 20.);  // filters::one_pole::Frequency
		one_pole.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		dynamic_blocksize.setParameterT(0, 0.); // container::chain::BlockSize
		
		; // add1::Value is automated
		
		pi.setParameterT(0, 0.179274); // math::pi::Value
		
		rect.setParameterT(0, 1.); // math::rect::Value
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		converter3.setParameterT(0, 21.8); // control::converter::Value
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		; // converter2::Value is automated
		
		; // phasor::Gate is automated
		; // phasor::Frequency is automated
		; // phasor::FreqRatio is automated
		; // phasor::Phase is automated
		
		file_player.setParameterT(0, 1.);      // core::file_player::PlaybackMode
		file_player.setParameterT(1, 1.);      // core::file_player::Gate
		file_player.setParameterT(2, 411.712); // core::file_player::RootFrequency
		file_player.setParameterT(3, 1.);      // core::file_player::FreqRatio
		
		;                                 // one_pole2::Frequency is automated
		one_pole2.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole2.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole2.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole2.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole2.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                     // simple_ar::Attack is automated
		;                                     // simple_ar::Release is automated
		;                                     // simple_ar::Gate is automated
		simple_ar.setParameterT(3, 0.260657); // envelope::simple_ar::AttackCurve
		
		; // FilterForRes::Cut is automated
		; // FilterForRes::Res is automated
		; // FilterForRes::Mode is automated
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 0.15028);
		this->setParameterT(2, 0.13176);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 0.);
		this->setParameterT(5, -20.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 69.1);
		this->setParameterT(8, 10.);
		this->setParameterT(9, 0.);
		this->setParameterT(10, 20.);
		this->setParameterT(11, 0.);
		this->setParameterT(12, 11.);
		this->setParameterT(13, 1.);
		this->setParameterT(14, 0.0863621);
		this->setParameterT(15, 6.66134e-16);
		this->setParameterT(16, 64.8804);
		this->setParameterT(17, 6.66134e-16);
		this->setParameterT(18, 4.);
		this->setParameterT(19, 3992.66);
		this->setParameterT(20, 0.991938);
		this->setParameterT(21, 0.860983);
		this->setParameterT(22, 0.721938);
		this->setParameterT(23, 1.);
		this->setParameterT(24, 1.);
		this->setParameterT(25, 1.);
		this->setParameterT(26, 0.);
		this->setParameterT(27, 0.);
		this->setParameterT(28, 5.);
		this->setParameterT(29, 1.);
		this->setParameterT(30, 3.);
		this->setParameterT(31, 3.);
		this->setParameterT(32, 0.);
		this->setParameterT(33, 78.7);
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
		
		this->getT(1).getT(1).getT(0).setExternalData(b, index);                         // ResStage2_impl::comp_t<NV>
		this->getT(4).getT(3).getT(0).getT(0).getT(1).getT(3).setExternalData(b, index); // ResStage2_impl::peak_t<NV>
		this->getT(4).getT(3).getT(0).getT(5).setExternalData(b, index);                 // ResStage2_impl::file_player_t<NV>
		this->getT(4).getT(3).getT(0).getT(7).setExternalData(b, index);                 // ResStage2_impl::simple_ar_t<NV>
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
using ResStage2 = wrap::node<ResStage2_impl::instance<NV>>;
}


