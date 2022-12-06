# Advent of Code 2022

- [x] Day 1
- [x] Day 2
- [x] Day 3
- [x] Day 4
- [x] Day 5
- [x] Day 6

## Requirements
- C++ compiler supporting C++20 standard
- CMake >= 3.24
- Conan >= 1.54

## Usage
```bash
git clone https://github.com/BenjikQ/AdventOfCode2022.git
cd AdventOfCode2022
mkdir build
cd build
conan install .. -pr:h <profile> -pr:b <profile> --build missing
cmake -DCMAKE_BUILD_TYPE=Release -S .. -B . # optionally specify compiler
cmake --build . -j <N> # number of threads
cd dayXX # day number
ctest --verbose # for testing purpose
./dayXX input.txt
```
