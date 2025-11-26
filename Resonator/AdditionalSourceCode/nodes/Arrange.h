#pragma once

#include "res1.h"
#include "res1.h"
#include "res1.h"
#include "res1.h"
#include "res1.h"
#include "res1.h"
#include "res1.h"
#include "res1.h"
// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace Arrange_impl
{
// ==============================| Node & Parameter type declarations |==============================

using pack_resizer_t = wrap::data<control::pack_resizer, 
                                  data::external::sliderpack<3>>;

template <int NV>
using clone_pack_t = wrap::data<control::clone_pack<parameter::cloned<parameter::plain<project::res1<NV>, 6>>>, 
                                data::external::sliderpack<1>>;

template <int NV>
using clone_cable_t = control::clone_cable<parameter::cloned<parameter::plain<project::res1<NV>, 7>>, 
                                           duplilogic::fixed>;

template <int NV>
using clone_forward_t = control::clone_forward<parameter::cloned<parameter::plain<project::res1<NV>, 8>>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<1, clone_pack_t<NV>>, 
                                  clone_cable_t<NV>, 
                                  clone_forward_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(clone_pack1_modRange, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using clone_pack1_mod = parameter::from0To1<project::res1<NV>, 
                                            9, 
                                            clone_pack1_modRange>;

template <int NV>
using clone_pack1_t = wrap::data<control::clone_pack<parameter::cloned<clone_pack1_mod<NV>>>, 
                                 data::external::sliderpack<2>>;

DECLARE_PARAMETER_RANGE_SKEW(clone_cable7_modRange, 
                             0., 
                             250., 
                             0.430677);

template <int NV>
using clone_cable7_mod = parameter::from0To1<project::res1<NV>, 
                                             10, 
                                             clone_cable7_modRange>;

template <int NV>
using clone_cable7_t = control::clone_cable<parameter::cloned<clone_cable7_mod<NV>>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_cable3_mod = parameter::from0To1<project::res1<NV>, 
                                             11, 
                                             clone_cable7_modRange>;

template <int NV>
using clone_cable3_t = control::clone_cable<parameter::cloned<clone_cable3_mod<NV>>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_cable10_mod = parameter::from0To1<core::gain<NV>, 
                                              0, 
                                              clone_pack1_modRange>;

template <int NV>
using clone_cable10_t = control::clone_cable<parameter::cloned<clone_cable10_mod<NV>>, 
                                             duplilogic::fixed>;

template <int NV> using clone_cable9_mod = clone_cable10_mod<NV>;

template <int NV>
using clone_cable9_t = control::clone_cable<parameter::cloned<clone_cable9_mod<NV>>, 
                                            duplilogic::fixed>;
template <int NV>
using xfader1_multimod = parameter::list<parameter::plain<clone_cable10_t<NV>, 1>, 
                                         parameter::plain<clone_cable9_t<NV>, 1>>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::linear>;

template <int NV>
using clone_forward2_t = control::clone_forward<parameter::cloned<parameter::plain<project::res1<NV>, 12>>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<1, clone_pack1_t<NV>>, 
                                  clone_cable7_t<NV>, 
                                  clone_cable3_t<NV>, 
                                  xfader1_t<NV>, 
                                  clone_cable10_t<NV>, 
                                  clone_cable9_t<NV>, 
                                  clone_forward2_t<NV>>;

template <int NV>
using clone_cable2_t = control::clone_cable<parameter::cloned<parameter::plain<project::res1<NV>, 13>>, 
                                            duplilogic::fixed>;

DECLARE_PARAMETER_RANGE_STEP(clone_cable8_modRange, 
                             4, 
                             200., 
                             0.001);

template <int NV>
using clone_cable8_mod = parameter::from0To1<project::gran<NV>, 
                                             4, 
                                             clone_cable8_modRange>;

template <int NV>
using clone_cable8_t = control::clone_cable<parameter::cloned<clone_cable8_mod<NV>>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_pack2_t = wrap::data<control::clone_pack<parameter::cloned<parameter::plain<project::gran<NV>, 2>>>, 
                                 data::external::sliderpack<7>>;

DECLARE_PARAMETER_RANGE_STEP(clone_pack3_modRange, 
                             0.125, 
                             4., 
                             0.001);

template <int NV>
using clone_pack3_mod = parameter::from0To1<project::gran<NV>, 
                                            3, 
                                            clone_pack3_modRange>;

template <int NV>
using clone_pack3_t = wrap::data<control::clone_pack<parameter::cloned<clone_pack3_mod<NV>>>, 
                                 data::external::sliderpack<8>>;

DECLARE_PARAMETER_RANGE_STEP(clone_pack4_modRange, 
                             1., 
                             256., 
                             1.);

template <int NV>
using clone_pack4_mod = parameter::from0To1<fx::sampleandhold<NV>, 
                                            0, 
                                            clone_pack4_modRange>;

template <int NV>
using clone_pack4_t = wrap::data<control::clone_pack<parameter::cloned<clone_pack4_mod<NV>>>, 
                                 data::external::sliderpack<9>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<1, clone_cable2_t<NV>>, 
                                  clone_cable8_t<NV>, 
                                  clone_pack2_t<NV>, 
                                  clone_pack3_t<NV>, 
                                  clone_pack4_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(clone_pack5_modRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using clone_pack5_mod = parameter::from0To1<project::res1<NV>, 
                                            1, 
                                            clone_pack5_modRange>;

template <int NV>
using clone_pack5_t = wrap::data<control::clone_pack<parameter::cloned<clone_pack5_mod<NV>>>, 
                                 data::external::sliderpack<0>>;
using pack8_writer_t = wrap::data<control::pack8_writer, 
                                  data::external::sliderpack<0>>;

template <int NV>
using clone_cable4_t = control::clone_cable<parameter::cloned<parameter::plain<project::res1<NV>, 0>>, 
                                            duplilogic::fixed>;

DECLARE_PARAMETER_RANGE_SKEW(clone_cable6_modRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using clone_cable6_mod = parameter::from0To1<project::res1<NV>, 
                                             3, 
                                             clone_cable6_modRange>;

template <int NV>
using clone_cable6_t = control::clone_cable<parameter::cloned<clone_cable6_mod<NV>>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_cable5_t = control::clone_cable<parameter::cloned<parameter::plain<project::res1<NV>, 5>>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_pack6_mod = parameter::from0To1<project::res1<NV>, 
                                            2, 
                                            clone_pack5_modRange>;

template <int NV>
using clone_pack6_t = wrap::data<control::clone_pack<parameter::cloned<clone_pack6_mod<NV>>>, 
                                 data::external::sliderpack<4>>;

template <int NV> using clone_pack7_mod = clone_cable10_mod<NV>;

template <int NV>
using clone_pack7_t = wrap::data<control::clone_pack<parameter::cloned<clone_pack7_mod<NV>>>, 
                                 data::external::sliderpack<5>>;

DECLARE_PARAMETER_RANGE(clone_pack8_modRange, 
                        -1., 
                        1.);

template <int NV>
using clone_pack8_mod = parameter::from0To1<jdsp::jpanner<NV>, 
                                            0, 
                                            clone_pack8_modRange>;

template <int NV>
using clone_pack8_t = wrap::data<control::clone_pack<parameter::cloned<clone_pack8_mod<NV>>>, 
                                 data::external::sliderpack<6>>;

template <int NV>
using clone_forward4_t = control::clone_forward<parameter::cloned<parameter::plain<project::res1<NV>, 4>>>;

template <int NV>
using clone_forward5_t = control::clone_forward<parameter::cloned<parameter::plain<project::res1<NV>, 14>>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<1, clone_pack5_t<NV>>, 
                                  pack8_writer_t, 
                                  clone_cable4_t<NV>, 
                                  clone_cable6_t<NV>, 
                                  clone_cable5_t<NV>, 
                                  clone_pack6_t<NV>, 
                                  clone_pack7_t<NV>, 
                                  clone_pack8_t<NV>, 
                                  clone_forward4_t<NV>, 
                                  clone_forward5_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, pack_resizer_t>, 
                                     split1_t<NV>, 
                                     split2_t<NV>, 
                                     split3_t<NV>, 
                                     split4_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV> using xfader_c0 = clone_cable10_mod<NV>;

template <int NV> using xfader_c1 = clone_cable10_mod<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::overlap>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>>;

template <int NV> using chain3_t = chain1_t<NV>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, project::gran<NV>>, 
                                  core::gain<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain3_t<NV>>, 
                                  chain4_t<NV>>;

template <int NV>
using clone_child_t = container::chain<parameter::empty, 
                                       wrap::fix<2, split5_t<NV>>, 
                                       fx::sampleandhold<NV>, 
                                       project::res1<NV>, 
                                       core::gain<NV>, 
                                       jdsp::jpanner<NV>>;
template <int NV>
using clone_t = wrap::fix_clonecopy<clone_child_t<NV>, 8>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, clone_t<NV>>, 
                                  filters::one_pole<NV>, 
                                  core::gain<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain1_t<NV>>, 
                                 chain2_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, xfader_t<NV>>, 
                                 split_t<NV>>;

namespace Arrange_t_parameters
{
// Parameter list for Arrange_impl::Arrange_t ------------------------------------------------------

DECLARE_PARAMETER_RANGE_SKEW(FREQ1_InputRange, 
                             20., 
                             20000., 
                             0.229905);

using FREQ1 = parameter::chain<FREQ1_InputRange, 
                               parameter::plain<Arrange_impl::pack8_writer_t, 0>>;

DECLARE_PARAMETER_RANGE_SKEW(FREQ2_InputRange, 
                             20., 
                             20000., 
                             0.229905);

using FREQ2 = parameter::chain<FREQ2_InputRange, 
                               parameter::plain<Arrange_impl::pack8_writer_t, 1>>;

DECLARE_PARAMETER_RANGE_SKEW(FREQ3_InputRange, 
                             20., 
                             20000., 
                             0.229905);

using FREQ3 = parameter::chain<FREQ3_InputRange, 
                               parameter::plain<Arrange_impl::pack8_writer_t, 2>>;

DECLARE_PARAMETER_RANGE_SKEW(FREQ4_InputRange, 
                             20., 
                             20000., 
                             0.229905);

using FREQ4 = parameter::chain<FREQ4_InputRange, 
                               parameter::plain<Arrange_impl::pack8_writer_t, 3>>;

DECLARE_PARAMETER_RANGE_SKEW(FREQ5_InputRange, 
                             20., 
                             20000., 
                             0.229905);

using FREQ5 = parameter::chain<FREQ5_InputRange, 
                               parameter::plain<Arrange_impl::pack8_writer_t, 4>>;

DECLARE_PARAMETER_RANGE_SKEW(FREQ6_InputRange, 
                             20., 
                             20000., 
                             0.229905);

using FREQ6 = parameter::chain<FREQ6_InputRange, 
                               parameter::plain<Arrange_impl::pack8_writer_t, 5>>;

DECLARE_PARAMETER_RANGE_SKEW(FREQ7_InputRange, 
                             20., 
                             20000., 
                             0.229905);

using FREQ7 = parameter::chain<FREQ7_InputRange, 
                               parameter::plain<Arrange_impl::pack8_writer_t, 6>>;

DECLARE_PARAMETER_RANGE_SKEW(FREQ8_InputRange, 
                             20., 
                             20000., 
                             0.229905);

using FREQ8 = parameter::chain<FREQ8_InputRange, 
                               parameter::plain<Arrange_impl::pack8_writer_t, 7>>;

template <int NV>
using FilterQ = parameter::plain<Arrange_impl::clone_cable_t<NV>, 
                                 1>;
template <int NV>
using FilterMode = parameter::plain<Arrange_impl::clone_forward_t<NV>, 
                                    1>;
template <int NV>
using FilterGain = parameter::plain<Arrange_impl::clone_pack2_t<NV>, 
                                    1>;
template <int NV>
using CompRatio = parameter::plain<Arrange_impl::clone_forward2_t<NV>, 
                                   1>;
template <int NV>
using Trig = parameter::plain<Arrange_impl::clone_cable2_t<NV>, 
                              1>;
using SH = parameter::empty;
template <int NV>
using Feed = parameter::plain<Arrange_impl::clone_cable4_t<NV>, 
                              1>;
template <int NV>
using Phase = parameter::plain<Arrange_impl::clone_cable6_t<NV>, 
                               1>;
template <int NV>
using Snap = parameter::plain<Arrange_impl::clone_cable5_t<NV>, 
                              1>;
template <int NV>
using ResoMode = parameter::plain<Arrange_impl::clone_forward4_t<NV>, 
                                  1>;
template <int NV>
using mix = parameter::plain<Arrange_impl::xfader_t<NV>, 
                             0>;
template <int NV>
using Atk = parameter::plain<Arrange_impl::clone_cable7_t<NV>, 
                             1>;
template <int NV>
using Rel = parameter::plain<Arrange_impl::clone_cable3_t<NV>, 
                             1>;
template <int NV>
using DelOffset = parameter::plain<Arrange_impl::clone_pack5_t<NV>, 
                                   1>;
template <int NV>
using BlockSize = parameter::plain<Arrange_impl::clone_forward5_t<NV>, 
                                   1>;
using GrainFb = SH;
template <int NV>
using gmix = parameter::plain<Arrange_impl::xfader1_t<NV>, 
                              0>;
template <int NV>
using Arrange_t_plist = parameter::list<FREQ1, 
                                        FREQ2, 
                                        FREQ3, 
                                        FREQ4, 
                                        FREQ5, 
                                        FREQ6, 
                                        FREQ7, 
                                        FREQ8, 
                                        FilterQ<NV>, 
                                        FilterMode<NV>, 
                                        FilterGain<NV>, 
                                        CompRatio<NV>, 
                                        Trig<NV>, 
                                        SH, 
                                        Feed<NV>, 
                                        Phase<NV>, 
                                        Snap<NV>, 
                                        ResoMode<NV>, 
                                        mix<NV>, 
                                        Atk<NV>, 
                                        Rel<NV>, 
                                        DelOffset<NV>, 
                                        BlockSize<NV>, 
                                        GrainFb, 
                                        gmix<NV>>;
}

template <int NV>
using Arrange_t_ = container::chain<Arrange_t_parameters::Arrange_t_plist<NV>, 
                                    wrap::fix<2, modchain_t<NV>>, 
                                    chain_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public Arrange_impl::Arrange_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 10;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(Arrange);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(396)
		{
			0x005B, 0x0000, 0x4600, 0x4552, 0x3151, 0x0000, 0xA000, 0x0041, 
            0x9C40, 0x0046, 0xCFA7, 0x1A43, 0x6B6C, 0x003E, 0x0000, 0x5B00, 
            0x0001, 0x0000, 0x5246, 0x5145, 0x0032, 0x0000, 0x41A0, 0x4000, 
            0x469C, 0xA700, 0x43CF, 0x6C1A, 0x3E6B, 0x0000, 0x0000, 0x025B, 
            0x0000, 0x4600, 0x4552, 0x3351, 0x0000, 0xA000, 0x0041, 0x9C40, 
            0x0046, 0xCFA7, 0x1A43, 0x6B6C, 0x003E, 0x0000, 0x5B00, 0x0003, 
            0x0000, 0x5246, 0x5145, 0x0034, 0x0000, 0x41A0, 0x4000, 0x469C, 
            0xA700, 0x43CF, 0x6C1A, 0x3E6B, 0x0000, 0x0000, 0x045B, 0x0000, 
            0x4600, 0x4552, 0x3551, 0x0000, 0xA000, 0x0041, 0x9C40, 0x0046, 
            0xCFA7, 0x1A43, 0x6B6C, 0x003E, 0x0000, 0x5B00, 0x0005, 0x0000, 
            0x5246, 0x5145, 0x0036, 0x0000, 0x41A0, 0x4000, 0x469C, 0xA700, 
            0x43CF, 0x6C1A, 0x3E6B, 0x0000, 0x0000, 0x065B, 0x0000, 0x4600, 
            0x4552, 0x3751, 0x0000, 0xA000, 0x0041, 0x9C40, 0x0046, 0xCFA7, 
            0x1A43, 0x6B6C, 0x003E, 0x0000, 0x5B00, 0x0007, 0x0000, 0x5246, 
            0x5145, 0x0038, 0x0000, 0x41A0, 0x4000, 0x469C, 0xA700, 0x43CF, 
            0x6C1A, 0x3E6B, 0x0000, 0x0000, 0x085B, 0x0000, 0x4600, 0x6C69, 
            0x6574, 0x5172, 0x0000, 0x0000, 0x0000, 0x8000, 0x3D3F, 0x570A, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0009, 0x0000, 0x6946, 
            0x746C, 0x7265, 0x6F4D, 0x6564, 0x0000, 0x8000, 0x003F, 0xA000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000A, 
            0x0000, 0x6946, 0x746C, 0x7265, 0x6147, 0x6E69, 0x0000, 0x0000, 
            0x0000, 0x8000, 0xB83F, 0x051E, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x000B, 0x0000, 0x6F43, 0x706D, 0x6152, 0x6974, 0x006F, 
            0x0000, 0x3F80, 0x0000, 0x4200, 0x6666, 0x4066, 0x0000, 0x3F80, 
            0xCCCD, 0x3DCC, 0x0C5B, 0x0000, 0x5400, 0x6972, 0x0067, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0D5B, 0x0000, 0x5300, 0x0048, 0x0000, 0x3F80, 0x0000, 
            0x4400, 0xF443, 0x4236, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0E5B, 
            0x0000, 0x4600, 0x6565, 0x0064, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0F5B, 0x0000, 
            0x5000, 0x6168, 0x6573, 0x0000, 0x0000, 0x0000, 0x8000, 0xAE3F, 
            0xE147, 0x003E, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0010, 0x0000, 
            0x6E53, 0x7061, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0011, 0x0000, 0x6552, 
            0x6F73, 0x6F4D, 0x6564, 0x0000, 0x8000, 0x003F, 0xA000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0012, 0x0000, 
            0x696D, 0x0078, 0x0000, 0x0000, 0x0000, 0x3F80, 0x8F5C, 0x3F02, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x135B, 0x0000, 0x4100, 0x6B74, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0014, 0x0000, 0x6552, 0x006C, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x47AE, 0x3E61, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x155B, 0x0000, 0x4400, 0x6C65, 0x664F, 0x7366, 0x7465, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x713F, 0x0A3D, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0016, 0x0000, 0x6C42, 0x636F, 0x536B, 
            0x7A69, 0x0065, 0x0000, 0x0000, 0x0000, 0x40E0, 0x0000, 0x4000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x175B, 0x0000, 0x4700, 0x6172, 
            0x6E69, 0x6246, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0018, 0x0000, 0x6D67, 
            0x7869, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain = this->getT(0);                                              // Arrange_impl::modchain_t<NV>
		auto& pack_resizer = this->getT(0).getT(0);                                  // Arrange_impl::pack_resizer_t
		auto& split1 = this->getT(0).getT(1);                                        // Arrange_impl::split1_t<NV>
		auto& clone_pack = this->getT(0).getT(1).getT(0);                            // Arrange_impl::clone_pack_t<NV>
		auto& clone_cable = this->getT(0).getT(1).getT(1);                           // Arrange_impl::clone_cable_t<NV>
		auto& clone_forward = this->getT(0).getT(1).getT(2);                         // Arrange_impl::clone_forward_t<NV>
		auto& split2 = this->getT(0).getT(2);                                        // Arrange_impl::split2_t<NV>
		auto& clone_pack1 = this->getT(0).getT(2).getT(0);                           // Arrange_impl::clone_pack1_t<NV>
		auto& clone_cable7 = this->getT(0).getT(2).getT(1);                          // Arrange_impl::clone_cable7_t<NV>
		auto& clone_cable3 = this->getT(0).getT(2).getT(2);                          // Arrange_impl::clone_cable3_t<NV>
		auto& xfader1 = this->getT(0).getT(2).getT(3);                               // Arrange_impl::xfader1_t<NV>
		auto& clone_cable10 = this->getT(0).getT(2).getT(4);                         // Arrange_impl::clone_cable10_t<NV>
		auto& clone_cable9 = this->getT(0).getT(2).getT(5);                          // Arrange_impl::clone_cable9_t<NV>
		auto& clone_forward2 = this->getT(0).getT(2).getT(6);                        // Arrange_impl::clone_forward2_t<NV>
		auto& split3 = this->getT(0).getT(3);                                        // Arrange_impl::split3_t<NV>
		auto& clone_cable2 = this->getT(0).getT(3).getT(0);                          // Arrange_impl::clone_cable2_t<NV>
		auto& clone_cable8 = this->getT(0).getT(3).getT(1);                          // Arrange_impl::clone_cable8_t<NV>
		auto& clone_pack2 = this->getT(0).getT(3).getT(2);                           // Arrange_impl::clone_pack2_t<NV>
		auto& clone_pack3 = this->getT(0).getT(3).getT(3);                           // Arrange_impl::clone_pack3_t<NV>
		auto& clone_pack4 = this->getT(0).getT(3).getT(4);                           // Arrange_impl::clone_pack4_t<NV>
		auto& split4 = this->getT(0).getT(4);                                        // Arrange_impl::split4_t<NV>
		auto& clone_pack5 = this->getT(0).getT(4).getT(0);                           // Arrange_impl::clone_pack5_t<NV>
		auto& pack8_writer = this->getT(0).getT(4).getT(1);                          // Arrange_impl::pack8_writer_t
		auto& clone_cable4 = this->getT(0).getT(4).getT(2);                          // Arrange_impl::clone_cable4_t<NV>
		auto& clone_cable6 = this->getT(0).getT(4).getT(3);                          // Arrange_impl::clone_cable6_t<NV>
		auto& clone_cable5 = this->getT(0).getT(4).getT(4);                          // Arrange_impl::clone_cable5_t<NV>
		auto& clone_pack6 = this->getT(0).getT(4).getT(5);                           // Arrange_impl::clone_pack6_t<NV>
		auto& clone_pack7 = this->getT(0).getT(4).getT(6);                           // Arrange_impl::clone_pack7_t<NV>
		auto& clone_pack8 = this->getT(0).getT(4).getT(7);                           // Arrange_impl::clone_pack8_t<NV>
		auto& clone_forward4 = this->getT(0).getT(4).getT(8);                        // Arrange_impl::clone_forward4_t<NV>
		auto& clone_forward5 = this->getT(0).getT(4).getT(9);                        // Arrange_impl::clone_forward5_t<NV>
		auto& chain = this->getT(1);                                                 // Arrange_impl::chain_t<NV>
		auto& xfader = this->getT(1).getT(0);                                        // Arrange_impl::xfader_t<NV>
		auto& split = this->getT(1).getT(1);                                         // Arrange_impl::split_t<NV>
		auto& chain1 = this->getT(1).getT(1).getT(0);                                // Arrange_impl::chain1_t<NV>
		auto& gain16 = this->getT(1).getT(1).getT(0).getT(0);                        // core::gain<NV>
		auto& chain2 = this->getT(1).getT(1).getT(1);                                // Arrange_impl::chain2_t<NV>
		auto& clone = this->getT(1).getT(1).getT(1).getT(0);                         // Arrange_impl::clone_t<NV>                         // Arrange_impl::clone_child_t<NV>
		auto split5 = this->getT(1).getT(1).getT(1).getT(0).getT(0);                 // Arrange_impl::split5_t<NV>
		auto chain3 = this->getT(1).getT(1).getT(1).getT(0).getT(0).getT(0);         // Arrange_impl::chain3_t<NV>
		auto gain24 = this->getT(1).getT(1).getT(1).getT(0).getT(0).getT(0).getT(0); // core::gain<NV>
		auto chain4 = this->getT(1).getT(1).getT(1).getT(0).getT(0).getT(1);         // Arrange_impl::chain4_t<NV>
		auto faust = this->getT(1).getT(1).getT(1).getT(0).getT(0).getT(1).getT(0);  // project::gran<NV>
		auto gain25 = this->getT(1).getT(1).getT(1).getT(0).getT(0).getT(1).getT(1); // core::gain<NV>
		auto sampleandhold = this->getT(1).getT(1).getT(1).getT(0).getT(1);          // fx::sampleandhold<NV>
		auto res1 = this->getT(1).getT(1).getT(1).getT(0).getT(2);                   // project::res1<NV>
		auto gain = this->getT(1).getT(1).getT(1).getT(0).getT(3);                   // core::gain<NV>
		auto jpanner = this->getT(1).getT(1).getT(1).getT(0).getT(4);                // jdsp::jpanner<NV>
		auto& one_pole = this->getT(1).getT(1).getT(1).getT(1);                      // filters::one_pole<NV>
		auto& gain17 = this->getT(1).getT(1).getT(1).getT(2);                        // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pack8_writer); // FREQ1 -> pack8_writer::Value1
		
		this->getParameterT(1).connectT(0, pack8_writer); // FREQ2 -> pack8_writer::Value2
		
		this->getParameterT(2).connectT(0, pack8_writer); // FREQ3 -> pack8_writer::Value3
		
		this->getParameterT(3).connectT(0, pack8_writer); // FREQ4 -> pack8_writer::Value4
		
		this->getParameterT(4).connectT(0, pack8_writer); // FREQ5 -> pack8_writer::Value5
		
		this->getParameterT(5).connectT(0, pack8_writer); // FREQ6 -> pack8_writer::Value6
		
		this->getParameterT(6).connectT(0, pack8_writer); // FREQ7 -> pack8_writer::Value7
		
		this->getParameterT(7).connectT(0, pack8_writer); // FREQ8 -> pack8_writer::Value8
		
		this->getParameterT(8).connectT(0, clone_cable); // FilterQ -> clone_cable::Value
		
		this->getParameterT(9).connectT(0, clone_forward); // FilterMode -> clone_forward::Value
		
		this->getParameterT(10).connectT(0, clone_pack2); // FilterGain -> clone_pack2::Value
		
		this->getParameterT(11).connectT(0, clone_forward2); // CompRatio -> clone_forward2::Value
		
		this->getParameterT(12).connectT(0, clone_cable2); // Trig -> clone_cable2::Value
		
		this->getParameterT(14).connectT(0, clone_cable4); // Feed -> clone_cable4::Value
		
		this->getParameterT(15).connectT(0, clone_cable6); // Phase -> clone_cable6::Value
		
		this->getParameterT(16).connectT(0, clone_cable5); // Snap -> clone_cable5::Value
		
		this->getParameterT(17).connectT(0, clone_forward4); // ResoMode -> clone_forward4::Value
		
		this->getParameterT(18).connectT(0, xfader); // mix -> xfader::Value
		
		this->getParameterT(19).connectT(0, clone_cable7); // Atk -> clone_cable7::Value
		
		this->getParameterT(20).connectT(0, clone_cable3); // Rel -> clone_cable3::Value
		
		this->getParameterT(21).connectT(0, clone_pack5); // DelOffset -> clone_pack5::Value
		
		this->getParameterT(22).connectT(0, clone_forward5); // BlockSize -> clone_forward5::Value
		
		this->getParameterT(24).connectT(0, xfader1); // gmix -> xfader1::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		clone_pack.getWrappedObject().getParameter().connectT(0, res1);      // clone_pack -> res1::FilterCut
		clone_cable.getWrappedObject().getParameter().connectT(0, res1);     // clone_cable -> res1::FilterQ
		clone_forward.getWrappedObject().getParameter().connectT(0, res1);   // clone_forward -> res1::FilterMode
		clone_pack1.getWrappedObject().getParameter().connectT(0, res1);     // clone_pack1 -> res1::Thresh
		clone_cable7.getWrappedObject().getParameter().connectT(0, res1);    // clone_cable7 -> res1::Atk
		clone_cable3.getWrappedObject().getParameter().connectT(0, res1);    // clone_cable3 -> res1::rel
		clone_cable10.getWrappedObject().getParameter().connectT(0, gain24); // clone_cable10 -> gain24::Gain
		clone_cable9.getWrappedObject().getParameter().connectT(0, gain25);  // clone_cable9 -> gain25::Gain
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, clone_cable10);                    // xfader1 -> clone_cable10::Value
		xfader1_p.getParameterT(1).connectT(0, clone_cable9);                     // xfader1 -> clone_cable9::Value
		clone_forward2.getWrappedObject().getParameter().connectT(0, res1);       // clone_forward2 -> res1::Ratio
		clone_cable2.getWrappedObject().getParameter().connectT(0, res1);         // clone_cable2 -> res1::Trig
		clone_cable8.getWrappedObject().getParameter().connectT(0, faust);        // clone_cable8 -> faust::taille
		clone_pack2.getWrappedObject().getParameter().connectT(0, faust);         // clone_pack2 -> faust::population
		clone_pack3.getWrappedObject().getParameter().connectT(0, faust);         // clone_pack3 -> faust::speed
		clone_pack4.getWrappedObject().getParameter().connectT(0, sampleandhold); // clone_pack4 -> sampleandhold::Counter
		clone_pack5.getWrappedObject().getParameter().connectT(0, res1);          // clone_pack5 -> res1::Del
		clone_cable4.getWrappedObject().getParameter().connectT(0, res1);         // clone_cable4 -> res1::feed
		clone_cable6.getWrappedObject().getParameter().connectT(0, res1);         // clone_cable6 -> res1::FbModifier
		clone_cable5.getWrappedObject().getParameter().connectT(0, res1);         // clone_cable5 -> res1::Comp
		clone_pack6.getWrappedObject().getParameter().connectT(0, res1);          // clone_pack6 -> res1::LP
		clone_pack7.getWrappedObject().getParameter().connectT(0, gain);          // clone_pack7 -> gain::Gain
		clone_pack8.getWrappedObject().getParameter().connectT(0, jpanner);       // clone_pack8 -> jpanner::Pan
		clone_forward4.getWrappedObject().getParameter().connectT(0, res1);       // clone_forward4 -> res1::Mode
		clone_forward5.getWrappedObject().getParameter().connectT(0, res1);       // clone_forward5 -> res1::block
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain16); // xfader -> gain16::Gain
		xfader_p.getParameterT(1).connectT(0, gain17); // xfader -> gain17::Gain
		
		// Default Values --------------------------------------------------------------------------
		
		pack_resizer.setParameterT(0, 8.); // control::pack_resizer::NumSliders
		
		clone_pack.setParameterT(0, 8.); // control::clone_pack::NumClones
		clone_pack.setParameterT(1, 1.); // control::clone_pack::Value
		
		;                                 // clone_cable::NumClones is deactivated
		;                                 // clone_cable::Value is automated
		clone_cable.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		clone_forward.setParameterT(0, 8.); // control::clone_forward::NumClones
		;                                   // clone_forward::Value is automated
		
		clone_pack1.setParameterT(0, 8.); // control::clone_pack::NumClones
		clone_pack1.setParameterT(1, 1.); // control::clone_pack::Value
		
		;                                  // clone_cable7::NumClones is deactivated
		;                                  // clone_cable7::Value is automated
		clone_cable7.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable3::NumClones is deactivated
		;                                  // clone_cable3::Value is automated
		clone_cable3.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		; // xfader1::Value is automated
		
		;                                   // clone_cable10::NumClones is deactivated
		;                                   // clone_cable10::Value is automated
		clone_cable10.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable9::NumClones is deactivated
		;                                  // clone_cable9::Value is automated
		clone_cable9.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		clone_forward2.setParameterT(0, 8.); // control::clone_forward::NumClones
		;                                    // clone_forward2::Value is automated
		
		;                                  // clone_cable2::NumClones is deactivated
		;                                  // clone_cable2::Value is automated
		clone_cable2.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable8::NumClones is deactivated
		clone_cable8.setParameterT(1, 1.); // control::clone_cable::Value
		clone_cable8.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		clone_pack2.setParameterT(0, 8.); // control::clone_pack::NumClones
		;                                 // clone_pack2::Value is automated
		
		clone_pack3.setParameterT(0, 8.); // control::clone_pack::NumClones
		clone_pack3.setParameterT(1, 1.); // control::clone_pack::Value
		
		clone_pack4.setParameterT(0, 8.); // control::clone_pack::NumClones
		clone_pack4.setParameterT(1, 1.); // control::clone_pack::Value
		
		clone_pack5.setParameterT(0, 8.); // control::clone_pack::NumClones
		;                                 // clone_pack5::Value is automated
		
		; // pack8_writer::Value1 is automated
		; // pack8_writer::Value2 is automated
		; // pack8_writer::Value3 is automated
		; // pack8_writer::Value4 is automated
		; // pack8_writer::Value5 is automated
		; // pack8_writer::Value6 is automated
		; // pack8_writer::Value7 is automated
		; // pack8_writer::Value8 is automated
		
		;                                  // clone_cable4::NumClones is deactivated
		;                                  // clone_cable4::Value is automated
		clone_cable4.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable6::NumClones is deactivated
		;                                  // clone_cable6::Value is automated
		clone_cable6.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable5::NumClones is deactivated
		;                                  // clone_cable5::Value is automated
		clone_cable5.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		clone_pack6.setParameterT(0, 8.); // control::clone_pack::NumClones
		clone_pack6.setParameterT(1, 1.); // control::clone_pack::Value
		
		clone_pack7.setParameterT(0, 8.); // control::clone_pack::NumClones
		clone_pack7.setParameterT(1, 1.); // control::clone_pack::Value
		
		clone_pack8.setParameterT(0, 8.); // control::clone_pack::NumClones
		clone_pack8.setParameterT(1, 1.); // control::clone_pack::Value
		
		clone_forward4.setParameterT(0, 8.); // control::clone_forward::NumClones
		;                                    // clone_forward4::Value is automated
		
		clone_forward5.setParameterT(0, 8.); // control::clone_forward::NumClones
		;                                    // clone_forward5::Value is automated
		
		; // xfader::Value is automated
		
		;                             // gain16::Gain is automated
		gain16.setParameterT(1, 20.); // core::gain::Smoothing
		gain16.setParameterT(2, 0.);  // core::gain::ResetValue
		
		clone.setParameterT(0, 8.); // container::clone::NumClones
		clone.setParameterT(1, 2.); // container::clone::SplitSignal
		
		;                             // gain24::Gain is automated
		gain24.setParameterT(1, 20.); // core::gain::Smoothing
		gain24.setParameterT(2, 0.);  // core::gain::ResetValue
		
		faust.setParameterT(0, 0.904); // core::faust::decal
		faust.setParameterT(1, 0.);    // core::faust::feedback
		;                              // faust::population is automated
		;                              // faust::speed is automated
		;                              // faust::taille is automated
		
		;                             // gain25::Gain is automated
		gain25.setParameterT(1, 20.); // core::gain::Smoothing
		gain25.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // sampleandhold::Counter is automated
		
		; // res1::feed is automated
		; // res1::Del is automated
		; // res1::LP is automated
		; // res1::FbModifier is automated
		; // res1::Mode is automated
		; // res1::Comp is automated
		; // res1::FilterCut is automated
		; // res1::FilterQ is automated
		; // res1::FilterMode is automated
		; // res1::Thresh is automated
		; // res1::Atk is automated
		; // res1::rel is automated
		; // res1::Ratio is automated
		; // res1::Trig is automated
		; // res1::block is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                             // jpanner::Pan is automated
		jpanner.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		one_pole.setParameterT(0, 50.);  // filters::one_pole::Frequency
		one_pole.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                             // gain17::Gain is automated
		gain17.setParameterT(1, 20.); // core::gain::Smoothing
		gain17.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 415.305);
		this->setParameterT(1, 415.305);
		this->setParameterT(2, 415.305);
		this->setParameterT(3, 415.305);
		this->setParameterT(4, 415.305);
		this->setParameterT(5, 415.305);
		this->setParameterT(6, 415.305);
		this->setParameterT(7, 415.305);
		this->setParameterT(8, 0.84);
		this->setParameterT(9, 1.);
		this->setParameterT(10, 0.52);
		this->setParameterT(11, 3.6);
		this->setParameterT(12, 1.);
		this->setParameterT(13, 45.7385);
		this->setParameterT(14, 1.);
		this->setParameterT(15, 0.44);
		this->setParameterT(16, 0.);
		this->setParameterT(17, 1.);
		this->setParameterT(18, 0.51);
		this->setParameterT(19, 0.);
		this->setParameterT(20, 0.22);
		this->setParameterT(21, 0.54);
		this->setParameterT(22, 2.);
		this->setParameterT(23, 1.);
		this->setParameterT(24, 1.);
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
		
		this->getT(0).getT(0).setExternalData(b, index);         // Arrange_impl::pack_resizer_t
		this->getT(0).getT(1).getT(0).setExternalData(b, index); // Arrange_impl::clone_pack_t<NV>
		this->getT(0).getT(2).getT(0).setExternalData(b, index); // Arrange_impl::clone_pack1_t<NV>
		this->getT(0).getT(3).getT(2).setExternalData(b, index); // Arrange_impl::clone_pack2_t<NV>
		this->getT(0).getT(3).getT(3).setExternalData(b, index); // Arrange_impl::clone_pack3_t<NV>
		this->getT(0).getT(3).getT(4).setExternalData(b, index); // Arrange_impl::clone_pack4_t<NV>
		this->getT(0).getT(4).getT(0).setExternalData(b, index); // Arrange_impl::clone_pack5_t<NV>
		this->getT(0).getT(4).getT(1).setExternalData(b, index); // Arrange_impl::pack8_writer_t
		this->getT(0).getT(4).getT(5).setExternalData(b, index); // Arrange_impl::clone_pack6_t<NV>
		this->getT(0).getT(4).getT(6).setExternalData(b, index); // Arrange_impl::clone_pack7_t<NV>
		this->getT(0).getT(4).getT(7).setExternalData(b, index); // Arrange_impl::clone_pack8_t<NV>
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
using Arrange = wrap::node<Arrange_impl::instance<NV>>;
}


