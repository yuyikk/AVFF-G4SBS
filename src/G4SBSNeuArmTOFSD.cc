

#include "G4SBSNeuArmTOFSD.hh"
#include "G4SBSNeuArmTOFHit.hh"
// #include "TrackInformation.hh"

#include "G4HCofThisEvent.hh"
#include "G4TouchableHistory.hh"
#include "G4TouchableHandle.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4SDManager.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "G4ios.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
enum
{
  row,
  column,
  layer
};
G4int GetHCalRowId(G4int copyNum);
G4int GetHCalColumnId(G4int copyNum);
G4int GetHCalLayerId(G4int copyNum);
G4int ConvertCopyNumber(G4int copyNum, G4int axis);
G4SBSNeuArmTOFSD::G4SBSNeuArmTOFSD(G4String name, G4String collname) : G4VSensitiveDetector(name), fHitsCollection(NULL)
{
  collectionName.insert(collname);
}
G4SBSNeuArmTOFSD::~G4SBSNeuArmTOFSD()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void G4SBSNeuArmTOFSD::Initialize(G4HCofThisEvent *HCE)
{
  fHitsCollection = new G4SBSNeuArmTOFHitsCollection(SensitiveDetectorName, collectionName[0]);
  // G4cout << collectionName[0] << "\t" << collectionName[1] << G4endl;
  G4int HCID = G4SDManager::GetSDMpointer()->GetCollectionID(fHitsCollection);
  HCE->AddHitsCollection(HCID, fHitsCollection);
  // HCID = G4SDManager::GetSDMpointer()->GetCollectionID(fTOFHitsCollection);
  // HCE->AddHitsCollection(HCID, fTOFHitsCollection);
  // fill calorimeter hits with zero energy deposition
  // for (int i = 0; i < MyTOF::kNofModules; ++i)
  // {
  //   fTOFHitsCollection->insert(new TOFHit());
  // }
  // G4cout << fModuleEdep.size() << G4endl;
  // G4cout << fModuleEdep.size() << G4endl;
  // clear();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4bool G4SBSNeuArmTOFSD::ProcessHits(G4Step *step, G4TouchableHistory *touch)
{
  if (!fHitsCollection)
  {
    return false;
  }
  //StandardDetectorSD::ProcessHits(step, touch);
  // G4cout << "Haha fHitsCollection.size " << (*fHitsCollection).GetSize() << "\n";
  // G4cout << "Haha fTOFHitsCollection.size " << (*fTOFHitsCollection).GetSize() << "\n";
  G4Track *trk = step->GetTrack();
  // TrackInformation *trkInfo = (TrackInformation *)(trk->GetUserInformation());
  // G4cout << "Hahahaha=========1" << G4endl;
  G4double Edep = step->GetTotalEnergyDeposit();
  G4int AncestorID = -1; // trkInfo->GetAncestor(fID);
  G4StepPoint *preStepPoint = step->GetPreStepPoint();
  G4StepPoint *postStepPoint = step->GetPostStepPoint();
  G4TouchableHandle theTouchable = preStepPoint->GetTouchableHandle();
  G4VPhysicalVolume *thePhysVol = theTouchable->GetVolume();
  G4int PID = trk->GetParticleDefinition()->GetPDGEncoding();
  G4int trkID = trk->GetTrackID();
  G4int ParentTrkID = trk->GetParentID();
  G4int DetectorID = theTouchable->GetCopyNumber();
  // for (G4int i = 0; i < theTouchable->GetHistoryDepth(); ++i)
  // {
  //   DetectorID += theTouchable->GetCopyNumber(i);
  // }
  G4ThreeVector InPos = preStepPoint->GetPosition();
  G4ThreeVector InMom = preStepPoint->GetMomentum();
  G4ThreeVector OutPos = postStepPoint->GetPosition();
  G4ThreeVector OutMom = postStepPoint->GetMomentum();
  G4ThreeVector VertexPos = trk->GetVertexPosition();
  G4double InZ = (InPos.z() + OutPos.z()) / 2.;
  G4double InBeta = preStepPoint->GetBeta();
  G4double Time = preStepPoint->GetGlobalTime();
  G4String materialVol = thePhysVol->GetLogicalVolume()->GetMaterial()->GetName();
  G4double StepLength = 0;
  if (trk->GetParticleDefinition()->GetPDGCharge() != 0.0)
  {
    StepLength = step->GetStepLength();
  }
  G4int CopyNo = theTouchable->GetCopyNumber();
  if (AncestorID < 0)
  {
    AncestorID = trkID;
  }
  G4SBSNeuArmTOFHit *hit = NULL;
  for (G4int i = fHitsCollection->entries() - 1; i >= 0; --i)
  {
    G4SBSNeuArmTOFHit *savedHit = (*fHitsCollection)[i];
    if (savedHit->GetTrackID() == AncestorID && savedHit->GetDetectorID() == CopyNo)
    {
      hit = (*fHitsCollection)[i];
      break;
    }
  }
  if (hit)
  {
    hit->AddEdep(Edep);
    hit->AddTrackLength(StepLength);
    if (hit->GetTrackID() == trkID)
    {
      if (hit->GetTime() > Time)
      {
        hit->SetTime(Time);
      }
      hit->SetOutXYZ(OutPos);
      hit->SetOutPxPyPz(OutMom);
    }
  }
  else
  {
    hit = new G4SBSNeuArmTOFHit();
    hit->SetTrackID(trkID);
    hit->SetPdgID(PID);
    hit->SetParentTrackID(ParentTrkID);
    hit->SetDetectorID(DetectorID);
    hit->SetInXYZ(InPos);
    hit->SetInPxPyPz(InMom);
    hit->SetOutXYZ(OutPos);
    hit->SetOutPxPyPz(OutMom);
    hit->SetVertexXYZ(VertexPos);
    hit->SetTime(Time);
    hit->SetEdep(Edep);
    hit->SetTrackLength(StepLength);
    // hit->SetPhysV(thePhysVol);
    // hit->SetCopyNo(CopyNo);
    fHitsCollection->insert(hit);
  }
  // G4cout << "DetId: " << DetectorID << G4endl;
  // TOFHit *tofHit = (*fHitsCollection)[DetectorID];
  // tofHit->SetDetectorID(DetectorID);
  // tofHit->AddEdep(Edep);
  // tofHit->AddTrackLength(StepLength);

  return true;
}
void G4SBSNeuArmTOFSD::EndOfEvent(G4HCofThisEvent *HCE)
{
  // if (!HCE)
  // {
  //   return;
  // }
  // G4int nHits = fHitsCollection->GetSize();
  // fN = nHits;
  // // if (nHits <= 0)
  // // {
  // //   return;
  // // }
  // // G4cout << fModuleEdep.size() << G4endl;
  // for (int i = 0; i < fN; ++i)
  // {
  //   G4SBSNeuArmVirtualHit *hit = (*fHitsCollection)[i];
  //   // if (hit->GetEdep() <= 0)
  //   // {
  //   //   continue;
  //   // }
  //   fPID.push_back(hit->GetPID());
  //   fTID.push_back(hit->GetTrackID());
  //   fPTID.push_back(hit->GetParentTrackID());
  //   fDID.push_back(hit->GetDetectorID());
  //   fProcessID.push_back(hit->GetProcessID());
  //   fX.push_back(hit->GetInPosition().x());
  //   fY.push_back(hit->GetInPosition().y());
  //   fZ.push_back(hit->GetInPosition().z());
  //   fOutx.push_back(hit->GetOutPosition().x());
  //   fOuty.push_back(hit->GetOutPosition().y());
  //   fOutz.push_back(hit->GetOutPosition().z());
  //   fPx.push_back(hit->GetInMomentum().x());
  //   fPy.push_back(hit->GetInMomentum().y());
  //   fPz.push_back(hit->GetInMomentum().z());
  //   fTime.push_back(hit->GetTime());
  //   fEdep.push_back(hit->GetEdep());
  //   fTotalEdep[hit->GetDetectorID()] += hit->GetEdep();
  //   fTotalTrackLength[hit->GetDetectorID()] += hit->GetTrackLength();
  // }
  // fTotalEdep = 0.;
  // fTotalTrackLength = 0.;
  // for (int i = 0; i < MyTOF::kNofModules; ++i)
  // {
  //   TOFHit *hit = (*fTOFHitsCollection)[i];
  //   // if (hit->GetEdep() <= 0)
  //   // {
  //   //   continue;
  //   // }
  //   fModuleID.push_back(hit->GetDetectorID());
  //   // G4cout << hit->GetDetectorID() << G4endl;
  //   fModuleEdep.push_back(hit->GetEdep());
  //   // G4cout << hit->GetEdep() << G4endl;
  //   fModuleTrackLength.push_back(hit->GetTrackLength());
  //   fTotalEdep += hit->GetEdep();
  //   fTotalTrackLength += hit->GetTrackLength();
  // }
}
// void G4SBSNeuArmTOFSD::RegisterTree(TTree *tree)
// {
//   G4cout << "Building ROOT Tree..." << G4endl;
//   tree->Branch("TOF.NHits", &fN, "NHits/I");
//   tree->Branch("TOF.PDGID", &fPID);
//   tree->Branch("TOF.TrackID", &fTID);
//   tree->Branch("TOF.ParentTrackID", &fPTID);
//   tree->Branch("TOF.DetID", &fDID);
//   tree->Branch("TOF.ProcessID", &fProcessID);
//   tree->Branch("TOF.HitInPosition.X", &fX);
//   tree->Branch("TOF.HitInPosition.Y", &fY);
//   tree->Branch("TOF.HitInPosition.Z", &fZ);
//   tree->Branch("TOF.HitInMomentum.X", &fPx);
//   tree->Branch("TOF.HitInMomentum.Y", &fPy);
//   tree->Branch("TOF.HitInMomentum.Z", &fPz);
//   tree->Branch("TOF.VertexPosition.X", &fVx);
//   tree->Branch("TOF.VertexPosition.Y", &fVy);
//   tree->Branch("TOF.VertexPosition.Z", &fVz);
//   tree->Branch("TOF.HitOutPosition.X", &fOutx);
//   tree->Branch("TOF.HitOutPosition.Y", &fOuty);
//   tree->Branch("TOF.HitOutPosition.Z", &fOutz);
//   tree->Branch("TOF.HitGlobalTime", &fTime);
//   tree->Branch("TOF.HitEdep", &fEdep);
//   tree->Branch("TOF.TrackLength", &fTrackL);
//   tree->Branch("TOF.ModuleID", &fModuleID);
//   tree->Branch("TOF.TotalEdep", &fTotalEdep, "TOF.TotalEdep/D");
//   tree->Branch("TOF.TotalTrackLength", &fTotalTrackLength, "TOF.TotalTrackLength/D");
//   tree->Branch("TOF.ModuleEdep", &fModuleEdep);
//   tree->Branch("TOF.ModuleTrackLength", &fModuleTrackLength);
// }
// void G4SBSNeuArmTOFSD::clear()
// {
//   // // G4cout << fDID.size() << G4endl;
//   // // StandardDetectorSD::Clear();
//   // fModuleEdep.clear();
//   // fModuleTrackLength.clear();
//   // fModuleID.clear();
//   // fDID.clear();
// }
G4int GetHCalRowId(G4int copyNum)
{
  return ConvertCopyNumber(copyNum, row);
}
G4int GetHCalColumnId(G4int copyNum)
{
  return ConvertCopyNumber(copyNum, column);
}
G4int GetHCalLayerId(G4int copyNum)
{
  return ConvertCopyNumber(copyNum, layer);
}
G4int ConvertCopyNumber(G4int copyNum, G4int axis)
{
  // G4int nRow = MyTOF::kNofRows;
  // G4int nCol = MyTOF::kNofColumns;
  // G4int layid = copyNum / (nRow * nCol);
  // G4int colid = (copyNum - layid * nRow * nCol) / nRow;
  // G4int rowid = (copyNum - layid * nRow * nCol) - colid * nRow;
  // G4int ids[3] = {rowid, colid, layid};
  // return ids[axis];
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
