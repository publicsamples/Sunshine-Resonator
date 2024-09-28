/** Autogenerated Main.cpp. */

// =============================| Include only the DSP files  |=============================

#include <AppConfig.h>
#include <hi_dsp_library/hi_dsp_library.h>
#include <hi_faust/hi_faust.h>
#include "includes.h"
// =======================| Now we can add the rest of the codebase |=======================

#include <JuceHeader.h>

#if !JUCE_WINDOWS
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
#endif

// ===================================| Project Factory |===================================

namespace project
{

struct Factory: public scriptnode::dll::StaticLibraryHostFactory
{
	Factory()
	{
		TempoSyncer::initTempoData();
		// Node registrations -------------------------------------------------------------
		
		registerPolyNode<project::modtest1<1>, wrap::illegal_poly<project::modtest1<1>>>();
		registerPolyNode<project::OneAP<1>, wrap::illegal_poly<project::OneAP<1>>>();
		registerDataNode<project::AP_networkdata>();
		registerDataNode<project::ApTest_networkdata>();
		registerDataNode<project::BUF_networkdata>();
		registerDataNode<project::CableRouting_networkdata>();
		registerDataNode<project::_networkdata>();
		registerDataNode<project::delay_networkdata>();
		registerDataNode<project::Follow1_networkdata>();
		registerDataNode<project::_networkdata>();
		registerDataNode<project::PitchNu1_networkdata>();
		registerDataNode<project::POSTRESONATOR_networkdata>();
		registerDataNode<project::PreTrack_networkdata>();
		registerDataNode<project::Resonantor_networkdata>();
		registerDataNode<project::reverb_networkdata>();
		registerDataNode<project::_networkdata>();
	}
};
}

scriptnode::dll::FactoryBase* scriptnode::DspNetwork::createStaticFactory()
{
	return new project::Factory();
}

#if !JUCE_WINDOWS
#pragma clang diagnostic pop
#endif


