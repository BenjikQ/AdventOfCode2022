#include "day01_lib.hpp"

#include <sstream>
#include <string>

#include <catch2/catch_all.hpp>

TEST_CASE( "Part 1", "[Day 01]" ) {
    auto [input, expected] = GENERATE(table<std::string, int>({
        { "1", 1 },
        { "1\n"
          "2", 3 },
        { "1\n"
          "\n"
          "2", 2 },
        { "1\n"
          "\n"
          "2\n"
          "3\n"
          "\n"
          "4", 5 },
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
          "10000", 24000 },
    }));

    std::stringstream ss{ input };
    const auto data = readData(ss);
    CHECK( maxCalories(data, 1) == expected );
}

TEST_CASE( "Part 2", "[Day 01]" ) {
    auto [input, n, expected] = GENERATE(table<std::string, int, int>({
        { "1", 1, 1 },
        { "1\n"
        "2", 1, 3 },
        { "1\n"
        "\n"
        "2", 2, 3 },
        { "1\n"
        "\n"
        "2\n"
        "3\n"
        "\n"
        "4", 2, 9 },
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
    CHECK( maxCalories(data, n) == expected );
}
