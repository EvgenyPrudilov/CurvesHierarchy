# CurvesHierarchy
A small program in C++ that implements a simple support of 3D curves hierarchy.

# Overview
The project compiles with g++.
The library files are curves.cpp and curves.hpp .
The main.cpp uses this library.

File test.cpp contains the test program (not complete: I need more data for full testing).
To compile it, you need the Google-test library(see below how to install it).

# How To

### compile main and library:
make 
### run code:
make run
### run tests:
make run-test
### install Google-test (on linux):
make install-google-test
### compile library:
make libcurves.so
### clean directory up:
make clean
