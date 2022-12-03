#include "day03_lib.hpp"

#include <sstream>

#include <catch2/catch_all.hpp>

TEST_CASE( "Part 1", "[Day 03]" ) {
    auto [input, expected] = GENERATE(table<std::string, int>({
        { "aa", 1 },
        { "AA", 27 },
        { "aBcxyB", 28 },
        { "jwrwAswd\n"
          "pmmdZcqqoRp", 23 + 16 },
        { "vJrwpWtwJgWrhcsFMMfFFhFp\n"
          "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL\n"
          "PmmdzqPrVvPwwTWBwg\n"
          "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn\n"
          "ttgJtRGJQctTZtZT\n"
          "CrZsJsPPZsGzwwsLwLmpwMDw", 16 + 38 + 42 + 22 + 20 + 19 },
    }));

    std::stringstream ss{ input };
    const auto data = readData(ss);
    CHECK( part1::sumOfPriorities(data) == expected );
}

TEST_CASE( "Part 2", "[Day 03]" ) {
    auto [input, expected] = GENERATE(table<std::string, int>({
        { "a\n"
          "a\n"
          "a", 1 },
        { "abC\n"
          "Ccxde\n"
          "XDCf", 29 },
        { "vJrwpWtwJgWrhcsFMMfFFhFp\n"
          "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL\n"
          "PmmdzqPrVvPwwTWBwg\n"
          "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn\n"
          "ttgJtRGJQctTZtZT\n"
          "CrZsJsPPZsGzwwsLwLmpwMDw", 18 + 52 },
    }));

    std::stringstream ss{ input };
    const auto data = readData(ss);
    CHECK( part2::sumOfPriorities(data) == expected );
}
