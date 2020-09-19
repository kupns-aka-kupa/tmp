#ifndef CONVOLUTION_HPP
#define CONVOLUTION_HPP

template<typename... Args>
auto SumWithTreshold(Args... args, int treshold)
{
    return (args + ... + treshold);
}

#endif // CONVOLUTION_HPP
