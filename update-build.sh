#!/usr/bin/env bash

make distclean
./bootstrap

mkdir build
cd build
../configure --prefix="$HOME/Development/opt"

