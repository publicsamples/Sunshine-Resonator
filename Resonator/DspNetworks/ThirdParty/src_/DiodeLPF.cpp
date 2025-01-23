/* ------------------------------------------------------------
name: "DiodeLPF"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _DiodeLPF -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___DiodeLPF_H__
#define  ___DiodeLPF_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _DiodeLPF
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

static float _DiodeLPF_faustpower2_f(float value) {
	return value * value;
}
static float _DiodeLPF_faustpower3_f(float value) {
	return value * value * value;
}
static float _DiodeLPF_faustpower4_f(float value) {
	return value * value * value * value;
}

struct _DiodeLPF final : public ::faust::dsp {
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fConst3;
	float fRec5[2];
	FAUSTFLOAT fHslider1;
	float fRec1[2];
	float fRec2[2];
	float fRec3[2];
	float fRec4[2];
	
	_DiodeLPF() {
	}
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _DiodeLPF -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("filename", "DiodeLPF.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("misceffects.lib/cubicnl:author", "Julius O. Smith III");
		m->declare("misceffects.lib/cubicnl:license", "STK-4.3");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.5.0");
		m->declare("name", "DiodeLPF");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.6.0");
		m->declare("vaeffects.lib/diodeLadder:author", "Eric Tarr");
		m->declare("vaeffects.lib/diodeLadder:license", "MIT-style STK-4.3 license");
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
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 6.2831855f / fConst0;
		fConst2 = 44.1f / fConst0;
		fConst3 = 1.0f - fConst2;
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
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec4[l4] = 0.0f;
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
	
	_DiodeLPF* clone() {
		return new _DiodeLPF();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("DiodeLPF");
		ui_interface->addHorizontalSlider("Q", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.7072f), FAUSTFLOAT(25.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("freq", &fHslider0, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = fConst2 * std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider0)));
		float fSlow1 = std::max<float>(0.7072f, std::min<float>(25.0f, float(fHslider1))) + -0.70710677f;
		float fSlow2 = 0.0051455377f * fSlow1;
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fRec5[0] = fSlow0 + fConst3 * fRec5[1];
			float fTemp0 = std::tan(fConst1 * std::pow(1e+01f, 3.0f * fRec5[0] + 1.0f));
			float fTemp1 = fTemp0 + 1.0f;
			float fTemp2 = 0.5f * (fTemp0 * fRec1[1] / fTemp1) + fRec2[1];
			float fTemp3 = fTemp0 * (1.0f - 0.25f * (fTemp0 / fTemp1)) + 1.0f;
			float fTemp4 = fTemp0 * fTemp2 / fTemp3;
			float fTemp5 = 0.5f * fTemp4;
			float fTemp6 = fTemp5 + fRec3[1];
			float fTemp7 = fTemp0 * (1.0f - 0.25f * (fTemp0 / fTemp3)) + 1.0f;
			float fTemp8 = fTemp0 * fTemp6 / fTemp7;
			float fTemp9 = std::max<float>(-1.0f, std::min<float>(1.0f, 1e+02f * float(input0[i0])));
			float fTemp10 = 17.0f - 9.7f * std::pow(fRec5[0], 1e+01f);
			float fTemp11 = fTemp8 + fRec4[1];
			float fTemp12 = fTemp3 * fTemp7;
			float fTemp13 = fTemp0 * (1.0f - 0.5f * (fTemp0 / fTemp7)) + 1.0f;
			float fTemp14 = _DiodeLPF_faustpower2_f(fTemp0);
			float fTemp15 = fTemp1 * fTemp3;
			float fTemp16 = fTemp0 * ((1.5f * fTemp9 * (1.0f - 0.33333334f * _DiodeLPF_faustpower2_f(fTemp9)) - fSlow1 * (fTemp10 * (0.02058215f * fTemp4 + 0.0411643f * fRec1[1] + 0.02058215f * fTemp8 + 0.0051455377f * (_DiodeLPF_faustpower3_f(fTemp0) * fTemp11 / (fTemp12 * fTemp13))) / fTemp1)) * (0.5f * (fTemp14 / (fTemp7 * fTemp13)) + 1.0f) / (fSlow2 * (_DiodeLPF_faustpower4_f(fTemp0) * fTemp10 / (fTemp15 * fTemp7 * fTemp13)) + 1.0f) + (fTemp6 + 0.5f * (fTemp0 * fTemp11 / fTemp13)) / fTemp7 - fRec4[1]) / fTemp1;
			float fTemp17 = (0.5f * ((0.5f * fTemp8 + fTemp2) / fTemp3 + (fRec4[1] + fTemp16) * (0.25f * (fTemp14 / fTemp12) + 1.0f)) - fRec3[1]) * fTemp0 / fTemp1;
			float fTemp18 = (0.5f * ((fTemp17 + fRec3[1]) * (0.25f * (fTemp14 / fTemp15) + 1.0f) + (fTemp5 + fRec1[1]) / fTemp1) - fRec2[1]) * fTemp0 / fTemp1;
			float fTemp19 = (0.5f * (fTemp18 + fRec2[1]) - fRec1[1]) * fTemp0 / fTemp1;
			float fRec0 = fTemp19 + fRec1[1];
			fRec1[0] = 2.0f * fTemp19 + fRec1[1];
			fRec2[0] = 2.0f * fTemp18 + fRec2[1];
			fRec3[0] = 2.0f * fTemp17 + fRec3[1];
			fRec4[0] = 2.0f * fTemp16 + fRec4[1];
			output0[i0] = FAUSTFLOAT(fRec0);
			output1[i0] = FAUSTFLOAT(fRec0);
			fRec5[1] = fRec5[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "DiodeLPF.dsp"
	#define FAUST_CLASS_NAME "_DiodeLPF"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _DiodeLPF -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
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
