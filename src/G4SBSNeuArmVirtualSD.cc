#include "G4SBSNeuArmVirtualSD.hh"
// #include "GlobalVars.hh"
// #include "RootTree.hh"
#include "G4SBSNeuArmVirtualHit.hh"
// #include "TrackInformation.hh"

#include "TROOT.h"
#include "TError.h"
#include "TObject.h"
#include "TTree.h"

#include "G4HCofThisEvent.hh"
#include "G4SDManager.hh"
#include "G4Step.hh"
#include "G4StepPoint.hh"
#include "G4TouchableHandle.hh"
#include "G4Track.hh"
#include "G4ProcessType.hh"
#include "G4VProcess.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VSensitiveDetector.hh"
#include "G4ThreeVector.hh"
#include <string>
// #include "Constants.hh"
// G4bool G4SBSNeuArmVirtualSD::hasHits = false;
G4SBSNeuArmVirtualSD::G4SBSNeuArmVirtualSD(G4String name, G4String collname) : G4VSensitiveDetector(name)
{
    collectionName.insert(collname);
}
G4SBSNeuArmVirtualSD::~G4SBSNeuArmVirtualSD()
{
}

void G4SBSNeuArmVirtualSD::Initialize(G4HCofThisEvent *HCE)
{
    fHitsCollection = new G4SBSNeuArmVirtualHitsCollection(SensitiveDetectorName, collectionName[0]);

    G4int HCID = G4SDManager::GetSDMpointer()->GetCollectionID(fHitsCollection);
    HCE->AddHitsCollection(HCID, fHitsCollection);
    // hasHits = false;
    clear();
}

G4bool G4SBSNeuArmVirtualSD::ProcessHits(G4Step *step, G4TouchableHistory *)
{
    if (!fHitsCollection)
    {
        return false;
    }
    G4Track *trk = step->GetTrack();
    // TrackInformation *trkInfo = (TrackInformation *)(trk->GetUserInformation());
    G4double Edep = step->GetTotalEnergyDeposit();
    G4int AncestorID = -1; // trkInfo->GetAncestor(fID);

    G4StepPoint *preStepPoint = step->GetPreStepPoint();
    G4StepPoint *postStepPoint = step->GetPostStepPoint();
    G4TouchableHandle theTouchable = preStepPoint->GetTouchableHandle();
    G4VPhysicalVolume *thePhysVol = theTouchable->GetVolume();

    G4int PID = trk->GetParticleDefinition()->GetPDGEncoding();
    G4int TrackID = trk->GetTrackID();
    G4int ParentTrackID = trk->GetParentID();
    G4ThreeVector InPos = preStepPoint->GetPosition();
    G4ThreeVector InMomentum = preStepPoint->GetMomentum();

    G4ThreeVector OutPos = postStepPoint->GetPosition();
    G4ThreeVector OutMomentum = postStepPoint->GetMomentum();

    G4ThreeVector VertexPos = trk->GetVertexPosition();

    G4double Time = preStepPoint->GetGlobalTime();

    G4double StepLength = 0.;
    if (trk->GetParticleDefinition()->GetPDGCharge() != 0)
    {
        StepLength = step->GetStepLength();
    }
    G4int CopyNo = theTouchable->GetCopyNumber();

    if (AncestorID < 0)
    {
        AncestorID = TrackID;
    }

    const G4VProcess *creatorProcess = trk->GetCreatorProcess();

    G4int ProcessID = -9999;
    if (creatorProcess)
    {
        ProcessID = creatorProcess->GetProcessSubType();
    }
    G4SBSNeuArmVirtualHit *hit = NULL;

    for (G4int i = fHitsCollection->entries() - 1; i >= 0; --i)
    {
	G4SBSNeuArmVirtualHit *savedHit = (*fHitsCollection)[i];
        if (savedHit->GetTrackID() == AncestorID && savedHit->GetDetectorID() == CopyNo)
        {
            hit = (*fHitsCollection)[i];
            break;
        }
    }
    if (hit)
    {
        if (hit->GetTrackID() == TrackID)
        {
            if (hit->GetTime() > Time)
            {
                hit->SetTime(Time);
            }
        }
    }
    else
    {
        hit = new G4SBSNeuArmVirtualHit();
        hit->SetPID(PID);
        hit->SetTrackID(TrackID);
        hit->SetParentTrackID(ParentTrackID);
        hit->SetDetectorID(CopyNo);
        hit->SetProcessID(ProcessID);
        hit->SetInPosition(InPos);
        hit->SetInMomentum(InMomentum);
        hit->SetVertexPosition(VertexPos);
        hit->SetOutPosition(OutPos);
        hit->SetTime(Time);
        hit->SetProcessID(ProcessID);
        fHitsCollection->insert(hit);
    }
    // G4int nSencondaries = step->GetNumberOfSecondariesInCurrentStep();
    // if (nSencondaries > 0 && AncestorID >= 0)
    // {
    //     for (auto &secondary : *(step->GetSecondaryInCurrentStep()))
    //     {
    //         if (secondary->GetUserInformation() != 0)
    //         {
    //             continue;
    //         }
    //         TrackInformation *newTrkInfo = new TrackInformation(trkInfo);
    //         newTrkInfo->SetAncestor(fID, AncestorID);
    //         G4Track *secTrk = (G4Track *)secondary;
    //         secTrk->SetUserInformation(newTrkInfo);
    //     }
    // }

    return true;
}
void G4SBSNeuArmVirtualSD::EndOfEvent(G4HCofThisEvent *HCE)
{
    
}
void G4SBSNeuArmVirtualSD::clear()
{
    // fPID.clear();
    // fTID.clear();
    // fPTID.clear();
    // fDID.clear();
    // fProcessID.clear();
    // fX.clear();
    // fY.clear();
    // fZ.clear();
    // fPx.clear();
    // fPy.clear();
    // fPz.clear();
    // fTime.clear();
    // fEdep.clear();
    // fTrackL.clear();
    // fVx.clear();
    // fVy.clear();
    // fVz.clear();
    // fOutx.clear();
    // fOuty.clear();
    // fOutz.clear();
}
