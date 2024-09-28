Content.makeFrontInterface(650, 550);

//mod


const var m1step1 = Content.getComponent("m1step1");
const var m1step2 = Content.getComponent("m1step2");
const var m1step3 = Content.getComponent("m1step3");
const var m1step4 = Content.getComponent("m1step4");



const var m1table1 = Content.getComponent("m1table1");
const var m1table2 = Content.getComponent("m1table2");
const var m1table3 = Content.getComponent("m1table3");
const var m1table4 = Content.getComponent("m1table4");


const var Gmod9 = Synth.getModulator("Mod1");
const var Gmod10 = Synth.getModulator("Mod2");
const var Gmod11 = Synth.getModulator("Mod3");
const var Gmod12 = Synth.getModulator("Mod4");

const var Gm1 = [Content.getComponent("GlobalMod9"),
                 Content.getComponent("GlobalMod10")];
                 
const var Gm2 = [Content.getComponent("GlobalMod11"),
                 Content.getComponent("GlobalMod12")];
        
        const var MODS = Content.getComponent("MODS");
        
                 

inline function onEXTRAMODControl(component, value)
{
if(value == 0)
	  	{
MODS.showControl(0);
}
if(value == 1)
	  	{
MODS.showControl(1);
}
};

Content.getComponent("EXTRAMOD").setControlCallback(onEXTRAMODControl);

const var Presets = Content.getComponent("Presets");


inline function onButton6Control(component, value)
{
	if(value == 0)
	  	{
Presets.showControl(0);
}
if(value == 1)
	  	{
Presets.showControl(1);
}
};

Content.getComponent("Button6").setControlCallback(onButton6Control);


inline function onModPageControl(component, value)
{
if(value == 0)
	  	{
	
for(s in Gm1)
       s.showControl(1);
 for(s in Gm2)
        s.showControl(0);      
        }
        
if(value == 1)
	  	{
	
for(s in Gm1)
       s.showControl(0);
 for(s in Gm2)
        s.showControl(1);      
        }        
       
};

Content.getComponent("ModPage").setControlCallback(onModPageControl);



inline function onGmodMode9Control(component, value)
{
	if(value == 1)
	  	{
	Waveform1.showControl(1);
	m1step1.showControl(0);
	    m1table1.showControl(0);
	    Gmod9.setAttribute(Gmod9.Shape, 0);
	    }
	    
	    if(value == 2)
	      	{
	    Waveform1.showControl(1);
	    m1step1.showControl(0);
	        m1table1.showControl(0);
	        Gmod9.setAttribute(Gmod9.Shape, 1.2);
	        }
	        
	        if(value == 3)
	        	      	{
	        	    Waveform1.showControl(1);
	        	    m1step1.showControl(0);
	        	        m1table1.showControl(0);
	        	        Gmod9.setAttribute(Gmod9.Shape, 2.4);
	        	        }
	if(value == 4)
		        	      	{
		        	    Waveform1.showControl(1);
		        	    m1step1.showControl(0);
		        	        m1table1.showControl(0);
		        	        Gmod9.setAttribute(Gmod9.Shape, 3.6);
		        	        }
		        	        
	if(value == 5)
		        	      	{
		        	    Waveform1.showControl(1);
		        	    m1step1.showControl(0);
		        	        m1table1.showControl(0);
		        	        Gmod9.setAttribute(Gmod9.Shape, 4.8);
		        	        }	        
		        	        
	if(value == 6)
			        	      	{
			        	    Waveform1.showControl(0);
			        	    m1step1.showControl(0);
			        	        m1table1.showControl(1);
			        	        Gmod9.setAttribute(Gmod9.Shape, 6);
			        	        }	
			        	        
	if(value == 7)
			        	      	{
			        	    Waveform1.showControl(0);
			        	    m1step1.showControl(1);
			        	        m1table1.showControl(0);
			        	        Gmod9.setAttribute(Gmod9.Shape, 7.1);
			        	        }			        	                	        	        	        
};

Content.getComponent("GmodMode9").setControlCallback(onGmodMode9Control);

inline function onGmodMode10Control(component, value)
{
	if(value == 1)
	  	{
	Waveform3.showControl(1);
	m1step2.showControl(0);
	    m1table2.showControl(0);
	    Gmod10.setAttribute(Gmod10.Shape, 0);
	    }
	    
	    if(value == 2)
	      	{
	    Waveform3.showControl(1);
	    m1step2.showControl(0);
	        m1table2.showControl(0);
	        Gmod10.setAttribute(Gmod10.Shape, 1.2);
	        }
	        
	        if(value == 3)
	        	      	{
	        	    Waveform3.showControl(1);
	        	    m1step2.showControl(0);
	        	        m1table2.showControl(0);
	        	        Gmod10.setAttribute(Gmod10.Shape, 2.4);
	        	        }
	if(value == 4)
		        	      	{
		        	    Waveform3.showControl(1);
		        	    m1step2.showControl(0);
		        	        m1table2.showControl(0);
		        	        Gmod10.setAttribute(Gmod10.Shape, 3.6);
		        	        }
		        	        
	if(value == 5)
		        	      	{
		        	    Waveform3.showControl(1);
		        	    m1step2.showControl(0);
		        	        m1table2.showControl(0);
		        	        Gmod10.setAttribute(Gmod10.Shape, 4.8);
		        	        }	        
		        	        
	if(value == 6)
			        	      	{
			        	    Waveform3.showControl(0);
			        	    m1step2.showControl(0);
			        	        m1table2.showControl(1);
			        	        Gmod10.setAttribute(Gmod10.Shape, 6);
			        	        }	
			        	        
	if(value == 7)
			        	      	{
			        	    Waveform3.showControl(0);
			        	    m1step2.showControl(1);
			        	        m1table2.showControl(0);
			        	        Gmod10.setAttribute(Gmod10.Shape, 7.1);
			        	        }			        	                	        	        	        
};

Content.getComponent("GmodMode10").setControlCallback(onGmodMode10Control);

inline function onGmodMode11Control(component, value)
{
	if(value == 1)
	  	{
	Waveform5.showControl(1);
	m1step3.showControl(0);
	    m1table3.showControl(0);
	    Gmod11.setAttribute(Gmod11.Shape, 0);
	    }
	    
	    if(value == 2)
	      	{
	    Waveform5.showControl(1);
	    m1step3.showControl(0);
	        m1table3.showControl(0);
	        Gmod11.setAttribute(Gmod11.Shape, 1.2);
	        }
	        
	        if(value == 3)
	        	      	{
	        	    Waveform5.showControl(1);
	        	    m1step3.showControl(0);
	        	        m1table3.showControl(0);
	        	        Gmod11.setAttribute(Gmod11.Shape, 2.4);
	        	        }
	if(value == 4)
		        	      	{
		        	    Waveform5.showControl(1);
		        	    m1step3.showControl(0);
		        	        m1table3.showControl(0);
		        	        Gmod11.setAttribute(Gmod11.Shape, 3.6);
		        	        }
		        	        
	if(value == 5)
		        	      	{
		        	    Waveform5.showControl(1);
		        	    m1step3.showControl(0);
		        	        m1table3.showControl(0);
		        	        Gmod11.setAttribute(Gmod11.Shape, 4.8);
		        	        }	        
		        	        
	if(value == 6)
			        	      	{
			        	    Waveform5.showControl(0);
			        	    m1step3.showControl(0);
			        	        m1table3.showControl(1);
			        	        Gmod11.setAttribute(Gmod11.Shape, 6);
			        	        }	
			        	        
	if(value == 7)
			        	      	{
			        	    Waveform5.showControl(0);
			        	    m1step3.showControl(1);
			        	        m1table3.showControl(0);
			        	        Gmod11.setAttribute(Gmod11.Shape, 7.1);
			        	        }			        	                	        	        	        
};

Content.getComponent("GmodMode11").setControlCallback(onGmodMode11Control);


inline function onGmodMode12Control(component, value)
{
	if(value == 1)
	  	{
	Waveform7.showControl(1);
	m1step4.showControl(0);
	    m1table4.showControl(0);
	    Gmod12.setAttribute(Gmod12.Shape, 0);
	    }
	    
	    if(value == 2)
	      	{
	    Waveform7.showControl(1);
	    m1step4.showControl(0);
	        m1table4.showControl(0);
	        Gmod12.setAttribute(Gmod12.Shape, 1.2);
	        }
	        
	        if(value == 3)
	        	      	{
	        	    Waveform7.showControl(1);
	        	    m1step4.showControl(0);
	        	        m1table4.showControl(0);
	        	        Gmod12.setAttribute(Gmod12.Shape, 2.4);
	        	        }
	if(value == 4)
		        	      	{
		        	    Waveform7.showControl(1);
		        	    m1step4.showControl(0);
		        	        m1table4.showControl(0);
		        	        Gmod12.setAttribute(Gmod12.Shape, 3.6);
		        	        }
		        	        
	if(value == 5)
		        	      	{
		        	    Waveform7.showControl(1);
		        	    m1step4.showControl(0);
		        	        m1table4.showControl(0);
		        	        Gmod12.setAttribute(Gmod12.Shape, 4.8);
		        	        }	        
		        	        
	if(value == 6)
			        	      	{
			        	    Waveform7.showControl(0);
			        	    m1step4.showControl(0);
			        	        m1table4.showControl(1);
			        	        Gmod12.setAttribute(Gmod12.Shape, 6);
			        	        }	
			        	        
	if(value == 7)
			        	      	{
			        	    Waveform7.showControl(0);
			        	    m1step4.showControl(1);
			        	        m1table4.showControl(0);
			        	        Gmod12.setAttribute(Gmod12.Shape, 7.1);
			        	        }			        	                	        	        	        
};

Content.getComponent("GmodMode12").setControlCallback(onGmodMode12Control);

const var dp1 = Synth.getDisplayBufferSource("Mod1");

const var rb1 = dp1.getDisplayBuffer(0);
const var rb2 = dp1.getDisplayBuffer(1);

const var BUFFER_LENGTH = 16384;

const var properties = {
  "BufferLength": BUFFER_LENGTH,
  "NumChannels": 2
};


rb1.setRingBufferProperties(properties);
rb2.setRingBufferProperties(properties);

const var Waveform1 = Content.getComponent("Waveform1");
const var Waveform2 = Content.getComponent("Waveform2");

Waveform1.setTimerCallback(function()
{

	this.data.buffer = rb1.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform1.startTimer(30);

Waveform1.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xCC843E38);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

Waveform2.setTimerCallback(function()
{

	this.data.buffer = rb2.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform2.startTimer(30);

Waveform2.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xFF686449);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});



const var dp2 = Synth.getDisplayBufferSource("Mod2");

const var rb3 = dp2.getDisplayBuffer(0);
const var rb4 = dp2.getDisplayBuffer(1);


rb3.setRingBufferProperties(properties);
rb4.setRingBufferProperties(properties);

const var Waveform3 = Content.getComponent("Waveform3");
const var Waveform4 = Content.getComponent("Waveform4");

Waveform3.setTimerCallback(function()
{

	this.data.buffer = rb3.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform3.startTimer(30);

Waveform3.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xCC843E38);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

Waveform4.setTimerCallback(function()
{

	this.data.buffer = rb4.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform4.startTimer(30);

Waveform4.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xFF686449);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});


const var dp3 = Synth.getDisplayBufferSource("Mod3");

const var rb5 = dp3.getDisplayBuffer(0);
const var rb6 = dp3.getDisplayBuffer(1);


rb5.setRingBufferProperties(properties);
rb6.setRingBufferProperties(properties);

const var Waveform5 = Content.getComponent("Waveform5");
const var Waveform6 = Content.getComponent("Waveform6");

Waveform5.setTimerCallback(function()
{

	this.data.buffer = rb5.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform5.startTimer(30);

Waveform5.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xCC843E38);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

Waveform6.setTimerCallback(function()
{

	this.data.buffer = rb6.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform6.startTimer(30);

Waveform6.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xFF686449);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

const var dp4 = Synth.getDisplayBufferSource("Mod4");

const var rb7 = dp4.getDisplayBuffer(0);
const var rb8 = dp4.getDisplayBuffer(1);


rb7.setRingBufferProperties(properties);
rb8.setRingBufferProperties(properties);

const var Waveform7 = Content.getComponent("Waveform7");
const var Waveform8 = Content.getComponent("Waveform8");

Waveform7.setTimerCallback(function()
{

	this.data.buffer = rb7.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform7.startTimer(30);

Waveform7.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xCC843E38);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

Waveform8.setTimerCallback(function()
{

	this.data.buffer = rb8.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform8.startTimer(30);

Waveform8.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xFF686449);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

function onNoteOn()
{
	
}
 function onNoteOff()
{
	
}
 function onController()
{
	
}
 function onTimer()
{
	
}
 function onControl(number, value)
{
	
}
 