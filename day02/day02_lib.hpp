#ifndef ADVENTOFCODE2022_DAY02_LIB_HPP
#define ADVENTOFCODE2022_DAY02_LIB_HPP

#include <istream>
#include <utility>
#include <vector>

#include <range/v3/all.hpp>

using Data = std::vector<std::pair<char, char>>;

[[nodiscard]] Data readData(std::istream& is);

struct MovesStrategy {
    static constexpr auto mod = [](int a, int b) {
        return (b + (a % b)) % b;
    };

    [[nodiscard]] static constexpr int calculate(char first, char second) {
        auto result = second - 'X' + 1;
        switch (mod((second - 'X') - (first - 'A'), 3)) {
            case 0: result += 3; break;
            case 1: result += 6; break;
        }
        return result;
    }
};

struct MoveAndResultStrategy {
    [[nodiscard]] static constexpr int calculate(char first, char second) {
        auto result = (first - 'A' + second - 'X' + 2) % 3 + 1;
        switch (second) {
            case 'Y': result += 3; break;
            case 'Z': result += 6; break;
        }
        return result;
    }
};

template<typename Strategy>
[[nodiscard]] int calculateScore(const Data& data) {
    auto rng = data
            | ranges::view::transform([](auto&& symbols) {
                return Strategy::calculate(symbols.first, symbols.second);
            });
    return ranges::accumulate(rng, 0);
}

#endif // ADVENTOFCODE2022_DAY02_LIB_HPP
