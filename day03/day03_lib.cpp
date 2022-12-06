#include "day03_lib.hpp"

#include <iterator>

#include <range/v3/all.hpp>

Data readData(std::istream& is) {
    Data data;
    data.reserve(500);

    ranges::copy(ranges::istream_view<std::string>(is), std::back_inserter(data));
    return data;
}

[[nodiscard]] static constexpr int priority(unsigned char ch) {
    return std::islower(ch) ? ch - 'a' + 1 : ch - 'A' + 27;
}

template<typename Range>
[[nodiscard]] int calculatePriority(Range&& range) {
    auto rucksacks = range | ranges::to<Data>;
    ranges::for_each(rucksacks, ranges::sort);

    const auto intersections = ranges::accumulate(rucksacks, rucksacks[0], [](const auto& intersection, const auto& rucksack) {
       return ranges::view::set_intersection(intersection, rucksack) | ranges::to<std::string>;
    });
    return priority(ranges::front(intersections));
}

[[nodiscard]] int sumOfPriorities(const Data& data) {
    auto rng = data
            | ranges::view::transform([](auto&& r) {
                const auto middle = ranges::next(std::cbegin(r), ranges::distance(r) / 2);
                const auto ch =  *ranges::find_first_of(ranges::cbegin(r), middle,
                                                       ranges::next(middle), ranges::cend(r));
                return priority(ch);
            });
    return ranges::accumulate(rng, 0);
}

int sumOfPriorities(const Data& data, int n) {
    if (n == 1) {
        return sumOfPriorities(data);
    }
    auto rng = data | ranges::view::chunk(n);
    return ranges::accumulate(rng, 0, [](auto sum, auto&& rucksacks) {
       return sum + calculatePriority(rucksacks);
    });
}
