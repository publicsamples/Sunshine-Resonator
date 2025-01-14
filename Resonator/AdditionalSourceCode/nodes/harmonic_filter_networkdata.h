namespace project
{

struct harmonic_filter_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "harmonic_filter";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "3301.nT6K8ClZP1sY.nrX3JwN.DIvAfqIUU0ZP++eotR...M7EvMM4JBEjj7eWHzCmUc2fzL..vhlQrcWhRad9GtOFe8PI8+XZfVfjTfCAfQ.iDfV1Dik1nTsSTl2bEp1Z+aVbKeoza7ms0VDMHxHMl5bylUmO1xgq9MmIOoSLGew14Zmcy0xyT5l5ULSb6MWWKoyNr1lu1tN69qVZV+Z4F+jXRm4tNKRWAeRly02WNo3tyf0xmRs29w5pm0YWKmM27ZFY6M9obayFOcPseosl4l2Lbi89jpi0MHVDgCcl14WdY+ZkvAGgzbn6vo4DW7x0eay9QEsru4vwi1s433z7d3KZ9MmD78y+lecMKxGictLY3UmtVVk6WmdtZyzxdGxbs4LODml2Ksjzz7fZbYn1NjhkR8383fQyiN8RvNGdUdb1n4UsS78+v69Y57hIYypc65ZNHn4oAQxn4cx0lR9IIfE5H7pcZ210h49Lt+pMO2dbINgf.WtzkgLNkCO0vLD6T14QGr7nXdIOO6ZXDOeiywoI6qU6G4Gy0KoZmi7dj7YKIi7dNWHEAic5GNA3hLZpdWiRmqUu8Moz+6is0U6GEWq+TZJ72tr+VtpeEwIEPp8V.MzHiHnnJpJqpXzsyRse3zfG0y9.VDmAj4m46yYuc.ilHb+SfPmer2T5mBFocS93t9utHcGc3vBt5zIAXToxEamIyucYYd+ayL1+qr58iw2p1V9XGqwmT6zxjubhxT1emm0T5LktuL4p81lycbMdhwel8x0+clquiJZXvTN2bDvyYC3H7Q5n9GpyQxn40zTIBoXoO100lcZWF0yLISV86Dweub8XH7A2LVSgHjQ5+s6sRHP8N4emR7TV4B+YS6GtdPws0GZ25mhAiM2XhHnUTxg.ZH8HUc.OXEgPn3jHd91luALDwaxETvuGDz8ma8EaF+NWR+R6ZbTO7fDjf7GwLDIHg+9fLZyqrqsutZs77aMLc1KlNi61x.REu1c4ZSICVikUKG9uY1.QWAqk0czBEXhs5LgKvH1TjUzzSDF9isNRbDvDDdQkHPFwKqMPY8oXN.HV8TUAQYxBbS15t3LdhjX6ZIIdgyc1M68RKeNNe65puv4rmaDeeep+XclqiwO9wMF3fiSxbrNOWAb.jXZwhy6EG4hDb3jmXEdtBou9WmzF97gSjBbDfT5ArxyKCkaloci3vArBuGL6a1LFWzfyy9Jx5oxSeglJB6.STUvnkEL5oZp5wxCIi3qDr2FOrr5YHimk7jxYwg.QmLfPHDFiRRwm3S7IBgQQVVVVVOwmHDTUUUUkkULRQQQQUUAgSSSSSSTTOPCHIIIIMMYYEEEEEEIIUUAAAAAEEQQEiwXLBAMMAgPHDFiRRb7.K.DFEYYYYYY8.C.DTUUUUUkkULhAU.nHP7gQUEr.NvHqJompnkzzzTjzDT0SCvTmZYqcyB7gxJpxx5AJoQU0FSUPooGHJXEEjJZJk+DKOHp3CjTEbxpphkUz5IZAgOPJvQCmKtnoN0H2d.DttSxlVrr103Rbe7j5aWaMlAO55+ojeLmNjlrjLPTDUzh5.Yn3KpOuukKJ8AWKVGt9WIcpkEBJ1PVAoDMN+hAOylWt72or93ZC1HpxsyTYFZjA.A..f..xG..fBkkEHH25hgjfAxyAgwPBfAg...fA.P....D.L.....fQgFoJiQUMwI2Yt5IeOakfxB8aNhehrZ+lWVPuXXI.0xehWqIP.enOSWfuzf9.aTCx60nPkFwvuef+h481mIEK.bPNH0Mxce7Rwd2M6FDjipNtzywiGCUo3yRr2uUT2MqrGxXTegqBXY3taC7RkFjFLe.VeLgU6caLVEpK.MAdrsQN0.KROzIWntYpWu0SgpdHcho5I3dO2cPpbE1AMaij36YHM8PsLTcWbM3SiK294vTCLdm5WYOQTUDGRQOjtX5dBsWm6NjgbENNn2oHP9d.ojGpknhdbary8LHIWgcPwVHI+dBoeGpgn5dbary8LHIWgcPwVHI0o0ES0Qv4dN63b4EnunX107GWyzkkq0uGsxH8couf05b1iYxIrKTn0YRbBc4TcEbrm6NHW9A5g51WSxITFwm68EXtlydLSNA6itV2IxopKjpqvik4ug4xITWTo8NINkV4zdEZrO2MPR9g6hFMOmjSJaoydTXxZWBHlDYMgFmO1icLp2OyF6rOSwcwBbeKuS2p63sJbpl.kb4KvIWGG.hSr4PXK2bXsunTtRhSqGkfiPxM4reAJNG4VIytCslBKVfQaAAJO.HdBtgFKjbeKbGnXRuEQUfcKCj+VybKGPJCss.muRaCityM9Z.fy+MHRkSnevalG+P0f4UW0djTBHFOv.CxTECXKaWIlBDiTNCLqCH2HTTdW0xSnqN.hiCdltNdzC5ZmUtCZdp6I.Xbdcyzdd1zohTy.6o.S8bQlF5t4+1CoTDdwN7YFj4N8Tb56vKz9OX.tldIZTtGr70qpDLT4J6Cirn18faP3ec7IpXkJBTM+GPGceLKrPxPsBZ6fPOqIdY95YY5cCIlHf2Fo8qsyun8.zjK2uLo643FGxM0O2d90f0qK82Dq9lWPhc3hbP657U3UsFAUzNX5vK+qGKwz2IHHBKpFvrP3Zda7fXdRE3IUU8GIXTKnhixW2LGxpI5iTP5pJBx2VeVrZ0B9eIY6xuDD79b4dA1MWpyRBv9wY+J4mGjIuck2n.TxkV0KwkZeUTARxANb0QKxsLemSf5rAnASkrlb9x0G7VZ2rV50E9jFtQ9PerZ1ja6PCD6wWtfgjHHlQAXdayOQp+dL52St8YiVnz7FkBcoKcswAap.gMo.NYs78eaNrmdxB2Ogi0VlRiOhKXxerzwmnY.f1XdTHoIE05x2cvRXpAPOB3NEOYsMkpHNNR.p+IFkqWMvstdy7bKeaEqs.cuXKVFNU2M3k.fYG0uqIBmIOR6133uDpZU1Z5Z73lQu0FsL8d5LDHBpen.ZI66PZHYuknb5YnPaDOClqTOuT5COxO9I.zpl4ueZzrm9RPR4jBZSD2RhI1EYsN3le.yusIKttCRgEds+.4CS2x9DUO47KtjG0.abdFas7EnjrcTEr19jPDVNgNu6I.g14mSoPI3Bh3jHDSFQLjUtXTAs3upJpvc3lyHgsFzL7EZXvF.uayiaq.LsioWiHdLZ+nhYTVCiLvfBLWYEdexHzVz4Twir4L.LlfCN0ZsIK2LGdZSP4AvnrKn8Rp4YN+Wo4MCoeOPWBX8td9XMedxdxpXpmLgJgTK1TARWrQOogI0q7F9cDMrrHGgNq8HF7X+pBjWLOp0zIuydBLwcl2BNPAuwBwW1PkLnQop2jInbvlQhbunFBDt2xSNXj3ZcyoICFE0WZeysFLcXPXDlo+p.p8QdZkAA+ASKkACGobiEed0f7cha.MZUTq1qHuw.GB8q3j2bLYDKF7mtPWbxvSDsObUaFOASw5og8SYO9rW3iF+Xm91KUXQCGF0L+zlzeVnTIljLidRlzZRF9W6dDeG5cSjm.Qgz2OpYgojo8b5.h5Y3f3y.Uw2xtjiqdiQSx6SCzFpucjeZNmNRoq4LIF0gJwLydX9FqhHY4q77lcCmJFHwdRBNebnlMngIxrbFQuKCoZjYZUXPOtjRhrjwOH79bt5wtQ2TOIEMhha3gRL2bAEVyXDWQg9kw9AXJasgWPE10sSgm+bZm31Az7yFvgmYtHYlbV.fny+35gXK3n7FfoRYwO.g7Zh.CCxc+CYVFE0mz1TRPAJuhLRl0tqbSxN98fyzD8JrYAXzL4MJbL3mQCCt3JOBetT3j2XxqPbsS9l0Qc3dRB1B9Fg32YZ.RnsBlWBJAy3LMSIC11vOKYpaDgC8FvkseRwZi2T8qqqy.JRKmYMzr.HR2qlQEg3nknF7zUEqwtfZxxzvqYz6iT3leTs5X+YmnVfXFbT0+R0P5cA0haM+VAHXr6s1uYCRA17M9LEK9fQVvoV8I080fG8hIJsM0NtcOCrfkvYQU7NgYOb4Dfb+idOPMH71vnh5oPyXBqtH0+.7QBvGwB1Q8HMPGdQlcKhpgQuBRmY9.rzzRukbniJffzCoYFEWA.awEKuvcZSTPViL.8HkX7BJ8S7IzjPJSbdc4SULC8pIZl1MjfL1rCbJ1YD9HsOO.fZPM.mSplEfY3UAy5FRffHOChkk9jdTB1a6IfBfms5t+.X58gH4Bg2HSRyF14LIjKbUTObDTAdTbHK2sAmYKrcBXAgFiDsDCLXnOQ80xYfLrzH9jmO1Smf+gKEl.5nwF3qFjJqsG.OHWmSXOBywns4Si4p6zvewm1F.qzP4vmT3nnIS8gf+xLw5enjXw2LccwEbDr0pEe9lDCkGg33AGsvPcbJpDhBr+sajWc1qp5X3URN6AzO0yajQffDVpXu8wO8.";
	}
};
}
