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
const var GainSP = Synth.getSliderPackProcessor("Resonator").getSliderPack(5);
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
const var FilterSP = Synth.getSliderPackProcessor("Resonator").getSliderPack(1);
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



const Lrs = Engine.createAndRegisterSliderPackData(4);     
const var PanSP = Synth.getSliderPackProcessor("Resonator").getSliderPack(6);
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



const Tr = Engine.createAndRegisterSliderPackData(4);     
const var ThreshSP = Synth.getSliderPackProcessor("Resonator").getSliderPack(2);
Tr.linkTo(ThreshSP);
        
const var TrStages =[];

for (i = 0; i < 8; i++)
{
    TrStages[i] = Content.getComponent("Thresh"+(i+1));
    TrStages[i].setControlCallback(TrStage);
}
     
     inline function TrStage(component, value)
     {    
         local idx = TrStages.indexOf(component); 
        
         {  
         
         	Tr.setValueWithUndo(idx, value);
       
     }
     
}  

const Rat = Engine.createAndRegisterSliderPackData(4);     
const var RatioSP = Synth.getSliderPackProcessor("Resonator").getSliderPack(4);
Rat.linkTo(RatioSP);
        
const var RatStages =[];

for (i = 0; i < 8; i++)
{
    RatStages[i] = Content.getComponent("Ratio"+(i+1));
    RatStages[i].setControlCallback(RatStage);
}
     
     inline function RatStage(component, value)
     {    
         local idx = RatStages.indexOf(component); 
        
         {  
         
         	Rat.setValueWithUndo(idx, value);
       
     }
     
}  

const Rel = Engine.createAndRegisterSliderPackData(4);     
const var RelSP = Synth.getSliderPackProcessor("Resonator").getSliderPack(3);
Rel.linkTo(RelSP);
        
const var RelStages =[];

for (i = 0; i < 8; i++)
{
    RelStages[i] = Content.getComponent("Rel"+(i+1));
    RelStages[i].setControlCallback(RelStage);
}
     
     inline function RelStage(component, value)
     {    
         local idx = RelStages.indexOf(component); 
        
         {  
         
         	Rel.setValueWithUndo(idx, value);
       
     }
     
}  

const Pshift = Engine.createAndRegisterSliderPackData(4);     
const var PshiftSP = Synth.getSliderPackProcessor("Resonator").getSliderPack(7);
Pshift.linkTo(PshiftSP);
        
const var PshiftStages =[];

for (i = 0; i < 8; i++)
{
    PshiftStages[i] = Content.getComponent("Pshift"+(i+1));
    PshiftStages[i].setControlCallback(PshiftStage);
}
     
     inline function PshiftStage(component, value)
     {    
         local idx = PshiftStages.indexOf(component); 
        
         {  
         
         	Pshift.setValueWithUndo(idx, value);
       
     }
     
}  


