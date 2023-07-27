#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(Span const &copy)
{
    *this = copy;
}

Span &Span::operator=(Span const &copy)
{
    if (this != &copy)
    {
        this->_n = copy._n;
        this->_v = copy._v;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if (this->_v.size() < this->_n)
        this->_v.push_back(n);
    else
        throw Span::FullException();
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (this->_v.size() + std::distance(begin, end) <= this->_n)
        this->_v.insert(this->_v.end(), begin, end);
    else
        throw Span::FullException();
}

int Span::shortestSpan()
{
    if (this->_v.size() <= 1)
        throw Span::NoSpanException();
    std::vector<int> tmp = this->_v;
    std::sort(tmp.begin(), tmp.end());
    std::vector<int>::iterator it = tmp.begin();
    std::vector<int>::iterator ite = tmp.end();
    int min = std::abs(*it - *(it + 1));
    for (; it != ite - 1; it++)
    {
        if (std::abs(*it - *(it + 1)) < min)
            min = std::abs(*it - *(it + 1));
    }
    return min;
}

int Span::longestSpan()
{
    if (this->_v.size() <= 1)
        throw Span::NoSpanException();
    std::vector<int> tmp = this->_v;
    std::sort(tmp.begin(), tmp.end());
    return std::abs(*tmp.begin() - *(tmp.end() - 1));
}

const char* Span::FullException::what() const throw()
{
    return "Span is full";
}

const char* Span::NoSpanException::what() const throw()
{
    return "No span to find";
}
