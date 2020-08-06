#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout<< "sum: " << sum<< std::endl;

    auto multi = [](int a, int b) { return a * b ; };
    auto multi_sum = std::accumulate(v.begin(), v.end(), 1, multi);
    std::cout << "multi: "<< multi_sum << std::endl;
}