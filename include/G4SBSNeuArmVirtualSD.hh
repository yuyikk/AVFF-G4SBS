#ifndef _G4SBSNeuArmVirtualSD_hh_
#define _G4SBSNeuArmVirtualSD_hh_

#include "G4VSensitiveDetector.hh"
#include "G4SBSNeuArmVirtualHit.hh"
#include "G4String.hh"
#include <vector>
class G4HCofThisEvent;
class G4Step;
class G4TouchableHistory;
// class TTree;

class G4SBSNeuArmVirtualSD : public G4VSensitiveDetector
{
    public:
        G4SBSNeuArmVirtualSD(G4String name, G4String collname);
        virtual ~G4SBSNeuArmVirtualSD();
        virtual void Initialize(G4HCofThisEvent *);
        virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
        virtual void EndOfEvent(G4HCofThisEvent *);
        // static int GetNhits() { return fNhits; }
        // static G4bool hasHits;

    protected:
        virtual void clear();
        G4SBSNeuArmVirtualHitsCollection *fHitsCollection = nullptr;

};
#endif