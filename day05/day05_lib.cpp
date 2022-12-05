#include "day05_lib.hpp"

#include <string_view>

#include <range/v3/all.hpp>

using namespace std::string_view_literals;
using namespace std::string_literals;

[[nodiscard]] std::vector<std::stack<char>> readStacks(std::istream& is) {
    std::vector<std::string> lines{};
    std::string line;
    while (std::getline(is, line)) {
        if (line.starts_with(" 1")) {
            break;
        }
        lines.push_back(line);
    }

    const auto numberOfStacks = ranges::distance(line | ranges::view::split("  "sv));
    std::vector<std::stack<char>> data(numberOfStacks);
    for (const auto& s : lines | ranges::view::reverse) {
        auto rng = s
                   | ranges::view::drop(1)
                   | ranges::view::stride(4);

        for (auto [index, ch] : rng | ranges::view::enumerate) {
            if (ch != ' ') {
                data[index].push(ch);
            }
        }
    }

    return data;
}

[[nodiscard]] std::vector<Command> readCommands(std::istream& is) {
    std::vector<Command> commands{};
    std::string _, line;
    std::getline(is, line); // skip empty line;
    while (std::getline(is, line)) {
        std::istringstream iss{ line };
        int amount, from, to;
        iss >> _ >> amount >> _ >> from >> _ >> to;
        commands.push_back({ amount, from - 1, to - 1 });
    }

    return commands;
}

[[nodiscard]] Data readData(std::istream& is) {
    auto stacks = readStacks(is);
    auto commands = readCommands(is);
    return { stacks, commands };
}

namespace part1 {
    void moveCrate(std::stack<char>& from, std::stack<char>& to, int amount) {
        while (amount--) {
            const auto top = from.top();
            from.pop();
            to.push(top);
        }
    }
}

std::string part1::moveCrates(const Data& data) {
    auto [stacks, commands] = data;
    for (const auto& command : commands) {
        moveCrate(stacks[command.from], stacks[command.to], command.amount);
    }
    auto rng = stacks | ranges::view::transform([](const auto& stack) { return stack.top(); });
    return ranges::accumulate(rng, ""s);
}

namespace part2 {
    void moveCrate(std::stack<char>& from, std::stack<char>& to, int amount) {
        std::vector<char> elements;
        while (amount--) {
            const auto top = from.top();
            from.pop();
            elements.push_back(top);
        }

        for (auto element : elements | ranges::view::reverse) {
            to.push(element);
        }
    }
}

std::string part2::moveCrates(const Data &data) {
    auto [stacks, commands] = data;
    for (const auto& command : commands) {
        moveCrate(stacks[command.from], stacks[command.to], command.amount);
    }
    auto rng = stacks | ranges::view::transform([](const auto& stack) { return stack.top(); });
    return ranges::accumulate(rng, ""s);
}
