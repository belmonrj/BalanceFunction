void CalculateCharge_AlisBinning()
{

  TFile *file = TFile::Open("OutExample.root");
  TList *list = (TList *)file->Get("ListExample");

  // Nch
  double dndy_c0005 = 2373/2.0;
  double dndy_c3040 =  603/2.0;
  double dndy_c7080 =   45/2.0;

  DoCalculationAverage(list,"0005",dndy_c0005);
  DoCalculationAverage(list,"3040",dndy_c3040);
  DoCalculationAverage(list,"7080",dndy_c7080);

  DoCalculationCovariance(list,"0005",dndy_c0005);
  DoCalculationCovariance(list,"3040",dndy_c3040);
  DoCalculationCovariance(list,"7080",dndy_c7080);

}



void DoCalculationAverage(TList *list, char *centstring, double mult)
{
  TProfile *tp_xb = (TProfile *)list->FindObject(Form("h_AT_Y_deta_cent%s",centstring));
  TProfile *tp_xp = (TProfile *)list->FindObject(Form("h_AT_Y_detaP_cent%s",centstring));
  TProfile *tp_xn = (TProfile *)list->FindObject(Form("h_AT_Y_detaN_cent%s",centstring));
  TH1D *th1d_xb = tp_xb->ProjectionX();
  TH1D *th1d_xp = tp_xp->ProjectionX();
  TH1D *th1d_xn = tp_xn->ProjectionX();
  TH1D *th1d_xa = (TH1D *)th1d_xp->Clone();
  th1d_xa->Add(th1d_xn);
  th1d_xa->Scale(0.5);
  th1d_xa->Divide(th1d_xb);
  th1d_xa->SetLineColor(kBlack);
  th1d_xa->Draw();
  c1->Print(Form("FigChargeAveAlisRatio_c%s.png",centstring));
  c1->Clear();
  th1d_xp->Add(th1d_xb,-1);
  th1d_xn->Add(th1d_xb,-1);
  TF1 *fun = new TF1("fun","pol0",-2,2);
  fun->SetParameter(0,1);
  th1d_xp->Multiply(fun,-1);
  th1d_xp->SetLineColor(kRed);
  th1d_xp->Draw();
  th1d_xn->SetLineColor(kBlue);
  th1d_xn->Draw("same");
  c1->Print(Form("FigChargeAveAlisComparison_c%s.png",centstring));
  th1d_xp->Add(th1d_xn);
  th1d_xp->Scale(0.5); // must average pos and neg
  th1d_xp->Draw();
  c1->Print(Form("FigChargeAveAlis_c%s.png",centstring));
  ofstream fout(Form("TextChargeAveAlis_c%s.dat",centstring));
  for(int i=0; i<50; i++)
    {
      fout<<th1d_xp->GetBinCenter(i+1)
	  <<"\t"
	  <<th1d_xp->GetBinContent(i+1)
	  <<"\t"
	  <<th1d_xp->GetBinError(i+1)
	  <<endl;
    }
  fout.close();
  th1d_xp->Scale(mult);
  th1d_xp->Draw();
  c1->Print(Form("FigChargeAveAlisBF_c%s.png",centstring));
  ofstream fout(Form("TextChargeAveAlisBF_c%s.dat",centstring));
  for(int i=0; i<50; i++)
    {
      fout<<th1d_xp->GetBinCenter(i+1)
	  <<"\t"
	  <<th1d_xp->GetBinContent(i+1)
	  <<"\t"
	  <<th1d_xp->GetBinError(i+1)
	  <<endl;
    }
  fout.close();

}



void DoCalculationCovariance(TList *list, char *centstring, double mult)
{
  TProfile *tp_xb = (TProfile *)list->FindObject(Form("h_q1q3_Y_deta_cent%s",centstring));
  TProfile *tp_xp = (TProfile *)list->FindObject(Form("h_q1_Y_deta_cent%s",centstring));
  TProfile *tp_xn = (TProfile *)list->FindObject(Form("h_q3_Y_deta_cent%s",centstring));
  TH1D *th1d_xb = tp_xb->ProjectionX();
  TH1D *th1d_xp = tp_xp->ProjectionX();
  TH1D *th1d_xn = tp_xn->ProjectionX();
  th1d_xp->Multiply(th1d_xn);
  TF1 *fun = new TF1("fun","pol0",-2,2);
  fun->SetParameter(0,1);
  th1d_xb->Multiply(fun,-1);
  th1d_xb->Add(th1d_xp);
  th1d_xb->Draw();
  c1->Print(Form("FigChargeCovAlis_c%s.png",centstring));
  ofstream fout(Form("TextChargeCovAlis_c%s.dat",centstring));
  for(int i=0; i<50; i++)
    {
      fout<<th1d_xb->GetBinCenter(i+1)
	  <<"\t"
	  <<th1d_xb->GetBinContent(i+1)
	  <<"\t"
	  <<th1d_xb->GetBinError(i+1)
	  <<endl;
    }
  fout.close();
  th1d_xb->Scale(mult);
  th1d_xb->Draw();
  c1->Print(Form("FigChargeCovAlisBF_c%s.png",centstring));
  fout.open(Form("TextChargeCovAlisBF_c%s.dat",centstring));
  for(int i=0; i<50; i++)
    {
      fout<<th1d_xb->GetBinCenter(i+1)
	  <<"\t"
	  <<th1d_xb->GetBinContent(i+1)
	  <<"\t"
	  <<th1d_xb->GetBinError(i+1)
	  <<endl;
    }
  fout.close();
}
