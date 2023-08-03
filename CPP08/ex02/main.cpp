#include "MutantStack.hpp"
#include <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    std::cout<<"******************************"<<std::endl;
    MutantStack<int , std::list<int> > list;
    list.push(5);
    list.push(17);
    std::cout << list.top() << std::endl;
    list.pop();
    std::cout << list.size() << std::endl;
    list.push(3);
    list.push(5);
    list.push(737);
    list.push(0);
    MutantStack<int, std::list<int> >::iterator itt = list.begin();
    ++itt;
    --itt;
    while (itt != list.end())
    {
    std::cout << *itt << std::endl;
    ++itt;
    }
    return 0;
}