#!/bin/bash
BUILD_PATH=$PWD/build
INSTALL_PATH=$PWD/exe
SOURCE_PATH=$PWD/g4sbs
if [ -d $BUILD_PATH ];then
 	rm -r $BUILD_PATH
fi
if [ -d $INSTALL_PATH ];then
	rm -r $INSTALL_PATH
fi
mkdir -p $BUILD_PATH
mkdir -p $INSTALL_PATH
cd $BUILD_PATH


cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH -DINSTALL_SBS_FIELD_MAPS=ON $SOURCE_PATH
make install
cd $INSTALL_PATH/run_g4sbs_here
ln -s $INSTALL_PATH/scripts mac