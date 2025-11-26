/* ------------------------------------------------------------
name: "comb"
Code generated with Faust 2.81.2 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _comb -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___comb_H__
#define  ___comb_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _comb
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


struct _comb final : public ::faust::dsp {
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int IOTA0;
	float fRec0[2048];
	float fRec1[2048];
	int fSampleRate;
	
	_comb() {
	}
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _comb -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("filename", "comb.dsp");
		m->declare("filters.lib/fb_comb_common:author", "Oleg Nesterov");
		m->declare("filters.lib/fb_fcomb:author", "Julius O. Smith III");
		m->declare("filters.lib/fb_fcomb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>, revised by Oleg Nesterov");
		m->declare("filters.lib/fb_fcomb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.7.1");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.1");
		m->declare("name", "comb");
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
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2048; l1 = l1 + 1) {
			fRec1[l1] = 0.0f;
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
	
	_comb* clone() {
		return new _comb();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("comb");
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
		float fSlow2 = fSlow1 + -1.0f;
		float fSlow3 = std::floor(fSlow2);
		float fSlow4 = fSlow3 + (2.0f - fSlow1);
		int iSlow5 = int(fSlow2);
		int iSlow6 = std::min<int>(1025, std::max<int>(0, iSlow5)) + 1;
		float fSlow7 = fSlow1 + (-1.0f - fSlow3);
		int iSlow8 = std::min<int>(1025, std::max<int>(0, iSlow5 + 1)) + 1;
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fRec0[IOTA0 & 2047] = float(input0[i0]) - fSlow0 * (fSlow4 * fRec0[(IOTA0 - iSlow6) & 2047] + fSlow7 * fRec0[(IOTA0 - iSlow8) & 2047]);
			output0[i0] = FAUSTFLOAT(fRec0[(IOTA0 - 1) & 2047]);
			fRec1[IOTA0 & 2047] = float(input1[i0]) - fSlow0 * (fSlow4 * fRec1[(IOTA0 - iSlow6) & 2047] + fSlow7 * fRec1[(IOTA0 - iSlow8) & 2047]);
			output1[i0] = FAUSTFLOAT(fRec1[(IOTA0 - 1) & 2047]);
			IOTA0 = IOTA0 + 1;
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "comb.dsp"
	#define FAUST_CLASS_NAME "_comb"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _comb -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
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
