cmake_minimum_required(VERSION 3.20)
project(MagiqueNumbers)
add_executable(MagiqueNumbers src/Magicnumbers.cpp)
set_target_properties(MagiqueNumbers PROPERTIES CXX_STANDARD 23 CXX_STANDARD_REQUIRED ON)
