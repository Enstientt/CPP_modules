#include "Span.hpp"

int main()
{
    srand(time(NULL));
    Span sp = Span(10000);
    std::vector<int> v;
    for (int i = 0; i < 10000; i++)
    {
        v.push_back(rand() % 10000);
    }
    sp.addNumber(v.begin(), v.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}