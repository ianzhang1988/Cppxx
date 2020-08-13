#include <iostream>
#include <utility>

// some what like rust value
// https://changkun.de/modern-cpp/zh-cn/03-runtime/index.html#3-3-右值引用

class A {
public:
    int *pointer;
    A():pointer(new int(1)) { 
        std::cout << "构造" << pointer << std::endl; 
    }
    A(A& a):pointer(new int(*a.pointer)) { 
        std::cout << "拷贝" << pointer << std::endl; 
    } // 无意义的对象拷贝
    A(A&& a):pointer(a.pointer) { 
        a.pointer = nullptr;
        std::cout << "移动" << pointer << std::endl; 
    }
    ~A(){ 
        std::cout << "析构" << pointer << std::endl; 
        delete pointer; 
    }
};
// 防止编译器优化
A return_rvalue(bool test) {
    A a,b;
    if(test) return a; // 等价于 static_cast<A&&>(a);
    else return b;     // 等价于 static_cast<A&&>(b);
}

void reference(int& v) {
    std::cout << "左值引用" << std::endl;
}
void reference(int&& v) {
    std::cout << "右值引用" << std::endl;
}
template <typename T>
void pass(T&& v) {
    std::cout << "              普通传参: ";
    reference(v);
    std::cout << "       std::move 传参: ";
    reference(std::move(v));
    std::cout << "    std::forward 传参: ";
    reference(std::forward<T>(v));
    std::cout << "static_cast<T&&> 传参: ";
    reference(static_cast<T&&>(v));
}

int main() {
    std::cout << "begin:" << std::endl;
    A obj = return_rvalue(false);
    std::cout << "obj:" << std::endl;
    std::cout << obj.pointer << std::endl;
    std::cout << *obj.pointer << std::endl;


    std::cout << "传递右值:" << std::endl;
    pass(1);

    std::cout << "传递左值:" << std::endl;
    int v = 1;
    pass(v);

    return 0;
}