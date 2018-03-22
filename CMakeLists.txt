cmake_minimum_required(VERSION 3.9)
project(OSProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(OSProject main.cpp cpu.cpp cpu.h DMA.cpp DMA.h PCB.cpp PCB.h)