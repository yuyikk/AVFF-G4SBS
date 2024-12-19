#ifndef _MyG4SBSNeuArmTOFHit_HH_
#define _MyG4SBSNeuArmTOFHit_HH_ 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"
#include "G4Transform3D.hh"
#include "G4RotationMatrix.hh"



// class G4AttDef;
// class G4AttValue;

class G4SBSNeuArmTOFHit : public G4VHit
{
public:
  G4SBSNeuArmTOFHit();
  // G4SBSNeuArmTOFHit(G4int iRow, G4int iCol, G4int iLay);
  virtual ~G4SBSNeuArmTOFHit();


  G4SBSNeuArmTOFHit &operator=(const G4SBSNeuArmTOFHit &right) = default;
  // G4bool operator==(const G4SBSNeuArmTOFHit &right) const;

  inline void *operator new(size_t);
  inline void operator delete(void *aHit);

  // void Draw() override;
  // const std::map<G4String, G4AttDef> *GetAttDefs() const override;
  // std::vector<G4AttValue> *CreateAttValues() const override;
  void Print();
  void Clear();

  // void SetColumnID(G4int z) { fColumnID = z; }
  // G4int GetColumnID() const { return fColumnID; }

  // void SetRowID(G4int z) { fRowID = z; }
  // G4int GetRowID() const { return fRowID; }

  // void SetLayerID(G4int z) { fLayerId = z; }
  // G4int GetLayerID() const { return fLayerId; }

  void SetDetectorID(G4int val);
  short GetDetectorID() const;

  void SetPdgID(short val);
  short GetPdgID();

  void SetTrackID(short val);
  short GetTrackID();

  void SetParentTrackID(short val);
  short GetParentTrackID();

  void SetProcessID(short val);
  short GetProcessID();

  void SetTime(const float &time);
  G4float GetTime();

  void SetEdep(const G4float &de);
  G4float GetEdep() const;
  void AddEdep(const G4float &de);

  // void SetModuleEdep(const int &i, const G4float &val);
  // G4float GetModuleEdep(const int &i);
  // void AddModuleEdep(const int &i, const float &val);

  void SetTrackLength(const G4float &length);
  void AddTrackLength(const G4float &length);
  G4float GetTrackLength() const;

  void SetInXYZ(G4ThreeVector xyz);
  G4ThreeVector GetInXYZ();
  // void SetInXYZ(const float &x, const float &y, const float &z);
  // void SetInX(const float &x);
  // void SetInY(const float &y);
  // void SetInZ(const float &z);
  // void SetInPxPyPz(const float &Px, const float &Py, const float &Pz);
  void SetInPxPyPz(G4ThreeVector mom);
  G4ThreeVector GetInPxPyPz();
  // void SetInPx(const float &Px);
  // void SetInPy(const float &Py);
  // void SetInPz(const float &Pz);

  void SetOutXYZ(G4ThreeVector xyz);
  G4ThreeVector GetOutXYZ();
  // void SetOutXYZ(const float &x, const float &y, const float &z);
  // void SetOutX(const float &x);
  // void SetOutY(const float &y);
  // void SetOutZ(const float &z);
  // void SetOutPxPyPz(const float &Px, const float &Py, const float &Pz);
  void SetOutPxPyPz(G4ThreeVector mom);
  G4ThreeVector GetOutPxPyPz();
  // void SetOutPx(const float &Px);
  // void SetOutPy(const float &Py);
  // void SetOutPz(const float &Pz);

  void SetVertexXYZ(G4ThreeVector xyz);
  // void SetVertexXYZ(const float &x, const float &y, const float &z);

  G4ThreeVector GetVertexXYZ();



private:
  short fPID;
  short fTID;
  short fPTID;
  short fDID;
  short fProcessID;
  G4float fX;
  G4float fY;
  G4float fZ;
  G4float fPx;
  G4float fPy;
  G4float fPz;
  G4float fTime;
  G4float fEdep;
  G4float fTrackL;
  G4float fVx;
  G4float fVy;
  G4float fVz;
  G4float fOutX;
  G4float fOutY;
  G4float fOutZ;
  G4float fOutPx;
  G4float fOutPy;
  G4float fOutPz;
};

using G4SBSNeuArmTOFHitsCollection = G4THitsCollection<G4SBSNeuArmTOFHit>;

extern G4ThreadLocal G4Allocator<G4SBSNeuArmTOFHit> *G4SBSNeuArmTOFHitAllocator;

inline void *G4SBSNeuArmTOFHit::operator new(size_t)
{
  if (!G4SBSNeuArmTOFHitAllocator)
  {
    G4SBSNeuArmTOFHitAllocator = new G4Allocator<G4SBSNeuArmTOFHit>;
  }
  return (void *)G4SBSNeuArmTOFHitAllocator->MallocSingle();
}

inline void G4SBSNeuArmTOFHit::operator delete(void *aHit)
{
  G4SBSNeuArmTOFHitAllocator->FreeSingle((G4SBSNeuArmTOFHit *)aHit);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
#endif
