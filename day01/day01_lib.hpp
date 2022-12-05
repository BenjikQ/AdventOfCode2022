#ifndef ADVENTOFCODE2022_DAY01_LIB_HPP
#define ADVENTOFCODE2022_DAY01_LIB_HPP

#include <istream>
#include <vector>

using Data = std::vector<std::vector<int>>;

[[nodiscard]] Data readData(std::istream& is);
[[nodiscard]] int sumMaxCalories(const Data& data, int n);

#endif // ADVENTOFCODE2022_DAY01_LIB_HPP
