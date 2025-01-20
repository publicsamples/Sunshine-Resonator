const Rs = Engine.createAndRegisterSliderPackData(0);     
const var ResSP = Synth.getSliderPackProcessor("Resonator").getSliderPack(0);
Rs.linkTo(ResSP);
        
const var RsStages =[];

for (i = 0; i < 8; i++)
{
    RsStages[i] = Content.getComponent("ResStage"+(i+1));
    RsStages[i].setControlCallback(RsStage);
}
     
     inline function RsStage(component, value)
     {    
         local idx = RsStages.indexOf(component); 
        
         {  
         
         	Rs.setValueWithUndo(idx, value);
       
     }
     
}       

const Gs = Engine.createAndRegisterSliderPackData(1);     
const var GainSP = Synth.getSliderPackProcessor("Resonator").getSliderPack(7);
Gs.linkTo(GainSP);
        
const var GsStages =[];

for (i = 0; i < 8; i++)
{
    GsStages[i] = Content.getComponent("Gain"+(i+1));
    GsStages[i].setControlCallback(GsStage);
}
     
     inline function GsStage(component, value)
     {    
         local idx = GsStages.indexOf(component); 
        
         {  
         
         	Gs.setValueWithUndo(idx, value);
       
     }
     
}    

const Fs = Engine.createAndRegisterSliderPackData(2);     
const var FilterSP = Synth.getSliderPackProcessor("Resonator").getSliderPack(3);
Fs.linkTo(FilterSP);
        
const var FsStages =[];

for (i = 0; i < 8; i++)
{
    FsStages[i] = Content.getComponent("CUT"+(i+1));
    FsStages[i].setControlCallback(FsStage);
}
     
     inline function FsStage(component, value)
     {    
         local idx = FsStages.indexOf(component); 
        
         {  
         
         	Fs.setValueWithUndo(idx, value);
       
     }
     
}    

const Ps = Engine.createAndRegisterSliderPackData(3);     
const var ShiftSP = Synth.getSliderPackProcessor("Resonator").getSliderPack(2);
Ps.linkTo(ShiftSP);
        
const var PsStages =[];

for (i = 0; i < 8; i++)
{
    PsStages[i] = Content.getComponent("Pshift"+(i+1));
    PsStages[i].setControlCallback(PsStage);
}
     
     inline function PsStage(component, value)
     {    
         local idx = PsStages.indexOf(component); 
        
         {  
         
         	Ps.setValueWithUndo(idx, value);
       
     }
     
}  

const Lrs = Engine.createAndRegisterSliderPackData(4);     
const var PanSP = Synth.getSliderPackProcessor("Resonator").getSliderPack(5);
Lrs.linkTo(PanSP);
        
const var LrsStages =[];

for (i = 0; i < 8; i++)
{
    LrsStages[i] = Content.getComponent("Pan"+(i+1));
    LrsStages[i].setControlCallback(LrsStage);
}
     
     inline function LrsStage(component, value)
     {    
         local idx = LrsStages.indexOf(component); 
        
         {  
         
         	Lrs.setValueWithUndo(idx, value);
       
     }
     
}  


