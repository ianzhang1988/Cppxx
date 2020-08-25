#include <iostream>
#include <regex>
#include <string>
#include <algorithm>

// not quite understand the regex in c++... leave it here

int main() {

std::string data_short = "2020-08-11: abc defg she";
std::string data = "2020-08-11: abc defg she\n"
"2020-08-12: asds dghdghkr\n"
"2020-08-13:  asdg  qetsftuyd\n"
"2020-08-14: gikg hjkt uyuk\n"
"2020-08-15:   rtuy kgthkru";

std::regex match_regex("(\\d\\d\\d\\d-\\d\\d-\\d\\d):\\s+(.*?)");
std::smatch base_match;

bool result;

result = std::regex_match(data, base_match, match_regex);
std::cout<<"match result full: "<<result<<std::endl;

result = std::regex_match(data_short, base_match, match_regex);
std::cout<<"match result short: "<<result<<std::endl;

auto search_result = std::regex_search(data, base_match, match_regex);
std::cout<<"search_result full: "<<search_result<<std::endl;
std::cout<<"search_result full size : "<<base_match.size()<<std::endl;
std::for_each(base_match.begin(), base_match.end(), [](auto x){std::cout<<"sub match: "<<x<<std::endl;});

search_result = std::regex_search(data_short, base_match, match_regex);
std::cout<<"match search_result short: "<<search_result<<std::endl;
std::cout<<"search_result full size : "<<base_match.size()<<std::endl;
std::for_each(base_match.begin(), base_match.end(), [](auto x){std::cout<<"sub match: "<<x<<std::endl;});
}
