#ifndef ADVENTOFCODE2022_DAY02_LIB_HPP
#define ADVENTOFCODE2022_DAY02_LIB_HPP

#include <istream>
#include <utility>
#include <vector>

[[nodiscard]] std::vector<std::pair<char, char>> readData(std::istream& is);
[[nodiscard]] int calculateScore(const std::vector<std::pair<char, char>>& data);

#endif // ADVENTOFCODE2022_DAY02_LIB_HPP
