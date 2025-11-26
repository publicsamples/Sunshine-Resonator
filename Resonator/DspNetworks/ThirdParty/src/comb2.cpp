/* ------------------------------------------------------------
name: "comb2"
Code generated with Faust 2.81.2 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _comb2 -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___comb2_H__
#define  ___comb2_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _comb2
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


struct _comb2 final : public ::faust::dsp {
	
	int IOTA0;
	float fVec0[2048];
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	float fVec1[2048];
	int fSampleRate;
	
	_comb2() {
	}
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _comb2 -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("filename", "comb2.dsp");
		m->declare("filters.lib/ff_fcomb:author", "Julius O. Smith III");
		m->declare("filters.lib/ff_fcomb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/ff_fcomb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.7.1");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.1");
		m->declare("name", "comb2");
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
		for (int l0 = 0; l0 < 2048; l0 = l0 + 1) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2048; l1 = l1 + 1) {
			fVec1[l1] = 0.0f;
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
	
	_comb2* clone() {
		return new _comb2();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("comb2");
		ui_interface->addHorizontalSlider("aN", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("del", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1024.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider0)));
		float fSlow1 = std::max<float>(0.0f, std::min<float>(1024.0f, float(fHslider1)));
		float fSlow2 = std::floor(fSlow1);
		float fSlow3 = fSlow2 + (1.0f - fSlow1);
		int iSlow4 = int(fSlow1);
		int iSlow5 = std::min<int>(1025, std::max<int>(0, iSlow4));
		float fSlow6 = fSlow1 - fSlow2;
		int iSlow7 = std::min<int>(1025, std::max<int>(0, iSlow4 + 1));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = float(input0[i0]);
			fVec0[IOTA0 & 2047] = fTemp0;
			output0[i0] = FAUSTFLOAT(fTemp0 + fSlow0 * (fSlow3 * fVec0[(IOTA0 - iSlow5) & 2047] + fSlow6 * fVec0[(IOTA0 - iSlow7) & 2047]));
			float fTemp1 = float(input1[i0]);
			fVec1[IOTA0 & 2047] = fTemp1;
			output1[i0] = FAUSTFLOAT(fTemp1 + fSlow0 * (fSlow3 * fVec1[(IOTA0 - iSlow5) & 2047] + fSlow6 * fVec1[(IOTA0 - iSlow7) & 2047]));
			IOTA0 = IOTA0 + 1;
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "comb2.dsp"
	#define FAUST_CLASS_NAME "_comb2"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _comb2 -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 2
	#define FAUST_PASSIVES 0

	FAUST_ADDHORIZONTALSLIDER("aN", fHslider0, 0.0f, 0.0f, 1.0f, 0.01f);
	FAUST_ADDHORIZONTALSLIDER("del", fHslider1, 0.0f, 0.0f, 1024.0f, 1.0f);

	#define FAUST_LIST_ACTIVES(p) \
		p(HORIZONTALSLIDER, aN, "aN", fHslider0, 0.0f, 0.0f, 1.0f, 0.01f) \
		p(HORIZONTALSLIDER, del, "del", fHslider1, 0.0f, 0.0f, 1024.0f, 1.0f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
