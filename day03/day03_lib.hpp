#ifndef ADVENTOFCODE2022_DAY02_LIB_HPP
#define ADVENTOFCODE2022_DAY02_LIB_HPP

#include <istream>
#include <string>
#include <vector>

[[nodiscard]] std::vector<std::string> readData(std::istream& is);

namespace part1 {
    [[nodiscard]] int sumOfPriorities(const std::vector<std::string>& data);
}

namespace part2 {
    [[nodiscard]] int sumOfPriorities(const std::vector<std::string>& data);
}

#endif // ADVENTOFCODE2022_DAY02_LIB_HPP
