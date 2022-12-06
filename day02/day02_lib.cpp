#include "day02_lib.hpp"

Data readData(std::istream& is) {
    Data data;
    data.reserve(500);

    char a, b;
    while (is >> a >> b) {
        data.emplace_back(a, b);
    }
    return data;
}
