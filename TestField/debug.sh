#!/bin/bash

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/../ZucchiniEngine/ZEngine/lib:$(pwd)/../ZGraphics2D/ZGraphics2D/lib
./bin/Debug/TestField
