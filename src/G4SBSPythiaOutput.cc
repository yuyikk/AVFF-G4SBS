#include "G4SBSPythiaOutput.hh"
#include "G4SystemOfUnits.hh"

G4SBSPythiaOutput::G4SBSPythiaOutput(){
  Sigma = 1.0; //default to 1.0 mb
  Clear();
}

G4SBSPythiaOutput::~G4SBSPythiaOutput(){
  ;
}

void G4SBSPythiaOutput::Clear(){
  Ebeam = 0.0;
  Eprime = 0.0;
  theta_e = 0.0;
  phi_e = 0.0;
  px_e = 0.0;
  py_e = 0.0;
  pz_e = 0.0;
  vx_e = 0.0;
  vy_e = 0.0;
  vz_e = 0.0;
  Egamma = 0.0;
  theta_gamma = 0.0;
  phi_gamma = 0.0;
  px_gamma = 0.0;
  py_gamma = 0.0;
  pz_gamma = 0.0;
  vx_gamma = 0.0;
  vy_gamma = 0.0;
  vz_gamma = 0.0;
  Q2 = 0.0;
  xbj = 0.0;
  y = 0.0;
  W2 = 0.0;

  Nprimaries = 0;
  PID.clear();
  genflag.clear();
  Px.clear();
  Py.clear();
  Pz.clear();
  M.clear();
  E.clear();
  P.clear();
  t.clear();
  vx.clear();
  vy.clear();
  vz.clear();
  theta.clear();
  phi.clear();
}

void G4SBSPythiaOutput::ConvertToTreeUnits(){ //This is called once per event after primary vertices are generated. When this is called, all quantities should be in GEANT4 standard units of MeV, ns, cm;
  Ebeam /= MeV;
  Eprime /= MeV;
  px_e /= MeV;
  py_e /= MeV;
  pz_e /= MeV;
  vx_e /= cm;
  vy_e /= cm;
  vz_e /= cm;
  Egamma /= MeV;
  px_gamma /= MeV;
  py_gamma /= MeV;
  pz_gamma /= MeV;
  vx_gamma /= cm;
  vy_gamma /= cm;
  vz_gamma /= cm;
  Q2 /= (MeV*MeV);
  W2 /= (MeV*MeV);

  for( int i=0; i<Nprimaries; i++ ){
    Px[i] /= MeV;
    Py[i] /= MeV;
    Pz[i] /= MeV;
    M[i] /= MeV;
    E[i] /= MeV;
    P[i] /= MeV;
    t[i] /= ns;
    vx[i] /= cm;
    vy[i] /= cm;
    vz[i] /= cm;
  }

}
