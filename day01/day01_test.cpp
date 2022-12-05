#include "day01_lib.hpp"

#include <sstream>

#include <catch2/catch_all.hpp>

TEST_CASE( "Day 1" ) {
    auto [input, n, expected] = GENERATE(table<std::string, int, int>({
        { "1", 1, 1 },
        { "1\n"
          "2", 1, 3 },
        { "1\n"
          "2\n"
          "\n"
          "3", 1, 3 },
        { "1\n"
          "5\n"
          "\n"
          "4\n", 1, 6 },
        { "2\n"
          "3\n"
          "\n"
          "14\n", 1, 14},
        { "1\n"
          "2\n"
          "\n"
          "3", 2, 6 },
        { "1\n"
          "\n"
          "2\n"
          "3\n"
          "\n"
          "4", 1, 5 },
        { "1\n"
          "\n"
          "2\n"
          "3\n"
          "\n"
          "4", 2, 9 },
        { "1\n"
          "\n"
          "2\n"
          "3\n"
          "\n"
          "4", 3, 10 },
        { "1000\n"
          "2000\n"
          "3000\n"
          "\n"
          "4000\n"
          "\n"
          "5000\n"
          "6000\n"
          "\n"
          "7000\n"
          "8000\n"
          "9000\n"
          "\n"
          "10000", 1, 24000 },
        { "1000\n"
          "2000\n"
          "3000\n"
          "\n"
          "4000\n"
          "\n"
          "5000\n"
          "6000\n"
          "\n"
          "7000\n"
          "8000\n"
          "9000\n"
          "\n"
          "10000", 3, 45000 },
    }));

    std::stringstream ss{ input };
    const auto data = readData(ss);
    CHECK( sumMaxCalories(data, n) == expected );
}
