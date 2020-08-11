#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <initializer_list>

////////////////////// 别名 //////////////////////////
template<typename T, typename U>
class MagicType {
public:
    T dark;
    U magic;
};

// 不合法
//template<typename T>
//typedef MagicType<std::vector<T>, std::string> FakeDarkMagic;

typedef int (*process)(void *);
using NewProcess = int(*)(void *);
template<typename T>
using TrueDarkMagic = MagicType<std::vector<T>, std::string>;

template<typename T = int, typename U = int> // 默认参数
auto add(T x, U y) -> decltype(x+y) {
    return x+y;
}

////////////////////// 变长参数模板 //////////////////////////

template<typename... Ts> class Magic;

// compile error: has incomplete type and cannot be defined; hmm, why
// class Magic<int,
//             std::vector<int>,
//             std::map<std::string,
//             std::vector<int>>> darkMagic;

template<typename... Ts>
void magic(Ts... args) {
    std::cout << sizeof...(args) << std::endl;
}

template<typename T_last>
void myprintf(T_last v) {
    std::cout<<v<<std::endl;
}

template<typename T, typename... Ts>
void myprintf(T v, Ts... args) {
    std::cout<<v<<" ";
    myprintf(args...);
}

// C++ 17
// template<typename T0, typename... T>
// void myprintf2(T0 t0, T... t) {
//     std::cout << t0 << std::endl;
//     if constexpr (sizeof...(t) > 0) printf2(t...);
// }

// too complex ...
// template<typename T, typename... Ts>
// auto myprintf3(T value, Ts... args) {
//     std::cout << value << std::endl;
//     (void) std::initializer_list<T>{([&args] {
//         std::cout << args << std::endl;
//     }(), value)...};
// }

////////////////////// 折叠表达式 //////////////////////////
// C++ 17
// template<typename ... T>
// auto sum(T ... t) {
//     return (t + ...);
// }

int main() {
    TrueDarkMagic<bool> you;

    magic(); 
    magic(1);
    magic(1, "");

    myprintf("hi", 1,"+","2=",1+2);

    // std::cout << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;
    // std::cout << sum(1, 2, 3, 4.0, 5, 6, 7.0, 8, 9, 10) << std::endl;

}