#!/bin/sh

echo "Compile times:"
echo "-------------------- GCC -----------------"
echo "V2 : "
time g++ bench_compil_v2.cpp src/image.cpp -I include -std=c++20
echo "V3 : "
time g++ bench_compil_v3.cpp src/image.cpp -I include -std=c++20 -lasmjit

echo "-------------------- Clang ---------------"
echo "V2 : "
time clang bench_compil_v2.cpp src/image.cpp -I include -std=c++20
echo "V3 : "
time clang bench_compil_v3.cpp src/image.cpp -I include -std=c++20

rm a.out
