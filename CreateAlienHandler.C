AliAnalysisGrid *CreateAlienHandler()
{

  AliAnalysisAlien *plugin = new AliAnalysisAlien();
  //plugin->SetOverwriteMode();

  // Set the run mode (can be "full", "test", "offline", "submit" or "terminate")
  //plugin->SetRunMode("test");
  plugin->SetRunMode("full");
  //plugin->SetRunMode("terminate");

  // Set versions of used packages
  plugin->SetAPIVersion("V1.1x");
  plugin->SetROOTVersion("v5-34-08-6");
  plugin->SetAliROOTVersion("vAN-20141031");

  // Set the path for finding the data
  plugin->SetGridDataDir("/alice/data/2010/LHC10h/");
  plugin->SetDataPattern("ESDs/pass2/AOD086/*/AliAOD.root"); // for testing over multiple files
  //plugin->SetDataPattern("ESDs/pass2/AOD086/0001/AliAOD.root"); // for testing over a single file
  plugin->SetRunPrefix("000");
  //plugin->AddRunNumber(137161);
  gROOT->ProcessLine(".L AddRunNumbers.C");
  int added = AddRunNumbers(plugin,0,95,"lhc10h");
  if(added<0) return NULL;

  // Set the path for the output
  plugin->SetGridWorkingDir("TaskExample"); // $HOME/TaskExample
  plugin->SetGridOutputDir("OutputTesting_X005"); // $HOME/TaskExample/OutputTesting

  // Specify the source code for the analysis
  plugin->SetAnalysisSource("AliAnalysisTaskExample.cxx"); // class file
  plugin->SetAdditionalLibs("AliAnalysisTaskExample.h AliAnalysisTaskExample.cxx"); // header space class

  // Default outputs (?)
  plugin->SetDefaultOutputs(); // ALWAYS use default outputs, code warns then crashes if not
  // The rest of these are optional, though some are very useful
  plugin->SetSplitMaxInputFileNumber(100); // default 100 input files/subjob
  plugin->SetMaxInitFailed(5); // default (?) jobs fail to kill waiting subjobs
  plugin->SetMasterResubmitThreshold(90); // default (?) resubmit threshold
  plugin->SetTTL(50000); // default 30000 sec time to live
  plugin->SetAnalysisMacro("TaskExample.C"); // default "MyAnalysis.C"
  plugin->SetExecutable("TaskExample.sh"); // default "analysis.sh"
  plugin->SetJDLName("TaskExample.jdl"); // default "analysis.jdl"
  plugin->SetInputFormat("xml-single"); // default "xml-single"
  plugin->SetPrice(1); // default 1 price to modify job
  plugin->SetSplitMode("se"); // default "se"

  return plugin;

}
