#include <iostream>
#include "AliAnalysisTaskSE.h"
#include "AliAnalysisTaskExample.h"
ClassImp(AliAnalysisTaskExample); // import class inheriting from TObject

#include "TList.h"
#include "TProfile.h"
#include "AliAnalysisManager.h"
#include "AliAODInputHandler.h"
// #include "AliAODEvent.h"
// #include "AliAODVertex.h"
// #include "AliCentrality.h"
// #include "AliAODTrack.h"

using namespace std;



AliAnalysisTaskExample::AliAnalysisTaskExample() : AliAnalysisTaskSE()
{
  cout << "Default class constructor called" << endl;
}



AliAnalysisTaskExample::AliAnalysisTaskExample(const char* name) : AliAnalysisTaskSE(name)
{
  cout << "User defined class constructor called" << endl;
  DefineOutput(1,TList::Class()); // 0 reserved, 1 for user
}



void AliAnalysisTaskExample::UserCreateOutputObjects()
{
  cout << "UserCreateOutputObjects called" << endl;

  // create the output list, set owner to true
  outputlist = new TList();
  outputlist->SetOwner(kTRUE);

  // ------------------------
  // declare the histogram(s)
  // ------------------------

  th1d_cent = new TH1D("th1d_cent","",100,0,100);
  th1d_cent0005 = new TH1D("th1d_cent0005","",100,0,100);
  th1d_cent1020 = new TH1D("th1d_cent1020","",100,0,100);
  th1d_cent3040 = new TH1D("th1d_cent3040","",100,0,100);
  th1d_cent5060 = new TH1D("th1d_cent5060","",100,0,100);
  th1d_cent7080 = new TH1D("th1d_cent7080","",100,0,100);
  outputlist->Add(th1d_cent);
  outputlist->Add(th1d_cent0005);
  outputlist->Add(th1d_cent1020);
  outputlist->Add(th1d_cent3040);
  outputlist->Add(th1d_cent5060);
  outputlist->Add(th1d_cent7080);

  // --- 1d histograms
  th1d_etaP_cent0005 = new TH1D("th1d_etaP_cent0005","",20,-1.0,1.0);
  th1d_etaN_cent0005 = new TH1D("th1d_etaN_cent0005","",20,-1.0,1.0);
  outputlist->Add(th1d_etaP_cent0005);
  outputlist->Add(th1d_etaN_cent0005);
  // --- 2d histograms
  th2d_etaPetaN_cent0005 = new TH2D("th2d_etaPetaN_cent0005","",20,-1.0,1.0,20,-1.0,1.0);
  th2d_etaNetaP_cent0005 = new TH2D("th2d_etaNetaP_cent0005","",20,-1.0,1.0,20,-1.0,1.0);
  th2d_etaPetaP_cent0005 = new TH2D("th2d_etaPetaP_cent0005","",20,-1.0,1.0,20,-1.0,1.0);
  th2d_etaNetaN_cent0005 = new TH2D("th2d_etaNetaN_cent0005","",20,-1.0,1.0,20,-1.0,1.0);
  outputlist->Add(th2d_etaPetaN_cent0005);
  outputlist->Add(th2d_etaNetaP_cent0005);
  outputlist->Add(th2d_etaPetaP_cent0005);
  outputlist->Add(th2d_etaNetaN_cent0005);
  // --- 1d histograms
  th1d_etaP_cent1020 = new TH1D("th1d_etaP_cent1020","",20,-1.0,1.0);
  th1d_etaN_cent1020 = new TH1D("th1d_etaN_cent1020","",20,-1.0,1.0);
  outputlist->Add(th1d_etaP_cent1020);
  outputlist->Add(th1d_etaN_cent1020);
  // --- 2d histograms
  th2d_etaPetaN_cent1020 = new TH2D("th2d_etaPetaN_cent1020","",20,-1.0,1.0,20,-1.0,1.0);
  th2d_etaNetaP_cent1020 = new TH2D("th2d_etaNetaP_cent1020","",20,-1.0,1.0,20,-1.0,1.0);
  th2d_etaPetaP_cent1020 = new TH2D("th2d_etaPetaP_cent1020","",20,-1.0,1.0,20,-1.0,1.0);
  th2d_etaNetaN_cent1020 = new TH2D("th2d_etaNetaN_cent1020","",20,-1.0,1.0,20,-1.0,1.0);
  outputlist->Add(th2d_etaPetaN_cent1020);
  outputlist->Add(th2d_etaNetaP_cent1020);
  outputlist->Add(th2d_etaPetaP_cent1020);
  outputlist->Add(th2d_etaNetaN_cent1020);
  // --- 1d histograms
  th1d_etaP_cent3040 = new TH1D("th1d_etaP_cent3040","",20,-1.0,1.0);
  th1d_etaN_cent3040 = new TH1D("th1d_etaN_cent3040","",20,-1.0,1.0);
  outputlist->Add(th1d_etaP_cent3040);
  outputlist->Add(th1d_etaN_cent3040);
  // --- 2d histograms
  th2d_etaPetaN_cent3040 = new TH2D("th2d_etaPetaN_cent3040","",20,-1.0,1.0,20,-1.0,1.0);
  th2d_etaNetaP_cent3040 = new TH2D("th2d_etaNetaP_cent3040","",20,-1.0,1.0,20,-1.0,1.0);
  th2d_etaPetaP_cent3040 = new TH2D("th2d_etaPetaP_cent3040","",20,-1.0,1.0,20,-1.0,1.0);
  th2d_etaNetaN_cent3040 = new TH2D("th2d_etaNetaN_cent3040","",20,-1.0,1.0,20,-1.0,1.0);
  outputlist->Add(th2d_etaPetaN_cent3040);
  outputlist->Add(th2d_etaNetaP_cent3040);
  outputlist->Add(th2d_etaPetaP_cent3040);
  outputlist->Add(th2d_etaNetaN_cent3040);
  // --- 1d histograms
  th1d_etaP_cent5060 = new TH1D("th1d_etaP_cent5060","",20,-1.0,1.0);
  th1d_etaN_cent5060 = new TH1D("th1d_etaN_cent5060","",20,-1.0,1.0);
  outputlist->Add(th1d_etaP_cent5060);
  outputlist->Add(th1d_etaN_cent5060);
  // --- 2d histograms
  th2d_etaPetaN_cent5060 = new TH2D("th2d_etaPetaN_cent5060","",20,-1.0,1.0,20,-1.0,1.0);
  th2d_etaNetaP_cent5060 = new TH2D("th2d_etaNetaP_cent5060","",20,-1.0,1.0,20,-1.0,1.0);
  th2d_etaPetaP_cent5060 = new TH2D("th2d_etaPetaP_cent5060","",20,-1.0,1.0,20,-1.0,1.0);
  th2d_etaNetaN_cent5060 = new TH2D("th2d_etaNetaN_cent5060","",20,-1.0,1.0,20,-1.0,1.0);
  outputlist->Add(th2d_etaPetaN_cent5060);
  outputlist->Add(th2d_etaNetaP_cent5060);
  outputlist->Add(th2d_etaPetaP_cent5060);
  outputlist->Add(th2d_etaNetaN_cent5060);
  // --- 1d histograms
  th1d_etaP_cent7080 = new TH1D("th1d_etaP_cent7080","",20,-1.0,1.0);
  th1d_etaN_cent7080 = new TH1D("th1d_etaN_cent7080","",20,-1.0,1.0);
  outputlist->Add(th1d_etaP_cent7080);
  outputlist->Add(th1d_etaN_cent7080);
  // --- 2d histograms
  th2d_etaPetaN_cent7080 = new TH2D("th2d_etaPetaN_cent7080","",20,-1.0,1.0,20,-1.0,1.0);
  th2d_etaNetaP_cent7080 = new TH2D("th2d_etaNetaP_cent7080","",20,-1.0,1.0,20,-1.0,1.0);
  th2d_etaPetaP_cent7080 = new TH2D("th2d_etaPetaP_cent7080","",20,-1.0,1.0,20,-1.0,1.0);
  th2d_etaNetaN_cent7080 = new TH2D("th2d_etaNetaN_cent7080","",20,-1.0,1.0,20,-1.0,1.0);
  outputlist->Add(th2d_etaPetaN_cent7080);
  outputlist->Add(th2d_etaNetaP_cent7080);
  outputlist->Add(th2d_etaPetaP_cent7080);
  outputlist->Add(th2d_etaNetaN_cent7080);


  float tpmax = 1e10;
  float tpmin = -1e10;

  // --- average charge method, 39 bins

  h_AT_X_deta_cent0005 = new TProfile("h_AT_X_deta_cent0005","",39,-2.0,2.0,tpmin,tpmax,"");
  h_AT_X_detaP_cent0005 = new TProfile("h_AT_X_detaP_cent0005","",39,-2.0,2.0,tpmin,tpmax,"");
  h_AT_X_detaN_cent0005 = new TProfile("h_AT_X_detaN_cent0005","",39,-2.0,2.0,tpmin,tpmax,"");
  outputlist->Add(h_AT_X_deta_cent0005);
  outputlist->Add(h_AT_X_detaP_cent0005);
  outputlist->Add(h_AT_X_detaN_cent0005);

  h_AT_X_deta_cent1020 = new TProfile("h_AT_X_deta_cent1020","",39,-2.0,2.0,tpmin,tpmax,"");
  h_AT_X_detaP_cent1020 = new TProfile("h_AT_X_detaP_cent1020","",39,-2.0,2.0,tpmin,tpmax,"");
  h_AT_X_detaN_cent1020 = new TProfile("h_AT_X_detaN_cent1020","",39,-2.0,2.0,tpmin,tpmax,"");
  outputlist->Add(h_AT_X_deta_cent1020);
  outputlist->Add(h_AT_X_detaP_cent1020);
  outputlist->Add(h_AT_X_detaN_cent1020);

  h_AT_X_deta_cent3040 = new TProfile("h_AT_X_deta_cent3040","",39,-2.0,2.0,tpmin,tpmax,"");
  h_AT_X_detaP_cent3040 = new TProfile("h_AT_X_detaP_cent3040","",39,-2.0,2.0,tpmin,tpmax,"");
  h_AT_X_detaN_cent3040 = new TProfile("h_AT_X_detaN_cent3040","",39,-2.0,2.0,tpmin,tpmax,"");
  outputlist->Add(h_AT_X_deta_cent3040);
  outputlist->Add(h_AT_X_detaP_cent3040);
  outputlist->Add(h_AT_X_detaN_cent3040);

  h_AT_X_deta_cent5060 = new TProfile("h_AT_X_deta_cent5060","",39,-2.0,2.0,tpmin,tpmax,"");
  h_AT_X_detaP_cent5060 = new TProfile("h_AT_X_detaP_cent5060","",39,-2.0,2.0,tpmin,tpmax,"");
  h_AT_X_detaN_cent5060 = new TProfile("h_AT_X_detaN_cent5060","",39,-2.0,2.0,tpmin,tpmax,"");
  outputlist->Add(h_AT_X_deta_cent5060);
  outputlist->Add(h_AT_X_detaP_cent5060);
  outputlist->Add(h_AT_X_detaN_cent5060);

  h_AT_X_deta_cent7080 = new TProfile("h_AT_X_deta_cent7080","",39,-2.0,2.0,tpmin,tpmax,"");
  h_AT_X_detaP_cent7080 = new TProfile("h_AT_X_detaP_cent7080","",39,-2.0,2.0,tpmin,tpmax,"");
  h_AT_X_detaN_cent7080 = new TProfile("h_AT_X_detaN_cent7080","",39,-2.0,2.0,tpmin,tpmax,"");
  outputlist->Add(h_AT_X_deta_cent7080);
  outputlist->Add(h_AT_X_detaP_cent7080);
  outputlist->Add(h_AT_X_detaN_cent7080);



  // --- charge covariance method, 39 bins

  h_q1q3_X_deta_cent0005 = new TProfile("h_q1q3_X_deta_cent0005","",39,-2.0,2.0,tpmin,tpmax,"");
  h_q1_X_deta_cent0005 = new TProfile("h_q1_X_deta_cent0005","",39,-2.0,2.0,tpmin,tpmax,"");
  h_q3_X_deta_cent0005 = new TProfile("h_q3_X_deta_cent0005","",39,-2.0,2.0,tpmin,tpmax,"");
  outputlist->Add(h_q1q3_X_deta_cent0005);
  outputlist->Add(h_q1_X_deta_cent0005);
  outputlist->Add(h_q3_X_deta_cent0005);

  h_q1q3_X_deta_cent1020 = new TProfile("h_q1q3_X_deta_cent1020","",39,-2.0,2.0,tpmin,tpmax,"");
  h_q1_X_deta_cent1020 = new TProfile("h_q1_X_deta_cent1020","",39,-2.0,2.0,tpmin,tpmax,"");
  h_q3_X_deta_cent1020 = new TProfile("h_q3_X_deta_cent1020","",39,-2.0,2.0,tpmin,tpmax,"");
  outputlist->Add(h_q1q3_X_deta_cent1020);
  outputlist->Add(h_q1_X_deta_cent1020);
  outputlist->Add(h_q3_X_deta_cent1020);

  h_q1q3_X_deta_cent3040 = new TProfile("h_q1q3_X_deta_cent3040","",39,-2.0,2.0,tpmin,tpmax,"");
  h_q1_X_deta_cent3040 = new TProfile("h_q1_X_deta_cent3040","",39,-2.0,2.0,tpmin,tpmax,"");
  h_q3_X_deta_cent3040 = new TProfile("h_q3_X_deta_cent3040","",39,-2.0,2.0,tpmin,tpmax,"");
  outputlist->Add(h_q1q3_X_deta_cent3040);
  outputlist->Add(h_q1_X_deta_cent3040);
  outputlist->Add(h_q3_X_deta_cent3040);

  h_q1q3_X_deta_cent5060 = new TProfile("h_q1q3_X_deta_cent5060","",39,-2.0,2.0,tpmin,tpmax,"");
  h_q1_X_deta_cent5060 = new TProfile("h_q1_X_deta_cent5060","",39,-2.0,2.0,tpmin,tpmax,"");
  h_q3_X_deta_cent5060 = new TProfile("h_q3_X_deta_cent5060","",39,-2.0,2.0,tpmin,tpmax,"");
  outputlist->Add(h_q1q3_X_deta_cent5060);
  outputlist->Add(h_q1_X_deta_cent5060);
  outputlist->Add(h_q3_X_deta_cent5060);

  h_q1q3_X_deta_cent7080 = new TProfile("h_q1q3_X_deta_cent7080","",39,-2.0,2.0,tpmin,tpmax,"");
  h_q1_X_deta_cent7080 = new TProfile("h_q1_X_deta_cent7080","",39,-2.0,2.0,tpmin,tpmax,"");
  h_q3_X_deta_cent7080 = new TProfile("h_q3_X_deta_cent7080","",39,-2.0,2.0,tpmin,tpmax,"");
  outputlist->Add(h_q1q3_X_deta_cent7080);
  outputlist->Add(h_q1_X_deta_cent7080);
  outputlist->Add(h_q3_X_deta_cent7080);



  // --- average charge method, 50 bins

  h_AT_Y_deta_cent0005 = new TProfile("h_AT_Y_deta_cent0005","",50,-2.0,2.0,tpmin,tpmax,"");
  h_AT_Y_detaP_cent0005 = new TProfile("h_AT_Y_detaP_cent0005","",50,-2.0,2.0,tpmin,tpmax,"");
  h_AT_Y_detaN_cent0005 = new TProfile("h_AT_Y_detaN_cent0005","",50,-2.0,2.0,tpmin,tpmax,"");
  outputlist->Add(h_AT_Y_deta_cent0005);
  outputlist->Add(h_AT_Y_detaP_cent0005);
  outputlist->Add(h_AT_Y_detaN_cent0005);

  h_AT_Y_deta_cent1020 = new TProfile("h_AT_Y_deta_cent1020","",50,-2.0,2.0,tpmin,tpmax,"");
  h_AT_Y_detaP_cent1020 = new TProfile("h_AT_Y_detaP_cent1020","",50,-2.0,2.0,tpmin,tpmax,"");
  h_AT_Y_detaN_cent1020 = new TProfile("h_AT_Y_detaN_cent1020","",50,-2.0,2.0,tpmin,tpmax,"");
  outputlist->Add(h_AT_Y_deta_cent1020);
  outputlist->Add(h_AT_Y_detaP_cent1020);
  outputlist->Add(h_AT_Y_detaN_cent1020);

  h_AT_Y_deta_cent3040 = new TProfile("h_AT_Y_deta_cent3040","",50,-2.0,2.0,tpmin,tpmax,"");
  h_AT_Y_detaP_cent3040 = new TProfile("h_AT_Y_detaP_cent3040","",50,-2.0,2.0,tpmin,tpmax,"");
  h_AT_Y_detaN_cent3040 = new TProfile("h_AT_Y_detaN_cent3040","",50,-2.0,2.0,tpmin,tpmax,"");
  outputlist->Add(h_AT_Y_deta_cent3040);
  outputlist->Add(h_AT_Y_detaP_cent3040);
  outputlist->Add(h_AT_Y_detaN_cent3040);

  h_AT_Y_deta_cent5060 = new TProfile("h_AT_Y_deta_cent5060","",50,-2.0,2.0,tpmin,tpmax,"");
  h_AT_Y_detaP_cent5060 = new TProfile("h_AT_Y_detaP_cent5060","",50,-2.0,2.0,tpmin,tpmax,"");
  h_AT_Y_detaN_cent5060 = new TProfile("h_AT_Y_detaN_cent5060","",50,-2.0,2.0,tpmin,tpmax,"");
  outputlist->Add(h_AT_Y_deta_cent5060);
  outputlist->Add(h_AT_Y_detaP_cent5060);
  outputlist->Add(h_AT_Y_detaN_cent5060);

  h_AT_Y_deta_cent7080 = new TProfile("h_AT_Y_deta_cent7080","",50,-2.0,2.0,tpmin,tpmax,"");
  h_AT_Y_detaP_cent7080 = new TProfile("h_AT_Y_detaP_cent7080","",50,-2.0,2.0,tpmin,tpmax,"");
  h_AT_Y_detaN_cent7080 = new TProfile("h_AT_Y_detaN_cent7080","",50,-2.0,2.0,tpmin,tpmax,"");
  outputlist->Add(h_AT_Y_deta_cent7080);
  outputlist->Add(h_AT_Y_detaP_cent7080);
  outputlist->Add(h_AT_Y_detaN_cent7080);



  // --- charge covariance method, 50 bins

  h_q1q3_Y_deta_cent0005 = new TProfile("h_q1q3_Y_deta_cent0005","",50,-2.0,2.0,tpmin,tpmax,"");
  h_q1_Y_deta_cent0005 = new TProfile("h_q1_Y_deta_cent0005","",50,-2.0,2.0,tpmin,tpmax,"");
  h_q3_Y_deta_cent0005 = new TProfile("h_q3_Y_deta_cent0005","",50,-2.0,2.0,tpmin,tpmax,"");
  outputlist->Add(h_q1q3_Y_deta_cent0005);
  outputlist->Add(h_q1_Y_deta_cent0005);
  outputlist->Add(h_q3_Y_deta_cent0005);

  h_q1q3_Y_deta_cent1020 = new TProfile("h_q1q3_Y_deta_cent1020","",50,-2.0,2.0,tpmin,tpmax,"");
  h_q1_Y_deta_cent1020 = new TProfile("h_q1_Y_deta_cent1020","",50,-2.0,2.0,tpmin,tpmax,"");
  h_q3_Y_deta_cent1020 = new TProfile("h_q3_Y_deta_cent1020","",50,-2.0,2.0,tpmin,tpmax,"");
  outputlist->Add(h_q1q3_Y_deta_cent1020);
  outputlist->Add(h_q1_Y_deta_cent1020);
  outputlist->Add(h_q3_Y_deta_cent1020);

  h_q1q3_Y_deta_cent3040 = new TProfile("h_q1q3_Y_deta_cent3040","",50,-2.0,2.0,tpmin,tpmax,"");
  h_q1_Y_deta_cent3040 = new TProfile("h_q1_Y_deta_cent3040","",50,-2.0,2.0,tpmin,tpmax,"");
  h_q3_Y_deta_cent3040 = new TProfile("h_q3_Y_deta_cent3040","",50,-2.0,2.0,tpmin,tpmax,"");
  outputlist->Add(h_q1q3_Y_deta_cent3040);
  outputlist->Add(h_q1_Y_deta_cent3040);
  outputlist->Add(h_q3_Y_deta_cent3040);

  h_q1q3_Y_deta_cent5060 = new TProfile("h_q1q3_Y_deta_cent5060","",50,-2.0,2.0,tpmin,tpmax,"");
  h_q1_Y_deta_cent5060 = new TProfile("h_q1_Y_deta_cent5060","",50,-2.0,2.0,tpmin,tpmax,"");
  h_q3_Y_deta_cent5060 = new TProfile("h_q3_Y_deta_cent5060","",50,-2.0,2.0,tpmin,tpmax,"");
  outputlist->Add(h_q1q3_Y_deta_cent5060);
  outputlist->Add(h_q1_Y_deta_cent5060);
  outputlist->Add(h_q3_Y_deta_cent5060);

  h_q1q3_Y_deta_cent7080 = new TProfile("h_q1q3_Y_deta_cent7080","",50,-2.0,2.0,tpmin,tpmax,"");
  h_q1_Y_deta_cent7080 = new TProfile("h_q1_Y_deta_cent7080","",50,-2.0,2.0,tpmin,tpmax,"");
  h_q3_Y_deta_cent7080 = new TProfile("h_q3_Y_deta_cent7080","",50,-2.0,2.0,tpmin,tpmax,"");
  outputlist->Add(h_q1q3_Y_deta_cent7080);
  outputlist->Add(h_q1_Y_deta_cent7080);
  outputlist->Add(h_q3_Y_deta_cent7080);



  // write the TList to the output file
  PostData(1,outputlist); // recall 1 from constructor
}



void AliAnalysisTaskExample::UserExec(Option_t*)
{
  // event processing

  // get the analysis manager, need to get the input handler
  AliAnalysisManager *manager = AliAnalysisManager::GetAnalysisManager();
  if(manager==NULL)
    {
      cout << "AnalysisManager returned null, skipping event" << endl;
      return;
    }

  // get the input handler, useful for getting things like the trigger mask
  AliAODInputHandler *handler = (AliAODInputHandler *)manager->GetInputEventHandler();
  if(handler==NULL)
    {
      cout << "InputEventHandler returned null, skipping event" << endl;
      return;
    }

  AliAODEvent *fAOD = (AliAODEvent *)InputEvent();
  if(fAOD==NULL)
    {
      cout << "AOD event object not available, skipping event" << endl;
      return;
    }

  // get the trigger mask and selec the trigger
  ULong64_t mask = handler->IsEventSelected();
  ULong64_t amb = AliVEvent::kMB;
  if(mask&amb==0) return; // trigger selection (MB only)



  // get the vertex object
  // can use either one, up to the user to decide details of analysis
  //AliAODVertex *fVtx = fAOD->GetPrimaryVertexSPD();
  AliAODVertex *fVtx = fAOD->GetPrimaryVertex();
  float zvtx = fVtx->GetZ(); // z-coordinate of vertex
  if(fabs(zvtx>10.0)) return; // 10cm z-vertex cut



  // get the centrality object
  AliCentrality *fCentrality = fAOD->GetCentrality();
  // V0M meants V0 multiplicity (sum of A+C sides)
  // also available are TRK (TPC multiplicity), CL1, etc...
  float centV0M = fCentrality->GetCentralityPercentile("V0M");

  th1d_cent->Fill(centV0M);
  int centflag = 0;
  if(centV0M>0  &&  centV0M<5) centflag = 1;
  if(centV0M>10 && centV0M<20) centflag = 2;
  if(centV0M>30 && centV0M<40) centflag = 3;
  if(centV0M>50 && centV0M<60) centflag = 4;
  if(centV0M>70 && centV0M<80) centflag = 5;

  if(centflag == 0) return;

  if(centflag==1) th1d_cent0005->Fill(centV0M);
  if(centflag==2) th1d_cent1020->Fill(centV0M);
  if(centflag==3) th1d_cent3040->Fill(centV0M);
  if(centflag==4) th1d_cent5060->Fill(centV0M);
  if(centflag==5) th1d_cent7080->Fill(centV0M);


  // get the number of tracks and start the track loop
  int d_ntrk = fAOD->GetNumberOfTracks();
  float pt3[d_ntrk];
  float eta3[d_ntrk];
  float phi3[d_ntrk];
  int charge3[d_ntrk];
  for(int i=0; i<d_ntrk; i++)
    {
      pt3[i] = -99;
      eta3[i] = -99;
      phi3[i] = -99;
      charge3[i] = 0;
    }
  for(int itrk = 0; itrk<d_ntrk; itrk++)
    {
      // get the track object
      AliAODTrack *track = (AliAODTrack *)fAOD->GetTrack(itrk);
      if(track==NULL) continue;

      // select filter bit (1 means global tracks)
      if(!track->TestFilterBit(1)) continue;



      float pt = track->Pt();
      float phi = track->Phi();
      float eta = track->Eta();
      int charge = (int)track->Charge();

      if(charge==0) continue;
      if(pt<0.2||pt>2.0) continue;
      if(fabs(eta)>1.0) continue;

      pt3[itrk] = pt;
      eta3[itrk] = eta;
      phi3[itrk] = phi;
      charge3[itrk] = charge;
    }

  for(int itrk = 0; itrk<d_ntrk; itrk++)
    {
      // get the track object
      AliAODTrack *track = (AliAODTrack *)fAOD->GetTrack(itrk);
      if(track==NULL) continue;

      // select filter bit (1 means global tracks)
      if(!track->TestFilterBit(1)) continue;

      float pt = track->Pt();
      float phi = track->Phi();
      float eta = track->Eta();
      int charge = track->Charge();

      if(pt<0.2||pt>2.0) continue;
      if(fabs(eta)>1.0) continue;

      if(charge>0 && centflag==1) th1d_etaP_cent0005->Fill(eta); // eta for pos only
      if(charge<0 && centflag==1) th1d_etaN_cent0005->Fill(eta); // eta for neg only
      if(charge>0 && centflag==2) th1d_etaP_cent1020->Fill(eta); // eta for pos only
      if(charge<0 && centflag==2) th1d_etaN_cent1020->Fill(eta); // eta for neg only
      if(charge>0 && centflag==3) th1d_etaP_cent3040->Fill(eta); // eta for pos only
      if(charge<0 && centflag==3) th1d_etaN_cent3040->Fill(eta); // eta for neg only
      if(charge>0 && centflag==4) th1d_etaP_cent5060->Fill(eta); // eta for pos only
      if(charge<0 && centflag==4) th1d_etaN_cent5060->Fill(eta); // eta for neg only
      if(charge>0 && centflag==5) th1d_etaP_cent7080->Fill(eta); // eta for pos only
      if(charge<0 && centflag==5) th1d_etaN_cent7080->Fill(eta); // eta for neg only

      for(int i=0; i<d_ntrk; i++)
	{
	  if(fabs(eta3[i]>1.0)) continue;
	  if(charge3[i]==0) continue;
	  if(pt3[i]<0.2||pt3[i]>2.0) continue;
	  if(i==itrk) continue; // auto-correlations

	  float DETA = eta-eta3[i];
	  float DPHI = phi-phi3[i];
	  float DPT = pt-pt3[i];

	  bool pos = charge>0.0;
	  bool neg = charge<0.0;

	  // ---
	  int charge1 = charge;
	  int charge2 = charge3[i];
	  float eta1 = eta;
	  float eta2 = eta3[i];


	  if(centflag == 1)
	    {
	      h_AT_X_deta_cent0005->Fill(DETA,charge3[i]);
	      if(pos) h_AT_X_detaP_cent0005->Fill(DETA,charge3[i]);
	      if(neg) h_AT_X_detaN_cent0005->Fill(DETA,charge3[i]);
	      h_AT_Y_deta_cent0005->Fill(DETA,charge3[i]);
	      if(pos) h_AT_Y_detaP_cent0005->Fill(DETA,charge3[i]);
	      if(neg) h_AT_Y_detaN_cent0005->Fill(DETA,charge3[i]);
	      // ---
	      h_q1q3_X_deta_cent0005->Fill(DETA,charge*charge3[i]);
	      h_q1_X_deta_cent0005->Fill(DETA,charge);
	      h_q3_X_deta_cent0005->Fill(DETA,charge3[i]);
	      h_q1q3_Y_deta_cent0005->Fill(DETA,charge*charge3[i]);
	      h_q1_Y_deta_cent0005->Fill(DETA,charge);
	      h_q3_Y_deta_cent0005->Fill(DETA,charge3[i]);
	      // --- PN
	      if(charge1>0&&charge2<0) th2d_etaPetaN_cent0005->Fill(eta1,eta2);
	      // --- NP
	      if(charge1<0&&charge2>0) th2d_etaNetaP_cent0005->Fill(eta1,eta2);
	      // --- PP
	      if(charge1>0&&charge2>0) th2d_etaPetaP_cent0005->Fill(eta1,eta2);
	      // --- NN
	      if(charge1<0&&charge2<0) th2d_etaNetaN_cent0005->Fill(eta1,eta2);
	    }
	  if(centflag == 2)
	    {
	      h_AT_X_deta_cent1020->Fill(DETA,charge3[i]);
	      if(pos) h_AT_X_detaP_cent1020->Fill(DETA,charge3[i]);
	      if(neg) h_AT_X_detaN_cent1020->Fill(DETA,charge3[i]);
	      h_AT_Y_deta_cent1020->Fill(DETA,charge3[i]);
	      if(pos) h_AT_Y_detaP_cent1020->Fill(DETA,charge3[i]);
	      if(neg) h_AT_Y_detaN_cent1020->Fill(DETA,charge3[i]);
	      // ---
	      h_q1q3_X_deta_cent1020->Fill(DETA,charge*charge3[i]);
	      h_q1_X_deta_cent1020->Fill(DETA,charge);
	      h_q3_X_deta_cent1020->Fill(DETA,charge3[i]);
	      h_q1q3_Y_deta_cent1020->Fill(DETA,charge*charge3[i]);
	      h_q1_Y_deta_cent1020->Fill(DETA,charge);
	      h_q3_Y_deta_cent1020->Fill(DETA,charge3[i]);
	      // --- PN
	      if(charge1>0&&charge2<0) th2d_etaPetaN_cent1020->Fill(eta1,eta2);
	      // --- NP
	      if(charge1<0&&charge2>0) th2d_etaNetaP_cent1020->Fill(eta1,eta2);
	      // --- PP
	      if(charge1>0&&charge2>0) th2d_etaPetaP_cent1020->Fill(eta1,eta2);
	      // --- NN
	      if(charge1<0&&charge2<0) th2d_etaNetaN_cent1020->Fill(eta1,eta2);
	    }
	  if(centflag == 3)
	    {
	      h_AT_X_deta_cent3040->Fill(DETA,charge3[i]);
	      if(pos) h_AT_X_detaP_cent3040->Fill(DETA,charge3[i]);
	      if(neg) h_AT_X_detaN_cent3040->Fill(DETA,charge3[i]);
	      h_AT_Y_deta_cent3040->Fill(DETA,charge3[i]);
	      if(pos) h_AT_Y_detaP_cent3040->Fill(DETA,charge3[i]);
	      if(neg) h_AT_Y_detaN_cent3040->Fill(DETA,charge3[i]);
	      // ---
	      h_q1q3_X_deta_cent3040->Fill(DETA,charge*charge3[i]);
	      h_q1_X_deta_cent3040->Fill(DETA,charge);
	      h_q3_X_deta_cent3040->Fill(DETA,charge3[i]);
	      h_q1q3_Y_deta_cent3040->Fill(DETA,charge*charge3[i]);
	      h_q1_Y_deta_cent3040->Fill(DETA,charge);
	      h_q3_Y_deta_cent3040->Fill(DETA,charge3[i]);
	      // --- PN
	      if(charge1>0&&charge2<0) th2d_etaPetaN_cent3040->Fill(eta1,eta2);
	      // --- NP
	      if(charge1<0&&charge2>0) th2d_etaNetaP_cent3040->Fill(eta1,eta2);
	      // --- PP
	      if(charge1>0&&charge2>0) th2d_etaPetaP_cent3040->Fill(eta1,eta2);
	      // --- NN
	      if(charge1<0&&charge2<0) th2d_etaNetaN_cent3040->Fill(eta1,eta2);
	    }
	  if(centflag == 4)
	    {
	      h_AT_X_deta_cent5060->Fill(DETA,charge3[i]);
	      if(pos) h_AT_X_detaP_cent5060->Fill(DETA,charge3[i]);
	      if(neg) h_AT_X_detaN_cent5060->Fill(DETA,charge3[i]);
	      h_AT_Y_deta_cent5060->Fill(DETA,charge3[i]);
	      if(pos) h_AT_Y_detaP_cent5060->Fill(DETA,charge3[i]);
	      if(neg) h_AT_Y_detaN_cent5060->Fill(DETA,charge3[i]);
	      // ---
	      h_q1q3_X_deta_cent5060->Fill(DETA,charge*charge3[i]);
	      h_q1_X_deta_cent5060->Fill(DETA,charge);
	      h_q3_X_deta_cent5060->Fill(DETA,charge3[i]);
	      h_q1q3_Y_deta_cent5060->Fill(DETA,charge*charge3[i]);
	      h_q1_Y_deta_cent5060->Fill(DETA,charge);
	      h_q3_Y_deta_cent5060->Fill(DETA,charge3[i]);
	      // --- PN
	      if(charge1>0&&charge2<0) th2d_etaPetaN_cent5060->Fill(eta1,eta2);
	      // --- NP
	      if(charge1<0&&charge2>0) th2d_etaNetaP_cent5060->Fill(eta1,eta2);
	      // --- PP
	      if(charge1>0&&charge2>0) th2d_etaPetaP_cent5060->Fill(eta1,eta2);
	      // --- NN
	      if(charge1<0&&charge2<0) th2d_etaNetaN_cent5060->Fill(eta1,eta2);
	    }
	  if(centflag == 5)
	    {
	      h_AT_X_deta_cent7080->Fill(DETA,charge3[i]);
	      if(pos) h_AT_X_detaP_cent7080->Fill(DETA,charge3[i]);
	      if(neg) h_AT_X_detaN_cent7080->Fill(DETA,charge3[i]);
	      h_AT_Y_deta_cent7080->Fill(DETA,charge3[i]);
	      if(pos) h_AT_Y_detaP_cent7080->Fill(DETA,charge3[i]);
	      if(neg) h_AT_Y_detaN_cent7080->Fill(DETA,charge3[i]);
	      // ---
	      h_q1q3_X_deta_cent7080->Fill(DETA,charge*charge3[i]);
	      h_q1_X_deta_cent7080->Fill(DETA,charge);
	      h_q3_X_deta_cent7080->Fill(DETA,charge3[i]);
	      h_q1q3_Y_deta_cent7080->Fill(DETA,charge*charge3[i]);
	      h_q1_Y_deta_cent7080->Fill(DETA,charge);
	      h_q3_Y_deta_cent7080->Fill(DETA,charge3[i]);
	      // --- PN
	      if(charge1>0&&charge2<0) th2d_etaPetaN_cent7080->Fill(eta1,eta2);
	      // --- NP
	      if(charge1<0&&charge2>0) th2d_etaNetaP_cent7080->Fill(eta1,eta2);
	      // --- PP
	      if(charge1>0&&charge2>0) th2d_etaPetaP_cent7080->Fill(eta1,eta2);
	      // --- NN
	      if(charge1<0&&charge2<0) th2d_etaNetaN_cent7080->Fill(eta1,eta2);
	    }

	  // ---

	} // nested loop

    } // second main loop

} // UserExec
