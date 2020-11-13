#!/bin/bash

#NPROCS_TOTAL=$(nproc)
#NPROCS_TOUSE=$(expr $NPROCS_TOTAL \/ 2)
# 1 if NPROCS_TOUSE is 0, else nproc / 2
#NPROCS_TOUSE=$(expr $NPROCS_TOUSE \< 1 \| $NPROCS_TOUSE)
NPROCS_TOUSE=$(nproc)

pushd .

mkdir Tapir
cd Tapir

git clone https://github.com/wsmoses/Tapir-LLVM.git src
cd src 
git checkout ba2f0eda34108ab64e581f2740b4d06eecc50709
git submodule update --init --recursive

mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DLLVM_TARGETS_TO_BUILD=host -DLLVM_BINUTILS_INCDIR=/usr/include ..
#cmake --build .
cmake --build . -- -j$NPROCS_TOUSE

cd ../..

popd
