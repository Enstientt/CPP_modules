#include <algorithm> // std::min_element and std::max_element
#include <iostream>
#include <list>
#include <numeric> // std::iota
#include <vector>
#include <functional>

int main()
{
    std::vector<int> vect = {11,20,34,7,8,9};

    for (std::vector<int>::iterator it = vect.begin(); it != vect.end();it++)
        std::cout<< *it<<std::endl;
    std::sort(vect.begin(), vect.end(), std::greater<int>());
    for (std::vector<int>::iterator it = vect.begin(); it != vect.end();it++)
        std::cout<< *it<<std::endl;
}