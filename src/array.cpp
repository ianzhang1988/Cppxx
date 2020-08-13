#include <iostream>
#include <array>
#include <algorithm>

template<typename T>
void show(T a) {
    for(auto i : a){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}

int main() {
    std::array<int, 5> a = {1,2,3,4,5};

    std::cout<<"a[2]:"<<a[2]<<std::endl;

    show(a);

    std::sort(a.begin(), a.end(), [](int a, int b){return a>b;});

    show(a);
}