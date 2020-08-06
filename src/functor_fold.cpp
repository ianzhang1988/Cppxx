#include <iostream>

struct sum 
{
    double val;

    sum(double a) : val(a) {}

    sum operator()(double a) { return val + a; }

    operator double() const { return val; }
};

sum f(double a)
{
    return a;
}

int main()
{
    std::cout << f(1)(2)(3)(4) << std::endl;
}