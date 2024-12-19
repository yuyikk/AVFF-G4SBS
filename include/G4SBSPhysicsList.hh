#ifndef G4SBSPhysicsList_h 
#define G4SBSPhysicsList_h 1

#include "G4VModularPhysicsList.hh"
#include <vector>

using namespace std;

class G4SBSPhysicsList : public G4VModularPhysicsList 
{
public:
  G4SBSPhysicsList();
  virtual ~G4SBSPhysicsList();
  
  void SetCuts();
  //void ConstructOptical();
  //void SetOpticalPhysicsProcessActive( G4int, G4bool );
  //inline G4VPhysicsConstructor *GetOpticalPhysics() const { return G4SBSOpticalPhysics; }
  //void SetOpticalPhysics( G4VPhysicsConstructor *c ){ G4SBSOpticalPhysics = c; }
  void ToggleCerenkov(G4bool);
  void ToggleScintillation(G4bool);

private:

  //G4bool UseOptical;

  G4double cutGamma;
  G4double cutElectron;
  G4double cutPositron;
  G4double cutProton;

  // G4VPhysicsConstructor *G4SBSEMPhysics;
  // G4VPhysicsConstructor *G4SBSParticleList;
  // vector<G4VPhysicsConstructor*> G4SBSHadronicPhysics;
  G4VPhysicsConstructor *G4SBSOpticalPhysics;
  // G4VPhysicsConstructor *G4SBSOpticalPhysics;

  // void ConstructParticle();
  //virtual void ConstructProcess();

};

#endif
