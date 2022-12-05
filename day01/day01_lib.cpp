#include "day01_lib.hpp"

#include <charconv>
#include <string_view>

#include <range/v3/all.hpp>

[[nodiscard]] int toInt(std::string_view s) {
    if (int value; std::from_chars(s.data(), ranges::next(s.data(), s.size()), value).ec == std::errc{}) {
        return value;
    }
    return {};
}

Data readData(std::istream& is) {
    std::vector<std::vector<int>> data{};
    data.reserve(500);

    std::string line;
    std::vector<int> calories{};
    while (std::getline(is, line)) {
        if (line.empty()) {
            data.push_back(calories);
            calories.clear();
        } else {
            if (const auto number = toInt(line)) [[likely]] {
                calories.push_back(number);
            }
        }
    }

    data.push_back(calories);
    return data;
}

int sumMaxCalories(const Data& data, int n) {
    auto sumOfCalories = data
            | ranges::view::transform([](auto&& calories) { return ranges::accumulate(calories, 0); })
            | ranges::to<std::vector>;
    ranges::partial_sort(sumOfCalories, ranges::next(std::begin(sumOfCalories), n), std::greater{});
    return ranges::accumulate(sumOfCalories | ranges::view::take(n), 0);
}
