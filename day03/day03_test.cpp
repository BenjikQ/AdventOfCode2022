#include "day03_lib.hpp"

#include <sstream>

#include <catch2/catch_all.hpp>

TEST_CASE( "Part 1", "[Day 03]" ) {
    auto [input, n, expected] = GENERATE(table<std::string, int, int>({
        { "aa", 1, 1 },
        { "AccD", 1, 3 },
        { "ABcxyB", 1, 28 },
        { "jwrwAswd\n"
          "pmmdZcqqoRp", 1, 23 + 16 },
        { "jwrwAswd\n"
          "pmmeZcqqoRpr", 2, 18 },
        { "kfeaifkeiaf\n"
          "gdohpoqwfddd", 2, 6 },
        { "HhHMvWLHjbv\n"
          "pakdczmWdc\n"
          "popqldalcpvmdloef\n"
          "gjsjkguzza\n", 2, 49 + 1 },
        { "vJrwpWtwJgWrhcsFMMfFFhFp\n"
          "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL\n"
          "PmmdzqPrVvPwwTWBwg\n"
          "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn\n"
          "ttgJtRGJQctTZtZT\n"
          "CrZsJsPPZsGzwwsLwLmpwMDw", 3, 18 + 52 },
    }));

    std::stringstream ss{ input };
    const auto data = readData(ss);
    CHECK(sumOfPriorities(data, n) == expected );
}
