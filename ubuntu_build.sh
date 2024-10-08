#!/bin/bash

sudo apt-get install libgl1-mesa-dev libwayland-dev libxkbcommon-dev libglu1-mesa-dev

cmake .
make
