#ifndef G4SBSNeuArmVirtualoutput_hh
#define G4SBSNeuArmVirtualoutput_hh 1
#include <vector>

class G4SBSNeuArmVirtualoutput
{
    public:
        G4SBSNeuArmVirtualoutput();
        ~G4SBSNeuArmVirtualoutput();
        void Clear();
        std::vector<short> fPID;
        std::vector<short> fTID;
        std::vector<short> fPTID;
        std::vector<short> fDID;
        std::vector<short> fProcessID;
        std::vector<float> fX;
        std::vector<float> fY;
        std::vector<float> fZ;
        std::vector<float> fPx;
        std::vector<float> fPy;
        std::vector<float> fPz;
        std::vector<float> fTime;
        std::vector<float> fVx;
        std::vector<float> fVy;
        std::vector<float> fVz;
};
#endif