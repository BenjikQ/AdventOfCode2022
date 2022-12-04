#include "day04_lib.hpp"

#include <sstream>

#include <catch2/catch_all.hpp>

TEST_CASE( "Part 1", "[Day 04]" ) {
    auto [input, expected] = GENERATE(table<std::string, int>({
        { "0-1,1-2", 0 },
        { "0-1,1-1", 1 },
        { "1-1,0-1", 1 },
        { "1-1,1-1", 1 },
        { "1-3,2-4", 0 },
        { "2-5,7-10", 0 },
        { "3-8,5-7\n"
          "1-2,0-4", 2 },
        { "2-4,6-8\n"
          "2-3,4-5\n"
          "5-7,7-9\n"
          "2-8,3-7\n"
          "6-6,4-6\n"
          "2-6,4-8", 2 },
    }));

    std::stringstream ss{ input };
    const auto data = readData(ss);
    CHECK(  countFullyOverlapping(data) == expected );
}
