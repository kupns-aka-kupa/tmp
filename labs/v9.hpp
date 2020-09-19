#pragma GCC optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("avx")
#include <x86intrin.h>
#include <iostream>
#include <math.h>
#include <vector>

/**
 * @href https://www.wolframalpha.com/input/?i=Sum%5BProduct%5BSin%5BPi+%28i%2Fk%29%5D%2C+%7Bi%2C+1%2C+k+-+1%7D%5D%2C+%7Bk%2C+2%2C+n%7D%5D
 * @param n > 2
 * @return Sum[Product[Sin[Pi (i / k)], {i, 1, k - 1}], {k, 2, n}] -> 3.00..01
 * @exec_time ~= .686s; n = 10000;
 */

double expression_v9(size_t n)
{
    std::vector<double> sum(n - 2), mul(n - 2);

    for (size_t k = 2; k <= n; k++) {
        for (size_t i = 1; i <= k - 1; i++) {
            mul[i - 1] = std::sin(M_PI * i / k);
        }
        sum[k - 2] = std::accumulate(mul.begin(), mul.begin() + k - 1, 1.0, std::multiplies<double>());
    }
    return std::accumulate(sum.begin(), sum.end(), .0);
}
