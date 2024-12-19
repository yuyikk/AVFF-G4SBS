#include "G4SBSNeuArmTOFoutput.hh"
#include "G4SystemOfUnits.hh"

G4SBSNeuArmTOFoutput::G4SBSNeuArmTOFoutput()
{
    Clear();
}
G4SBSNeuArmTOFoutput::~G4SBSNeuArmTOFoutput()
{
}
void G4SBSNeuArmTOFoutput::Clear()
{
    fPID.clear();
    fTID.clear();
    fPTID.clear();
    fDID.clear();
    fProcessID.clear();
    fX.clear();
    fY.clear();
    fZ.clear();
    fPx.clear();
    fPy.clear();
    fPz.clear();
    fTime.clear();
    fEdep.clear();
    fTrackL.clear();
    fVx.clear();
    fVy.clear();
    fVz.clear();
    fOutX.clear();
    fOutY.clear();
    fOutZ.clear();
    fModuleEdep.fill(0);
    fTotalEdep = 0;
}