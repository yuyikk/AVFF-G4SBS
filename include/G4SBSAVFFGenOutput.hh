#ifndef _AVFFGENOUTPUT_
#define _AVFFGENOUTPUT_
#include <vector>
class G4SBSAVFFGenOutput
{
    public:
        G4SBSAVFFGenOutput();
        ~G4SBSAVFFGenOutput();
        void ConvertUnits();
        void Clear();
        float fWeight;
        std::vector<int> fPdgID;
        std::vector<float> fPx, fPy, fPz; // momentum
        float fVx, fVy, fVz; // vertex position
};
#endif