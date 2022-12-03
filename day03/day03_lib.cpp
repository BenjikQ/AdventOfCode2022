#include "day03_lib.hpp"

#include <cctype>
#include <string>

#include <range/v3/all.hpp>

[[nodiscard]] std::vector<std::string> readData(std::istream& is) {
    std::vector<std::string> data{};
    std::string s;
    while (is >> s) {
        data.push_back(s);
    }
    return data;
}

[[nodiscard]] int sumOfPriorities(const std::vector<std::string>& data) {
    auto priority = [](unsigned char c) -> int {
        return std::islower(c) ? c - 'a' + 1 : c - 'A' + 27;
    };
    auto rng = data
            | ranges::view::transform([&priority](const auto& s) {
                const auto middle = std::next(std::cbegin(s), std::size(s) / 2);
                const auto c =  ranges::find_first_of(std::cbegin(s), middle,
                                                      std::next(middle), std::cend(s));
                return priority(*c);
            });
    return ranges::accumulate(rng, 0);
}
