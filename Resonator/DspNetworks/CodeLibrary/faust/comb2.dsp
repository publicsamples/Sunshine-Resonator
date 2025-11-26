import("stdfaust.lib");

intdel = hslider("del",0,0,1024,1.0);
maxdel = 1024;

aN = 1;
del = hslider("aN",0,0,1,0.01);


process = fi.ff_fcomb(maxdel,intdel,aN,del), fi.ff_fcomb(maxdel,intdel,aN,del);
