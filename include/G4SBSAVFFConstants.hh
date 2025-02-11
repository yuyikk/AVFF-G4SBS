#ifndef _G4SBSAVFFCONSTANTS_
#define _G4SBSAVFFCONSTANTS_ 1
#include "G4SystemOfUnits.hh"
#include "globals.hh"
#include <cmath>
#include <algorithm>
#include <iostream>
namespace MyTOF
{
    // relative to the center of MyAarmHad

    constexpr G4double kLengthToTarget = 15 * m;
    constexpr G4int kNofLayers = 11;
    constexpr G4int kNofRows = 140;
    constexpr G4int kNofColumns = 1;
    constexpr G4int kNofModules = kNofRows * kNofColumns * kNofLayers;
    constexpr G4double kLayerShift = 0 * cm;

    constexpr G4double kModSizeX = 200 * cm;
    constexpr G4double kModSizeY = 6 * cm;
    constexpr G4double kModSizeZ = 6 * cm;

    constexpr G4double kIronSizeX = kModSizeX;
    constexpr G4double kIronSizeY = kModSizeY;
    constexpr G4double kIronSizeZ = 2 * cm;

    constexpr G4double kSizeX = 200 * cm;
    constexpr G4double kSizeY = 840 * cm;
    constexpr G4double kSizeZ = kModSizeZ * kNofLayers;

}

namespace MyTarget
{
    constexpr G4double kRadiusContainer = 2.54 * cm; // 2 inches in diameter
    constexpr G4double kRadiusTarget = kRadiusContainer - 0.25 * mm;
    constexpr G4double kLengthContainer = 20 * cm + 0.3 * mm;
    constexpr G4double kLengthTarget = 20 * cm;
    constexpr G4double kPosX = 0;
    constexpr G4double kPosY = 0;
    constexpr G4double kPosZ = 0;
}
namespace MyCollimator
{
    constexpr G4double kInnerR = MyTarget::kRadiusContainer + 1 * mm;
    constexpr G4double kThickness = 25 * cm;
    constexpr G4double kOuterR = kInnerR + kThickness;
    constexpr G4double kConeAngle = 96 * deg;
    constexpr G4double kLength = 15 * cm;
}
namespace MyNeuArm // the arm for hadron detection
{
    constexpr G4double kSizeX = 2.5 * m;
    constexpr G4double kSizeY = 10 * m;
    constexpr G4double kSizeZ = 20 * m;
    constexpr G4double kPosX = 0;
    constexpr G4double kPosY = 0;
    constexpr G4double kPosZ = 0;
}
namespace MyMagnet
{
    // Magnet v1
    // constexpr G4double kLengthToTarget = 1.5 * m;
    // constexpr G4double kFieldSizeX = 34 * cm;
    // constexpr G4double kFieldSizeY = 142 * cm;
    // constexpr G4double kFieldSizeZ = 100 * cm;
    // constexpr G4double kShellThickness = 100 * cm;
    // constexpr G4double kSizeX = kFieldSizeX + 2 * kShellThickness;
    // constexpr G4double kSizeY = kFieldSizeY + 2 * kShellThickness;
    // constexpr G4double kSizeZ = kFieldSizeZ;
    // constexpr G4double kPosX = 0;
    // constexpr G4double kPosY = 0;
    // constexpr G4double kPosZ = -650 * cm; 
    // constexpr G4double kFieldDirectionX = 0;
    // constexpr G4double kFieldDirectionY = 1;
    // constexpr G4double kFieldDirectionZ = 0;
    // constexpr G4double kBx = 0;
    // constexpr G4double kBy = 0.5 * tesla;
    // constexpr G4double kBz = 0;

    // Magnet v2
    constexpr G4double kLengthToTarget = 1.5 * m;
    constexpr G4double kFieldSizeX = 53.5 * cm;
    constexpr G4double kFieldSizeY = 224 * cm;
    constexpr G4double kFieldSizeZ = 200 * cm;
    constexpr G4double kShellThickness = 50 * cm;
    constexpr G4double kSizeX = kFieldSizeX + 2 * kShellThickness;
    constexpr G4double kSizeY = kFieldSizeY + 2 * kShellThickness;
    constexpr G4double kSizeZ = kFieldSizeZ;
}
namespace MyMagnet2
{
    // distance to the target
    constexpr G4double kCtoTarget = 3 * m;
    constexpr G4double kPosX = 0;
    constexpr G4double kPosY = 0;
    constexpr G4double kPosZ = -7 * m;
    constexpr G4double kFieldSizeZ = 2 * m;
    constexpr G4double kFieldSizeX = (kCtoTarget + kFieldSizeZ / 2) * MyTOF::kSizeX / (15. * m);
    constexpr G4double kFieldSizeY = (kCtoTarget + kFieldSizeZ / 2) * MyTOF::kSizeY / (15. * m);
    constexpr G4double kBdl = 1 * tesla * m;
    constexpr G4double kBx = 0;
    constexpr G4double kBy = kBdl / kFieldSizeZ;
    constexpr G4double kBz = 0;
    
    constexpr G4double kCoreSizeX = 40 * cm;
    constexpr G4double kCoreSizeY = kFieldSizeY;
    constexpr G4double kCoreSizeZ = 160 * cm;
    constexpr G4double kIronWallThickness = 40 * cm;
    constexpr G4double kCoilThickness = 30 * cm;
    constexpr G4double kCoilSizeX = kCoreSizeX + 2 * kCoilThickness;
    constexpr G4double kCoilSizeY = kFieldSizeY;
    constexpr G4double kCoilSizeZ = kCoreSizeZ + 2 * kCoilThickness;

    constexpr G4double kCorePosX = 0.5 * (kFieldSizeX + kCoreSizeX) + kCoilThickness;
    constexpr G4double kCorePosY = kPosY;
    constexpr G4double kCorePosZ = kPosZ;
}
namespace MyLeadBlock // the arm for lepton detection
{
    constexpr G4double kThickness= 40 * m;
    constexpr G4double kHeight = 1 * m;
    constexpr G4double kUpperEdge = 40 * cm;
}
namespace MyHCal
{
    constexpr G4int kNofRows = 24;
    constexpr G4int kNofColumns = 12;
    // Dimentions of modules
    constexpr G4double kModSizeX = 152.4 * mm;
    constexpr G4double kModSizeY = 152.4 * mm;
    constexpr G4double kModSizeZ = 1555.7 * mm;
    constexpr G4double kModCtoCDistX = 152.94 * mm;
    constexpr G4double kModCtoCDistY = 158.75 * mm;

    // Dimentions of module containers
    constexpr G4double kModCanThickX = 2 * 1.4478 * mm;
    constexpr G4double kModCanThickY = 1.4478 * mm;
    constexpr G4double kModCanSizeX = kModSizeX - kModCanThickX;
    constexpr G4double kModCanSizeY = kModSizeY - kModCanThickY;

    // Dimentions of absorber
    constexpr G4double kAbsSizeX = 69.6 * mm;
    constexpr G4double kAbsSizeY = 148.80 * mm;
    constexpr G4double kAbsSizeZ = 6.35 * mm;

    // Dimentions of scintillators
    constexpr G4double kScintSizeX =   69.35 * mm;
    constexpr G4double kScintSizeY =  147.00 * mm;
    constexpr G4double kScintSizeZ =    9.90 * mm;

    constexpr G4double kFrontPlateZ = 19.05*CLHEP::mm;

    // Dimentions of HCal
    constexpr G4double kSizeX = (kNofColumns - 1) * kModCtoCDistX + kModSizeX;
    constexpr G4double kSizeY = (kNofRows - 1) * kModCtoCDistY + kModSizeY;
    constexpr G4double kSizeZ = kModSizeZ + kFrontPlateZ;
}

namespace MyParticleGun
{
    constexpr G4double kEtot = 2.2 * GeV; // total energy
    constexpr G4double kPosX = MyTarget::kPosX;
    constexpr G4double kPosY = MyTarget::kPosY;
    constexpr G4double kPosZ = MyTarget::kPosZ - MyTarget::kLengthContainer / 2; // shoot in from the surface of HCal
    constexpr G4double kDirectionX = 0;
    constexpr G4double kDirectionY = 0;
    constexpr G4double kDirectionZ = 1;
}
#endif
