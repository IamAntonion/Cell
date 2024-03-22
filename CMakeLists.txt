cmake_minimum_required(VERSION 3.11)

project(TapeInter CXX)
set(CMAKE_CXX_STANDARD 17)
 
add_executable(Tape 
               src/main.cpp 
               src/FileTape.h 
               src/FileTape.cpp 
               src/Interface.h 
               src/SorterTape.h 
               src/SorterTape.cpp)