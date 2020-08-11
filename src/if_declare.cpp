#include <iostream>
#include <algorithm>


int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};

    // C++ 17
    // if (auto iter = std::find(vec.begin(),vec.end(), 2);
    //     iter!=vec.end()) {
    //     std::cout<< "found" << *iter << std::endl;
    //     *iter = 3;
    // }

    auto iter = std::find(vec.begin(),vec.end(), 2);
    if (iter!=vec.end()) {
        std::cout<< "found:" << *iter << std::endl;
        *iter = 3;
    }

    for (auto element = vec.begin(); element != vec.end(); ++element)
        std::cout << *element << std::endl;
}