Content.makeFrontInterface(460, 600);
Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");
include("sliderpacks.js");


const var Presets = Content.getComponent("Presets");
const var Resonator = Synth.getEffect("Resonator");
const var Fb = Content.getComponent("Fb");


inline function onButton1Control(component, value)
{
	Presets.showControl(value);
};

Content.getComponent("Button1").setControlCallback(onButton1Control);



inline function onResModeControl(component, value)
{


	if(value == 1)
	  	{
	Resonator.setAttribute(Resonator.ResMode, 1);

	}
	if(value == 2)
	  	{
	Resonator.setAttribute(Resonator.ResMode, 2);

	}
	if(value == 3)
	  	{
	Resonator.setAttribute(Resonator.ResMode, 3);

	}
	if(value == 4)
	  	{
	Resonator.setAttribute(Resonator.ResMode, 4);

		
	}

};

Content.getComponent("ResMode").setControlCallback(onResModeControl);

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
 