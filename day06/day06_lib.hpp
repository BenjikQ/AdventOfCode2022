#ifndef ADVENTOFCODE2022_DAY02_LIB_HPP
#define ADVENTOFCODE2022_DAY02_LIB_HPP

#include <istream>
#include <string>

using Data = std::string;

[[nodiscard]] Data readData(std::istream& is);
[[nodiscard]] int startOfPacketMarkerPosition(const std::string& data, int n);

#endif // ADVENTOFCODE2022_DAY02_LIB_HPP
