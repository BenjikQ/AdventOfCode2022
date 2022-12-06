#include "day06_lib.hpp"

#include <range/v3/all.hpp>

Data readData(std::istream& is) {
    std::string data;
    is >> data;
    return data;
}

int startOfPacketMarkerPosition(const std::string& data, int n) {
    auto rng = data | ranges::view::sliding(n);
    auto position = ranges::find_if(rng, [n](auto&& signal) {
        auto s = signal | ranges::to<std::string>;
        ranges::sort(s);
        return ranges::distance(s | ranges::view::unique) == n;
    });
    return ranges::distance(ranges::begin(rng), position) + n;
}
