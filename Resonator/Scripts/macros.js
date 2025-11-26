/** Macro Plugin Parameter Example.

This snippet demonstrates how to use the macro control system for a dynamic plugin parameter assignment
so that the user can assign any control to a plugin parameter.

In order for this to work, you will need to add two preprocessor macros to your ExtraDefinitions fields in the project settings:

HISE_MACROS_ARE_PLUGIN_PARAMETERS=1
HISE_NUM_MACROS=4

Obviously you can use any number instead of 4, but for this snippet we'll keep it lean...

*/



namespace MacroParameterHandling
{

// Use EXACTLY as many names as you define with HISE_NUM_MACROS in your extra definitions here
Engine.setFrontendMacros(["Mod 1", "Mod 2", "Mod 3"]);

const var mh = Engine.createMacroHandler();

// This command will make sure that you can't assign more than one parameter to a macro slot
// (omit this if you want to keep this, but usually you want a 1:1 connection to plugin parameters)
mh.setExclusiveMode(false);

//Note that macro assignments are part of the user preset data model, so they will be 
// restored correctly when loading a DAW session. However if you want to keep the 
// macro assignments consistent across user preset browsing, you will have to implement 
// this manually by saving and restoring the macro connection data
const var uph = Engine.createUserPresetHandler();

reg currentMacroConnections;

// This will be executed before a preset is loaded
uph.setPreCallback(function(presetData)
{
	// checks if the preset load is coming from a user trying to load a preset
	// (as opposed to the DAW restoring the project session)
	if(!uph.isInternalPresetLoad())
	{
		// Store the current macro connections as a JSON object.
		currentMacroConnections = mh.getMacroDataObject();
	}
});

// This will be executed after a preset load and will restore the macro connection objects
// when the user loads a preset so they stay consistent across browsing presets.
uph.setPostCallback(function(presetFile)
{
	if(!uph.isInternalPresetLoad() && isDefined(currentMacroConnections))
	{
		mh.setMacroDataFromObject(currentMacroConnections);
	}
});
	
}





