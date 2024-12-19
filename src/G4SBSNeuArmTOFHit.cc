#include "G4SBSNeuArmTOFHit.hh"

#include "G4VVisManager.hh"
#include "G4VisAttributes.hh"
#include "G4Box.hh"
#include "G4Colour.hh"
#include "G4AttDefStore.hh"
#include "G4AttDef.hh"
#include "G4AttValue.hh"
#include "G4UIcommand.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4ThreadLocal G4Allocator<G4SBSNeuArmTOFHit> *G4SBSNeuArmTOFHitAllocator;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4SBSNeuArmTOFHit::G4SBSNeuArmTOFHit(): G4VHit()
{
  // Clear();
}
G4SBSNeuArmTOFHit::~G4SBSNeuArmTOFHit()
{
  // Clear();
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// G4bool G4SBSNeuArmTOFHit::operator==(const G4SBSNeuArmTOFHit &right) const
// {
//   return (fColumnID == right.fColumnID && fRowID == right.fRowID && fLayerId == right.fLayerId);
// }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// void G4SBSNeuArmTOFHit::Draw()
// {
//   auto visManager = G4VVisManager::GetConcreteInstance();
//   if (!visManager || (fEdep == 0.))
//     return;

//   // Draw a calorimeter cell with depth propotional to the energy deposition
//   G4Transform3D trans(fRot.inverse(), fPos);
//   G4VisAttributes attribs;
//   attribs.SetColour(G4Colour::Red());
//   attribs.SetForceSolid(true);
//   G4Box box("dummy", 15. * cm, 15. * cm, 1. * m * fEdep / (0.1 * GeV));
//   visManager->Draw(box, attribs, trans);
// }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// const std::map<G4String, G4AttDef> *G4SBSNeuArmTOFHit::GetAttDefs() const
// {
//   G4bool isNew;
//   auto store = G4AttDefStore::GetInstance("G4SBSNeuArmTOFHit", isNew);

//   if (isNew)
//   {
//     (*store)["HitType"] = G4AttDef("HitType", "Hit Type", "Physics", "", "G4String");

//     (*store)["Column"] = G4AttDef("Column", "Column ID", "Physics", "", "G4int");

//     (*store)["Row"] = G4AttDef("Row", "Row ID", "Physics", "", "G4int");

//     (*store)["Energy"] = G4AttDef("Energy", "Energy Deposited", "Physics", "G4BestUnit",
//                                   "G4double");

//     (*store)["Pos"] = G4AttDef("Pos", "Position", "Physics", "G4BestUnit",
//                                "G4ThreeVector");
//   }
//   return store;
// }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// std::vector<G4AttValue> *G4SBSNeuArmTOFHit::CreateAttValues() const
// {
//   auto values = new std::vector<G4AttValue>;

//   values
//       ->push_back(G4AttValue("HitType", "G4SBSNeuArmTOFHit", ""));
//   values
//       ->push_back(G4AttValue("Column", G4UIcommand::ConvertToString(fColumnID),
//                              ""));
//   values
//       ->push_back(G4AttValue("Row", G4UIcommand::ConvertToString(fRowID), ""));
//   values
//       ->push_back(G4AttValue("Energy", G4BestUnit(fEdep, "Energy"), ""));
//   values
//       ->push_back(G4AttValue("Pos", G4BestUnit(fPos, "Length"), ""));

//   return values;
// }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void G4SBSNeuArmTOFHit::Print()
{
  // G4cout << "  Cell[" << fRowID << ", " << fColumnID << ", " << fLayerId << "] "
  //        << fEdep / MeV << " (MeV) " << fPos << G4endl;
}

void G4SBSNeuArmTOFHit::SetDetectorID(G4int val) { fDID = val; }
short G4SBSNeuArmTOFHit::GetDetectorID() const { return fDID; }

void G4SBSNeuArmTOFHit::SetPdgID(short val) { fPID = val; }
short G4SBSNeuArmTOFHit::GetPdgID() { return fPID; }

void G4SBSNeuArmTOFHit::SetTrackID(short val) { fTID = val; }
short G4SBSNeuArmTOFHit::GetTrackID() { return fTID; }

void G4SBSNeuArmTOFHit::SetParentTrackID(short val) { fPTID = val; }
short G4SBSNeuArmTOFHit::GetParentTrackID() { return fPTID; }

void G4SBSNeuArmTOFHit::SetProcessID(short val) { fProcessID = val; }
short G4SBSNeuArmTOFHit::GetProcessID() { return fProcessID; }

void G4SBSNeuArmTOFHit::SetEdep(const G4float &de) { fEdep = de; }
void G4SBSNeuArmTOFHit::AddEdep(const G4float &de) { fEdep += de; }
G4float G4SBSNeuArmTOFHit::GetEdep() const { return fEdep; }
void G4SBSNeuArmTOFHit::SetTrackLength(const G4float &length) { fTrackL = length; }
void G4SBSNeuArmTOFHit::AddTrackLength(const G4float &length) { fTrackL += length; }
G4float G4SBSNeuArmTOFHit::GetTrackLength() const { return fTrackL; }
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void G4SBSNeuArmTOFHit::SetInXYZ(G4ThreeVector xyz)
{
  fX = xyz.getX();
  fY = xyz.getY();
  fZ = xyz.getZ();
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void G4SBSNeuArmTOFHit::SetOutXYZ(G4ThreeVector xyz)
{
  fOutX = xyz.getX();
  fOutY = xyz.getY();
  fOutZ = xyz.getZ();
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void G4SBSNeuArmTOFHit::SetInPxPyPz(G4ThreeVector mom)
{
  fPx = mom.getX();
  fPy = mom.getY();
  fPz = mom.getZ();
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void G4SBSNeuArmTOFHit::SetOutPxPyPz(G4ThreeVector mom)
{
  fOutPx = mom.getX();
  fOutPy = mom.getY();
  fOutPz = mom.getZ();
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void G4SBSNeuArmTOFHit::SetVertexXYZ(G4ThreeVector xyz)
{
  fVx = xyz.getX();
  fVy = xyz.getY();
  fVz = xyz.getZ();
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void G4SBSNeuArmTOFHit::SetTime(const float &val)
{
  fTime = val;
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
G4ThreeVector G4SBSNeuArmTOFHit::GetInXYZ()
{
  return G4ThreeVector(fX, fY, fZ);
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
G4ThreeVector G4SBSNeuArmTOFHit::GetOutXYZ()
{
  return G4ThreeVector(fOutX, fOutY, fOutZ);
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
G4ThreeVector G4SBSNeuArmTOFHit::GetInPxPyPz() 
{ 
  return G4ThreeVector(fPx, fPy, fPz); 
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
G4ThreeVector G4SBSNeuArmTOFHit::GetOutPxPyPz() 
{ 
  return G4ThreeVector(fOutPx, fOutPy, fOutPz); 
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
G4ThreeVector G4SBSNeuArmTOFHit::GetVertexXYZ()
{
  return G4ThreeVector(fVx, fVy, fVz);
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
G4float G4SBSNeuArmTOFHit::GetTime()
{
  return fTime;
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void G4SBSNeuArmTOFHit::Clear()
{
  
}