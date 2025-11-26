#pragma once

// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace dtest_impl
{
// ==============================| Node & Parameter type declarations |==============================

DECLARE_PARAMETER_RANGE_SKEW(xfader_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using xfader_c0 = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      xfader_c0Range>;

template <int NV> using xfader_c1 = xfader_c0<NV>;

template <int NV> using xfader_c2 = xfader_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, 
                                        xfader_c1<NV>, 
                                        xfader_c2<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::linear>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, filters::svf<NV>>, 
                                  core::gain<NV>>;

template <int NV> using chain6_t = chain4_t<NV>;

template <int NV> using chain5_t = chain4_t<NV>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain4_t<NV>>, 
                                 chain6_t<NV>, 
                                 chain5_t<NV>>;

template <int NV>
using comp_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                         wrap::no_data<dynamics::comp>>;

template <int NV> using xfader1_c0 = xfader_c0<NV>;

template <int NV> using xfader1_c1 = xfader_c0<NV>;

template <int NV>
using xfader1_multimod = parameter::list<xfader1_c0<NV>, xfader1_c1<NV>>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::linear>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, core::gain<NV>>>;
using peak_t = wrap::no_data<core::peak>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, wrap::no_process<math::clear<NV>>>, 
                                  math::add<NV>, 
                                  wrap::no_process<math::rect<NV>>, 
                                  peak_t, 
                                  core::gain<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain_t<NV>>, 
                                  chain2_t<NV>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, xfader1_t<NV>>, 
                                  split1_t<NV>>;

template <int NV>
using converter_mod = parameter::chain<ranges::Identity, 
                                       parameter::plain<core::fix_delay, 0>, 
                                       parameter::plain<jdsp::jdelay<NV>, 1>, 
                                       parameter::plain<project::comb<NV>, 1>, 
                                       parameter::plain<project::comb<NV>, 1>>;

template <int NV>
using converter_t = control::converter<converter_mod<NV>, 
                                       conversion_logic::freq2ms>;
using stereo_cable = cable::block<2>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, routing::receive<stereo_cable>>, 
                                  core::fix_delay, 
                                  filters::one_pole<NV>, 
                                  routing::send<stereo_cable>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, routing::receive<stereo_cable>>, 
                                  jdsp::jdelay<NV>, 
                                  fx::phase_delay<NV>, 
                                  math::tanh<NV>, 
                                  routing::send<stereo_cable>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<2, project::comb<NV>>, 
                                  filters::svf_eq<NV>>;

template <int NV> using chain11_t = chain8_t<NV>;

struct cable_table_t_data
{
	span<float, 512> data =
	{
		1.f, 0.996883f, 0.993767f, 0.99065f, 0.987533f, 0.984417f,
		0.9813f, 0.978183f, 0.975067f, 0.97195f, 0.968833f, 0.965717f,
		0.9626f, 0.959548f, 0.956527f, 0.953505f, 0.950484f, 0.947462f,
		0.94444f, 0.941419f, 0.938397f, 0.935376f, 0.932354f, 0.929333f,
		0.926311f, 0.923302f, 0.920372f, 0.917442f, 0.914512f, 0.911582f,
		0.908652f, 0.905723f, 0.902793f, 0.899863f, 0.896933f, 0.894003f,
		0.891073f, 0.888143f, 0.885243f, 0.882402f, 0.879561f, 0.876719f,
		0.873878f, 0.871036f, 0.868195f, 0.865353f, 0.862512f, 0.85967f,
		0.856829f, 0.853987f, 0.851146f, 0.848331f, 0.845574f, 0.842818f,
		0.840062f, 0.837306f, 0.834549f, 0.831793f, 0.829037f, 0.826281f,
		0.823524f, 0.820768f, 0.818012f, 0.815256f, 0.812504f, 0.80983f,
		0.807155f, 0.804481f, 0.801807f, 0.799133f, 0.796459f, 0.793785f,
		0.791111f, 0.788437f, 0.785763f, 0.783089f, 0.780415f, 0.777741f,
		0.775111f, 0.772517f, 0.769922f, 0.767327f, 0.764733f, 0.762138f,
		0.759544f, 0.756949f, 0.754354f, 0.75176f, 0.749165f, 0.746571f,
		0.743976f, 0.741381f, 0.73885f, 0.736332f, 0.733814f, 0.731296f,
		0.728778f, 0.726261f, 0.723743f, 0.721225f, 0.718707f, 0.716189f,
		0.713671f, 0.711153f, 0.708636f, 0.706118f, 0.703663f, 0.70122f,
		0.698776f, 0.696332f, 0.693889f, 0.691445f, 0.689001f, 0.686558f,
		0.684114f, 0.68167f, 0.679227f, 0.676783f, 0.674339f, 0.671896f,
		0.669499f, 0.667127f, 0.664755f, 0.662383f, 0.660011f, 0.65764f,
		0.655268f, 0.652896f, 0.650524f, 0.648152f, 0.64578f, 0.643408f,
		0.641036f, 0.638664f, 0.636308f, 0.634005f, 0.631703f, 0.6294f,
		0.627098f, 0.624795f, 0.622493f, 0.620191f, 0.617888f, 0.615586f,
		0.613283f, 0.610981f, 0.608679f, 0.606376f, 0.604074f, 0.601808f,
		0.599573f, 0.597337f, 0.595102f, 0.592867f, 0.590632f, 0.588397f,
		0.586162f, 0.583927f, 0.581692f, 0.579456f, 0.577221f, 0.574986f,
		0.572751f, 0.570516f, 0.568322f, 0.566152f, 0.563982f, 0.561812f,
		0.559642f, 0.557472f, 0.555302f, 0.553132f, 0.550962f, 0.548792f,
		0.546622f, 0.544452f, 0.542283f, 0.540113f, 0.537943f, 0.535804f,
		0.533697f, 0.53159f, 0.529483f, 0.527377f, 0.52527f, 0.523163f,
		0.521056f, 0.518949f, 0.516843f, 0.514736f, 0.512629f, 0.510522f,
		0.508416f, 0.506309f, 0.504209f, 0.502163f, 0.500118f, 0.498072f,
		0.496027f, 0.493981f, 0.491936f, 0.48989f, 0.487845f, 0.485799f,
		0.483754f, 0.481708f, 0.479663f, 0.477618f, 0.475572f, 0.473527f,
		0.47151f, 0.469524f, 0.467538f, 0.465552f, 0.463566f, 0.46158f,
		0.459594f, 0.457608f, 0.455622f, 0.453636f, 0.45165f, 0.449664f,
		0.447678f, 0.445692f, 0.443706f, 0.44172f, 0.439771f, 0.437843f,
		0.435915f, 0.433986f, 0.432058f, 0.43013f, 0.428201f, 0.426273f,
		0.424345f, 0.422417f, 0.420488f, 0.41856f, 0.416632f, 0.414703f,
		0.412775f, 0.410847f, 0.40895f, 0.407077f, 0.405205f, 0.403333f,
		0.401461f, 0.399588f, 0.397716f, 0.395844f, 0.393972f, 0.392099f,
		0.390227f, 0.388355f, 0.386483f, 0.384611f, 0.382738f, 0.380866f,
		0.379007f, 0.377189f, 0.375371f, 0.373553f, 0.371735f, 0.369918f,
		0.3681f, 0.366282f, 0.364464f, 0.362647f, 0.360829f, 0.359011f,
		0.357193f, 0.355375f, 0.353558f, 0.35174f, 0.349922f, 0.34814f,
		0.346375f, 0.34461f, 0.342846f, 0.341081f, 0.339316f, 0.337551f,
		0.335786f, 0.334021f, 0.332256f, 0.330492f, 0.328727f, 0.326962f,
		0.325197f, 0.323432f, 0.321667f, 0.319903f, 0.318183f, 0.31647f,
		0.314756f, 0.313043f, 0.31133f, 0.309616f, 0.307903f, 0.30619f,
		0.304476f, 0.302763f, 0.301049f, 0.299336f, 0.297623f, 0.295909f,
		0.294196f, 0.292483f, 0.290769f, 0.289099f, 0.287435f, 0.285772f,
		0.284109f, 0.282445f, 0.280782f, 0.279119f, 0.277456f, 0.275792f,
		0.274129f, 0.272466f, 0.270802f, 0.269139f, 0.267476f, 0.265812f,
		0.264149f, 0.262486f, 0.260851f, 0.259237f, 0.257622f, 0.256007f,
		0.254393f, 0.252778f, 0.251164f, 0.249549f, 0.247935f, 0.24632f,
		0.244705f, 0.243091f, 0.241476f, 0.239862f, 0.238247f, 0.236632f,
		0.235018f, 0.233408f, 0.23184f, 0.230273f, 0.228706f, 0.227139f,
		0.225572f, 0.224005f, 0.222437f, 0.22087f, 0.219303f, 0.217736f,
		0.216169f, 0.214602f, 0.213034f, 0.211467f, 0.2099f, 0.208333f,
		0.206766f, 0.205215f, 0.203694f, 0.202173f, 0.200652f, 0.199131f,
		0.19761f, 0.196089f, 0.194568f, 0.193047f, 0.191526f, 0.190005f,
		0.188484f, 0.186963f, 0.185442f, 0.183921f, 0.1824f, 0.180879f,
		0.179358f, 0.177855f, 0.176379f, 0.174903f, 0.173427f, 0.171951f,
		0.170475f, 0.168999f, 0.167523f, 0.166047f, 0.164571f, 0.163095f,
		0.161619f, 0.160143f, 0.158667f, 0.157191f, 0.155715f, 0.154239f,
		0.152763f, 0.151295f, 0.149863f, 0.14843f, 0.146998f, 0.145566f,
		0.144134f, 0.142702f, 0.14127f, 0.139837f, 0.138405f, 0.136973f,
		0.135541f, 0.134109f, 0.132677f, 0.131244f, 0.129812f, 0.12838f,
		0.126948f, 0.125516f, 0.124115f, 0.122726f, 0.121336f, 0.119947f,
		0.118557f, 0.117168f, 0.115779f, 0.114389f, 0.113f, 0.11161f,
		0.110221f, 0.108832f, 0.107442f, 0.106053f, 0.104663f, 0.103274f,
		0.101884f, 0.100495f, 0.0991081f, 0.0977603f, 0.0964125f, 0.0950648f,
		0.093717f, 0.0923693f, 0.0910215f, 0.0896738f, 0.088326f, 0.0869783f,
		0.0856305f, 0.0842827f, 0.082935f, 0.0815872f, 0.0802395f, 0.0788917f,
		0.077544f, 0.0761962f, 0.0748484f, 0.0735068f, 0.0721996f, 0.0708925f,
		0.0695854f, 0.0682783f, 0.0669712f, 0.0656641f, 0.0643569f, 0.0630499f,
		0.0617427f, 0.0604357f, 0.0591285f, 0.0578214f, 0.0565143f, 0.0552072f,
		0.0539001f, 0.0525929f, 0.0512858f, 0.0499787f, 0.0486717f, 0.0474042f,
		0.0461368f, 0.0448693f, 0.0436018f, 0.0423344f, 0.0410669f, 0.0397995f,
		0.038532f, 0.0372645f, 0.0359971f, 0.0347296f, 0.0334621f, 0.0321947f,
		0.0309272f, 0.0296597f, 0.0283923f, 0.0271248f, 0.0258574f, 0.0245899f,
		0.0233464f, 0.0221176f, 0.0208889f, 0.0196601f, 0.0184314f, 0.0172026f,
		0.0159739f, 0.0147451f, 0.0135163f, 0.0122876f, 0.0110588f, 0.00983006f,
		0.00860131f, 0.00737256f, 0.00614381f, 0.00491506f, 0.00368625f, 0.0024575f,
		0.00122875f, 0.f
	};
};

template <int NV>
using cable_table_t = wrap::data<control::cable_table<parameter::plain<math::clip<NV>, 0>>, 
                                 data::embedded::table<cable_table_t_data>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<2, filters::allpass<NV>>, 
                                   cable_table_t<NV>, 
                                   math::clip<NV>, 
                                   core::gain<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain1_t<NV>>, 
                                    chain3_t<NV>, 
                                    chain8_t<NV>, 
                                    chain11_t<NV>, 
                                    chain10_t<NV>>;

template <int NV>
using fix8_block_t = container::chain<parameter::empty, 
                                      wrap::fix<2, branch1_t<NV>>>;

template <int NV>
using dynamic_blocksize_t_ = container::chain<parameter::empty, 
                                              wrap::fix<2, fix8_block_t<NV>>>;

template <int NV>
using dynamic_blocksize_t = wrap::dynamic_blocksize<dynamic_blocksize_t_<NV>>;

namespace dtest_t_parameters
{
// Parameter list for dtest_impl::dtest_t ----------------------------------------------------------

DECLARE_PARAMETER_RANGE_SKEW(freq_InputRange, 
                             20., 
                             20000., 
                             0.229905);
DECLARE_PARAMETER_RANGE_SKEW(freq_1Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using freq_1 = parameter::from0To1<filters::allpass<NV>, 
                                   0, 
                                   freq_1Range>;

template <int NV>
using freq = parameter::chain<freq_InputRange, 
                              parameter::plain<dtest_impl::converter_t<NV>, 0>, 
                              freq_1<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(FbRes_3Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using FbRes_3 = parameter::from0To1<filters::allpass<NV>, 
                                    1, 
                                    FbRes_3Range>;

template <int NV>
using FbRes = parameter::chain<ranges::Identity, 
                               parameter::plain<routing::receive<stereo_cable>, 0>, 
                               parameter::plain<routing::receive<stereo_cable>, 0>, 
                               parameter::plain<project::comb<NV>, 0>, 
                               FbRes_3<NV>, 
                               parameter::plain<project::comb<NV>, 0>>;

template <int NV>
using InputCut = parameter::chain<ranges::Identity, 
                                  parameter::plain<filters::svf<NV>, 0>, 
                                  parameter::plain<filters::svf<NV>, 0>, 
                                  parameter::plain<filters::svf<NV>, 0>>;

template <int NV>
using InputQ_0 = parameter::from0To1<filters::svf<NV>, 
                                     1, 
                                     FbRes_3Range>;

template <int NV> using InputQ_1 = InputQ_0<NV>;

template <int NV> using InputQ_2 = InputQ_0<NV>;

template <int NV>
using InputQ = parameter::chain<ranges::Identity, 
                                InputQ_0<NV>, 
                                InputQ_1<NV>, 
                                InputQ_2<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Delmode_InputRange, 
                             1., 
                             5., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Delmode_0Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using Delmode_0 = parameter::from0To1<dtest_impl::branch1_t<NV>, 
                                      0, 
                                      Delmode_0Range>;

template <int NV>
using Delmode = parameter::chain<Delmode_InputRange, Delmode_0<NV>>;

template <int NV>
using DelMod_0 = parameter::from0To1<filters::one_pole<NV>, 
                                     0, 
                                     freq_1Range>;

DECLARE_PARAMETER_RANGE_SKEW(DelMod_1Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using DelMod_1 = parameter::from0To1<fx::phase_delay<NV>, 
                                     0, 
                                     DelMod_1Range>;

template <int NV>
using DelMod_2 = parameter::from0To1<filters::svf_eq<NV>, 
                                     0, 
                                     freq_1Range>;

template <int NV> using DelMod_3 = DelMod_2<NV>;

DECLARE_PARAMETER_RANGE_STEP(DelMod_5Range, 
                             0., 
                             12., 
                             0.1);

template <int NV>
using DelMod_5 = parameter::from0To1<core::gain<NV>, 
                                     0, 
                                     DelMod_5Range>;

template <int NV>
using DelMod = parameter::chain<ranges::Identity, 
                                DelMod_0<NV>, 
                                DelMod_1<NV>, 
                                DelMod_2<NV>, 
                                DelMod_3<NV>, 
                                parameter::plain<dtest_impl::cable_table_t<NV>, 0>, 
                                DelMod_5<NV>>;

DECLARE_PARAMETER_RANGE_STEP(block_InputRange, 
                             1., 
                             8., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(block_0Range, 
                             0., 
                             7., 
                             1.);

template <int NV>
using block_0 = parameter::from0To1<dtest_impl::dynamic_blocksize_t<NV>, 
                                    0, 
                                    block_0Range>;

template <int NV>
using block = parameter::chain<block_InputRange, block_0<NV>>;

template <int NV>
using InputMode = parameter::plain<dtest_impl::xfader_t<NV>, 
                                   0>;
template <int NV>
using SH = parameter::plain<fx::sampleandhold<NV>, 0>;
template <int NV>
using InputThresh = parameter::plain<dtest_impl::comp_t<NV>, 0>;
template <int NV>
using InputAtk = parameter::plain<dtest_impl::comp_t<NV>, 1>;
template <int NV>
using InputRel = parameter::plain<dtest_impl::comp_t<NV>, 2>;
template <int NV>
using Trg = parameter::plain<dtest_impl::xfader1_t<NV>, 
                             0>;
template <int NV>
using dtest_t_plist = parameter::list<freq<NV>, 
                                      FbRes<NV>, 
                                      InputCut<NV>, 
                                      InputQ<NV>, 
                                      InputMode<NV>, 
                                      Delmode<NV>, 
                                      SH<NV>, 
                                      DelMod<NV>, 
                                      InputThresh<NV>, 
                                      InputAtk<NV>, 
                                      InputRel<NV>, 
                                      Trg<NV>, 
                                      block<NV>>;
}

template <int NV>
using dtest_t_ = container::chain<dtest_t_parameters::dtest_t_plist<NV>, 
                                  wrap::fix<2, xfader_t<NV>>, 
                                  split_t<NV>, 
                                  comp_t<NV>, 
                                  fx::sampleandhold<NV>, 
                                  chain7_t<NV>, 
                                  converter_t<NV>, 
                                  dynamic_blocksize_t<NV>, 
                                  filters::one_pole<NV>, 
                                  wrap::no_process<math::tanh<NV>>, 
                                  core::gain<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public dtest_impl::dtest_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(dtest);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(212)
		{
			0x005B, 0x0000, 0x6600, 0x6572, 0x0071, 0x0000, 0x41A0, 0x4000, 
            0x469C, 0xC000, 0x441B, 0x6C1A, 0x3E6B, 0xCCCD, 0x3DCC, 0x015B, 
            0x0000, 0x4600, 0x5262, 0x7365, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0002, 
            0x0000, 0x6E49, 0x7570, 0x4374, 0x7475, 0x0000, 0xA000, 0x0041, 
            0x9C40, 0x0046, 0x9C40, 0x1A46, 0x6B6C, 0x003E, 0x0000, 0x5B00, 
            0x0003, 0x0000, 0x6E49, 0x7570, 0x5174, 0x0000, 0x0000, 0x0000, 
            0x8000, 0xD13F, 0x1FA2, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0004, 0x0000, 0x6E49, 0x7570, 0x4D74, 0x646F, 0x0065, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x055B, 0x0000, 0x4400, 0x6C65, 0x6F6D, 0x6564, 0x0000, 
            0x8000, 0x003F, 0xA000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x0006, 0x0000, 0x4853, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x0043, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0007, 0x0000, 0x6544, 0x4D6C, 0x646F, 0x0000, 0x0000, 0x0000, 
            0x8000, 0xC83F, 0x3AC2, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0008, 0x0000, 0x6E49, 0x7570, 0x5474, 0x7268, 0x7365, 0x0068, 
            0x0000, 0xC2C8, 0x0000, 0x0000, 0x3332, 0xC11B, 0x833E, 0x40AD, 
            0xCCCD, 0x3DCC, 0x095B, 0x0000, 0x4900, 0x706E, 0x7475, 0x7441, 
            0x006B, 0x0000, 0x0000, 0x0000, 0x437A, 0x3333, 0x422F, 0x81A3, 
            0x3EDC, 0xCCCD, 0x3DCC, 0x0A5B, 0x0000, 0x4900, 0x706E, 0x7475, 
            0x6552, 0x006C, 0x0000, 0x0000, 0x0000, 0x437A, 0xCCCD, 0x421E, 
            0x81A3, 0x3EDC, 0xCCCD, 0x3DCC, 0x0B5B, 0x0000, 0x5400, 0x6772, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x000C, 0x0000, 0x6C62, 0x636F, 0x006B, 
            0x0000, 0x3F80, 0x0000, 0x4100, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& xfader = this->getT(0);                                      // dtest_impl::xfader_t<NV>
		auto& split = this->getT(1);                                       // dtest_impl::split_t<NV>
		auto& chain4 = this->getT(1).getT(0);                              // dtest_impl::chain4_t<NV>
		auto& svf = this->getT(1).getT(0).getT(0);                         // filters::svf<NV>
		auto& gain = this->getT(1).getT(0).getT(1);                        // core::gain<NV>
		auto& chain6 = this->getT(1).getT(1);                              // dtest_impl::chain6_t<NV>
		auto& svf2 = this->getT(1).getT(1).getT(0);                        // filters::svf<NV>
		auto& gain2 = this->getT(1).getT(1).getT(1);                       // core::gain<NV>
		auto& chain5 = this->getT(1).getT(2);                              // dtest_impl::chain5_t<NV>
		auto& svf1 = this->getT(1).getT(2).getT(0);                        // filters::svf<NV>
		auto& gain1 = this->getT(1).getT(2).getT(1);                       // core::gain<NV>
		auto& comp = this->getT(2);                                        // dtest_impl::comp_t<NV>
		auto& sampleandhold = this->getT(3);                               // fx::sampleandhold<NV>
		auto& chain7 = this->getT(4);                                      // dtest_impl::chain7_t<NV>
		auto& xfader1 = this->getT(4).getT(0);                             // dtest_impl::xfader1_t<NV>
		auto& split1 = this->getT(4).getT(1);                              // dtest_impl::split1_t<NV>
		auto& chain = this->getT(4).getT(1).getT(0);                       // dtest_impl::chain_t<NV>
		auto& gain3 = this->getT(4).getT(1).getT(0).getT(0);               // core::gain<NV>
		auto& chain2 = this->getT(4).getT(1).getT(1);                      // dtest_impl::chain2_t<NV>
		auto& clear = this->getT(4).getT(1).getT(1).getT(0);               // wrap::no_process<math::clear<NV>>
		auto& add = this->getT(4).getT(1).getT(1).getT(1);                 // math::add<NV>
		auto& rect = this->getT(4).getT(1).getT(1).getT(2);                // wrap::no_process<math::rect<NV>>
		auto& peak = this->getT(4).getT(1).getT(1).getT(3);                // dtest_impl::peak_t
		auto& gain4 = this->getT(4).getT(1).getT(1).getT(4);               // core::gain<NV>
		auto& converter = this->getT(5);                                   // dtest_impl::converter_t<NV>
		auto& dynamic_blocksize = this->getT(6);                           // dtest_impl::dynamic_blocksize_t<NV>
		auto& fix8_block = this->getT(6).getT(0);                          // dtest_impl::fix8_block_t<NV>
		auto& branch1 = this->getT(6).getT(0).getT(0);                     // dtest_impl::branch1_t<NV>
		auto& chain1 = this->getT(6).getT(0).getT(0).getT(0);              // dtest_impl::chain1_t<NV>
		auto& receive = this->getT(6).getT(0).getT(0).getT(0).getT(0);     // routing::receive<stereo_cable>
		auto& fix_delay = this->getT(6).getT(0).getT(0).getT(0).getT(1);   // core::fix_delay
		auto& one_pole1 = this->getT(6).getT(0).getT(0).getT(0).getT(2);   // filters::one_pole<NV>
		auto& send = this->getT(6).getT(0).getT(0).getT(0).getT(3);        // routing::send<stereo_cable>
		auto& chain3 = this->getT(6).getT(0).getT(0).getT(1);              // dtest_impl::chain3_t<NV>
		auto& receive1 = this->getT(6).getT(0).getT(0).getT(1).getT(0);    // routing::receive<stereo_cable>
		auto& jdelay = this->getT(6).getT(0).getT(0).getT(1).getT(1);      // jdsp::jdelay<NV>
		auto& phase_delay = this->getT(6).getT(0).getT(0).getT(1).getT(2); // fx::phase_delay<NV>
		auto& tanh1 = this->getT(6).getT(0).getT(0).getT(1).getT(3);       // math::tanh<NV>
		auto& send1 = this->getT(6).getT(0).getT(0).getT(1).getT(4);       // routing::send<stereo_cable>
		auto& chain8 = this->getT(6).getT(0).getT(0).getT(2);              // dtest_impl::chain8_t<NV>
		auto& faust = this->getT(6).getT(0).getT(0).getT(2).getT(0);       // project::comb<NV>
		auto& svf_eq = this->getT(6).getT(0).getT(0).getT(2).getT(1);      // filters::svf_eq<NV>
		auto& chain11 = this->getT(6).getT(0).getT(0).getT(3);             // dtest_impl::chain11_t<NV>
		auto& faust1 = this->getT(6).getT(0).getT(0).getT(3).getT(0);      // project::comb<NV>
		auto& svf_eq1 = this->getT(6).getT(0).getT(0).getT(3).getT(1);     // filters::svf_eq<NV>
		auto& chain10 = this->getT(6).getT(0).getT(0).getT(4);             // dtest_impl::chain10_t<NV>
		auto& allpass = this->getT(6).getT(0).getT(0).getT(4).getT(0);     // filters::allpass<NV>
		auto& cable_table = this->getT(6).getT(0).getT(0).getT(4).getT(1); // dtest_impl::cable_table_t<NV>
		auto& clip = this->getT(6).getT(0).getT(0).getT(4).getT(2);        // math::clip<NV>
		auto& gain5 = this->getT(6).getT(0).getT(0).getT(4).getT(3);       // core::gain<NV>
		auto& one_pole = this->getT(7);                                    // filters::one_pole<NV>
		auto& tanh = this->getT(8);                                        // wrap::no_process<math::tanh<NV>>
		auto& gain6 = this->getT(9);                                       // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& freq_p = this->getParameterT(0);
		freq_p.connectT(0, converter); // freq -> converter::Value
		freq_p.connectT(1, allpass);   // freq -> allpass::Frequency
		
		auto& FbRes_p = this->getParameterT(1);
		FbRes_p.connectT(0, receive);  // FbRes -> receive::Feedback
		FbRes_p.connectT(1, receive1); // FbRes -> receive1::Feedback
		FbRes_p.connectT(2, faust);    // FbRes -> faust::aN
		FbRes_p.connectT(3, allpass);  // FbRes -> allpass::Q
		FbRes_p.connectT(4, faust1);   // FbRes -> faust1::aN
		
		auto& InputCut_p = this->getParameterT(2);
		InputCut_p.connectT(0, svf1); // InputCut -> svf1::Frequency
		InputCut_p.connectT(1, svf2); // InputCut -> svf2::Frequency
		InputCut_p.connectT(2, svf);  // InputCut -> svf::Frequency
		
		auto& InputQ_p = this->getParameterT(3);
		InputQ_p.connectT(0, svf);  // InputQ -> svf::Q
		InputQ_p.connectT(1, svf2); // InputQ -> svf2::Q
		InputQ_p.connectT(2, svf1); // InputQ -> svf1::Q
		
		this->getParameterT(4).connectT(0, xfader); // InputMode -> xfader::Value
		
		this->getParameterT(5).connectT(0, branch1); // Delmode -> branch1::Index
		
		this->getParameterT(6).connectT(0, sampleandhold); // SH -> sampleandhold::Counter
		
		auto& DelMod_p = this->getParameterT(7);
		DelMod_p.connectT(0, one_pole1);   // DelMod -> one_pole1::Frequency
		DelMod_p.connectT(1, phase_delay); // DelMod -> phase_delay::Frequency
		DelMod_p.connectT(2, svf_eq);      // DelMod -> svf_eq::Frequency
		DelMod_p.connectT(3, svf_eq1);     // DelMod -> svf_eq1::Frequency
		DelMod_p.connectT(4, cable_table); // DelMod -> cable_table::Value
		DelMod_p.connectT(5, gain5);       // DelMod -> gain5::Gain
		
		this->getParameterT(8).connectT(0, comp); // InputThresh -> comp::Threshhold
		
		this->getParameterT(9).connectT(0, comp); // InputAtk -> comp::Attack
		
		this->getParameterT(10).connectT(0, comp); // InputRel -> comp::Release
		
		this->getParameterT(11).connectT(0, xfader1); // Trg -> xfader1::Value
		
		this->getParameterT(12).connectT(0, dynamic_blocksize); // block -> dynamic_blocksize::BlockSize
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);  // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain2); // xfader -> gain2::Gain
		xfader_p.getParameterT(2).connectT(0, gain1); // xfader -> gain1::Gain
		comp.getParameter().connectT(0, add);         // comp -> add::Value
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain3);                      // xfader1 -> gain3::Gain
		xfader1_p.getParameterT(1).connectT(0, gain4);                      // xfader1 -> gain4::Gain
		converter.getWrappedObject().getParameter().connectT(0, fix_delay); // converter -> fix_delay::DelayTime
		converter.getWrappedObject().getParameter().connectT(1, jdelay);    // converter -> jdelay::DelayTime
		converter.getWrappedObject().getParameter().connectT(2, faust);     // converter -> faust::del
		converter.getWrappedObject().getParameter().connectT(3, faust1);    // converter -> faust1::del
		cable_table.getWrappedObject().getParameter().connectT(0, clip);    // cable_table -> clip::Value
		
		// Send Connections ------------------------------------------------------------------------
		
		send.connect(receive);
		send1.connect(receive1);
		
		// Default Values --------------------------------------------------------------------------
		
		; // xfader::Value is automated
		
		;                           // svf::Frequency is automated
		;                           // svf::Q is automated
		svf.setParameterT(2, 0.);   // filters::svf::Gain
		svf.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf.setParameterT(4, 0.);   // filters::svf::Mode
		svf.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                            // svf2::Frequency is automated
		;                            // svf2::Q is automated
		svf2.setParameterT(2, 0.);   // filters::svf::Gain
		svf2.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf2.setParameterT(4, 1.);   // filters::svf::Mode
		svf2.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // gain2::Gain is automated
		gain2.setParameterT(1, 20.); // core::gain::Smoothing
		gain2.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                            // svf1::Frequency is automated
		;                            // svf1::Q is automated
		svf1.setParameterT(2, 0.);   // filters::svf::Gain
		svf1.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf1.setParameterT(4, 2.);   // filters::svf::Mode
		svf1.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                           // comp::Threshhold is automated
		;                           // comp::Attack is automated
		;                           // comp::Release is automated
		comp.setParameterT(3, 2.2); // dynamics::comp::Ratio
		comp.setParameterT(4, 0.);  // dynamics::comp::Sidechain
		
		; // sampleandhold::Counter is automated
		
		; // xfader1::Value is automated
		
		;                            // gain3::Gain is automated
		gain3.setParameterT(1, 20.); // core::gain::Smoothing
		gain3.setParameterT(2, 0.);  // core::gain::ResetValue
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // add::Value is automated
		
		rect.setParameterT(0, 0.); // math::rect::Value
		
		;                            // gain4::Gain is automated
		gain4.setParameterT(1, 43.); // core::gain::Smoothing
		gain4.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // converter::Value is automated
		
		; // dynamic_blocksize::BlockSize is automated
		
		; // branch1::Index is automated
		
		; // receive::Feedback is automated
		
		;                                  // fix_delay::DelayTime is automated
		fix_delay.setParameterT(1, 1024.); // core::fix_delay::FadeTime
		
		;                                 // one_pole1::Frequency is automated
		one_pole1.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole1.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole1.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole1.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole1.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // receive1::Feedback is automated
		
		jdelay.setParameterT(0, 1000.); // jdsp::jdelay::Limit
		;                               // jdelay::DelayTime is automated
		
		; // phase_delay::Frequency is automated
		
		tanh1.setParameterT(0, 1.); // math::tanh::Value
		
		; // faust::aN is automated
		; // faust::del is automated
		
		;                              // svf_eq::Frequency is automated
		svf_eq.setParameterT(1, 0.3);  // filters::svf_eq::Q
		svf_eq.setParameterT(2, 0.);   // filters::svf_eq::Gain
		svf_eq.setParameterT(3, 0.01); // filters::svf_eq::Smoothing
		svf_eq.setParameterT(4, 4.);   // filters::svf_eq::Mode
		svf_eq.setParameterT(5, 1.);   // filters::svf_eq::Enabled
		
		; // faust1::aN is automated
		; // faust1::del is automated
		
		;                                  // svf_eq1::Frequency is automated
		svf_eq1.setParameterT(1, 5.66258); // filters::svf_eq::Q
		svf_eq1.setParameterT(2, 0.);      // filters::svf_eq::Gain
		svf_eq1.setParameterT(3, 0.01);    // filters::svf_eq::Smoothing
		svf_eq1.setParameterT(4, 4.);      // filters::svf_eq::Mode
		svf_eq1.setParameterT(5, 1.);      // filters::svf_eq::Enabled
		
		;                               // allpass::Frequency is automated
		;                               // allpass::Q is automated
		allpass.setParameterT(2, 0.);   // filters::allpass::Gain
		allpass.setParameterT(3, 0.01); // filters::allpass::Smoothing
		allpass.setParameterT(4, 0.);   // filters::allpass::Mode
		allpass.setParameterT(5, 1.);   // filters::allpass::Enabled
		
		; // cable_table::Value is automated
		
		; // clip::Value is automated
		
		;                             // gain5::Gain is automated
		gain5.setParameterT(1, 20.);  // core::gain::Smoothing
		gain5.setParameterT(2, -38.); // core::gain::ResetValue
		
		one_pole.setParameterT(0, 50.);  // filters::one_pole::Frequency
		one_pole.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		tanh.setParameterT(0, 1.); // math::tanh::Value
		
		gain6.setParameterT(0, -7.2); // core::gain::Gain
		gain6.setParameterT(1, 20.);  // core::gain::Smoothing
		gain6.setParameterT(2, 0.);   // core::gain::ResetValue
		
		this->setParameterT(0, 623.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 20000.);
		this->setParameterT(3, 0.623578);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 0.729535);
		this->setParameterT(8, -9.7);
		this->setParameterT(9, 43.8);
		this->setParameterT(10, 39.7);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 1.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(2).setExternalData(b, index);                                 // dtest_impl::comp_t<NV>
		this->getT(4).getT(1).getT(1).getT(3).setExternalData(b, index);         // dtest_impl::peak_t
		this->getT(6).getT(0).getT(0).getT(4).getT(1).setExternalData(b, index); // dtest_impl::cable_table_t<NV>
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
using dtest = wrap::node<dtest_impl::instance<NV>>;
}


