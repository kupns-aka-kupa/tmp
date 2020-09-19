#include <iostream>
#include <vector>

static std::vector<size_t> cache = std::vector<size_t>(0xFFFF);

size_t factorial(size_t i) {
    return i == 0 ? 1 : i * factorial(i - 1);
}

double expression_v1(size_t n) {
    double s = 0;
    for (size_t i = 1; i <= n; i++) {
        double m = 1;
        for (size_t j = 1; j <= i; j++) {
            auto at = &cache.at(i - 1);
            if (!*at) *at = factorial(i);
            m *= (double) cache[j - 1] / *at;
        }
        s += m;
    }
    return s;
}

