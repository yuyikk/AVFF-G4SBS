#define AVFFGenBotTree_cxx
#include "AVFFGenBotTree.h"
#include <TH2.h>

void AVFFGenBotTree::Loop()
{
//   In a ROOT session, you can do:
//      root> .L AVFFGenTree.C
//      root> AVFFGenTree t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
}
Int_t AVFFGenBotTree::GetPdgID(const int &i) const 
{
   if (i >= NParticle)
   {
      return -9999;
   }
   return PID[i]; 
}
Double_t AVFFGenBotTree::GetPx(const int &i) const 
{ 
   if (i >= NParticle)
   {
      return -9999;
   }
   return Px[i]; 
}
Double_t AVFFGenBotTree::GetPy(const int &i) const 
{ 
   if (i >= NParticle)
   {
      return -9999;
   }
   return Py[i]; 
}
Double_t AVFFGenBotTree::GetPz(const int &i) const 
{ 
   if (i >= NParticle)
   {
      return -9999;
   }
   return Pz[i]; 
}
Double_t AVFFGenBotTree::GetHitX(const int &i) const 
{
   if (i >= NParticle)
   {
      return -9999;
   }
   return HitX[i]; 
}
Double_t AVFFGenBotTree::GetHitY(const int &i) const 
{ 
   if (i >= NParticle)
   {
      return -9999;
   }
   return HitY[i]; 
}
Double_t AVFFGenBotTree::GetHitZ(const int &i) const 
{ 
   if (i >= NParticle)
   {
      return -9999;
   }
   return HitZ[i]; 
}
Double_t AVFFGenBotTree::GetTime(const int &i) const 
{ 
   if (i >= NParticle)
   {
      return -9999;
   }
   return Time[i]; 
}