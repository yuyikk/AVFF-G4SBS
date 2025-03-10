#include "G4SBSAVFFGenBotOutput.hh"
#include "G4SystemOfUnits.hh"

G4SBSAVFFGenBotOutput::G4SBSAVFFGenBotOutput()
{
    Clear();
}
G4SBSAVFFGenBotOutput::~G4SBSAVFFGenBotOutput()
{
    
}
void G4SBSAVFFGenBotOutput::Clear()
{
    fWeight = 1.0;
    fTime.clear();
    fHitX.clear();
    fHitY.clear();
    fHitZ.clear();
    fPdgID.clear();
    fPx.clear();
    fPy.clear();
    fPz.clear();
}
void G4SBSAVFFGenBotOutput::ConvertUnits()
{
    
    for (unsigned int i = 0; i < fPx.size(); ++i)
    {
        fTime.at(i) /= ns;
        fHitX.at(i) /= cm;
        fHitY.at(i) /= cm;
        fHitZ.at(i) /= cm;
        fPx.at(i) /= MeV;
        fPy.at(i) /= MeV;
        fPz.at(i) /= MeV;
    }
}