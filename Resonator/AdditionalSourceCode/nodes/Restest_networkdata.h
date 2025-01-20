namespace project
{

struct Restest_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "Restest";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "215.nT6K8Cl+.zlA.HACmHBLMNM..ahTV1cqgLVgzdnypS7orTKUtx1qfBJQr4nB2jzO+m0IVLfA.0OqFPE+GzOhjNTl+.aAIJYTICjjKtJoP7tF4Q1fsVf2Wted0VixMYbWRhCjf6vpQnKJvYkSixlqvk6OJyIjIHb1JgbRqxVYyZNXA2g5jwjs0NYB.bWeZM2cURkTnh6r1hWswaVaVW.G3NiBJ2gXaRzZSDAHPXRUeDmYA5LY5abHfgwmCGn4gwRSnxlW.Y+A7Ac6cAB.vK9hVXAbgHEYZT.";
	}
};
}

