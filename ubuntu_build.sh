#!/bin/bash

#Install billion fucking packets
sudo apt install libgl1-mesa-dev libwayland-dev libxkbcommon-dev libglu1-mesa-dev make cmake g++ build-essential pkg-config -y
sudo apt install libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev -y

cmake .
make
