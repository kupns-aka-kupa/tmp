#ifndef FACTORIAL_HPP
#define FACTORIAL_HPP

#include <type_traits>
#include <inttypes.h>

template<uint64_t T>
struct factorial
{
    static constexpr uint64_t
    value = T * factorial<T - 1>::value;
};

template<>
struct factorial<0>
{
    static constexpr uint64_t value = 1;
};

template<uint64_t T>
using permutations = factorial<T>;

template<uint64_t N>
struct __permutations_with_replasement_h
{
    static constexpr uint64_t
    value = factorial<N>::value * __permutations_with_replasement_h<N - 1>::value;
};

template<>
struct __permutations_with_replasement_h<0>
{
    static constexpr uint64_t value = factorial<0>::value;
};

template<uint64_t N, uint64_t K>
struct  permutations_with_replacement
{
    static constexpr
    typename std::enable_if<(N >= K), uint64_t>::type
    value = factorial<N>::value / __permutations_with_replasement_h<K>::value;
};

template<uint64_t N, uint64_t K>
struct combinations
{
    static constexpr
    typename std::enable_if<(N >= K), uint64_t>::type
    value = factorial<N>::value / (factorial<K>::value * factorial<N - K>::value);
};

template<uint64_t N, uint64_t K>
struct accommodation
{
    static constexpr
    typename std::enable_if<(N >= K), uint64_t>::type
    value = factorial<N>::value / factorial<N - K>::value;
};

template<uint64_t N, uint64_t K>
struct accommodation_with_replacement
{
    static constexpr uint64_t value = N * accommodation_with_replacement<N, K - 1>::value;
};

template<uint64_t N, uint64_t K>
using constexp_pow = accommodation_with_replacement<N, K>;

template<uint64_t N>
struct accommodation_with_replacement<N, 1>
{
    static constexpr uint64_t value = N;
};

template<int64_t N, typename T>
typename std::enable_if<(N < 0), T>::type
power(T x);

template<int64_t N, typename T>
typename std::enable_if<(N == 0), T>::type
power(T);

template<int64_t N, typename T>
typename std::enable_if<(N > 0) && (N % 2 == 1), T>::type
power(T x);

template<int64_t N, typename T>
typename std::enable_if<(N > 0) && (N % 2 == 0), T>::type
power(T x);

template<int64_t N, typename T>
typename std::enable_if<(N < 0), T>::type
power(T x)
{
    return 1 / power<-N>(x);
}

template<int64_t N, typename T>
typename std::enable_if<(N == 0), T>::type
power(T)
{
    return 1;
}

template<int64_t N, typename T>
typename std::enable_if<(N > 0) && (N % 2 == 1), T>::type
power(T x)
{
    return x * power<N - 1>(x);
}

template<int64_t N, typename T>
typename std::enable_if<(N > 0) && (N % 2 == 0), T>::type
power(T x)
{
    T tmp = power<N / 2>(x);
    return tmp * tmp;
}

template<uint64_t N, typename T>
struct __fibonacci_impl
{
    static constexpr T impl(T f, T s)
    {
        return __fibonacci_impl<N - 1, T>::impl(s, f + s);
    }
};

template<typename T>
struct __fibonacci_impl<0, T>
{
    static constexpr T impl(T f, T s)
    {
        return f + s;
    }
};

template<uint64_t N = 0, typename T>
constexpr
typename std::enable_if<std::is_integral<T>::value, T>::type
fibonacci(T f, T s)
{
    return __fibonacci_impl<N, T>::impl(f, s);
}

template<int64_t N, int64_t K>
struct __is_prime_h : std::conditional<(N % K),
                            __is_prime_h<N, K - 1>,
                            std::false_type>::type
{};

template<int64_t N>
struct __is_prime_h<N, 1> : std::true_type
{};

template<int64_t N>
struct is_prime : __is_prime_h<N, N / 2>
{};

#endif // FACTORIAL_HPP
