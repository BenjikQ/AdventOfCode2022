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

[[nodiscard]] int maxCalories(std::istream &is, int n) {
    std::vector<int> v;
    int sum{};
    std::string s;
    while (std::getline(is, s)) {
        if (s.empty()) {
            v.emplace_back(sum);
            sum = 0;
        } else {
            sum += *toInt(s);
        }
    }
    v.emplace_back(sum);
    ranges::sort(v, std::greater{});
    return ranges::accumulate(v | ranges::view::take(n), 0);
}
