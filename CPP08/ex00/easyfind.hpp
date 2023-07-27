#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <set>
# include <map>
//without iterator
template<typename T>
void  easyfind(T &container, int n)
{
    std::find(container.begin(), container.end(), n) == container.end()
    ? std::cout<< "not found" << std::endl
    : std::cout<< "found" << std::endl;
}
#endif