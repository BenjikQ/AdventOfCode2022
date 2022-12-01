#ifndef ADVENTOFCODE2022_DAY01_LIB_HPP
#define ADVENTOFCODE2022_DAY01_LIB_HPP

#include <istream>
#include <vector>

[[nodiscard]] std::vector<std::vector<int>> readData(std::istream& is);
[[nodiscard]] int maxCalories(const std::vector<std::vector<int>>& data, int n);

#endif // ADVENTOFCODE2022_DAY01_LIB_HPP
