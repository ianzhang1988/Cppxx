#include <initializer_list>
#include <iostream>
#include <algorithm>

class Foo{
    std::vector<int> vec;
public:
    Foo(std::initializer_list<int> list) {
        for(auto it = list.begin(); it!=list.end(); ++it) {
            vec.push_back(*it);
        }
    }

    void print() {
        std::for_each(vec.begin(),vec.end(), [](int x){std::cout<<x<<std::endl;} );
    }

    void append(std::initializer_list<int> list){
        for(auto it = list.begin(); it!=list.end(); ++it) {
            vec.push_back(*it);
        }
    }
};

struct Bar{
    int v1;
    int v2;
    int v3;
};

int main() {
    Foo foo = {1,2,3};
    foo.print();
    std::cout<<"-------------------"<<std::endl;
    foo.append({4,5,6});
    foo.print();

    Bar bar {1,2};
    // version ralated
    // gcc 5.4
    // Bar bar2 {.v2=1,.v1=2}; //sorry, unimplemented: non-trivial designated initializers not supported
    // Bar bar2 {.v1=2,.v3=3};//sorry, unimplemented: non-trivial designated initializers not supported
    Bar bar2 {.v1=2, .v2=1, .v3=3};
}