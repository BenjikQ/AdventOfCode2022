#include "day02_lib.hpp"

#include <unordered_map>

#include <range/v3/all.hpp>

enum class Shape {
    Rock = 1,
    Paper = 2,
    Scissors = 3,
};

static const std::unordered_map<char, Shape> shapes{
    { 'A', Shape::Rock },
    { 'B', Shape::Paper },
    { 'C', Shape::Scissors },
    { 'X', Shape::Rock },
    { 'Y', Shape::Paper },
    { 'Z', Shape::Scissors },
};

enum class Result {
    Lose = 0,
    Draw = 3,
    Win = 6,
};

static const std::unordered_map<char, Result> results{
    { 'X', Result::Lose },
    { 'Y', Result::Draw },
    { 'Z', Result::Win },
};

[[nodiscard]] Result result(Shape opponent, Shape player) {
    if (opponent == player) return Result::Draw;

    if (opponent == Shape::Rock && player == Shape::Paper) return Result::Win;
    if (opponent == Shape::Rock && player == Shape::Scissors) return Result::Lose;

    if (opponent == Shape::Paper && player == Shape::Rock) return Result::Lose;
    if (opponent == Shape::Paper && player == Shape::Scissors) return Result::Win;

    if (opponent == Shape::Scissors && player == Shape::Rock) return Result::Win;
    if (opponent == Shape::Scissors && player == Shape::Paper) return Result::Lose;
}

[[nodiscard]] Shape shape(Shape opponent, Result result) {
    if (result == Result::Draw) return opponent;

    if (result == Result::Lose && opponent == Shape::Rock) return Shape::Scissors;
    if (result == Result::Lose && opponent == Shape::Paper) return Shape::Rock;
    if (result == Result::Lose && opponent == Shape::Scissors) return Shape::Paper;

    if (result == Result::Win && opponent == Shape::Rock) return Shape::Paper;
    if (result == Result::Win && opponent == Shape::Paper) return Shape::Scissors;
    if (result == Result::Win && opponent == Shape::Scissors) return Shape::Rock;
}

[[nodiscard]] std::vector<std::pair<char, char>> readData(std::istream& is) {
    std::vector<std::pair<char, char>> data{};
    char a, b;
    while (is >> a >> b) {
        data.emplace_back(a, b);
    }
    return data;
}

[[nodiscard]] int part1::calculateScore(const std::vector<std::pair<char, char>>& data) {
    auto rng = data
            | ranges::view::transform([](auto&& r) {
                const auto opponent = shapes.at(r.first);
                const auto player = shapes.at(r.second);
                return static_cast<int>(result(opponent, player)) + static_cast<int>(player);
            });
    return ranges::accumulate(rng, 0);
}

[[nodiscard]] int part2::calculateScore(const std::vector<std::pair<char, char>>& data) {
    auto rng = data
               | ranges::view::transform([](auto&& r) {
        const auto opponent = shapes.at(r.first);
        const auto result = results.at(r.second);
        return static_cast<int>(result) + static_cast<int>(shape(opponent, result));
    });
    return ranges::accumulate(rng, 0);
}
