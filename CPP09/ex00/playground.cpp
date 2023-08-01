#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

void reverse(std::string &str){
    std::reverse(str.begin(), str.end());
}
int main(){
    std::string str("2022-01-01");
    std::string str1("2023-07-01");
    reverse(str);
    reverse(str1);
    std::cout <<str.compare(str1) << std::endl;
}