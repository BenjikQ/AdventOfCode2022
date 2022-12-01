#include "day01_lib.hpp"

#include <charconv>
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
    std::vector<std::vector<int>> data{};
    std::vector<int> values;
    std::string s;
    while (std::getline(is, s)) {
        if (s.empty()) {
            data.push_back(values);
            values.clear();
        } else {
            values.emplace_back(*toInt(s));
        }
    }
    data.push_back(values);
    return data;
}

[[nodiscard]] int maxCalories(const std::vector<std::vector<int>>& data, int n) {
    auto sumOfCalories = data | ranges::view::transform([](const auto& v) {
        return ranges::accumulate(v, 0);
    }) | ranges::to<std::vector>;
    ranges::partial_sort(sumOfCalories, std::next(std::begin(sumOfCalories), n), std::greater{});
    return ranges::accumulate(sumOfCalories | ranges::view::take(n), 0);
}
