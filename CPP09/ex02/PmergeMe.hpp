#ifndef PMERGEME_HPP_
#define PMERGEME_HPP_

#include <iostream>
#include <algorithm>
#include <list>
#include <deque>

template<typename T>
void aff(T &t)
{
    typename T::iterator it = t.begin();
    typename T::iterator ite = t.end();
    while (it != ite)
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

template<typename T>
void mergeMe(T &t)
{
    typename T::iterator it = t.begin();
    typename T::iterator ite = t.end();
    typename T::iterator it2 = t.begin();
    typename T::iterator ite2 = t.end();
    it2++;
    while (it != ite)
    {
        while (it2 != ite2)
        {
            if (*it == *it2)
            {
                it2 = t.erase(it2);
                ite2 = t.end();
            }
            else
                it2++;
        }
        it++;
        it2 = it;
        it2++;
        ite2 = t.end();
    }
}

#endif /* !PMERGEME_HPP_ */