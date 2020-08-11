#include <iostream>


template<typename A, typename B>
auto add(A a, B b) {
    return a+b;
}

// decltype(auto)
static std::string g_str;
std::string  lookup1(){return std::string("");};
std::string& lookup2(){return g_str;};

decltype(auto) look_up_a_string_1() {
    return lookup1();
}
decltype(auto) look_up_a_string_2() {
    return lookup2();
}

// std::string look_up_a_string_1() {
//     return lookup1();
// }
// std::string& look_up_a_string_2() {
//     return lookup2();
// }

int main() {
    auto a = 1;
    auto b = 2.5;
    decltype(a+b) c = a+b;

    std::cout<< "a:" << a << std::endl
             << "b:" << a << std::endl
             << "c:" << c << std::endl;

    if (std::is_same<decltype(c), int>::value)
        std::cout << "type c == int" << std::endl;
    if (std::is_same<decltype(c), float>::value)
        std::cout << "type c == float" << std::endl;
    if (std::is_same<decltype(c), double>::value)
        std::cout << "type c == double" << std::endl;


    std::cout<< "add(2, 5.4): "<<add(2, 5.4)<<std::endl;

    g_str="hi";
    std::cout<< "look_up_a_string_2: "<<look_up_a_string_2()<<std::endl;
}


