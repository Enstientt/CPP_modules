#include "Span.hpp"

int main()
{
    Span sp = Span(20);
    std::vector<int> vect(10);
    std::vector<int>::iterator it = vect.begin();
    std::vector<int>::iterator ite =vect.end();
    vect.push_back(12);
    vect.push_back(12);
    vect.push_back(122);
    vect.push_back(112);
    vect.push_back(22);
    vect.push_back(32);
    vect.push_back(22);
    vect.push_back(1);
    vect.push_back(124);
    vect.push_back(123);
    vect.push_back(122);
    vect.push_back(121);
    vect.push_back(122);
    vect.push_back(2);

    // sp.addNumber(6);
    // sp.addNumber(3);
    // sp.addNumber(17);
    // sp.addNumber(9);
    // sp.addNumber(11);
    sp.addNumber(it, ite);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}