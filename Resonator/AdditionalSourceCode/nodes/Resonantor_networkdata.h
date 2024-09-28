namespace project
{

struct Resonantor_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "Resonantor";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "429.nT6K8CFmBzQC.X3EKUB.uhd.G5h6g171bxzK+qtW2m7Sy.1hvZeISK9++EOBIFbTJqSo.A.P.7C.7N8WWxLaPXmTxKRLqeRIqSpTS.uWpRF1XQqRRIM38mnUXdcly7N.dmTpKq+g0hVmxI85cnGf2HSXv6DVTKpekXw8GZjTVm4t1AueEUxGlTTZdc7XjVRF1scP2fWM+zbByqDl2UVkQz7UYvPSfAytr9ZEUDaUkrerWL3Girx5M.QC9ZumHmmycffsnHjEaHQWzcwVycXdCYWG3C5bPsXD9.wZtXCY2HM+Jn3sjzB.AevGGmKB5wiQmi4cA7ZwOQvtSeEDxoB8iKnrj4q+DkhCB4fOQuWzMPhI0kJkhwRyewGXL5t63M2o0c2Ny6dRIWHxj1ArcPGPisgFfHXCJxcdA7BHPADgnkY.8wkANbHLcTxkDQFfewAGixCfXDrLSjZFHJIwUUjaXAdY4O6YgoHfePG0aLDb1iDHtPECxktE5nYQ3EbfT2hkTjnlnFv7AK7.rTxhPEgSO29MfvQ.3lMxePTFSCMqy9CsVSVb2rvH2EnZlGQA";
	}
};
}

