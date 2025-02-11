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

void G4SBSNeuArmVirtualoutput::ConvertUnits()
{
    for (unsigned int i = 0; i < fX.size(); ++i)
    {
        fX.at(i) /= CLHEP::cm;
        fY.at(i) /= CLHEP::cm;
        fZ.at(i) /= CLHEP::cm;
        fPx.at(i) /= CLHEP::MeV;
        fPy.at(i) /= CLHEP::MeV;
        fPz.at(i) /= CLHEP::MeV;
        fTime.at(i) /= CLHEP::ns;
        fVx.at(i) /= CLHEP::cm;
        fVy.at(i) /= CLHEP::cm;
        fVz.at(i) /= CLHEP::cm;
    }
}