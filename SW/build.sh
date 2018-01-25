#!/bin/sh

TARGET=${1:-release}

cmake -DCMAKE_TOOLCHAIN_FILE="sdk/tools/cmake_toolchain_files/armgcc.cmake" -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=${TARGET} .
make -j4
