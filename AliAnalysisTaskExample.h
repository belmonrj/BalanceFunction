#ifndef AliAnalysisTaskExample_cxx
#define AliAnalysisTaskExample_cxx

class AliAnalysisTaskExample : public AliAnalysisTaskSE
{

 public:

  AliAnalysisTaskExample();
  AliAnalysisTaskExample(const char*);
  virtual ~AliAnalysisTaskExample() {}
  virtual void UserCreateOutputObjects();
  virtual void UserExec(Option_t*);
  ClassDef(AliAnalysisTaskExample,1);

 private:

  TList *outputlist;//!
  // ---
  TH1D *th1d_cent;//!
  TH1D *th1d_cent0005;//!
  TH1D *th1d_cent1020;//!
  TH1D *th1d_cent3040;//!
  TH1D *th1d_cent5060;//!
  TH1D *th1d_cent7080;//!
  // ---
  TH1D *th1d_etaP_cent0005;//!
  TH1D *th1d_etaN_cent0005;//!
  TH2D *th2d_etaPetaN_cent0005;//!
  TH2D *th2d_etaNetaP_cent0005;//!
  TH2D *th2d_etaPetaP_cent0005;//!
  TH2D *th2d_etaNetaN_cent0005;//!
  // ---
  TH1D *th1d_etaP_cent1020;//!
  TH1D *th1d_etaN_cent1020;//!
  TH2D *th2d_etaPetaN_cent1020;//!
  TH2D *th2d_etaNetaP_cent1020;//!
  TH2D *th2d_etaPetaP_cent1020;//!
  TH2D *th2d_etaNetaN_cent1020;//!
  // ---
  TH1D *th1d_etaP_cent3040;//!
  TH1D *th1d_etaN_cent3040;//!
  TH2D *th2d_etaPetaN_cent3040;//!
  TH2D *th2d_etaNetaP_cent3040;//!
  TH2D *th2d_etaPetaP_cent3040;//!
  TH2D *th2d_etaNetaN_cent3040;//!
  // ---
  TH1D *th1d_etaP_cent5060;//!
  TH1D *th1d_etaN_cent5060;//!
  TH2D *th2d_etaPetaN_cent5060;//!
  TH2D *th2d_etaNetaP_cent5060;//!
  TH2D *th2d_etaPetaP_cent5060;//!
  TH2D *th2d_etaNetaN_cent5060;//!
  // ---
  TH1D *th1d_etaP_cent7080;//!
  TH1D *th1d_etaN_cent7080;//!
  TH2D *th2d_etaPetaN_cent7080;//!
  TH2D *th2d_etaNetaP_cent7080;//!
  TH2D *th2d_etaPetaP_cent7080;//!
  TH2D *th2d_etaNetaN_cent7080;//!
  // ---
  TProfile *h_AT_X_deta_cent0005;//!
  TProfile *h_AT_X_detaP_cent0005;//!
  TProfile *h_AT_X_detaN_cent0005;//!
  TProfile *h_AT_X_deta_cent1020;//!
  TProfile *h_AT_X_detaP_cent1020;//!
  TProfile *h_AT_X_detaN_cent1020;//!
  TProfile *h_AT_X_deta_cent3040;//!
  TProfile *h_AT_X_detaP_cent3040;//!
  TProfile *h_AT_X_detaN_cent3040;//!
  TProfile *h_AT_X_deta_cent5060;//!
  TProfile *h_AT_X_detaP_cent5060;//!
  TProfile *h_AT_X_detaN_cent5060;//!
  TProfile *h_AT_X_deta_cent7080;//!
  TProfile *h_AT_X_detaP_cent7080;//!
  TProfile *h_AT_X_detaN_cent7080;//!
  // ---
  TProfile *h_q1q3_X_deta_cent0005;//!
  TProfile *h_q1_X_deta_cent0005;//!
  TProfile *h_q3_X_deta_cent0005;//!
  TProfile *h_q1q3_X_deta_cent1020;//!
  TProfile *h_q1_X_deta_cent1020;//!
  TProfile *h_q3_X_deta_cent1020;//!
  TProfile *h_q1q3_X_deta_cent3040;//!
  TProfile *h_q1_X_deta_cent3040;//!
  TProfile *h_q3_X_deta_cent3040;//!
  TProfile *h_q1q3_X_deta_cent5060;//!
  TProfile *h_q1_X_deta_cent5060;//!
  TProfile *h_q3_X_deta_cent5060;//!
  TProfile *h_q1q3_X_deta_cent7080;//!
  TProfile *h_q1_X_deta_cent7080;//!
  TProfile *h_q3_X_deta_cent7080;//!
  // ---
  TProfile *h_AT_Y_deta_cent0005;//!
  TProfile *h_AT_Y_detaP_cent0005;//!
  TProfile *h_AT_Y_detaN_cent0005;//!
  TProfile *h_AT_Y_deta_cent1020;//!
  TProfile *h_AT_Y_detaP_cent1020;//!
  TProfile *h_AT_Y_detaN_cent1020;//!
  TProfile *h_AT_Y_deta_cent3040;//!
  TProfile *h_AT_Y_detaP_cent3040;//!
  TProfile *h_AT_Y_detaN_cent3040;//!
  TProfile *h_AT_Y_deta_cent5060;//!
  TProfile *h_AT_Y_detaP_cent5060;//!
  TProfile *h_AT_Y_detaN_cent5060;//!
  TProfile *h_AT_Y_deta_cent7080;//!
  TProfile *h_AT_Y_detaP_cent7080;//!
  TProfile *h_AT_Y_detaN_cent7080;//!
  // ---
  TProfile *h_q1q3_Y_deta_cent0005;//!
  TProfile *h_q1_Y_deta_cent0005;//!
  TProfile *h_q3_Y_deta_cent0005;//!
  TProfile *h_q1q3_Y_deta_cent1020;//!
  TProfile *h_q1_Y_deta_cent1020;//!
  TProfile *h_q3_Y_deta_cent1020;//!
  TProfile *h_q1q3_Y_deta_cent3040;//!
  TProfile *h_q1_Y_deta_cent3040;//!
  TProfile *h_q3_Y_deta_cent3040;//!
  TProfile *h_q1q3_Y_deta_cent5060;//!
  TProfile *h_q1_Y_deta_cent5060;//!
  TProfile *h_q3_Y_deta_cent5060;//!
  TProfile *h_q1q3_Y_deta_cent7080;//!
  TProfile *h_q1_Y_deta_cent7080;//!
  TProfile *h_q3_Y_deta_cent7080;//!

};

#endif
