#include "G4SBSNeuArmVirtualoutput.hh"
#include "G4SystemOfUnits.hh"

G4SBSNeuArmVirtualoutput::G4SBSNeuArmVirtualoutput()
{
    Clear();
}
G4SBSNeuArmVirtualoutput::~G4SBSNeuArmVirtualoutput()
{
}
void G4SBSNeuArmVirtualoutput::Clear()
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
    fVx.clear();
    fVy.clear();
    fVz.clear();
}