 // -----------------------------
// Quantiser script (UI already built)
// -----------------------------


// Scale definitions (unchanged)
const var major      = [0, 2, 4, 5, 7, 9, 11];
const var minor      = [0, 2, 3, 5, 7, 8, 10];
const var majorPent  = [0, 2, 4, 7, 9];
const var minorPent  = [0, 3, 5, 7, 10];

// UI references (expects these IDs exist in the Designer)
const var FreqKnob1  = Content.getComponent("ResStage1");
const var FreqKnob2  = Content.getComponent("ResStage2");
const var FreqKnob3  = Content.getComponent("ResStage3");
const var FreqKnob4  = Content.getComponent("ResStage4");
const var FreqKnob5  = Content.getComponent("ResStage5");
const var FreqKnob6  = Content.getComponent("ResStage6");
const var FreqKnob7  = Content.getComponent("ResStage7");
const var FreqKnob8  = Content.getComponent("ResStage8");

const var ScaleMenu = Content.getComponent("ScaleMenu");
const var RootMenu  = Content.getComponent("RootMenu");
const var ScriptFX1 = Synth.getEffect("Resonator");

// cached state
var currentRootOffset = 0; // 0..11

// quantiser helper functions (unchanged)
inline function quantiseToSemitone(freqValue)
{
    local midi = 69 + 12 * Math.log(freqValue / 440) / Math.log(2);
    local quantisedMidi = Math.round(midi);
    return 440 * Math.pow(2, (quantisedMidi - 69) / 12);
}

inline function quantiseToScale(freqValue, scaleArray, rootOffset)
{
    local midi = 69 + 12 * Math.log(freqValue / 440) / Math.log(2);
    local oct = Math.floor(midi / 12);
    local deg = midi % 12;

    deg = (deg - rootOffset + 12) % 12;

    local closest = scaleArray[0];
    local diff = Math.abs(deg - closest);
    for (i in scaleArray)
    {
        local d = Math.abs(deg - scaleArray[i]);
        if (d < diff)
        {
            closest = scaleArray[i];
            diff = d;
        }
    }

    closest = (closest + rootOffset) % 12;
    local quantisedMidi = oct * 12 + closest;
    return 440 * Math.pow(2, (quantisedMidi - 69) / 12);
}

// Main knob callback (reads cached rootOffset)
inline function onFreqKnob1Control(component, value)
{
    local mode = ScaleMenu.getItemText();
    local rootOffset = currentRootOffset; // 0..11
    local quantised = value;

    // debug print so you can watch root/value when knob changes
    // remove or comment out in production
    Console.print("Knob value: " + value + "   rootOffset: " + rootOffset + "   mode: " + mode);

    if (mode == "Semitone")
        quantised = quantiseToSemitone(value);
    else if (mode == "Major")
        quantised = quantiseToScale(value, major, rootOffset);
    else if (mode == "Minor")
        quantised = quantiseToScale(value, minor, rootOffset);
    else if (mode == "Major Pentatonic")
        quantised = quantiseToScale(value, majorPent, rootOffset);
    else if (mode == "Minor Pentatonic")
        quantised = quantiseToScale(value, minorPent, rootOffset);

    Resonator.setAttribute(Resonator.FREQ1, quantised);
}
FreqKnob1.setControlCallback(onFreqKnob1Control);

inline function onFreqKnob2Control(component, value)
{
    local mode = ScaleMenu.getItemText();
    local rootOffset = currentRootOffset; // 0..11
    local quantised = value;

    // debug print so you can watch root/value when knob changes
    // remove or comment out in production
    Console.print("Knob value: " + value + "   rootOffset: " + rootOffset + "   mode: " + mode);

    if (mode == "Semitone")
        quantised = quantiseToSemitone(value);
    else if (mode == "Major")
        quantised = quantiseToScale(value, major, rootOffset);
    else if (mode == "Minor")
        quantised = quantiseToScale(value, minor, rootOffset);
    else if (mode == "Major Pentatonic")
        quantised = quantiseToScale(value, majorPent, rootOffset);
    else if (mode == "Minor Pentatonic")
        quantised = quantiseToScale(value, minorPent, rootOffset);

    Resonator.setAttribute(Resonator.FREQ2, quantised);
}
FreqKnob2.setControlCallback(onFreqKnob2Control);

inline function onFreqKnob3Control(component, value)
{
    local mode = ScaleMenu.getItemText();
    local rootOffset = currentRootOffset; // 0..11
    local quantised = value;

    // debug print so you can watch root/value when knob changes
    // remove or comment out in production
    Console.print("Knob value: " + value + "   rootOffset: " + rootOffset + "   mode: " + mode);

    if (mode == "Semitone")
        quantised = quantiseToSemitone(value);
    else if (mode == "Major")
        quantised = quantiseToScale(value, major, rootOffset);
    else if (mode == "Minor")
        quantised = quantiseToScale(value, minor, rootOffset);
    else if (mode == "Major Pentatonic")
        quantised = quantiseToScale(value, majorPent, rootOffset);
    else if (mode == "Minor Pentatonic")
        quantised = quantiseToScale(value, minorPent, rootOffset);

    Resonator.setAttribute(Resonator.FREQ3, quantised);
}
FreqKnob3.setControlCallback(onFreqKnob3Control);

inline function onFreqKnob4Control(component, value)
{
    local mode = ScaleMenu.getItemText();
    local rootOffset = currentRootOffset; // 0..11
    local quantised = value;

    // debug print so you can watch root/value when knob changes
    // remove or comment out in production
    Console.print("Knob value: " + value + "   rootOffset: " + rootOffset + "   mode: " + mode);

    if (mode == "Semitone")
        quantised = quantiseToSemitone(value);
    else if (mode == "Major")
        quantised = quantiseToScale(value, major, rootOffset);
    else if (mode == "Minor")
        quantised = quantiseToScale(value, minor, rootOffset);
    else if (mode == "Major Pentatonic")
        quantised = quantiseToScale(value, majorPent, rootOffset);
    else if (mode == "Minor Pentatonic")
        quantised = quantiseToScale(value, minorPent, rootOffset);

    Resonator.setAttribute(Resonator.FREQ4, quantised);
}
FreqKnob4.setControlCallback(onFreqKnob4Control);

inline function onFreqKnob5Control(component, value)
{
    local mode = ScaleMenu.getItemText();
    local rootOffset = currentRootOffset; // 0..11
    local quantised = value;

    // debug print so you can watch root/value when knob changes
    // remove or comment out in production
    Console.print("Knob value: " + value + "   rootOffset: " + rootOffset + "   mode: " + mode);

    if (mode == "Semitone")
        quantised = quantiseToSemitone(value);
    else if (mode == "Major")
        quantised = quantiseToScale(value, major, rootOffset);
    else if (mode == "Minor")
        quantised = quantiseToScale(value, minor, rootOffset);
    else if (mode == "Major Pentatonic")
        quantised = quantiseToScale(value, majorPent, rootOffset);
    else if (mode == "Minor Pentatonic")
        quantised = quantiseToScale(value, minorPent, rootOffset);

    Resonator.setAttribute(Resonator.FREQ5, quantised);
}
FreqKnob5.setControlCallback(onFreqKnob5Control);

inline function onFreqKnob6Control(component, value)
{
    local mode = ScaleMenu.getItemText();
    local rootOffset = currentRootOffset; // 0..11
    local quantised = value;

    // debug print so you can watch root/value when knob changes
    // remove or comment out in production
    Console.print("Knob value: " + value + "   rootOffset: " + rootOffset + "   mode: " + mode);

    if (mode == "Semitone")
        quantised = quantiseToSemitone(value);
    else if (mode == "Major")
        quantised = quantiseToScale(value, major, rootOffset);
    else if (mode == "Minor")
        quantised = quantiseToScale(value, minor, rootOffset);
    else if (mode == "Major Pentatonic")
        quantised = quantiseToScale(value, majorPent, rootOffset);
    else if (mode == "Minor Pentatonic")
        quantised = quantiseToScale(value, minorPent, rootOffset);

    Resonator.setAttribute(Resonator.FREQ6, quantised);
}
FreqKnob6.setControlCallback(onFreqKnob6Control);

inline function onFreqKnob7Control(component, value)
{
    local mode = ScaleMenu.getItemText();
    local rootOffset = currentRootOffset; // 0..11
    local quantised = value;

    // debug print so you can watch root/value when knob changes
    // remove or comment out in production
    Console.print("Knob value: " + value + "   rootOffset: " + rootOffset + "   mode: " + mode);

    if (mode == "Semitone")
        quantised = quantiseToSemitone(value);
    else if (mode == "Major")
        quantised = quantiseToScale(value, major, rootOffset);
    else if (mode == "Minor")
        quantised = quantiseToScale(value, minor, rootOffset);
    else if (mode == "Major Pentatonic")
        quantised = quantiseToScale(value, majorPent, rootOffset);
    else if (mode == "Minor Pentatonic")
        quantised = quantiseToScale(value, minorPent, rootOffset);

    Resonator.setAttribute(Resonator.FREQ7, quantised);
}
FreqKnob7.setControlCallback(onFreqKnob7Control);

inline function onFreqKnob8Control(component, value)
{
    local mode = ScaleMenu.getItemText();
    local rootOffset = currentRootOffset; // 0..11
    local quantised = value;

    // debug print so you can watch root/value when knob changes
    // remove or comment out in production
    Console.print("Knob value: " + value + "   rootOffset: " + rootOffset + "   mode: " + mode);

    if (mode == "Semitone")
        quantised = quantiseToSemitone(value);
    else if (mode == "Major")
        quantised = quantiseToScale(value, major, rootOffset);
    else if (mode == "Minor")
        quantised = quantiseToScale(value, minor, rootOffset);
    else if (mode == "Major Pentatonic")
        quantised = quantiseToScale(value, majorPent, rootOffset);
    else if (mode == "Minor Pentatonic")
        quantised = quantiseToScale(value, minorPent, rootOffset);

    Resonator.setAttribute(Resonator.FREQ8, quantised);
}
FreqKnob8.setControlCallback(onFreqKnob8Control);



// RootMenu callback — uses the 'value' passed in (1-based index)
inline function onRootMenuControl(component, value)
{
    // debug - confirm the callback fires and the value is 1..12
    Console.print("RootMenu callback fired. value = " + value);

    // convert 1-based index to 0-based semitone offset
    currentRootOffset = Math.max(0, value - 1);

    // reapply quantisation immediately
    FreqKnob1.changed();
    FreqKnob2.changed();
    FreqKnob3.changed();
    FreqKnob4.changed();
    FreqKnob5.changed();
    FreqKnob6.changed();
    FreqKnob7.changed();
    FreqKnob8.changed();
}
RootMenu.setControlCallback(onRootMenuControl);

// ScaleMenu callback — simply reapply when scale changes
inline function onScaleMenuControl(component, value)
{
    Console.print("ScaleMenu changed. value = " + value + "  text = " + ScaleMenu.getItemText());
    FreqKnob1.changed();
    FreqKnob2.changed();
    FreqKnob3.changed();
    FreqKnob4.changed();
    FreqKnob5.changed();
    FreqKnob6.changed();
    FreqKnob7.changed();
    FreqKnob8.changed();
}
ScaleMenu.setControlCallback(onScaleMenuControl);

// Don't touch existing ComboBox item population done in the Designer
Console.print("Quantiser script loaded - ready.");
