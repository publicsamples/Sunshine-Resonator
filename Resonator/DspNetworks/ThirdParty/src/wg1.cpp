/* ------------------------------------------------------------
name: "wg1"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _wg1 -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___wg1_H__
#define  ___wg1_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _wg1
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif


struct _wg1 final : public ::faust::dsp {
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int IOTA0;
	float fVec0[1024];
	float fRec0[2];
	float fVec1[1024];
	float fRec2[2];
	int fSampleRate;
	
	_wg1() {
	}
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _wg1 -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.1.0");
		m->declare("filename", "wg1.dsp");
		m->declare("filters.lib/allpass_fcomb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_fcomb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_fcomb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.3.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("name", "wg1");
	}

	static constexpr int getStaticNumInputs() {
		return 2;
	}
	static constexpr int getStaticNumOutputs() {
		return 2;
	}
	int getNumInputs() {
		return 2;
	}
	int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
	}
	
	void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.0f);
	}
	
	void instanceClear() {
		IOTA0 = 0;
		for (int l0 = 0; l0 < 1024; l0 = l0 + 1) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec0[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 1024; l2 = l2 + 1) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec2[l3] = 0.0f;
		}
	}
	
	void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	_wg1* clone() {
		return new _wg1();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("wg1");
		ui_interface->addHorizontalSlider("aN", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("del", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::max<float>(0.0f, std::min<float>(1e+03f, float(fHslider0)));
		float fSlow1 = fSlow0 + -1.0f;
		float fSlow2 = std::floor(fSlow1);
		float fSlow3 = fSlow2 + (2.0f - fSlow0);
		float fSlow4 = std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider1)));
		int iSlow5 = int(fSlow1);
		int iSlow6 = std::min<int>(1025, std::max<int>(0, iSlow5));
		float fSlow7 = fSlow0 + (-1.0f - fSlow2);
		int iSlow8 = std::min<int>(1025, std::max<int>(0, iSlow5 + 1));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = float(input0[i0]) - fSlow4 * fRec0[1];
			fVec0[IOTA0 & 1023] = fTemp0;
			fRec0[0] = fSlow3 * fVec0[(IOTA0 - iSlow6) & 1023] + fSlow7 * fVec0[(IOTA0 - iSlow8) & 1023];
			float fRec1 = fSlow4 * fTemp0;
			output0[i0] = FAUSTFLOAT(fRec0[1] + fRec1);
			float fTemp1 = float(input1[i0]) - fSlow4 * fRec2[1];
			fVec1[IOTA0 & 1023] = fTemp1;
			fRec2[0] = fSlow7 * fVec1[(IOTA0 - iSlow8) & 1023] + fSlow3 * fVec1[(IOTA0 - iSlow6) & 1023];
			float fRec3 = fSlow4 * fTemp1;
			output1[i0] = FAUSTFLOAT(fRec2[1] + fRec3);
			IOTA0 = IOTA0 + 1;
			fRec0[1] = fRec0[0];
			fRec2[1] = fRec2[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "wg1.dsp"
	#define FAUST_CLASS_NAME "_wg1"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _wg1 -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 2
	#define FAUST_PASSIVES 0

	FAUST_ADDHORIZONTALSLIDER("aN", fHslider1, 0.0f, 0.0f, 1.0f, 0.01f);
	FAUST_ADDHORIZONTALSLIDER("del", fHslider0, 0.0f, 0.0f, 1e+03f, 1.0f);

	#define FAUST_LIST_ACTIVES(p) \
		p(HORIZONTALSLIDER, aN, "aN", fHslider1, 0.0f, 0.0f, 1.0f, 0.01f) \
		p(HORIZONTALSLIDER, del, "del", fHslider0, 0.0f, 0.0f, 1e+03f, 1.0f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
