#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
# include <iterator>
# include <numeric>
# include <cstdlib>
# include <ctime>
#include <stack>

template <typename T,class container = std::deque<T> >

class MutantStack :public std::stack<T, container> {
    private:

    public:
        MutantStack(){
        };
        MutantStack(MutantStack const &copy){
            *this = copy;
        };
        MutantStack &operator=(MutantStack<T, container> const &copy){
            if (this != &copy)
            {
                std::stack<T, container>::operator=(copy); 
            }
            return *this;
        };
        ~MutantStack()
        {
        };
        typedef typename container::iterator iterator;
        iterator begin(){return this->c.begin();};
        iterator end(){return this->c.end();};
};


#endif