# AVFF-G4SBS
G4 simulation for Axial FF experiment under the framework of g4sbs.
Introduction about the g4sbs can be found at

[g4sbs github](https://github.com/JeffersonLab/g4sbs?tab=coc-ov-file)

[Documentation of g4sbs](https://hallaweb.jlab.org/wiki/index.php/Documentation_of_g4sbs#Notes_on_GEANT4_build_options)

## How to compile
Detailed instruction on how to build the program can be found at [Documentation of g4sbs](https://hallaweb.jlab.org/wiki/index.php/Documentation_of_g4sbs#Notes_on_GEANT4_build_options).

A script `compile.sh` can be used to compile the codes.
Make sure all the files and folders in this repo are within a same folder. Let's say `g4sbs`.

Run the script `compile.sh` at the same level of `g4sbs`. The installed program can be found in the directory `exe`.

## An example: run a beam-on-target simulation

```bash
cd ./exe/run_g4sbs_here
source ../bin/g4sbs.sh
g4sbs mac/AVFF_Gun.mac
```
