#!/bin/bash

if [ ! -d "build" ]; then
    mkdir build
else
    rm -rf build/*
fi

cd build

Local_Dir=$(cd "$(dirname "$0")"; pwd)

echo "当前工作目录为:$Local_Dir"

cmake ..

make