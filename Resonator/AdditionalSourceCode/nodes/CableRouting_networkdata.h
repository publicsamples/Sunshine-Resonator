namespace project
{

struct CableRouting_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "CableRouting";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "2366.nT6K8CVKJWZR.nSS.1fJ.CMtMb8Qe0u3qfQi8X7jD+igPHuknlpSYlYlYhbQQQg4yxYQow9wtT6NtCf0..K.cDAAEcg6BfYBvrp6ualpqJBI6LUQSabfiijKKITnGNLTKLOX.giZEQQghasbTThvzSCRNK3f1nTHkHLbRSd.g0DNp2FH2Ell7vfIphOdljdYhjx3AGEu5xs7ycE.GkzlHnnJjHsTvCZC2jL.41HBRCqArvkArLAiSZiUDGn7n.E0KHVQjPkSOPYzr..DJMN3nPMRuo2EmjKiNhrnw6haBJ15AGEkmFMtLe7.ElGmkIRjdXdbSXhlrJfixxjKiOjhll3tX4ndThlfiiRBaEwQgI5Qiz6BJMf4YZSTEdPa3pXI.GkEQvAGEGRQcL8lP3ppYlIFgwTYV1pTIZZSERuInmKl1j4.N3n9uad5alY1Zdin9LLR5sF1+yPjycUkpiHJXdvvB.Nj5lc2ZH.PHXD2auc+ytcj4lgQrKDtgQ.Qe2wj8byaLOybOfipiGGPldZpTgBRQSNLQZdUXU.GbTsx8+skZ4vDzFWkmEq1cgBEG3XCd56bhZhLhHyR30B9.JyyDzFLVR.4AIPQRTfp.H4dPSZvBBGMRuJU17fObPYz7XgaxYgGOnLWhpvcIyCNRdRQSVSvg6kwiGELQXCOZj4MogZW8FIuMaYKqMCkHyFaMQYj61912s2dl0c4cyUYUUE2jSMU1h7yvHXbamp7XYeW8uou+tpr2nh5+Lkot2Zc+Oyq21UWKZdRVrPlKMVYrVSUu8dYMq0lW2UM2tSEWlQks6xzV+u+z3rjgSiEEL26V+LYlYGa00TyNyLcVwDydUVxRV0E6ohpz6oxy.xb2cUUatCS+Oyl6X9cyRGhsaNyPBbLw8.Ju2EXiasu0TUUjQ9aL+6tA7qVCiX4P9Gemhbwmw1+1iGLjn81lnxMjcdQVCVJX.dqbSYaigrpw+q+8x906tabBlDgwDb1rmSz4t99YC+UkXYJ6R0nWhXoYjvFWjDHgHwTWuUtwZKEXDrbB7+tkM2+1l6tbKSk0PTkzVF3wEjUxXb1rlxXrknl.Njl1UMQRCHK1p0X5H532M9LIolmTy92KyP86DeWQ8wlg.FnTbfwAswJhl+23GXFFAhQXHDomN55mut5xcmatL23haff5hpT5lrFAD.gDf.BBHBI..hBJcVFsygX.wPxP.F.D.CDC.BBFAND.P....B.B...C.CDDiBIJ1Gjx5MP9e.KRpZX8Rlm6U..MXxtrOcANh2j1eQk3hLlE.JkMfCn55+kXZN4ragXB45.IU2DCudYCgEoepmAD.JhL1IVIvv01AwHx2klkgAUWQzeHZ40DRLr1oPYEJrGQ14jcIo.fUI+kzIJUjDhPaswSeAzhX53QBjeMMPeQNkyyyWgfOnE7UYfJbGPD8+KxSFnCp.LoheZEDstCuZc9QrJ22XeLe42fKMxocsNLY5OQ9FD+Ch2NdmeF3lowExNAStBD4C7YOwa3ogCjfDOMvU321wIHlxKjCDQIagWb9fifRlv2WFFcUR4CZM9Y14RO23rpVM2pmKmMN6MsBjEmHoosfFq0ZeyneGkdTnY7+I37pQ7jBL8wljI.BekriezaCjHTLObfqjo60mPyZ7LVlMcgPlKBZiTGO3b8ifAbsZr9HTl5kstXnSSA1Ys8wNM.TlqAbUE0jsVmCZo9kzaD2.ywxLXev1Spykk4e99VHDGmA361XBZjwnVymVNVU+Hj5GThHjKQ1YqIRd.PDr5qomfvVx0NIOwRQu3ICCmemTKAIkbNF2+S58fUuIdm+45jQL3oOmvSnvxmRbSNwBaeZw0bBDV8IFGbvEJkb+iYjP4isSij07dUa6fdPICnTPY2J0j913ESdxYm3uiOTQYcdx3vmN4fO83EcBGdvob+7S8wmbdzW3H6JT3DC9rMJkzXzdhNX9dPhBAEkipQ3YFuZxOicldN7CJ.7dmsGHJKXfS+SfBOKeJeCT7rwS6uBKO1mOCZF5fRM8Hrd+tAkeKoA2OGhwwzpAWqY0gHzSxFUXtxyDu+TI+7oGu3TNO9oD27DOe340UMHZnCi79W7VXqtgHKMPi4H4CBJytonQ12GutVizL74DNS5sNMCS3d5ifJuX7PcGCc57I9DFrvov27SrvFmle05KDm2Az.bkdBzEBjChTvHq+vonfGrEJBIVshlfuMdACRmDnhIlWbNb8BfkHpOWRlSyb2O0tGkQF5oiSfBkE7T5F4JxicNOnpnZH0ziW2c6lkwz3ExuKqg7iwHxnB9oo5+Qcyc3S9WIiRJawyPj4efpKekNUZB4juXXmHByDr9xIudE73XdeKfrZGRWmelIBlEkAe3K.gLhP3Ccr4FowwuF8jgOmbNLEBgS7jLyw9IcPZOCPIlXK.uIFl6DStf3h2ATb7rNUP18AiBUDFp3LAoxAlHJJRsADxzXNg4CyW8T6NP7CdMLYfTGvoYoRaBD7ljoZeeRMEfO9Q97luIILLxgqjCwU2KNT5.9MTqULwNScBYuMTcexFaJm0PU+Rn3vSgSZHrS5nPw54bFxO9WHa.ZpvgzhVxWGECCUbxmJamDZDchHcDpVoYcv+DTWvx5ZonKTkDIcR5pGDLjDyIlBfmLTlLvAqImrHo8VZllhymPyhrJFzlnLmuwNNqxn6XZTQX848qq2HuRvIcWolsNz0uDEz5c2yPKCvAh+aIUiNEI00K0aG8xO9Ern.vwz08H0GQTu0a7QgvbmG9Xa5SWyB1BAwX4kb8SqY+fJKXfU5WSspbs6784YUz9gqbMGxskzuwyf.5ObxirDeyRN+RiV8RLUiOllNDSY9E0CXhF.NwHnjTm9joO4MoYk+BFXYJzmxXwswdc1qN0guHfEZD+pSdo386Y1kzvy4fMxckwk7VNVVjtqP9LY3HhnhcODnueI04M+oi0WkRK.D9yobDTl08ASOZuEcRGdOpSE52Nk+VosVIATVqFtB8tfhPT2WDkfVbCOb+02thdW2BYOuVZQSqnKysJTcD50IEc6JGmDexofYl+2Q6m8b3APA3A6FfCRT8Jk2At90Y2n3N3.d.54uFQGtavsZX.WZpGa6twKKuMNs.w6ZvO9G+1+.UXXAy6KE12NK0ivAK5aOSPxmm615J.+qG.";
	}
};
}

