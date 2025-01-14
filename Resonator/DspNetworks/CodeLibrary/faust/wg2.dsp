import("stdfaust.lib");

nMax = hslider("nMax",0,0,1000,1.0);



n = 1;


process = pm.waveguideUd(nMax,n);

