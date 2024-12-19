#include "G4SBSAVFFGenOutput.hh"
#include "G4SystemOfUnits.hh"

G4SBSAVFFGenOutput::G4SBSAVFFGenOutput()
{
    Clear();
}
G4SBSAVFFGenOutput::~G4SBSAVFFGenOutput()
{
    
}
void G4SBSAVFFGenOutput::Clear()
{
    fWeight = 1.0;
    fVx = -9999;
    fVy = -9999;
    fVz = -9999;
    fPdgID.clear();
    fPx.clear();
    fPy.clear();
    fPz.clear();
}
void G4SBSAVFFGenOutput::ConvertToTreeUnits()
{
    fVx /= mm;
    fVy /= mm;
    fVz /= mm;
    for (unsigned int i = 0; i < fPx.size(); ++i)
    {
        fPx.at(i) /= MeV;
        fPy.at(i) /= MeV;
        fPz.at(i) /= MeV;
    }
}