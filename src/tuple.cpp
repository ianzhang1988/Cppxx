#include <iostream>
#include <tuple>

std::tuple<int, double, std::string> f() {
    return std::make_tuple(1, 2.3, "456");
}

int main() {
    // C++ 17
    // auto [x, y, z] = f();
    // std::cout << x << ", " << y << ", " << z << std::endl;
    
    int myint;
    std::string mystring;

    auto mytuple = f();
    std::tie (myint, std::ignore, mystring) = mytuple;

    std::cout << myint << ", " << mystring << std::endl;
    std::cout << "[1]: " << std::get<1>(mytuple) << std::endl;
    return 0;
}