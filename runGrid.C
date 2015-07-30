void runGrid()
{

  // gSystem->Load("libCore.so");
  // gSystem->Load("libTree.so");
  // gSystem->Load("libGeom.so");
  // gSystem->Load("libVMC.so");
  // gSystem->Load("libPhysics.so");
  // gSystem->Load("libSTEERBase");
  // gSystem->Load("libESD");
  // gSystem->Load("libAOD");
  // gSystem->Load("libANALYSIS");
  // gSystem->Load("libANALYSISalice");
  gROOT->ProcessLine(".include $ROOTSYS/include");
  gROOT->ProcessLine(".include $ALICE_ROOT/include");

  gROOT->LoadMacro("CreateAlienHandler.C");
  AliAnalysisGrid *alienH = CreateAlienHandler();
  if(!alienH) return;
  AliAnalysisManager *mgr = new AliAnalysisManager("AnalysisTaskExample");
  mgr->SetGridHandler(alienH);
  AliAODInputHandler *aodH = new AliAODInputHandler();
  mgr->SetInputEventHandler(aodH);
  cout<<"Memory address of AliAnalysisManager is "<<mgr<<endl;

  gROOT->LoadMacro("AliAnalysisTaskExample.cxx++g");
  gROOT->LoadMacro("AddTaskExample.C");
  AliAnalysisTaskExample *ptr = AddTaskExample();
  if(ptr) cout << "Success!  AddTask = " << ptr << endl;

  int debug = 2;
  mgr->SetDebugLevel(debug);
  if(!mgr->InitAnalysis()) return;
  mgr->PrintStatus();
  mgr->StartAnalysis("grid");

}
