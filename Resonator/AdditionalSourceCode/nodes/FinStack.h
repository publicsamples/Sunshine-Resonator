#pragma once

#include "ResStage.h"
#include "ResStage.h"
#include "ResStage.h"
#include "ResStage.h"
#include "ResStage.h"
#include "ResStage.h"
#include "ResStage.h"
#include "ResStage.h"
// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace FinStack_impl
{
// ==============================| Node & Parameter type declarations |==============================

using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::empty>>;

template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<core::gain<NV>, 0>>;
template <int NV>
using gate_t = wrap::mod<parameter::plain<minmax_t<NV>, 0>, 
                         wrap::no_data<dynamics::gate>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, gate_t<NV>>, 
                                  math::clear<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain2_t>, 
                                  chain3_t<NV>>;

template <int NV>
using ResStage_t = wrap::no_data<project::ResStage<NV>>;
template <int NV>
using clone_pack_t = wrap::data<control::clone_pack<parameter::cloned<parameter::plain<ResStage_t<NV>, 9>>>, 
                                data::external::sliderpack<0>>;

DECLARE_PARAMETER_RANGE_STEP(clone_pack1_modRange, 
                             1., 
                             2000., 
                             1.);

template <int NV>
using clone_pack1_mod = parameter::from0To1<fx::sampleandhold<NV>, 
                                            0, 
                                            clone_pack1_modRange>;

template <int NV>
using clone_pack1_t = wrap::data<control::clone_pack<parameter::cloned<clone_pack1_mod<NV>>>, 
                                 data::external::sliderpack<1>>;

DECLARE_PARAMETER_RANGE_SKEW(clone_pack2_modRange, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using clone_pack2_mod = parameter::from0To1<ResStage_t<NV>, 
                                            2, 
                                            clone_pack2_modRange>;

template <int NV>
using clone_pack2_t = wrap::data<control::clone_pack<parameter::cloned<clone_pack2_mod<NV>>>, 
                                 data::external::sliderpack<2>>;

DECLARE_PARAMETER_RANGE_SKEW(clone_pack3_modRange, 
                             1., 
                             32., 
                             0.430677);

template <int NV>
using clone_pack3_mod = parameter::from0To1<ResStage_t<NV>, 
                                            4, 
                                            clone_pack3_modRange>;

template <int NV>
using clone_pack3_t = wrap::data<control::clone_pack<parameter::cloned<clone_pack3_mod<NV>>>, 
                                 data::external::sliderpack<3>>;

DECLARE_PARAMETER_RANGE_SKEW(clone_pack4_modRange, 
                             0., 
                             250., 
                             0.430677);

template <int NV>
using clone_pack4_mod = parameter::from0To1<ResStage_t<NV>, 
                                            5, 
                                            clone_pack4_modRange>;

template <int NV>
using clone_pack4_t = wrap::data<control::clone_pack<parameter::cloned<clone_pack4_mod<NV>>>, 
                                 data::external::sliderpack<4>>;

template <int NV>
using clone_pack5_mod = parameter::from0To1<core::gain<NV>, 
                                            0, 
                                            clone_pack2_modRange>;

template <int NV>
using clone_pack5_t = wrap::data<control::clone_pack<parameter::cloned<clone_pack5_mod<NV>>>, 
                                 data::external::sliderpack<5>>;

DECLARE_PARAMETER_RANGE(clone_pack6_modRange, 
                        -1., 
                        1.);

template <int NV>
using clone_pack6_mod = parameter::from0To1<jdsp::jpanner<NV>, 
                                            0, 
                                            clone_pack6_modRange>;

template <int NV>
using clone_pack6_t = wrap::data<control::clone_pack<parameter::cloned<clone_pack6_mod<NV>>>, 
                                 data::external::sliderpack<6>>;

template <int NV>
using clone_pack7_t = wrap::data<control::clone_pack<parameter::cloned<parameter::plain<ResStage_t<NV>, 8>>>, 
                                 data::external::sliderpack<7>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, clone_pack_t<NV>>, 
                                 clone_pack1_t<NV>, 
                                 clone_pack2_t<NV>, 
                                 clone_pack3_t<NV>, 
                                 clone_pack4_t<NV>, 
                                 clone_pack5_t<NV>, 
                                 clone_pack6_t<NV>, 
                                 clone_pack7_t<NV>>;

template <int NV>
using clone_cable1_t = control::clone_cable<parameter::cloned<parameter::plain<ResStage_t<NV>, 6>>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_cable2_t = control::clone_cable<parameter::cloned<parameter::plain<ResStage_t<NV>, 15>>, 
                                            duplilogic::fixed>;

DECLARE_PARAMETER_RANGE_SKEW(clone_cable3_modRange, 
                             0., 
                             1., 
                             0.239104);

template <int NV>
using clone_cable3_mod = parameter::from0To1<ResStage_t<NV>, 
                                             16, 
                                             clone_cable3_modRange>;

template <int NV>
using clone_cable3_t = control::clone_cable<parameter::cloned<clone_cable3_mod<NV>>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_cable4_t = control::clone_cable<parameter::cloned<parameter::plain<ResStage_t<NV>, 17>>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_cable5_t = control::clone_cable<parameter::cloned<parameter::plain<ResStage_t<NV>, 20>>, 
                                            duplilogic::fixed>;

DECLARE_PARAMETER_RANGE_SKEW(clone_cable8_modRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using clone_cable8_mod = parameter::from0To1<ResStage_t<NV>, 
                                             7, 
                                             clone_cable8_modRange>;

template <int NV>
using clone_cable8_t = control::clone_cable<parameter::cloned<clone_cable8_mod<NV>>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_cable6_mod = parameter::from0To1<ResStage_t<NV>, 
                                             0, 
                                             clone_cable3_modRange>;

template <int NV>
using clone_cable6_t = control::clone_cable<parameter::cloned<clone_cable6_mod<NV>>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_cable7_t = control::clone_cable<parameter::cloned<parameter::plain<ResStage_t<NV>, 1>>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_forward6_t = control::clone_forward<parameter::cloned<parameter::plain<ResStage_t<NV>, 18>>>;

template <int NV>
using clone_forward8_t = control::clone_forward<parameter::cloned<parameter::plain<ResStage_t<NV>, 19>>>;

template <int NV>
using clone_forward_t = control::clone_forward<parameter::cloned<parameter::plain<ResStage_t<NV>, 10>>>;

template <int NV>
using clone_forward1_t = control::clone_forward<parameter::cloned<parameter::plain<ResStage_t<NV>, 11>>>;

template <int NV>
using clone_forward3_t = control::clone_forward<parameter::cloned<parameter::plain<ResStage_t<NV>, 12>>>;

template <int NV>
using clone_forward7_t = control::clone_forward<parameter::cloned<parameter::plain<ResStage_t<NV>, 3>>>;

template <int NV>
using clone_forward4_t = control::clone_forward<parameter::cloned<parameter::plain<ResStage_t<NV>, 13>>>;

template <int NV>
using clone_forward5_t = control::clone_forward<parameter::cloned<parameter::plain<ResStage_t<NV>, 14>>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<1, clone_cable1_t<NV>>, 
                                  clone_cable2_t<NV>, 
                                  clone_cable3_t<NV>, 
                                  clone_cable4_t<NV>, 
                                  clone_cable5_t<NV>, 
                                  clone_cable8_t<NV>, 
                                  clone_cable6_t<NV>, 
                                  clone_cable7_t<NV>, 
                                  clone_forward6_t<NV>, 
                                  clone_forward8_t<NV>, 
                                  clone_forward_t<NV>, 
                                  clone_forward1_t<NV>, 
                                  clone_forward3_t<NV>, 
                                  clone_forward7_t<NV>, 
                                  clone_forward4_t<NV>, 
                                  clone_forward5_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split_t<NV>>, 
                                     split1_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV> using xfader_c0 = clone_pack5_mod<NV>;

template <int NV> using xfader_c1 = clone_pack5_mod<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::overlap>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, core::gain<NV>>>;

template <int NV>
using clone_child_t = container::chain<parameter::empty, 
                                       wrap::fix<2, fx::sampleandhold<NV>>, 
                                       ResStage_t<NV>, 
                                       core::gain<NV>, 
                                       jdsp::jpanner<NV>>;
template <int NV>
using clone_t = wrap::fix_clonecopy<clone_child_t<NV>, 8>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, clone_t<NV>>, 
                                  minmax_t<NV>, 
                                  core::gain<NV>, 
                                  core::gain<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain_t<NV>>, 
                                  chain1_t<NV>>;

namespace FinStack_t_parameters
{
// Parameter list for FinStack_impl::FinStack_t ----------------------------------------------------

DECLARE_PARAMETER_RANGE_SKEW(InputHP_InputRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using InputHP = parameter::chain<InputHP_InputRange, 
                                 parameter::plain<FinStack_impl::clone_cable8_t<NV>, 1>>;

using Resonance = parameter::empty;
template <int NV>
using InputTrig = parameter::plain<FinStack_impl::clone_cable1_t<NV>, 
                                   1>;
template <int NV>
using Feedback = parameter::plain<FinStack_impl::clone_cable2_t<NV>, 
                                  1>;
template <int NV>
using PostCut = parameter::plain<FinStack_impl::clone_cable3_t<NV>, 
                                 1>;
template <int NV>
using PostRes = parameter::plain<FinStack_impl::clone_cable4_t<NV>, 
                                 1>;
template <int NV>
using Phase = parameter::plain<FinStack_impl::clone_cable5_t<NV>, 
                               1>;
template <int NV>
using Min = parameter::plain<FinStack_impl::clone_forward_t<NV>, 
                             1>;
template <int NV>
using Max = parameter::plain<FinStack_impl::clone_forward1_t<NV>, 
                             1>;
template <int NV>
using Step = parameter::plain<FinStack_impl::clone_forward3_t<NV>, 
                              1>;
template <int NV>
using ResMode = parameter::plain<FinStack_impl::clone_forward4_t<NV>, 
                                 1>;
template <int NV>
using PostMode = parameter::plain<FinStack_impl::clone_forward6_t<NV>, 
                                  1>;
template <int NV>
using FbLp = parameter::plain<FinStack_impl::clone_forward5_t<NV>, 
                              1>;
template <int NV>
using compAttack = parameter::plain<FinStack_impl::clone_forward7_t<NV>, 
                                    1>;
template <int NV>
using PreCut = parameter::plain<FinStack_impl::clone_cable6_t<NV>, 
                                1>;
template <int NV>
using PreMode = parameter::plain<FinStack_impl::clone_forward8_t<NV>, 
                                 1>;
template <int NV>
using PreQ = parameter::plain<FinStack_impl::clone_cable7_t<NV>, 
                              1>;
template <int NV>
using mix = parameter::plain<FinStack_impl::xfader_t<NV>, 
                             0>;
template <int NV>
using FinStack_t_plist = parameter::list<Resonance, 
                                         InputTrig<NV>, 
                                         Feedback<NV>, 
                                         PostCut<NV>, 
                                         PostRes<NV>, 
                                         Phase<NV>, 
                                         Min<NV>, 
                                         Max<NV>, 
                                         Step<NV>, 
                                         ResMode<NV>, 
                                         InputHP<NV>, 
                                         PostMode<NV>, 
                                         FbLp<NV>, 
                                         compAttack<NV>, 
                                         PreCut<NV>, 
                                         PreMode<NV>, 
                                         PreQ<NV>, 
                                         mix<NV>>;
}

template <int NV>
using FinStack_t_ = container::chain<FinStack_t_parameters::FinStack_t_plist<NV>, 
                                     wrap::fix<2, split3_t<NV>>, 
                                     modchain_t<NV>, 
                                     xfader_t<NV>, 
                                     split2_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public FinStack_impl::FinStack_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 8;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(FinStack);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(290)
		{
			0x005B, 0x0000, 0x5200, 0x7365, 0x6E6F, 0x6E61, 0x6563, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x523F, 0x9EB8, 0x003E, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0001, 0x0000, 0x6E49, 0x7570, 0x5474, 0x6972, 
            0x0067, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x025B, 0x0000, 0x4600, 0x6565, 0x6264, 
            0x6361, 0x006B, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x035B, 0x0000, 0x5000, 0x736F, 
            0x4374, 0x7475, 0x0000, 0x0000, 0x0000, 0x8000, 0x863F, 0xFD2C, 
            0x003E, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0004, 0x0000, 0x6F50, 
            0x7473, 0x6552, 0x0073, 0x0000, 0x0000, 0x0000, 0x3F80, 0xAE15, 
            0x3F47, 0x0000, 0x3F80, 0x0000, 0x0000, 0x055B, 0x0000, 0x5000, 
            0x6168, 0x6573, 0x0000, 0x0000, 0x0000, 0x8000, 0x9A3F, 0x1999, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0006, 0x0000, 0x694D, 
            0x006E, 0x0000, 0x435C, 0x0000, 0x455C, 0x0000, 0x435C, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x075B, 0x0000, 0x4D00, 0x7861, 0x0000, 
            0x5C00, 0x0043, 0x5C00, 0x0045, 0x5C00, 0x0045, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0008, 0x0000, 0x7453, 0x7065, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x0043, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0009, 0x0000, 0x6552, 0x4D73, 0x646F, 0x0065, 0x0000, 
            0x3F80, 0x0000, 0x4080, 0x0000, 0x4000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0A5B, 0x0000, 0x4900, 0x706E, 0x7475, 0x5048, 0x0000, 
            0xA000, 0x0041, 0x9C40, 0x0046, 0x0A00, 0x1A44, 0x6B6C, 0x003E, 
            0x0000, 0x5B00, 0x000B, 0x0000, 0x6F50, 0x7473, 0x6F4D, 0x6564, 
            0x0000, 0x8000, 0x003F, 0x5000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x000C, 0x0000, 0x6246, 0x704C, 0x0000, 
            0xA000, 0x0041, 0x9C40, 0xB846, 0x95F2, 0x1A45, 0x6B6C, 0x003E, 
            0x0000, 0x5B00, 0x000D, 0x0000, 0x6F63, 0x706D, 0x7441, 0x6174, 
            0x6B63, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x000E, 0x0000, 0x7250, 0x4365, 
            0x7475, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x000F, 0x0000, 0x7250, 0x4D65, 
            0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 0x4150, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x105B, 0x0000, 0x5000, 0x6572, 
            0x0051, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x115B, 0x0000, 0x6D00, 0x7869, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& split3 = this->getT(0);                               // FinStack_impl::split3_t<NV>
		auto& chain2 = this->getT(0).getT(0);                       // FinStack_impl::chain2_t
		auto& chain3 = this->getT(0).getT(1);                       // FinStack_impl::chain3_t<NV>
		auto& gate = this->getT(0).getT(1).getT(0);                 // FinStack_impl::gate_t<NV>
		auto& clear = this->getT(0).getT(1).getT(1);                // math::clear<NV>
		auto& modchain = this->getT(1);                             // FinStack_impl::modchain_t<NV>
		auto& split = this->getT(1).getT(0);                        // FinStack_impl::split_t<NV>
		auto& clone_pack = this->getT(1).getT(0).getT(0);           // FinStack_impl::clone_pack_t<NV>
		auto& clone_pack1 = this->getT(1).getT(0).getT(1);          // FinStack_impl::clone_pack1_t<NV>
		auto& clone_pack2 = this->getT(1).getT(0).getT(2);          // FinStack_impl::clone_pack2_t<NV>
		auto& clone_pack3 = this->getT(1).getT(0).getT(3);          // FinStack_impl::clone_pack3_t<NV>
		auto& clone_pack4 = this->getT(1).getT(0).getT(4);          // FinStack_impl::clone_pack4_t<NV>
		auto& clone_pack5 = this->getT(1).getT(0).getT(5);          // FinStack_impl::clone_pack5_t<NV>
		auto& clone_pack6 = this->getT(1).getT(0).getT(6);          // FinStack_impl::clone_pack6_t<NV>
		auto& clone_pack7 = this->getT(1).getT(0).getT(7);          // FinStack_impl::clone_pack7_t<NV>
		auto& split1 = this->getT(1).getT(1);                       // FinStack_impl::split1_t<NV>
		auto& clone_cable1 = this->getT(1).getT(1).getT(0);         // FinStack_impl::clone_cable1_t<NV>
		auto& clone_cable2 = this->getT(1).getT(1).getT(1);         // FinStack_impl::clone_cable2_t<NV>
		auto& clone_cable3 = this->getT(1).getT(1).getT(2);         // FinStack_impl::clone_cable3_t<NV>
		auto& clone_cable4 = this->getT(1).getT(1).getT(3);         // FinStack_impl::clone_cable4_t<NV>
		auto& clone_cable5 = this->getT(1).getT(1).getT(4);         // FinStack_impl::clone_cable5_t<NV>
		auto& clone_cable8 = this->getT(1).getT(1).getT(5);         // FinStack_impl::clone_cable8_t<NV>
		auto& clone_cable6 = this->getT(1).getT(1).getT(6);         // FinStack_impl::clone_cable6_t<NV>
		auto& clone_cable7 = this->getT(1).getT(1).getT(7);         // FinStack_impl::clone_cable7_t<NV>
		auto& clone_forward6 = this->getT(1).getT(1).getT(8);       // FinStack_impl::clone_forward6_t<NV>
		auto& clone_forward8 = this->getT(1).getT(1).getT(9);       // FinStack_impl::clone_forward8_t<NV>
		auto& clone_forward = this->getT(1).getT(1).getT(10);       // FinStack_impl::clone_forward_t<NV>
		auto& clone_forward1 = this->getT(1).getT(1).getT(11);      // FinStack_impl::clone_forward1_t<NV>
		auto& clone_forward3 = this->getT(1).getT(1).getT(12);      // FinStack_impl::clone_forward3_t<NV>
		auto& clone_forward7 = this->getT(1).getT(1).getT(13);      // FinStack_impl::clone_forward7_t<NV>
		auto& clone_forward4 = this->getT(1).getT(1).getT(14);      // FinStack_impl::clone_forward4_t<NV>
		auto& clone_forward5 = this->getT(1).getT(1).getT(15);      // FinStack_impl::clone_forward5_t<NV>
		auto& xfader = this->getT(2);                               // FinStack_impl::xfader_t<NV>
		auto& split2 = this->getT(3);                               // FinStack_impl::split2_t<NV>
		auto& chain = this->getT(3).getT(0);                        // FinStack_impl::chain_t<NV>
		auto& gain8 = this->getT(3).getT(0).getT(0);                // core::gain<NV>
		auto& chain1 = this->getT(3).getT(1);                       // FinStack_impl::chain1_t<NV>
		auto& clone = this->getT(3).getT(1).getT(0);                // FinStack_impl::clone_t<NV>                // FinStack_impl::clone_child_t<NV>
		auto sampleandhold = this->getT(3).getT(1).getT(0).getT(0); // fx::sampleandhold<NV>
		auto ResStage = this->getT(3).getT(1).getT(0).getT(1);      // FinStack_impl::ResStage_t<NV>
		auto gain = this->getT(3).getT(1).getT(0).getT(2);          // core::gain<NV>
		auto jpanner = this->getT(3).getT(1).getT(0).getT(3);       // jdsp::jpanner<NV>
		auto& minmax = this->getT(3).getT(1).getT(1);               // FinStack_impl::minmax_t<NV>
		auto& gain1 = this->getT(3).getT(1).getT(2);                // core::gain<NV>
		auto& gain9 = this->getT(3).getT(1).getT(3);                // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(1).connectT(0, clone_cable1); // InputTrig -> clone_cable1::Value
		
		this->getParameterT(2).connectT(0, clone_cable2); // Feedback -> clone_cable2::Value
		
		this->getParameterT(3).connectT(0, clone_cable3); // PostCut -> clone_cable3::Value
		
		this->getParameterT(4).connectT(0, clone_cable4); // PostRes -> clone_cable4::Value
		
		this->getParameterT(5).connectT(0, clone_cable5); // Phase -> clone_cable5::Value
		
		this->getParameterT(6).connectT(0, clone_forward); // Min -> clone_forward::Value
		
		this->getParameterT(7).connectT(0, clone_forward1); // Max -> clone_forward1::Value
		
		this->getParameterT(8).connectT(0, clone_forward3); // Step -> clone_forward3::Value
		
		this->getParameterT(9).connectT(0, clone_forward4); // ResMode -> clone_forward4::Value
		
		this->getParameterT(10).connectT(0, clone_cable8); // InputHP -> clone_cable8::Value
		
		this->getParameterT(11).connectT(0, clone_forward6); // PostMode -> clone_forward6::Value
		
		this->getParameterT(12).connectT(0, clone_forward5); // FbLp -> clone_forward5::Value
		
		this->getParameterT(13).connectT(0, clone_forward7); // compAttack -> clone_forward7::Value
		
		this->getParameterT(14).connectT(0, clone_cable6); // PreCut -> clone_cable6::Value
		
		this->getParameterT(15).connectT(0, clone_forward8); // PreMode -> clone_forward8::Value
		
		this->getParameterT(16).connectT(0, clone_cable7); // PreQ -> clone_cable7::Value
		
		this->getParameterT(17).connectT(0, xfader); // mix -> xfader::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		minmax.getWrappedObject().getParameter().connectT(0, gain1);              // minmax -> gain1::Gain
		gate.getParameter().connectT(0, minmax);                                  // gate -> minmax::Value
		clone_pack.getWrappedObject().getParameter().connectT(0, ResStage);       // clone_pack -> ResStage::ResFreq
		clone_pack1.getWrappedObject().getParameter().connectT(0, sampleandhold); // clone_pack1 -> sampleandhold::Counter
		clone_pack2.getWrappedObject().getParameter().connectT(0, ResStage);      // clone_pack2 -> ResStage::CompThresh
		clone_pack3.getWrappedObject().getParameter().connectT(0, ResStage);      // clone_pack3 -> ResStage::CompRel
		clone_pack4.getWrappedObject().getParameter().connectT(0, ResStage);      // clone_pack4 -> ResStage::CompRatio
		clone_pack5.getWrappedObject().getParameter().connectT(0, gain);          // clone_pack5 -> gain::Gain
		clone_pack6.getWrappedObject().getParameter().connectT(0, jpanner);       // clone_pack6 -> jpanner::Pan
		clone_pack7.getWrappedObject().getParameter().connectT(0, ResStage);      // clone_pack7 -> ResStage::Rate
		clone_cable1.getWrappedObject().getParameter().connectT(0, ResStage);     // clone_cable1 -> ResStage::InputTrig
		clone_cable2.getWrappedObject().getParameter().connectT(0, ResStage);     // clone_cable2 -> ResStage::ResFeed
		clone_cable3.getWrappedObject().getParameter().connectT(0, ResStage);     // clone_cable3 -> ResStage::PostCut
		clone_cable4.getWrappedObject().getParameter().connectT(0, ResStage);     // clone_cable4 -> ResStage::PostRes
		clone_cable5.getWrappedObject().getParameter().connectT(0, ResStage);     // clone_cable5 -> ResStage::Phase
		clone_cable8.getWrappedObject().getParameter().connectT(0, ResStage);     // clone_cable8 -> ResStage::InputHP
		clone_cable6.getWrappedObject().getParameter().connectT(0, ResStage);     // clone_cable6 -> ResStage::CutOffA
		clone_cable7.getWrappedObject().getParameter().connectT(0, ResStage);     // clone_cable7 -> ResStage::qA
		clone_forward6.getWrappedObject().getParameter().connectT(0, ResStage);   // clone_forward6 -> ResStage::PostMode
		clone_forward8.getWrappedObject().getParameter().connectT(0, ResStage);   // clone_forward8 -> ResStage::Fmode1
		clone_forward.getWrappedObject().getParameter().connectT(0, ResStage);    // clone_forward -> ResStage::ResMin
		clone_forward1.getWrappedObject().getParameter().connectT(0, ResStage);   // clone_forward1 -> ResStage::ResMax
		clone_forward3.getWrappedObject().getParameter().connectT(0, ResStage);   // clone_forward3 -> ResStage::ResStep
		clone_forward7.getWrappedObject().getParameter().connectT(0, ResStage);   // clone_forward7 -> ResStage::CompAtk
		clone_forward4.getWrappedObject().getParameter().connectT(0, ResStage);   // clone_forward4 -> ResStage::ResMode
		clone_forward5.getWrappedObject().getParameter().connectT(0, ResStage);   // clone_forward5 -> ResStage::ResLP
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain8); // xfader -> gain8::Gain
		xfader_p.getParameterT(1).connectT(0, gain9); // xfader -> gain9::Gain
		
		// Default Values --------------------------------------------------------------------------
		
		gate.setParameterT(0, -100.); // dynamics::gate::Threshhold
		gate.setParameterT(1, 50.);   // dynamics::gate::Attack
		gate.setParameterT(2, 50.);   // dynamics::gate::Release
		gate.setParameterT(3, 1.);    // dynamics::gate::Ratio
		gate.setParameterT(4, 2.);    // dynamics::gate::Sidechain
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		clone_pack.setParameterT(0, 8.); // control::clone_pack::NumClones
		clone_pack.setParameterT(1, 1.); // control::clone_pack::Value
		
		clone_pack1.setParameterT(0, 8.); // control::clone_pack::NumClones
		clone_pack1.setParameterT(1, 1.); // control::clone_pack::Value
		
		clone_pack2.setParameterT(0, 8.); // control::clone_pack::NumClones
		clone_pack2.setParameterT(1, 1.); // control::clone_pack::Value
		
		clone_pack3.setParameterT(0, 8.); // control::clone_pack::NumClones
		clone_pack3.setParameterT(1, 1.); // control::clone_pack::Value
		
		clone_pack4.setParameterT(0, 8.); // control::clone_pack::NumClones
		clone_pack4.setParameterT(1, 1.); // control::clone_pack::Value
		
		clone_pack5.setParameterT(0, 8.); // control::clone_pack::NumClones
		clone_pack5.setParameterT(1, 1.); // control::clone_pack::Value
		
		clone_pack6.setParameterT(0, 8.); // control::clone_pack::NumClones
		clone_pack6.setParameterT(1, 1.); // control::clone_pack::Value
		
		clone_pack7.setParameterT(0, 8.); // control::clone_pack::NumClones
		clone_pack7.setParameterT(1, 1.); // control::clone_pack::Value
		
		;                                  // clone_cable1::NumClones is deactivated
		;                                  // clone_cable1::Value is automated
		clone_cable1.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable2::NumClones is deactivated
		;                                  // clone_cable2::Value is automated
		clone_cable2.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable3::NumClones is deactivated
		;                                  // clone_cable3::Value is automated
		clone_cable3.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable4::NumClones is deactivated
		;                                  // clone_cable4::Value is automated
		clone_cable4.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable5::NumClones is deactivated
		;                                  // clone_cable5::Value is automated
		clone_cable5.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable8::NumClones is deactivated
		;                                  // clone_cable8::Value is automated
		clone_cable8.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable6::NumClones is deactivated
		;                                  // clone_cable6::Value is automated
		clone_cable6.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable7::NumClones is deactivated
		;                                  // clone_cable7::Value is automated
		clone_cable7.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		clone_forward6.setParameterT(0, 8.); // control::clone_forward::NumClones
		;                                    // clone_forward6::Value is automated
		
		clone_forward8.setParameterT(0, 8.); // control::clone_forward::NumClones
		;                                    // clone_forward8::Value is automated
		
		clone_forward.setParameterT(0, 8.); // control::clone_forward::NumClones
		;                                   // clone_forward::Value is automated
		
		clone_forward1.setParameterT(0, 8.); // control::clone_forward::NumClones
		;                                    // clone_forward1::Value is automated
		
		clone_forward3.setParameterT(0, 8.); // control::clone_forward::NumClones
		;                                    // clone_forward3::Value is automated
		
		clone_forward7.setParameterT(0, 8.); // control::clone_forward::NumClones
		;                                    // clone_forward7::Value is automated
		
		clone_forward4.setParameterT(0, 8.); // control::clone_forward::NumClones
		;                                    // clone_forward4::Value is automated
		
		clone_forward5.setParameterT(0, 8.); // control::clone_forward::NumClones
		;                                    // clone_forward5::Value is automated
		
		; // xfader::Value is automated
		
		;                            // gain8::Gain is automated
		gain8.setParameterT(1, 20.); // core::gain::Smoothing
		gain8.setParameterT(2, 0.);  // core::gain::ResetValue
		
		clone.setParameterT(0, 8.); // container::clone::NumClones
		clone.setParameterT(1, 2.); // container::clone::SplitSignal
		
		; // sampleandhold::Counter is automated
		
		; // ResStage::CutOffA is automated
		; // ResStage::qA is automated
		; // ResStage::CompThresh is automated
		; // ResStage::CompAtk is automated
		; // ResStage::CompRel is automated
		; // ResStage::CompRatio is automated
		; // ResStage::InputTrig is automated
		; // ResStage::InputHP is automated
		; // ResStage::Rate is automated
		; // ResStage::ResFreq is automated
		; // ResStage::ResMin is automated
		; // ResStage::ResMax is automated
		; // ResStage::ResStep is automated
		; // ResStage::ResMode is automated
		; // ResStage::ResLP is automated
		; // ResStage::ResFeed is automated
		; // ResStage::PostCut is automated
		; // ResStage::PostRes is automated
		; // ResStage::PostMode is automated
		; // ResStage::Fmode1 is automated
		; // ResStage::Phase is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                             // jpanner::Pan is automated
		jpanner.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                                 // minmax::Value is automated
		minmax.setParameterT(1, -100.);   // control::minmax::Minimum
		minmax.setParameterT(2, 0.);      // control::minmax::Maximum
		minmax.setParameterT(3, 5.42227); // control::minmax::Skew
		minmax.setParameterT(4, 0.1);     // control::minmax::Step
		minmax.setParameterT(5, 1.);      // control::minmax::Polarity
		
		;                              // gain1::Gain is automated
		gain1.setParameterT(1, 189.9); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);    // core::gain::ResetValue
		
		;                            // gain9::Gain is automated
		gain9.setParameterT(1, 20.); // core::gain::Smoothing
		gain9.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 0.31);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 0.49448);
		this->setParameterT(4, 0.78);
		this->setParameterT(5, 0.6);
		this->setParameterT(6, 220.);
		this->setParameterT(7, 3520.);
		this->setParameterT(8, 0.);
		this->setParameterT(9, 2.);
		this->setParameterT(10, 552.);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 4798.34);
		this->setParameterT(13, 0.);
		this->setParameterT(14, 0.);
		this->setParameterT(15, 1.);
		this->setParameterT(16, 0.);
		this->setParameterT(17, 1.);
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
		
		this->getT(0).getT(1).getT(0).setExternalData(b, index);         // FinStack_impl::gate_t<NV>
		this->getT(1).getT(0).getT(0).setExternalData(b, index);         // FinStack_impl::clone_pack_t<NV>
		this->getT(1).getT(0).getT(1).setExternalData(b, index);         // FinStack_impl::clone_pack1_t<NV>
		this->getT(1).getT(0).getT(2).setExternalData(b, index);         // FinStack_impl::clone_pack2_t<NV>
		this->getT(1).getT(0).getT(3).setExternalData(b, index);         // FinStack_impl::clone_pack3_t<NV>
		this->getT(1).getT(0).getT(4).setExternalData(b, index);         // FinStack_impl::clone_pack4_t<NV>
		this->getT(1).getT(0).getT(5).setExternalData(b, index);         // FinStack_impl::clone_pack5_t<NV>
		this->getT(1).getT(0).getT(6).setExternalData(b, index);         // FinStack_impl::clone_pack6_t<NV>
		this->getT(1).getT(0).getT(7).setExternalData(b, index);         // FinStack_impl::clone_pack7_t<NV>
		this->getT(3).getT(1).getT(0).getT(1).setExternalData(b, index); // FinStack_impl::ResStage_t<NV>
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
using FinStack = wrap::node<FinStack_impl::instance<NV>>;
}


