#ifndef PMERGEME_HPP_
#define PMERGEME_HPP_

#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <sys/time.h>
#include <vector>

class PmergeMe{
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(PmergeMe const &other);
        PmergeMe &operator=(PmergeMe const &other);
};
#endif