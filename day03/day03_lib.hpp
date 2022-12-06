#ifndef ADVENTOFCODE2022_DAY02_LIB_HPP
#define ADVENTOFCODE2022_DAY02_LIB_HPP

#include <istream>
#include <string>
#include <vector>

using Data = std::vector<std::string>;

[[nodiscard]] Data readData(std::istream& is);
[[nodiscard]] int sumOfPriorities(const Data& data, int n);

#endif // ADVENTOFCODE2022_DAY02_LIB_HPP
