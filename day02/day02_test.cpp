#include "day02_lib.hpp"

#include <sstream>

#include <catch2/catch_all.hpp>

TEST_CASE( "Day 2" ) {
    auto [input, moves, moveAndResult] = GENERATE(table<std::string, int, int>({
          { "A X", 1 + 3, 3 + 0 },
          { "A Y", 2 + 6, 1 + 3 },
          { "A Z", 3 + 0, 2 + 6 },
          { "B X", 1 + 0, 1 + 0 },
          { "B Y", 2 + 3, 2 + 3 },
          { "B Z", 3 + 6, 3 + 6 },
          { "C X", 1 + 6, 2 + 0 },
          { "C Y", 2 + 0, 3 + 3 },
          { "C Z", 3 + 3, 1 + 6 },
          { "A Y\n"
            "B X\n"
            "C Z", 8 + 1 + 6, 4 + 1 + 7 },
    }));

    std::stringstream ss{ input };
    const auto data = readData(ss);
    CHECK( calculateScore<MovesStrategy>(data) == moves );
    CHECK( calculateScore<MoveAndResultStrategy>(data) == moveAndResult );
}
