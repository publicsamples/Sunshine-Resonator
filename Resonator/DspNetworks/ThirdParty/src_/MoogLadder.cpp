/* ------------------------------------------------------------
name: "MoogLadder"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _MoogLadder -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___MoogLadder_H__
#define  ___MoogLadder_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _MoogLadder
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

static float _MoogLadder_faustpower4_f(float value) {
	return value * value * value * value;
}

struct _MoogLadder final : public ::faust::dsp {
	
	int fSampleRate;
	float fConst0;
	FAUSTFLOAT fHslider0;
	float fConst1;
	float fRec5[2];
	FAUSTFLOAT fHslider1;
	float fRec0[2];
	float fRec1[2];
	float fRec2[2];
	float fRec3[2];
	
	_MoogLadder() {
	}
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _MoogLadder -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("filename", "MoogLadder.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("name", "MoogLadder");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.6.0");
		m->declare("vaeffects.lib/moogLadder:author", "Dario Sanfilippo");
		m->declare("vaeffects.lib/moogLadder:license", "MIT-style STK-4.3 license");
		m->declare("vaeffects.lib/name", "Faust Virtual Analog Filter Effect Library");
		m->declare("vaeffects.lib/version", "1.2.1");
	}

	static constexpr int getStaticNumInputs() {
		return 1;
	}
	static constexpr int getStaticNumOutputs() {
		return 2;
	}
	int getNumInputs() {
		return 1;
	}
	int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = 44.1f / std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 1.0f - fConst0;
	}
	
	void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.1f);
		fHslider1 = FAUSTFLOAT(1.0f);
	}
	
	void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fRec5[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec0[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec2[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec3[l4] = 0.0f;
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
	
	_MoogLadder* clone() {
		return new _MoogLadder();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("MoogLadder");
		ui_interface->addHorizontalSlider("Q", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.7072f), FAUSTFLOAT(25.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("freq", &fHslider0, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = fConst0 * std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider0)));
		float fSlow1 = 0.1646572f * (std::max<float>(0.7072f, std::min<float>(25.0f, float(fHslider1))) + -0.70710677f);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fRec5[0] = fSlow0 + fConst1 * fRec5[1];
			float fTemp0 = std::tan(1.5707964f * fRec5[0]);
			float fTemp1 = fTemp0 + 1.0f;
			float fTemp2 = fTemp0 * ((float(input0[i0]) - fSlow1 * (1.0f - fTemp0 / fTemp1) * (fRec3[1] + fTemp0 * (fRec2[1] + fTemp0 * (fRec1[1] + fTemp0 * fRec0[1] / fTemp1) / fTemp1) / fTemp1)) / (fSlow1 * (_MoogLadder_faustpower4_f(fTemp0) / _MoogLadder_faustpower4_f(fTemp1)) + 1.0f) - fRec0[1]) / fTemp1;
			fRec0[0] = fRec0[1] + 2.0f * fTemp2;
			float fTemp3 = fTemp0 * (fRec0[1] + fTemp2 - fRec1[1]) / fTemp1;
			fRec1[0] = fRec1[1] + 2.0f * fTemp3;
			float fTemp4 = fTemp0 * (fRec1[1] + fTemp3 - fRec2[1]) / fTemp1;
			fRec2[0] = fRec2[1] + 2.0f * fTemp4;
			float fTemp5 = fTemp0 * (fRec2[1] + fTemp4 - fRec3[1]) / fTemp1;
			fRec3[0] = fRec3[1] + 2.0f * fTemp5;
			float fRec4 = fRec3[1] + fTemp5;
			output0[i0] = FAUSTFLOAT(fRec4);
			output1[i0] = FAUSTFLOAT(fRec4);
			fRec5[1] = fRec5[0];
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "MoogLadder.dsp"
	#define FAUST_CLASS_NAME "_MoogLadder"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _MoogLadder -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 1
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 2
	#define FAUST_PASSIVES 0

	FAUST_ADDHORIZONTALSLIDER("Q", fHslider1, 1.0f, 0.7072f, 25.0f, 0.01f);
	FAUST_ADDHORIZONTALSLIDER("freq", fHslider0, 0.1f, 0.0f, 1.0f, 0.001f);

	#define FAUST_LIST_ACTIVES(p) \
		p(HORIZONTALSLIDER, Q, "Q", fHslider1, 1.0f, 0.7072f, 25.0f, 0.01f) \
		p(HORIZONTALSLIDER, freq, "freq", fHslider0, 0.1f, 0.0f, 1.0f, 0.001f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
