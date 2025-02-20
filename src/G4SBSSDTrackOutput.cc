#include "G4SBSSDTrackOutput.hh"

G4SBSSDTrackOutput::G4SBSSDTrackOutput()
{
  Clear();
}

G4SBSSDTrackOutput::G4SBSSDTrackOutput(G4String name)
{
  sdname = name;
  Clear();
}

G4SBSSDTrackOutput::~G4SBSSDTrackOutput() { ; }

void G4SBSSDTrackOutput::Clear()
{
  notracks = 0;
  nptracks = 0;
  nsdtracks = 0;

  //"Original track" info:
  otrid.clear();
  omid.clear();
  opid.clear();
  ompid.clear();

  oposx.clear();
  omomx.clear();
  opolx.clear();

  oposy.clear();
  omomy.clear();
  opoly.clear();

  oposz.clear();
  omomz.clear();
  opolz.clear();

  oenergy.clear();
  otime.clear();

  //"Primary track" info:
  ptrid.clear();
  // pmid.clear();
  ppid.clear();

  pposx.clear();
  pmomx.clear();
  ppolx.clear();

  pposy.clear();
  pmomy.clear();
  ppoly.clear();

  pposz.clear();
  pmomz.clear();
  ppolz.clear();

  penergy.clear();
  ptime.clear();

  //"SD boundary crossing t3rack info":
  sdtrid.clear();
  sdmid.clear();
  sdpid.clear();
  sdmpid.clear();

  sdposx.clear();
  sdmomx.clear();
  sdpolx.clear();

  sdposy.clear();
  sdmomy.clear();
  sdpoly.clear();

  sdposz.clear();
  sdmomz.clear();
  sdpolz.clear();

  sdenergy.clear();
  sdtime.clear();

  // New vertex info:
  sdvx.clear();
  sdvy.clear();
  sdvz.clear();
  sdvnx.clear();
  sdvny.clear();
  sdvnz.clear();
  sdEkin.clear();

  // maps:
  otracklist.clear();
  ptracklist.clear();
  sdtracklist.clear();

  // otrack_hits.clear();
  // ptrack_hits.clear();
  // sdtrack_hits.clear();
}

void G4SBSSDTrackOutput::SetSDname(G4String name)
{
  sdname = name;
}

void G4SBSSDTrackOutput::ConvertToTreeUnits()
{
  // Units in the ROOT Tree are meters, GeV, ns:
  for (int i = 0; i < notracks; i++)
  {
    oposx[i] /= CLHEP::cm;
    oposy[i] /= CLHEP::cm;
    oposz[i] /= CLHEP::cm;

    omomx[i] /= CLHEP::MeV;
    omomy[i] /= CLHEP::MeV;
    omomz[i] /= CLHEP::MeV;

    oenergy[i] /= CLHEP::MeV;
    otime[i] /= CLHEP::ns;
  }

  for (int i = 0; i < nptracks; i++)
  {
    pposx[i] /= CLHEP::cm;
    pposy[i] /= CLHEP::cm;
    pposz[i] /= CLHEP::cm;

    pmomx[i] /= CLHEP::MeV;
    pmomy[i] /= CLHEP::MeV;
    pmomz[i] /= CLHEP::MeV;

    penergy[i] /= CLHEP::MeV;
    ptime[i] /= CLHEP::ns;
  }

  for (int i = 0; i < nsdtracks; i++)
  {
    sdposx[i] /= CLHEP::cm;
    sdposy[i] /= CLHEP::cm;
    sdposz[i] /= CLHEP::cm;

    sdmomx[i] /= CLHEP::MeV;
    sdmomy[i] /= CLHEP::MeV;
    sdmomz[i] /= CLHEP::MeV;

    sdenergy[i] /= CLHEP::MeV;
    sdtime[i] /= CLHEP::ns;

    sdvx[i] /= CLHEP::cm;
    sdvy[i] /= CLHEP::cm;
    sdvz[i] /= CLHEP::cm;

    sdEkin[i] /= CLHEP::MeV;
  }
}

G4int G4SBSSDTrackOutput::InsertOriginalTrackInformation(G4Track *aTrack)
{

  G4SBSTrackInformation *aTrackInfo = (G4SBSTrackInformation *)aTrack->GetUserInformation();

  int tidtemp = aTrackInfo->GetOriginalTrackID();

  std::pair<map<int, int>::iterator, bool> newtrack = otracklist.insert(std::pair<int, int>(tidtemp, notracks));

  if (newtrack.second)
  { // new track found: add its info to the arrays:
    otrid.push_back(tidtemp);
    omid.push_back(aTrackInfo->GetOriginalParentID());
    opid.push_back(aTrackInfo->GetOriginalDefinition()->GetPDGEncoding());
    ompid.push_back(aTrackInfo->GetOriginalParentPID()->GetPDGEncoding());

    G4ThreeVector postemp = aTrackInfo->GetOriginalPosition();
    G4ThreeVector momtemp = aTrackInfo->GetOriginalMomentum();
    G4ThreeVector poltemp = aTrackInfo->GetOriginalPolarization();

    oposx.push_back(postemp.x());
    oposy.push_back(postemp.y());
    oposz.push_back(postemp.z());

    omomx.push_back(momtemp.x());
    omomy.push_back(momtemp.y());
    omomz.push_back(momtemp.z());

    opolx.push_back(poltemp.x());
    opoly.push_back(poltemp.y());
    opolz.push_back(poltemp.z());

    oenergy.push_back(aTrackInfo->GetOriginalEnergy());
    otime.push_back(aTrackInfo->GetOriginalTime());

    notracks++;
  }

  //  return otracklist[tidtemp]; //this is the position/index in the (unsorted) otrack array
  return tidtemp; // Instead of returning the array index, return the G4 track ID
}

G4int G4SBSSDTrackOutput::InsertPrimaryTrackInformation(G4Track *aTrack)
{
  G4SBSTrackInformation *aTrackInfo = (G4SBSTrackInformation *)aTrack->GetUserInformation();

  int tidtemp = aTrackInfo->GetPrimaryTrackID();

  std::pair<map<int, int>::iterator, bool> newtrack = ptracklist.insert(std::pair<int, int>(tidtemp, nptracks));

  if (newtrack.second)
  { // new track found: add its info to the arrays:
    ptrid.push_back(tidtemp);
    // pmid.push_back( aTrackInfo->GetPrimaryParentID() );
    ppid.push_back(aTrackInfo->GetPrimaryDefinition()->GetPDGEncoding());

    G4ThreeVector postemp = aTrackInfo->GetPrimaryPosition();
    G4ThreeVector momtemp = aTrackInfo->GetPrimaryMomentum();
    G4ThreeVector poltemp = aTrackInfo->GetPrimaryPolarization();

    pposx.push_back(postemp.x());
    pposy.push_back(postemp.y());
    pposz.push_back(postemp.z());

    pmomx.push_back(momtemp.x());
    pmomy.push_back(momtemp.y());
    pmomz.push_back(momtemp.z());

    ppolx.push_back(poltemp.x());
    ppoly.push_back(poltemp.y());
    ppolz.push_back(poltemp.z());

    penergy.push_back(aTrackInfo->GetPrimaryEnergy());
    ptime.push_back(aTrackInfo->GetPrimaryTime());

    nptracks++;
  }

  // return ptracklist[tidtemp]; //this is the position/index in the (unsorted) ptrack array
  // Instead of returning the array index, return the G4 track ID:
  return tidtemp;
}

G4int G4SBSSDTrackOutput::InsertSDTrackInformation(G4Track *aTrack)
{
  G4SBSTrackInformation *aTrackInfo = (G4SBSTrackInformation *)aTrack->GetUserInformation();

  if ((aTrackInfo->fSDlist).find(sdname) != (aTrackInfo->fSDlist).end())
  {

    // G4cout << "found track information for SD " << sdname << G4endl;

    int tidtemp = (aTrackInfo->fSDTrackID)[sdname];

    // std::pair< std::map<int,int>::iterator, bool > newtrack = sdtracklist.insert( std::pair<int,int>(tidtemp,nsdtracks) );

    // std::map<int,map<G4String,int> >::iterator newtrack = sdtracklist.find( tidtemp );

    // bool newsdboundarycrossing = false;
    if (sdtracklist.find(tidtemp) != sdtracklist.end())
    { // existing G4 track ID: check whether SDname exists:
      if (sdtracklist[tidtemp].find(sdname) != sdtracklist[tidtemp].end())
      { // existing track ID AND SDname: return mapped index value:
        // return sdtracklist[tidtemp][sdname];
        return tidtemp; // this is the G4 track ID. EndOfEventAction now expects this!
      }
    }

    // if NOT pre-existing track ID/SD combination, assign the sd track list information
    // mapped by SD track ID and SD name to the index in the array of sd tracks associated with this detector:
    sdtracklist[tidtemp][sdname] = nsdtracks;

    sdtrid.push_back(tidtemp);
    sdmid.push_back((aTrackInfo->fSDParentID)[sdname]);
    sdpid.push_back((aTrackInfo->fSDDefinition)[sdname]->GetPDGEncoding());
    sdmpid.push_back((aTrackInfo->fSDParentPID)[sdname]->GetPDGEncoding());

    G4ThreeVector postemp = (aTrackInfo->fSDPosition)[sdname];
    G4ThreeVector momtemp = (aTrackInfo->fSDMomentum)[sdname];
    G4ThreeVector poltemp = (aTrackInfo->fSDPolarization)[sdname];

    sdposx.push_back(postemp.x());
    sdposy.push_back(postemp.y());
    sdposz.push_back(postemp.z());

    sdmomx.push_back(momtemp.x());
    sdmomy.push_back(momtemp.y());
    sdmomz.push_back(momtemp.z());

    sdpolx.push_back(poltemp.x());
    sdpoly.push_back(poltemp.y());
    sdpolz.push_back(poltemp.z());

    sdenergy.push_back((aTrackInfo->fSDEnergy)[sdname]);
    sdtime.push_back((aTrackInfo->fSDTime)[sdname]);

    postemp = (aTrackInfo->fSDVertexPosition)[sdname];
    momtemp = (aTrackInfo->fSDVertexDirection)[sdname];

    sdvx.push_back(postemp.x());
    sdvy.push_back(postemp.y());
    sdvz.push_back(postemp.z());

    sdvnx.push_back(momtemp.x());
    sdvny.push_back(momtemp.y());
    sdvnz.push_back(momtemp.z());

    sdEkin.push_back((aTrackInfo->fSDVertexKineticEnergy)[sdname]);

    nsdtracks++;

    // this is the index in the SD track array
    // return sdtracklist[tidtemp][sdname];
    return tidtemp; // This is the G4 Track ID: EndOfEventAction now EXPECTS this!
  }
  else
  { // May alter this behavior later...
    // G4cout << "no SD track info available for track " << aTrack->GetTrackID() << ", SD name = " << sdname
    // 	   << G4endl;
    sdtracklist[-1][sdname] = -1;
    return -1;
  }
}

// return a vector<int> containing a list of the new indices relative to the old ones:
void G4SBSSDTrackOutput::Merge(G4SBSSDTrackOutput &sd)
{

  // Start with OTracks:
  for (int i = 0; i < sd.notracks; i++)
  {
    std::pair<std::map<int, int>::iterator, bool> newtrack = otracklist.insert(std::pair<int, int>(sd.otrid[i], notracks));

    if (newtrack.second)
    { // new track: add to end of existing array:
      otrid.push_back(sd.otrid[i]);
      omid.push_back(sd.omid[i]);
      opid.push_back(sd.opid[i]);
      ompid.push_back(sd.ompid[i]);

      oposx.push_back(sd.oposx[i]);
      oposy.push_back(sd.oposy[i]);
      oposz.push_back(sd.oposz[i]);

      omomx.push_back(sd.omomx[i]);
      omomy.push_back(sd.omomy[i]);
      omomz.push_back(sd.omomz[i]);

      opolx.push_back(sd.opolx[i]);
      opoly.push_back(sd.opoly[i]);
      opolz.push_back(sd.opolz[i]);

      oenergy.push_back(sd.oenergy[i]);
      otime.push_back(sd.otime[i]);

      notracks++;
    }
  }

  // Then do PTracks:
  for (int i = 0; i < sd.nptracks; i++)
  {
    std::pair<std::map<int, int>::iterator, bool> newtrack = ptracklist.insert(std::pair<int, int>(sd.ptrid[i], nptracks));

    if (newtrack.second)
    { // new track: add to end of existing array:
      ptrid.push_back(sd.ptrid[i]);
      // pmid.push_back( sd.pmid[i] );
      ppid.push_back(sd.ppid[i]);

      pposx.push_back(sd.pposx[i]);
      pposy.push_back(sd.pposy[i]);
      pposz.push_back(sd.pposz[i]);

      pmomx.push_back(sd.pmomx[i]);
      pmomy.push_back(sd.pmomy[i]);
      pmomz.push_back(sd.pmomz[i]);

      ppolx.push_back(sd.ppolx[i]);
      ppoly.push_back(sd.ppoly[i]);
      ppolz.push_back(sd.ppolz[i]);

      penergy.push_back(sd.penergy[i]);
      ptime.push_back(sd.ptime[i]);

      nptracks++;
    }
  }

  // loop on the sd track list to be merged into this one; compare with existing, add as needed:
  for (map<int, map<G4String, int>>::iterator i = sd.sdtracklist.begin(); i != sd.sdtracklist.end(); ++i)
  {

    int tidtemp = i->first;

    for (map<G4String, int>::iterator j = (i->second).begin(); j != (i->second).end(); ++j)
    {
      G4String sdnametemp = j->first;

      int idx = j->second;

      bool addtrack = true;
      if (sdtracklist.find(tidtemp) != sdtracklist.end())
      { // existing TID:
        if (sdtracklist[tidtemp].find(sdnametemp) != sdtracklist[tidtemp].end())
        { // existing SDname:
          addtrack = false;
        }
      }

      if (addtrack && tidtemp >= 0 && idx >= 0)
      {

        // G4cout << "added SD track to detector " << sdnametemp << ", TID = "
        //        << tidtemp << ", index in detector SD track list = " << idx
        //        << ", index in new SD track list = " << nsdtracks << G4endl;

        sdtracklist[tidtemp][sdnametemp] = nsdtracks;

        sdtrid.push_back(sd.sdtrid[idx]);
        sdmid.push_back(sd.sdmid[idx]);
        sdpid.push_back(sd.sdpid[idx]);
        sdmpid.push_back(sd.sdmpid[idx]);

        sdposx.push_back(sd.sdposx[idx]);
        sdposy.push_back(sd.sdposy[idx]);
        sdposz.push_back(sd.sdposz[idx]);

        sdmomx.push_back(sd.sdmomx[idx]);
        sdmomy.push_back(sd.sdmomy[idx]);
        sdmomz.push_back(sd.sdmomz[idx]);

        sdpolx.push_back(sd.sdpolx[idx]);
        sdpoly.push_back(sd.sdpoly[idx]);
        sdpolz.push_back(sd.sdpolz[idx]);

        sdenergy.push_back(sd.sdenergy[idx]);
        sdtime.push_back(sd.sdtime[idx]);

        // new vertex info:
        sdvx.push_back(sd.sdvx[idx]);
        sdvy.push_back(sd.sdvy[idx]);
        sdvz.push_back(sd.sdvz[idx]);

        sdvnx.push_back(sd.sdvnx[idx]);
        sdvny.push_back(sd.sdvny[idx]);
        sdvnz.push_back(sd.sdvnz[idx]);

        sdEkin.push_back(sd.sdEkin[idx]);

        nsdtracks++;
      }
    }
  }
}
