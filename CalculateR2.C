void CalculateR2()
{

  TFile *file = TFile::Open("OutExample.root");
  TList *list = (TList *)file->Get("ListExample");

  // Nch
  double dndy_c0005 = 2373/2.0;
  double dndy_c1020 = 1419/2.0;
  double dndy_c3040 =  603/2.0;
  double dndy_c5060 =  204/2.0;
  double dndy_c7080 =   45/2.0;

  GetCIandCD(list,"0005",dndy_c0005);
  GetCIandCD(list,"1020",dndy_c1020);
  GetCIandCD(list,"3040",dndy_c3040);
  GetCIandCD(list,"5060",dndy_c5060);
  GetCIandCD(list,"7080",dndy_c7080);

}



void GetCIandCD(TList *list, char *centstring, double mult)
{

  // --- PP
  TProfile *tp1d_deta_PP = CalculatePairCorrProfile(list,"P","P",centstring);
  tp1d_deta_PP->Draw();
  c1->Print(Form("QAFigs/test_corr_PP_cent%s.png",centstring));
  // --- NN
  TProfile *tp1d_deta_NN = CalculatePairCorrProfile(list,"N","N",centstring);
  tp1d_deta_NN->Draw();
  c1->Print(Form("QAFigs/test_corr_NN_cent%s.png",centstring));
  // --- PN
  TProfile *tp1d_deta_PN = CalculatePairCorrProfile(list,"P","N",centstring);
  tp1d_deta_PN->Draw();
  c1->Print(Form("QAFigs/test_corr_PN_cent%s.png",centstring));
  // --- NP
  TProfile *tp1d_deta_NP = CalculatePairCorrProfile(list,"N","P",centstring);
  tp1d_deta_NP->Draw();
  c1->Print(Form("QAFigs/test_corr_NP_cent%s.png",centstring));

  TH1D *th1d_deta_PP = tp1d_deta_PP->ProjectionX();
  TH1D *th1d_deta_NN = tp1d_deta_NN->ProjectionX();
  TH1D *th1d_deta_PN = tp1d_deta_PN->ProjectionX();
  TH1D *th1d_deta_NP = tp1d_deta_NP->ProjectionX();

  TH1D *th1dC_deta_PP = (TH1D *)th1d_deta_PP->Clone();
  TH1D *th1dC_deta_NN = (TH1D *)th1d_deta_NN->Clone();
  TH1D *th1dC_deta_PN = (TH1D *)th1d_deta_PN->Clone();
  TH1D *th1dC_deta_NP = (TH1D *)th1d_deta_NP->Clone();

  th1d_deta_PP->Add(th1d_deta_NN);
  th1d_deta_PP->Add(th1d_deta_PN);
  th1d_deta_PP->Add(th1d_deta_NP);
  th1d_deta_PP->Scale(0.25);
  th1d_deta_PP->Draw();
  c1->Print(Form("QAFigs/test_corr_CI_cent%s.png",centstring));

  th1dC_deta_PN->Add(th1dC_deta_NP);
  th1dC_deta_PN->Add(th1dC_deta_PP,-1);
  th1dC_deta_PN->Add(th1dC_deta_NN,-1);
  th1dC_deta_PN->Scale(0.25);
  fixerrors(th1dC_deta_PN); // not a real fix for now...
  th1dC_deta_PN->Draw();
  c1->Print(Form("QAFigs/test_corr_CD_cent%s.png",centstring));
  c1->Print(Form("FigR2_cent%s.png",centstring));

  ofstream fout(Form("TextR2_c%s.dat",centstring));
  for ( int i = 0; i < th1dC_deta_PN->GetNbinsX(); i++ )
    {
      fout << th1dC_deta_PN->GetBinCenter(i+1)
	   << " "
	   << th1dC_deta_PN->GetBinContent(i+1)
	   << " "
	   << th1dC_deta_PN->GetBinError(i+1)
	   << endl;
    }
  fout.close();

  th1dC_deta_PN->Scale(mult);
  th1dC_deta_PN->Draw();
  c1->Print(Form("FigR2BF_cent%s.png",centstring));

  ofstream fout(Form("TextR2BF_c%s.dat",centstring));
  for ( int i = 0; i < th1dC_deta_PN->GetNbinsX(); i++ )
    {
      fout << th1dC_deta_PN->GetBinCenter(i+1)
	   << " "
	   << th1dC_deta_PN->GetBinContent(i+1)
	   << " "
	   << th1dC_deta_PN->GetBinError(i+1)
	   << endl;
    }
  fout.close();

}



void fixerrors(TH1D *h1)
{
  cout<<"now \"fixing\" error bars"<<endl;
  int nbins = h1->GetNbinsX();
  for(int i=0; i<nbins; i++)
    {
      double content = h1->GetBinContent(i+1);
      double error = h1->GetBinError(i+1);
      double nerror = error/10;
      h1->SetBinError(i+1,nerror);
    }
}



TProfile *CalculatePairCorrProfile(TList *list, char *e1, char *e2, char *centstring)
{

  TH1D *th1d_cent = (TH1D *)list->FindObject(Form("th1d_cent%s",centstring));
  double nevents = (double)th1d_cent->GetEntries();
  cout << "number of events for centrality " << centstring << " is " << nevents << endl;

  TH1D *th1d_eta1 = (TH1D *)list->FindObject(Form("th1d_eta%s_cent%s",e1,centstring));
  TH1D *th1d_eta2 = (TH1D *)list->FindObject(Form("th1d_eta%s_cent%s",e2,centstring));

  TH2D *th2d_eta1eta2 = (TH2D *)list->FindObject(Form("th2d_eta%seta%s_cent%s",e1,e2,centstring));
  th2d_eta1eta2->Draw("colz");
  c1->Print(Form("QAFigs/example_x2d_initial_eta%seta%s_cent%s.png",e1,e2,centstring));
  int nbinsx = th2d_eta1eta2->GetNbinsX();
  int nbinsy = th2d_eta1eta2->GetNbinsY();
  float xlo = th1d_eta1->GetBinLowEdge(1);
  float xhi = th1d_eta1->GetBinLowEdge(nbinsx+1);
  float ylo = th1d_eta2->GetBinLowEdge(1);
  float yhi = th1d_eta2->GetBinLowEdge(nbinsy+1);
  TH2D *th2d_eta1eta2_symm = new TH2D(Form("th2d_eta%seta%s_symm_cent%s",e1,e2,centstring),"",nbinsx,xlo,xhi,nbinsy,ylo,yhi);
  TH2D *th2d_eta1eta2_corr = new TH2D(Form("th2d_eta%seta%s_corr_cent%s",e1,e2,centstring),"",nbinsx,xlo,xhi,nbinsy,ylo,yhi);
  TProfile *tp1d_deta_corr = new TProfile(Form("tp1d_deta_%s%s_corr_cent%s",e1,e2,centstring),"",nbinsx+nbinsy-1,-2,2,-1e10,1e10,"");
  TH1D *th1d_deta_acc = new TH1D(Form("th1d_deta_%s%s_acc_cent%s",e1,e2,centstring),"",nbinsx+nbinsy-1,-2,2);
  for(int i=0; i<nbinsx; i++)
    {
      for(int j=0; j<nbinsy; j++)
  	{
  	  double content = th2d_eta1eta2->GetBinContent(i+1,j+1);
  	  double h1 = th1d_eta1->GetBinContent(i+1);
  	  double h2 = th1d_eta2->GetBinContent(j+1);
  	  double eta1 = th1d_eta1->GetBinCenter(i+1);
  	  double eta2 = th1d_eta2->GetBinCenter(j+1);
  	  double deta = eta1 - eta2;
  	  content = content/nevents;
  	  h1 = h1/nevents;
  	  h2 = h2/nevents;
  	  double cumulant = (content/(h1*h2))-1;
  	  th2d_eta1eta2_symm->SetBinContent(i+1,j+1,content);
  	  th2d_eta1eta2_corr->SetBinContent(i+1,j+1,cumulant);
  	  tp1d_deta_corr->Fill(deta,cumulant);
  	  th1d_deta_acc->Fill(deta);
  	}
    }
  th2d_eta1eta2_symm->Draw("colz");
  c1->Print(Form("QAFigs/example_x2d_symmetrized_eta%seta%s_cent%s.png",e1,e2,centstring));
  th2d_eta1eta2_corr->Draw("colz");
  c1->Print(Form("QAFigs/example_x2d_zcorrelation_eta%seta%s_cent%s.png",e1,e2,centstring));
  tp1d_deta_corr->Draw();
  c1->Print(Form("QAFigs/example_x1d_correlation_deta_%s%s_cent%s.png",e1,e2,centstring));
  th1d_deta_acc->Draw();
  c1->Print(Form("QAFigs/example_x1d_acceptance_deta_%s%s_cent%s.png",e1,e2,centstring));

  ofstream foutt(Form("QAFigs/text_%s%s_corr_cent%s.txt",e1,e2,centstring));
  for(int i=0; i<nbinsx+nbinsy-1; i++)
    {
      foutt << tp1d_deta_corr->GetBinCenter(i+1)
	    << " "
	    << tp1d_deta_corr->GetBinContent(i+1)
	    << " "
	    << tp1d_deta_corr->GetBinError(i+1)
	    << endl;
    }
  foutt.close();

  return tp1d_deta_corr;

}
