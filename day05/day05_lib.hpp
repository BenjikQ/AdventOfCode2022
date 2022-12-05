#ifndef ADVENTOFCODE2022_DAY02_LIB_HPP
#define ADVENTOFCODE2022_DAY02_LIB_HPP

#include <istream>
#include <stack>
#include <string>
#include <vector>

struct Command {
    int amount{};
    int from{};
    int to{};
};

using Data = std::pair<std::vector<std::stack<char>>, std::vector<Command>>;

[[nodiscard]] Data readData(std::istream& is);
[[nodiscard]] std::string moveCrates(const Data& data);


#endif // ADVENTOFCODE2022_DAY02_LIB_HPP
