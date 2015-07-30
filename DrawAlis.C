void DrawAlis()
{

  //gStyle->SetOptFit(1);

  DoDraw("0005");
  DoDraw("3040");
  DoDraw("7080");

}


void DoDraw(char *centstring)
{

  TH1D *halis = new TH1D(Form("halis_c%s",centstring),"",50,-2,2);
  TH1D *hron1 = new TH1D(Form("hron1_c%s",centstring),"",50,-2,2);
  TH1D *hron2 = new TH1D(Form("hron2_c%s",centstring),"",50,-2,2);
  TH1D *hron3 = new TH1D(Form("hron3_c%s",centstring),"",50,-2,2);

  ifstream falis;
  //ifstream fron1;
  ifstream fron2;
  ifstream fron3;

  falis.open(Form("AlisBF_c%s.dat",centstring));
  //fron1.open(Form("TextR2BF_c%s.dat",centstring));
  fron2.open(Form("TextChargeAveAlisBF_c%s.dat",centstring));
  fron3.open(Form("TextChargeCovAlisBF_c%s.dat",centstring));
  for(int i=0; i<50; i++)
    {
      float tmp1, tmp2, tmp3;
      if(i<40)
	{
	  falis>>tmp1>>tmp2>>tmp3;
	  halis->SetBinContent(i+6,tmp2);
	  halis->SetBinError(i+6,tmp3);
	}
      // ---
      // fron1>>tmp1>>tmp2>>tmp3;
      // hron1->SetBinContent(i+1,tmp2);
      // hron1->SetBinError(i+1,tmp3);
      // ---
      fron2>>tmp1>>tmp2>>tmp3;
      hron2->SetBinContent(i+1,tmp2);
      hron2->SetBinError(i+1,tmp3);
      // ---
      fron3>>tmp1>>tmp2>>tmp3;
      hron3->SetBinContent(i+1,tmp2);
      hron3->SetBinError(i+1,tmp3);
    }
  falis.close();
  //fron1.close();
  fron2.close();
  fron3.close();
  // ---
  halis->SetMarkerStyle(kFullCircle);
  //  hron1->SetMarkerStyle(kOpenSquare);
  hron2->SetMarkerStyle(kOpenTriangleUp);
  hron3->SetMarkerStyle(kOpenDiamond);
  halis->SetMarkerColor(kBlack);
  //  hron1->SetMarkerColor(kRed);
  hron2->SetMarkerColor(kBlue);
  hron3->SetMarkerColor(kGreen+2);
  halis->SetLineColor(kBlack);
  //  hron1->SetLineColor(kRed);
  hron2->SetLineColor(kBlue);
  hron3->SetLineColor(kGreen+2);
  // ---
  halis->Draw("ex0p");
  //  hron1->Draw("same ex0p");
  hron2->Draw("same ex0p");
  hron3->Draw("same ex0p");
  halis->GetYaxis()->SetTitle("Balance Function");
  halis->GetXaxis()->SetTitle("#Delta#eta");
  // ---
  TLegend *leg = new TLegend(0.18,0.68,0.38,0.88);
  leg->AddEntry(halis,"Alis Corr","ep");
  //  leg->AddEntry(hron1,"Ron R2","ep");
  leg->AddEntry(hron2,"Ron Charge Ave","ep");
  leg->AddEntry(hron3,"Ron Charge Cov","ep");
  leg->SetTextSize(0.04);
  leg->Draw();
  c1->Print(Form("ComparisonFig_AlisRon1_c%s.pdf",centstring));
  // ---
  // ---
  //hron1->Divide(halis);
  hron2->Divide(halis);
  hron3->Divide(halis);
  hron1->Draw("ex0p");
  hron1->SetMaximum(2.0);
  hron1->SetMinimum(0.0);
  hron2->Draw("same ex0p");
  hron3->Draw("same ex0p");
  hron1->GetYaxis()->SetTitle("Ratio of Balance Functions");
  hron1->GetXaxis()->SetTitle("#Delta#eta");
  TLine line(-2.0,1.0,2.0,1.0);
  line.Draw();
  // TF1 *fun1 = new TF1("fun1","pol0",-2,2);
  // fun1->SetLineColor(kBlack);
  // hron1->Fit(fun1,"R");
  TF1 *fun2 = new TF1("fun2","pol0",-2,2);
  fun2->SetLineColor(kBlack);
  hron2->Fit(fun2,"R");
  TF1 *fun3 = new TF1("fun3","pol0",-2,2);
  fun3->SetLineColor(kBlack);
  hron3->Fit(fun3,"R");
  // ---
  // float par1, err1, chi2_1;  int ndf1;
  // par1 = fun1->GetParameter(0);
  // err1 = fun1->GetParError(0);
  // TLatex *tex1 = new TLatex(-1,0.4,Form("p0 = %.2f #pm %.2f",par1,err1));
  // tex1->SetTextSize(0.04);
  // tex1->SetTextColor(kRed);
  // tex1->Draw();
  // ---
  float par2, err2, chi2_2;  int ndf2;
  par2 = fun2->GetParameter(0);
  err2 = fun2->GetParError(0);
  TLatex *tex2 = new TLatex(-1,0.25,Form("p0 = %.2f #pm %.2f",par2,err2));
  tex2->SetTextSize(0.04);
  tex2->SetTextColor(kBlue);
  tex2->Draw();
  // ---
  float par3, err3, chi2_3;  int ndf3;
  par3 = fun3->GetParameter(0);
  err3 = fun3->GetParError(0);
  TLatex *tex3 = new TLatex(-1,0.1,Form("p0 = %.2f #pm %.2f",par3,err3));
  tex3->SetTextSize(0.04);
  tex3->SetTextColor(kGreen+2);
  tex3->Draw();
  // ---
  TLegend *leg = new TLegend(0.18,0.72,0.38,0.88);
  //leg->AddEntry(hron1,"(Ron R2)/(Alis Corr)","ep");
  leg->AddEntry(hron2,"(Ron Charge Ave)/(Alis Corr)","ep");
  leg->AddEntry(hron3,"(Ron Charge Cov)/(Alis Corr)","ep");
  leg->SetTextSize(0.04);
  leg->Draw();
  c1->Print(Form("ComparisonFig_AlisRonRatio1_c%s.pdf",centstring));

}
