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
		return "2658.nT6K8CVQ5WrT.nmTT4fJf6rsM76hc5PC+6QeV7M.B76uwoRLxChfxLyLyLEBiwvaSrnx5uOOhztC+CP2.nK.Y3gCLtINT6pgUuRvPDDTjCbeBlG.ypt+tYptpnCYmoJZJyBZZnvxBBkEWff3fgZc4AiHMpkDUkJNqUipxEStJ7bhfCTFkBqDggyaBjFrhnQ4x.4HA0knmIJtKWhpHjmomCSzSiFZT7pK2xO2kDMpWlHnnJn3sPfCpCGJT.xoiHnJrDvBWE3CJWbdcrj.fJtJPQ85gkDIT4zCDFo0CQTR.nQgRO2jyhyyQCLD8AGNKNYnXqFZTUbRRNXBgApKONePghm6xiyzkHJKBzn9XxQiPdQSTbbvpQ4pDkQSihB1RRi5RzizyIAUEt7LkIZCGTGNUrlnQYwE.nQYgWDFlbYDdCS+Oyl6X9cyROx1MmPf01lpphLxei4e20UUyLSTBioxrrMIEowR.NyM1alY1Zdin9LTR5sF1+yPjSGVUA83.I2FtmFqlt2sF9.5.Jw81a2+raGYtY3jccfa3D8i3JEAZkas88akJmbRd3wCdQSNWhjbarJPqy+aqJUVfiJvouyIpIxHhLSAuRPHPXdlfxfwBBGZXh1+9iD.retNrjIC2TTFKIfhdS3vAdp7XYEgDOGGDEErhzH8bd3QFFDhCDFoGKblbr.DGDFKQU3XASCMT3dQTVQXAGGFPbUtbQ.Cijd5nqe95pK2ct4xbiKtbyV1xLHRbR1KrmxTQpLtycaLTRq0Z3y9V6Y8+dy896l8F1LKQuX6Oua6ae2d6YV2k2MWkUUUbSN0TYKxOCmv3VGO2EbuUDIq9qu+tpr2nh5+Lkot2Zc+Oyq21UWPdvHDGHmEKH9lpd68xZVqMutqZtcmJtLiJa2kos9eWm3wCbVdlrnyl8aKSlY1wVcUyNyLcVwDydUVxRV0E6ohJUEG2CCGqG1L2cWU0V.BgjKxBDfrjrqI6jUafpqHILmfLi8G8VQVSylK4dO1ZRtMHvpgnDFJYa1h6592pqNmoB+m3w2Yr1FfMVQzON71lnxMjcdQlBVHvA4g4fW+6k8q2c23CvYydhQDfU2HVURs.gkCJDVMjEHEPJANgMwFZrl.+uaYy8us4tK6dZrhHRxXb1rlxXrknd.K7lPJXqhxii0Rx8X+6kYn9chuqFfBkxUwwiILfm6O6++++8W7A28GaZnid+Lm4r+82a6s25usUYHDRtMxkadYFY3DLLnLnJktMIAFA..AD.PP.H+L..hRBoPEoigPPwfw.Pg.Avv.f.fvAPPB...A...D.P...CB.ECCDDnI+z+5M3.HUWMxXXIoh33EoR5NEnARm.amc9oK5OqPbgMC.gjoA9yfwA+ULtw2+FfRMRfljSZYlDXibQ6L+woeylXhm4d2HabwZFPjKa79BGXa8xPlkf7uH4PIqEJaDj5BwKD6r2iI4ZJSEZANbcNBcAK95JCTPAaDv+FexoVuoysznlK2EcFoMBRFACOuQlx9F4TEU+BDibY3KAiD3LG.B2FNVCYbaIX0gZhoEb5I5P7y14FS.pra.RABzMpYgqLzK7.584VGKQXFwTU2RHYEOJREKT+MAwAONXrclGW+MuSvJgMvQyWyTk0XWgrYVQo6xybQ3k9jtiB0EiE4PDxiB9LSkIRIz1MIij1qiZ3kHNvbZfHQdAhaPQKCbvz9JeY10f2Zn.pdnZX7GkYAwKIGr8Mn5tAnIK1a.+S8RP84xSoRDzP3QHw3hHsM08XxwqMcJSfgOtSCG.BGHcaxDucXpx71JOpgDM+KIHjm8XdXbVPeD.f89Rb6gXh4Vva395BzFzEVSJLgLuJFLRMnkMauy2PaAXT2a.G2b3EMrFX1eTWxMIzwSWLWHZ0QmFiWqROwZkMKe7QHT7LtRH4mTMSzzf7LDn4f5HjcJEw36bNg8jSJYXRbJmT9iVJhvW5LNY2eLtwRuF.KdGmvIguW1NvZouNiuINCrexI9L0txASZWmEAgmAIJ7SpMAuIO43e2QBdRfJjjevw3c+oWMlPSLNli4oLl3IkmvII34SSNmSf3SepIOJmlgYhmGTnGeRfaL4LqoIhxf++QSjInGC4NX0lNUJvtrucXQwfBcNCEV.I8IKwWnvGbHMglCbZ71O5o7b9LzCOAx6m3GAEkyOk+DURd7z9777PPlK6TBk.XAtqDQY7WgBTBnXaTME+a30D0LwI5SHCELm5IAudRNK8zp25TDtpSBm5oQXQNs5LbGcCJ3Ofgg.EVPov8KyH8RTFnPcPMW+OvpIdl3j7UTLJT3BmluOJbL0I4qnFxymlmiJyDOoeZb6nboreDnAJ6ShInn.PjnP1hZLdajMZVKDlTypSnHlDAJ773yyN+DHS8jrWOIjkd1ryOExTOIcPoZYvHIg9svxbxyvONDk3WiLKr1yKFlAORnXxFnFi+F6YWisLZYxNMIG8jKKCH8zEAsuX3fBiKbR8IbRBd5zzy4DHt5rvWIUweMOtMPfJwNqa5A0bPdKXFdnTin1fZr96Ha7m9M..FZl57YrC.hV6awT6TQ18IqyPg45OodE0HO+o0YjK9yboefnQHH.JDKM.6CIZI8QuZDCwbDMU+yv6LzioMw+DkKKsmn+QhRJ63YGB3CnBypr5dnPtzWLhSXxL.SZjL+m3jCzoZIB9LjP1CcAg9FkoJ4kTZFWHtCerDOPy0GGexXmKcJLagjXOMxbskGEx3UNJwfC.vCwv.oIYDRJeSTH3JbBgr6CFNJDuhNePRDxSbbXZaRhzf3PW6qMCP7GUW5BPbEd1MAf3xIaAfpNXXdhr9gm.xV99pZT.tUOxmj8MUnzQ5U4lrWjWaxBQ50j6TchclvoveZRAexC6tyYRpGTTRvHbJSBcBQIhohyXx.w+RxFnyweHv9jF9aLWRAIwukzYlVAp+eL5iosttbvIc1RhreJwM4I0vT9zhCPzwAPT4HNnxAlNwB0fRBHansWFRV2hhyMDp7JBo9TS8bonbR9lkychD1caCNeclnf2k5dtDvbg7fyZIsDYp6DmdkYt9pSBoejbtmg9SPR+kOH2YoCw0qK6oKwBATsQrL1OHX.PH.N7PsLHYEiHEXVWKTsZ4J3G3Amhl9EhU50AG4UDRApvHgcYU7BPAkQad45Yt8TpmtU0RsxjUMKDHyy055GgVxAkM6FvYYsI6R4M3CaphR37CYti.M21P7cI.ISvX2sNV3KCen5+o0eD+l2XHlEsaEDvHUA3RQugkKb0TSnGJXT+EgY.X.bhhKQnS2.78j.+uQ2RC5bbxKbneHL6xrnJtvt5RTb4KUNytHcgA4zDGNnIpULz79x3llO8SzT+bj1F8X1PJNeCXLBo8dTidpvf2TvpvTNYM.a7yrLMQXjk2p4Fwpinv5tiG7PR5ksqfHlqklXdXb4pUuKiPubRLrvk5P1mPWXFC78gPvNuqAnMdpdii0GxrG7NSIebyGwPoqpGGo+aCzIDN7VU8I2nsOn5RDqLVowPDnd8F90AbqWiRQpEe1mwreGDp6GMV4SdlheOOV7yUl9OO";
	}
};
}

