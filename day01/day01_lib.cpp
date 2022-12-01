#include "day01_lib.hpp"

#include <charconv>
#include <iterator>
#include <optional>
#include <string>
#include <string_view>

#include <range/v3/all.hpp>

[[nodiscard]] std::optional<int> toInt(std::string_view s) {
    if (int value; std::from_chars(s.data(), s.data() + s.size(), value).ec == std::errc{}) {
        return value;
    }
    return {};
}

[[nodiscard]] std::vector<std::vector<int>> readData(std::istream &is) {
    std::string input{ std::istreambuf_iterator<char>{ is }, {} };
    constexpr std::string_view delim{"\n\n"};
    auto data = input
            | ranges::view::split(delim)
            | ranges::view::transform([](auto&& r) { return r | ranges::view::split('\n'); })
            | ranges::view::transform([](auto&& r) {
                return r | ranges::view::transform([](auto&& s) {
                    return *toInt(s | ranges::to<std::string>);
                });
            })
            | ranges::to<std::vector<std::vector<int>>>;

    return data;
}

[[nodiscard]] int maxCalories(const std::vector<std::vector<int>>& data, int n) {
    auto sumOfCalories = data
            | ranges::view::transform([](auto&& v) { return ranges::accumulate(v, 0); })
            | ranges::to<std::vector>;
    ranges::partial_sort(sumOfCalories, std::next(std::begin(sumOfCalories), n), std::greater{});
    return ranges::accumulate(sumOfCalories | ranges::view::take(n), 0);
}
