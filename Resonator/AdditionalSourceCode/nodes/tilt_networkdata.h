namespace project
{

struct tilt_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "tilt";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "202.nT6K8C1U.TfA.HrBi.BPMrM.eYBo9zViS0QtJwNV610Mb3JHsLOu2nDDzzsjObtUH1zgEV2Vzv+4UasI2LowYgL3NLYhqfvbxn.hfGiVuph2lbfIcK3HzrS9.ZfyFn1jqqPG3UTlSEOIbWKWXoUcsrcOF5.7Kcl7rulkL..dU4sP7pjJoPBf28Z7pIdyzZT.3W.w.eD6aQqqS.BLBhP8A.Xe01QWHHFh5RcAHbqdIegj4oVqoEWn.GClAtme2d.n4hivh4JAmCieT.";
	}
};
}

