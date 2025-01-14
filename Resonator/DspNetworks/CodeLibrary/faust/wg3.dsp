import("stdfaust.lib");

sv = hslider("del",-1,0,1,0.01);
//maxdel = 1024;


n = 1;


process = fi.allpassn(n, sv), fi.allpassn(n, sv);

