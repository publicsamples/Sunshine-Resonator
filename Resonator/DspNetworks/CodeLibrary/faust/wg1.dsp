import("stdfaust.lib");

del = hslider("del",0,0,1000,1.0);
maxdel = 1024;


aN = hslider("aN",0,0,1,0.01);


process = fi.allpass_fcomb(maxdel,del,aN), fi.allpass_fcomb(maxdel,del,aN);

