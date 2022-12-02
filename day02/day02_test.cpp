#include "day02_lib.hpp"

#include <sstream>

#include <catch2/catch_all.hpp>

TEST_CASE( "Part 1", "[Day 02]" ) {
    auto [input, expected] = GENERATE(table<std::string, int>({
        { "A X", 1 + 3 },
        { "A Y", 2 + 6 },
        { "A Z", 3 + 0 },
        { "B X", 1 + 0 },
        { "B Y", 2 + 3 },
        { "B Z", 3 + 6 },
        { "C X", 1 + 6 },
        { "C Y", 2 + 0 },
        { "C Z", 3 + 3 },
        { "A Y\n"
          "B X\n"
          "C Z", 8 + 1 + 6 },
    }));

    std::stringstream ss{ input };
    const auto data = readData(ss);
    CHECK( part1::calculateScore(data) == expected );
}

TEST_CASE( "Part 2", "[Day 02]" ) {
    auto [input, expected] = GENERATE(table<std::string, int>({
        { "A X", 3 + 0 },
        { "A Y", 1 + 3 },
        { "A Z", 2 + 6 },
        { "B X", 1 + 0 },
        { "B Y", 2 + 3 },
        { "B Z", 3 + 6 },
        { "C X", 2 + 0 },
        { "C Y", 3 + 3 },
        { "C Z", 1 + 6 },
        { "A Y\n"
          "B X\n"
          "C Z", 4 + 1 + 7 },
    }));

    std::stringstream ss{ input };
    const auto data = readData(ss);
    CHECK( part2::calculateScore(data) == expected );
}
