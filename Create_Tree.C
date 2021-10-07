#include "TMath.h"
#include "TF1.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TTree.h"
#include "TBranch.h"
#include "TRandom1.h"
#include <string>
#include <iostream>
#include <fstream>
#define maxrun 39
using namespace std;
int maketaglist(){
Double_t Energy[maxrun];
Double_t tag[maxrun];
Double_t bcirange[maxrun];
ofstream taglist;
taglist.open(Form("Cu_TagList.txt"));
ifstream energylist;
energylist.open(Form("Curuninfo.txt"));
for(int i=0; i<maxrun; i++){
energylist>>Energy[i]>>tag[i]>>bcirange[i];
	taglist<<Energy[i]<<" "<<tag[i]<<" "<<tag[i]+1<<" "<<tag[i]+2<<" "<<tag[i]+3<<" "<<tag[i]+4<<" "<<tag[i]+5<<endl;
}
return 0;
}


int tree2(){
Int_t Nchan = 4095;
Double_t Inner_ring;
Double_t Middle_ring;
Double_t He1_ring;
Double_t He2_ring;
Double_t Rtime;
Double_t bci;
Double_t BG_Inner_ring;
Double_t BG_Middle_ring;
Double_t BG_He1_ring;
Double_t BG_He2_ring;
Double_t BG_Rtime;
Double_t BG_bci;
Double_t count;
char Energy[maxrun];  //root doesn't like variable here
char run_Inner[maxrun];
char run_Middle[maxrun];
char run_He1[maxrun];
char run_He2[maxrun];
char run_Rtime[maxrun];
char run_bci[maxrun];
char run_BG_Inner[maxrun];
char run_BG_Middle[maxrun];
char run_BG_He1[maxrun];
char run_BG_He2[maxrun];
char run_BG_Rtime[maxrun];
char run_BG_bci[maxrun];
TString directory_input = Form("/Users/gulakshanhammad/Desktop/Cu_Analysis/AllCuDataPlusCodes/dsk1120");
ifstream runlist;
runlist.open(Form("Cu_TagList.txt"));
cout<< " I am open0 " << endl;
for(int it=0 ; it < maxrun ; it++){
runlist>>Energy>>run_Middle>>run_Inner>>run_He1>>run_He2>>run_Rtime>>run_bci;
cout << Energy<<" "<<run_Middle<<"  " <<run_Inner<<" "<<run_He1<<" "<<run_He2<<" "<<run_Rtime<<" "<<run_bci<<endl;
ifstream Inner_data;
Inner_data.open(Form("%s/tag%s.xy",directory_input.Data(),run_Inner));
ifstream Middle_data;
Middle_data.open(Form("%s/tag%s.xy",directory_input.Data(),run_Middle));
ifstream He1_data;
He1_data.open(Form("%s/tag%s.xy",directory_input.Data(),run_He1));
ifstream He2_data;
He2_data.open(Form("%s/tag%s.xy",directory_input.Data(),run_He2));
ifstream Rtime_data;
Rtime_data.open(Form("%s/tag%s.xy",directory_input.Data(),run_Rtime));
ifstream bci_data;
bci_data.open(Form("%s/tag%s.xy",directory_input.Data(),run_bci));
cout<< " Making tree: "<<it<< endl;
char datafilename[it];  //changed to nonvariable
sprintf(datafilename,"Cu_Energy%s.root",Energy);
TFile* SimFile= new TFile(datafilename,"RECREATE");
TTree *tr1= new TTree("data_tree","tree with events");
tr1->Branch("count",&count);
tr1->Branch("Inner_ring",&Inner_ring);
tr1->Branch("Middle_ring",&Middle_ring);
tr1->Branch("He1_ring",&He1_ring);
tr1->Branch("He2_ring",&He2_ring);
tr1->Branch("Rtime",&Rtime);
tr1->Branch("bci",&bci);
Int_t event_counter = 0;
while(event_counter <= Nchan){
Inner_data>>count>>Inner_ring;
Middle_data>>count>>Middle_ring;
He1_data>>count>>He1_ring;
He2_data>>count>>He2_ring;
Rtime_data>>count>>Rtime;
bci_data>>count>>bci;
tr1->Fill();
event_counter = event_counter +1;
}
tr1->Write();
SimFile->Close();
Inner_data.close();
Middle_data.close();
He1_data.close();
He2_data.close();
Rtime_data.close();
bci_data.close();
}
return 0;
}




int tree(){
    Int_t Nchan = 4094;
    Double_t Inner_ring;
    Double_t Middle_ring;
    Double_t He1_ring;
    Double_t He2_ring;
    Double_t Rtime;
    Double_t bci;
    Double_t BG_Inner_ring;
    Double_t BG_Middle_ring;
    Double_t BG_He1_ring;
    Double_t BG_He2_ring;
    Double_t BG_Rtime;
    Double_t BG_bci;
    Double_t count;
    //int maxrun = 3;
    char Energy[maxrun];
    char run_Inner[maxrun];
    char run_Middle[maxrun];
    char run_He1[maxrun];
    char run_He2[maxrun];
    char run_Rtime[maxrun];
    char run_bci[maxrun];
    char run_BG_Inner[maxrun];
    char run_BG_Middle[maxrun];
    char run_BG_He1[maxrun];
    char run_BG_He2[maxrun];
    char run_BG_Rtime[maxrun];
    char run_BG_bci[maxrun];
    TString directory_input = Form("/Users/gulakshanhammad/Desktop/Cu_Analysis/AllCuDataPlusCodes/dsk1120");
    ifstream runlist;
    runlist.open(Form("/Users/gulakshanhammad/Desktop/Cu_Analysis/AllCuDataPlusCodes/Cu_TagList.txt"));
    cout<< " I am open0 " << endl;
    for(int it=0;it<maxrun;it++)
    {
        runlist>>Energy>>run_Middle>>run_Inner>>run_He1>>run_He2>>run_Rtime>>run_bci;
        cout << Energy<<" "<<run_Middle<<"  " <<run_Inner<<" "<<run_He1<<" "<<run_He2<<" "<<run_Rtime<<" "<<run_bci<<endl;
    ifstream Inner_data;
    Inner_data.open(Form("%s/tag%s.xy",directory_input.Data(),run_Inner));
    ifstream Middle_data;
    Middle_data.open(Form("%s/tag%s.xy",directory_input.Data(),run_Middle));
    ifstream He1_data;
    He1_data.open(Form("%s/tag%s.xy",directory_input.Data(),run_He1));
    ifstream He2_data;
    He2_data.open(Form("%s/tag%s.xy",directory_input.Data(),run_He2));
    ifstream Rtime_data;
    Rtime_data.open(Form("%s/tag%s.xy",directory_input.Data(),run_Rtime));
    ifstream bci_data;
    bci_data.open(Form("%s/tag%s.xy",directory_input.Data(),run_bci));
//    ifstream BG_Inner_data;
//    BG_Inner_data.open(Form("%s/tag%s.xy",directory_input.Data(),run_BG_Inner));
//    ifstream BG_Middle_data;
//    BG_Middle_data.open(Form("%s/tag%s.xy",directory_input.Data(),run_BG_Middle));
//    ifstream BG_He1_data;
//    BG_He1_data.open(Form("%s/tag%s.xy",directory_input.Data(),run_BG_He1));
//    ifstream BG_He2_data;
//    BG_He2_data.open(Form("%s/tag%s.xy",directory_input.Data(),run_BG_He2));
//    ifstream BG_Rtime_data;
//    BG_Rtime_data.open(Form("%s/tag%s.xy",directory_input.Data(),run_BG_Rtime));
//    ifstream BG_bci_data;
//    BG_bci_data.open(Form("%s/tag%s.xy",directory_input.Data(),run_BG_bci));
    cout<< " I am open1 " << endl;
    char datafilename[it];
    sprintf(datafilename,"Cu_Energy%s.root",Energy);
    TFile* SimFile= new TFile(datafilename,"RECREATE");
    TTree*tr1= new TTree("data_tree","tree with events");
    tr1->Branch("count",&count);
    tr1->Branch("Inner_ring",&Inner_ring);
    tr1->Branch("Middle_ring",&Middle_ring);
    tr1->Branch("He1_ring",&He1_ring);
    tr1->Branch("He2_ring",&He2_ring);
    tr1->Branch("Rtime",&Rtime);
    tr1->Branch("bci",&bci);
//    tr1->Branch("BG_Inner_ring",&BG_Inner_ring);
//    tr1->Branch("BG_Middle_ring",&BG_Middle_ring);
//    tr1->Branch("BG_He1_ring",&BG_He1_ring);
//    tr1->Branch("BG_He2_ring",&BG_He2_ring);
//    tr1->Branch("BG_Rtime",&BG_Rtime);
//    tr1->Branch("BG_bci",&BG_bci);
   Int_t event_counter = 0;
    while(event_counter <= Nchan){
        Inner_data>>count>>Inner_ring;
        Middle_data>>count>>Middle_ring;
        He1_data>>count>>He1_ring;
        He2_data>>count>>He2_ring;
        Rtime_data>>count>>Rtime;
        bci_data>> count>>bci;
//        BG_Inner_data>>count>>BG_Inner_ring;
//        BG_Middle_data>>count>>BG_Middle_ring;
//        BG_He1_data>>count>>BG_He1_ring;
//        BG_He2_data>>count>>BG_He2_ring;
//        BG_Rtime_data>>count>>BG_Rtime;
//        BG_bci_data>>count>>BG_bci;
        tr1->Fill();
        event_counter = event_counter +1;
        }
    
    tr1->Write();
    SimFile->Close();
    Inner_data.close();
    Middle_data.close();
    He1_data.close();
    He2_data.close();
    Rtime_data.close();
    bci_data.close();
//    BG_Inner_data.close();
//    BG_Middle_data.close();
//    BG_He1_data.close();
//    BG_He2_data.close();
//    BG_Rtime_data.close();
//    BG_bci_data.close();
    
    }
    
    return 0;
}


























void Event1(){
    
    Double_t BG_Inner_ring;
    Double_t BG_Middle_ring;
    Double_t BG_He1_ring;
    Double_t BG_He2_ring;
    Double_t Inner_ring;
    Double_t Middle_ring;
    Double_t He1_ring;
    Double_t He2_ring;
    Double_t count;
    Double_t t_2;
    int event_type;

    TFile *f1 = TFile::Open("C13_Energy4450.root");
    TTree *event = (TTree*)f1->Get("data_tree");
    event->SetBranchAddress("Inner_ring",&Inner_ring);
    event->SetBranchAddress("Middle_ring",&Middle_ring);
    event->SetBranchAddress("He1_ring",&He1_ring);
    event->SetBranchAddress("He2_ring",&He2_ring);
    event->SetBranchAddress("BG_Inner_ring",&BG_Inner_ring);
    event->SetBranchAddress("BG_Middle_ring",&BG_Middle_ring);
    event->SetBranchAddress("BG_He1_ring",&BG_He1_ring);
    event->SetBranchAddress("BG_He2_ring",&BG_He2_ring);
    event->SetBranchAddress("count",&count);
    cout << "THE DATA FILE IS OPENED"<<endl;

    int nbin=200;
    TH1F *h2  = new TH1F("h2","Inner_ring", nbin, 0, 4096);
    TH1F *h3  = new TH1F("h3","Middle_ring", nbin, 0, 4096);
    TH1F *h4  = new TH1F("h4","He1_ring", nbin, 0, 4096);
    TH1F *h5  = new TH1F("h5","He2_ring", nbin, 0, 4096);
    TH1F *h6  = new TH1F("h6","BG_Inner_ring", nbin, 0, 4096);
    TH1F *h7 = new TH1F("h7","BG_Middle_ring", nbin, 0, 4096);
    TH1F *h8  = new TH1F("h8","BG_He1_ring", nbin, 0, 4096);
    TH1F *h9  = new TH1F("h9","BG_He2_ring", nbin, 0, 4096);
    
   
    int Total_Entry=event->GetEntries();
    cout<<" no.of events:  "<<Total_Entry<<endl;
    for (int ii=0;ii<Total_Entry;ii++){
        event->GetEntry(ii);
        h2->Fill(count,Inner_ring);
        h3->Fill(count,Middle_ring);
        h4->Fill(count,He1_ring);
        h5->Fill(count,He2_ring);
        h6->Fill(count,BG_Inner_ring);
        h7->Fill(count,BG_Middle_ring);
        h8->Fill(count,BG_He1_ring);
        h9->Fill(count,BG_He2_ring);
        
        
    }
    TCanvas *cene= new TCanvas();
    cene->Divide(4,4);
    cene->cd(1);
    h2->Draw("colz");
    cene->cd(2);
    h3->Draw("colz");
    cene->cd(3);
    h4->Draw("colz");
    cene->cd(4);
    h5->Draw("colz");
    cene->cd(5);
    h6->Draw("colz");
    cene->cd(6);
    h7->Draw("colz");
    cene->cd(7);
    h8->Draw("colz");
    cene->cd(8);
    h9->Draw("colz");
   
    
}









































































































































