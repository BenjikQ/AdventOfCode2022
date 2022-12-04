#include "day04_lib.hpp"

#include <fstream>

#include <fmt/core.h>

void help() {
    fmt::print("Usage: day04 <input_file>");
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        help();
        return 1;
    }

    std::ifstream input{ argv[1] };
    if (!input.is_open()) {
        fmt::print(stderr, "File not found or failed to open.\n");
        return 2;
    }

    const auto data = readData(input);
    fmt::print("Day 4 | part 1: {}\n", countFullyOverlapping(data));
    fmt::print("Day 4 | part 2: {}\n", countOverlapping(data));
}
