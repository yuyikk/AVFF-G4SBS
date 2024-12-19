#ifndef G4SBSNeuArmTOFoutput_hh
#define G4SBSNeuArmTOFoutput_hh 1
#include <vector>
#include <array>

class G4SBSNeuArmTOFoutput
{
    public:
        G4SBSNeuArmTOFoutput();
        ~G4SBSNeuArmTOFoutput();
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
        std::vector<float> fEdep;
        std::vector<float> fTrackL;
        std::vector<float> fVx;
        std::vector<float> fVy;
        std::vector<float> fVz;
        std::vector<float> fOutX;
        std::vector<float> fOutY;
        std::vector<float> fOutZ;
        std::array<float, 980> fModuleEdep;
        float fTotalEdep;
};
#endif