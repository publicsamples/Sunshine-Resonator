Content.makeFrontInterface(600, 600);
Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");

//mod

const var Gmod9 = Synth.getModulator("Mod1");


const var Gm1 = [Content.getComponent("GlobalMod9"),
                 Content.getComponent("GlobalMod10")];
                 
const var Gm2 = [Content.getComponent("GlobalMod11"),
                 Content.getComponent("GlobalMod12")];
        
        const var MODS = Content.getComponent("MODS");
        

const var Presets = Content.getComponent("Presets");

const var Wgresos = Content.getComponent("Wgresos");
const var WgFile = Content.getComponent("WgFile");
const var Resonator = Synth.getAudioSampleProcessor("Resonator");

const var Fb = Content.getComponent("Fb");


const var MinMax = Content.getComponent("MinMax");
const var SyncDiv = Content.getComponent("SyncDiv");
const var ResSync = Content.getComponent("ResSync");
const var SyncCont = [Content.getComponent("ResSync"),
                      Content.getComponent("ScriptLabel27")];


inline function onResSyncControl(component, value)
{
	Resonator.setAttribute(Resonator.SampleSync, value);

	MinMax.showControl(value-1);
	SyncDiv.showControl(value);
};

Content.getComponent("ResSync").setControlCallback(onResSyncControl);



inline function onResModeControl(component, value)
{


	if(value == 1)
	  	{
	Resonator.setAttribute(Resonator.delaymode, 1);
	Wgresos.showControl(1);
	WgFile.showControl(0);
	for(s in SyncCont)
		s.showControl(0);
		ResSync.setValue(0);
		ResSync.changed();
	}
	if(value == 2)
	  	{
	Resonator.setAttribute(Resonator.delaymode, 2);
	Wgresos.showControl(1);
	WgFile.showControl(0);
	for(s in SyncCont)
		s.showControl(1);
	}
	if(value == 3)
	  	{
	Resonator.setAttribute(Resonator.delaymode, 3);
	Wgresos.showControl(1);
	WgFile.showControl(0);
	for(s in SyncCont)
		s.showControl(1);
	}
	if(value == 4)
	  	{
	Resonator.setAttribute(Resonator.delaymode, 4);
	Wgresos.showControl(1);
	WgFile.showControl(0);
	for(s in SyncCont)
		s.showControl(1);
	}
	if(value == 5)
	  	{
	Resonator.setAttribute(Resonator.delaymode, 5);
	Wgresos.showControl(1);
	WgFile.showControl(0);
	for(s in SyncCont)
		s.showControl(0);
		ResSync.setValue(0);
			ResSync.changed();
	}
	if(value == 6)
	  	{
	Resonator.setAttribute(Resonator.delaymode, 6);
	Wgresos.showControl(1);
	WgFile.showControl(0);
	for(s in SyncCont)
		s.showControl(0);
		ResSync.setValue(0);
			ResSync.changed();
	}
	if(value == 7)
		  	{
		Resonator.setAttribute(Resonator.delaymode, 7);
		Wgresos.showControl(0);
		WgFile.showControl(1);
		for(s in SyncCont)
			s.showControl(1);
		}

};

Content.getComponent("ResMode").setControlCallback(onResModeControl);

const var COMP = Content.getComponent("COMP");
const var Filter = Content.getComponent("Filter");
const var PitchShift = Content.getComponent("PitchShift");


inline function onProcModeControl(component, value)
{
		if(value == 1)
	  	{
	COMP.showControl(1);
	Filter.showControl(0);
	PitchShift.showControl(0);
	}
	if(value == 2)
	  	{
	COMP.showControl(0);
	Filter.showControl(2);
	PitchShift.showControl(0);
	}
	if(value == 3)
	  	{
	COMP.showControl(0);
	Filter.showControl(0);
	PitchShift.showControl(1);
	}
};

Content.getComponent("ProcMode").setControlCallback(onProcModeControl);




const var Table1 = Content.getComponent("Table1");
const var Waveform1 = Content.getComponent("Waveform1");
const var Step1 = Content.getComponent("Step1");


inline function onGmodMode9Control(component, value)
{
	if(value == 1)
	  	{

	Table1.showControl(0);
	Step1.showControl(0);
	Waveform1.setPosition(10, 65, 170, 80);

	    Gmod9.setAttribute(Gmod9.Shape, 1);
	    }
	    
	    if(value == 2)
	      	{
	
	    Table1.showControl(0);
	    Step1.showControl(0);
Waveform1.setPosition(10, 90, 170, 80);

	        Gmod9.setAttribute(Gmod9.Shape, 2);
	        }
	        
	        if(value == 3)
	        	      	{

	        	    Table1.showControl(0);
	        	    Step1.showControl(0);
	        	    Waveform1.setPosition(10, 90, 170, 80);

	        	        Gmod9.setAttribute(Gmod9.Shape, 3);
	        	        }
	if(value == 4)
		        	      	{

		        	    Table1.showControl(0);
		        	    Step1.showControl(0);
		        	    Waveform1.setPosition(10, 90, 170, 80);

		        	        Gmod9.setAttribute(Gmod9.Shape, 4);
		        	        }
		        	        
	if(value == 5)
		        	      	{

		        	    Table1.showControl(0);
		        	    Step1.showControl(0);
		        	    Waveform1.setPosition(10, 90, 170, 80);

		        	        Gmod9.setAttribute(Gmod9.Shape, 5);
		        	        }	        
		        	        
	if(value == 6)
			        	      	{

			        	    Table1.showControl(1);
			        	    Step1.showControl(0);
			        	    Waveform1.setPosition(10, 165, 170, 15);

			        	        Gmod9.setAttribute(Gmod9.Shape, 6);
			        	        }	
			        	        
	if(value == 7)
			        	      	{

			        	    Table1.showControl(0);
			        	    Step1.showControl(1);
			        	    Waveform1.setPosition(10, 165, 170, 15);

			        	        Gmod9.setAttribute(Gmod9.Shape, 7);
			        	        }			        	                	        	        	        
};

Content.getComponent("GmodMode9").setControlCallback(onGmodMode9Control);

//const var Waveform1 = Content.getComponent("Waveform1");

const var BUFFER_LENGTH = 16384;

const var properties = {
  "BufferLength": BUFFER_LENGTH,
  "NumChannels": 1
};

const var CompWave = Content.getComponent("CompWave");

const var CompDisplay = Synth.getDisplayBufferSource("Resonator");
const var cRb = CompDisplay.getDisplayBuffer(0);


cRb.setRingBufferProperties(properties);

CompWave.setTimerCallback(function()
{

	this.data.buffer = cRb.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

CompWave.startTimer(30);

CompWave.setPaintRoutine(function(g)
{
	g.fillAll(0x22FFFFFF);
	g.setColour(0xFF3C1212);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});


//mod display


const var dp = Synth.getDisplayBufferSource("Mod1");

const var rb = dp.getDisplayBuffer(0);

rb.setRingBufferProperties(properties);

Waveform1.setTimerCallback(function()
{

	this.data.buffer = rb.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform1.startTimer(30);

Waveform1.setPaintRoutine(function(g)
{
	g.fillAll(0x22FFFFFF);
	g.setColour(0xFF3C1212);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});


inline function onStagesControl(component, value)
{
	Resonator.setAttribute(Resonator.NumClones, value);
	Resonator.setAttribute(Resonator.Clones2, value);
};

Content.getComponent("Stages").setControlCallback(onStagesControl);
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
 