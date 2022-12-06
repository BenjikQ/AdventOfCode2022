#include "day06_lib.hpp"

#include <sstream>

#include <catch2/catch_all.hpp>

TEST_CASE( "Day 6" ) {
    auto [input, n, expected] = GENERATE(table<std::string, int, int>({
        { "ab", 1, 1 },
        { "ab", 2, 2 },
        { "babacd", 3, 5 },
        { "abcd", 4, 4 },
        { "abcad", 4, 5 },
        { "bbceedcbabcdde", 4, 8 },
        { "mjqjpqmgbljsphdztnvjfqwrcgsmlb", 4, 7 },
        { "bvwbjplbgvbhsrlpgdmjqwftvncz", 4, 5 },
        { "nppdvjthqldpwncqszvftbrmjlhg", 4, 6 },
        { "nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg", 4, 10 },
        { "zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw", 4, 11 },
    }));

    std::stringstream ss{ input };
    const auto data = readData(ss);
    CHECK( startOfPacketMarkerPosition(data, n) == expected );
}
