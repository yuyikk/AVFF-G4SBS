# AVFF-G4SBS
G4 simulation for Axial FF experiment under the framework of g4sbs.
Introduction about the g4sbs can be found at

[g4sbs github](https://github.com/JeffersonLab/g4sbs?tab=coc-ov-file)

[Documentation of g4sbs](https://hallaweb.jlab.org/wiki/index.php/Documentation_of_g4sbs#Notes_on_GEANT4_build_options)

## How to compile
Detailed instruction on how to build the program can be found in [Documentation of g4sbs](https://hallaweb.jlab.org/wiki/index.php/Documentation_of_g4sbs#Notes_on_GEANT4_build_options).

A script `compile.sh` can be used to compile the codes.
Please make sure all the files and folders in this repo are in a same folder (Let's say `g4sbs`).
Copy the `compile.sh` to the directory where `g4sbs` locates.
Run the script `compile.sh`. The installed program can be found in the directory `exe`.

## Examples
### 1. run a beam-on-target simulation

```bash
cd ./exe/run_g4sbs_here
source ../bin/g4sbs.sh
g4sbs mac/AVFF_Gun.mac 
```
### 2. generator files as input of geant4 simulation
Please modify the `mac/AVFF_Gun.mac` and replace 'YOUR_GENERATOR_ROOT_FILE' with your input generator file
```bash
cd ./exe/run_g4sbs_here
source ../bin/g4sbs.sh
g4sbs mac/AVFF_Gun.mac 
```

## About TTree Branches
For descriptions of branches of sbs arm, please refer [Documentation of g4sbs](https://hallaweb.jlab.org/wiki/index.php/Documentation_of_g4sbs#Notes_on_GEANT4_build_options).

The units (also applied to sbs arm) used in the simulation are  
- Energy: $\mathrm{MeV}$
- Length: $\mathrm{cm}$
- Time: $\mathrm{ns}$

### Branches for virtual plane
---
Branches with prefix 'Virtual'. They stores information of virtual planes in neutron arm.
- Virtual1: virtual plane in front of magnet
- Virtual2: virtual plane in front of TOF
- Virtual3: virtual plane in front of NCal (HCal of neutron arm)
### Branches for TOF
---
Branches with prefix 'TOF'.
### Branches for NCal
---
Branches with prefix 'NCal'.
- NCalScint: hits information on scintillators
- NCalAbsorb: hits information on absorbers