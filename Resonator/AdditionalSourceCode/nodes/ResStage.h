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

DECLARE_PARAMETER_RANGE_SKEW(xfader1_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using xfader1_c0 = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       xfader1_c0Range>;

template <int NV> using xfader1_c1 = xfader1_c0<NV>;

template <int NV>
using xfader1_multimod = parameter::list<xfader1_c0<NV>, xfader1_c1<NV>>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::linear>;

DECLARE_PARAMETER_RANGE_STEP(cable_table2_modRange, 
                             5., 
                             2205., 
                             1.);

template <int NV>
using cable_table2_mod = parameter::from0To1<project::granul<NV>, 
                                             0, 
                                             cable_table2_modRange>;

struct cable_table2_t_data
{
	span<float, 512> data =
	{
		1.f, 0.991854f, 0.983708f, 0.975562f, 0.967416f, 0.95927f,
		0.951124f, 0.942978f, 0.934832f, 0.926686f, 0.91854f, 0.910394f,
		0.902248f, 0.894102f, 0.885956f, 0.87781f, 0.869664f, 0.861518f,
		0.853372f, 0.845226f, 0.83708f, 0.828934f, 0.820788f, 0.812642f,
		0.804496f, 0.79635f, 0.788204f, 0.780058f, 0.771912f, 0.763766f,
		0.75562f, 0.747474f, 0.739328f, 0.731182f, 0.723036f, 0.71489f,
		0.706744f, 0.698598f, 0.690452f, 0.682306f, 0.67416f, 0.666014f,
		0.657868f, 0.649722f, 0.641576f, 0.63343f, 0.625284f, 0.617138f,
		0.608992f, 0.600846f, 0.5927f, 0.584554f, 0.576408f, 0.568262f,
		0.560116f, 0.55197f, 0.543824f, 0.535679f, 0.527532f, 0.519387f,
		0.511241f, 0.503094f, 0.494949f, 0.486803f, 0.478657f, 0.470511f,
		0.462365f, 0.454219f, 0.446073f, 0.437927f, 0.429781f, 0.421635f,
		0.413489f, 0.405343f, 0.397197f, 0.389051f, 0.380905f, 0.372759f,
		0.364613f, 0.356467f, 0.348321f, 0.340175f, 0.332029f, 0.323883f,
		0.315737f, 0.307591f, 0.299445f, 0.291299f, 0.283153f, 0.275007f,
		0.266861f, 0.258715f, 0.250569f, 0.242423f, 0.234277f, 0.226131f,
		0.217985f, 0.209839f, 0.201693f, 0.193547f, 0.185401f, 0.177255f,
		0.169109f, 0.160963f, 0.152817f, 0.144671f, 0.136525f, 0.128379f,
		0.120233f, 0.112087f, 0.103941f, 0.0957949f, 0.0876489f, 0.0795029f,
		0.071357f, 0.063211f, 0.055065f, 0.046919f, 0.0387731f, 0.030627f,
		0.0224811f, 0.014335f, 0.00618899f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.00197226f,
		0.00590152f, 0.00983071f, 0.0137601f, 0.0176893f, 0.0216185f, 0.0255477f,
		0.029477f, 0.0334062f, 0.0373355f, 0.0412647f, 0.045194f, 0.0491232f,
		0.0530525f, 0.0569817f, 0.0609109f, 0.0648401f, 0.0687694f, 0.0726986f,
		0.076628f, 0.0805572f, 0.0844864f, 0.0884156f, 0.0923449f, 0.0962741f,
		0.100203f, 0.104133f, 0.108062f, 0.111991f, 0.11592f, 0.11985f,
		0.123779f, 0.127708f, 0.131637f, 0.135567f, 0.139496f, 0.143425f,
		0.147354f, 0.151284f, 0.155213f, 0.159142f, 0.163071f, 0.167f,
		0.17093f, 0.174859f, 0.178788f, 0.182717f, 0.186647f, 0.190576f,
		0.194505f, 0.198434f, 0.202364f, 0.206293f, 0.210222f, 0.214151f,
		0.218081f, 0.22201f, 0.225939f, 0.229868f, 0.233798f, 0.237727f,
		0.241656f, 0.245585f, 0.249515f, 0.253444f, 0.257373f, 0.261302f,
		0.265232f, 0.269161f, 0.27309f, 0.277019f, 0.280949f, 0.284878f,
		0.288807f, 0.292736f, 0.296666f, 0.300595f, 0.304524f, 0.308453f,
		0.312382f, 0.316312f, 0.320241f, 0.32417f, 0.328099f, 0.332029f,
		0.335958f, 0.339887f, 0.343816f, 0.347746f, 0.351675f, 0.355604f,
		0.359533f, 0.363463f, 0.367392f, 0.371321f, 0.37525f, 0.37918f,
		0.383109f, 0.387038f, 0.390967f, 0.394897f, 0.398826f, 0.402755f,
		0.406684f, 0.410614f, 0.414543f, 0.418472f, 0.422401f, 0.426331f,
		0.43026f, 0.434189f, 0.438118f, 0.442047f, 0.445977f, 0.449906f,
		0.453835f, 0.457765f, 0.461694f, 0.465623f, 0.469552f, 0.473481f,
		0.477411f, 0.48134f, 0.485269f, 0.489198f, 0.493128f, 0.497057f,
		0.500986f, 0.504915f, 0.508845f, 0.512774f, 0.516703f, 0.520632f,
		0.524562f, 0.528491f, 0.53242f, 0.536349f, 0.540279f, 0.544208f,
		0.548137f, 0.552066f, 0.555996f, 0.559925f, 0.563854f, 0.567783f,
		0.571712f, 0.575642f, 0.579571f, 0.5835f, 0.58743f, 0.591359f,
		0.595288f, 0.599217f, 0.603146f, 0.607076f, 0.611005f, 0.614934f,
		0.618863f, 0.622793f, 0.626722f, 0.630651f, 0.63458f, 0.63851f,
		0.642439f, 0.646368f, 0.650297f, 0.654227f, 0.658156f, 0.662085f,
		0.666014f, 0.669944f, 0.673873f, 0.677802f, 0.681731f, 0.685661f,
		0.68959f, 0.693519f, 0.697448f, 0.701378f, 0.705307f, 0.709236f,
		0.713165f, 0.717095f, 0.721024f, 0.724953f, 0.728882f, 0.732811f,
		0.736741f, 0.74067f, 0.744599f, 0.748528f, 0.752458f, 0.756387f,
		0.760316f, 0.764245f, 0.768175f, 0.772104f, 0.776033f, 0.779962f,
		0.783892f, 0.787821f, 0.79175f, 0.795679f, 0.799609f, 0.803538f,
		0.807467f, 0.811396f, 0.815326f, 0.819255f, 0.823184f, 0.827113f,
		0.831043f, 0.834972f, 0.838901f, 0.84283f, 0.84676f, 0.850689f,
		0.854618f, 0.858547f, 0.862477f, 0.866406f, 0.870335f, 0.874264f,
		0.878193f, 0.882123f, 0.886052f, 0.889981f, 0.893911f, 0.89784f,
		0.901769f, 0.905698f, 0.909627f, 0.913557f, 0.917486f, 0.921415f,
		0.925344f, 0.929274f, 0.933203f, 0.937132f, 0.941061f, 0.944991f,
		0.94892f, 0.952849f, 0.956778f, 0.960708f, 0.964637f, 0.968566f,
		0.972495f, 0.976425f, 0.980354f, 0.984283f, 0.988212f, 0.992142f,
		0.996071f, 1.f
	};
};

template <int NV>
using cable_table2_t = wrap::data<control::cable_table<cable_table2_mod<NV>>, 
                                  data::embedded::table<cable_table2_t_data>>;

DECLARE_PARAMETER_RANGE(cable_table3_modRange, 
                        1., 
                        20.);

template <int NV>
using cable_table3_mod = parameter::from0To1<project::granul<NV>, 
                                             1, 
                                             cable_table3_modRange>;

struct cable_table3_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00400782f, 0.00801563f, 0.0120235f, 0.0160313f, 0.0200391f,
		0.024047f, 0.0280548f, 0.0320626f, 0.0360705f, 0.0400783f, 0.0440861f,
		0.0480939f, 0.0521017f, 0.0561096f, 0.0601174f, 0.0641252f, 0.0681331f,
		0.0721409f, 0.0761487f, 0.0801566f, 0.0841644f, 0.0881722f, 0.09218f,
		0.0961879f, 0.100196f, 0.104204f, 0.108211f, 0.112219f, 0.116227f,
		0.120235f, 0.124243f, 0.12825f, 0.132258f, 0.136266f, 0.140274f,
		0.144282f, 0.14829f, 0.152297f, 0.156305f, 0.160313f, 0.164321f,
		0.168329f, 0.172337f, 0.176344f, 0.180352f, 0.18436f, 0.188368f,
		0.192376f, 0.196384f, 0.200391f, 0.204399f, 0.208407f, 0.212415f,
		0.216423f, 0.22043f, 0.224438f, 0.228446f, 0.232454f, 0.236462f,
		0.24047f, 0.244478f, 0.248485f, 0.252493f, 0.256501f, 0.260509f,
		0.264517f, 0.268524f, 0.272532f, 0.27654f, 0.280548f, 0.284556f,
		0.288564f, 0.292571f, 0.296579f, 0.300587f, 0.304595f, 0.308603f,
		0.312611f, 0.316618f, 0.320626f, 0.324634f, 0.328642f, 0.33265f,
		0.336658f, 0.340665f, 0.344673f, 0.348681f, 0.352689f, 0.356697f,
		0.360705f, 0.364712f, 0.36872f, 0.372728f, 0.376736f, 0.380744f,
		0.384751f, 0.388759f, 0.392767f, 0.396775f, 0.400783f, 0.404791f,
		0.408798f, 0.412806f, 0.416814f, 0.420822f, 0.42483f, 0.428838f,
		0.432845f, 0.436853f, 0.440861f, 0.444869f, 0.448877f, 0.452885f,
		0.456892f, 0.4609f, 0.464908f, 0.468916f, 0.472924f, 0.476932f,
		0.480939f, 0.484947f, 0.488955f, 0.492963f, 0.496971f, 0.500978f,
		0.504986f, 0.508994f, 0.513002f, 0.51701f, 0.521018f, 0.525025f,
		0.529033f, 0.533041f, 0.537049f, 0.541057f, 0.545065f, 0.549072f,
		0.55308f, 0.557088f, 0.561096f, 0.565104f, 0.569112f, 0.573119f,
		0.577127f, 0.581135f, 0.585143f, 0.589151f, 0.593159f, 0.597166f,
		0.601174f, 0.605182f, 0.60919f, 0.613198f, 0.617206f, 0.621213f,
		0.625221f, 0.629229f, 0.633237f, 0.637245f, 0.641253f, 0.64526f,
		0.649268f, 0.653276f, 0.657284f, 0.661292f, 0.665299f, 0.669307f,
		0.673315f, 0.677323f, 0.681331f, 0.685339f, 0.689346f, 0.693354f,
		0.697362f, 0.70137f, 0.705378f, 0.709386f, 0.713393f, 0.717401f,
		0.721409f, 0.725417f, 0.729425f, 0.733433f, 0.73744f, 0.741448f,
		0.745456f, 0.749464f, 0.753472f, 0.757479f, 0.761487f, 0.765495f,
		0.769503f, 0.773511f, 0.777519f, 0.781526f, 0.785534f, 0.789542f,
		0.79355f, 0.797558f, 0.801566f, 0.805573f, 0.809581f, 0.813589f,
		0.817597f, 0.821605f, 0.825613f, 0.82962f, 0.833628f, 0.837636f,
		0.841644f, 0.845652f, 0.84966f, 0.853667f, 0.857675f, 0.861683f,
		0.865691f, 0.869699f, 0.873707f, 0.877714f, 0.881722f, 0.88573f,
		0.889738f, 0.893746f, 0.897753f, 0.901761f, 0.905769f, 0.909777f,
		0.913785f, 0.917793f, 0.9218f, 0.925808f, 0.929816f, 0.933824f,
		0.937832f, 0.94184f, 0.945847f, 0.949855f, 0.953863f, 0.957871f,
		0.961879f, 0.965887f, 0.969894f, 0.973902f, 0.97791f, 0.981918f,
		0.985926f, 0.989933f, 0.993941f, 0.997949f, 0.996564f, 0.989528f,
		0.982492f, 0.975456f, 0.968419f, 0.961383f, 0.954347f, 0.947311f,
		0.940275f, 0.933239f, 0.926202f, 0.919166f, 0.91213f, 0.905094f,
		0.898057f, 0.891021f, 0.883985f, 0.876949f, 0.869912f, 0.862876f,
		0.85584f, 0.848804f, 0.841768f, 0.834731f, 0.827695f, 0.820659f,
		0.813623f, 0.806587f, 0.79955f, 0.792514f, 0.785478f, 0.778442f,
		0.771406f, 0.764369f, 0.757333f, 0.750297f, 0.743261f, 0.736224f,
		0.729188f, 0.722152f, 0.715116f, 0.70808f, 0.701043f, 0.694007f,
		0.686971f, 0.679935f, 0.672899f, 0.665862f, 0.658826f, 0.65179f,
		0.644754f, 0.637717f, 0.630681f, 0.623645f, 0.616609f, 0.609573f,
		0.602536f, 0.5955f, 0.588464f, 0.581428f, 0.574391f, 0.567355f,
		0.560319f, 0.553283f, 0.546247f, 0.53921f, 0.532174f, 0.525138f,
		0.518102f, 0.511065f, 0.504029f, 0.496993f, 0.494382f, 0.494382f,
		0.494382f, 0.494382f, 0.494382f, 0.494382f, 0.494382f, 0.494382f,
		0.494382f, 0.494382f, 0.494382f, 0.494382f, 0.494382f, 0.494382f,
		0.494382f, 0.494382f, 0.494382f, 0.494382f, 0.494382f, 0.494382f,
		0.494382f, 0.494382f, 0.494382f, 0.494382f, 0.494382f, 0.494382f,
		0.494382f, 0.494382f, 0.494382f, 0.494382f, 0.494382f, 0.494382f,
		0.494382f, 0.494382f, 0.494382f, 0.494382f, 0.494382f, 0.494382f,
		0.494382f, 0.494382f, 0.494382f, 0.494382f, 0.494382f, 0.494382f,
		0.494382f, 0.494382f, 0.494382f, 0.494382f, 0.494382f, 0.494382f,
		0.494382f, 0.494382f, 0.494382f, 0.494382f, 0.494382f, 0.494382f,
		0.494382f, 0.494382f, 0.494382f, 0.494382f, 0.494382f, 0.494382f,
		0.494382f, 0.447823f, 0.385904f, 0.323986f, 0.262065f, 0.200147f,
		0.138228f, 0.0763099f, 0.0143914f, 0.00646281f, 0.0148826f, 0.0233024f,
		0.0317224f, 0.0401422f, 0.0485619f, 0.0569817f, 0.0654015f, 0.0738212f,
		0.082241f, 0.0906608f, 0.0990809f, 0.107501f, 0.11592f, 0.12434f,
		0.13276f, 0.14118f, 0.149599f, 0.158019f, 0.166439f, 0.174859f,
		0.183279f, 0.191699f, 0.200118f, 0.208538f, 0.216958f, 0.225378f,
		0.233798f, 0.242218f, 0.250637f, 0.259057f, 0.267477f, 0.275897f,
		0.284316f, 0.292736f, 0.301156f, 0.309576f, 0.317996f, 0.326416f,
		0.334835f, 0.343255f, 0.351675f, 0.360095f, 0.368515f, 0.376934f,
		0.385354f, 0.393774f, 0.402194f, 0.410614f, 0.419033f, 0.427453f,
		0.435873f, 0.444293f, 0.452713f, 0.461132f, 0.469552f, 0.477972f,
		0.486392f, 0.494812f, 0.503232f, 0.511651f, 0.520071f, 0.528491f,
		0.536911f, 0.54533f, 0.55375f, 0.56217f, 0.57059f, 0.57901f,
		0.58743f, 0.595849f, 0.604269f, 0.612689f, 0.621109f, 0.629528f,
		0.637948f, 0.646368f, 0.654788f, 0.663208f, 0.671628f, 0.680047f,
		0.688467f, 0.696887f, 0.705307f, 0.713727f, 0.722146f, 0.730566f,
		0.738986f, 0.747406f, 0.755826f, 0.764245f, 0.772665f, 0.781085f,
		0.789505f, 0.797925f, 0.806344f, 0.814764f, 0.823184f, 0.831604f,
		0.840024f, 0.848444f, 0.856863f, 0.865283f, 0.873703f, 0.882123f,
		0.890542f, 0.898962f, 0.907382f, 0.915802f, 0.924222f, 0.932642f,
		0.941061f, 0.949481f, 0.957901f, 0.966321f, 0.974741f, 0.98316f,
		0.99158f, 1.f
	};
};

template <int NV>
using cable_table3_t = wrap::data<control::cable_table<cable_table3_mod<NV>>, 
                                  data::embedded::table<cable_table3_t_data>>;

template <int NV>
using tempo_sync2_t = wrap::mod<parameter::plain<core::fix_delay, 0>, 
                                control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(pma1_mod_0Range, 
                             1., 
                             1024., 
                             1.);

template <int NV>
using pma1_mod_0 = parameter::from0To1<fx::sampleandhold<NV>, 
                                       0, 
                                       pma1_mod_0Range>;

DECLARE_PARAMETER_RANGE(pma1_mod_1Range, 
                        0.01, 
                        1.);

template <int NV>
using pma1_mod_1 = parameter::from0To1<math::tanh<NV>, 
                                       0, 
                                       pma1_mod_1Range>;

DECLARE_PARAMETER_RANGE_STEP(pma1_mod_2Range, 
                             1, 
                             5., 
                             0.1);

template <int NV>
using pma1_mod_2 = parameter::from0To1<fx::bitcrush<NV>, 
                                       0, 
                                       pma1_mod_2Range>;

DECLARE_PARAMETER_RANGE_STEP(pma1_mod_6Range, 
                             0., 
                             18., 
                             1.);

template <int NV>
using pma1_mod_6 = parameter::from0To1<tempo_sync2_t<NV>, 
                                       0, 
                                       pma1_mod_6Range>;

template <int NV>
using pma1_mod = parameter::chain<ranges::Identity, 
                                  pma1_mod_0<NV>, 
                                  pma1_mod_1<NV>, 
                                  pma1_mod_2<NV>, 
                                  parameter::plain<xfader1_t<NV>, 0>, 
                                  parameter::plain<cable_table2_t<NV>, 0>, 
                                  parameter::plain<cable_table3_t<NV>, 0>, 
                                  pma1_mod_6<NV>>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;
DECLARE_PARAMETER_RANGE(peak_modRange, 
                        5.55112e-17, 
                        1.);

template <int NV>
using peak_mod = parameter::from0To1<pma1_t<NV>, 
                                     2, 
                                     peak_modRange>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch3_t<NV>>, 
                                   peak_t<NV>, 
                                   pma1_t<NV>>;
template <int NV> using branch5_t = branch3_t<NV>;

template <int NV>
using smoothed_parameter_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                       control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
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

DECLARE_PARAMETER_RANGE_SKEW(pma3_mod_4Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma3_mod_4 = parameter::from0To1<project::res1<NV>, 
                                       4, 
                                       pma3_mod_4Range>;

template <int NV> using pma3_mod_5 = pma3_mod_3<NV>;

template <int NV>
using pma3_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<smoothed_parameter_t<NV>, 0>, 
                                  pma3_mod_1<NV>, 
                                  parameter::plain<project::res1<NV>, 7>, 
                                  pma3_mod_3<NV>, 
                                  pma3_mod_4<NV>, 
                                  pma3_mod_5<NV>>;

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
                                   smoothed_parameter_t<NV>>;
template <int NV> using branch6_t = branch3_t<NV>;

template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<project::PitchShifter<NV>, 0>>;
template <int NV>
using pma4_t = control::pma<NV, 
                            parameter::plain<minmax_t<NV>, 0>>;
template <int NV>
using peak4_mod = parameter::from0To1<pma4_t<NV>, 
                                      2, 
                                      peak_modRange>;

template <int NV>
using peak4_t = wrap::mod<peak4_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch6_t<NV>>, 
                                   peak4_t<NV>, 
                                   pma4_t<NV>>;
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

template <int NV> using pma2_mod = xfader1_c0<NV>;

template <int NV>
using pma2_t = control::pma<NV, pma2_mod<NV>>;

template <int NV>
using comp_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<math::add<NV>, 0>, 
                                  parameter::plain<pma2_t<NV>, 0>, 
                                  parameter::plain<math::add<NV>, 0>>;

template <int NV>
using comp_t = wrap::mod<comp_mod<NV>, 
                         wrap::no_data<dynamics::comp>>;
DECLARE_PARAMETER_RANGE_SKEW(pma7_modRange, 
                             0., 
                             250., 
                             0.430677);

template <int NV>
using pma7_mod = parameter::from0To1<comp_t<NV>, 
                                     2, 
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

template <int NV>
using tempo_sync1_mod = parameter::chain<ranges::Identity, 
                                         parameter::plain<project::PitchShifter<NV>, 1>, 
                                         parameter::plain<project::PitchShifter<NV>, 2>>;

template <int NV>
using tempo_sync1_t = wrap::mod<tempo_sync1_mod<NV>, 
                                control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(pma8_modRange, 
                             1., 
                             32., 
                             1.);

template <int NV>
using pma8_mod = parameter::from0To1<tempo_sync1_t<NV>, 
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
                                   chain31_t<NV>, 
                                   chain32_t<NV>, 
                                   chain33_t<NV>, 
                                   chain34_t<NV>, 
                                   chain35_t<NV>>;

template <int NV>
using modchain2_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split16_t<NV>>>;

template <int NV>
using modchain2_t = wrap::control_rate<modchain2_t_<NV>>;

using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::empty>>;
using stereo_cable = cable::block<2>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<2, tempo_sync2_t<NV>>, 
                                   routing::receive<stereo_cable>, 
                                   core::fix_delay, 
                                   routing::send<stereo_cable>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::abs<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain15_t<NV>>, 
                                  chain16_t<NV>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfader1_t<NV>>, 
                                   split8_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, cable_table2_t<NV>>, 
                                  cable_table3_t<NV>, 
                                  project::granul<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain18_t>, 
                                    fx::sampleandhold<NV>, 
                                    chain10_t<NV>, 
                                    math::tanh<NV>, 
                                    fx::bitcrush<NV>, 
                                    chain17_t<NV>, 
                                    chain1_t<NV>>;

template <int NV>
using chain431_t = container::chain<parameter::empty, 
                                    wrap::fix<2, modchain2_t<NV>>, 
                                    branch1_t<NV>>;

template <int NV> using xfader_c0 = xfader1_c0<NV>;

template <int NV> using xfader_c1 = xfader1_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::overlap>;

template <int NV> using chain11_t = chain15_t<NV>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::clear<NV>>, 
                                   math::add<NV>, 
                                   pma2_t<NV>, 
                                   core::gain<NV>, 
                                   core::gain<NV>>;
using peak1_t = wrap::no_data<core::peak>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain13_t<NV>>, 
                                   peak1_t>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<2, comp_t<NV>>, 
                                   chain21_t<NV>, 
                                   wrap::no_process<math::clear<NV>>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain11_t<NV>>, 
                                  chain12_t<NV>>;

template <int NV>
using ramp_t = wrap::no_data<core::ramp<NV, false>>;

template <int NV>
using tempo_sync_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<ramp_t<NV>, 0>, 
                                        parameter::plain<project::res1<NV>, 1>, 
                                        parameter::plain<project::res1<NV>, 1>, 
                                        parameter::plain<project::res1<NV>, 1>>;

template <int NV>
using tempo_sync_t = wrap::mod<tempo_sync_mod<NV>, 
                               control::tempo_sync<NV>>;
template <int NV>
using converter6_t = control::converter<parameter::plain<tempo_sync_t<NV>, 3>, 
                                        conversion_logic::freq2ms>;

template <int NV>
using converter2_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<converter6_t<NV>, 0>, 
                                        parameter::plain<filters::allpass<NV>, 0>, 
                                        parameter::plain<project::res1<NV>, 5>>;

template <int NV>
using converter2_t = control::converter<converter2_mod<NV>, 
                                        conversion_logic::midi2freq>;
template <int NV>
using pma9_t = control::pma<NV, 
                            parameter::plain<converter2_t<NV>, 0>>;

template <int NV>
using minmax1_mod = parameter::chain<ranges::Identity, 
                                     parameter::plain<control::pma<NV, parameter::empty>, 0>, 
                                     parameter::plain<pma9_t<NV>, 0>>;

template <int NV>
using minmax1_t = control::minmax<NV, minmax1_mod<NV>>;

template <int NV>
using peak3_t = wrap::mod<parameter::plain<ramp_t<NV>, 2>, 
                          wrap::data<core::peak, data::external::displaybuffer<0>>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, minmax1_t<NV>>, 
                                     pma9_t<NV>, 
                                     converter2_t<NV>, 
                                     converter6_t<NV>, 
                                     tempo_sync_t<NV>, 
                                     control::pma<NV, parameter::empty>, 
                                     math::clear<NV>, 
                                     math::add<NV>, 
                                     math::pi<NV>, 
                                     wrap::no_process<math::rect<NV>>, 
                                     wrap::no_process<math::sin<NV>>, 
                                     peak3_t<NV>, 
                                     math::clear<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>, 
                                  filters::one_pole<NV>, 
                                  minmax_t<NV>, 
                                  routing::receive<stereo_cable>, 
                                  project::PitchShifter<NV>, 
                                  routing::send<stereo_cable>, 
                                  modchain_t<NV>>;

template <int NV>
using pma10_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<project::res1<NV>, 0>, 
                                   parameter::plain<project::res1<NV>, 0>, 
                                   parameter::plain<project::res1<NV>, 0>>;

template <int NV>
using pma10_t = control::pma<NV, pma10_mod<NV>>;
template <int NV>
using smoothed_parameter_unscaled_t = wrap::mod<parameter::plain<pma10_t<NV>, 1>, 
                                                control::smoothed_parameter_unscaled<NV, smoothers::linear_ramp<NV>>>;

struct cable_table1_t_data
{
	span<float, 512> data =
	{
		1.f, 0.979961f, 0.959922f, 0.939883f, 0.919843f, 0.899804f,
		0.879765f, 0.859726f, 0.839687f, 0.819648f, 0.799609f, 0.77957f,
		0.75953f, 0.739491f, 0.719452f, 0.699413f, 0.679374f, 0.659335f,
		0.639296f, 0.619256f, 0.599217f, 0.579178f, 0.559139f, 0.5391f,
		0.519061f, 0.499022f, 0.478982f, 0.458943f, 0.438904f, 0.418865f,
		0.398826f, 0.378787f, 0.358748f, 0.338708f, 0.318669f, 0.29863f,
		0.278591f, 0.258552f, 0.238513f, 0.218474f, 0.198434f, 0.178395f,
		0.158356f, 0.138317f, 0.118278f, 0.0982388f, 0.0781996f, 0.0581605f,
		0.0381213f, 0.0180823f, 0.00184619f, 0.020751f, 0.0396559f, 0.0585607f,
		0.0774655f, 0.0963704f, 0.115275f, 0.13418f, 0.153085f, 0.17199f,
		0.190895f, 0.2098f, 0.228704f, 0.247609f, 0.266514f, 0.285419f,
		0.304324f, 0.323229f, 0.342133f, 0.361038f, 0.379943f, 0.398848f,
		0.417753f, 0.436658f, 0.455563f, 0.474467f, 0.493372f, 0.512277f,
		0.531182f, 0.550087f, 0.568992f, 0.587897f, 0.606801f, 0.625706f,
		0.644611f, 0.663516f, 0.682421f, 0.701326f, 0.72023f, 0.739135f,
		0.75804f, 0.776945f, 0.79585f, 0.814755f, 0.833659f, 0.852564f,
		0.871469f, 0.890374f, 0.909279f, 0.928184f, 0.947089f, 0.965993f,
		0.984898f, 0.995419f, 0.972647f, 0.949875f, 0.927104f, 0.904332f,
		0.88156f, 0.858788f, 0.836017f, 0.813245f, 0.790473f, 0.767701f,
		0.74493f, 0.722158f, 0.699386f, 0.676614f, 0.653843f, 0.631071f,
		0.608299f, 0.585527f, 0.562756f, 0.539984f, 0.517212f, 0.49444f,
		0.471669f, 0.448897f, 0.426125f, 0.403354f, 0.380582f, 0.35781f,
		0.335038f, 0.312267f, 0.289495f, 0.266723f, 0.243951f, 0.22118f,
		0.198408f, 0.175636f, 0.152864f, 0.130093f, 0.107321f, 0.084549f,
		0.0617773f, 0.0390056f, 0.0162336f, 0.00487584f, 0.0218581f, 0.0388404f,
		0.0558228f, 0.0728051f, 0.0897874f, 0.10677f, 0.123752f, 0.140734f,
		0.157717f, 0.174699f, 0.191681f, 0.208664f, 0.225646f, 0.242628f,
		0.259611f, 0.276593f, 0.293575f, 0.310557f, 0.32754f, 0.344522f,
		0.361505f, 0.378487f, 0.395469f, 0.412452f, 0.429434f, 0.446416f,
		0.463399f, 0.480381f, 0.497363f, 0.514345f, 0.531328f, 0.54831f,
		0.565292f, 0.582275f, 0.599257f, 0.616239f, 0.633222f, 0.650204f,
		0.667186f, 0.684169f, 0.701151f, 0.718133f, 0.735116f, 0.752098f,
		0.76908f, 0.786062f, 0.803045f, 0.820027f, 0.837009f, 0.853992f,
		0.870974f, 0.887957f, 0.904939f, 0.921921f, 0.938904f, 0.955886f,
		0.972868f, 0.98985f, 0.990402f, 0.966545f, 0.942689f, 0.918833f,
		0.894977f, 0.871121f, 0.847265f, 0.823409f, 0.799553f, 0.775697f,
		0.75184f, 0.727984f, 0.704128f, 0.680272f, 0.656416f, 0.63256f,
		0.608704f, 0.584848f, 0.560992f, 0.537136f, 0.513279f, 0.489423f,
		0.465567f, 0.441711f, 0.417855f, 0.393999f, 0.370143f, 0.346287f,
		0.32243f, 0.298574f, 0.274718f, 0.250862f, 0.227006f, 0.20315f,
		0.179294f, 0.155438f, 0.131581f, 0.107725f, 0.0838692f, 0.0600132f,
		0.0361568f, 0.0123007f, 0.0082258f, 0.0252081f, 0.0421906f, 0.0591728f,
		0.0761551f, 0.0931373f, 0.11012f, 0.127102f, 0.144084f, 0.161067f,
		0.178049f, 0.195031f, 0.212014f, 0.228996f, 0.245978f, 0.262961f,
		0.279943f, 0.296925f, 0.313907f, 0.33089f, 0.347872f, 0.364855f,
		0.381837f, 0.398819f, 0.415801f, 0.432784f, 0.449766f, 0.466748f,
		0.483731f, 0.500713f, 0.517696f, 0.534678f, 0.55166f, 0.568642f,
		0.585625f, 0.602607f, 0.61959f, 0.636572f, 0.653554f, 0.670536f,
		0.687519f, 0.704501f, 0.721483f, 0.738465f, 0.755448f, 0.77243f,
		0.789413f, 0.806395f, 0.823377f, 0.840359f, 0.857342f, 0.874324f,
		0.891307f, 0.908289f, 0.925271f, 0.942253f, 0.959236f, 0.976218f,
		0.9932f, 0.98694f, 0.965158f, 0.943376f, 0.921594f, 0.899813f,
		0.878031f, 0.85625f, 0.834468f, 0.812686f, 0.790904f, 0.769123f,
		0.747341f, 0.725559f, 0.703778f, 0.681996f, 0.660215f, 0.638433f,
		0.616651f, 0.594869f, 0.573088f, 0.551306f, 0.529524f, 0.507743f,
		0.485961f, 0.46418f, 0.442397f, 0.420616f, 0.398834f, 0.377053f,
		0.355271f, 0.333489f, 0.311708f, 0.289926f, 0.268144f, 0.246362f,
		0.224581f, 0.202799f, 0.181018f, 0.159236f, 0.137454f, 0.115673f,
		0.0938906f, 0.072109f, 0.0503275f, 0.0285458f, 0.00676423f, 0.0132846f,
		0.0325528f, 0.0518212f, 0.0710901f, 0.0903584f, 0.109627f, 0.128895f,
		0.148163f, 0.167432f, 0.1867f, 0.205968f, 0.225237f, 0.244506f,
		0.263774f, 0.283042f, 0.302311f, 0.321579f, 0.340847f, 0.360116f,
		0.379385f, 0.398653f, 0.417921f, 0.43719f, 0.456458f, 0.475726f,
		0.494995f, 0.514263f, 0.533532f, 0.5528f, 0.572068f, 0.591337f,
		0.610605f, 0.629873f, 0.649142f, 0.66841f, 0.687679f, 0.706947f,
		0.726216f, 0.745484f, 0.764752f, 0.784021f, 0.803289f, 0.822557f,
		0.841826f, 0.861095f, 0.880363f, 0.899631f, 0.9189f, 0.938168f,
		0.957436f, 0.976705f, 0.995973f, 0.980669f, 0.956231f, 0.931793f,
		0.907355f, 0.882917f, 0.85848f, 0.834042f, 0.809603f, 0.785165f,
		0.760727f, 0.736289f, 0.711852f, 0.687414f, 0.662976f, 0.638538f,
		0.614099f, 0.589661f, 0.565223f, 0.540786f, 0.516348f, 0.49191f,
		0.467472f, 0.443034f, 0.418595f, 0.394158f, 0.36972f, 0.345282f,
		0.320844f, 0.296406f, 0.271968f, 0.24753f, 0.223092f, 0.198654f,
		0.174216f, 0.149778f, 0.12534f, 0.100902f, 0.0764644f, 0.0520265f,
		0.0275878f, 0.00314999f, 0.0132243f, 0.0284054f, 0.0435865f, 0.0587676f,
		0.0739487f, 0.0891298f, 0.104311f, 0.119492f, 0.134674f, 0.149855f,
		0.165036f, 0.180217f, 0.195398f, 0.210579f, 0.225761f, 0.240942f,
		0.256123f, 0.271304f, 0.286485f, 0.301666f, 0.316847f, 0.332028f,
		0.34721f, 0.362391f, 0.377572f, 0.392753f, 0.407934f, 0.423116f,
		0.438297f, 0.453478f, 0.468659f, 0.48384f, 0.499022f, 0.514203f,
		0.529384f, 0.544565f, 0.559746f, 0.574927f, 0.590109f, 0.60529f,
		0.620471f, 0.635652f, 0.650833f, 0.666014f, 0.681195f, 0.696376f,
		0.711558f, 0.726739f, 0.74192f, 0.757101f, 0.772282f, 0.787464f,
		0.802645f, 0.817826f, 0.833007f, 0.848188f, 0.86337f, 0.878551f,
		0.893732f, 0.908913f, 0.924094f, 0.939275f, 0.954457f, 0.969638f,
		0.984819f, 1.f
	};
};

template <int NV>
using cable_table1_t = wrap::data<control::cable_table<parameter::plain<smoothed_parameter_unscaled_t<NV>, 0>>, 
                                  data::embedded::table<cable_table1_t_data>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, filters::allpass<NV>>, 
                                  filters::one_pole<NV>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, project::res1<NV>>>;

template <int NV> using chain8_t = chain5_t<NV>;

template <int NV> using chain7_t = chain5_t<NV>;

using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, core::empty>>;

using multi_t = container::multi<parameter::empty, 
                                 wrap::fix<2, core::empty>>;
template <int NV>
using file_player_t = wrap::data<core::file_player<NV>, 
                                 data::external::audiofile<0>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, multi_t>, 
                                  math::add<NV>, 
                                  file_player_t<NV>, 
                                  filters::one_pole<NV>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   split1_t, 
                                   ramp_t<NV>, 
                                   chain2_t<NV>>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, chain22_t<NV>>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain4_t<NV>>, 
                                   chain5_t<NV>, 
                                   chain8_t<NV>, 
                                   chain7_t<NV>, 
                                   fix8_block_t<NV>>;

namespace ResStage_t_parameters
{
// Parameter list for ResStage_impl::ResStage_t ----------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(ModifierMode_InputRange, 
                             1., 
                             7., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(ModifierMode_0Range, 
                             0., 
                             6., 
                             1.);

template <int NV>
using ModifierMode_0 = parameter::from0To1<ResStage_impl::branch1_t<NV>, 
                                           0, 
                                           ModifierMode_0Range>;

template <int NV>
using ModifierMode = parameter::chain<ModifierMode_InputRange, 
                                      ModifierMode_0<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(CutOffA_InputRange, 
                             0., 
                             1., 
                             0.239104);

template <int NV>
using CutOffA = parameter::chain<CutOffA_InputRange, 
                                 parameter::plain<math::add<NV>, 0>>;

DECLARE_PARAMETER_RANGE_SKEW(CutOffB_InputRange, 
                             0., 
                             1., 
                             0.239104);

template <int NV>
using CutOffB = parameter::chain<CutOffB_InputRange, 
                                 parameter::plain<math::add<NV>, 0>>;

DECLARE_PARAMETER_RANGE_SKEW(CompRel_InputRange, 
                             0., 
                             250., 
                             0.430677);

template <int NV>
using CompRel = parameter::chain<CompRel_InputRange, 
                                 parameter::plain<math::add<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(RateWinDiv_InputRange, 
                             1., 
                             32., 
                             1.);

template <int NV>
using RateWinDiv = parameter::chain<RateWinDiv_InputRange, 
                                    parameter::plain<math::add<NV>, 0>>;

DECLARE_PARAMETER_RANGE_SKEW(ResStep_InputRange, 
                             0., 
                             1., 
                             0.507273);
DECLARE_PARAMETER_RANGE_SKEW(ResStep_0Range, 
                             0., 
                             0.5, 
                             0.507273);

template <int NV>
using ResStep_0 = parameter::from0To1<ResStage_impl::minmax1_t<NV>, 
                                      4, 
                                      ResStep_0Range>;

template <int NV>
using ResStep = parameter::chain<ResStep_InputRange, ResStep_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(ResMode_InputRange, 
                             0., 
                             5., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(ResMode_0Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using ResMode_0 = parameter::from0To1<ResStage_impl::branch_t<NV>, 
                                      0, 
                                      ResMode_0Range>;

template <int NV>
using ResMode = parameter::chain<ResMode_InputRange, 
                                 ResMode_0<NV>, 
                                 parameter::plain<ResStage_impl::cable_table1_t<NV>, 0>>;

template <int NV>
using ResLP = parameter::chain<ranges::Identity, 
                               parameter::plain<filters::one_pole<NV>, 0>, 
                               parameter::plain<project::res1<NV>, 3>, 
                               parameter::plain<project::res1<NV>, 3>, 
                               parameter::plain<project::res1<NV>, 3>, 
                               parameter::plain<filters::one_pole<NV>, 0>>;

DECLARE_PARAMETER_RANGE_SKEW(ResFeed_1Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using ResFeed_1 = parameter::from0To1<filters::allpass<NV>, 
                                      1, 
                                      ResFeed_1Range>;

template <int NV>
using ResFeed = parameter::chain<ranges::Identity, 
                                 parameter::plain<ResStage_impl::pma10_t<NV>, 0>, 
                                 ResFeed_1<NV>>;

DECLARE_PARAMETER_RANGE_STEP(PostMode_InputRange, 
                             1., 
                             13., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(PostMode_0Range, 
                             1., 
                             12., 
                             1.);

template <int NV>
using PostMode_0 = parameter::from0To1<project::FilterForRes<NV>, 
                                       2, 
                                       PostMode_0Range>;

template <int NV>
using PostMode = parameter::chain<PostMode_InputRange, PostMode_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Fmode1_InputRange, 
                             1., 
                             11., 
                             1.);

template <int NV>
using Fmode1 = parameter::chain<Fmode1_InputRange, 
                                parameter::plain<math::add<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(FilterModShape_InputRange, 
                             1., 
                             3., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(FilterModShape_0Range, 
                             1., 
                             2., 
                             1.);

template <int NV>
using FilterModShape_0 = parameter::from0To1<ResStage_impl::branch7_t<NV>, 
                                             0, 
                                             FilterModShape_0Range>;

template <int NV>
using FilterModShape = parameter::chain<FilterModShape_InputRange, 
                                        FilterModShape_0<NV>>;

DECLARE_PARAMETER_RANGE(PhaseMode_InputRange, 
                        1., 
                        3.);
DECLARE_PARAMETER_RANGE_STEP(PhaseMode_0Range, 
                             0., 
                             2., 
                             1.);

template <int NV>
using PhaseMode_0 = parameter::from0To1<ResStage_impl::branch5_t<NV>, 
                                        0, 
                                        PhaseMode_0Range>;

template <int NV>
using PhaseMode = parameter::chain<PhaseMode_InputRange, PhaseMode_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(ModMode_InputRange, 
                             1., 
                             3., 
                             1.);
template <int NV>
using ModMode_0 = parameter::from0To1<ResStage_impl::branch3_t<NV>, 
                                      0, 
                                      PhaseMode_0Range>;

template <int NV>
using ModMode = parameter::chain<ModMode_InputRange, ModMode_0<NV>>;

DECLARE_PARAMETER_RANGE(ratemode_InputRange, 
                        1., 
                        3.);
template <int NV>
using ratemode_0 = parameter::from0To1<ResStage_impl::branch6_t<NV>, 
                                       0, 
                                       PhaseMode_0Range>;

template <int NV>
using ratemode = parameter::chain<ratemode_InputRange, ratemode_0<NV>>;

DECLARE_PARAMETER_RANGE(Fmode2_InputRange, 
                        1., 
                        11.);

template <int NV>
using Fmode2 = parameter::chain<Fmode2_InputRange, 
                                parameter::plain<math::add<NV>, 0>>;

DECLARE_PARAMETER_RANGE(Fmode3_InputRange, 
                        1., 
                        11.);

template <int NV>
using Fmode3 = parameter::chain<Fmode3_InputRange, 
                                parameter::plain<math::add<NV>, 0>>;

DECLARE_PARAMETER_RANGE(FmodeShape_InputRange, 
                        1., 
                        3.);
template <int NV>
using FmodeShape_0 = parameter::from0To1<ResStage_impl::branch8_t<NV>, 
                                         0, 
                                         PhaseMode_0Range>;

template <int NV>
using FmodeShape = parameter::chain<FmodeShape_InputRange, FmodeShape_0<NV>>;

DECLARE_PARAMETER_RANGE(CmpRel2_InputRange, 
                        0., 
                        250.);

template <int NV>
using CmpRel2 = parameter::chain<CmpRel2_InputRange, 
                                 parameter::plain<math::add<NV>, 0>>;

DECLARE_PARAMETER_RANGE(CpmRel3_InputRange, 
                        0., 
                        250.);

template <int NV>
using CpmRel3 = parameter::chain<CpmRel3_InputRange, 
                                 parameter::plain<math::add<NV>, 0>>;

DECLARE_PARAMETER_RANGE(CompRelMode_InputRange, 
                        1., 
                        3.);
template <int NV>
using CompRelMode_0 = parameter::from0To1<ResStage_impl::branch9_t<NV>, 
                                          0, 
                                          PhaseMode_0Range>;

template <int NV>
using CompRelMode = parameter::chain<CompRelMode_InputRange, CompRelMode_0<NV>>;

template <int NV>
using SampleSigIn = parameter::from0To1<core::gain<NV>, 
                                        0, 
                                        ResStage_impl::xfader1_c0Range>;

DECLARE_PARAMETER_RANGE(RateDiv2_InputRange, 
                        1., 
                        32.);

template <int NV>
using RateDiv2 = parameter::chain<RateDiv2_InputRange, 
                                  parameter::plain<math::add<NV>, 0>>;

DECLARE_PARAMETER_RANGE(RateDiv3_InputRange, 
                        1., 
                        32.);

template <int NV>
using RateDiv3 = parameter::chain<RateDiv3_InputRange, 
                                  parameter::plain<math::add<NV>, 0>>;

DECLARE_PARAMETER_RANGE(RateDivMode_InputRange, 
                        1., 
                        3.);
template <int NV>
using RateDivMode_0 = parameter::from0To1<ResStage_impl::branch10_t<NV>, 
                                          0, 
                                          PhaseMode_0Range>;

template <int NV>
using RateDivMode = parameter::chain<RateDivMode_InputRange, RateDivMode_0<NV>>;

template <int NV>
using qA = parameter::plain<project::FilterForRes<NV>, 
                            1>;
template <int NV>
using CutOffC = parameter::plain<math::add<NV>, 0>;
template <int NV>
using CompThresh = parameter::plain<ResStage_impl::comp_t<NV>, 
                                    0>;
template <int NV>
using CompAtk = parameter::plain<ResStage_impl::comp_t<NV>, 
                                 1>;
template <int NV>
using CompRatio = parameter::plain<ResStage_impl::comp_t<NV>, 
                                   3>;
template <int NV>
using InputTrig = parameter::plain<ResStage_impl::xfader_t<NV>, 
                                   0>;
template <int NV>
using InputHP = parameter::plain<filters::one_pole<NV>, 0>;
template <int NV> using Rate = CutOffC<NV>;
template <int NV>
using RateWin = parameter::plain<ResStage_impl::tempo_sync1_t<NV>, 
                                 0>;
template <int NV>
using ResFreq = parameter::plain<ResStage_impl::minmax1_t<NV>, 
                                 0>;
template <int NV>
using ResMin = parameter::plain<ResStage_impl::minmax1_t<NV>, 
                                1>;
template <int NV>
using ResMax = parameter::plain<ResStage_impl::minmax1_t<NV>, 
                                2>;
template <int NV>
using PostCut = parameter::plain<project::FilterForRes<NV>, 
                                 0>;
template <int NV> using PostRes = qA<NV>;
using Fb = parameter::plain<routing::receive<stereo_cable>, 
                            0>;
using Atk = parameter::empty;
using Rel = Atk;
template <int NV>
using SampleSync = parameter::plain<ResStage_impl::tempo_sync_t<NV>, 
                                    2>;
template <int NV> using Phase = CutOffC<NV>;
template <int NV>
using sampletempo = parameter::plain<ResStage_impl::tempo_sync_t<NV>, 
                                     0>;
template <int NV>
using samplediv = parameter::plain<ResStage_impl::tempo_sync_t<NV>, 
                                   1>;
template <int NV> using Phase1 = CutOffC<NV>;
template <int NV> using Phase2 = CutOffC<NV>;
template <int NV> using Mod1 = CutOffC<NV>;
template <int NV> using Mod2 = CutOffC<NV>;
template <int NV> using Mod3 = CutOffC<NV>;
template <int NV>
using PsStep = parameter::plain<ResStage_impl::minmax_t<NV>, 
                                4>;
template <int NV> using rate2 = CutOffC<NV>;
template <int NV> using rate3 = CutOffC<NV>;
template <int NV>
using ResStage_t_plist = parameter::list<ModifierMode<NV>, 
                                         CutOffA<NV>, 
                                         CutOffB<NV>, 
                                         qA<NV>, 
                                         CutOffC<NV>, 
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
                                         Fmode1<NV>, 
                                         FilterModShape<NV>, 
                                         Fb, 
                                         Atk, 
                                         Rel, 
                                         SampleSync<NV>, 
                                         Phase<NV>, 
                                         sampletempo<NV>, 
                                         samplediv<NV>, 
                                         Phase1<NV>, 
                                         Phase2<NV>, 
                                         Mod1<NV>, 
                                         Mod2<NV>, 
                                         Mod3<NV>, 
                                         PhaseMode<NV>, 
                                         ModMode<NV>, 
                                         PsStep<NV>, 
                                         rate2<NV>, 
                                         rate3<NV>, 
                                         ratemode<NV>, 
                                         Fmode2<NV>, 
                                         Fmode3<NV>, 
                                         FmodeShape<NV>, 
                                         CmpRel2<NV>, 
                                         CpmRel3<NV>, 
                                         CompRelMode<NV>, 
                                         SampleSigIn<NV>, 
                                         RateDiv2<NV>, 
                                         RateDiv3<NV>, 
                                         RateDivMode<NV>>;
}

template <int NV>
using ResStage_t_ = container::chain<ResStage_t_parameters::ResStage_t_plist<NV>, 
                                     wrap::fix<2, chain431_t<NV>>, 
                                     xfader_t<NV>, 
                                     split5_t<NV>, 
                                     tempo_sync1_t<NV>, 
                                     chain6_t<NV>, 
                                     project::FilterForRes<NV>, 
                                     cable_table1_t<NV>, 
                                     smoothed_parameter_unscaled_t<NV>, 
                                     pma10_t<NV>, 
                                     branch_t<NV>, 
                                     project::FilterForRes<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public ResStage_impl::ResStage_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 1;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 1;
		
		SNEX_METADATA_ID(ResStage);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(896)
		{
			0x005B, 0x0000, 0x4D00, 0x646F, 0x6669, 0x6569, 0x4D72, 0x646F, 
            0x0065, 0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 0x40A0, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x015B, 0x0000, 0x4300, 0x7475, 0x664F, 
            0x4166, 0x0000, 0x0000, 0x0000, 0x8000, 0x203F, 0x2C91, 0xB53A, 
            0x74D7, 0x003E, 0x0000, 0x5B00, 0x0002, 0x0000, 0x7543, 0x4F74, 
            0x6666, 0x0042, 0x0000, 0x0000, 0x0000, 0x3F80, 0x3099, 0x3C11, 
            0xD7B5, 0x3E74, 0x0000, 0x0000, 0x035B, 0x0000, 0x7100, 0x0041, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x045B, 0x0000, 0x4300, 0x7475, 0x664F, 0x4366, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x7A3F, 0x0753, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0005, 0x0000, 0x6F43, 0x706D, 0x6854, 
            0x6572, 0x6873, 0x0000, 0xC800, 0x00C2, 0x0000, 0x6600, 0xDE66, 
            0x3EC1, 0xAD83, 0xCD40, 0xCCCC, 0x5B3D, 0x0006, 0x0000, 0x6F43, 
            0x706D, 0x7441, 0x006B, 0x0000, 0x0000, 0x0000, 0x437A, 0x0000, 
            0x0000, 0x81A3, 0x3EDC, 0xCCCD, 0x3DCC, 0x075B, 0x0000, 0x4300, 
            0x6D6F, 0x5270, 0x6C65, 0x0000, 0x0000, 0x0000, 0x7A00, 0x3343, 
            0x7533, 0xA342, 0xDC81, 0xCD3E, 0xCCCC, 0x5B3D, 0x0008, 0x0000, 
            0x6F43, 0x706D, 0x6152, 0x6974, 0x006F, 0x0000, 0x3F80, 0x0000, 
            0x4200, 0xCCCD, 0x3F8C, 0xF69D, 0x3E97, 0xCCCD, 0x3DCC, 0x095B, 
            0x0000, 0x4900, 0x706E, 0x7475, 0x7254, 0x6769, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x863F, 0x61AC, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x000A, 0x0000, 0x6E49, 0x7570, 0x4874, 0x0050, 0x0000, 
            0x41A0, 0x4000, 0x469C, 0xE719, 0x41A2, 0x6C1A, 0x3E6B, 0x0000, 
            0x0000, 0x0B5B, 0x0000, 0x5200, 0x7461, 0x0065, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x6783, 0x3F2B, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0C5B, 0x0000, 0x5200, 0x7461, 0x5765, 0x6E69, 0x0000, 0x0000, 
            0x0000, 0x9000, 0x0041, 0x3000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x000D, 0x0000, 0x6152, 0x6574, 0x6957, 0x446E, 0x7669, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 0xF800, 0x0041, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x000E, 0x0000, 0x6552, 0x4673, 0x6572, 
            0x0071, 0x0000, 0x0000, 0x0000, 0x3F80, 0xE42D, 0x3F66, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0F5B, 0x0000, 0x5200, 0x7365, 0x694D, 
            0x006E, 0x0000, 0x2640, 0x0000, 0x3F80, 0x0000, 0x2640, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x105B, 0x0000, 0x5200, 0x7365, 0x614D, 
            0x0078, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x115B, 0x0000, 0x5200, 0x7365, 0x7453, 
            0x7065, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0xA000, 
            0x01DC, 0x003F, 0x0000, 0x5B00, 0x0012, 0x0000, 0x6552, 0x4D73, 
            0x646F, 0x0065, 0x0000, 0x0000, 0x0000, 0x40A0, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x135B, 0x0000, 0x5200, 0x7365, 
            0x504C, 0x0000, 0xA000, 0x0041, 0x9C40, 0x9E46, 0x937E, 0x1A46, 
            0x6B6C, 0x003E, 0x0000, 0x5B00, 0x0014, 0x0000, 0x6552, 0x4673, 
            0x6565, 0x0064, 0x0000, 0x0000, 0x0000, 0x3F80, 0x4DEA, 0x3F72, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x155B, 0x0000, 0x5000, 0x736F, 
            0x4374, 0x7475, 0x0000, 0x0000, 0x0000, 0x8000, 0x913F, 0x0CA8, 
            0xB53F, 0x74D7, 0x003E, 0x0000, 0x5B00, 0x0016, 0x0000, 0x6F50, 
            0x7473, 0x6552, 0x0073, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x175B, 0x0000, 0x5000, 
            0x736F, 0x4D74, 0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 0x4150, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x185B, 0x0000, 
            0x4600, 0x6F6D, 0x6564, 0x0031, 0x0000, 0x3F80, 0x0000, 0x4130, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x195B, 0x0000, 
            0x4600, 0x6C69, 0x6574, 0x4D72, 0x646F, 0x6853, 0x7061, 0x0065, 
            0x0000, 0x3F80, 0x0000, 0x4040, 0x0000, 0x4040, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x1A5B, 0x0000, 0x4600, 0x0062, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x1B5B, 0x0000, 0x4100, 0x6B74, 0x0000, 0x0000, 0x0000, 0x7A00, 
            0xCD44, 0xFFCC, 0x9B42, 0x9A20, 0xCD3E, 0xCCCC, 0x5B3D, 0x001C, 
            0x0000, 0x6552, 0x006C, 0x0000, 0x0000, 0x0000, 0x447A, 0x0000, 
            0x447A, 0x209B, 0x3E9A, 0xCCCD, 0x3DCC, 0x1D5B, 0x0000, 0x5300, 
            0x6D61, 0x6C70, 0x5365, 0x6E79, 0x0063, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x1E5B, 
            0x0000, 0x5000, 0x6168, 0x6573, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x433F, 0x2C16, 0x003E, 0x8000, 0x003F, 0x0000, 0x5B00, 0x001F, 
            0x0000, 0x6173, 0x706D, 0x656C, 0x6574, 0x706D, 0x006F, 0x0000, 
            0x0000, 0x0000, 0x4190, 0x0000, 0x4120, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x205B, 0x0000, 0x7300, 0x6D61, 0x6C70, 0x6465, 0x7669, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 0xB800, 0x0041, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0021, 0x0000, 0x6850, 0x7361, 0x3165, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0022, 0x0000, 0x6850, 0x7361, 0x3265, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0023, 0x0000, 0x6F4D, 0x3164, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0024, 0x0000, 0x6F4D, 0x3264, 0x0000, 0x0000, 
            0x0000, 0x8000, 0xCF3F, 0x11F7, 0x003E, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0025, 0x0000, 0x6F4D, 0x3364, 0x0000, 0x0000, 0x0000, 
            0x8000, 0xAE3F, 0x9147, 0x003C, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0026, 0x0000, 0x6850, 0x7361, 0x4D65, 0x646F, 0x0065, 0x0000, 
            0x3F80, 0x0000, 0x4040, 0x642D, 0x3F89, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x275B, 0x0000, 0x4D00, 0x646F, 0x6F4D, 0x6564, 0x0000, 
            0x8000, 0x003F, 0x4000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x0028, 0x0000, 0x7350, 0x7453, 0x7065, 0x0000, 
            0x0000, 0x0000, 0xC000, 0x0041, 0x8000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x0029, 0x0000, 0x6172, 0x6574, 0x0032, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x7A6F, 0x3ED3, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x2A5B, 0x0000, 0x7200, 0x7461, 0x3365, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x513F, 0x9D4D, 0x003E, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x002B, 0x0000, 0x6172, 0x6574, 0x6F6D, 0x6564, 0x0000, 
            0x8000, 0x003F, 0x4000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x002C, 0x0000, 0x6D46, 0x646F, 0x3265, 0x0000, 
            0x8000, 0x003F, 0x3000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x002D, 0x0000, 0x6D46, 0x646F, 0x3365, 0x0000, 
            0x8000, 0x003F, 0x3000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x002E, 0x0000, 0x6D46, 0x646F, 0x5365, 0x6168, 
            0x6570, 0x0000, 0x8000, 0x003F, 0x4000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x002F, 0x0000, 0x6D43, 0x5270, 
            0x6C65, 0x0032, 0x0000, 0x0000, 0x0000, 0x437A, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x305B, 0x0000, 0x4300, 0x6D70, 
            0x6552, 0x336C, 0x0000, 0x0000, 0x0000, 0x7A00, 0x0043, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0031, 0x0000, 0x6F43, 
            0x706D, 0x6552, 0x4D6C, 0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 
            0x4040, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x325B, 
            0x0000, 0x5300, 0x6D61, 0x6C70, 0x5365, 0x6769, 0x6E49, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0033, 0x0000, 0x6152, 0x6574, 0x6944, 0x3276, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0034, 0x0000, 0x6152, 0x6574, 0x6944, 
            0x3376, 0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0035, 0x0000, 0x6152, 0x6574, 
            0x6944, 0x4D76, 0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 0x4040, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x0000
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
		auto& pma1 = this->getT(0).getT(0).getT(0).getT(0).getT(2);               // ResStage_impl::pma1_t<NV>
		auto& chain30 = this->getT(0).getT(0).getT(0).getT(1);                    // ResStage_impl::chain30_t<NV>
		auto& branch5 = this->getT(0).getT(0).getT(0).getT(1).getT(0);            // ResStage_impl::branch5_t<NV>
		auto& add40 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0);      // math::add<NV>
		auto& add41 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1);      // math::add<NV>
		auto& add43 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(2);      // math::add<NV>
		auto& peak2 = this->getT(0).getT(0).getT(0).getT(1).getT(1);              // ResStage_impl::peak2_t<NV>
		auto& pma3 = this->getT(0).getT(0).getT(0).getT(1).getT(2);               // ResStage_impl::pma3_t<NV>
		auto& smoothed_parameter = this->getT(0).getT(0).getT(0).getT(1).getT(3); // ResStage_impl::smoothed_parameter_t<NV>
		auto& chain31 = this->getT(0).getT(0).getT(0).getT(2);                    // ResStage_impl::chain31_t<NV>
		auto& branch6 = this->getT(0).getT(0).getT(0).getT(2).getT(0);            // ResStage_impl::branch6_t<NV>
		auto& add44 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(0);      // math::add<NV>
		auto& add45 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(1);      // math::add<NV>
		auto& add46 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(2);      // math::add<NV>
		auto& peak4 = this->getT(0).getT(0).getT(0).getT(2).getT(1);              // ResStage_impl::peak4_t<NV>
		auto& pma4 = this->getT(0).getT(0).getT(0).getT(2).getT(2);               // ResStage_impl::pma4_t<NV>
		auto& chain32 = this->getT(0).getT(0).getT(0).getT(3);                    // ResStage_impl::chain32_t<NV>
		auto& branch7 = this->getT(0).getT(0).getT(0).getT(3).getT(0);            // ResStage_impl::branch7_t<NV>
		auto& add47 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(0);      // math::add<NV>
		auto& add48 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(1);      // math::add<NV>
		auto& add49 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(2);      // math::add<NV>
		auto& peak5 = this->getT(0).getT(0).getT(0).getT(3).getT(1);              // ResStage_impl::peak5_t<NV>
		auto& pma5 = this->getT(0).getT(0).getT(0).getT(3).getT(2);               // ResStage_impl::pma5_t<NV>
		auto& chain33 = this->getT(0).getT(0).getT(0).getT(4);                    // ResStage_impl::chain33_t<NV>
		auto& branch8 = this->getT(0).getT(0).getT(0).getT(4).getT(0);            // ResStage_impl::branch8_t<NV>
		auto& add50 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(0);      // math::add<NV>
		auto& add51 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(1);      // math::add<NV>
		auto& add52 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(2);      // math::add<NV>
		auto& peak6 = this->getT(0).getT(0).getT(0).getT(4).getT(1);              // ResStage_impl::peak6_t<NV>
		auto& pma6 = this->getT(0).getT(0).getT(0).getT(4).getT(2);               // ResStage_impl::pma6_t<NV>
		auto& chain34 = this->getT(0).getT(0).getT(0).getT(5);                    // ResStage_impl::chain34_t<NV>
		auto& branch9 = this->getT(0).getT(0).getT(0).getT(5).getT(0);            // ResStage_impl::branch9_t<NV>
		auto& add53 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(0);      // math::add<NV>
		auto& add54 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(1);      // math::add<NV>
		auto& add55 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(2);      // math::add<NV>
		auto& peak7 = this->getT(0).getT(0).getT(0).getT(5).getT(1);              // ResStage_impl::peak7_t<NV>
		auto& pma7 = this->getT(0).getT(0).getT(0).getT(5).getT(2);               // ResStage_impl::pma7_t<NV>
		auto& chain35 = this->getT(0).getT(0).getT(0).getT(6);                    // ResStage_impl::chain35_t<NV>
		auto& branch10 = this->getT(0).getT(0).getT(0).getT(6).getT(0);           // ResStage_impl::branch10_t<NV>
		auto& add56 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(0);      // math::add<NV>
		auto& add57 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(1);      // math::add<NV>
		auto& add58 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(2);      // math::add<NV>
		auto& peak8 = this->getT(0).getT(0).getT(0).getT(6).getT(1);              // ResStage_impl::peak8_t<NV>
		auto& pma8 = this->getT(0).getT(0).getT(0).getT(6).getT(2);               // ResStage_impl::pma8_t<NV>
		auto& branch1 = this->getT(0).getT(1);                                    // ResStage_impl::branch1_t<NV>
		auto& chain18 = this->getT(0).getT(1).getT(0);                            // ResStage_impl::chain18_t
		auto& sampleandhold = this->getT(0).getT(1).getT(1);                      // fx::sampleandhold<NV>
		auto& chain10 = this->getT(0).getT(1).getT(2);                            // ResStage_impl::chain10_t<NV>
		auto& tempo_sync2 = this->getT(0).getT(1).getT(2).getT(0);                // ResStage_impl::tempo_sync2_t<NV>
		auto& receive1 = this->getT(0).getT(1).getT(2).getT(1);                   // routing::receive<stereo_cable>
		auto& fix_delay1 = this->getT(0).getT(1).getT(2).getT(2);                 // core::fix_delay
		auto& send3 = this->getT(0).getT(1).getT(2).getT(3);                      // routing::send<stereo_cable>
		auto& tanh = this->getT(0).getT(1).getT(3);                               // math::tanh<NV>
		auto& bitcrush = this->getT(0).getT(1).getT(4);                           // fx::bitcrush<NV>
		auto& chain17 = this->getT(0).getT(1).getT(5);                            // ResStage_impl::chain17_t<NV>
		auto& xfader1 = this->getT(0).getT(1).getT(5).getT(0);                    // ResStage_impl::xfader1_t<NV>
		auto& split8 = this->getT(0).getT(1).getT(5).getT(1);                     // ResStage_impl::split8_t<NV>
		auto& chain15 = this->getT(0).getT(1).getT(5).getT(1).getT(0);            // ResStage_impl::chain15_t<NV>
		auto& gain4 = this->getT(0).getT(1).getT(5).getT(1).getT(0).getT(0);      // core::gain<NV>
		auto& chain16 = this->getT(0).getT(1).getT(5).getT(1).getT(1);            // ResStage_impl::chain16_t<NV>
		auto& abs1 = this->getT(0).getT(1).getT(5).getT(1).getT(1).getT(0);       // math::abs<NV>
		auto& gain8 = this->getT(0).getT(1).getT(5).getT(1).getT(1).getT(1);      // core::gain<NV>
		auto& chain1 = this->getT(0).getT(1).getT(6);                             // ResStage_impl::chain1_t<NV>
		auto& cable_table2 = this->getT(0).getT(1).getT(6).getT(0);               // ResStage_impl::cable_table2_t<NV>
		auto& cable_table3 = this->getT(0).getT(1).getT(6).getT(1);               // ResStage_impl::cable_table3_t<NV>
		auto& faust1 = this->getT(0).getT(1).getT(6).getT(2);                     // project::granul<NV>
		auto& xfader = this->getT(1);                                             // ResStage_impl::xfader_t<NV>
		auto& split5 = this->getT(2);                                             // ResStage_impl::split5_t<NV>
		auto& chain11 = this->getT(2).getT(0);                                    // ResStage_impl::chain11_t<NV>
		auto& gain = this->getT(2).getT(0).getT(0);                               // core::gain<NV>
		auto& chain12 = this->getT(2).getT(1);                                    // ResStage_impl::chain12_t<NV>
		auto& comp = this->getT(2).getT(1).getT(0);                               // ResStage_impl::comp_t<NV>
		auto& chain21 = this->getT(2).getT(1).getT(1);                            // ResStage_impl::chain21_t<NV>
		auto& chain13 = this->getT(2).getT(1).getT(1).getT(0);                    // ResStage_impl::chain13_t<NV>
		auto& clear4 = this->getT(2).getT(1).getT(1).getT(0).getT(0);             // math::clear<NV>
		auto& add3 = this->getT(2).getT(1).getT(1).getT(0).getT(1);               // math::add<NV>
		auto& pma2 = this->getT(2).getT(1).getT(1).getT(0).getT(2);               // ResStage_impl::pma2_t<NV>
		auto& gain6 = this->getT(2).getT(1).getT(1).getT(0).getT(3);              // core::gain<NV>
		auto& gain76 = this->getT(2).getT(1).getT(1).getT(0).getT(4);             // core::gain<NV>
		auto& peak1 = this->getT(2).getT(1).getT(1).getT(1);                      // ResStage_impl::peak1_t
		auto& clear2 = this->getT(2).getT(1).getT(2);                             // wrap::no_process<math::clear<NV>>
		auto& tempo_sync1 = this->getT(3);                                        // ResStage_impl::tempo_sync1_t<NV>
		auto& chain6 = this->getT(4);                                             // ResStage_impl::chain6_t<NV>
		auto& gain5 = this->getT(4).getT(0);                                      // core::gain<NV>
		auto& one_pole30 = this->getT(4).getT(1);                                 // filters::one_pole<NV>
		auto& minmax = this->getT(4).getT(2);                                     // ResStage_impl::minmax_t<NV>
		auto& receive58 = this->getT(4).getT(3);                                  // routing::receive<stereo_cable>
		auto& faust = this->getT(4).getT(4);                                      // project::PitchShifter<NV>
		auto& send = this->getT(4).getT(5);                                       // routing::send<stereo_cable>
		auto& modchain = this->getT(4).getT(6);                                   // ResStage_impl::modchain_t<NV>
		auto& minmax1 = this->getT(4).getT(6).getT(0);                            // ResStage_impl::minmax1_t<NV>
		auto& pma9 = this->getT(4).getT(6).getT(1);                               // ResStage_impl::pma9_t<NV>
		auto& converter2 = this->getT(4).getT(6).getT(2);                         // ResStage_impl::converter2_t<NV>
		auto& converter6 = this->getT(4).getT(6).getT(3);                         // ResStage_impl::converter6_t<NV>
		auto& tempo_sync = this->getT(4).getT(6).getT(4);                         // ResStage_impl::tempo_sync_t<NV>
		auto& pma = this->getT(4).getT(6).getT(5);                                // control::pma<NV, parameter::empty>
		auto& clear1 = this->getT(4).getT(6).getT(6);                             // math::clear<NV>
		auto& add7 = this->getT(4).getT(6).getT(7);                               // math::add<NV>
		auto& pi3 = this->getT(4).getT(6).getT(8);                                // math::pi<NV>
		auto& rect2 = this->getT(4).getT(6).getT(9);                              // wrap::no_process<math::rect<NV>>
		auto& sin = this->getT(4).getT(6).getT(10);                               // wrap::no_process<math::sin<NV>>
		auto& peak3 = this->getT(4).getT(6).getT(11);                             // ResStage_impl::peak3_t<NV>
		auto& clear3 = this->getT(4).getT(6).getT(12);                            // math::clear<NV>
		auto& FilterForRes1 = this->getT(5);                                      // project::FilterForRes<NV>
		auto& cable_table1 = this->getT(6);                                       // ResStage_impl::cable_table1_t<NV>
		auto& smoothed_parameter_unscaled = this->getT(7);                        // ResStage_impl::smoothed_parameter_unscaled_t<NV>
		auto& pma10 = this->getT(8);                                              // ResStage_impl::pma10_t<NV>
		auto& branch = this->getT(9);                                             // ResStage_impl::branch_t<NV>
		auto& chain4 = this->getT(9).getT(0);                                     // ResStage_impl::chain4_t<NV>
		auto& allpass1 = this->getT(9).getT(0).getT(0);                           // filters::allpass<NV>
		auto& one_pole3 = this->getT(9).getT(0).getT(1);                          // filters::one_pole<NV>
		auto& chain5 = this->getT(9).getT(1);                                     // ResStage_impl::chain5_t<NV>
		auto& res3 = this->getT(9).getT(1).getT(0);                               // project::res1<NV>
		auto& chain8 = this->getT(9).getT(2);                                     // ResStage_impl::chain8_t<NV>
		auto& res4 = this->getT(9).getT(2).getT(0);                               // project::res1<NV>
		auto& chain7 = this->getT(9).getT(3);                                     // ResStage_impl::chain7_t<NV>
		auto& res5 = this->getT(9).getT(3).getT(0);                               // project::res1<NV>
		auto& fix8_block = this->getT(9).getT(4);                                 // ResStage_impl::fix8_block_t<NV>
		auto& chain22 = this->getT(9).getT(4).getT(0);                            // ResStage_impl::chain22_t<NV>
		auto& gain2 = this->getT(9).getT(4).getT(0).getT(0);                      // core::gain<NV>
		auto& split1 = this->getT(9).getT(4).getT(0).getT(1);                     // ResStage_impl::split1_t
		auto& ramp = this->getT(9).getT(4).getT(0).getT(2);                       // ResStage_impl::ramp_t<NV>
		auto& chain2 = this->getT(9).getT(4).getT(0).getT(3);                     // ResStage_impl::chain2_t<NV>
		auto& multi = this->getT(9).getT(4).getT(0).getT(3).getT(0);              // ResStage_impl::multi_t
		auto& add1 = this->getT(9).getT(4).getT(0).getT(3).getT(1);               // math::add<NV>
		auto& file_player = this->getT(9).getT(4).getT(0).getT(3).getT(2);        // ResStage_impl::file_player_t<NV>
		auto& one_pole1 = this->getT(9).getT(4).getT(0).getT(3).getT(3);          // filters::one_pole<NV>
		auto& FilterForRes = this->getT(10);                                      // project::FilterForRes<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, branch1); // ModifierMode -> branch1::Index
		
		this->getParameterT(1).connectT(0, add47); // CutOffA -> add47::Value
		
		this->getParameterT(2).connectT(0, add48); // CutOffB -> add48::Value
		
		this->getParameterT(3).connectT(0, FilterForRes1); // qA -> FilterForRes1::Res
		
		this->getParameterT(4).connectT(0, add49); // CutOffC -> add49::Value
		
		this->getParameterT(5).connectT(0, comp); // CompThresh -> comp::Threshhold
		
		this->getParameterT(6).connectT(0, comp); // CompAtk -> comp::Attack
		
		this->getParameterT(7).connectT(0, add53); // CompRel -> add53::Value
		
		this->getParameterT(8).connectT(0, comp); // CompRatio -> comp::Ratio
		
		this->getParameterT(9).connectT(0, xfader); // InputTrig -> xfader::Value
		
		this->getParameterT(10).connectT(0, one_pole30); // InputHP -> one_pole30::Frequency
		
		this->getParameterT(11).connectT(0, add44); // Rate -> add44::Value
		
		this->getParameterT(12).connectT(0, tempo_sync1); // RateWin -> tempo_sync1::Tempo
		
		this->getParameterT(13).connectT(0, add56); // RateWinDiv -> add56::Value
		
		this->getParameterT(14).connectT(0, minmax1); // ResFreq -> minmax1::Value
		
		this->getParameterT(15).connectT(0, minmax1); // ResMin -> minmax1::Minimum
		
		this->getParameterT(16).connectT(0, minmax1); // ResMax -> minmax1::Maximum
		
		this->getParameterT(17).connectT(0, minmax1); // ResStep -> minmax1::Step
		
		auto& ResMode_p = this->getParameterT(18);
		ResMode_p.connectT(0, branch);       // ResMode -> branch::Index
		ResMode_p.connectT(1, cable_table1); // ResMode -> cable_table1::Value
		
		auto& ResLP_p = this->getParameterT(19);
		ResLP_p.connectT(0, one_pole3); // ResLP -> one_pole3::Frequency
		ResLP_p.connectT(1, res3);      // ResLP -> res3::LP
		ResLP_p.connectT(2, res5);      // ResLP -> res5::LP
		ResLP_p.connectT(3, res4);      // ResLP -> res4::LP
		ResLP_p.connectT(4, one_pole1); // ResLP -> one_pole1::Frequency
		
		auto& ResFeed_p = this->getParameterT(20);
		ResFeed_p.connectT(0, pma10);    // ResFeed -> pma10::Value
		ResFeed_p.connectT(1, allpass1); // ResFeed -> allpass1::Q
		
		this->getParameterT(21).connectT(0, FilterForRes); // PostCut -> FilterForRes::Cut
		
		this->getParameterT(22).connectT(0, FilterForRes); // PostRes -> FilterForRes::Res
		
		this->getParameterT(23).connectT(0, FilterForRes); // PostMode -> FilterForRes::Mode
		
		this->getParameterT(24).connectT(0, add50); // Fmode1 -> add50::Value
		
		this->getParameterT(25).connectT(0, branch7); // FilterModShape -> branch7::Index
		
		this->getParameterT(26).connectT(0, receive58); // Fb -> receive58::Feedback
		
		this->getParameterT(29).connectT(0, tempo_sync); // SampleSync -> tempo_sync::Enabled
		
		this->getParameterT(30).connectT(0, add40); // Phase -> add40::Value
		
		this->getParameterT(31).connectT(0, tempo_sync); // sampletempo -> tempo_sync::Tempo
		
		this->getParameterT(32).connectT(0, tempo_sync); // samplediv -> tempo_sync::Multiplier
		
		this->getParameterT(33).connectT(0, add41); // Phase1 -> add41::Value
		
		this->getParameterT(34).connectT(0, add43); // Phase2 -> add43::Value
		
		this->getParameterT(35).connectT(0, add20); // Mod1 -> add20::Value
		
		this->getParameterT(36).connectT(0, add21); // Mod2 -> add21::Value
		
		this->getParameterT(37).connectT(0, add42); // Mod3 -> add42::Value
		
		this->getParameterT(38).connectT(0, branch5); // PhaseMode -> branch5::Index
		
		this->getParameterT(39).connectT(0, branch3); // ModMode -> branch3::Index
		
		this->getParameterT(40).connectT(0, minmax); // PsStep -> minmax::Step
		
		this->getParameterT(41).connectT(0, add45); // rate2 -> add45::Value
		
		this->getParameterT(42).connectT(0, add46); // rate3 -> add46::Value
		
		this->getParameterT(43).connectT(0, branch6); // ratemode -> branch6::Index
		
		this->getParameterT(44).connectT(0, add51); // Fmode2 -> add51::Value
		
		this->getParameterT(45).connectT(0, add52); // Fmode3 -> add52::Value
		
		this->getParameterT(46).connectT(0, branch8); // FmodeShape -> branch8::Index
		
		this->getParameterT(47).connectT(0, add54); // CmpRel2 -> add54::Value
		
		this->getParameterT(48).connectT(0, add55); // CpmRel3 -> add55::Value
		
		this->getParameterT(49).connectT(0, branch9); // CompRelMode -> branch9::Index
		
		this->getParameterT(50).connectT(0, gain2); // SampleSigIn -> gain2::Gain
		
		this->getParameterT(51).connectT(0, add57); // RateDiv2 -> add57::Value
		
		this->getParameterT(52).connectT(0, add58); // RateDiv3 -> add58::Value
		
		this->getParameterT(53).connectT(0, branch10); // RateDivMode -> branch10::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain4);                          // xfader1 -> gain4::Gain
		xfader1_p.getParameterT(1).connectT(0, gain8);                          // xfader1 -> gain8::Gain
		cable_table2.getWrappedObject().getParameter().connectT(0, faust1);     // cable_table2 -> faust1::GrainSize
		cable_table3.getWrappedObject().getParameter().connectT(0, faust1);     // cable_table3 -> faust1::Speed
		tempo_sync2.getParameter().connectT(0, fix_delay1);                     // tempo_sync2 -> fix_delay1::DelayTime
		pma1.getWrappedObject().getParameter().connectT(0, sampleandhold);      // pma1 -> sampleandhold::Counter
		pma1.getWrappedObject().getParameter().connectT(1, tanh);               // pma1 -> tanh::Value
		pma1.getWrappedObject().getParameter().connectT(2, bitcrush);           // pma1 -> bitcrush::BitDepth
		pma1.getWrappedObject().getParameter().connectT(3, xfader1);            // pma1 -> xfader1::Value
		pma1.getWrappedObject().getParameter().connectT(4, cable_table2);       // pma1 -> cable_table2::Value
		pma1.getWrappedObject().getParameter().connectT(5, cable_table3);       // pma1 -> cable_table3::Value
		pma1.getWrappedObject().getParameter().connectT(6, tempo_sync2);        // pma1 -> tempo_sync2::Tempo
		peak.getParameter().connectT(0, pma1);                                  // peak -> pma1::Add
		smoothed_parameter.getParameter().connectT(0, add1);                    // smoothed_parameter -> add1::Value
		pma3.getWrappedObject().getParameter().connectT(0, smoothed_parameter); // pma3 -> smoothed_parameter::Value
		pma3.getWrappedObject().getParameter().connectT(1, allpass1);           // pma3 -> allpass1::Smoothing
		pma3.getWrappedObject().getParameter().connectT(2, res3);               // pma3 -> res3::Comp
		pma3.getWrappedObject().getParameter().connectT(3, res3);               // pma3 -> res3::FbModifier
		pma3.getWrappedObject().getParameter().connectT(4, res4);               // pma3 -> res4::FbModifier
		pma3.getWrappedObject().getParameter().connectT(5, res5);               // pma3 -> res5::FbModifier
		peak2.getParameter().connectT(0, pma3);                                 // peak2 -> pma3::Add
		minmax.getWrappedObject().getParameter().connectT(0, faust);            // minmax -> faust::shiftsemitones
		pma4.getWrappedObject().getParameter().connectT(0, minmax);             // pma4 -> minmax::Value
		peak4.getParameter().connectT(0, pma4);                                 // peak4 -> pma4::Add
		pma5.getWrappedObject().getParameter().connectT(0, FilterForRes1);      // pma5 -> FilterForRes1::Cut
		peak5.getParameter().connectT(0, pma5);                                 // peak5 -> pma5::Add
		pma6.getWrappedObject().getParameter().connectT(0, FilterForRes1);      // pma6 -> FilterForRes1::Mode
		peak6.getParameter().connectT(0, pma6);                                 // peak6 -> pma6::Add
		pma2.getWrappedObject().getParameter().connectT(0, gain6);              // pma2 -> gain6::Gain
		comp.getParameter().connectT(0, add7);                                  // comp -> add7::Value
		comp.getParameter().connectT(1, pma2);                                  // comp -> pma2::Value
		comp.getParameter().connectT(2, add3);                                  // comp -> add3::Value
		pma7.getWrappedObject().getParameter().connectT(0, comp);               // pma7 -> comp::Release
		peak7.getParameter().connectT(0, pma7);                                 // peak7 -> pma7::Add
		tempo_sync1.getParameter().connectT(0, faust);                          // tempo_sync1 -> faust::windowsamples
		tempo_sync1.getParameter().connectT(1, faust);                          // tempo_sync1 -> faust::xfadesamples
		pma8.getWrappedObject().getParameter().connectT(0, tempo_sync1);        // pma8 -> tempo_sync1::Multiplier
		peak8.getParameter().connectT(0, pma8);                                 // peak8 -> pma8::Add
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);                                             // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain76);                                           // xfader -> gain76::Gain
		tempo_sync.getParameter().connectT(0, ramp);                                             // tempo_sync -> ramp::PeriodTime
		tempo_sync.getParameter().connectT(1, res3);                                             // tempo_sync -> res3::Del
		tempo_sync.getParameter().connectT(2, res5);                                             // tempo_sync -> res5::Del
		tempo_sync.getParameter().connectT(3, res4);                                             // tempo_sync -> res4::Del
		converter6.getWrappedObject().getParameter().connectT(0, tempo_sync);                    // converter6 -> tempo_sync::UnsyncedTime
		converter2.getWrappedObject().getParameter().connectT(0, converter6);                    // converter2 -> converter6::Value
		converter2.getWrappedObject().getParameter().connectT(1, allpass1);                      // converter2 -> allpass1::Frequency
		converter2.getWrappedObject().getParameter().connectT(2, res4);                          // converter2 -> res4::Freq
		pma9.getWrappedObject().getParameter().connectT(0, converter2);                          // pma9 -> converter2::Value
		minmax1.getWrappedObject().getParameter().connectT(0, pma);                              // minmax1 -> pma::Value
		minmax1.getWrappedObject().getParameter().connectT(1, pma9);                             // minmax1 -> pma9::Value
		peak3.getParameter().connectT(0, ramp);                                                  // peak3 -> ramp::Gate
		pma10.getWrappedObject().getParameter().connectT(0, res3);                               // pma10 -> res3::feed
		pma10.getWrappedObject().getParameter().connectT(1, res4);                               // pma10 -> res4::feed
		pma10.getWrappedObject().getParameter().connectT(2, res5);                               // pma10 -> res5::feed
		smoothed_parameter_unscaled.getParameter().connectT(0, pma10);                           // smoothed_parameter_unscaled -> pma10::Multiply
		cable_table1.getWrappedObject().getParameter().connectT(0, smoothed_parameter_unscaled); // cable_table1 -> smoothed_parameter_unscaled::Value
		
		// Send Connections ------------------------------------------------------------------------
		
		send3.connect(receive1);
		send.connect(receive58);
		
		// Default Values --------------------------------------------------------------------------
		
		; // branch3::Index is automated
		
		; // add20::Value is automated
		
		; // add21::Value is automated
		
		; // add42::Value is automated
		
		pma1.setParameterT(0, 0.); // control::pma::Value
		pma1.setParameterT(1, 0.); // control::pma::Multiply
		;                          // pma1::Add is automated
		
		; // branch5::Index is automated
		
		; // add40::Value is automated
		
		; // add41::Value is automated
		
		; // add43::Value is automated
		
		pma3.setParameterT(0, 0.); // control::pma::Value
		pma3.setParameterT(1, 0.); // control::pma::Multiply
		;                          // pma3::Add is automated
		
		;                                          // smoothed_parameter::Value is automated
		smoothed_parameter.setParameterT(1, 125.); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter.setParameterT(2, 1.);   // control::smoothed_parameter::Enabled
		
		; // branch6::Index is automated
		
		; // add44::Value is automated
		
		; // add45::Value is automated
		
		; // add46::Value is automated
		
		pma4.setParameterT(0, 0.); // control::pma::Value
		pma4.setParameterT(1, 0.); // control::pma::Multiply
		;                          // pma4::Add is automated
		
		; // branch7::Index is automated
		
		; // add47::Value is automated
		
		; // add48::Value is automated
		
		; // add49::Value is automated
		
		pma5.setParameterT(0, 0.); // control::pma::Value
		pma5.setParameterT(1, 0.); // control::pma::Multiply
		;                          // pma5::Add is automated
		
		; // branch8::Index is automated
		
		; // add50::Value is automated
		
		; // add51::Value is automated
		
		; // add52::Value is automated
		
		pma6.setParameterT(0, 0.); // control::pma::Value
		pma6.setParameterT(1, 0.); // control::pma::Multiply
		;                          // pma6::Add is automated
		
		; // branch9::Index is automated
		
		; // add53::Value is automated
		
		; // add54::Value is automated
		
		; // add55::Value is automated
		
		pma7.setParameterT(0, 0.); // control::pma::Value
		pma7.setParameterT(1, 0.); // control::pma::Multiply
		;                          // pma7::Add is automated
		
		; // branch10::Index is automated
		
		; // add56::Value is automated
		
		; // add57::Value is automated
		
		; // add58::Value is automated
		
		pma8.setParameterT(0, 0.); // control::pma::Value
		pma8.setParameterT(1, 0.); // control::pma::Multiply
		;                          // pma8::Add is automated
		
		; // branch1::Index is automated
		
		; // sampleandhold::Counter is automated
		
		;                                   // tempo_sync2::Tempo is automated
		tempo_sync2.setParameterT(1, 8.);   // control::tempo_sync::Multiplier
		tempo_sync2.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync2.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		receive1.setParameterT(0, 0.893458); // routing::receive::Feedback
		
		;                                  // fix_delay1::DelayTime is automated
		fix_delay1.setParameterT(1, 516.); // core::fix_delay::FadeTime
		
		; // tanh::Value is automated
		
		;                              // bitcrush::BitDepth is automated
		bitcrush.setParameterT(1, 1.); // fx::bitcrush::Mode
		
		; // xfader1::Value is automated
		
		;                            // gain4::Gain is automated
		gain4.setParameterT(1, 20.); // core::gain::Smoothing
		gain4.setParameterT(2, 0.);  // core::gain::ResetValue
		
		abs1.setParameterT(0, 1.); // math::abs::Value
		
		;                            // gain8::Gain is automated
		gain8.setParameterT(1, 20.); // core::gain::Smoothing
		gain8.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // cable_table2::Value is automated
		
		; // cable_table3::Value is automated
		
		;                             // faust1::GrainSize is automated
		;                             // faust1::Speed is automated
		faust1.setParameterT(2, 50.); // core::faust::Probability
		
		; // xfader::Value is automated
		
		;                             // gain::Gain is automated
		gain.setParameterT(1, 0.);    // core::gain::Smoothing
		gain.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                          // comp::Threshhold is automated
		;                          // comp::Attack is automated
		;                          // comp::Release is automated
		;                          // comp::Ratio is automated
		comp.setParameterT(4, 0.); // dynamics::comp::Sidechain
		
		clear4.setParameterT(0, 0.218947); // math::clear::Value
		
		; // add3::Value is automated
		
		;                                 // pma2::Value is automated
		pma2.setParameterT(1, 1.);        // control::pma::Multiply
		pma2.setParameterT(2, 0.0178545); // control::pma::Add
		
		;                           // gain6::Gain is automated
		gain6.setParameterT(1, 0.); // core::gain::Smoothing
		gain6.setParameterT(2, 0.); // core::gain::ResetValue
		
		;                               // gain76::Gain is automated
		gain76.setParameterT(1, 0.);    // core::gain::Smoothing
		gain76.setParameterT(2, -100.); // core::gain::ResetValue
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		;                                     // tempo_sync1::Tempo is automated
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
		
		;                              // minmax::Value is automated
		minmax.setParameterT(1, -48.); // control::minmax::Minimum
		minmax.setParameterT(2, 48.);  // control::minmax::Maximum
		minmax.setParameterT(3, 1.);   // control::minmax::Skew
		;                              // minmax::Step is automated
		minmax.setParameterT(5, 0.);   // control::minmax::Polarity
		
		; // receive58::Feedback is automated
		
		; // faust::shiftsemitones is automated
		; // faust::windowsamples is automated
		; // faust::xfadesamples is automated
		
		;                             // minmax1::Value is automated
		;                             // minmax1::Minimum is automated
		;                             // minmax1::Maximum is automated
		minmax1.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax1::Step is automated
		minmax1.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                          // pma9::Value is automated
		pma9.setParameterT(1, 1.); // control::pma::Multiply
		pma9.setParameterT(2, 0.); // control::pma::Add
		
		; // converter2::Value is automated
		
		; // converter6::Value is automated
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		;                          // pma::Value is automated
		pma.setParameterT(1, -1.); // control::pma::Multiply
		pma.setParameterT(2, 1.);  // control::pma::Add
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		; // add7::Value is automated
		
		pi3.setParameterT(0, 1.); // math::pi::Value
		
		rect2.setParameterT(0, 1.); // math::rect::Value
		
		sin.setParameterT(0, 0.535944); // math::sin::Value
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		; // FilterForRes1::Cut is automated
		; // FilterForRes1::Res is automated
		; // FilterForRes1::Mode is automated
		
		; // cable_table1::Value is automated
		
		;                                                    // smoothed_parameter_unscaled::Value is automated
		smoothed_parameter_unscaled.setParameterT(1, 354.7); // control::smoothed_parameter_unscaled::SmoothingTime
		smoothed_parameter_unscaled.setParameterT(2, 1.);    // control::smoothed_parameter_unscaled::Enabled
		
		;                                    // pma10::Value is automated
		;                                    // pma10::Multiply is automated
		pma10.setParameterT(2, 5.55112e-17); // control::pma::Add
		
		; // branch::Index is automated
		
		;                              // allpass1::Frequency is automated
		;                              // allpass1::Q is automated
		allpass1.setParameterT(2, 0.); // filters::allpass::Gain
		;                              // allpass1::Smoothing is automated
		allpass1.setParameterT(4, 0.); // filters::allpass::Mode
		allpass1.setParameterT(5, 1.); // filters::allpass::Enabled
		
		;                                 // one_pole3::Frequency is automated
		one_pole3.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole3.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole3.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole3.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole3.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                          // res3::feed is automated
		;                          // res3::Del is automated
		res3.setParameterT(2, 3.); // project::res1::Block
		;                          // res3::LP is automated
		;                          // res3::FbModifier is automated
		res3.setParameterT(5, 0.); // project::res1::Freq
		res3.setParameterT(6, 0.); // project::res1::Mode
		;                          // res3::Comp is automated
		res3.setParameterT(8, 0.); // project::res1::ga
		
		;                                // res4::feed is automated
		;                                // res4::Del is automated
		res4.setParameterT(2, 3.);       // project::res1::Block
		;                                // res4::LP is automated
		;                                // res4::FbModifier is automated
		;                                // res4::Freq is automated
		res4.setParameterT(6, 1.);       // project::res1::Mode
		res4.setParameterT(7, 0.876238); // project::res1::Comp
		res4.setParameterT(8, -3.8);     // project::res1::ga
		
		;                                // res5::feed is automated
		;                                // res5::Del is automated
		res5.setParameterT(2, 3.);       // project::res1::Block
		;                                // res5::LP is automated
		;                                // res5::FbModifier is automated
		res5.setParameterT(5, 20000.);   // project::res1::Freq
		res5.setParameterT(6, 2.);       // project::res1::Mode
		res5.setParameterT(7, 0.595194); // project::res1::Comp
		res5.setParameterT(8, 0.);       // project::res1::ga
		
		;                             // gain2::Gain is automated
		gain2.setParameterT(1, 40.5); // core::gain::Smoothing
		gain2.setParameterT(2, 0.);   // core::gain::ResetValue
		
		;                                // ramp::PeriodTime is automated
		ramp.setParameterT(1, 0.391531); // core::ramp::LoopStart
		;                                // ramp::Gate is automated
		
		; // add1::Value is automated
		
		file_player.setParameterT(0, 1.);   // core::file_player::PlaybackMode
		file_player.setParameterT(1, 0.);   // core::file_player::Gate
		file_player.setParameterT(2, 440.); // core::file_player::RootFrequency
		file_player.setParameterT(3, 0.55); // core::file_player::FreqRatio
		
		;                                      // one_pole1::Frequency is automated
		one_pole1.setParameterT(1, 1.);        // filters::one_pole::Q
		one_pole1.setParameterT(2, 0.);        // filters::one_pole::Gain
		one_pole1.setParameterT(3, 0.0282089); // filters::one_pole::Smoothing
		one_pole1.setParameterT(4, 0.);        // filters::one_pole::Mode
		one_pole1.setParameterT(5, 1.);        // filters::one_pole::Enabled
		
		; // FilterForRes::Cut is automated
		; // FilterForRes::Res is automated
		; // FilterForRes::Mode is automated
		
		this->setParameterT(0, 5.);
		this->setParameterT(1, 0.00065829);
		this->setParameterT(2, 0.00886168);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 0.528618);
		this->setParameterT(5, -27.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 61.3);
		this->setParameterT(8, 1.1);
		this->setParameterT(9, 0.881539);
		this->setParameterT(10, 20.3628);
		this->setParameterT(11, 0.669548);
		this->setParameterT(12, 11.);
		this->setParameterT(13, 31.);
		this->setParameterT(14, 0.901919);
		this->setParameterT(15, 6.66134e-16);
		this->setParameterT(16, 1.);
		this->setParameterT(17, 0.);
		this->setParameterT(18, 0.);
		this->setParameterT(19, 18879.3);
		this->setParameterT(20, 0.946501);
		this->setParameterT(21, 0.549447);
		this->setParameterT(22, 0.);
		this->setParameterT(23, 1.);
		this->setParameterT(24, 1.);
		this->setParameterT(25, 3.);
		this->setParameterT(26, 1.);
		this->setParameterT(27, 127.9);
		this->setParameterT(28, 1000.);
		this->setParameterT(29, 0.);
		this->setParameterT(30, 0.168054);
		this->setParameterT(31, 10.);
		this->setParameterT(32, 23.);
		this->setParameterT(33, 1.);
		this->setParameterT(34, 0.);
		this->setParameterT(35, 1.);
		this->setParameterT(36, 0.142547);
		this->setParameterT(37, 0.0177344);
		this->setParameterT(38, 1.07337);
		this->setParameterT(39, 1.);
		this->setParameterT(40, 4.);
		this->setParameterT(41, 0.413043);
		this->setParameterT(42, 0.30723);
		this->setParameterT(43, 1.);
		this->setParameterT(44, 1.);
		this->setParameterT(45, 1.);
		this->setParameterT(46, 1.);
		this->setParameterT(47, 0.);
		this->setParameterT(48, 0.);
		this->setParameterT(49, 1.);
		this->setParameterT(50, 0.);
		this->setParameterT(51, 1.);
		this->setParameterT(52, 1.);
		this->setParameterT(53, 1.);
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
		this->getT(0).getT(0).getT(0).getT(2).getT(1).setExternalData(b, index); // ResStage_impl::peak4_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(1).setExternalData(b, index); // ResStage_impl::peak5_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(1).setExternalData(b, index); // ResStage_impl::peak6_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(1).setExternalData(b, index); // ResStage_impl::peak7_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(1).setExternalData(b, index); // ResStage_impl::peak8_t<NV>
		this->getT(0).getT(1).getT(6).getT(0).setExternalData(b, index);         // ResStage_impl::cable_table2_t<NV>
		this->getT(0).getT(1).getT(6).getT(1).setExternalData(b, index);         // ResStage_impl::cable_table3_t<NV>
		this->getT(2).getT(1).getT(0).setExternalData(b, index);                 // ResStage_impl::comp_t<NV>
		this->getT(2).getT(1).getT(1).getT(1).setExternalData(b, index);         // ResStage_impl::peak1_t
		this->getT(4).getT(6).getT(11).setExternalData(b, index);                // ResStage_impl::peak3_t<NV>
		this->getT(6).setExternalData(b, index);                                 // ResStage_impl::cable_table1_t<NV>
		this->getT(9).getT(4).getT(0).getT(2).setExternalData(b, index);         // ResStage_impl::ramp_t<NV>
		this->getT(9).getT(4).getT(0).getT(3).getT(2).setExternalData(b, index); // ResStage_impl::file_player_t<NV>
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


