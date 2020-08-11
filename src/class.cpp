/////// 继承构造

#include <iostream>
class Base {
public:
    int value1;
    int value2;
    Base() {
        value1 = 1;
    }
    Base(int value) : Base() { // 委托 Base() 构造函数
        value2 = value;
    }
};
class Subclass : public Base {
public:
    using Base::Base; // 继承构造
};

/////// 显式虚函数重载

struct Base2 {
    virtual void foo(int);
    virtual void foo() final;
};
struct SubClass: Base2 {
    virtual void foo(int) override; // 合法
    // virtual void foo(float) override; // 非法, 父类没有此虚函数
};

struct SubClass1 final: Base2 {
}; // 合法

// struct SubClass2 : SubClass1 {
// }; // 非法, SubClass1 已 final

// struct SubClass3: Base2 {
//     void foo(); // 非法, foo 已 final
// };

class Magic {
    public:
    Magic() = default; // 显式声明使用编译器生成的构造
    Magic& operator=(const Magic&) = delete; // 显式声明拒绝编译器生成构造
    Magic(int magic_number);
};

/////// 强类型枚举

enum class new_enum : unsigned int {
    value1,
    value2,
    value3 = 100,
    value4 = 100
};

int main() {

    Subclass s(3);
    std::cout << s.value1 << std::endl;
    std::cout << s.value2 << std::endl;

}