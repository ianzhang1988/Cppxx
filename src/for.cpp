#include <iostream>
#include <vector>

int main () {
    std::vector<int> vec = {1,2,3,4};
    for(auto i : vec) { std::cout<< i <<","; } //read only
    std::cout<<std::endl;

    for(auto &i : vec) { i+=1; } //read write
    
    for(auto i : vec) { std::cout<< i <<","; }
     std::cout<<std::endl;
}