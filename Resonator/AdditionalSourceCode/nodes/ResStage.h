#pragma once

#include "FilterForRes.h"
#include "res1.h"
#include "res1.h"
#include "res1.h"
#include "Filetrig.h"
#include "Filetrig.h"
#include "Filetrig.h"
#include "Filetrig.h"
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
using Filetrig1_t = wrap::data<project::Filetrig<NV>, 
                               data::external::audiofile<0>>;
template <int NV>
using smoothed_parameter_t = wrap::mod<parameter::plain<Filetrig1_t<NV>, 3>, 
                                       control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
template <int NV>
using Filetrig3_t = wrap::data<project::Filetrig<NV>, 
                               data::external::audiofile<1>>;
template <int NV>
using Filetrig4_t = wrap::data<project::Filetrig<NV>, 
                               data::external::audiofile<2>>;
template <int NV>
using Filetrig5_t = wrap::data<project::Filetrig<NV>, 
                               data::external::audiofile<3>>;
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

template <int NV> using pma3_mod_4 = pma3_mod_3<NV>;

template <int NV>
using pma3_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<smoothed_parameter_t<NV>, 0>, 
                                  pma3_mod_1<NV>, 
                                  parameter::plain<project::res1<NV>, 7>, 
                                  pma3_mod_3<NV>, 
                                  pma3_mod_4<NV>, 
                                  parameter::plain<project::res1<NV>, 7>, 
                                  parameter::plain<Filetrig3_t<NV>, 3>, 
                                  parameter::plain<Filetrig4_t<NV>, 3>, 
                                  parameter::plain<Filetrig5_t<NV>, 3>>;

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
using h1_sb1_t_ = container::chain<parameter::empty, 
                                   wrap::fix<1, math::add<NV>>>;

template <int NV>
using h1_sb1_t = bypass::smoothed<20, h1_sb1_t_<NV>>;
template <int NV>
using h1_switcher_c0 = parameter::bypass<h1_sb1_t<NV>>;

template <int NV> using h1_sb2_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb2_t = bypass::smoothed<20, h1_sb2_t_<NV>>;
template <int NV>
using h1_switcher_c1 = parameter::bypass<h1_sb2_t<NV>>;

template <int NV> using h1_sb3_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb3_t = bypass::smoothed<20, h1_sb3_t_<NV>>;
template <int NV>
using h1_switcher_c2 = parameter::bypass<h1_sb3_t<NV>>;

template <int NV> using h1_sb4_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb4_t = bypass::smoothed<20, h1_sb4_t_<NV>>;
template <int NV>
using h1_switcher_c3 = parameter::bypass<h1_sb4_t<NV>>;

template <int NV> using h1_sb5_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb5_t = bypass::smoothed<20, h1_sb5_t_<NV>>;
template <int NV>
using h1_switcher_c4 = parameter::bypass<h1_sb5_t<NV>>;

template <int NV> using h1_sb6_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb6_t = bypass::smoothed<20, h1_sb6_t_<NV>>;
template <int NV>
using h1_switcher_c5 = parameter::bypass<h1_sb6_t<NV>>;

template <int NV> using h1_sb7_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb7_t = bypass::smoothed<20, h1_sb7_t_<NV>>;
template <int NV>
using h1_switcher_c6 = parameter::bypass<h1_sb7_t<NV>>;

template <int NV> using h1_sb8_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb8_t = bypass::smoothed<20, h1_sb8_t_<NV>>;
template <int NV>
using h1_switcher_c7 = parameter::bypass<h1_sb8_t<NV>>;

template <int NV>
using h1_switcher_multimod = parameter::list<h1_switcher_c0<NV>, 
                                             h1_switcher_c1<NV>, 
                                             h1_switcher_c2<NV>, 
                                             h1_switcher_c3<NV>, 
                                             h1_switcher_c4<NV>, 
                                             h1_switcher_c5<NV>, 
                                             h1_switcher_c6<NV>, 
                                             h1_switcher_c7<NV>>;

template <int NV>
using h1_switcher_t = control::xfader<h1_switcher_multimod<NV>, 
                                      faders::switcher>;

struct h1_cable_table1_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00392926f, 0.00785851f, 0.0117877f, 0.015717f, 0.0196462f,
		0.0235755f, 0.0275047f, 0.0314339f, 0.0353632f, 0.0392925f, 0.0432217f,
		0.0471509f, 0.0510802f, 0.0550094f, 0.0589386f, 0.0628679f, 0.0667971f,
		0.0707264f, 0.0746557f, 0.0785848f, 0.0825141f, 0.0864434f, 0.0903726f,
		0.0943018f, 0.0982311f, 0.10216f, 0.10609f, 0.110019f, 0.113948f,
		0.117877f, 0.121807f, 0.125736f, 0.129665f, 0.133594f, 0.137524f,
		0.141453f, 0.145382f, 0.149311f, 0.15324f, 0.15717f, 0.161099f,
		0.165028f, 0.168957f, 0.172887f, 0.176816f, 0.180745f, 0.184674f,
		0.188604f, 0.192533f, 0.196462f, 0.200391f, 0.204321f, 0.20825f,
		0.212179f, 0.216108f, 0.220038f, 0.223967f, 0.227896f, 0.231825f,
		0.235755f, 0.239684f, 0.243613f, 0.247542f, 0.251472f, 0.255401f,
		0.25933f, 0.263259f, 0.267189f, 0.271118f, 0.275047f, 0.278976f,
		0.282905f, 0.286835f, 0.290764f, 0.294693f, 0.298622f, 0.302552f,
		0.306481f, 0.31041f, 0.314339f, 0.318269f, 0.322198f, 0.326127f,
		0.330056f, 0.333986f, 0.337915f, 0.341844f, 0.345773f, 0.349703f,
		0.353632f, 0.357561f, 0.36149f, 0.36542f, 0.369349f, 0.373278f,
		0.377207f, 0.381137f, 0.385066f, 0.388995f, 0.392924f, 0.396854f,
		0.400783f, 0.404712f, 0.408641f, 0.412571f, 0.4165f, 0.420429f,
		0.424358f, 0.428288f, 0.432217f, 0.436146f, 0.440075f, 0.444004f,
		0.447934f, 0.451863f, 0.455792f, 0.459721f, 0.463651f, 0.46758f,
		0.471509f, 0.475438f, 0.479368f, 0.483297f, 0.487226f, 0.491155f,
		0.495085f, 0.499014f, 0.502943f, 0.506872f, 0.510802f, 0.514731f,
		0.51866f, 0.522589f, 0.526519f, 0.530448f, 0.534377f, 0.538306f,
		0.542236f, 0.546165f, 0.550094f, 0.554023f, 0.557953f, 0.561882f,
		0.565811f, 0.56974f, 0.57367f, 0.577599f, 0.581528f, 0.585457f,
		0.589386f, 0.593316f, 0.597245f, 0.601174f, 0.605103f, 0.609033f,
		0.612962f, 0.616891f, 0.62082f, 0.62475f, 0.628679f, 0.632608f,
		0.636537f, 0.640467f, 0.644396f, 0.648325f, 0.652254f, 0.656184f,
		0.660113f, 0.664042f, 0.667971f, 0.671901f, 0.67583f, 0.679759f,
		0.683688f, 0.687618f, 0.691547f, 0.695476f, 0.699405f, 0.703335f,
		0.707264f, 0.711193f, 0.715122f, 0.719051f, 0.722981f, 0.72691f,
		0.730839f, 0.734769f, 0.738698f, 0.742627f, 0.746556f, 0.750485f,
		0.754415f, 0.758344f, 0.762273f, 0.766202f, 0.770132f, 0.774061f,
		0.77799f, 0.781919f, 0.785849f, 0.789778f, 0.793707f, 0.797636f,
		0.801566f, 0.805495f, 0.809424f, 0.813353f, 0.817283f, 0.821212f,
		0.825141f, 0.82907f, 0.833f, 0.836929f, 0.840858f, 0.844787f,
		0.848716f, 0.852646f, 0.856575f, 0.860504f, 0.864433f, 0.868363f,
		0.872292f, 0.876221f, 0.88015f, 0.88408f, 0.888009f, 0.891938f,
		0.895867f, 0.899797f, 0.903726f, 0.907655f, 0.911584f, 0.915514f,
		0.919443f, 0.923372f, 0.927301f, 0.931231f, 0.93516f, 0.939089f,
		0.943018f, 0.946948f, 0.950877f, 0.954806f, 0.958735f, 0.962665f,
		0.966594f, 0.970523f, 0.974452f, 0.978382f, 0.982311f, 0.98624f,
		0.990169f, 0.994098f, 0.998028f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using h1_cable_table1_t = wrap::data<control::cable_table<parameter::plain<h1_switcher_t<NV>, 0>>, 
                                     data::embedded::table<h1_cable_table1_t_data>>;

template <int NV> using h1_sb9_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb9_t = bypass::smoothed<20, h1_sb9_t_<NV>>;
template <int NV>
using h1_switcher1_c0 = parameter::bypass<h1_sb9_t<NV>>;

template <int NV> using h1_sb10_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb10_t = bypass::smoothed<20, h1_sb10_t_<NV>>;
template <int NV>
using h1_switcher1_c1 = parameter::bypass<h1_sb10_t<NV>>;

template <int NV> using h1_sb11_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb11_t = bypass::smoothed<20, h1_sb11_t_<NV>>;
template <int NV>
using h1_switcher1_c2 = parameter::bypass<h1_sb11_t<NV>>;

template <int NV> using h1_sb12_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb12_t = bypass::smoothed<20, h1_sb12_t_<NV>>;
template <int NV>
using h1_switcher1_c3 = parameter::bypass<h1_sb12_t<NV>>;

template <int NV> using h1_sb13_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb13_t = bypass::smoothed<20, h1_sb13_t_<NV>>;
template <int NV>
using h1_switcher1_c4 = parameter::bypass<h1_sb13_t<NV>>;

template <int NV> using h1_sb14_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb14_t = bypass::smoothed<20, h1_sb14_t_<NV>>;
template <int NV>
using h1_switcher1_c5 = parameter::bypass<h1_sb14_t<NV>>;

template <int NV> using h1_sb15_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb15_t = bypass::smoothed<20, h1_sb15_t_<NV>>;
template <int NV>
using h1_switcher1_c6 = parameter::bypass<h1_sb15_t<NV>>;

template <int NV> using h1_sb16_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb16_t = bypass::smoothed<20, h1_sb16_t_<NV>>;
template <int NV>
using h1_switcher1_c7 = parameter::bypass<h1_sb16_t<NV>>;

template <int NV>
using h1_switcher1_multimod = parameter::list<h1_switcher1_c0<NV>, 
                                              h1_switcher1_c1<NV>, 
                                              h1_switcher1_c2<NV>, 
                                              h1_switcher1_c3<NV>, 
                                              h1_switcher1_c4<NV>, 
                                              h1_switcher1_c5<NV>, 
                                              h1_switcher1_c6<NV>, 
                                              h1_switcher1_c7<NV>>;

template <int NV>
using h1_switcher1_t = control::xfader<h1_switcher1_multimod<NV>, 
                                       faders::switcher>;

struct h1_cable_table2_t_data
{
	span<float, 512> data =
	{
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
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.00201124f, 0.00598741f, 0.00996339f, 0.0139394f, 0.0179154f,
		0.0218914f, 0.0258674f, 0.0298434f, 0.0338194f, 0.0377955f, 0.0417715f,
		0.0457475f, 0.0497236f, 0.0536996f, 0.0576755f, 0.0616516f, 0.0656276f,
		0.0696037f, 0.0735797f, 0.0775557f, 0.0815317f, 0.0855077f, 0.0894837f,
		0.0934597f, 0.0974357f, 0.101412f, 0.105388f, 0.109364f, 0.11334f,
		0.117316f, 0.121292f, 0.125268f, 0.129244f, 0.13322f, 0.137196f,
		0.141172f, 0.145148f, 0.149124f, 0.1531f, 0.157076f, 0.161052f,
		0.165028f, 0.169004f, 0.17298f, 0.176956f, 0.180932f, 0.184908f,
		0.188884f, 0.19286f, 0.196836f, 0.200812f, 0.204788f, 0.208764f,
		0.21274f, 0.216716f, 0.220692f, 0.224668f, 0.228644f, 0.23262f,
		0.236596f, 0.240572f, 0.244548f, 0.248524f, 0.252501f, 0.256477f,
		0.260453f, 0.264429f, 0.268405f, 0.272381f, 0.276357f, 0.280333f,
		0.284309f, 0.288285f, 0.292261f, 0.296237f, 0.300213f, 0.304189f,
		0.308165f, 0.312141f, 0.316117f, 0.320093f, 0.324069f, 0.328045f,
		0.332021f, 0.335997f, 0.339973f, 0.343949f, 0.347925f, 0.351901f,
		0.355877f, 0.359853f, 0.363829f, 0.367805f, 0.371781f, 0.375757f,
		0.379733f, 0.383709f, 0.387685f, 0.391661f, 0.395637f, 0.399613f,
		0.403589f, 0.407565f, 0.411541f, 0.415517f, 0.419493f, 0.423469f,
		0.427445f, 0.431421f, 0.435397f, 0.439373f, 0.443349f, 0.447325f,
		0.451302f, 0.455278f, 0.459254f, 0.46323f, 0.467206f, 0.471182f,
		0.475158f, 0.479134f, 0.48311f, 0.487086f, 0.491062f, 0.495038f,
		0.499014f, 0.50299f, 0.506966f, 0.510942f, 0.514918f, 0.518894f,
		0.52287f, 0.526846f, 0.530822f, 0.534798f, 0.538774f, 0.54275f,
		0.546726f, 0.550702f, 0.554678f, 0.558654f, 0.56263f, 0.566606f,
		0.570582f, 0.574558f, 0.578534f, 0.58251f, 0.586486f, 0.590462f,
		0.594438f, 0.598414f, 0.60239f, 0.606366f, 0.610342f, 0.614318f,
		0.618294f, 0.62227f, 0.626246f, 0.630222f, 0.634198f, 0.638174f,
		0.642151f, 0.646127f, 0.650102f, 0.654078f, 0.658054f, 0.662031f,
		0.666007f, 0.669983f, 0.673959f, 0.677935f, 0.681911f, 0.685887f,
		0.689863f, 0.693839f, 0.697815f, 0.701791f, 0.705767f, 0.709743f,
		0.713719f, 0.717695f, 0.721671f, 0.725647f, 0.729623f, 0.733599f,
		0.737575f, 0.741551f, 0.745527f, 0.749503f, 0.753479f, 0.757455f,
		0.761431f, 0.765407f, 0.769383f, 0.773359f, 0.777335f, 0.781311f,
		0.785287f, 0.789263f, 0.793239f, 0.797215f, 0.801191f, 0.805167f,
		0.809143f, 0.813119f, 0.817095f, 0.821071f, 0.825047f, 0.829023f,
		0.832999f, 0.836975f, 0.840951f, 0.844927f, 0.848903f, 0.852879f,
		0.856855f, 0.860831f, 0.864808f, 0.868784f, 0.87276f, 0.876736f,
		0.880712f, 0.884688f, 0.888664f, 0.89264f, 0.896616f, 0.900592f,
		0.904568f, 0.908544f, 0.91252f, 0.916496f, 0.920472f, 0.924448f,
		0.928424f, 0.9324f, 0.936376f, 0.940352f, 0.944328f, 0.948304f,
		0.95228f, 0.956256f, 0.960232f, 0.964208f, 0.968184f, 0.97216f,
		0.976136f, 0.980112f, 0.984088f, 0.988064f, 0.99204f, 0.996016f,
		0.999992f, 1.f
	};
};

template <int NV>
using h1_cable_table2_t = wrap::data<control::cable_table<parameter::plain<h1_switcher1_t<NV>, 0>>, 
                                     data::embedded::table<h1_cable_table2_t_data>>;

template <int NV>
using h1_sb_container_t = container::chain<parameter::empty, 
                                           wrap::fix<1, h1_sb1_t<NV>>, 
                                           h1_sb2_t<NV>, 
                                           h1_sb3_t<NV>, 
                                           h1_sb4_t<NV>, 
                                           h1_sb5_t<NV>, 
                                           h1_sb6_t<NV>, 
                                           h1_sb7_t<NV>, 
                                           h1_sb8_t<NV>>;

template <int NV>
using h1_softbypass_switch9_t = container::chain<parameter::empty, 
                                                 wrap::fix<1, h1_cable_table1_t<NV>>, 
                                                 h1_switcher_t<NV>, 
                                                 h1_sb_container_t<NV>>;

template <int NV>
using h1_sb17_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, h1_softbypass_switch9_t<NV>>>;

template <int NV>
using h1_sb17_t = bypass::smoothed<20, h1_sb17_t_<NV>>;
template <int NV>
using h1_switcher2_c0 = parameter::bypass<h1_sb17_t<NV>>;

template <int NV>
using h1_sb_container1_t = container::chain<parameter::empty, 
                                            wrap::fix<1, h1_sb9_t<NV>>, 
                                            h1_sb10_t<NV>, 
                                            h1_sb11_t<NV>, 
                                            h1_sb12_t<NV>, 
                                            h1_sb13_t<NV>, 
                                            h1_sb14_t<NV>, 
                                            h1_sb15_t<NV>, 
                                            h1_sb16_t<NV>>;

template <int NV>
using h1_softbypass_switch10_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_cable_table2_t<NV>>, 
                                                  h1_switcher1_t<NV>, 
                                                  h1_sb_container1_t<NV>>;

template <int NV>
using h1_sb18_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, h1_softbypass_switch10_t<NV>>>;

template <int NV>
using h1_sb18_t = bypass::smoothed<20, h1_sb18_t_<NV>>;
template <int NV>
using h1_switcher2_c1 = parameter::bypass<h1_sb18_t<NV>>;

template <int NV>
using h1_switcher2_multimod = parameter::list<h1_switcher2_c0<NV>, h1_switcher2_c1<NV>>;

template <int NV>
using h1_switcher2_t = control::xfader<h1_switcher2_multimod<NV>, 
                                       faders::switcher>;

using h1_switcher6_multimod = parameter::list<parameter::empty, parameter::empty>;

using h1_switcher6_t = control::xfader<h1_switcher6_multimod, faders::switcher>;

template <int NV> using h1_sb92_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb92_t = bypass::smoothed<20, h1_sb92_t_<NV>>;
template <int NV>
using h1_switcher15_c0 = parameter::bypass<h1_sb92_t<NV>>;

template <int NV> using h1_sb93_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb93_t = bypass::smoothed<20, h1_sb93_t_<NV>>;
template <int NV>
using h1_switcher15_c1 = parameter::bypass<h1_sb93_t<NV>>;

template <int NV> using h1_sb94_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb94_t = bypass::smoothed<20, h1_sb94_t_<NV>>;
template <int NV>
using h1_switcher15_c2 = parameter::bypass<h1_sb94_t<NV>>;

template <int NV> using h1_sb95_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb95_t = bypass::smoothed<20, h1_sb95_t_<NV>>;
template <int NV>
using h1_switcher15_c3 = parameter::bypass<h1_sb95_t<NV>>;

template <int NV> using h1_sb96_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb96_t = bypass::smoothed<20, h1_sb96_t_<NV>>;
template <int NV>
using h1_switcher15_c4 = parameter::bypass<h1_sb96_t<NV>>;

template <int NV> using h1_sb97_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb97_t = bypass::smoothed<20, h1_sb97_t_<NV>>;
template <int NV>
using h1_switcher15_c5 = parameter::bypass<h1_sb97_t<NV>>;

template <int NV> using h1_sb98_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb98_t = bypass::smoothed<20, h1_sb98_t_<NV>>;
template <int NV>
using h1_switcher15_c6 = parameter::bypass<h1_sb98_t<NV>>;

template <int NV> using h1_sb99_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb99_t = bypass::smoothed<20, h1_sb99_t_<NV>>;
template <int NV>
using h1_switcher15_c7 = parameter::bypass<h1_sb99_t<NV>>;

template <int NV>
using h1_switcher15_multimod = parameter::list<h1_switcher15_c0<NV>, 
                                               h1_switcher15_c1<NV>, 
                                               h1_switcher15_c2<NV>, 
                                               h1_switcher15_c3<NV>, 
                                               h1_switcher15_c4<NV>, 
                                               h1_switcher15_c5<NV>, 
                                               h1_switcher15_c6<NV>, 
                                               h1_switcher15_c7<NV>>;

template <int NV>
using h1_switcher15_t = control::xfader<h1_switcher15_multimod<NV>, 
                                        faders::switcher>;

struct h1_cable_table11_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00392926f, 0.00785851f, 0.0117877f, 0.015717f, 0.0196462f,
		0.0235755f, 0.0275047f, 0.0314339f, 0.0353632f, 0.0392925f, 0.0432217f,
		0.0471509f, 0.0510802f, 0.0550094f, 0.0589386f, 0.0628679f, 0.0667971f,
		0.0707264f, 0.0746557f, 0.0785848f, 0.0825141f, 0.0864434f, 0.0903726f,
		0.0943018f, 0.0982311f, 0.10216f, 0.10609f, 0.110019f, 0.113948f,
		0.117877f, 0.121807f, 0.125736f, 0.129665f, 0.133594f, 0.137524f,
		0.141453f, 0.145382f, 0.149311f, 0.15324f, 0.15717f, 0.161099f,
		0.165028f, 0.168957f, 0.172887f, 0.176816f, 0.180745f, 0.184674f,
		0.188604f, 0.192533f, 0.196462f, 0.200391f, 0.204321f, 0.20825f,
		0.212179f, 0.216108f, 0.220038f, 0.223967f, 0.227896f, 0.231825f,
		0.235755f, 0.239684f, 0.243613f, 0.247542f, 0.251472f, 0.255401f,
		0.25933f, 0.263259f, 0.267189f, 0.271118f, 0.275047f, 0.278976f,
		0.282905f, 0.286835f, 0.290764f, 0.294693f, 0.298622f, 0.302552f,
		0.306481f, 0.31041f, 0.314339f, 0.318269f, 0.322198f, 0.326127f,
		0.330056f, 0.333986f, 0.337915f, 0.341844f, 0.345773f, 0.349703f,
		0.353632f, 0.357561f, 0.36149f, 0.36542f, 0.369349f, 0.373278f,
		0.377207f, 0.381137f, 0.385066f, 0.388995f, 0.392924f, 0.396854f,
		0.400783f, 0.404712f, 0.408641f, 0.412571f, 0.4165f, 0.420429f,
		0.424358f, 0.428288f, 0.432217f, 0.436146f, 0.440075f, 0.444004f,
		0.447934f, 0.451863f, 0.455792f, 0.459721f, 0.463651f, 0.46758f,
		0.471509f, 0.475438f, 0.479368f, 0.483297f, 0.487226f, 0.491155f,
		0.495085f, 0.499014f, 0.502943f, 0.506872f, 0.510802f, 0.514731f,
		0.51866f, 0.522589f, 0.526519f, 0.530448f, 0.534377f, 0.538306f,
		0.542236f, 0.546165f, 0.550094f, 0.554023f, 0.557953f, 0.561882f,
		0.565811f, 0.56974f, 0.57367f, 0.577599f, 0.581528f, 0.585457f,
		0.589386f, 0.593316f, 0.597245f, 0.601174f, 0.605103f, 0.609033f,
		0.612962f, 0.616891f, 0.62082f, 0.62475f, 0.628679f, 0.632608f,
		0.636537f, 0.640467f, 0.644396f, 0.648325f, 0.652254f, 0.656184f,
		0.660113f, 0.664042f, 0.667971f, 0.671901f, 0.67583f, 0.679759f,
		0.683688f, 0.687618f, 0.691547f, 0.695476f, 0.699405f, 0.703335f,
		0.707264f, 0.711193f, 0.715122f, 0.719051f, 0.722981f, 0.72691f,
		0.730839f, 0.734769f, 0.738698f, 0.742627f, 0.746556f, 0.750485f,
		0.754415f, 0.758344f, 0.762273f, 0.766202f, 0.770132f, 0.774061f,
		0.77799f, 0.781919f, 0.785849f, 0.789778f, 0.793707f, 0.797636f,
		0.801566f, 0.805495f, 0.809424f, 0.813353f, 0.817283f, 0.821212f,
		0.825141f, 0.82907f, 0.833f, 0.836929f, 0.840858f, 0.844787f,
		0.848716f, 0.852646f, 0.856575f, 0.860504f, 0.864433f, 0.868363f,
		0.872292f, 0.876221f, 0.88015f, 0.88408f, 0.888009f, 0.891938f,
		0.895867f, 0.899797f, 0.903726f, 0.907655f, 0.911584f, 0.915514f,
		0.919443f, 0.923372f, 0.927301f, 0.931231f, 0.93516f, 0.939089f,
		0.943018f, 0.946948f, 0.950877f, 0.954806f, 0.958735f, 0.962665f,
		0.966594f, 0.970523f, 0.974452f, 0.978382f, 0.982311f, 0.98624f,
		0.990169f, 0.994098f, 0.998028f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using h1_cable_table11_t = wrap::data<control::cable_table<parameter::plain<h1_switcher15_t<NV>, 0>>, 
                                      data::embedded::table<h1_cable_table11_t_data>>;

template <int NV> using h1_sb101_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb101_t = bypass::smoothed<20, h1_sb101_t_<NV>>;
template <int NV>
using h1_switcher16_c0 = parameter::bypass<h1_sb101_t<NV>>;

template <int NV> using h1_sb102_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb102_t = bypass::smoothed<20, h1_sb102_t_<NV>>;
template <int NV>
using h1_switcher16_c1 = parameter::bypass<h1_sb102_t<NV>>;

template <int NV> using h1_sb103_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb103_t = bypass::smoothed<20, h1_sb103_t_<NV>>;
template <int NV>
using h1_switcher16_c2 = parameter::bypass<h1_sb103_t<NV>>;

template <int NV> using h1_sb104_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb104_t = bypass::smoothed<20, h1_sb104_t_<NV>>;
template <int NV>
using h1_switcher16_c3 = parameter::bypass<h1_sb104_t<NV>>;

template <int NV> using h1_sb105_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb105_t = bypass::smoothed<20, h1_sb105_t_<NV>>;
template <int NV>
using h1_switcher16_c4 = parameter::bypass<h1_sb105_t<NV>>;

template <int NV> using h1_sb106_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb106_t = bypass::smoothed<20, h1_sb106_t_<NV>>;
template <int NV>
using h1_switcher16_c5 = parameter::bypass<h1_sb106_t<NV>>;

template <int NV> using h1_sb107_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb107_t = bypass::smoothed<20, h1_sb107_t_<NV>>;
template <int NV>
using h1_switcher16_c6 = parameter::bypass<h1_sb107_t<NV>>;

template <int NV> using h1_sb108_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb108_t = bypass::smoothed<20, h1_sb108_t_<NV>>;
template <int NV>
using h1_switcher16_c7 = parameter::bypass<h1_sb108_t<NV>>;

template <int NV>
using h1_switcher16_multimod = parameter::list<h1_switcher16_c0<NV>, 
                                               h1_switcher16_c1<NV>, 
                                               h1_switcher16_c2<NV>, 
                                               h1_switcher16_c3<NV>, 
                                               h1_switcher16_c4<NV>, 
                                               h1_switcher16_c5<NV>, 
                                               h1_switcher16_c6<NV>, 
                                               h1_switcher16_c7<NV>>;

template <int NV>
using h1_switcher16_t = control::xfader<h1_switcher16_multimod<NV>, 
                                        faders::switcher>;

struct h1_cable_table12_t_data
{
	span<float, 512> data =
	{
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
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.00201124f, 0.00598741f, 0.00996339f, 0.0139394f, 0.0179154f,
		0.0218914f, 0.0258674f, 0.0298434f, 0.0338194f, 0.0377955f, 0.0417715f,
		0.0457475f, 0.0497236f, 0.0536996f, 0.0576755f, 0.0616516f, 0.0656276f,
		0.0696037f, 0.0735797f, 0.0775557f, 0.0815317f, 0.0855077f, 0.0894837f,
		0.0934597f, 0.0974357f, 0.101412f, 0.105388f, 0.109364f, 0.11334f,
		0.117316f, 0.121292f, 0.125268f, 0.129244f, 0.13322f, 0.137196f,
		0.141172f, 0.145148f, 0.149124f, 0.1531f, 0.157076f, 0.161052f,
		0.165028f, 0.169004f, 0.17298f, 0.176956f, 0.180932f, 0.184908f,
		0.188884f, 0.19286f, 0.196836f, 0.200812f, 0.204788f, 0.208764f,
		0.21274f, 0.216716f, 0.220692f, 0.224668f, 0.228644f, 0.23262f,
		0.236596f, 0.240572f, 0.244548f, 0.248524f, 0.252501f, 0.256477f,
		0.260453f, 0.264429f, 0.268405f, 0.272381f, 0.276357f, 0.280333f,
		0.284309f, 0.288285f, 0.292261f, 0.296237f, 0.300213f, 0.304189f,
		0.308165f, 0.312141f, 0.316117f, 0.320093f, 0.324069f, 0.328045f,
		0.332021f, 0.335997f, 0.339973f, 0.343949f, 0.347925f, 0.351901f,
		0.355877f, 0.359853f, 0.363829f, 0.367805f, 0.371781f, 0.375757f,
		0.379733f, 0.383709f, 0.387685f, 0.391661f, 0.395637f, 0.399613f,
		0.403589f, 0.407565f, 0.411541f, 0.415517f, 0.419493f, 0.423469f,
		0.427445f, 0.431421f, 0.435397f, 0.439373f, 0.443349f, 0.447325f,
		0.451302f, 0.455278f, 0.459254f, 0.46323f, 0.467206f, 0.471182f,
		0.475158f, 0.479134f, 0.48311f, 0.487086f, 0.491062f, 0.495038f,
		0.499014f, 0.50299f, 0.506966f, 0.510942f, 0.514918f, 0.518894f,
		0.52287f, 0.526846f, 0.530822f, 0.534798f, 0.538774f, 0.54275f,
		0.546726f, 0.550702f, 0.554678f, 0.558654f, 0.56263f, 0.566606f,
		0.570582f, 0.574558f, 0.578534f, 0.58251f, 0.586486f, 0.590462f,
		0.594438f, 0.598414f, 0.60239f, 0.606366f, 0.610342f, 0.614318f,
		0.618294f, 0.62227f, 0.626246f, 0.630222f, 0.634198f, 0.638174f,
		0.642151f, 0.646127f, 0.650102f, 0.654078f, 0.658054f, 0.662031f,
		0.666007f, 0.669983f, 0.673959f, 0.677935f, 0.681911f, 0.685887f,
		0.689863f, 0.693839f, 0.697815f, 0.701791f, 0.705767f, 0.709743f,
		0.713719f, 0.717695f, 0.721671f, 0.725647f, 0.729623f, 0.733599f,
		0.737575f, 0.741551f, 0.745527f, 0.749503f, 0.753479f, 0.757455f,
		0.761431f, 0.765407f, 0.769383f, 0.773359f, 0.777335f, 0.781311f,
		0.785287f, 0.789263f, 0.793239f, 0.797215f, 0.801191f, 0.805167f,
		0.809143f, 0.813119f, 0.817095f, 0.821071f, 0.825047f, 0.829023f,
		0.832999f, 0.836975f, 0.840951f, 0.844927f, 0.848903f, 0.852879f,
		0.856855f, 0.860831f, 0.864808f, 0.868784f, 0.87276f, 0.876736f,
		0.880712f, 0.884688f, 0.888664f, 0.89264f, 0.896616f, 0.900592f,
		0.904568f, 0.908544f, 0.91252f, 0.916496f, 0.920472f, 0.924448f,
		0.928424f, 0.9324f, 0.936376f, 0.940352f, 0.944328f, 0.948304f,
		0.95228f, 0.956256f, 0.960232f, 0.964208f, 0.968184f, 0.97216f,
		0.976136f, 0.980112f, 0.984088f, 0.988064f, 0.99204f, 0.996016f,
		0.999992f, 1.f
	};
};

template <int NV>
using h1_cable_table12_t = wrap::data<control::cable_table<parameter::plain<h1_switcher16_t<NV>, 0>>, 
                                      data::embedded::table<h1_cable_table12_t_data>>;

template <int NV> using h1_sb56_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb56_t = bypass::smoothed<20, h1_sb56_t_<NV>>;
template <int NV>
using h1_switcher10_c0 = parameter::bypass<h1_sb56_t<NV>>;

template <int NV> using h1_sb57_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb57_t = bypass::smoothed<20, h1_sb57_t_<NV>>;
template <int NV>
using h1_switcher10_c1 = parameter::bypass<h1_sb57_t<NV>>;

template <int NV> using h1_sb58_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb58_t = bypass::smoothed<20, h1_sb58_t_<NV>>;
template <int NV>
using h1_switcher10_c2 = parameter::bypass<h1_sb58_t<NV>>;

template <int NV> using h1_sb59_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb59_t = bypass::smoothed<20, h1_sb59_t_<NV>>;
template <int NV>
using h1_switcher10_c3 = parameter::bypass<h1_sb59_t<NV>>;

template <int NV> using h1_sb60_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb60_t = bypass::smoothed<20, h1_sb60_t_<NV>>;
template <int NV>
using h1_switcher10_c4 = parameter::bypass<h1_sb60_t<NV>>;

template <int NV> using h1_sb61_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb61_t = bypass::smoothed<20, h1_sb61_t_<NV>>;
template <int NV>
using h1_switcher10_c5 = parameter::bypass<h1_sb61_t<NV>>;

template <int NV> using h1_sb62_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb62_t = bypass::smoothed<20, h1_sb62_t_<NV>>;
template <int NV>
using h1_switcher10_c6 = parameter::bypass<h1_sb62_t<NV>>;

template <int NV> using h1_sb63_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb63_t = bypass::smoothed<20, h1_sb63_t_<NV>>;
template <int NV>
using h1_switcher10_c7 = parameter::bypass<h1_sb63_t<NV>>;

template <int NV>
using h1_switcher10_multimod = parameter::list<h1_switcher10_c0<NV>, 
                                               h1_switcher10_c1<NV>, 
                                               h1_switcher10_c2<NV>, 
                                               h1_switcher10_c3<NV>, 
                                               h1_switcher10_c4<NV>, 
                                               h1_switcher10_c5<NV>, 
                                               h1_switcher10_c6<NV>, 
                                               h1_switcher10_c7<NV>>;

template <int NV>
using h1_switcher10_t = control::xfader<h1_switcher10_multimod<NV>, 
                                        faders::switcher>;

struct h1_cable_table7_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00392926f, 0.00785851f, 0.0117877f, 0.015717f, 0.0196462f,
		0.0235755f, 0.0275047f, 0.0314339f, 0.0353632f, 0.0392925f, 0.0432217f,
		0.0471509f, 0.0510802f, 0.0550094f, 0.0589386f, 0.0628679f, 0.0667971f,
		0.0707264f, 0.0746557f, 0.0785848f, 0.0825141f, 0.0864434f, 0.0903726f,
		0.0943018f, 0.0982311f, 0.10216f, 0.10609f, 0.110019f, 0.113948f,
		0.117877f, 0.121807f, 0.125736f, 0.129665f, 0.133594f, 0.137524f,
		0.141453f, 0.145382f, 0.149311f, 0.15324f, 0.15717f, 0.161099f,
		0.165028f, 0.168957f, 0.172887f, 0.176816f, 0.180745f, 0.184674f,
		0.188604f, 0.192533f, 0.196462f, 0.200391f, 0.204321f, 0.20825f,
		0.212179f, 0.216108f, 0.220038f, 0.223967f, 0.227896f, 0.231825f,
		0.235755f, 0.239684f, 0.243613f, 0.247542f, 0.251472f, 0.255401f,
		0.25933f, 0.263259f, 0.267189f, 0.271118f, 0.275047f, 0.278976f,
		0.282905f, 0.286835f, 0.290764f, 0.294693f, 0.298622f, 0.302552f,
		0.306481f, 0.31041f, 0.314339f, 0.318269f, 0.322198f, 0.326127f,
		0.330056f, 0.333986f, 0.337915f, 0.341844f, 0.345773f, 0.349703f,
		0.353632f, 0.357561f, 0.36149f, 0.36542f, 0.369349f, 0.373278f,
		0.377207f, 0.381137f, 0.385066f, 0.388995f, 0.392924f, 0.396854f,
		0.400783f, 0.404712f, 0.408641f, 0.412571f, 0.4165f, 0.420429f,
		0.424358f, 0.428288f, 0.432217f, 0.436146f, 0.440075f, 0.444004f,
		0.447934f, 0.451863f, 0.455792f, 0.459721f, 0.463651f, 0.46758f,
		0.471509f, 0.475438f, 0.479368f, 0.483297f, 0.487226f, 0.491155f,
		0.495085f, 0.499014f, 0.502943f, 0.506872f, 0.510802f, 0.514731f,
		0.51866f, 0.522589f, 0.526519f, 0.530448f, 0.534377f, 0.538306f,
		0.542236f, 0.546165f, 0.550094f, 0.554023f, 0.557953f, 0.561882f,
		0.565811f, 0.56974f, 0.57367f, 0.577599f, 0.581528f, 0.585457f,
		0.589386f, 0.593316f, 0.597245f, 0.601174f, 0.605103f, 0.609033f,
		0.612962f, 0.616891f, 0.62082f, 0.62475f, 0.628679f, 0.632608f,
		0.636537f, 0.640467f, 0.644396f, 0.648325f, 0.652254f, 0.656184f,
		0.660113f, 0.664042f, 0.667971f, 0.671901f, 0.67583f, 0.679759f,
		0.683688f, 0.687618f, 0.691547f, 0.695476f, 0.699405f, 0.703335f,
		0.707264f, 0.711193f, 0.715122f, 0.719051f, 0.722981f, 0.72691f,
		0.730839f, 0.734769f, 0.738698f, 0.742627f, 0.746556f, 0.750485f,
		0.754415f, 0.758344f, 0.762273f, 0.766202f, 0.770132f, 0.774061f,
		0.77799f, 0.781919f, 0.785849f, 0.789778f, 0.793707f, 0.797636f,
		0.801566f, 0.805495f, 0.809424f, 0.813353f, 0.817283f, 0.821212f,
		0.825141f, 0.82907f, 0.833f, 0.836929f, 0.840858f, 0.844787f,
		0.848716f, 0.852646f, 0.856575f, 0.860504f, 0.864433f, 0.868363f,
		0.872292f, 0.876221f, 0.88015f, 0.88408f, 0.888009f, 0.891938f,
		0.895867f, 0.899797f, 0.903726f, 0.907655f, 0.911584f, 0.915514f,
		0.919443f, 0.923372f, 0.927301f, 0.931231f, 0.93516f, 0.939089f,
		0.943018f, 0.946948f, 0.950877f, 0.954806f, 0.958735f, 0.962665f,
		0.966594f, 0.970523f, 0.974452f, 0.978382f, 0.982311f, 0.98624f,
		0.990169f, 0.994098f, 0.998028f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using h1_cable_table7_t = wrap::data<control::cable_table<parameter::plain<h1_switcher10_t<NV>, 0>>, 
                                     data::embedded::table<h1_cable_table7_t_data>>;

template <int NV> using h1_sb65_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb65_t = bypass::smoothed<20, h1_sb65_t_<NV>>;
template <int NV>
using h1_switcher11_c0 = parameter::bypass<h1_sb65_t<NV>>;

template <int NV> using h1_sb66_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb66_t = bypass::smoothed<20, h1_sb66_t_<NV>>;
template <int NV>
using h1_switcher11_c1 = parameter::bypass<h1_sb66_t<NV>>;

template <int NV> using h1_sb67_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb67_t = bypass::smoothed<20, h1_sb67_t_<NV>>;
template <int NV>
using h1_switcher11_c2 = parameter::bypass<h1_sb67_t<NV>>;

template <int NV> using h1_sb68_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb68_t = bypass::smoothed<20, h1_sb68_t_<NV>>;
template <int NV>
using h1_switcher11_c3 = parameter::bypass<h1_sb68_t<NV>>;

template <int NV> using h1_sb69_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb69_t = bypass::smoothed<20, h1_sb69_t_<NV>>;
template <int NV>
using h1_switcher11_c4 = parameter::bypass<h1_sb69_t<NV>>;

template <int NV> using h1_sb70_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb70_t = bypass::smoothed<20, h1_sb70_t_<NV>>;
template <int NV>
using h1_switcher11_c5 = parameter::bypass<h1_sb70_t<NV>>;

template <int NV> using h1_sb71_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb71_t = bypass::smoothed<20, h1_sb71_t_<NV>>;
template <int NV>
using h1_switcher11_c6 = parameter::bypass<h1_sb71_t<NV>>;

template <int NV> using h1_sb72_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb72_t = bypass::smoothed<20, h1_sb72_t_<NV>>;
template <int NV>
using h1_switcher11_c7 = parameter::bypass<h1_sb72_t<NV>>;

template <int NV>
using h1_switcher11_multimod = parameter::list<h1_switcher11_c0<NV>, 
                                               h1_switcher11_c1<NV>, 
                                               h1_switcher11_c2<NV>, 
                                               h1_switcher11_c3<NV>, 
                                               h1_switcher11_c4<NV>, 
                                               h1_switcher11_c5<NV>, 
                                               h1_switcher11_c6<NV>, 
                                               h1_switcher11_c7<NV>>;

template <int NV>
using h1_switcher11_t = control::xfader<h1_switcher11_multimod<NV>, 
                                        faders::switcher>;

struct h1_cable_table8_t_data
{
	span<float, 512> data =
	{
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
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.00201124f, 0.00598741f, 0.00996339f, 0.0139394f, 0.0179154f,
		0.0218914f, 0.0258674f, 0.0298434f, 0.0338194f, 0.0377955f, 0.0417715f,
		0.0457475f, 0.0497236f, 0.0536996f, 0.0576755f, 0.0616516f, 0.0656276f,
		0.0696037f, 0.0735797f, 0.0775557f, 0.0815317f, 0.0855077f, 0.0894837f,
		0.0934597f, 0.0974357f, 0.101412f, 0.105388f, 0.109364f, 0.11334f,
		0.117316f, 0.121292f, 0.125268f, 0.129244f, 0.13322f, 0.137196f,
		0.141172f, 0.145148f, 0.149124f, 0.1531f, 0.157076f, 0.161052f,
		0.165028f, 0.169004f, 0.17298f, 0.176956f, 0.180932f, 0.184908f,
		0.188884f, 0.19286f, 0.196836f, 0.200812f, 0.204788f, 0.208764f,
		0.21274f, 0.216716f, 0.220692f, 0.224668f, 0.228644f, 0.23262f,
		0.236596f, 0.240572f, 0.244548f, 0.248524f, 0.252501f, 0.256477f,
		0.260453f, 0.264429f, 0.268405f, 0.272381f, 0.276357f, 0.280333f,
		0.284309f, 0.288285f, 0.292261f, 0.296237f, 0.300213f, 0.304189f,
		0.308165f, 0.312141f, 0.316117f, 0.320093f, 0.324069f, 0.328045f,
		0.332021f, 0.335997f, 0.339973f, 0.343949f, 0.347925f, 0.351901f,
		0.355877f, 0.359853f, 0.363829f, 0.367805f, 0.371781f, 0.375757f,
		0.379733f, 0.383709f, 0.387685f, 0.391661f, 0.395637f, 0.399613f,
		0.403589f, 0.407565f, 0.411541f, 0.415517f, 0.419493f, 0.423469f,
		0.427445f, 0.431421f, 0.435397f, 0.439373f, 0.443349f, 0.447325f,
		0.451302f, 0.455278f, 0.459254f, 0.46323f, 0.467206f, 0.471182f,
		0.475158f, 0.479134f, 0.48311f, 0.487086f, 0.491062f, 0.495038f,
		0.499014f, 0.50299f, 0.506966f, 0.510942f, 0.514918f, 0.518894f,
		0.52287f, 0.526846f, 0.530822f, 0.534798f, 0.538774f, 0.54275f,
		0.546726f, 0.550702f, 0.554678f, 0.558654f, 0.56263f, 0.566606f,
		0.570582f, 0.574558f, 0.578534f, 0.58251f, 0.586486f, 0.590462f,
		0.594438f, 0.598414f, 0.60239f, 0.606366f, 0.610342f, 0.614318f,
		0.618294f, 0.62227f, 0.626246f, 0.630222f, 0.634198f, 0.638174f,
		0.642151f, 0.646127f, 0.650102f, 0.654078f, 0.658054f, 0.662031f,
		0.666007f, 0.669983f, 0.673959f, 0.677935f, 0.681911f, 0.685887f,
		0.689863f, 0.693839f, 0.697815f, 0.701791f, 0.705767f, 0.709743f,
		0.713719f, 0.717695f, 0.721671f, 0.725647f, 0.729623f, 0.733599f,
		0.737575f, 0.741551f, 0.745527f, 0.749503f, 0.753479f, 0.757455f,
		0.761431f, 0.765407f, 0.769383f, 0.773359f, 0.777335f, 0.781311f,
		0.785287f, 0.789263f, 0.793239f, 0.797215f, 0.801191f, 0.805167f,
		0.809143f, 0.813119f, 0.817095f, 0.821071f, 0.825047f, 0.829023f,
		0.832999f, 0.836975f, 0.840951f, 0.844927f, 0.848903f, 0.852879f,
		0.856855f, 0.860831f, 0.864808f, 0.868784f, 0.87276f, 0.876736f,
		0.880712f, 0.884688f, 0.888664f, 0.89264f, 0.896616f, 0.900592f,
		0.904568f, 0.908544f, 0.91252f, 0.916496f, 0.920472f, 0.924448f,
		0.928424f, 0.9324f, 0.936376f, 0.940352f, 0.944328f, 0.948304f,
		0.95228f, 0.956256f, 0.960232f, 0.964208f, 0.968184f, 0.97216f,
		0.976136f, 0.980112f, 0.984088f, 0.988064f, 0.99204f, 0.996016f,
		0.999992f, 1.f
	};
};

template <int NV>
using h1_cable_table8_t = wrap::data<control::cable_table<parameter::plain<h1_switcher11_t<NV>, 0>>, 
                                     data::embedded::table<h1_cable_table8_t_data>>;

using h1_switcher9_multimod = h1_switcher6_multimod;

using h1_switcher9_t = control::xfader<h1_switcher9_multimod, faders::switcher>;

using h1_switcher18_multimod = h1_switcher6_multimod;

using h1_switcher18_t = control::xfader<h1_switcher18_multimod, faders::switcher>;

template <int NV> using h1_sb110_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb110_t = bypass::smoothed<20, h1_sb110_t_<NV>>;
template <int NV>
using h1_switcher19_c0 = parameter::bypass<h1_sb110_t<NV>>;

template <int NV> using h1_sb111_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb111_t = bypass::smoothed<20, h1_sb111_t_<NV>>;
template <int NV>
using h1_switcher19_c1 = parameter::bypass<h1_sb111_t<NV>>;

template <int NV> using h1_sb112_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb112_t = bypass::smoothed<20, h1_sb112_t_<NV>>;
template <int NV>
using h1_switcher19_c2 = parameter::bypass<h1_sb112_t<NV>>;

template <int NV> using h1_sb113_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb113_t = bypass::smoothed<20, h1_sb113_t_<NV>>;
template <int NV>
using h1_switcher19_c3 = parameter::bypass<h1_sb113_t<NV>>;

template <int NV> using h1_sb114_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb114_t = bypass::smoothed<20, h1_sb114_t_<NV>>;
template <int NV>
using h1_switcher19_c4 = parameter::bypass<h1_sb114_t<NV>>;

template <int NV> using h1_sb115_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb115_t = bypass::smoothed<20, h1_sb115_t_<NV>>;
template <int NV>
using h1_switcher19_c5 = parameter::bypass<h1_sb115_t<NV>>;

template <int NV> using h1_sb116_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb116_t = bypass::smoothed<20, h1_sb116_t_<NV>>;
template <int NV>
using h1_switcher19_c6 = parameter::bypass<h1_sb116_t<NV>>;

template <int NV> using h1_sb117_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb117_t = bypass::smoothed<20, h1_sb117_t_<NV>>;
template <int NV>
using h1_switcher19_c7 = parameter::bypass<h1_sb117_t<NV>>;

template <int NV>
using h1_switcher19_multimod = parameter::list<h1_switcher19_c0<NV>, 
                                               h1_switcher19_c1<NV>, 
                                               h1_switcher19_c2<NV>, 
                                               h1_switcher19_c3<NV>, 
                                               h1_switcher19_c4<NV>, 
                                               h1_switcher19_c5<NV>, 
                                               h1_switcher19_c6<NV>, 
                                               h1_switcher19_c7<NV>>;

template <int NV>
using h1_switcher19_t = control::xfader<h1_switcher19_multimod<NV>, 
                                        faders::switcher>;

struct h1_cable_table13_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00392926f, 0.00785851f, 0.0117877f, 0.015717f, 0.0196462f,
		0.0235755f, 0.0275047f, 0.0314339f, 0.0353632f, 0.0392925f, 0.0432217f,
		0.0471509f, 0.0510802f, 0.0550094f, 0.0589386f, 0.0628679f, 0.0667971f,
		0.0707264f, 0.0746557f, 0.0785848f, 0.0825141f, 0.0864434f, 0.0903726f,
		0.0943018f, 0.0982311f, 0.10216f, 0.10609f, 0.110019f, 0.113948f,
		0.117877f, 0.121807f, 0.125736f, 0.129665f, 0.133594f, 0.137524f,
		0.141453f, 0.145382f, 0.149311f, 0.15324f, 0.15717f, 0.161099f,
		0.165028f, 0.168957f, 0.172887f, 0.176816f, 0.180745f, 0.184674f,
		0.188604f, 0.192533f, 0.196462f, 0.200391f, 0.204321f, 0.20825f,
		0.212179f, 0.216108f, 0.220038f, 0.223967f, 0.227896f, 0.231825f,
		0.235755f, 0.239684f, 0.243613f, 0.247542f, 0.251472f, 0.255401f,
		0.25933f, 0.263259f, 0.267189f, 0.271118f, 0.275047f, 0.278976f,
		0.282905f, 0.286835f, 0.290764f, 0.294693f, 0.298622f, 0.302552f,
		0.306481f, 0.31041f, 0.314339f, 0.318269f, 0.322198f, 0.326127f,
		0.330056f, 0.333986f, 0.337915f, 0.341844f, 0.345773f, 0.349703f,
		0.353632f, 0.357561f, 0.36149f, 0.36542f, 0.369349f, 0.373278f,
		0.377207f, 0.381137f, 0.385066f, 0.388995f, 0.392924f, 0.396854f,
		0.400783f, 0.404712f, 0.408641f, 0.412571f, 0.4165f, 0.420429f,
		0.424358f, 0.428288f, 0.432217f, 0.436146f, 0.440075f, 0.444004f,
		0.447934f, 0.451863f, 0.455792f, 0.459721f, 0.463651f, 0.46758f,
		0.471509f, 0.475438f, 0.479368f, 0.483297f, 0.487226f, 0.491155f,
		0.495085f, 0.499014f, 0.502943f, 0.506872f, 0.510802f, 0.514731f,
		0.51866f, 0.522589f, 0.526519f, 0.530448f, 0.534377f, 0.538306f,
		0.542236f, 0.546165f, 0.550094f, 0.554023f, 0.557953f, 0.561882f,
		0.565811f, 0.56974f, 0.57367f, 0.577599f, 0.581528f, 0.585457f,
		0.589386f, 0.593316f, 0.597245f, 0.601174f, 0.605103f, 0.609033f,
		0.612962f, 0.616891f, 0.62082f, 0.62475f, 0.628679f, 0.632608f,
		0.636537f, 0.640467f, 0.644396f, 0.648325f, 0.652254f, 0.656184f,
		0.660113f, 0.664042f, 0.667971f, 0.671901f, 0.67583f, 0.679759f,
		0.683688f, 0.687618f, 0.691547f, 0.695476f, 0.699405f, 0.703335f,
		0.707264f, 0.711193f, 0.715122f, 0.719051f, 0.722981f, 0.72691f,
		0.730839f, 0.734769f, 0.738698f, 0.742627f, 0.746556f, 0.750485f,
		0.754415f, 0.758344f, 0.762273f, 0.766202f, 0.770132f, 0.774061f,
		0.77799f, 0.781919f, 0.785849f, 0.789778f, 0.793707f, 0.797636f,
		0.801566f, 0.805495f, 0.809424f, 0.813353f, 0.817283f, 0.821212f,
		0.825141f, 0.82907f, 0.833f, 0.836929f, 0.840858f, 0.844787f,
		0.848716f, 0.852646f, 0.856575f, 0.860504f, 0.864433f, 0.868363f,
		0.872292f, 0.876221f, 0.88015f, 0.88408f, 0.888009f, 0.891938f,
		0.895867f, 0.899797f, 0.903726f, 0.907655f, 0.911584f, 0.915514f,
		0.919443f, 0.923372f, 0.927301f, 0.931231f, 0.93516f, 0.939089f,
		0.943018f, 0.946948f, 0.950877f, 0.954806f, 0.958735f, 0.962665f,
		0.966594f, 0.970523f, 0.974452f, 0.978382f, 0.982311f, 0.98624f,
		0.990169f, 0.994098f, 0.998028f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using h1_cable_table13_t = wrap::data<control::cable_table<parameter::plain<h1_switcher19_t<NV>, 0>>, 
                                      data::embedded::table<h1_cable_table13_t_data>>;

template <int NV> using h1_sb119_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb119_t = bypass::smoothed<20, h1_sb119_t_<NV>>;
template <int NV>
using h1_switcher20_c0 = parameter::bypass<h1_sb119_t<NV>>;

template <int NV> using h1_sb120_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb120_t = bypass::smoothed<20, h1_sb120_t_<NV>>;
template <int NV>
using h1_switcher20_c1 = parameter::bypass<h1_sb120_t<NV>>;

template <int NV> using h1_sb121_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb121_t = bypass::smoothed<20, h1_sb121_t_<NV>>;
template <int NV>
using h1_switcher20_c2 = parameter::bypass<h1_sb121_t<NV>>;

template <int NV> using h1_sb122_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb122_t = bypass::smoothed<20, h1_sb122_t_<NV>>;
template <int NV>
using h1_switcher20_c3 = parameter::bypass<h1_sb122_t<NV>>;

template <int NV> using h1_sb123_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb123_t = bypass::smoothed<20, h1_sb123_t_<NV>>;
template <int NV>
using h1_switcher20_c4 = parameter::bypass<h1_sb123_t<NV>>;

template <int NV> using h1_sb124_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb124_t = bypass::smoothed<20, h1_sb124_t_<NV>>;
template <int NV>
using h1_switcher20_c5 = parameter::bypass<h1_sb124_t<NV>>;

template <int NV> using h1_sb125_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb125_t = bypass::smoothed<20, h1_sb125_t_<NV>>;
template <int NV>
using h1_switcher20_c6 = parameter::bypass<h1_sb125_t<NV>>;

template <int NV> using h1_sb126_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb126_t = bypass::smoothed<20, h1_sb126_t_<NV>>;
template <int NV>
using h1_switcher20_c7 = parameter::bypass<h1_sb126_t<NV>>;

template <int NV>
using h1_switcher20_multimod = parameter::list<h1_switcher20_c0<NV>, 
                                               h1_switcher20_c1<NV>, 
                                               h1_switcher20_c2<NV>, 
                                               h1_switcher20_c3<NV>, 
                                               h1_switcher20_c4<NV>, 
                                               h1_switcher20_c5<NV>, 
                                               h1_switcher20_c6<NV>, 
                                               h1_switcher20_c7<NV>>;

template <int NV>
using h1_switcher20_t = control::xfader<h1_switcher20_multimod<NV>, 
                                        faders::switcher>;

struct h1_cable_table14_t_data
{
	span<float, 512> data =
	{
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
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.00201124f, 0.00598741f, 0.00996339f, 0.0139394f, 0.0179154f,
		0.0218914f, 0.0258674f, 0.0298434f, 0.0338194f, 0.0377955f, 0.0417715f,
		0.0457475f, 0.0497236f, 0.0536996f, 0.0576755f, 0.0616516f, 0.0656276f,
		0.0696037f, 0.0735797f, 0.0775557f, 0.0815317f, 0.0855077f, 0.0894837f,
		0.0934597f, 0.0974357f, 0.101412f, 0.105388f, 0.109364f, 0.11334f,
		0.117316f, 0.121292f, 0.125268f, 0.129244f, 0.13322f, 0.137196f,
		0.141172f, 0.145148f, 0.149124f, 0.1531f, 0.157076f, 0.161052f,
		0.165028f, 0.169004f, 0.17298f, 0.176956f, 0.180932f, 0.184908f,
		0.188884f, 0.19286f, 0.196836f, 0.200812f, 0.204788f, 0.208764f,
		0.21274f, 0.216716f, 0.220692f, 0.224668f, 0.228644f, 0.23262f,
		0.236596f, 0.240572f, 0.244548f, 0.248524f, 0.252501f, 0.256477f,
		0.260453f, 0.264429f, 0.268405f, 0.272381f, 0.276357f, 0.280333f,
		0.284309f, 0.288285f, 0.292261f, 0.296237f, 0.300213f, 0.304189f,
		0.308165f, 0.312141f, 0.316117f, 0.320093f, 0.324069f, 0.328045f,
		0.332021f, 0.335997f, 0.339973f, 0.343949f, 0.347925f, 0.351901f,
		0.355877f, 0.359853f, 0.363829f, 0.367805f, 0.371781f, 0.375757f,
		0.379733f, 0.383709f, 0.387685f, 0.391661f, 0.395637f, 0.399613f,
		0.403589f, 0.407565f, 0.411541f, 0.415517f, 0.419493f, 0.423469f,
		0.427445f, 0.431421f, 0.435397f, 0.439373f, 0.443349f, 0.447325f,
		0.451302f, 0.455278f, 0.459254f, 0.46323f, 0.467206f, 0.471182f,
		0.475158f, 0.479134f, 0.48311f, 0.487086f, 0.491062f, 0.495038f,
		0.499014f, 0.50299f, 0.506966f, 0.510942f, 0.514918f, 0.518894f,
		0.52287f, 0.526846f, 0.530822f, 0.534798f, 0.538774f, 0.54275f,
		0.546726f, 0.550702f, 0.554678f, 0.558654f, 0.56263f, 0.566606f,
		0.570582f, 0.574558f, 0.578534f, 0.58251f, 0.586486f, 0.590462f,
		0.594438f, 0.598414f, 0.60239f, 0.606366f, 0.610342f, 0.614318f,
		0.618294f, 0.62227f, 0.626246f, 0.630222f, 0.634198f, 0.638174f,
		0.642151f, 0.646127f, 0.650102f, 0.654078f, 0.658054f, 0.662031f,
		0.666007f, 0.669983f, 0.673959f, 0.677935f, 0.681911f, 0.685887f,
		0.689863f, 0.693839f, 0.697815f, 0.701791f, 0.705767f, 0.709743f,
		0.713719f, 0.717695f, 0.721671f, 0.725647f, 0.729623f, 0.733599f,
		0.737575f, 0.741551f, 0.745527f, 0.749503f, 0.753479f, 0.757455f,
		0.761431f, 0.765407f, 0.769383f, 0.773359f, 0.777335f, 0.781311f,
		0.785287f, 0.789263f, 0.793239f, 0.797215f, 0.801191f, 0.805167f,
		0.809143f, 0.813119f, 0.817095f, 0.821071f, 0.825047f, 0.829023f,
		0.832999f, 0.836975f, 0.840951f, 0.844927f, 0.848903f, 0.852879f,
		0.856855f, 0.860831f, 0.864808f, 0.868784f, 0.87276f, 0.876736f,
		0.880712f, 0.884688f, 0.888664f, 0.89264f, 0.896616f, 0.900592f,
		0.904568f, 0.908544f, 0.91252f, 0.916496f, 0.920472f, 0.924448f,
		0.928424f, 0.9324f, 0.936376f, 0.940352f, 0.944328f, 0.948304f,
		0.95228f, 0.956256f, 0.960232f, 0.964208f, 0.968184f, 0.97216f,
		0.976136f, 0.980112f, 0.984088f, 0.988064f, 0.99204f, 0.996016f,
		0.999992f, 1.f
	};
};

template <int NV>
using h1_cable_table14_t = wrap::data<control::cable_table<parameter::plain<h1_switcher20_t<NV>, 0>>, 
                                      data::embedded::table<h1_cable_table14_t_data>>;

template <int NV> using h1_sb27_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb27_t = bypass::smoothed<20, h1_sb27_t_<NV>>;
template <int NV>
using h1_switcher5_c0 = parameter::bypass<h1_sb27_t<NV>>;

template <int NV> using h1_sb28_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb28_t = bypass::smoothed<20, h1_sb28_t_<NV>>;
template <int NV>
using h1_switcher5_c1 = parameter::bypass<h1_sb28_t<NV>>;

template <int NV> using h1_sb29_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb29_t = bypass::smoothed<20, h1_sb29_t_<NV>>;
template <int NV>
using h1_switcher5_c2 = parameter::bypass<h1_sb29_t<NV>>;

template <int NV> using h1_sb30_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb30_t = bypass::smoothed<20, h1_sb30_t_<NV>>;
template <int NV>
using h1_switcher5_c3 = parameter::bypass<h1_sb30_t<NV>>;

template <int NV> using h1_sb31_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb31_t = bypass::smoothed<20, h1_sb31_t_<NV>>;
template <int NV>
using h1_switcher5_c4 = parameter::bypass<h1_sb31_t<NV>>;

template <int NV> using h1_sb32_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb32_t = bypass::smoothed<20, h1_sb32_t_<NV>>;
template <int NV>
using h1_switcher5_c5 = parameter::bypass<h1_sb32_t<NV>>;

template <int NV> using h1_sb33_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb33_t = bypass::smoothed<20, h1_sb33_t_<NV>>;
template <int NV>
using h1_switcher5_c6 = parameter::bypass<h1_sb33_t<NV>>;

template <int NV>
using h1_switcher5_multimod = parameter::list<h1_switcher5_c0<NV>, 
                                              h1_switcher5_c1<NV>, 
                                              h1_switcher5_c2<NV>, 
                                              h1_switcher5_c3<NV>, 
                                              h1_switcher5_c4<NV>, 
                                              h1_switcher5_c5<NV>, 
                                              h1_switcher5_c6<NV>>;

template <int NV>
using h1_switcher5_t = control::xfader<h1_switcher5_multimod<NV>, 
                                       faders::switcher>;

template <int NV> using h1_sb128_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb128_t = bypass::smoothed<20, h1_sb128_t_<NV>>;
template <int NV>
using h1_switcher21_c0 = parameter::bypass<h1_sb128_t<NV>>;

template <int NV> using h1_sb129_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb129_t = bypass::smoothed<20, h1_sb129_t_<NV>>;
template <int NV>
using h1_switcher21_c1 = parameter::bypass<h1_sb129_t<NV>>;

template <int NV> using h1_sb130_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb130_t = bypass::smoothed<20, h1_sb130_t_<NV>>;
template <int NV>
using h1_switcher21_c2 = parameter::bypass<h1_sb130_t<NV>>;

template <int NV> using h1_sb131_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb131_t = bypass::smoothed<20, h1_sb131_t_<NV>>;
template <int NV>
using h1_switcher21_c3 = parameter::bypass<h1_sb131_t<NV>>;

template <int NV> using h1_sb132_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb132_t = bypass::smoothed<20, h1_sb132_t_<NV>>;
template <int NV>
using h1_switcher21_c4 = parameter::bypass<h1_sb132_t<NV>>;

template <int NV> using h1_sb133_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb133_t = bypass::smoothed<20, h1_sb133_t_<NV>>;
template <int NV>
using h1_switcher21_c5 = parameter::bypass<h1_sb133_t<NV>>;

template <int NV> using h1_sb134_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb134_t = bypass::smoothed<20, h1_sb134_t_<NV>>;
template <int NV>
using h1_switcher21_c6 = parameter::bypass<h1_sb134_t<NV>>;

template <int NV> using h1_sb135_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb135_t = bypass::smoothed<20, h1_sb135_t_<NV>>;
template <int NV>
using h1_switcher21_c7 = parameter::bypass<h1_sb135_t<NV>>;

template <int NV>
using h1_switcher21_multimod = parameter::list<h1_switcher21_c0<NV>, 
                                               h1_switcher21_c1<NV>, 
                                               h1_switcher21_c2<NV>, 
                                               h1_switcher21_c3<NV>, 
                                               h1_switcher21_c4<NV>, 
                                               h1_switcher21_c5<NV>, 
                                               h1_switcher21_c6<NV>, 
                                               h1_switcher21_c7<NV>>;

template <int NV>
using h1_switcher21_t = control::xfader<h1_switcher21_multimod<NV>, 
                                        faders::switcher>;

struct h1_cable_table15_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00392926f, 0.00785851f, 0.0117877f, 0.015717f, 0.0196462f,
		0.0235755f, 0.0275047f, 0.0314339f, 0.0353632f, 0.0392925f, 0.0432217f,
		0.0471509f, 0.0510802f, 0.0550094f, 0.0589386f, 0.0628679f, 0.0667971f,
		0.0707264f, 0.0746557f, 0.0785848f, 0.0825141f, 0.0864434f, 0.0903726f,
		0.0943018f, 0.0982311f, 0.10216f, 0.10609f, 0.110019f, 0.113948f,
		0.117877f, 0.121807f, 0.125736f, 0.129665f, 0.133594f, 0.137524f,
		0.141453f, 0.145382f, 0.149311f, 0.15324f, 0.15717f, 0.161099f,
		0.165028f, 0.168957f, 0.172887f, 0.176816f, 0.180745f, 0.184674f,
		0.188604f, 0.192533f, 0.196462f, 0.200391f, 0.204321f, 0.20825f,
		0.212179f, 0.216108f, 0.220038f, 0.223967f, 0.227896f, 0.231825f,
		0.235755f, 0.239684f, 0.243613f, 0.247542f, 0.251472f, 0.255401f,
		0.25933f, 0.263259f, 0.267189f, 0.271118f, 0.275047f, 0.278976f,
		0.282905f, 0.286835f, 0.290764f, 0.294693f, 0.298622f, 0.302552f,
		0.306481f, 0.31041f, 0.314339f, 0.318269f, 0.322198f, 0.326127f,
		0.330056f, 0.333986f, 0.337915f, 0.341844f, 0.345773f, 0.349703f,
		0.353632f, 0.357561f, 0.36149f, 0.36542f, 0.369349f, 0.373278f,
		0.377207f, 0.381137f, 0.385066f, 0.388995f, 0.392924f, 0.396854f,
		0.400783f, 0.404712f, 0.408641f, 0.412571f, 0.4165f, 0.420429f,
		0.424358f, 0.428288f, 0.432217f, 0.436146f, 0.440075f, 0.444004f,
		0.447934f, 0.451863f, 0.455792f, 0.459721f, 0.463651f, 0.46758f,
		0.471509f, 0.475438f, 0.479368f, 0.483297f, 0.487226f, 0.491155f,
		0.495085f, 0.499014f, 0.502943f, 0.506872f, 0.510802f, 0.514731f,
		0.51866f, 0.522589f, 0.526519f, 0.530448f, 0.534377f, 0.538306f,
		0.542236f, 0.546165f, 0.550094f, 0.554023f, 0.557953f, 0.561882f,
		0.565811f, 0.56974f, 0.57367f, 0.577599f, 0.581528f, 0.585457f,
		0.589386f, 0.593316f, 0.597245f, 0.601174f, 0.605103f, 0.609033f,
		0.612962f, 0.616891f, 0.62082f, 0.62475f, 0.628679f, 0.632608f,
		0.636537f, 0.640467f, 0.644396f, 0.648325f, 0.652254f, 0.656184f,
		0.660113f, 0.664042f, 0.667971f, 0.671901f, 0.67583f, 0.679759f,
		0.683688f, 0.687618f, 0.691547f, 0.695476f, 0.699405f, 0.703335f,
		0.707264f, 0.711193f, 0.715122f, 0.719051f, 0.722981f, 0.72691f,
		0.730839f, 0.734769f, 0.738698f, 0.742627f, 0.746556f, 0.750485f,
		0.754415f, 0.758344f, 0.762273f, 0.766202f, 0.770132f, 0.774061f,
		0.77799f, 0.781919f, 0.785849f, 0.789778f, 0.793707f, 0.797636f,
		0.801566f, 0.805495f, 0.809424f, 0.813353f, 0.817283f, 0.821212f,
		0.825141f, 0.82907f, 0.833f, 0.836929f, 0.840858f, 0.844787f,
		0.848716f, 0.852646f, 0.856575f, 0.860504f, 0.864433f, 0.868363f,
		0.872292f, 0.876221f, 0.88015f, 0.88408f, 0.888009f, 0.891938f,
		0.895867f, 0.899797f, 0.903726f, 0.907655f, 0.911584f, 0.915514f,
		0.919443f, 0.923372f, 0.927301f, 0.931231f, 0.93516f, 0.939089f,
		0.943018f, 0.946948f, 0.950877f, 0.954806f, 0.958735f, 0.962665f,
		0.966594f, 0.970523f, 0.974452f, 0.978382f, 0.982311f, 0.98624f,
		0.990169f, 0.994098f, 0.998028f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using h1_cable_table15_t = wrap::data<control::cable_table<parameter::plain<h1_switcher21_t<NV>, 0>>, 
                                      data::embedded::table<h1_cable_table15_t_data>>;

template <int NV>
using h1_sb_container22_t = container::chain<parameter::empty, 
                                             wrap::fix<1, h1_sb128_t<NV>>, 
                                             h1_sb129_t<NV>, 
                                             h1_sb130_t<NV>, 
                                             h1_sb131_t<NV>, 
                                             h1_sb132_t<NV>, 
                                             h1_sb133_t<NV>, 
                                             h1_sb134_t<NV>, 
                                             h1_sb135_t<NV>>;

template <int NV>
using h1_softbypass_switch24_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_cable_table15_t<NV>>, 
                                                  h1_switcher21_t<NV>, 
                                                  h1_sb_container22_t<NV>>;

template <int NV>
using h1_sb127_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, h1_softbypass_switch24_t<NV>>>;

template <int NV>
using h1_sb127_t = bypass::smoothed<20, h1_sb127_t_<NV>>;
template <int NV>
using h1_switcher17_c0 = parameter::bypass<h1_sb127_t<NV>>;

template <int NV> using h1_sb137_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb137_t = bypass::smoothed<20, h1_sb137_t_<NV>>;
template <int NV>
using h1_switcher22_c0 = parameter::bypass<h1_sb137_t<NV>>;

template <int NV> using h1_sb138_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb138_t = bypass::smoothed<20, h1_sb138_t_<NV>>;
template <int NV>
using h1_switcher22_c1 = parameter::bypass<h1_sb138_t<NV>>;

template <int NV> using h1_sb139_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb139_t = bypass::smoothed<20, h1_sb139_t_<NV>>;
template <int NV>
using h1_switcher22_c2 = parameter::bypass<h1_sb139_t<NV>>;

template <int NV> using h1_sb140_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb140_t = bypass::smoothed<20, h1_sb140_t_<NV>>;
template <int NV>
using h1_switcher22_c3 = parameter::bypass<h1_sb140_t<NV>>;

template <int NV> using h1_sb141_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb141_t = bypass::smoothed<20, h1_sb141_t_<NV>>;
template <int NV>
using h1_switcher22_c4 = parameter::bypass<h1_sb141_t<NV>>;

template <int NV> using h1_sb142_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb142_t = bypass::smoothed<20, h1_sb142_t_<NV>>;
template <int NV>
using h1_switcher22_c5 = parameter::bypass<h1_sb142_t<NV>>;

template <int NV> using h1_sb143_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb143_t = bypass::smoothed<20, h1_sb143_t_<NV>>;
template <int NV>
using h1_switcher22_c6 = parameter::bypass<h1_sb143_t<NV>>;

template <int NV> using h1_sb144_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb144_t = bypass::smoothed<20, h1_sb144_t_<NV>>;
template <int NV>
using h1_switcher22_c7 = parameter::bypass<h1_sb144_t<NV>>;

template <int NV>
using h1_switcher22_multimod = parameter::list<h1_switcher22_c0<NV>, 
                                               h1_switcher22_c1<NV>, 
                                               h1_switcher22_c2<NV>, 
                                               h1_switcher22_c3<NV>, 
                                               h1_switcher22_c4<NV>, 
                                               h1_switcher22_c5<NV>, 
                                               h1_switcher22_c6<NV>, 
                                               h1_switcher22_c7<NV>>;

template <int NV>
using h1_switcher22_t = control::xfader<h1_switcher22_multimod<NV>, 
                                        faders::switcher>;

struct h1_cable_table16_t_data
{
	span<float, 512> data =
	{
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
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.00201124f, 0.00598741f, 0.00996339f, 0.0139394f, 0.0179154f,
		0.0218914f, 0.0258674f, 0.0298434f, 0.0338194f, 0.0377955f, 0.0417715f,
		0.0457475f, 0.0497236f, 0.0536996f, 0.0576755f, 0.0616516f, 0.0656276f,
		0.0696037f, 0.0735797f, 0.0775557f, 0.0815317f, 0.0855077f, 0.0894837f,
		0.0934597f, 0.0974357f, 0.101412f, 0.105388f, 0.109364f, 0.11334f,
		0.117316f, 0.121292f, 0.125268f, 0.129244f, 0.13322f, 0.137196f,
		0.141172f, 0.145148f, 0.149124f, 0.1531f, 0.157076f, 0.161052f,
		0.165028f, 0.169004f, 0.17298f, 0.176956f, 0.180932f, 0.184908f,
		0.188884f, 0.19286f, 0.196836f, 0.200812f, 0.204788f, 0.208764f,
		0.21274f, 0.216716f, 0.220692f, 0.224668f, 0.228644f, 0.23262f,
		0.236596f, 0.240572f, 0.244548f, 0.248524f, 0.252501f, 0.256477f,
		0.260453f, 0.264429f, 0.268405f, 0.272381f, 0.276357f, 0.280333f,
		0.284309f, 0.288285f, 0.292261f, 0.296237f, 0.300213f, 0.304189f,
		0.308165f, 0.312141f, 0.316117f, 0.320093f, 0.324069f, 0.328045f,
		0.332021f, 0.335997f, 0.339973f, 0.343949f, 0.347925f, 0.351901f,
		0.355877f, 0.359853f, 0.363829f, 0.367805f, 0.371781f, 0.375757f,
		0.379733f, 0.383709f, 0.387685f, 0.391661f, 0.395637f, 0.399613f,
		0.403589f, 0.407565f, 0.411541f, 0.415517f, 0.419493f, 0.423469f,
		0.427445f, 0.431421f, 0.435397f, 0.439373f, 0.443349f, 0.447325f,
		0.451302f, 0.455278f, 0.459254f, 0.46323f, 0.467206f, 0.471182f,
		0.475158f, 0.479134f, 0.48311f, 0.487086f, 0.491062f, 0.495038f,
		0.499014f, 0.50299f, 0.506966f, 0.510942f, 0.514918f, 0.518894f,
		0.52287f, 0.526846f, 0.530822f, 0.534798f, 0.538774f, 0.54275f,
		0.546726f, 0.550702f, 0.554678f, 0.558654f, 0.56263f, 0.566606f,
		0.570582f, 0.574558f, 0.578534f, 0.58251f, 0.586486f, 0.590462f,
		0.594438f, 0.598414f, 0.60239f, 0.606366f, 0.610342f, 0.614318f,
		0.618294f, 0.62227f, 0.626246f, 0.630222f, 0.634198f, 0.638174f,
		0.642151f, 0.646127f, 0.650102f, 0.654078f, 0.658054f, 0.662031f,
		0.666007f, 0.669983f, 0.673959f, 0.677935f, 0.681911f, 0.685887f,
		0.689863f, 0.693839f, 0.697815f, 0.701791f, 0.705767f, 0.709743f,
		0.713719f, 0.717695f, 0.721671f, 0.725647f, 0.729623f, 0.733599f,
		0.737575f, 0.741551f, 0.745527f, 0.749503f, 0.753479f, 0.757455f,
		0.761431f, 0.765407f, 0.769383f, 0.773359f, 0.777335f, 0.781311f,
		0.785287f, 0.789263f, 0.793239f, 0.797215f, 0.801191f, 0.805167f,
		0.809143f, 0.813119f, 0.817095f, 0.821071f, 0.825047f, 0.829023f,
		0.832999f, 0.836975f, 0.840951f, 0.844927f, 0.848903f, 0.852879f,
		0.856855f, 0.860831f, 0.864808f, 0.868784f, 0.87276f, 0.876736f,
		0.880712f, 0.884688f, 0.888664f, 0.89264f, 0.896616f, 0.900592f,
		0.904568f, 0.908544f, 0.91252f, 0.916496f, 0.920472f, 0.924448f,
		0.928424f, 0.9324f, 0.936376f, 0.940352f, 0.944328f, 0.948304f,
		0.95228f, 0.956256f, 0.960232f, 0.964208f, 0.968184f, 0.97216f,
		0.976136f, 0.980112f, 0.984088f, 0.988064f, 0.99204f, 0.996016f,
		0.999992f, 1.f
	};
};

template <int NV>
using h1_cable_table16_t = wrap::data<control::cable_table<parameter::plain<h1_switcher22_t<NV>, 0>>, 
                                      data::embedded::table<h1_cable_table16_t_data>>;

template <int NV>
using h1_sb_container23_t = container::chain<parameter::empty, 
                                             wrap::fix<1, h1_sb137_t<NV>>, 
                                             h1_sb138_t<NV>, 
                                             h1_sb139_t<NV>, 
                                             h1_sb140_t<NV>, 
                                             h1_sb141_t<NV>, 
                                             h1_sb142_t<NV>, 
                                             h1_sb143_t<NV>, 
                                             h1_sb144_t<NV>>;

template <int NV>
using h1_softbypass_switch25_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_cable_table16_t<NV>>, 
                                                  h1_switcher22_t<NV>, 
                                                  h1_sb_container23_t<NV>>;

template <int NV>
using h1_sb136_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, h1_softbypass_switch25_t<NV>>>;

template <int NV>
using h1_sb136_t = bypass::smoothed<20, h1_sb136_t_<NV>>;
template <int NV>
using h1_switcher17_c1 = parameter::bypass<h1_sb136_t<NV>>;

template <int NV>
using h1_switcher17_multimod = parameter::list<h1_switcher17_c0<NV>, h1_switcher17_c1<NV>>;

template <int NV>
using h1_switcher17_t = control::xfader<h1_switcher17_multimod<NV>, 
                                        faders::switcher>;

template <int NV>
using pma11_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<h1_cable_table1_t<NV>, 0>, 
                                   parameter::plain<h1_cable_table2_t<NV>, 0>, 
                                   parameter::plain<h1_switcher2_t<NV>, 0>, 
                                   parameter::plain<h1_switcher6_t, 0>, 
                                   parameter::plain<h1_cable_table11_t<NV>, 0>, 
                                   parameter::plain<h1_cable_table12_t<NV>, 0>, 
                                   parameter::plain<h1_cable_table7_t<NV>, 0>, 
                                   parameter::plain<h1_cable_table8_t<NV>, 0>, 
                                   parameter::plain<h1_switcher9_t, 0>, 
                                   parameter::plain<h1_switcher18_t, 0>, 
                                   parameter::plain<h1_cable_table13_t<NV>, 0>, 
                                   parameter::plain<h1_cable_table14_t<NV>, 0>, 
                                   parameter::plain<h1_switcher5_t<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<h1_switcher17_t<NV>, 0>, 
                                   parameter::plain<h1_cable_table15_t<NV>, 0>, 
                                   parameter::plain<h1_cable_table16_t<NV>, 0>>;

template <int NV>
using pma11_t = control::pma<NV, pma11_mod<NV>>;

template <int NV>
using h1_sb_container2_t = container::chain<parameter::empty, 
                                            wrap::fix<1, h1_sb17_t<NV>>, 
                                            h1_sb18_t<NV>>;

template <int NV>
using h1_softbypass_switch3_t = container::chain<parameter::empty, 
                                                 wrap::fix<1, h1_switcher2_t<NV>>, 
                                                 h1_sb_container2_t<NV>>;

template <int NV>
using h1_harm_t = container::chain<parameter::empty, 
                                   wrap::fix<1, h1_softbypass_switch3_t<NV>>>;

template <int NV>
using h1_sb_container16_t = container::chain<parameter::empty, 
                                             wrap::fix<1, h1_sb92_t<NV>>, 
                                             h1_sb93_t<NV>, 
                                             h1_sb94_t<NV>, 
                                             h1_sb95_t<NV>, 
                                             h1_sb96_t<NV>, 
                                             h1_sb97_t<NV>, 
                                             h1_sb98_t<NV>, 
                                             h1_sb99_t<NV>>;

template <int NV>
using h1_softbypass_switch19_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_cable_table11_t<NV>>, 
                                                  h1_switcher15_t<NV>, 
                                                  h1_sb_container16_t<NV>>;

template <int NV>
using h1_sb91_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, h1_softbypass_switch19_t<NV>>>;

template <int NV>
using h1_sb91_t = bypass::smoothed<20, h1_sb91_t_<NV>>;

template <int NV>
using h1_sb_container17_t = container::chain<parameter::empty, 
                                             wrap::fix<1, h1_sb101_t<NV>>, 
                                             h1_sb102_t<NV>, 
                                             h1_sb103_t<NV>, 
                                             h1_sb104_t<NV>, 
                                             h1_sb105_t<NV>, 
                                             h1_sb106_t<NV>, 
                                             h1_sb107_t<NV>, 
                                             h1_sb108_t<NV>>;

template <int NV>
using h1_softbypass_switch20_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_cable_table12_t<NV>>, 
                                                  h1_switcher16_t<NV>, 
                                                  h1_sb_container17_t<NV>>;

template <int NV>
using h1_sb100_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, h1_softbypass_switch20_t<NV>>>;

template <int NV>
using h1_sb100_t = bypass::smoothed<20, h1_sb100_t_<NV>>;

template <int NV>
using h1_sb_container15_t = container::chain<parameter::empty, 
                                             wrap::fix<1, h1_sb91_t<NV>>, 
                                             h1_sb100_t<NV>>;

template <int NV>
using h1_softbypass_switch5_t = container::chain<parameter::empty, 
                                                 wrap::fix<1, h1_switcher6_t>, 
                                                 h1_sb_container15_t<NV>>;

template <int NV>
using h1_chromatic_t = container::chain<parameter::empty, 
                                        wrap::fix<1, h1_softbypass_switch5_t<NV>>>;

template <int NV>
using h1_sb_container10_t = container::chain<parameter::empty, 
                                             wrap::fix<1, h1_sb56_t<NV>>, 
                                             h1_sb57_t<NV>, 
                                             h1_sb58_t<NV>, 
                                             h1_sb59_t<NV>, 
                                             h1_sb60_t<NV>, 
                                             h1_sb61_t<NV>, 
                                             h1_sb62_t<NV>, 
                                             h1_sb63_t<NV>>;

template <int NV>
using h1_softbypass_switch15_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_cable_table7_t<NV>>, 
                                                  h1_switcher10_t<NV>, 
                                                  h1_sb_container10_t<NV>>;

template <int NV>
using h1_sb55_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, h1_softbypass_switch15_t<NV>>>;

template <int NV>
using h1_sb55_t = bypass::smoothed<20, h1_sb55_t_<NV>>;

template <int NV>
using h1_sb_container11_t = container::chain<parameter::empty, 
                                             wrap::fix<1, h1_sb65_t<NV>>, 
                                             h1_sb66_t<NV>, 
                                             h1_sb67_t<NV>, 
                                             h1_sb68_t<NV>, 
                                             h1_sb69_t<NV>, 
                                             h1_sb70_t<NV>, 
                                             h1_sb71_t<NV>, 
                                             h1_sb72_t<NV>>;

template <int NV>
using h1_softbypass_switch16_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_cable_table8_t<NV>>, 
                                                  h1_switcher11_t<NV>, 
                                                  h1_sb_container11_t<NV>>;

template <int NV>
using h1_sb64_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, h1_softbypass_switch16_t<NV>>>;

template <int NV>
using h1_sb64_t = bypass::smoothed<20, h1_sb64_t_<NV>>;

template <int NV>
using h1_sb_container9_t = container::chain<parameter::empty, 
                                            wrap::fix<1, h1_sb55_t<NV>>, 
                                            h1_sb64_t<NV>>;

template <int NV>
using h1_softbypass_switch6_t = container::chain<parameter::empty, 
                                                 wrap::fix<1, h1_switcher9_t>, 
                                                 h1_sb_container9_t<NV>>;

template <int NV>
using h1_min_t = container::chain<parameter::empty, 
                                  wrap::fix<1, h1_softbypass_switch6_t<NV>>>;

template <int NV>
using h1_sb_container19_t = container::chain<parameter::empty, 
                                             wrap::fix<1, h1_sb110_t<NV>>, 
                                             h1_sb111_t<NV>, 
                                             h1_sb112_t<NV>, 
                                             h1_sb113_t<NV>, 
                                             h1_sb114_t<NV>, 
                                             h1_sb115_t<NV>, 
                                             h1_sb116_t<NV>, 
                                             h1_sb117_t<NV>>;

template <int NV>
using h1_softbypass_switch21_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_cable_table13_t<NV>>, 
                                                  h1_switcher19_t<NV>, 
                                                  h1_sb_container19_t<NV>>;

template <int NV>
using h1_sb109_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, h1_softbypass_switch21_t<NV>>>;

template <int NV>
using h1_sb109_t = bypass::smoothed<20, h1_sb109_t_<NV>>;

template <int NV>
using h1_sb_container20_t = container::chain<parameter::empty, 
                                             wrap::fix<1, h1_sb119_t<NV>>, 
                                             h1_sb120_t<NV>, 
                                             h1_sb121_t<NV>, 
                                             h1_sb122_t<NV>, 
                                             h1_sb123_t<NV>, 
                                             h1_sb124_t<NV>, 
                                             h1_sb125_t<NV>, 
                                             h1_sb126_t<NV>>;

template <int NV>
using h1_softbypass_switch22_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_cable_table14_t<NV>>, 
                                                  h1_switcher20_t<NV>, 
                                                  h1_sb_container20_t<NV>>;

template <int NV>
using h1_sb118_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, h1_softbypass_switch22_t<NV>>>;

template <int NV>
using h1_sb118_t = bypass::smoothed<20, h1_sb118_t_<NV>>;

template <int NV>
using h1_sb_container18_t = container::chain<parameter::empty, 
                                             wrap::fix<1, h1_sb109_t<NV>>, 
                                             h1_sb118_t<NV>>;

template <int NV>
using h1_softbypass_switch12_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_switcher18_t>, 
                                                  h1_sb_container18_t<NV>>;

template <int NV>
using h1_min1_t = container::chain<parameter::empty, 
                                   wrap::fix<1, h1_softbypass_switch12_t<NV>>>;

template <int NV>
using h1_sb_container21_t = container::chain<parameter::empty, 
                                             wrap::fix<1, h1_sb127_t<NV>>, 
                                             h1_sb136_t<NV>>;

template <int NV>
using h1_softbypass_switch8_t = container::chain<parameter::empty, 
                                                 wrap::fix<1, h1_switcher17_t<NV>>, 
                                                 h1_sb_container21_t<NV>>;

template <int NV>
using h1_Det1_t = container::chain<parameter::empty, 
                                   wrap::fix<1, h1_softbypass_switch8_t<NV>>>;

template <int NV>
using h1_sb_container5_t = container::chain<parameter::empty, 
                                            wrap::fix<1, h1_sb27_t<NV>>, 
                                            h1_sb28_t<NV>, 
                                            h1_sb29_t<NV>, 
                                            h1_sb30_t<NV>, 
                                            h1_sb31_t<NV>, 
                                            h1_sb32_t<NV>, 
                                            h1_sb33_t<NV>>;

template <int NV>
using h1_softbypass_switch23_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_switcher5_t<NV>>, 
                                                  h1_sb_container5_t<NV>>;

template <int NV>
using h1_5ths_t = container::chain<parameter::empty, 
                                   wrap::fix<1, h1_softbypass_switch23_t<NV>>>;

template <int NV> using h1_free_t = h1_sb1_t_<NV>;
template <int NV>
using h1_branch_t = container::branch<parameter::empty, 
                                      wrap::fix<1, h1_harm_t<NV>>, 
                                      h1_chromatic_t<NV>, 
                                      h1_min_t<NV>, 
                                      h1_min1_t<NV>, 
                                      h1_Det1_t<NV>, 
                                      h1_5ths_t<NV>, 
                                      h1_free_t<NV>>;

template <int NV>
using minmax3_mod = parameter::chain<ranges::Identity, 
                                     parameter::plain<filters::allpass<NV>, 0>, 
                                     parameter::plain<project::res1<NV>, 5>, 
                                     parameter::plain<Filetrig1_t<NV>, 2>, 
                                     parameter::plain<Filetrig3_t<NV>, 2>, 
                                     parameter::plain<Filetrig4_t<NV>, 2>, 
                                     parameter::plain<Filetrig5_t<NV>, 2>>;

template <int NV>
using minmax3_t = control::minmax<NV, minmax3_mod<NV>>;
template <int NV>
using pma9_t = control::pma<NV, 
                            parameter::plain<minmax3_t<NV>, 0>>;
template <int NV>
using h1_peak3_t = wrap::mod<parameter::plain<pma9_t<NV>, 0>, 
                             wrap::no_data<core::peak>>;

template <int NV>
using converter1_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<project::res1<NV>, 1>, 
                                        parameter::plain<project::res1<NV>, 1>, 
                                        parameter::plain<project::res1<NV>, 1>, 
                                        parameter::plain<Filetrig1_t<NV>, 8>, 
                                        parameter::plain<Filetrig3_t<NV>, 8>, 
                                        parameter::plain<Filetrig4_t<NV>, 8>, 
                                        parameter::plain<Filetrig5_t<NV>, 8>>;

template <int NV>
using converter1_t = control::converter<converter1_mod<NV>, 
                                        conversion_logic::freq2ms>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, control::minmax<NV, parameter::empty>>, 
                                  h1_branch_t<NV>, 
                                  h1_peak3_t<NV>, 
                                  pma9_t<NV>, 
                                  minmax3_t<NV>, 
                                  converter1_t<NV>, 
                                  math::clear<NV>>;

template <int NV>
using Pitch_t = container::chain<parameter::empty, 
                                 wrap::fix<1, pma11_t<NV>>, 
                                 chain3_t<NV>>;

template <int NV> using ahdsr_c0_0 = xfader1_c0<NV>;

template <int NV>
using ahdsr_c0 = parameter::chain<ranges::Identity, 
                                  ahdsr_c0_0<NV>, 
                                  parameter::plain<Filetrig1_t<NV>, 0>, 
                                  parameter::plain<Filetrig3_t<NV>, 0>, 
                                  parameter::plain<Filetrig4_t<NV>, 0>, 
                                  parameter::plain<Filetrig5_t<NV>, 0>>;

template <int NV>
using ahdsr_multimod = parameter::list<ahdsr_c0<NV>, parameter::empty>;

template <int NV>
using ahdsr_t = wrap::no_data<envelope::ahdsr<NV, ahdsr_multimod<NV>>>;
template <int NV>
using peak3_t = wrap::mod<parameter::plain<ahdsr_t<NV>, 8>, 
                          wrap::data<core::peak, data::external::displaybuffer<0>>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, Pitch_t<NV>>, 
                                     math::clear<NV>, 
                                     math::add<NV>, 
                                     math::pi<NV>, 
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
using peak9_t = peak1_t;

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
		0.0617773f, 0.0390056f, 0.0162336f, 0.0170154f, 0.0736607f, 0.124522f,
		0.170701f, 0.213035f, 0.252175f, 0.288631f, 0.322811f, 0.354952f,
		0.384804f, 0.413196f, 0.440321f, 0.465947f, 0.490159f, 0.513543f,
		0.535704f, 0.556826f, 0.577414f, 0.596626f, 0.615423f, 0.633321f,
		0.650559f, 0.667233f, 0.683111f, 0.698645f, 0.713332f, 0.727799f,
		0.741442f, 0.754908f, 0.767633f, 0.780161f, 0.792077f, 0.803723f,
		0.814925f, 0.825738f, 0.836309f, 0.846337f, 0.856351f, 0.865636f,
		0.874921f, 0.883737f, 0.892319f, 0.900734f, 0.908649f, 0.916563f,
		0.923991f, 0.931271f, 0.938418f, 0.945096f, 0.951774f, 0.958101f,
		0.964205f, 0.970309f, 0.9759f, 0.981457f, 0.986909f, 0.991945f,
		0.996981f, 0.999852f, 0.999482f, 0.999112f, 0.998152f, 0.997006f,
		0.995692f, 0.993717f, 0.991742f, 0.98912f, 0.986258f, 0.983071f,
		0.979258f, 0.975408f, 0.970571f, 0.965735f, 0.959999f, 0.95406f,
		0.947311f, 0.940178f, 0.932236f, 0.923807f, 0.914456f, 0.904617f,
		0.893594f, 0.882214f, 0.869199f, 0.855664f, 0.840727f, 0.824522f,
		0.807372f, 0.788065f, 0.767218f, 0.744707f, 0.719902f, 0.692065f,
		0.661281f, 0.626844f, 0.587799f, 0.542831f, 0.490071f, 0.424817f,
		0.34047f, 0.204977f, 0.0082258f, 0.0252081f, 0.0421906f, 0.0591728f,
		0.0761551f, 0.0931373f, 0.11012f, 0.127102f, 0.144084f, 0.161067f,
		0.178049f, 0.195031f, 0.212014f, 0.228996f, 0.245978f, 0.262961f,
		0.279943f, 0.296925f, 0.313907f, 0.33089f, 0.347872f, 0.364855f,
		0.381837f, 0.398819f, 0.415801f, 0.432784f, 0.449766f, 0.466748f,
		0.483731f, 0.500713f, 0.517696f, 0.534678f, 0.55166f, 0.568642f,
		0.585625f, 0.602607f, 0.61959f, 0.636572f, 0.653554f, 0.670536f,
		0.687519f, 0.704501f, 0.721483f, 0.738465f, 0.755448f, 0.77243f,
		0.789413f, 0.806395f, 0.823377f, 0.840359f, 0.857342f, 0.874324f,
		0.891307f, 0.908289f, 0.925271f, 0.942253f, 0.959236f, 0.976218f,
		0.9932f, 1.f, 0.985045f, 0.960184f, 0.935324f, 0.910464f,
		0.885604f, 0.860972f, 0.836884f, 0.812795f, 0.788706f, 0.764617f,
		0.740529f, 0.717115f, 0.693773f, 0.670431f, 0.64709f, 0.623748f,
		0.60071f, 0.578092f, 0.555473f, 0.532854f, 0.510236f, 0.487617f,
		0.465595f, 0.443677f, 0.421758f, 0.39984f, 0.377922f, 0.356136f,
		0.334897f, 0.313658f, 0.292418f, 0.271179f, 0.24994f, 0.228995f,
		0.208414f, 0.187834f, 0.167253f, 0.146673f, 0.126092f, 0.105903f,
		0.0859603f, 0.0660185f, 0.0460766f, 0.0261348f, 0.00619292f, 0.0123357f,
		0.0302277f, 0.0481197f, 0.0660123f, 0.0839043f, 0.101796f, 0.119688f,
		0.13758f, 0.155472f, 0.173364f, 0.191256f, 0.209149f, 0.227041f,
		0.244933f, 0.262825f, 0.280717f, 0.298609f, 0.316501f, 0.334393f,
		0.352286f, 0.370178f, 0.38807f, 0.405962f, 0.423854f, 0.441746f,
		0.459638f, 0.47753f, 0.495422f, 0.513314f, 0.531206f, 0.549098f,
		0.56699f, 0.584882f, 0.602774f, 0.620666f, 0.638559f, 0.656451f,
		0.674343f, 0.692235f, 0.710127f, 0.728019f, 0.745911f, 0.763803f,
		0.781696f, 0.799588f, 0.81748f, 0.835372f, 0.853264f, 0.871156f,
		0.889048f, 0.90694f, 0.924832f, 0.942724f, 0.960617f, 0.978508f,
		0.996401f, 0.978368f, 0.951288f, 0.924208f, 0.897128f, 0.870048f,
		0.842968f, 0.815888f, 0.788808f, 0.761729f, 0.734649f, 0.707569f,
		0.680488f, 0.653409f, 0.626329f, 0.599249f, 0.572169f, 0.545089f,
		0.518009f, 0.49093f, 0.463849f, 0.436769f, 0.409689f, 0.38261f,
		0.35553f, 0.32845f, 0.30137f, 0.27429f, 0.24721f, 0.22013f,
		0.19305f, 0.16597f, 0.13889f, 0.111811f, 0.0847308f, 0.057651f,
		0.0305703f, 0.00349051f, 0.0132243f, 0.0284054f, 0.0435865f, 0.0587676f,
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

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, ahdsr_t<NV>>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<2, Filetrig1_t<NV>>, 
                                    Filetrig3_t<NV>, 
                                    Filetrig4_t<NV>, 
                                    Filetrig5_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, modchain1_t<NV>>, 
                                 branch2_t<NV>, 
                                 core::gain<NV>, 
                                 filters::one_pole<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain4_t<NV>>, 
                                   chain5_t<NV>, 
                                   chain8_t<NV>, 
                                   chain7_t<NV>, 
                                   chain_t<NV>>;

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

template <int NV>
using ResFreq = parameter::from0To1<ResStage_impl::pma11_t<NV>, 
                                    2, 
                                    ResStage_impl::peak_modRange>;

DECLARE_PARAMETER_RANGE_STEP(ResMode_InputRange, 
                             1., 
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
                               parameter::plain<project::res1<NV>, 3>>;

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

DECLARE_PARAMETER_RANGE_SKEW(Atk_InputRange, 
                             0., 
                             1000., 
                             0.30103);
DECLARE_PARAMETER_RANGE_SKEW(Atk_0Range, 
                             0., 
                             10000., 
                             0.197672);

template <int NV>
using Atk_0 = parameter::from0To1<ResStage_impl::ahdsr_t<NV>, 
                                  0, 
                                  Atk_0Range>;

template <int NV>
using Atk = parameter::chain<Atk_InputRange, Atk_0<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(Rel_InputRange, 
                             0., 
                             1000., 
                             0.30103);
template <int NV>
using Rel_0 = parameter::from0To1<ResStage_impl::ahdsr_t<NV>, 
                                  3, 
                                  Atk_0Range>;

template <int NV>
using Rel = parameter::chain<Rel_InputRange, Rel_0<NV>>;

template <int NV>
using SampleSync = parameter::chain<ranges::Identity, 
                                    parameter::plain<ResStage_impl::Filetrig1_t<NV>, 1>, 
                                    parameter::plain<ResStage_impl::Filetrig3_t<NV>, 1>, 
                                    parameter::plain<ResStage_impl::Filetrig4_t<NV>, 1>, 
                                    parameter::plain<ResStage_impl::Filetrig5_t<NV>, 1>>;

template <int NV>
using sampletempo = parameter::chain<ranges::Identity, 
                                     parameter::plain<ResStage_impl::Filetrig3_t<NV>, 4>, 
                                     parameter::plain<ResStage_impl::Filetrig4_t<NV>, 4>, 
                                     parameter::plain<ResStage_impl::Filetrig5_t<NV>, 4>, 
                                     parameter::plain<ResStage_impl::Filetrig1_t<NV>, 4>>;

DECLARE_PARAMETER_RANGE_STEP(samplediv_InputRange, 
                             1., 
                             32., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(samplediv_0Range, 
                             1., 
                             16., 
                             1.);

template <int NV>
using samplediv_0 = parameter::from0To1<ResStage_impl::Filetrig1_t<NV>, 
                                        5, 
                                        samplediv_0Range>;

template <int NV>
using samplediv_1 = parameter::from0To1<ResStage_impl::Filetrig3_t<NV>, 
                                        5, 
                                        samplediv_0Range>;

template <int NV>
using samplediv_2 = parameter::from0To1<ResStage_impl::Filetrig4_t<NV>, 
                                        5, 
                                        samplediv_0Range>;

template <int NV>
using samplediv_3 = parameter::from0To1<ResStage_impl::Filetrig5_t<NV>, 
                                        5, 
                                        samplediv_0Range>;

template <int NV>
using samplediv = parameter::chain<samplediv_InputRange, 
                                   samplediv_0<NV>, 
                                   samplediv_1<NV>, 
                                   samplediv_2<NV>, 
                                   samplediv_3<NV>>;

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
using SampleSigIn = parameter::chain<ranges::Identity, 
                                     parameter::plain<ResStage_impl::Filetrig1_t<NV>, 9>, 
                                     parameter::plain<ResStage_impl::Filetrig3_t<NV>, 9>, 
                                     parameter::plain<ResStage_impl::Filetrig4_t<NV>, 9>, 
                                     parameter::plain<ResStage_impl::Filetrig5_t<NV>, 9>>;

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

DECLARE_PARAMETER_RANGE(fineRange, 
                        -0.1, 
                        0.1);

template <int NV>
using fine = parameter::from0To1<ResStage_impl::pma9_t<NV>, 
                                 2, 
                                 fineRange>;

DECLARE_PARAMETER_RANGE_STEP(scale_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using scale_0 = parameter::from0To1<ResStage_impl::h1_branch_t<NV>, 
                                    0, 
                                    ModifierMode_0Range>;

template <int NV>
using scale = parameter::chain<scale_InputRange, scale_0<NV>>;

template <int NV>
using SampRel = parameter::from0To1<ResStage_impl::ahdsr_t<NV>, 
                                    5, 
                                    Atk_0Range>;

template <int NV>
using SampleShape = parameter::chain<ranges::Identity, 
                                     parameter::plain<ResStage_impl::Filetrig1_t<NV>, 6>, 
                                     parameter::plain<ResStage_impl::Filetrig3_t<NV>, 6>, 
                                     parameter::plain<ResStage_impl::Filetrig4_t<NV>, 6>, 
                                     parameter::plain<ResStage_impl::Filetrig5_t<NV>, 6>>;

template <int NV>
using SampleLoop = parameter::chain<ranges::Identity, 
                                    parameter::plain<ResStage_impl::Filetrig5_t<NV>, 7>, 
                                    parameter::plain<ResStage_impl::Filetrig4_t<NV>, 7>, 
                                    parameter::plain<ResStage_impl::Filetrig3_t<NV>, 7>, 
                                    parameter::plain<ResStage_impl::Filetrig1_t<NV>, 7>>;

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
using ResMin = parameter::empty;
using ResMax = ResMin;
using ResStep = ResMin;
template <int NV>
using PostCut = parameter::plain<project::FilterForRes<NV>, 
                                 0>;
template <int NV> using PostRes = qA<NV>;
using Fb = parameter::plain<routing::receive<stereo_cable>, 
                            0>;
template <int NV> using Phase = CutOffC<NV>;
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
using SlotSel1 = parameter::plain<ResStage_impl::branch2_t<NV>, 
                                  0>;
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
                                         ResMin, 
                                         ResMax, 
                                         ResStep, 
                                         ResMode<NV>, 
                                         ResLP<NV>, 
                                         ResFeed<NV>, 
                                         PostCut<NV>, 
                                         PostRes<NV>, 
                                         PostMode<NV>, 
                                         Fmode1<NV>, 
                                         FilterModShape<NV>, 
                                         Fb, 
                                         Atk<NV>, 
                                         Rel<NV>, 
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
                                         RateDivMode<NV>, 
                                         fine<NV>, 
                                         scale<NV>, 
                                         SampRel<NV>, 
                                         SampleShape<NV>, 
                                         SampleLoop<NV>, 
                                         SlotSel1<NV>>;
}

template <int NV>
using ResStage_t_ = container::chain<ResStage_t_parameters::ResStage_t_plist<NV>, 
                                     wrap::fix<2, chain431_t<NV>>, 
                                     xfader_t<NV>, 
                                     split5_t<NV>, 
                                     tempo_sync1_t<NV>, 
                                     chain6_t<NV>, 
                                     peak9_t, 
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
		static const int NumAudioFiles = 4;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 1;
		
		SNEX_METADATA_ID(ResStage);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(996)
		{
			0x005B, 0x0000, 0x4D00, 0x646F, 0x6669, 0x6569, 0x4D72, 0x646F, 
            0x0065, 0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x015B, 0x0000, 0x4300, 0x7475, 0x664F, 
            0x4166, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0xB53F, 
            0x74D7, 0x003E, 0x0000, 0x5B00, 0x0002, 0x0000, 0x7543, 0x4F74, 
            0x6666, 0x0042, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0xD7B5, 0x3E74, 0x0000, 0x0000, 0x035B, 0x0000, 0x7100, 0x0041, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x045B, 0x0000, 0x4300, 0x7475, 0x664F, 0x4366, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0005, 0x0000, 0x6F43, 0x706D, 0x6854, 
            0x6572, 0x6873, 0x0000, 0xC800, 0x00C2, 0x0000, 0xCC00, 0xE0CC, 
            0x3EC1, 0xAD83, 0xCD40, 0xCCCC, 0x5B3D, 0x0006, 0x0000, 0x6F43, 
            0x706D, 0x7441, 0x006B, 0x0000, 0x0000, 0x0000, 0x437A, 0x0000, 
            0x0000, 0x81A3, 0x3EDC, 0xCCCD, 0x3DCC, 0x075B, 0x0000, 0x4300, 
            0x6D6F, 0x5270, 0x6C65, 0x0000, 0x0000, 0x0000, 0x7A00, 0x0043, 
            0x4400, 0xA343, 0xDC81, 0xCD3E, 0xCCCC, 0x5B3D, 0x0008, 0x0000, 
            0x6F43, 0x706D, 0x6152, 0x6974, 0x006F, 0x0000, 0x3F80, 0x0000, 
            0x4200, 0x3333, 0x4013, 0xF69D, 0x3E97, 0xCCCD, 0x3DCC, 0x095B, 
            0x0000, 0x4900, 0x706E, 0x7475, 0x7254, 0x6769, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x000A, 0x0000, 0x6E49, 0x7570, 0x4874, 0x0050, 0x0000, 
            0x41A0, 0x4000, 0x469C, 0xE3C8, 0x41E3, 0x6C1A, 0x3E6B, 0x0000, 
            0x0000, 0x0B5B, 0x0000, 0x5200, 0x7461, 0x0065, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x6783, 0x3F2B, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0C5B, 0x0000, 0x5200, 0x7461, 0x5765, 0x6E69, 0x0000, 0x0000, 
            0x0000, 0x9000, 0x0041, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x000D, 0x0000, 0x6152, 0x6574, 0x6957, 0x446E, 0x7669, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 0xF800, 0x0041, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x000E, 0x0000, 0x6552, 0x4673, 0x6572, 
            0x0071, 0x0000, 0x0000, 0x0000, 0x3F80, 0xB216, 0x3EC9, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0F5B, 0x0000, 0x5200, 0x7365, 0x694D, 
            0x006E, 0x0000, 0x2640, 0x0000, 0x3F80, 0x0B21, 0x3D19, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x105B, 0x0000, 0x5200, 0x7365, 0x614D, 
            0x0078, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x115B, 0x0000, 0x5200, 0x7365, 0x7453, 
            0x7065, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0xA000, 
            0x01DC, 0x003F, 0x0000, 0x5B00, 0x0012, 0x0000, 0x6552, 0x4D73, 
            0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 0x40A0, 0x0000, 0x40A0, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x135B, 0x0000, 0x5200, 0x7365, 
            0x504C, 0x0000, 0xA000, 0x0041, 0x9C40, 0x0046, 0x9C40, 0x1A46, 
            0x6B6C, 0x003E, 0x0000, 0x5B00, 0x0014, 0x0000, 0x6552, 0x4673, 
            0x6565, 0x0064, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x155B, 0x0000, 0x5000, 0x736F, 
            0x4374, 0x7475, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0xB53F, 0x74D7, 0x003E, 0x0000, 0x5B00, 0x0016, 0x0000, 0x6F50, 
            0x7473, 0x6552, 0x0073, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x175B, 0x0000, 0x5000, 
            0x736F, 0x4D74, 0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 0x4150, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x185B, 0x0000, 
            0x4600, 0x6F6D, 0x6564, 0x0031, 0x0000, 0x3F80, 0x0000, 0x4130, 
            0x0000, 0x4130, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x195B, 0x0000, 
            0x4600, 0x6C69, 0x6574, 0x4D72, 0x646F, 0x6853, 0x7061, 0x0065, 
            0x0000, 0x3F80, 0x0000, 0x4040, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x1A5B, 0x0000, 0x4600, 0x0062, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x1B5B, 0x0000, 0x4100, 0x6B74, 0x0000, 0x0000, 0x0000, 0x7A00, 
            0x0044, 0x0000, 0x9B00, 0x9A20, 0xCD3E, 0xCCCC, 0x5B3D, 0x001C, 
            0x0000, 0x6552, 0x006C, 0x0000, 0x0000, 0x0000, 0x447A, 0x0000, 
            0x447A, 0x209B, 0x3E9A, 0xCCCD, 0x3DCC, 0x1D5B, 0x0000, 0x5300, 
            0x6D61, 0x6C70, 0x5365, 0x6E79, 0x0063, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x1E5B, 
            0x0000, 0x5000, 0x6168, 0x6573, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x001F, 
            0x0000, 0x6173, 0x706D, 0x656C, 0x6574, 0x706D, 0x006F, 0x0000, 
            0x0000, 0x0000, 0x4190, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x205B, 0x0000, 0x7300, 0x6D61, 0x6C70, 0x6465, 0x7669, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 0x2000, 0x0041, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0021, 0x0000, 0x6850, 0x7361, 0x3165, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0022, 0x0000, 0x6850, 0x7361, 0x3265, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x9A3F, 0x6A99, 0x003E, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0023, 0x0000, 0x6F4D, 0x3164, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0024, 0x0000, 0x6F4D, 0x3264, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x3B3F, 0x41DF, 0x003D, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0025, 0x0000, 0x6F4D, 0x3364, 0x0000, 0x0000, 0x0000, 
            0x8000, 0xAE3F, 0x9147, 0x003C, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0026, 0x0000, 0x6850, 0x7361, 0x4D65, 0x646F, 0x0065, 0x0000, 
            0x3F80, 0x0000, 0x4040, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x275B, 0x0000, 0x4D00, 0x646F, 0x6F4D, 0x6564, 0x0000, 
            0x8000, 0x003F, 0x4000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x0028, 0x0000, 0x7350, 0x7453, 0x7065, 0x0000, 
            0x0000, 0x0000, 0xC000, 0x0041, 0x8000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x0029, 0x0000, 0x6172, 0x6574, 0x0032, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0xADA3, 0x3EAD, 0x0000, 0x3F80, 0x0000, 
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
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x365B, 0x0000, 
            0x6600, 0x6E69, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x149D, 
            0x3F05, 0x0000, 0x3F80, 0x0000, 0x0000, 0x375B, 0x0000, 0x7300, 
            0x6163, 0x656C, 0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0038, 0x0000, 0x6153, 
            0x706D, 0x6552, 0x006C, 0x0000, 0x0000, 0x0000, 0x3F80, 0xBE9C, 
            0x3F45, 0x0000, 0x3F80, 0x0000, 0x0000, 0x395B, 0x0000, 0x5300, 
            0x6D61, 0x6C70, 0x5365, 0x6168, 0x6570, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x003A, 0x0000, 0x6153, 0x706D, 0x656C, 0x6F4C, 0x706F, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x913F, 0xBC85, 0x003D, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x003B, 0x0000, 0x6C53, 0x746F, 0x6553, 0x316C, 
            0x0000, 0x0000, 0x0000, 0x4000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain431 = this->getT(0);                                                               // ResStage_impl::chain431_t<NV>
		auto& modchain2 = this->getT(0).getT(0);                                                      // ResStage_impl::modchain2_t<NV>
		auto& split16 = this->getT(0).getT(0).getT(0);                                                // ResStage_impl::split16_t<NV>
		auto& chain29 = this->getT(0).getT(0).getT(0).getT(0);                                        // ResStage_impl::chain29_t<NV>
		auto& branch3 = this->getT(0).getT(0).getT(0).getT(0).getT(0);                                // ResStage_impl::branch3_t<NV>
		auto& add20 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);                          // math::add<NV>
		auto& add21 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1);                          // math::add<NV>
		auto& add42 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2);                          // math::add<NV>
		auto& peak = this->getT(0).getT(0).getT(0).getT(0).getT(1);                                   // ResStage_impl::peak_t<NV>
		auto& pma1 = this->getT(0).getT(0).getT(0).getT(0).getT(2);                                   // ResStage_impl::pma1_t<NV>
		auto& chain30 = this->getT(0).getT(0).getT(0).getT(1);                                        // ResStage_impl::chain30_t<NV>
		auto& branch5 = this->getT(0).getT(0).getT(0).getT(1).getT(0);                                // ResStage_impl::branch5_t<NV>
		auto& add40 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0);                          // math::add<NV>
		auto& add41 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1);                          // math::add<NV>
		auto& add43 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(2);                          // math::add<NV>
		auto& peak2 = this->getT(0).getT(0).getT(0).getT(1).getT(1);                                  // ResStage_impl::peak2_t<NV>
		auto& pma3 = this->getT(0).getT(0).getT(0).getT(1).getT(2);                                   // ResStage_impl::pma3_t<NV>
		auto& smoothed_parameter = this->getT(0).getT(0).getT(0).getT(1).getT(3);                     // ResStage_impl::smoothed_parameter_t<NV>
		auto& chain31 = this->getT(0).getT(0).getT(0).getT(2);                                        // ResStage_impl::chain31_t<NV>
		auto& branch6 = this->getT(0).getT(0).getT(0).getT(2).getT(0);                                // ResStage_impl::branch6_t<NV>
		auto& add44 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(0);                          // math::add<NV>
		auto& add45 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(1);                          // math::add<NV>
		auto& add46 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(2);                          // math::add<NV>
		auto& peak4 = this->getT(0).getT(0).getT(0).getT(2).getT(1);                                  // ResStage_impl::peak4_t<NV>
		auto& pma4 = this->getT(0).getT(0).getT(0).getT(2).getT(2);                                   // ResStage_impl::pma4_t<NV>
		auto& chain32 = this->getT(0).getT(0).getT(0).getT(3);                                        // ResStage_impl::chain32_t<NV>
		auto& branch7 = this->getT(0).getT(0).getT(0).getT(3).getT(0);                                // ResStage_impl::branch7_t<NV>
		auto& add47 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(0);                          // math::add<NV>
		auto& add48 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(1);                          // math::add<NV>
		auto& add49 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(2);                          // math::add<NV>
		auto& peak5 = this->getT(0).getT(0).getT(0).getT(3).getT(1);                                  // ResStage_impl::peak5_t<NV>
		auto& pma5 = this->getT(0).getT(0).getT(0).getT(3).getT(2);                                   // ResStage_impl::pma5_t<NV>
		auto& chain33 = this->getT(0).getT(0).getT(0).getT(4);                                        // ResStage_impl::chain33_t<NV>
		auto& branch8 = this->getT(0).getT(0).getT(0).getT(4).getT(0);                                // ResStage_impl::branch8_t<NV>
		auto& add50 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(0);                          // math::add<NV>
		auto& add51 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(1);                          // math::add<NV>
		auto& add52 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(2);                          // math::add<NV>
		auto& peak6 = this->getT(0).getT(0).getT(0).getT(4).getT(1);                                  // ResStage_impl::peak6_t<NV>
		auto& pma6 = this->getT(0).getT(0).getT(0).getT(4).getT(2);                                   // ResStage_impl::pma6_t<NV>
		auto& chain34 = this->getT(0).getT(0).getT(0).getT(5);                                        // ResStage_impl::chain34_t<NV>
		auto& branch9 = this->getT(0).getT(0).getT(0).getT(5).getT(0);                                // ResStage_impl::branch9_t<NV>
		auto& add53 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(0);                          // math::add<NV>
		auto& add54 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(1);                          // math::add<NV>
		auto& add55 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(2);                          // math::add<NV>
		auto& peak7 = this->getT(0).getT(0).getT(0).getT(5).getT(1);                                  // ResStage_impl::peak7_t<NV>
		auto& pma7 = this->getT(0).getT(0).getT(0).getT(5).getT(2);                                   // ResStage_impl::pma7_t<NV>
		auto& chain35 = this->getT(0).getT(0).getT(0).getT(6);                                        // ResStage_impl::chain35_t<NV>
		auto& branch10 = this->getT(0).getT(0).getT(0).getT(6).getT(0);                               // ResStage_impl::branch10_t<NV>
		auto& add56 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(0);                          // math::add<NV>
		auto& add57 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(1);                          // math::add<NV>
		auto& add58 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(2);                          // math::add<NV>
		auto& peak8 = this->getT(0).getT(0).getT(0).getT(6).getT(1);                                  // ResStage_impl::peak8_t<NV>
		auto& pma8 = this->getT(0).getT(0).getT(0).getT(6).getT(2);                                   // ResStage_impl::pma8_t<NV>
		auto& branch1 = this->getT(0).getT(1);                                                        // ResStage_impl::branch1_t<NV>
		auto& chain18 = this->getT(0).getT(1).getT(0);                                                // ResStage_impl::chain18_t
		auto& sampleandhold = this->getT(0).getT(1).getT(1);                                          // fx::sampleandhold<NV>
		auto& chain10 = this->getT(0).getT(1).getT(2);                                                // ResStage_impl::chain10_t<NV>
		auto& tempo_sync2 = this->getT(0).getT(1).getT(2).getT(0);                                    // ResStage_impl::tempo_sync2_t<NV>
		auto& receive1 = this->getT(0).getT(1).getT(2).getT(1);                                       // routing::receive<stereo_cable>
		auto& fix_delay1 = this->getT(0).getT(1).getT(2).getT(2);                                     // core::fix_delay
		auto& send3 = this->getT(0).getT(1).getT(2).getT(3);                                          // routing::send<stereo_cable>
		auto& tanh = this->getT(0).getT(1).getT(3);                                                   // math::tanh<NV>
		auto& bitcrush = this->getT(0).getT(1).getT(4);                                               // fx::bitcrush<NV>
		auto& chain17 = this->getT(0).getT(1).getT(5);                                                // ResStage_impl::chain17_t<NV>
		auto& xfader1 = this->getT(0).getT(1).getT(5).getT(0);                                        // ResStage_impl::xfader1_t<NV>
		auto& split8 = this->getT(0).getT(1).getT(5).getT(1);                                         // ResStage_impl::split8_t<NV>
		auto& chain15 = this->getT(0).getT(1).getT(5).getT(1).getT(0);                                // ResStage_impl::chain15_t<NV>
		auto& gain4 = this->getT(0).getT(1).getT(5).getT(1).getT(0).getT(0);                          // core::gain<NV>
		auto& chain16 = this->getT(0).getT(1).getT(5).getT(1).getT(1);                                // ResStage_impl::chain16_t<NV>
		auto& abs1 = this->getT(0).getT(1).getT(5).getT(1).getT(1).getT(0);                           // math::abs<NV>
		auto& gain8 = this->getT(0).getT(1).getT(5).getT(1).getT(1).getT(1);                          // core::gain<NV>
		auto& chain1 = this->getT(0).getT(1).getT(6);                                                 // ResStage_impl::chain1_t<NV>
		auto& cable_table2 = this->getT(0).getT(1).getT(6).getT(0);                                   // ResStage_impl::cable_table2_t<NV>
		auto& cable_table3 = this->getT(0).getT(1).getT(6).getT(1);                                   // ResStage_impl::cable_table3_t<NV>
		auto& faust1 = this->getT(0).getT(1).getT(6).getT(2);                                         // project::granul<NV>
		auto& xfader = this->getT(1);                                                                 // ResStage_impl::xfader_t<NV>
		auto& split5 = this->getT(2);                                                                 // ResStage_impl::split5_t<NV>
		auto& chain11 = this->getT(2).getT(0);                                                        // ResStage_impl::chain11_t<NV>
		auto& gain = this->getT(2).getT(0).getT(0);                                                   // core::gain<NV>
		auto& chain12 = this->getT(2).getT(1);                                                        // ResStage_impl::chain12_t<NV>
		auto& comp = this->getT(2).getT(1).getT(0);                                                   // ResStage_impl::comp_t<NV>
		auto& chain21 = this->getT(2).getT(1).getT(1);                                                // ResStage_impl::chain21_t<NV>
		auto& chain13 = this->getT(2).getT(1).getT(1).getT(0);                                        // ResStage_impl::chain13_t<NV>
		auto& clear4 = this->getT(2).getT(1).getT(1).getT(0).getT(0);                                 // math::clear<NV>
		auto& add3 = this->getT(2).getT(1).getT(1).getT(0).getT(1);                                   // math::add<NV>
		auto& pma2 = this->getT(2).getT(1).getT(1).getT(0).getT(2);                                   // ResStage_impl::pma2_t<NV>
		auto& gain6 = this->getT(2).getT(1).getT(1).getT(0).getT(3);                                  // core::gain<NV>
		auto& gain76 = this->getT(2).getT(1).getT(1).getT(0).getT(4);                                 // core::gain<NV>
		auto& peak1 = this->getT(2).getT(1).getT(1).getT(1);                                          // ResStage_impl::peak1_t
		auto& clear2 = this->getT(2).getT(1).getT(2);                                                 // wrap::no_process<math::clear<NV>>
		auto& tempo_sync1 = this->getT(3);                                                            // ResStage_impl::tempo_sync1_t<NV>
		auto& chain6 = this->getT(4);                                                                 // ResStage_impl::chain6_t<NV>
		auto& gain5 = this->getT(4).getT(0);                                                          // core::gain<NV>
		auto& one_pole30 = this->getT(4).getT(1);                                                     // filters::one_pole<NV>
		auto& minmax = this->getT(4).getT(2);                                                         // ResStage_impl::minmax_t<NV>
		auto& receive58 = this->getT(4).getT(3);                                                      // routing::receive<stereo_cable>
		auto& faust = this->getT(4).getT(4);                                                          // project::PitchShifter<NV>
		auto& send = this->getT(4).getT(5);                                                           // routing::send<stereo_cable>
		auto& modchain = this->getT(4).getT(6);                                                       // ResStage_impl::modchain_t<NV>
		auto& Pitch = this->getT(4).getT(6).getT(0);                                                  // ResStage_impl::Pitch_t<NV>
		auto& pma11 = this->getT(4).getT(6).getT(0).getT(0);                                          // ResStage_impl::pma11_t<NV>
		auto& chain3 = this->getT(4).getT(6).getT(0).getT(1);                                         // ResStage_impl::chain3_t<NV>
		auto& minmax2 = this->getT(4).getT(6).getT(0).getT(1).getT(0);                                // control::minmax<NV, parameter::empty>
		auto& h1_branch = this->getT(4).getT(6).getT(0).getT(1).getT(1);                              // ResStage_impl::h1_branch_t<NV>
		auto& h1_harm = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0);                        // ResStage_impl::h1_harm_t<NV>
		auto& h1_softbypass_switch3 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).getT(0);  // ResStage_impl::h1_softbypass_switch3_t<NV>
		auto& h1_switcher2 = this->getT(4).getT(6).getT(0).getT(1).                                   // ResStage_impl::h1_switcher2_t<NV>
                             getT(1).getT(0).getT(0).getT(0);
		auto& h1_sb_container2 = this->getT(4).getT(6).getT(0).getT(1).                               // ResStage_impl::h1_sb_container2_t<NV>
                                 getT(1).getT(0).getT(0).getT(1);
		auto& h1_sb17 = this->getT(4).getT(6).getT(0).getT(1).                                        // ResStage_impl::h1_sb17_t<NV>
                        getT(1).getT(0).getT(0).getT(1).
                        getT(0);
		auto& h1_softbypass_switch9 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                  // ResStage_impl::h1_softbypass_switch9_t<NV>
                                      getT(0).getT(0).getT(1).getT(0).getT(0);
		auto& h1_cable_table1 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                        // ResStage_impl::h1_cable_table1_t<NV>
                                getT(0).getT(0).getT(1).getT(0).getT(0).
                                getT(0);
		auto& h1_switcher = this->getT(4).getT(6).getT(0).getT(1).getT(1).                            // ResStage_impl::h1_switcher_t<NV>
                            getT(0).getT(0).getT(1).getT(0).getT(0).
                            getT(1);
		auto& h1_sb_container = this->getT(4).getT(6).getT(0).getT(1).getT(1).                        // ResStage_impl::h1_sb_container_t<NV>
                                getT(0).getT(0).getT(1).getT(0).getT(0).
                                getT(2);
		auto& h1_sb1 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                         // ResStage_impl::h1_sb1_t<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& h1_add2 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                        // math::add<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
                        getT(0);
		auto& h1_sb2 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                         // ResStage_impl::h1_sb2_t<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& h1_add4 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                        // math::add<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
                        getT(0);
		auto& h1_sb3 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                         // ResStage_impl::h1_sb3_t<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2).getT(2);
		auto& h1_add3 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                        // math::add<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(2).
                        getT(0);
		auto& h1_sb4 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                         // ResStage_impl::h1_sb4_t<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2).getT(3);
		auto& h1_add6 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                        // math::add<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(3).
                        getT(0);
		auto& h1_sb5 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                         // ResStage_impl::h1_sb5_t<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2).getT(4);
		auto& h1_add5 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                        // math::add<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(4).
                        getT(0);
		auto& h1_sb6 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                         // ResStage_impl::h1_sb6_t<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2).getT(5);
		auto& h1_add8 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                        // math::add<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(5).
                        getT(0);
		auto& h1_sb7 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                         // ResStage_impl::h1_sb7_t<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2).getT(6);
		auto& h1_add7 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                        // math::add<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(6).
                        getT(0);
		auto& h1_sb8 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                         // ResStage_impl::h1_sb8_t<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2).getT(7);
		auto& h1_add9 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                        // math::add<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(7).
                        getT(0);
		auto& h1_sb18 = this->getT(4).getT(6).getT(0).getT(1).                                        // ResStage_impl::h1_sb18_t<NV>
                        getT(1).getT(0).getT(0).getT(1).
                        getT(1);
		auto& h1_softbypass_switch10 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                 // ResStage_impl::h1_softbypass_switch10_t<NV>
                                       getT(0).getT(0).getT(1).getT(1).getT(0);
		auto& h1_cable_table2 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                        // ResStage_impl::h1_cable_table2_t<NV>
                                getT(0).getT(0).getT(1).getT(1).getT(0).
                                getT(0);
		auto& h1_switcher1 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                           // ResStage_impl::h1_switcher1_t<NV>
                             getT(0).getT(0).getT(1).getT(1).getT(0).
                             getT(1);
		auto& h1_sb_container1 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                       // ResStage_impl::h1_sb_container1_t<NV>
                                 getT(0).getT(0).getT(1).getT(1).getT(0).
                                 getT(2);
		auto& h1_sb9 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                         // ResStage_impl::h1_sb9_t<NV>
                       getT(0).getT(1).getT(1).getT(0).getT(2).getT(0);
		auto& h1_add10 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(0).
                         getT(0);
		auto& h1_sb10 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                        // ResStage_impl::h1_sb10_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2).getT(1);
		auto& h1_add11 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(1).
                         getT(0);
		auto& h1_sb11 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                        // ResStage_impl::h1_sb11_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2).getT(2);
		auto& h1_add12 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(2).
                         getT(0);
		auto& h1_sb12 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                        // ResStage_impl::h1_sb12_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2).getT(3);
		auto& h1_add13 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(3).
                         getT(0);
		auto& h1_sb13 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                        // ResStage_impl::h1_sb13_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2).getT(4);
		auto& h1_add14 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(4).
                         getT(0);
		auto& h1_sb14 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                        // ResStage_impl::h1_sb14_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2).getT(5);
		auto& h1_add15 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(5).
                         getT(0);
		auto& h1_sb15 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                        // ResStage_impl::h1_sb15_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2).getT(6);
		auto& h1_add16 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(6).
                         getT(0);
		auto& h1_sb16 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                        // ResStage_impl::h1_sb16_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2).getT(7);
		auto& h1_add17 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(0).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(7).
                         getT(0);
		auto& h1_chromatic = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1);                   // ResStage_impl::h1_chromatic_t<NV>
		auto& h1_softbypass_switch5 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).getT(0);  // ResStage_impl::h1_softbypass_switch5_t<NV>
		auto& h1_switcher6 = this->getT(4).getT(6).getT(0).getT(1).                                   // ResStage_impl::h1_switcher6_t
                             getT(1).getT(1).getT(0).getT(0);
		auto& h1_sb_container15 = this->getT(4).getT(6).getT(0).getT(1).                              // ResStage_impl::h1_sb_container15_t<NV>
                                  getT(1).getT(1).getT(0).getT(1);
		auto& h1_sb91 = this->getT(4).getT(6).getT(0).getT(1).                                        // ResStage_impl::h1_sb91_t<NV>
                        getT(1).getT(1).getT(0).getT(1).
                        getT(0);
		auto& h1_softbypass_switch19 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                 // ResStage_impl::h1_softbypass_switch19_t<NV>
                                       getT(1).getT(0).getT(1).getT(0).getT(0);
		auto& h1_cable_table11 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                       // ResStage_impl::h1_cable_table11_t<NV>
                                 getT(1).getT(0).getT(1).getT(0).getT(0).
                                 getT(0);
		auto& h1_switcher15 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                          // ResStage_impl::h1_switcher15_t<NV>
                              getT(1).getT(0).getT(1).getT(0).getT(0).
                              getT(1);
		auto& h1_sb_container16 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                      // ResStage_impl::h1_sb_container16_t<NV>
                                  getT(1).getT(0).getT(1).getT(0).getT(0).
                                  getT(2);
		auto& h1_sb92 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                        // ResStage_impl::h1_sb92_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& h1_add83 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // math::add<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
                         getT(0);
		auto& h1_sb93 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                        // ResStage_impl::h1_sb93_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& h1_add84 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // math::add<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
                         getT(0);
		auto& h1_sb94 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                        // ResStage_impl::h1_sb94_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(2);
		auto& h1_add85 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // math::add<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(2).
                         getT(0);
		auto& h1_sb95 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                        // ResStage_impl::h1_sb95_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(3);
		auto& h1_add86 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // math::add<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(3).
                         getT(0);
		auto& h1_sb96 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                        // ResStage_impl::h1_sb96_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(4);
		auto& h1_add87 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // math::add<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(4).
                         getT(0);
		auto& h1_sb97 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                        // ResStage_impl::h1_sb97_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(5);
		auto& h1_add88 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // math::add<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(5).
                         getT(0);
		auto& h1_sb98 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                        // ResStage_impl::h1_sb98_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(6);
		auto& h1_add89 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // math::add<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(6).
                         getT(0);
		auto& h1_sb99 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                        // ResStage_impl::h1_sb99_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(7);
		auto& h1_add90 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // math::add<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(7).
                         getT(0);
		auto& h1_sb100 = this->getT(4).getT(6).getT(0).getT(1).                                       // ResStage_impl::h1_sb100_t<NV>
                         getT(1).getT(1).getT(0).getT(1).
                         getT(1);
		auto& h1_softbypass_switch20 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                 // ResStage_impl::h1_softbypass_switch20_t<NV>
                                       getT(1).getT(0).getT(1).getT(1).getT(0);
		auto& h1_cable_table12 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                       // ResStage_impl::h1_cable_table12_t<NV>
                                 getT(1).getT(0).getT(1).getT(1).getT(0).
                                 getT(0);
		auto& h1_switcher16 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                          // ResStage_impl::h1_switcher16_t<NV>
                              getT(1).getT(0).getT(1).getT(1).getT(0).
                              getT(1);
		auto& h1_sb_container17 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                      // ResStage_impl::h1_sb_container17_t<NV>
                                  getT(1).getT(0).getT(1).getT(1).getT(0).
                                  getT(2);
		auto& h1_sb101 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // ResStage_impl::h1_sb101_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(0);
		auto& h1_add91 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(0).
                         getT(0);
		auto& h1_sb102 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // ResStage_impl::h1_sb102_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(1);
		auto& h1_add92 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(1).
                         getT(0);
		auto& h1_sb103 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // ResStage_impl::h1_sb103_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(2);
		auto& h1_add93 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(2).
                         getT(0);
		auto& h1_sb104 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // ResStage_impl::h1_sb104_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(3);
		auto& h1_add94 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(3).
                         getT(0);
		auto& h1_sb105 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // ResStage_impl::h1_sb105_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(4);
		auto& h1_add95 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(4).
                         getT(0);
		auto& h1_sb106 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // ResStage_impl::h1_sb106_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(5);
		auto& h1_add96 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(5).
                         getT(0);
		auto& h1_sb107 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // ResStage_impl::h1_sb107_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(6);
		auto& h1_add97 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(6).
                         getT(0);
		auto& h1_sb108 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // ResStage_impl::h1_sb108_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(7);
		auto& h1_add98 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(1).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(7).
                         getT(0);
		auto& h1_min = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2);                         // ResStage_impl::h1_min_t<NV>
		auto& h1_softbypass_switch6 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).getT(0);  // ResStage_impl::h1_softbypass_switch6_t<NV>
		auto& h1_switcher9 = this->getT(4).getT(6).getT(0).getT(1).                                   // ResStage_impl::h1_switcher9_t
                             getT(1).getT(2).getT(0).getT(0);
		auto& h1_sb_container9 = this->getT(4).getT(6).getT(0).getT(1).                               // ResStage_impl::h1_sb_container9_t<NV>
                                 getT(1).getT(2).getT(0).getT(1);
		auto& h1_sb55 = this->getT(4).getT(6).getT(0).getT(1).                                        // ResStage_impl::h1_sb55_t<NV>
                        getT(1).getT(2).getT(0).getT(1).
                        getT(0);
		auto& h1_softbypass_switch15 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                 // ResStage_impl::h1_softbypass_switch15_t<NV>
                                       getT(2).getT(0).getT(1).getT(0).getT(0);
		auto& h1_cable_table7 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                        // ResStage_impl::h1_cable_table7_t<NV>
                                getT(2).getT(0).getT(1).getT(0).getT(0).
                                getT(0);
		auto& h1_switcher10 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                          // ResStage_impl::h1_switcher10_t<NV>
                              getT(2).getT(0).getT(1).getT(0).getT(0).
                              getT(1);
		auto& h1_sb_container10 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                      // ResStage_impl::h1_sb_container10_t<NV>
                                  getT(2).getT(0).getT(1).getT(0).getT(0).
                                  getT(2);
		auto& h1_sb56 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                        // ResStage_impl::h1_sb56_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& h1_add50 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                       // math::add<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
                         getT(0);
		auto& h1_sb57 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                        // ResStage_impl::h1_sb57_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& h1_add51 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                       // math::add<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
                         getT(0);
		auto& h1_sb58 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                        // ResStage_impl::h1_sb58_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(2);
		auto& h1_add52 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                       // math::add<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(2).
                         getT(0);
		auto& h1_sb59 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                        // ResStage_impl::h1_sb59_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(3);
		auto& h1_add53 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                       // math::add<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(3).
                         getT(0);
		auto& h1_sb60 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                        // ResStage_impl::h1_sb60_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(4);
		auto& h1_add54 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                       // math::add<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(4).
                         getT(0);
		auto& h1_sb61 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                        // ResStage_impl::h1_sb61_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(5);
		auto& h1_add55 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                       // math::add<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(5).
                         getT(0);
		auto& h1_sb62 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                        // ResStage_impl::h1_sb62_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(6);
		auto& h1_add56 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                       // math::add<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(6).
                         getT(0);
		auto& h1_sb63 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                        // ResStage_impl::h1_sb63_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(7);
		auto& h1_add57 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                       // math::add<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(7).
                         getT(0);
		auto& h1_sb64 = this->getT(4).getT(6).getT(0).getT(1).                                        // ResStage_impl::h1_sb64_t<NV>
                        getT(1).getT(2).getT(0).getT(1).
                        getT(1);
		auto& h1_softbypass_switch16 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                 // ResStage_impl::h1_softbypass_switch16_t<NV>
                                       getT(2).getT(0).getT(1).getT(1).getT(0);
		auto& h1_cable_table8 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                        // ResStage_impl::h1_cable_table8_t<NV>
                                getT(2).getT(0).getT(1).getT(1).getT(0).
                                getT(0);
		auto& h1_switcher11 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                          // ResStage_impl::h1_switcher11_t<NV>
                              getT(2).getT(0).getT(1).getT(1).getT(0).
                              getT(1);
		auto& h1_sb_container11 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                      // ResStage_impl::h1_sb_container11_t<NV>
                                  getT(2).getT(0).getT(1).getT(1).getT(0).
                                  getT(2);
		auto& h1_sb65 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                        // ResStage_impl::h1_sb65_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2).getT(0);
		auto& h1_add58 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(0).
                         getT(0);
		auto& h1_sb66 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                        // ResStage_impl::h1_sb66_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2).getT(1);
		auto& h1_add59 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(1).
                         getT(0);
		auto& h1_sb67 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                        // ResStage_impl::h1_sb67_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2).getT(2);
		auto& h1_add60 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(2).
                         getT(0);
		auto& h1_sb68 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                        // ResStage_impl::h1_sb68_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2).getT(3);
		auto& h1_add61 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(3).
                         getT(0);
		auto& h1_sb69 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                        // ResStage_impl::h1_sb69_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2).getT(4);
		auto& h1_add62 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(4).
                         getT(0);
		auto& h1_sb70 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                        // ResStage_impl::h1_sb70_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2).getT(5);
		auto& h1_add63 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(5).
                         getT(0);
		auto& h1_sb71 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                        // ResStage_impl::h1_sb71_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2).getT(6);
		auto& h1_add64 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(6).
                         getT(0);
		auto& h1_sb72 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                        // ResStage_impl::h1_sb72_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2).getT(7);
		auto& h1_add65 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(2).                       // math::add<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(7).
                         getT(0);
		auto& h1_min1 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3);                        // ResStage_impl::h1_min1_t<NV>
		auto& h1_softbypass_switch12 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).getT(0); // ResStage_impl::h1_softbypass_switch12_t<NV>
		auto& h1_switcher18 = this->getT(4).getT(6).getT(0).getT(1).                                  // ResStage_impl::h1_switcher18_t
                              getT(1).getT(3).getT(0).getT(0);
		auto& h1_sb_container18 = this->getT(4).getT(6).getT(0).getT(1).                              // ResStage_impl::h1_sb_container18_t<NV>
                                  getT(1).getT(3).getT(0).getT(1);
		auto& h1_sb109 = this->getT(4).getT(6).getT(0).getT(1).                                       // ResStage_impl::h1_sb109_t<NV>
                         getT(1).getT(3).getT(0).getT(1).
                         getT(0);
		auto& h1_softbypass_switch21 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                 // ResStage_impl::h1_softbypass_switch21_t<NV>
                                       getT(3).getT(0).getT(1).getT(0).getT(0);
		auto& h1_cable_table13 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                       // ResStage_impl::h1_cable_table13_t<NV>
                                 getT(3).getT(0).getT(1).getT(0).getT(0).
                                 getT(0);
		auto& h1_switcher19 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                          // ResStage_impl::h1_switcher19_t<NV>
                              getT(3).getT(0).getT(1).getT(0).getT(0).
                              getT(1);
		auto& h1_sb_container19 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                      // ResStage_impl::h1_sb_container19_t<NV>
                                  getT(3).getT(0).getT(1).getT(0).getT(0).
                                  getT(2);
		auto& h1_sb110 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                       // ResStage_impl::h1_sb110_t<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& h1_add99 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                       // math::add<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
                         getT(0);
		auto& h1_sb111 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                       // ResStage_impl::h1_sb111_t<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& h1_add100 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                      // math::add<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
                          getT(0);
		auto& h1_sb112 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                       // ResStage_impl::h1_sb112_t<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(2);
		auto& h1_add101 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                      // math::add<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(2).getT(2).
                          getT(0);
		auto& h1_sb113 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                       // ResStage_impl::h1_sb113_t<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(3);
		auto& h1_add102 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                      // math::add<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(2).getT(3).
                          getT(0);
		auto& h1_sb114 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                       // ResStage_impl::h1_sb114_t<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(4);
		auto& h1_add103 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                      // math::add<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(2).getT(4).
                          getT(0);
		auto& h1_sb115 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                       // ResStage_impl::h1_sb115_t<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(5);
		auto& h1_add104 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                      // math::add<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(2).getT(5).
                          getT(0);
		auto& h1_sb116 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                       // ResStage_impl::h1_sb116_t<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(6);
		auto& h1_add105 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                      // math::add<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(2).getT(6).
                          getT(0);
		auto& h1_sb117 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                       // ResStage_impl::h1_sb117_t<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(7);
		auto& h1_add106 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                      // math::add<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(2).getT(7).
                          getT(0);
		auto& h1_sb118 = this->getT(4).getT(6).getT(0).getT(1).                                       // ResStage_impl::h1_sb118_t<NV>
                         getT(1).getT(3).getT(0).getT(1).
                         getT(1);
		auto& h1_softbypass_switch22 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                 // ResStage_impl::h1_softbypass_switch22_t<NV>
                                       getT(3).getT(0).getT(1).getT(1).getT(0);
		auto& h1_cable_table14 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                       // ResStage_impl::h1_cable_table14_t<NV>
                                 getT(3).getT(0).getT(1).getT(1).getT(0).
                                 getT(0);
		auto& h1_switcher20 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                          // ResStage_impl::h1_switcher20_t<NV>
                              getT(3).getT(0).getT(1).getT(1).getT(0).
                              getT(1);
		auto& h1_sb_container20 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                      // ResStage_impl::h1_sb_container20_t<NV>
                                  getT(3).getT(0).getT(1).getT(1).getT(0).
                                  getT(2);
		auto& h1_sb119 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                       // ResStage_impl::h1_sb119_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(0);
		auto& h1_add107 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                      // math::add<NV>
                          getT(0).getT(1).getT(1).getT(0).getT(2).getT(0).
                          getT(0);
		auto& h1_sb120 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                       // ResStage_impl::h1_sb120_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(1);
		auto& h1_add108 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                      // math::add<NV>
                          getT(0).getT(1).getT(1).getT(0).getT(2).getT(1).
                          getT(0);
		auto& h1_sb121 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                       // ResStage_impl::h1_sb121_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(2);
		auto& h1_add109 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                      // math::add<NV>
                          getT(0).getT(1).getT(1).getT(0).getT(2).getT(2).
                          getT(0);
		auto& h1_sb122 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                       // ResStage_impl::h1_sb122_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(3);
		auto& h1_add110 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                      // math::add<NV>
                          getT(0).getT(1).getT(1).getT(0).getT(2).getT(3).
                          getT(0);
		auto& h1_sb123 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                       // ResStage_impl::h1_sb123_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(4);
		auto& h1_add111 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                      // math::add<NV>
                          getT(0).getT(1).getT(1).getT(0).getT(2).getT(4).
                          getT(0);
		auto& h1_sb124 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                       // ResStage_impl::h1_sb124_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(5);
		auto& h1_add112 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                      // math::add<NV>
                          getT(0).getT(1).getT(1).getT(0).getT(2).getT(5).
                          getT(0);
		auto& h1_sb125 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                       // ResStage_impl::h1_sb125_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(6);
		auto& h1_add113 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                      // math::add<NV>
                          getT(0).getT(1).getT(1).getT(0).getT(2).getT(6).
                          getT(0);
		auto& h1_sb126 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                       // ResStage_impl::h1_sb126_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(7);
		auto& h1_add114 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(3).                      // math::add<NV>
                          getT(0).getT(1).getT(1).getT(0).getT(2).getT(7).
                          getT(0);
		auto& h1_Det1 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4);                        // ResStage_impl::h1_Det1_t<NV>
		auto& h1_softbypass_switch8 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).getT(0);  // ResStage_impl::h1_softbypass_switch8_t<NV>
		auto& h1_switcher17 = this->getT(4).getT(6).getT(0).getT(1).                                  // ResStage_impl::h1_switcher17_t<NV>
                              getT(1).getT(4).getT(0).getT(0);
		auto& h1_sb_container21 = this->getT(4).getT(6).getT(0).getT(1).                              // ResStage_impl::h1_sb_container21_t<NV>
                                  getT(1).getT(4).getT(0).getT(1);
		auto& h1_sb127 = this->getT(4).getT(6).getT(0).getT(1).                                       // ResStage_impl::h1_sb127_t<NV>
                         getT(1).getT(4).getT(0).getT(1).
                         getT(0);
		auto& h1_softbypass_switch24 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                 // ResStage_impl::h1_softbypass_switch24_t<NV>
                                       getT(4).getT(0).getT(1).getT(0).getT(0);
		auto& h1_cable_table15 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                       // ResStage_impl::h1_cable_table15_t<NV>
                                 getT(4).getT(0).getT(1).getT(0).getT(0).
                                 getT(0);
		auto& h1_switcher21 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                          // ResStage_impl::h1_switcher21_t<NV>
                              getT(4).getT(0).getT(1).getT(0).getT(0).
                              getT(1);
		auto& h1_sb_container22 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                      // ResStage_impl::h1_sb_container22_t<NV>
                                  getT(4).getT(0).getT(1).getT(0).getT(0).
                                  getT(2);
		auto& h1_sb128 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                       // ResStage_impl::h1_sb128_t<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& h1_add115 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                      // math::add<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
                          getT(0);
		auto& h1_sb129 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                       // ResStage_impl::h1_sb129_t<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& h1_add116 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                      // math::add<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
                          getT(0);
		auto& h1_sb130 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                       // ResStage_impl::h1_sb130_t<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(2);
		auto& h1_add117 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                      // math::add<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(2).getT(2).
                          getT(0);
		auto& h1_sb131 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                       // ResStage_impl::h1_sb131_t<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(3);
		auto& h1_add118 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                      // math::add<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(2).getT(3).
                          getT(0);
		auto& h1_sb132 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                       // ResStage_impl::h1_sb132_t<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(4);
		auto& h1_add119 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                      // math::add<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(2).getT(4).
                          getT(0);
		auto& h1_sb133 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                       // ResStage_impl::h1_sb133_t<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(5);
		auto& h1_add120 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                      // math::add<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(2).getT(5).
                          getT(0);
		auto& h1_sb134 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                       // ResStage_impl::h1_sb134_t<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(6);
		auto& h1_add121 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                      // math::add<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(2).getT(6).
                          getT(0);
		auto& h1_sb135 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                       // ResStage_impl::h1_sb135_t<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(2).getT(7);
		auto& h1_add122 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                      // math::add<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(2).getT(7).
                          getT(0);
		auto& h1_sb136 = this->getT(4).getT(6).getT(0).getT(1).                                       // ResStage_impl::h1_sb136_t<NV>
                         getT(1).getT(4).getT(0).getT(1).
                         getT(1);
		auto& h1_softbypass_switch25 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                 // ResStage_impl::h1_softbypass_switch25_t<NV>
                                       getT(4).getT(0).getT(1).getT(1).getT(0);
		auto& h1_cable_table16 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                       // ResStage_impl::h1_cable_table16_t<NV>
                                 getT(4).getT(0).getT(1).getT(1).getT(0).
                                 getT(0);
		auto& h1_switcher22 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                          // ResStage_impl::h1_switcher22_t<NV>
                              getT(4).getT(0).getT(1).getT(1).getT(0).
                              getT(1);
		auto& h1_sb_container23 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                      // ResStage_impl::h1_sb_container23_t<NV>
                                  getT(4).getT(0).getT(1).getT(1).getT(0).
                                  getT(2);
		auto& h1_sb137 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                       // ResStage_impl::h1_sb137_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(0);
		auto& h1_add123 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                      // math::add<NV>
                          getT(0).getT(1).getT(1).getT(0).getT(2).getT(0).
                          getT(0);
		auto& h1_sb138 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                       // ResStage_impl::h1_sb138_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(1);
		auto& h1_add124 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                      // math::add<NV>
                          getT(0).getT(1).getT(1).getT(0).getT(2).getT(1).
                          getT(0);
		auto& h1_sb139 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                       // ResStage_impl::h1_sb139_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(2);
		auto& h1_add125 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                      // math::add<NV>
                          getT(0).getT(1).getT(1).getT(0).getT(2).getT(2).
                          getT(0);
		auto& h1_sb140 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                       // ResStage_impl::h1_sb140_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(3);
		auto& h1_add126 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                      // math::add<NV>
                          getT(0).getT(1).getT(1).getT(0).getT(2).getT(3).
                          getT(0);
		auto& h1_sb141 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                       // ResStage_impl::h1_sb141_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(4);
		auto& h1_add127 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                      // math::add<NV>
                          getT(0).getT(1).getT(1).getT(0).getT(2).getT(4).
                          getT(0);
		auto& h1_sb142 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                       // ResStage_impl::h1_sb142_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(5);
		auto& h1_add128 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                      // math::add<NV>
                          getT(0).getT(1).getT(1).getT(0).getT(2).getT(5).
                          getT(0);
		auto& h1_sb143 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                       // ResStage_impl::h1_sb143_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(6);
		auto& h1_add129 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                      // math::add<NV>
                          getT(0).getT(1).getT(1).getT(0).getT(2).getT(6).
                          getT(0);
		auto& h1_sb144 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                       // ResStage_impl::h1_sb144_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(7);
		auto& h1_add130 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(4).                      // math::add<NV>
                          getT(0).getT(1).getT(1).getT(0).getT(2).getT(7).
                          getT(0);
		auto& h1_5ths = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(5);                        // ResStage_impl::h1_5ths_t<NV>
		auto& h1_softbypass_switch23 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(5).getT(0); // ResStage_impl::h1_softbypass_switch23_t<NV>
		auto& h1_switcher5 = this->getT(4).getT(6).getT(0).getT(1).                                   // ResStage_impl::h1_switcher5_t<NV>
                             getT(1).getT(5).getT(0).getT(0);
		auto& h1_sb_container5 = this->getT(4).getT(6).getT(0).getT(1).                 // ResStage_impl::h1_sb_container5_t<NV>
                                 getT(1).getT(5).getT(0).getT(1);
		auto& h1_sb27 = this->getT(4).getT(6).getT(0).getT(1).                          // ResStage_impl::h1_sb27_t<NV>
                        getT(1).getT(5).getT(0).getT(1).
                        getT(0);
		auto& h1_add25 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                 // math::add<NV>
                         getT(5).getT(0).getT(1).getT(0).getT(0);
		auto& h1_sb28 = this->getT(4).getT(6).getT(0).getT(1).                          // ResStage_impl::h1_sb28_t<NV>
                        getT(1).getT(5).getT(0).getT(1).
                        getT(1);
		auto& h1_add26 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                 // math::add<NV>
                         getT(5).getT(0).getT(1).getT(1).getT(0);
		auto& h1_sb29 = this->getT(4).getT(6).getT(0).getT(1).                          // ResStage_impl::h1_sb29_t<NV>
                        getT(1).getT(5).getT(0).getT(1).
                        getT(2);
		auto& h1_add27 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                 // math::add<NV>
                         getT(5).getT(0).getT(1).getT(2).getT(0);
		auto& h1_sb30 = this->getT(4).getT(6).getT(0).getT(1).                          // ResStage_impl::h1_sb30_t<NV>
                        getT(1).getT(5).getT(0).getT(1).
                        getT(3);
		auto& h1_add28 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                 // math::add<NV>
                         getT(5).getT(0).getT(1).getT(3).getT(0);
		auto& h1_sb31 = this->getT(4).getT(6).getT(0).getT(1).                          // ResStage_impl::h1_sb31_t<NV>
                        getT(1).getT(5).getT(0).getT(1).
                        getT(4);
		auto& h1_add29 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                 // math::add<NV>
                         getT(5).getT(0).getT(1).getT(4).getT(0);
		auto& h1_sb32 = this->getT(4).getT(6).getT(0).getT(1).                          // ResStage_impl::h1_sb32_t<NV>
                        getT(1).getT(5).getT(0).getT(1).
                        getT(5);
		auto& h1_add30 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                 // math::add<NV>
                         getT(5).getT(0).getT(1).getT(5).getT(0);
		auto& h1_sb33 = this->getT(4).getT(6).getT(0).getT(1).                          // ResStage_impl::h1_sb33_t<NV>
                        getT(1).getT(5).getT(0).getT(1).
                        getT(6);
		auto& h1_add31 = this->getT(4).getT(6).getT(0).getT(1).getT(1).                 // math::add<NV>
                         getT(5).getT(0).getT(1).getT(6).getT(0);
		auto& h1_free = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(6);          // ResStage_impl::h1_free_t<NV>
		auto& h1_add82 = this->getT(4).getT(6).getT(0).getT(1).getT(1).getT(6).getT(0); // math::add<NV>
		auto& h1_peak3 = this->getT(4).getT(6).getT(0).getT(1).getT(2);                 // ResStage_impl::h1_peak3_t<NV>
		auto& pma9 = this->getT(4).getT(6).getT(0).getT(1).getT(3);                     // ResStage_impl::pma9_t<NV>
		auto& minmax3 = this->getT(4).getT(6).getT(0).getT(1).getT(4);                  // ResStage_impl::minmax3_t<NV>
		auto& converter1 = this->getT(4).getT(6).getT(0).getT(1).getT(5);               // ResStage_impl::converter1_t<NV>
		auto& clear = this->getT(4).getT(6).getT(0).getT(1).getT(6);                    // math::clear<NV>
		auto& clear1 = this->getT(4).getT(6).getT(1);                                   // math::clear<NV>
		auto& add7 = this->getT(4).getT(6).getT(2);                                     // math::add<NV>
		auto& pi3 = this->getT(4).getT(6).getT(3);                                      // math::pi<NV>
		auto& peak3 = this->getT(4).getT(6).getT(4);                                    // ResStage_impl::peak3_t<NV>
		auto& clear3 = this->getT(4).getT(6).getT(5);                                   // math::clear<NV>
		auto& peak9 = this->getT(5);                                                    // ResStage_impl::peak9_t
		auto& FilterForRes1 = this->getT(6);                                            // project::FilterForRes<NV>
		auto& cable_table1 = this->getT(7);                                             // ResStage_impl::cable_table1_t<NV>
		auto& smoothed_parameter_unscaled = this->getT(8);                              // ResStage_impl::smoothed_parameter_unscaled_t<NV>
		auto& pma10 = this->getT(9);                                                    // ResStage_impl::pma10_t<NV>
		auto& branch = this->getT(10);                                                  // ResStage_impl::branch_t<NV>
		auto& chain4 = this->getT(10).getT(0);                                          // ResStage_impl::chain4_t<NV>
		auto& allpass1 = this->getT(10).getT(0).getT(0);                                // filters::allpass<NV>
		auto& one_pole3 = this->getT(10).getT(0).getT(1);                               // filters::one_pole<NV>
		auto& chain5 = this->getT(10).getT(1);                                          // ResStage_impl::chain5_t<NV>
		auto& res3 = this->getT(10).getT(1).getT(0);                                    // project::res1<NV>
		auto& chain8 = this->getT(10).getT(2);                                          // ResStage_impl::chain8_t<NV>
		auto& res4 = this->getT(10).getT(2).getT(0);                                    // project::res1<NV>
		auto& chain7 = this->getT(10).getT(3);                                          // ResStage_impl::chain7_t<NV>
		auto& res5 = this->getT(10).getT(3).getT(0);                                    // project::res1<NV>
		auto& chain = this->getT(10).getT(4);                                           // ResStage_impl::chain_t<NV>
		auto& modchain1 = this->getT(10).getT(4).getT(0);                               // ResStage_impl::modchain1_t<NV>
		auto& ahdsr = this->getT(10).getT(4).getT(0).getT(0);                           // ResStage_impl::ahdsr_t<NV>
		auto& branch2 = this->getT(10).getT(4).getT(1);                                 // ResStage_impl::branch2_t<NV>
		auto& Filetrig1 = this->getT(10).getT(4).getT(1).getT(0);                       // ResStage_impl::Filetrig1_t<NV>
		auto& Filetrig3 = this->getT(10).getT(4).getT(1).getT(1);                       // ResStage_impl::Filetrig3_t<NV>
		auto& Filetrig4 = this->getT(10).getT(4).getT(1).getT(2);                       // ResStage_impl::Filetrig4_t<NV>
		auto& Filetrig5 = this->getT(10).getT(4).getT(1).getT(3);                       // ResStage_impl::Filetrig5_t<NV>
		auto& gain2 = this->getT(10).getT(4).getT(2);                                   // core::gain<NV>
		auto& one_pole = this->getT(10).getT(4).getT(3);                                // filters::one_pole<NV>
		auto& FilterForRes = this->getT(11);                                            // project::FilterForRes<NV>
		
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
		
		this->getParameterT(14).connectT(0, pma11); // ResFreq -> pma11::Add
		
		auto& ResMode_p = this->getParameterT(18);
		ResMode_p.connectT(0, branch);       // ResMode -> branch::Index
		ResMode_p.connectT(1, cable_table1); // ResMode -> cable_table1::Value
		
		auto& ResLP_p = this->getParameterT(19);
		ResLP_p.connectT(0, one_pole3); // ResLP -> one_pole3::Frequency
		ResLP_p.connectT(1, res3);      // ResLP -> res3::LP
		ResLP_p.connectT(2, res5);      // ResLP -> res5::LP
		ResLP_p.connectT(3, res4);      // ResLP -> res4::LP
		
		auto& ResFeed_p = this->getParameterT(20);
		ResFeed_p.connectT(0, pma10);    // ResFeed -> pma10::Value
		ResFeed_p.connectT(1, allpass1); // ResFeed -> allpass1::Q
		
		this->getParameterT(21).connectT(0, FilterForRes); // PostCut -> FilterForRes::Cut
		
		this->getParameterT(22).connectT(0, FilterForRes); // PostRes -> FilterForRes::Res
		
		this->getParameterT(23).connectT(0, FilterForRes); // PostMode -> FilterForRes::Mode
		
		this->getParameterT(24).connectT(0, add50); // Fmode1 -> add50::Value
		
		this->getParameterT(25).connectT(0, branch7); // FilterModShape -> branch7::Index
		
		this->getParameterT(26).connectT(0, receive58); // Fb -> receive58::Feedback
		
		this->getParameterT(27).connectT(0, ahdsr); // Atk -> ahdsr::Attack
		
		this->getParameterT(28).connectT(0, ahdsr); // Rel -> ahdsr::Decay
		
		auto& SampleSync_p = this->getParameterT(29);
		SampleSync_p.connectT(0, Filetrig1); // SampleSync -> Filetrig1::sync
		SampleSync_p.connectT(1, Filetrig3); // SampleSync -> Filetrig3::sync
		SampleSync_p.connectT(2, Filetrig4); // SampleSync -> Filetrig4::sync
		SampleSync_p.connectT(3, Filetrig5); // SampleSync -> Filetrig5::sync
		
		this->getParameterT(30).connectT(0, add40); // Phase -> add40::Value
		
		auto& sampletempo_p = this->getParameterT(31);
		sampletempo_p.connectT(0, Filetrig3); // sampletempo -> Filetrig3::tempo
		sampletempo_p.connectT(1, Filetrig4); // sampletempo -> Filetrig4::tempo
		sampletempo_p.connectT(2, Filetrig5); // sampletempo -> Filetrig5::tempo
		sampletempo_p.connectT(3, Filetrig1); // sampletempo -> Filetrig1::tempo
		
		auto& samplediv_p = this->getParameterT(32);
		samplediv_p.connectT(0, Filetrig1); // samplediv -> Filetrig1::div
		samplediv_p.connectT(1, Filetrig3); // samplediv -> Filetrig3::div
		samplediv_p.connectT(2, Filetrig4); // samplediv -> Filetrig4::div
		samplediv_p.connectT(3, Filetrig5); // samplediv -> Filetrig5::div
		
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
		
		auto& SampleSigIn_p = this->getParameterT(50);
		SampleSigIn_p.connectT(0, Filetrig1); // SampleSigIn -> Filetrig1::input
		SampleSigIn_p.connectT(1, Filetrig3); // SampleSigIn -> Filetrig3::input
		SampleSigIn_p.connectT(2, Filetrig4); // SampleSigIn -> Filetrig4::input
		SampleSigIn_p.connectT(3, Filetrig5); // SampleSigIn -> Filetrig5::input
		
		this->getParameterT(51).connectT(0, add57); // RateDiv2 -> add57::Value
		
		this->getParameterT(52).connectT(0, add58); // RateDiv3 -> add58::Value
		
		this->getParameterT(53).connectT(0, branch10); // RateDivMode -> branch10::Index
		
		this->getParameterT(54).connectT(0, pma9); // fine -> pma9::Add
		
		this->getParameterT(55).connectT(0, h1_branch); // scale -> h1_branch::Index
		
		this->getParameterT(56).connectT(0, ahdsr); // SampRel -> ahdsr::Release
		
		auto& SampleShape_p = this->getParameterT(57);
		SampleShape_p.connectT(0, Filetrig1); // SampleShape -> Filetrig1::shape
		SampleShape_p.connectT(1, Filetrig3); // SampleShape -> Filetrig3::shape
		SampleShape_p.connectT(2, Filetrig4); // SampleShape -> Filetrig4::shape
		SampleShape_p.connectT(3, Filetrig5); // SampleShape -> Filetrig5::shape
		
		auto& SampleLoop_p = this->getParameterT(58);
		SampleLoop_p.connectT(0, Filetrig5); // SampleLoop -> Filetrig5::loop
		SampleLoop_p.connectT(1, Filetrig4); // SampleLoop -> Filetrig4::loop
		SampleLoop_p.connectT(2, Filetrig3); // SampleLoop -> Filetrig3::loop
		SampleLoop_p.connectT(3, Filetrig1); // SampleLoop -> Filetrig1::loop
		
		this->getParameterT(59).connectT(0, branch2); // SlotSel1 -> branch2::Index
		
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
		smoothed_parameter.getParameter().connectT(0, Filetrig1);               // smoothed_parameter -> Filetrig1::Pos
		pma3.getWrappedObject().getParameter().connectT(0, smoothed_parameter); // pma3 -> smoothed_parameter::Value
		pma3.getWrappedObject().getParameter().connectT(1, allpass1);           // pma3 -> allpass1::Smoothing
		pma3.getWrappedObject().getParameter().connectT(2, res3);               // pma3 -> res3::Comp
		pma3.getWrappedObject().getParameter().connectT(3, res3);               // pma3 -> res3::FbModifier
		pma3.getWrappedObject().getParameter().connectT(4, res5);               // pma3 -> res5::FbModifier
		pma3.getWrappedObject().getParameter().connectT(5, res4);               // pma3 -> res4::Comp
		pma3.getWrappedObject().getParameter().connectT(6, Filetrig3);          // pma3 -> Filetrig3::Pos
		pma3.getWrappedObject().getParameter().connectT(7, Filetrig4);          // pma3 -> Filetrig4::Pos
		pma3.getWrappedObject().getParameter().connectT(8, Filetrig5);          // pma3 -> Filetrig5::Pos
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
		xfader_p.getParameterT(0).connectT(0, gain);   // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain76); // xfader -> gain76::Gain
		auto& h1_switcher_p = h1_switcher.getWrappedObject().getParameter();
		h1_switcher_p.getParameterT(0).connectT(0, h1_sb1);                         // h1_switcher -> h1_sb1::Bypassed
		h1_switcher_p.getParameterT(1).connectT(0, h1_sb2);                         // h1_switcher -> h1_sb2::Bypassed
		h1_switcher_p.getParameterT(2).connectT(0, h1_sb3);                         // h1_switcher -> h1_sb3::Bypassed
		h1_switcher_p.getParameterT(3).connectT(0, h1_sb4);                         // h1_switcher -> h1_sb4::Bypassed
		h1_switcher_p.getParameterT(4).connectT(0, h1_sb5);                         // h1_switcher -> h1_sb5::Bypassed
		h1_switcher_p.getParameterT(5).connectT(0, h1_sb6);                         // h1_switcher -> h1_sb6::Bypassed
		h1_switcher_p.getParameterT(6).connectT(0, h1_sb7);                         // h1_switcher -> h1_sb7::Bypassed
		h1_switcher_p.getParameterT(7).connectT(0, h1_sb8);                         // h1_switcher -> h1_sb8::Bypassed
		h1_cable_table1.getWrappedObject().getParameter().connectT(0, h1_switcher); // h1_cable_table1 -> h1_switcher::Value
		auto& h1_switcher1_p = h1_switcher1.getWrappedObject().getParameter();
		h1_switcher1_p.getParameterT(0).connectT(0, h1_sb9);                         // h1_switcher1 -> h1_sb9::Bypassed
		h1_switcher1_p.getParameterT(1).connectT(0, h1_sb10);                        // h1_switcher1 -> h1_sb10::Bypassed
		h1_switcher1_p.getParameterT(2).connectT(0, h1_sb11);                        // h1_switcher1 -> h1_sb11::Bypassed
		h1_switcher1_p.getParameterT(3).connectT(0, h1_sb12);                        // h1_switcher1 -> h1_sb12::Bypassed
		h1_switcher1_p.getParameterT(4).connectT(0, h1_sb13);                        // h1_switcher1 -> h1_sb13::Bypassed
		h1_switcher1_p.getParameterT(5).connectT(0, h1_sb14);                        // h1_switcher1 -> h1_sb14::Bypassed
		h1_switcher1_p.getParameterT(6).connectT(0, h1_sb15);                        // h1_switcher1 -> h1_sb15::Bypassed
		h1_switcher1_p.getParameterT(7).connectT(0, h1_sb16);                        // h1_switcher1 -> h1_sb16::Bypassed
		h1_cable_table2.getWrappedObject().getParameter().connectT(0, h1_switcher1); // h1_cable_table2 -> h1_switcher1::Value
		auto& h1_switcher2_p = h1_switcher2.getWrappedObject().getParameter();
		h1_switcher2_p.getParameterT(0).connectT(0, h1_sb17); // h1_switcher2 -> h1_sb17::Bypassed
		h1_switcher2_p.getParameterT(1).connectT(0, h1_sb18); // h1_switcher2 -> h1_sb18::Bypassed
		auto& h1_switcher6_p = h1_switcher6.getWrappedObject().getParameter();
		auto& h1_switcher15_p = h1_switcher15.getWrappedObject().getParameter();
		h1_switcher15_p.getParameterT(0).connectT(0, h1_sb92);                         // h1_switcher15 -> h1_sb92::Bypassed
		h1_switcher15_p.getParameterT(1).connectT(0, h1_sb93);                         // h1_switcher15 -> h1_sb93::Bypassed
		h1_switcher15_p.getParameterT(2).connectT(0, h1_sb94);                         // h1_switcher15 -> h1_sb94::Bypassed
		h1_switcher15_p.getParameterT(3).connectT(0, h1_sb95);                         // h1_switcher15 -> h1_sb95::Bypassed
		h1_switcher15_p.getParameterT(4).connectT(0, h1_sb96);                         // h1_switcher15 -> h1_sb96::Bypassed
		h1_switcher15_p.getParameterT(5).connectT(0, h1_sb97);                         // h1_switcher15 -> h1_sb97::Bypassed
		h1_switcher15_p.getParameterT(6).connectT(0, h1_sb98);                         // h1_switcher15 -> h1_sb98::Bypassed
		h1_switcher15_p.getParameterT(7).connectT(0, h1_sb99);                         // h1_switcher15 -> h1_sb99::Bypassed
		h1_cable_table11.getWrappedObject().getParameter().connectT(0, h1_switcher15); // h1_cable_table11 -> h1_switcher15::Value
		auto& h1_switcher16_p = h1_switcher16.getWrappedObject().getParameter();
		h1_switcher16_p.getParameterT(0).connectT(0, h1_sb101);                        // h1_switcher16 -> h1_sb101::Bypassed
		h1_switcher16_p.getParameterT(1).connectT(0, h1_sb102);                        // h1_switcher16 -> h1_sb102::Bypassed
		h1_switcher16_p.getParameterT(2).connectT(0, h1_sb103);                        // h1_switcher16 -> h1_sb103::Bypassed
		h1_switcher16_p.getParameterT(3).connectT(0, h1_sb104);                        // h1_switcher16 -> h1_sb104::Bypassed
		h1_switcher16_p.getParameterT(4).connectT(0, h1_sb105);                        // h1_switcher16 -> h1_sb105::Bypassed
		h1_switcher16_p.getParameterT(5).connectT(0, h1_sb106);                        // h1_switcher16 -> h1_sb106::Bypassed
		h1_switcher16_p.getParameterT(6).connectT(0, h1_sb107);                        // h1_switcher16 -> h1_sb107::Bypassed
		h1_switcher16_p.getParameterT(7).connectT(0, h1_sb108);                        // h1_switcher16 -> h1_sb108::Bypassed
		h1_cable_table12.getWrappedObject().getParameter().connectT(0, h1_switcher16); // h1_cable_table12 -> h1_switcher16::Value
		auto& h1_switcher10_p = h1_switcher10.getWrappedObject().getParameter();
		h1_switcher10_p.getParameterT(0).connectT(0, h1_sb56);                        // h1_switcher10 -> h1_sb56::Bypassed
		h1_switcher10_p.getParameterT(1).connectT(0, h1_sb57);                        // h1_switcher10 -> h1_sb57::Bypassed
		h1_switcher10_p.getParameterT(2).connectT(0, h1_sb58);                        // h1_switcher10 -> h1_sb58::Bypassed
		h1_switcher10_p.getParameterT(3).connectT(0, h1_sb59);                        // h1_switcher10 -> h1_sb59::Bypassed
		h1_switcher10_p.getParameterT(4).connectT(0, h1_sb60);                        // h1_switcher10 -> h1_sb60::Bypassed
		h1_switcher10_p.getParameterT(5).connectT(0, h1_sb61);                        // h1_switcher10 -> h1_sb61::Bypassed
		h1_switcher10_p.getParameterT(6).connectT(0, h1_sb62);                        // h1_switcher10 -> h1_sb62::Bypassed
		h1_switcher10_p.getParameterT(7).connectT(0, h1_sb63);                        // h1_switcher10 -> h1_sb63::Bypassed
		h1_cable_table7.getWrappedObject().getParameter().connectT(0, h1_switcher10); // h1_cable_table7 -> h1_switcher10::Value
		auto& h1_switcher11_p = h1_switcher11.getWrappedObject().getParameter();
		h1_switcher11_p.getParameterT(0).connectT(0, h1_sb65);                        // h1_switcher11 -> h1_sb65::Bypassed
		h1_switcher11_p.getParameterT(1).connectT(0, h1_sb66);                        // h1_switcher11 -> h1_sb66::Bypassed
		h1_switcher11_p.getParameterT(2).connectT(0, h1_sb67);                        // h1_switcher11 -> h1_sb67::Bypassed
		h1_switcher11_p.getParameterT(3).connectT(0, h1_sb68);                        // h1_switcher11 -> h1_sb68::Bypassed
		h1_switcher11_p.getParameterT(4).connectT(0, h1_sb69);                        // h1_switcher11 -> h1_sb69::Bypassed
		h1_switcher11_p.getParameterT(5).connectT(0, h1_sb70);                        // h1_switcher11 -> h1_sb70::Bypassed
		h1_switcher11_p.getParameterT(6).connectT(0, h1_sb71);                        // h1_switcher11 -> h1_sb71::Bypassed
		h1_switcher11_p.getParameterT(7).connectT(0, h1_sb72);                        // h1_switcher11 -> h1_sb72::Bypassed
		h1_cable_table8.getWrappedObject().getParameter().connectT(0, h1_switcher11); // h1_cable_table8 -> h1_switcher11::Value
		auto& h1_switcher9_p = h1_switcher9.getWrappedObject().getParameter();
		auto& h1_switcher18_p = h1_switcher18.getWrappedObject().getParameter();
		auto& h1_switcher19_p = h1_switcher19.getWrappedObject().getParameter();
		h1_switcher19_p.getParameterT(0).connectT(0, h1_sb110);                        // h1_switcher19 -> h1_sb110::Bypassed
		h1_switcher19_p.getParameterT(1).connectT(0, h1_sb111);                        // h1_switcher19 -> h1_sb111::Bypassed
		h1_switcher19_p.getParameterT(2).connectT(0, h1_sb112);                        // h1_switcher19 -> h1_sb112::Bypassed
		h1_switcher19_p.getParameterT(3).connectT(0, h1_sb113);                        // h1_switcher19 -> h1_sb113::Bypassed
		h1_switcher19_p.getParameterT(4).connectT(0, h1_sb114);                        // h1_switcher19 -> h1_sb114::Bypassed
		h1_switcher19_p.getParameterT(5).connectT(0, h1_sb115);                        // h1_switcher19 -> h1_sb115::Bypassed
		h1_switcher19_p.getParameterT(6).connectT(0, h1_sb116);                        // h1_switcher19 -> h1_sb116::Bypassed
		h1_switcher19_p.getParameterT(7).connectT(0, h1_sb117);                        // h1_switcher19 -> h1_sb117::Bypassed
		h1_cable_table13.getWrappedObject().getParameter().connectT(0, h1_switcher19); // h1_cable_table13 -> h1_switcher19::Value
		auto& h1_switcher20_p = h1_switcher20.getWrappedObject().getParameter();
		h1_switcher20_p.getParameterT(0).connectT(0, h1_sb119);                        // h1_switcher20 -> h1_sb119::Bypassed
		h1_switcher20_p.getParameterT(1).connectT(0, h1_sb120);                        // h1_switcher20 -> h1_sb120::Bypassed
		h1_switcher20_p.getParameterT(2).connectT(0, h1_sb121);                        // h1_switcher20 -> h1_sb121::Bypassed
		h1_switcher20_p.getParameterT(3).connectT(0, h1_sb122);                        // h1_switcher20 -> h1_sb122::Bypassed
		h1_switcher20_p.getParameterT(4).connectT(0, h1_sb123);                        // h1_switcher20 -> h1_sb123::Bypassed
		h1_switcher20_p.getParameterT(5).connectT(0, h1_sb124);                        // h1_switcher20 -> h1_sb124::Bypassed
		h1_switcher20_p.getParameterT(6).connectT(0, h1_sb125);                        // h1_switcher20 -> h1_sb125::Bypassed
		h1_switcher20_p.getParameterT(7).connectT(0, h1_sb126);                        // h1_switcher20 -> h1_sb126::Bypassed
		h1_cable_table14.getWrappedObject().getParameter().connectT(0, h1_switcher20); // h1_cable_table14 -> h1_switcher20::Value
		auto& h1_switcher5_p = h1_switcher5.getWrappedObject().getParameter();
		h1_switcher5_p.getParameterT(0).connectT(0, h1_sb27); // h1_switcher5 -> h1_sb27::Bypassed
		h1_switcher5_p.getParameterT(1).connectT(0, h1_sb28); // h1_switcher5 -> h1_sb28::Bypassed
		h1_switcher5_p.getParameterT(2).connectT(0, h1_sb29); // h1_switcher5 -> h1_sb29::Bypassed
		h1_switcher5_p.getParameterT(3).connectT(0, h1_sb30); // h1_switcher5 -> h1_sb30::Bypassed
		h1_switcher5_p.getParameterT(4).connectT(0, h1_sb31); // h1_switcher5 -> h1_sb31::Bypassed
		h1_switcher5_p.getParameterT(5).connectT(0, h1_sb32); // h1_switcher5 -> h1_sb32::Bypassed
		h1_switcher5_p.getParameterT(6).connectT(0, h1_sb33); // h1_switcher5 -> h1_sb33::Bypassed
		auto& h1_switcher21_p = h1_switcher21.getWrappedObject().getParameter();
		h1_switcher21_p.getParameterT(0).connectT(0, h1_sb128);                        // h1_switcher21 -> h1_sb128::Bypassed
		h1_switcher21_p.getParameterT(1).connectT(0, h1_sb129);                        // h1_switcher21 -> h1_sb129::Bypassed
		h1_switcher21_p.getParameterT(2).connectT(0, h1_sb130);                        // h1_switcher21 -> h1_sb130::Bypassed
		h1_switcher21_p.getParameterT(3).connectT(0, h1_sb131);                        // h1_switcher21 -> h1_sb131::Bypassed
		h1_switcher21_p.getParameterT(4).connectT(0, h1_sb132);                        // h1_switcher21 -> h1_sb132::Bypassed
		h1_switcher21_p.getParameterT(5).connectT(0, h1_sb133);                        // h1_switcher21 -> h1_sb133::Bypassed
		h1_switcher21_p.getParameterT(6).connectT(0, h1_sb134);                        // h1_switcher21 -> h1_sb134::Bypassed
		h1_switcher21_p.getParameterT(7).connectT(0, h1_sb135);                        // h1_switcher21 -> h1_sb135::Bypassed
		h1_cable_table15.getWrappedObject().getParameter().connectT(0, h1_switcher21); // h1_cable_table15 -> h1_switcher21::Value
		auto& h1_switcher22_p = h1_switcher22.getWrappedObject().getParameter();
		h1_switcher22_p.getParameterT(0).connectT(0, h1_sb137);                        // h1_switcher22 -> h1_sb137::Bypassed
		h1_switcher22_p.getParameterT(1).connectT(0, h1_sb138);                        // h1_switcher22 -> h1_sb138::Bypassed
		h1_switcher22_p.getParameterT(2).connectT(0, h1_sb139);                        // h1_switcher22 -> h1_sb139::Bypassed
		h1_switcher22_p.getParameterT(3).connectT(0, h1_sb140);                        // h1_switcher22 -> h1_sb140::Bypassed
		h1_switcher22_p.getParameterT(4).connectT(0, h1_sb141);                        // h1_switcher22 -> h1_sb141::Bypassed
		h1_switcher22_p.getParameterT(5).connectT(0, h1_sb142);                        // h1_switcher22 -> h1_sb142::Bypassed
		h1_switcher22_p.getParameterT(6).connectT(0, h1_sb143);                        // h1_switcher22 -> h1_sb143::Bypassed
		h1_switcher22_p.getParameterT(7).connectT(0, h1_sb144);                        // h1_switcher22 -> h1_sb144::Bypassed
		h1_cable_table16.getWrappedObject().getParameter().connectT(0, h1_switcher22); // h1_cable_table16 -> h1_switcher22::Value
		auto& h1_switcher17_p = h1_switcher17.getWrappedObject().getParameter();
		h1_switcher17_p.getParameterT(0).connectT(0, h1_sb127);                 // h1_switcher17 -> h1_sb127::Bypassed
		h1_switcher17_p.getParameterT(1).connectT(0, h1_sb136);                 // h1_switcher17 -> h1_sb136::Bypassed
		pma11.getWrappedObject().getParameter().connectT(0, h1_cable_table1);   // pma11 -> h1_cable_table1::Value
		pma11.getWrappedObject().getParameter().connectT(1, h1_cable_table2);   // pma11 -> h1_cable_table2::Value
		pma11.getWrappedObject().getParameter().connectT(2, h1_switcher2);      // pma11 -> h1_switcher2::Value
		pma11.getWrappedObject().getParameter().connectT(3, h1_switcher6);      // pma11 -> h1_switcher6::Value
		pma11.getWrappedObject().getParameter().connectT(4, h1_cable_table11);  // pma11 -> h1_cable_table11::Value
		pma11.getWrappedObject().getParameter().connectT(5, h1_cable_table12);  // pma11 -> h1_cable_table12::Value
		pma11.getWrappedObject().getParameter().connectT(6, h1_cable_table7);   // pma11 -> h1_cable_table7::Value
		pma11.getWrappedObject().getParameter().connectT(7, h1_cable_table8);   // pma11 -> h1_cable_table8::Value
		pma11.getWrappedObject().getParameter().connectT(8, h1_switcher9);      // pma11 -> h1_switcher9::Value
		pma11.getWrappedObject().getParameter().connectT(9, h1_switcher18);     // pma11 -> h1_switcher18::Value
		pma11.getWrappedObject().getParameter().connectT(10, h1_cable_table13); // pma11 -> h1_cable_table13::Value
		pma11.getWrappedObject().getParameter().connectT(11, h1_cable_table14); // pma11 -> h1_cable_table14::Value
		pma11.getWrappedObject().getParameter().connectT(12, h1_switcher5);     // pma11 -> h1_switcher5::Value
		pma11.getWrappedObject().getParameter().connectT(13, h1_add82);         // pma11 -> h1_add82::Value
		pma11.getWrappedObject().getParameter().connectT(14, h1_switcher17);    // pma11 -> h1_switcher17::Value
		pma11.getWrappedObject().getParameter().connectT(15, h1_cable_table15); // pma11 -> h1_cable_table15::Value
		pma11.getWrappedObject().getParameter().connectT(16, h1_cable_table16); // pma11 -> h1_cable_table16::Value
		minmax3.getWrappedObject().getParameter().connectT(0, allpass1);        // minmax3 -> allpass1::Frequency
		minmax3.getWrappedObject().getParameter().connectT(1, res4);            // minmax3 -> res4::Freq
		minmax3.getWrappedObject().getParameter().connectT(2, Filetrig1);       // minmax3 -> Filetrig1::freq
		minmax3.getWrappedObject().getParameter().connectT(3, Filetrig3);       // minmax3 -> Filetrig3::freq
		minmax3.getWrappedObject().getParameter().connectT(4, Filetrig4);       // minmax3 -> Filetrig4::freq
		minmax3.getWrappedObject().getParameter().connectT(5, Filetrig5);       // minmax3 -> Filetrig5::freq
		pma9.getWrappedObject().getParameter().connectT(0, minmax3);            // pma9 -> minmax3::Value
		h1_peak3.getParameter().connectT(0, pma9);                              // h1_peak3 -> pma9::Value
		converter1.getWrappedObject().getParameter().connectT(0, res3);         // converter1 -> res3::Del
		converter1.getWrappedObject().getParameter().connectT(1, res4);         // converter1 -> res4::Del
		converter1.getWrappedObject().getParameter().connectT(2, res5);         // converter1 -> res5::Del
		converter1.getWrappedObject().getParameter().connectT(3, Filetrig1);    // converter1 -> Filetrig1::MS
		converter1.getWrappedObject().getParameter().connectT(4, Filetrig3);    // converter1 -> Filetrig3::MS
		converter1.getWrappedObject().getParameter().connectT(5, Filetrig4);    // converter1 -> Filetrig4::MS
		converter1.getWrappedObject().getParameter().connectT(6, Filetrig5);    // converter1 -> Filetrig5::MS
		auto& ahdsr_p = ahdsr.getWrappedObject().getParameter();
		ahdsr_p.getParameterT(0).connectT(0, gain2);                                             // ahdsr -> gain2::Gain
		ahdsr_p.getParameterT(0).connectT(1, Filetrig1);                                         // ahdsr -> Filetrig1::gate
		ahdsr_p.getParameterT(0).connectT(2, Filetrig3);                                         // ahdsr -> Filetrig3::gate
		ahdsr_p.getParameterT(0).connectT(3, Filetrig4);                                         // ahdsr -> Filetrig4::gate
		ahdsr_p.getParameterT(0).connectT(4, Filetrig5);                                         // ahdsr -> Filetrig5::gate
		peak3.getParameter().connectT(0, ahdsr);                                                 // peak3 -> ahdsr::Gate
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
		
		pma11.setParameterT(0, 0.); // control::pma::Value
		pma11.setParameterT(1, 0.); // control::pma::Multiply
		;                           // pma11::Add is automated
		
		minmax2.setParameterT(0, 0.); // control::minmax::Value
		minmax2.setParameterT(1, 0.); // control::minmax::Minimum
		minmax2.setParameterT(2, 1.); // control::minmax::Maximum
		minmax2.setParameterT(3, 1.); // control::minmax::Skew
		minmax2.setParameterT(4, 0.); // control::minmax::Step
		minmax2.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // h1_branch::Index is automated
		
		; // h1_switcher2::Value is automated
		
		; // h1_cable_table1::Value is automated
		
		; // h1_switcher::Value is automated
		
		h1_add2.setParameterT(0, 0.); // math::add::Value
		
		h1_add4.setParameterT(0, 0.25); // math::add::Value
		
		h1_add3.setParameterT(0, 0.39625); // math::add::Value
		
		h1_add6.setParameterT(0, 0.5); // math::add::Value
		
		h1_add5.setParameterT(0, 0.5805); // math::add::Value
		
		h1_add8.setParameterT(0, 0.646); // math::add::Value
		
		h1_add7.setParameterT(0, 0.702); // math::add::Value
		
		h1_add9.setParameterT(0, 0.75); // math::add::Value
		
		; // h1_cable_table2::Value is automated
		
		; // h1_switcher1::Value is automated
		
		h1_add10.setParameterT(0, 0.792); // math::add::Value
		
		h1_add11.setParameterT(0, 0.8305); // math::add::Value
		
		h1_add12.setParameterT(0, 0.865); // math::add::Value
		
		h1_add13.setParameterT(0, 0.896); // math::add::Value
		
		h1_add14.setParameterT(0, 0.925); // math::add::Value
		
		h1_add15.setParameterT(0, 0.9515); // math::add::Value
		
		h1_add16.setParameterT(0, 0.975); // math::add::Value
		
		h1_add17.setParameterT(0, 1.); // math::add::Value
		
		; // h1_switcher6::Value is automated
		
		; // h1_cable_table11::Value is automated
		
		; // h1_switcher15::Value is automated
		
		h1_add83.setParameterT(0, 0.); // math::add::Value
		
		h1_add84.setParameterT(0, 0.0417); // math::add::Value
		
		h1_add85.setParameterT(0, 0.0833); // math::add::Value
		
		h1_add86.setParameterT(0, 0.104189); // math::add::Value
		
		h1_add87.setParameterT(0, 0.1459); // math::add::Value
		
		h1_add88.setParameterT(0, 0.1876); // math::add::Value
		
		h1_add89.setParameterT(0, 0.2292); // math::add::Value
		
		h1_add90.setParameterT(0, 0.25); // math::add::Value
		
		; // h1_cable_table12::Value is automated
		
		; // h1_switcher16::Value is automated
		
		h1_add91.setParameterT(0, 0.2916); // math::add::Value
		
		h1_add92.setParameterT(0, 0.3334); // math::add::Value
		
		h1_add93.setParameterT(0, 0.3541); // math::add::Value
		
		h1_add94.setParameterT(0, 0.3958); // math::add::Value
		
		h1_add95.setParameterT(0, 0.4376); // math::add::Value
		
		h1_add96.setParameterT(0, 0.4791); // math::add::Value
		
		h1_add97.setParameterT(0, 0.5); // math::add::Value
		
		h1_add98.setParameterT(0, 0.5417); // math::add::Value
		
		; // h1_switcher9::Value is automated
		
		; // h1_cable_table7::Value is automated
		
		; // h1_switcher10::Value is automated
		
		h1_add50.setParameterT(0, 0.); // math::add::Value
		
		h1_add51.setParameterT(0, 0.0626); // math::add::Value
		
		h1_add52.setParameterT(0, 0.1458); // math::add::Value
		
		h1_add53.setParameterT(0, 0.2084); // math::add::Value
		
		h1_add54.setParameterT(0, 0.2501); // math::add::Value
		
		h1_add55.setParameterT(0, 0.3124); // math::add::Value
		
		h1_add56.setParameterT(0, 0.395911); // math::add::Value
		
		h1_add57.setParameterT(0, 0.4584); // math::add::Value
		
		; // h1_cable_table8::Value is automated
		
		; // h1_switcher11::Value is automated
		
		h1_add58.setParameterT(0, 0.5); // math::add::Value
		
		h1_add59.setParameterT(0, 0.56244); // math::add::Value
		
		h1_add60.setParameterT(0, 0.6458); // math::add::Value
		
		h1_add61.setParameterT(0, 0.6875); // math::add::Value
		
		h1_add62.setParameterT(0, 0.75); // math::add::Value
		
		h1_add63.setParameterT(0, 0.8125); // math::add::Value
		
		h1_add64.setParameterT(0, 0.8958); // math::add::Value
		
		h1_add65.setParameterT(0, 1.); // math::add::Value
		
		; // h1_switcher18::Value is automated
		
		; // h1_cable_table13::Value is automated
		
		; // h1_switcher19::Value is automated
		
		h1_add99.setParameterT(0, 0.); // math::add::Value
		
		h1_add100.setParameterT(0, 0.0417); // math::add::Value
		
		h1_add101.setParameterT(0, 0.0626); // math::add::Value
		
		h1_add102.setParameterT(0, 0.1042); // math::add::Value
		
		h1_add103.setParameterT(0, 0.1458); // math::add::Value
		
		h1_add104.setParameterT(0, 0.1876); // math::add::Value
		
		h1_add105.setParameterT(0, 0.2291); // math::add::Value
		
		h1_add106.setParameterT(0, 0.25); // math::add::Value
		
		; // h1_cable_table14::Value is automated
		
		; // h1_switcher20::Value is automated
		
		h1_add107.setParameterT(0, 0.2916); // math::add::Value
		
		h1_add108.setParameterT(0, 0.3124); // math::add::Value
		
		h1_add109.setParameterT(0, 0.3542); // math::add::Value
		
		h1_add110.setParameterT(0, 0.3959); // math::add::Value
		
		h1_add111.setParameterT(0, 0.4376); // math::add::Value
		
		h1_add112.setParameterT(0, 0.4792); // math::add::Value
		
		h1_add113.setParameterT(0, 0.5); // math::add::Value
		
		h1_add114.setParameterT(0, 0.5); // math::add::Value
		
		; // h1_switcher17::Value is automated
		
		; // h1_cable_table15::Value is automated
		
		; // h1_switcher21::Value is automated
		
		h1_add115.setParameterT(0, 0.); // math::add::Value
		
		h1_add116.setParameterT(0, 0.00754482); // math::add::Value
		
		h1_add117.setParameterT(0, 0.0163417); // math::add::Value
		
		h1_add118.setParameterT(0, 0.0311212); // math::add::Value
		
		h1_add119.setParameterT(0, 0.0376708); // math::add::Value
		
		h1_add120.setParameterT(0, 0.048629); // math::add::Value
		
		h1_add121.setParameterT(0, 0.059939); // math::add::Value
		
		h1_add122.setParameterT(0, 0.0681339); // math::add::Value
		
		; // h1_cable_table16::Value is automated
		
		; // h1_switcher22::Value is automated
		
		h1_add123.setParameterT(0, 0.0842896); // math::add::Value
		
		h1_add124.setParameterT(0, 0.0857338); // math::add::Value
		
		h1_add125.setParameterT(0, 0.104119); // math::add::Value
		
		h1_add126.setParameterT(0, 0.114154); // math::add::Value
		
		h1_add127.setParameterT(0, 0.123716); // math::add::Value
		
		h1_add128.setParameterT(0, 0.131463); // math::add::Value
		
		h1_add129.setParameterT(0, 0.144165); // math::add::Value
		
		h1_add130.setParameterT(0, 0.143979); // math::add::Value
		
		; // h1_switcher5::Value is automated
		
		h1_add25.setParameterT(0, 0.); // math::add::Value
		
		h1_add26.setParameterT(0, 0.1459); // math::add::Value
		
		h1_add27.setParameterT(0, 0.2916); // math::add::Value
		
		h1_add28.setParameterT(0, 0.4375); // math::add::Value
		
		h1_add29.setParameterT(0, 0.5834); // math::add::Value
		
		h1_add30.setParameterT(0, 0.7291); // math::add::Value
		
		h1_add31.setParameterT(0, 0.875); // math::add::Value
		
		; // h1_add82::Value is automated
		
		;                          // pma9::Value is automated
		pma9.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma9::Add is automated
		
		;                                   // minmax3::Value is automated
		minmax3.setParameterT(1, 20.);      // control::minmax::Minimum
		minmax3.setParameterT(2, 20000.);   // control::minmax::Maximum
		minmax3.setParameterT(3, 0.229905); // control::minmax::Skew
		minmax3.setParameterT(4, 0.);       // control::minmax::Step
		minmax3.setParameterT(5, 0.);       // control::minmax::Polarity
		
		converter1.setParameterT(0, 0.); // control::converter::Value
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		; // add7::Value is automated
		
		pi3.setParameterT(0, 0.469102); // math::pi::Value
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		; // FilterForRes1::Cut is automated
		; // FilterForRes1::Res is automated
		; // FilterForRes1::Mode is automated
		
		; // cable_table1::Value is automated
		
		;                                                    // smoothed_parameter_unscaled::Value is automated
		smoothed_parameter_unscaled.setParameterT(1, 614.1); // control::smoothed_parameter_unscaled::SmoothingTime
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
		
		;                                 // res3::feed is automated
		;                                 // res3::Del is automated
		res3.setParameterT(2, 3.);        // project::res1::Block
		;                                 // res3::LP is automated
		;                                 // res3::FbModifier is automated
		res3.setParameterT(5, 1067.2);    // project::res1::Freq
		res3.setParameterT(6, 0.);        // project::res1::Mode
		;                                 // res3::Comp is automated
		res3.setParameterT(8, -0.199999); // project::res1::ga
		
		;                              // res4::feed is automated
		;                              // res4::Del is automated
		res4.setParameterT(2, 3.);     // project::res1::Block
		;                              // res4::LP is automated
		res4.setParameterT(4, 20000.); // project::res1::FbModifier
		;                              // res4::Freq is automated
		res4.setParameterT(6, 1.);     // project::res1::Mode
		;                              // res4::Comp is automated
		res4.setParameterT(8, -3.8);   // project::res1::ga
		
		;                                 // res5::feed is automated
		;                                 // res5::Del is automated
		res5.setParameterT(2, 1.);        // project::res1::Block
		;                                 // res5::LP is automated
		;                                 // res5::FbModifier is automated
		res5.setParameterT(5, 8345.7);    // project::res1::Freq
		res5.setParameterT(6, 2.);        // project::res1::Mode
		res5.setParameterT(7, 0.0171621); // project::res1::Comp
		res5.setParameterT(8, 0.);        // project::res1::ga
		
		;                                 // ahdsr::Attack is automated
		ahdsr.setParameterT(1, 1.);       // envelope::ahdsr::AttackLevel
		ahdsr.setParameterT(2, 0.);       // envelope::ahdsr::Hold
		;                                 // ahdsr::Decay is automated
		ahdsr.setParameterT(4, 0.);       // envelope::ahdsr::Sustain
		;                                 // ahdsr::Release is automated
		ahdsr.setParameterT(6, 0.495684); // envelope::ahdsr::AttackCurve
		ahdsr.setParameterT(7, 0.);       // envelope::ahdsr::Retrigger
		;                                 // ahdsr::Gate is automated
		
		; // branch2::Index is automated
		
		; // Filetrig1::gate is automated
		; // Filetrig1::sync is automated
		; // Filetrig1::freq is automated
		; // Filetrig1::Pos is automated
		; // Filetrig1::tempo is automated
		; // Filetrig1::div is automated
		; // Filetrig1::shape is automated
		; // Filetrig1::loop is automated
		; // Filetrig1::MS is automated
		; // Filetrig1::input is automated
		
		; // Filetrig3::gate is automated
		; // Filetrig3::sync is automated
		; // Filetrig3::freq is automated
		; // Filetrig3::Pos is automated
		; // Filetrig3::tempo is automated
		; // Filetrig3::div is automated
		; // Filetrig3::shape is automated
		; // Filetrig3::loop is automated
		; // Filetrig3::MS is automated
		; // Filetrig3::input is automated
		
		; // Filetrig4::gate is automated
		; // Filetrig4::sync is automated
		; // Filetrig4::freq is automated
		; // Filetrig4::Pos is automated
		; // Filetrig4::tempo is automated
		; // Filetrig4::div is automated
		; // Filetrig4::shape is automated
		; // Filetrig4::loop is automated
		; // Filetrig4::MS is automated
		; // Filetrig4::input is automated
		
		; // Filetrig5::gate is automated
		; // Filetrig5::sync is automated
		; // Filetrig5::freq is automated
		; // Filetrig5::Pos is automated
		; // Filetrig5::tempo is automated
		; // Filetrig5::div is automated
		; // Filetrig5::shape is automated
		; // Filetrig5::loop is automated
		; // Filetrig5::MS is automated
		; // Filetrig5::input is automated
		
		;                           // gain2::Gain is automated
		gain2.setParameterT(1, 0.); // core::gain::Smoothing
		gain2.setParameterT(2, 0.); // core::gain::ResetValue
		
		one_pole.setParameterT(0, 5850.79); // filters::one_pole::Frequency
		one_pole.setParameterT(1, 1.);      // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);      // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01);    // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 0.);      // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);      // filters::one_pole::Enabled
		
		; // FilterForRes::Cut is automated
		; // FilterForRes::Res is automated
		; // FilterForRes::Mode is automated
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, -28.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 196.);
		this->setParameterT(8, 2.3);
		this->setParameterT(9, 1.);
		this->setParameterT(10, 28.4862);
		this->setParameterT(11, 0.669548);
		this->setParameterT(12, 7.);
		this->setParameterT(13, 31.);
		this->setParameterT(14, 0.393937);
		this->setParameterT(15, 0.0373641);
		this->setParameterT(16, 1.);
		this->setParameterT(17, 0.);
		this->setParameterT(18, 5.);
		this->setParameterT(19, 20000.);
		this->setParameterT(20, 1.);
		this->setParameterT(21, 1.);
		this->setParameterT(22, 0.);
		this->setParameterT(23, 1.);
		this->setParameterT(24, 11.);
		this->setParameterT(25, 1.);
		this->setParameterT(26, 0.);
		this->setParameterT(27, 0.);
		this->setParameterT(28, 1000.);
		this->setParameterT(29, 0.);
		this->setParameterT(30, 0.);
		this->setParameterT(31, 0.);
		this->setParameterT(32, 10.);
		this->setParameterT(33, 1.);
		this->setParameterT(34, 0.229102);
		this->setParameterT(35, 1.);
		this->setParameterT(36, 0.047332);
		this->setParameterT(37, 0.0177344);
		this->setParameterT(38, 1.);
		this->setParameterT(39, 1.);
		this->setParameterT(40, 4.);
		this->setParameterT(41, 0.339215);
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
		this->setParameterT(54, 0.519846);
		this->setParameterT(55, 1.);
		this->setParameterT(56, 0.77244);
		this->setParameterT(57, 1.);
		this->setParameterT(58, 0.0920516);
		this->setParameterT(59, 1.);
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
		this->getT(4).getT(6).getT(0).getT(1).getT(1).                           // ResStage_impl::h1_cable_table1_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(4).getT(6).getT(0).getT(1).getT(1).                           // ResStage_impl::h1_cable_table2_t<NV>
        getT(0).getT(0).getT(1).getT(1).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(4).getT(6).getT(0).getT(1).getT(1).                           // ResStage_impl::h1_cable_table11_t<NV>
        getT(1).getT(0).getT(1).getT(0).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(4).getT(6).getT(0).getT(1).getT(1).                           // ResStage_impl::h1_cable_table12_t<NV>
        getT(1).getT(0).getT(1).getT(1).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(4).getT(6).getT(0).getT(1).getT(1).                           // ResStage_impl::h1_cable_table7_t<NV>
        getT(2).getT(0).getT(1).getT(0).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(4).getT(6).getT(0).getT(1).getT(1).                           // ResStage_impl::h1_cable_table8_t<NV>
        getT(2).getT(0).getT(1).getT(1).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(4).getT(6).getT(0).getT(1).getT(1).                           // ResStage_impl::h1_cable_table13_t<NV>
        getT(3).getT(0).getT(1).getT(0).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(4).getT(6).getT(0).getT(1).getT(1).                           // ResStage_impl::h1_cable_table14_t<NV>
        getT(3).getT(0).getT(1).getT(1).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(4).getT(6).getT(0).getT(1).getT(1).                           // ResStage_impl::h1_cable_table15_t<NV>
        getT(4).getT(0).getT(1).getT(0).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(4).getT(6).getT(0).getT(1).getT(1).                           // ResStage_impl::h1_cable_table16_t<NV>
        getT(4).getT(0).getT(1).getT(1).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(4).getT(6).getT(0).getT(1).getT(2).setExternalData(b, index); // ResStage_impl::h1_peak3_t<NV>
		this->getT(4).getT(6).getT(4).setExternalData(b, index);                 // ResStage_impl::peak3_t<NV>
		this->getT(5).setExternalData(b, index);                                 // ResStage_impl::peak9_t
		this->getT(7).setExternalData(b, index);                                 // ResStage_impl::cable_table1_t<NV>
		this->getT(10).getT(4).getT(0).getT(0).setExternalData(b, index);        // ResStage_impl::ahdsr_t<NV>
		this->getT(10).getT(4).getT(1).getT(0).setExternalData(b, index);        // ResStage_impl::Filetrig1_t<NV>
		this->getT(10).getT(4).getT(1).getT(1).setExternalData(b, index);        // ResStage_impl::Filetrig3_t<NV>
		this->getT(10).getT(4).getT(1).getT(2).setExternalData(b, index);        // ResStage_impl::Filetrig4_t<NV>
		this->getT(10).getT(4).getT(1).getT(3).setExternalData(b, index);        // ResStage_impl::Filetrig5_t<NV>
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


