#include <iostream>

constexpr int fibonacci(int n) {
    if(n == 1) return 1;
    if(n == 2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    std::cout<< "fibonacci(7): " <<fibonacci(7) <<std::endl;

    char a[fibonacci(7)];
    std::cout<< "char [fibonacci(7)] size: "<< sizeof(a);
}