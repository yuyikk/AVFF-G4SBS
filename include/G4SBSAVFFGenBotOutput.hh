#ifndef _AVFFGENBOTOUTPUT_
#define _AVFFGENBOTOUTPUT_
#include <vector>
class G4SBSAVFFGenBotOutput
{
    public:
        G4SBSAVFFGenBotOutput();
        ~G4SBSAVFFGenBotOutput();
        void ConvertUnits();
        void Clear();
        float fWeight;
        std::vector<int> fPdgID;
        std::vector<float> fTime; // hit global time
        std::vector<float> fPx, fPy, fPz; // momentum
        std::vector<float> fHitX, fHitY, fHitZ; // hit position 
};
#endif