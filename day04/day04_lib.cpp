#include "day04_lib.hpp"

#include <charconv>
#include <optional>
#include <string_view>
#include <utility>

#include <range/v3/all.hpp>

struct Range {
    int min{};
    int max{};
};

[[nodiscard]] std::optional<int> toInt(std::string_view s) {
    if (int value; std::from_chars(s.data(), s.data() + s.size(), value).ec == std::errc{}) {
        return value;
    }
    return {};
}

[[nodiscard]] constexpr bool contains(Range r1, Range r2) {
    auto distance = [](Range& r) { return r.max - r.min; };
    if (distance(r1) > distance(r2)) {
        std::swap(r1, r2);
    }

    return r1.min >= r2.min && r1.max <= r2.max;
}

[[nodiscard]] constexpr bool overlap(Range r1, Range r2) {
    if (r1.min > r2.min) {
        std::swap(r1, r2);
    }

    return r1.max >= r2.min;
}

[[nodiscard]] std::vector<std::string> readData(std::istream& is) {
    std::vector<std::string> data{};
    std::string s;
    while (is >> s) {
        data.push_back(s);
    }
    return data;
}

[[nodiscard]] int countFullyOverlapping(const std::vector<std::string>& data) {
    auto rng = data
            | ranges::view::transform([](const auto& s) {
                  const auto assignments = s
                    | ranges::view::split(',')
                    | ranges::view::transform([](const auto& assignment) {
                        auto&& r = assignment | ranges::view::split('-');
                        return r | ranges::view::transform([](const auto& p) {
                          return *toInt(p | ranges::to<std::string>);
                        });
                    })
                    | ranges::to<std::vector<std::vector<int>>>;
                  Range r1{ assignments[0][0], assignments[0][1] };
                  Range r2{ assignments[1][0], assignments[1][1] };
                  return std::pair{ r1, r2 };
            });
    return ranges::count_if(rng, [](const auto& assignments) {
        return contains(assignments.first, assignments.second);
    });
}

int countOverlapping(const std::vector<std::string>& data) {
    auto rng = data
           | ranges::view::transform([](const auto& s) {
                const auto assignments = s
                 | ranges::view::split(',')
                 | ranges::view::transform([](const auto& assignment) {
                    auto&& r = assignment | ranges::view::split('-');
                    return r | ranges::view::transform([](const auto& p) {
                        return *toInt(p | ranges::to<std::string>);
                    });
                })
                 | ranges::to<std::vector<std::vector<int>>>;
            Range r1{ assignments[0][0], assignments[0][1] };
            Range r2{ assignments[1][0], assignments[1][1] };
            return std::pair{ r1, r2 };
    });
    return ranges::count_if(rng, [](const auto& assignments) {
        return overlap(assignments.first, assignments.second);
    });
}
