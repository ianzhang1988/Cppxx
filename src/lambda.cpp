#include <iostream>
#include <utility>
#include <memory>

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

int main () {
    int v1 = 0;
    int v2 = 0;

    auto lamb1 = [v1](){
        std::cout<<v1<<std::endl;
        };

    v1 = 2;
    lamb1();

    auto lamb2 = [&v1](){
        v1 = 3;
        std::cout<<v1<<std::endl;
        };

    lamb2();
    std::cout<<v1<<std::endl;

    auto lamb3 = [=](auto x){
        std::cout<<"v1:"<<v1<<" v2:"<<v2<<" x:"<<x<<std::endl;
        };

    lamb3("hi");

    auto lamb4 = [&](auto x){
        v1 = 7; v2=8;
        std::cout<<" x:"<<x<<std::endl;
        };

    lamb4(6);
    std::cout<<"v1:"<<v1<<" v2:"<<v2<<std::endl;

    auto important = make_unique<int>(1);
    auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int {
        return x+y+v1+(*v2);
    };
    std::cout << add(3,4) << std::endl;
}