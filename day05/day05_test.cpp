#include "day05_lib.hpp"

#include <sstream>

#include <catch2/catch_all.hpp>

TEST_CASE( "Part 1", "[Day 05]" ) {
    auto [input, expected] = GENERATE(table<std::string, std::string>({
        { "[C]    \n"
          "[A] [B]\n"
          " 1   2 \n"
          "\n"
          "move 1 from 1 to 2\n", "AC" },
        { "[C]    \n"
          "[A] [B]\n"
          " 1   2 \n"
          "\n"
          "move 2 from 1 to 2\n"
          "move 1 from 2 to 1\n", "AC" },
        { "    [D]    \n"
          "[N] [C]    \n"
          "[Z] [M] [P]\n"
          " 1   2   3 \n"
          "\n"
          "move 1 from 2 to 1\n"
          "move 3 from 1 to 3\n"
          "move 2 from 2 to 1\n"
          "move 1 from 1 to 2\n", "CMZ" },
    }));

    std::stringstream ss{ input };
    const auto data = readData(ss);
    CHECK( moveCrates(data) == expected );
}
