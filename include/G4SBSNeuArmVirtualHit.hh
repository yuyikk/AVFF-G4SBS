//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// G4SBSNeuArmVirtualHit.hh
// Developer : Jixie Zhang(original), Chao Gu
// History:
//   Jan 2017, C. Gu, Add for ROOT support.
//

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef G4SBSNeuArmVirtualHit_h
#define G4SBSNeuArmVirtualHit_h 1

#include "G4VHit.hh"

#include "G4Allocator.hh"
#include "G4THitsCollection.hh"
#include "G4VPhysicalVolume.hh"

#include "G4ThreeVector.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class G4SBSNeuArmVirtualHit : public G4VHit
{
public:
    G4SBSNeuArmVirtualHit();
    virtual ~G4SBSNeuArmVirtualHit();

    inline void *operator new (size_t);
    inline void operator delete (void *);

    // bool operator ==(const G4SBSNeuArmVirtualHit &) const;

    void Print();
    void Clear();

    inline G4int GetPdgID() const;
    inline G4int GetTrackID() const;
    inline G4int GetParentTrackID() const;
    inline G4int GetDetectorID() const;
    inline G4int GetProcessID() const;
    inline G4ThreeVector GetInXYZ() const;
    inline G4ThreeVector GetOutPosition() const;
    inline G4ThreeVector GetVertexXYZ() const;
    inline G4ThreeVector GetInPxPyPz() const;
    // inline G4ThreeVector GetOutMomentum() const;
    inline G4double GetTime() const;
    // inline G4double GetEdep() const;
    // inline G4double GetTrackLength() const;
    // inline const G4VPhysicalVolume *GetPhysV() const;
    // inline G4int GetCopyNo() const;

    inline void SetPID(G4int &val);
    inline void SetTrackID(G4int &val);
    inline void SetParentTrackID(G4int &val);
    inline void SetDetectorID(G4int &val);
    inline void SetProcessID(G4int &val);
    inline void SetInPosition(G4ThreeVector &xyz);
    inline void SetOutPosition(G4ThreeVector &xyz);
    inline void SetVertexPosition(G4ThreeVector &xyz);
    inline void SetInMomentum(G4ThreeVector &pxpypz);
    // inline void SetOutMomentum(G4ThreeVector &pxpypz);
    inline void SetTime(G4double &val);
    // inline void SetEdep(G4double &val);
    // inline void SetTrackLength(G4double &val);
    // inline void SetPhysV(G4VPhysicalVolume *val);
    // inline void SetCopyNo(G4int &val);

    // inline void AddEdep(G4double &val);
    // inline void AddTrackLength(G4double &val);

private:
    G4int         fPID;
    G4int         fTrackID;
    G4int         fPTrackID;
    G4int         fDetID;
    G4int         fProcessID;
    G4ThreeVector fInPos;
    G4ThreeVector fOutPos;
    G4ThreeVector fVertexPos;
    G4ThreeVector fInMom;
    // G4ThreeVector fOutMom;
    G4double      fTime;
    // G4double      fEdep;
    // G4double      fTrackLen;
    // const G4VPhysicalVolume *fPhysV = nullptr;
    // G4int         fCopyNo;
};

typedef G4THitsCollection<G4SBSNeuArmVirtualHit> G4SBSNeuArmVirtualHitsCollection;

extern G4Allocator<G4SBSNeuArmVirtualHit> G4SBSNeuArmVirtualHitAllocator;

inline void *G4SBSNeuArmVirtualHit::operator new (size_t)
{
    void *aHit;
    aHit = (void *)G4SBSNeuArmVirtualHitAllocator.MallocSingle();
    return aHit;
}

inline void G4SBSNeuArmVirtualHit::operator delete (void *aHit)
{
    G4SBSNeuArmVirtualHitAllocator.FreeSingle((G4SBSNeuArmVirtualHit *)aHit);
}

inline G4int G4SBSNeuArmVirtualHit::GetPdgID() const
{
    return fPID;
}

inline G4int G4SBSNeuArmVirtualHit::GetTrackID() const
{
    return fTrackID;
}

inline G4int G4SBSNeuArmVirtualHit::GetParentTrackID() const
{
    return fPTrackID;
}

inline G4int G4SBSNeuArmVirtualHit::GetDetectorID() const
{
    return fDetID;
}

inline G4int G4SBSNeuArmVirtualHit::GetProcessID() const
{
    return fProcessID;
}

inline G4ThreeVector G4SBSNeuArmVirtualHit::GetInXYZ() const
{
    return fInPos;
}

inline G4ThreeVector G4SBSNeuArmVirtualHit::GetOutPosition() const
{
    return fOutPos;
}

inline G4ThreeVector G4SBSNeuArmVirtualHit::GetVertexXYZ() const
{
    return fVertexPos;
}

inline G4ThreeVector G4SBSNeuArmVirtualHit::GetInPxPyPz() const
{
    return fInMom;
}

// inline G4ThreeVector G4SBSNeuArmVirtualHit::GetOutMomentum() const
// {
//     return fOutMom;
// }

inline G4double G4SBSNeuArmVirtualHit::GetTime() const
{
    return fTime;
}

// inline G4double G4SBSNeuArmVirtualHit::GetEdep() const
// {
//     return fEdep;
// }

// inline G4double G4SBSNeuArmVirtualHit::GetTrackLength() const
// {
//     return fTrackLen;
// }

// inline const G4VPhysicalVolume *G4SBSNeuArmVirtualHit::GetPhysV() const
// {
//     return fPhysV;
// }

// inline G4int G4SBSNeuArmVirtualHit::GetCopyNo() const
// {
//     return fCopyNo;
// }

inline void G4SBSNeuArmVirtualHit::SetPID(G4int &val)
{
    fPID = val;
}

inline void G4SBSNeuArmVirtualHit::SetTrackID(G4int &val)
{
    fTrackID = val;
}

inline void G4SBSNeuArmVirtualHit::SetParentTrackID(G4int &val)
{
    fPTrackID = val;
}

inline void G4SBSNeuArmVirtualHit::SetDetectorID(G4int &val)
{
    fDetID = val;
}

inline void G4SBSNeuArmVirtualHit::SetProcessID(G4int &val)
{
    fProcessID = val;
}

inline void G4SBSNeuArmVirtualHit::SetInPosition(G4ThreeVector &xyz)
{
    fInPos = xyz;
}

inline void G4SBSNeuArmVirtualHit::SetOutPosition(G4ThreeVector &xyz)
{
    fOutPos = xyz;
}

inline void G4SBSNeuArmVirtualHit::SetVertexPosition(G4ThreeVector &xyz)
{
    fVertexPos = xyz;
}

inline void G4SBSNeuArmVirtualHit::SetInMomentum(G4ThreeVector &pxpypz)
{
    fInMom = pxpypz;
}

// inline void G4SBSNeuArmVirtualHit::SetOutMomentum(G4ThreeVector &pxpypz)
// {
//     fOutMom = pxpypz;
// }

inline void G4SBSNeuArmVirtualHit::SetTime(G4double &val)
{
    fTime = val;
}

// inline void G4SBSNeuArmVirtualHit::SetEdep(G4double &val)
// {
//     fEdep = val;
// }

// inline void G4SBSNeuArmVirtualHit::SetTrackLength(G4double &val)
// {
//     fTrackLen = val;
// }

// inline void G4SBSNeuArmVirtualHit::SetPhysV(G4VPhysicalVolume *val)
// {
//     fPhysV = val;
// }

// inline void G4SBSNeuArmVirtualHit::SetCopyNo(G4int &val)
// {
//     fCopyNo = val;
// }

// inline void G4SBSNeuArmVirtualHit::AddEdep(G4double &val)
// {
//     fEdep += val;
// }

// inline void G4SBSNeuArmVirtualHit::AddTrackLength(G4double &val)
// {
//     fTrackLen += val;
// }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
