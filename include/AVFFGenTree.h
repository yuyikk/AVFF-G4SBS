//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Nov 26 19:59:11 2024 by ROOT version 6.32.02
// from TTree T/T
// found on file: /public/home/xiongw/esepp_file/neutron_signal_e_angle_25_50_10M_AVFF.root
//////////////////////////////////////////////////////////

#ifndef AVFFGenTree_h
#define AVFFGenTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class AVFFGenTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UShort_t        NParticle;
   Double_t        Weight;
   Int_t           PID[20];   //[NParticle]
   Double_t        Px[20];   //[NParticle]
   Double_t        Py[20];   //[NParticle]
   Double_t        Pz[20];   //[NParticle]

   // List of branches
   TBranch        *b_NParticle;   //!
   TBranch        *b_Weight;   //!
   TBranch        *b_PID;   //!
   TBranch        *b_Px;   //!
   TBranch        *b_Py;   //!
   TBranch        *b_Pz;   //!

   AVFFGenTree(TTree *tree=0);
   virtual ~AVFFGenTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t GetEntries();
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual bool     Notify();
   virtual void     Show(Long64_t entry = -1);
   Double_t GetWeight() const { return Weight; }
   UShort_t GetNumOfParticle() const { return NParticle; }
   Int_t GetPdgID(const int &i) const;
   Double_t GetPx(const int &i) const;
   Double_t GetPy(const int &i) const;
   Double_t GetPz(const int &i) const;
};

#endif

#ifdef AVFFGenTree_cxx
AVFFGenTree::AVFFGenTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/public/home/xiongw/esepp_file/neutron_signal_e_angle_25_50_10M_AVFF.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/public/home/xiongw/esepp_file/neutron_signal_e_angle_25_50_10M_AVFF.root");
      }
      f->GetObject("T",tree);

   }
   Init(tree);
}

AVFFGenTree::~AVFFGenTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t AVFFGenTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t AVFFGenTree::GetEntries()
{
   if (!fChain) return 0;
   return fChain->GetEntries();
}
Long64_t AVFFGenTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void AVFFGenTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("NParticle", &NParticle, &b_NParticle);
   fChain->SetBranchAddress("Weight", &Weight, &b_Weight);
   fChain->SetBranchAddress("PID", PID, &b_PID);
   fChain->SetBranchAddress("Px", Px, &b_Px);
   fChain->SetBranchAddress("Py", Py, &b_Py);
   fChain->SetBranchAddress("Pz", Pz, &b_Pz);
   Notify();
}

bool AVFFGenTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return true;
}

void AVFFGenTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t AVFFGenTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef AVFFGenTree_cxx