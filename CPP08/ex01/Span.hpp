#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
# include <iterator>
# include <numeric>
# include <cstdlib>
# include <ctime>


class Span
{
    private:
        unsigned int _n;
        std::vector<int> _v;
        Span();
    public:
        Span(unsigned int n);
        Span(Span const &copy);
        Span &operator=(Span const &copy);
        ~Span();
        void addNumber(int n);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();
        std::vector<int> getvect();
        class FullException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class NoSpanException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif