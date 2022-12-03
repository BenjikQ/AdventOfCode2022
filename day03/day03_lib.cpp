#include "day03_lib.hpp"

#include <cctype>
#include <string>

#include <range/v3/all.hpp>

#include <iostream>

[[nodiscard]] std::vector<std::string> readData(std::istream& is) {
    std::vector<std::string> data{};
    std::string s;
    while (is >> s) {
        data.push_back(s);
    }
    return data;
}

static constexpr int priority(unsigned char c) {
    return std::islower(c) ? c - 'a' + 1 : c - 'A' + 27;
}

[[nodiscard]] int part1::sumOfPriorities(const std::vector<std::string>& data) {
    auto rng = data
            | ranges::view::transform([](const auto& s) {
                const auto middle = std::next(std::cbegin(s), std::size(s) / 2);
                const auto c =  ranges::find_first_of(std::cbegin(s), middle,
                                                      std::next(middle), std::cend(s));
                return priority(*c);
            });
    return ranges::accumulate(rng, 0);
}



[[nodiscard]] int part2::sumOfPriorities(const std::vector<std::string>& data) {
    auto rng = data
                | ranges::view::chunk(3)
                | ranges::view::transform([](auto&& r) {
                    auto s1 = r[0];
                    auto s2 = r[1];
                    auto s3 = r[2];
                    ranges::sort(s1);
                    ranges::sort(s2);
                    ranges::sort(s3);

                    auto rng1 = ranges::view::set_intersection(s1, s2);
                    auto rng2 = ranges::view::set_intersection(rng1, s3);
                    return priority(ranges::front(rng2));
                });

    return ranges::accumulate(rng, 0);
}
