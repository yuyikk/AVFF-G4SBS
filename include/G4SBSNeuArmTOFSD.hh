#ifndef _G4SBSNeuArmTOFSD_HH_
#define _G4SBSNeuArmTOFSD_HH_ 1

#include "G4VSensitiveDetector.hh"
#include "Math/Interpolator.h"

#include "G4SBSNeuArmTOFHit.hh"
#include "G4String.hh"

class G4Step;
class G4HCofThisEvent;
class G4TouchableHistory;
// class TTree;

/// Hadron calorimeter sensitive detector

class G4SBSNeuArmTOFSD : public G4VSensitiveDetector
{
public:
  G4SBSNeuArmTOFSD(G4String name, G4String collname);
  ~G4SBSNeuArmTOFSD() override;

  virtual void Initialize(G4HCofThisEvent *);
  virtual G4bool ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist);
  virtual void EndOfEvent(G4HCofThisEvent *);
  // inline void SetAttenuationLG(const G4double &val);
  // inline void SetReflectanceLG(const G4double &val);
protected:
  // virtual void clear();
  G4SBSNeuArmTOFHitsCollection *fHitsCollection = nullptr;
  // G4float fTotalEdep[980];
  // G4float fTotalTrackLength[980];
  // std::vector<short> fModuleID;
  // std::vector<float> fModuleEdep;
  // std::vector<float> fModuleTrackLength;
};
// inline void G4SBSNeuArmTOFSD::SetReflectanceLG(const G4double &val)
// {
//   fReflectanceLG = val;
// }

// inline void G4SBSNeuArmTOFSD::SetAttenuationLG(const G4double &val)
// {
//   fAttenuationLG = val;
// }
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
