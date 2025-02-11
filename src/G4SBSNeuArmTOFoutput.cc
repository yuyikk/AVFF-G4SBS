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

void G4SBSNeuArmTOFoutput::ConvertUnits()
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

        fTrackL.at(i) /= CLHEP::cm;
        fVx.at(i) /= CLHEP::cm;
        fVy.at(i) /= CLHEP::cm;
        fVz.at(i) /= CLHEP::cm;
        fOutX.at(i) /= CLHEP::cm;
        fOutY.at(i) /= CLHEP::cm;
        fOutZ.at(i) /= CLHEP::cm;
        fEdep.at(i) /= CLHEP::MeV;
    }
    for (unsigned int i = 0; i < fModuleEdep.size(); ++i)
    {
        fModuleEdep.at(i) /= CLHEP::MeV;
    }
    fTotalEdep /= CLHEP::MeV;
}