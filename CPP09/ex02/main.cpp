#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <sys/time.h>
#include <deque>

bool flag = false;
unsigned int tmp;

template <typename T, typename S, typename V>
void algo(int ac, char *av[], T &container, S &cont, V &conta, char choice)
{
    clock_t start, end;
    double diff;
    (void)av;
    start = clock();
    for (typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        if ((*it).first > (*it).second)
            std::swap((*it).first, (*it).second);
    }

    for (typename T::iterator it = container.begin(); it != container.end(); ++it)
        conta.push_back((*it).first);

    for (typename T::iterator it = container.begin(); it != container.end(); ++it)
        cont.push_back((*it).second);

    conta.sort();

    for (typename S::iterator it = cont.begin(); it != cont.end(); ++it)
        conta.insert(std::lower_bound(conta.begin(), conta.end(), *it), *it);
    if (flag)
        conta.insert(std::lower_bound(conta.begin(), conta.end(), tmp), tmp);

    std::cout << "\nAfter  : ";
    for (typename V::iterator it = conta.begin(); it != conta.end(); ++it)
        std::cout << *it << " ";

    end = clock();
    diff = (double)(end - start) / CLOCKS_PER_SEC;
    if (choice == 'l')
        std::cout << "\nTime to process a range of " << ac << " elements with std::list : " << diff * 1000000 << " us" << "\n";
    if (choice == 'd')
        std::cout << "\nTime to process a range of " << ac << " elements with std::deque : " << diff * 1000000 << " us" << "\n";
}

void checkInput(char *av1, char *av2)
{
    if (std::atoi(av1) < 0 || std::atoi(av2) < 0)
    {
        std::cerr << "Invalid Input: Number Less Than 0\n";
        exit(0);
    }
}

int main(int ac, char *av[])
{
    if ((ac - 1) % 2 != 0)
    {
        flag = true;
        tmp = std::atof(av[ac - 1]);
        if (std::atof(av[ac - 1]) < 0)
            exit(1);
        ac -= 1;
    }

    std::cout << "Before : ";
    if (ac < 6)
    {
        for (int i = 1; i < ac; i++)
            std::cout << av[i] << " ";
    }
    else
    {
        for (int i = 1; i < 6; i++)
            std::cout << av[i] << " ";
        std::cout << "[...]";
    }
    std::list<std::pair<unsigned int, unsigned int> > lst;
    for (int i = 1; i < ac; i += 2)
    {
        if (isdigit(*av[i]))
        {
            checkInput(av[i], av[i + 1]);
            lst.push_back(std::make_pair(std::atof(av[i]), std::atof(av[i + 1])));
        }
    }
    std::list<unsigned int> lst_a, lst_b;
    algo(ac, av, lst, lst_a, lst_b, 'l');
    std::list<std::pair<unsigned int, unsigned int> > dec;
    for (int i = 1; i < ac; i += 2)
    {
        if (isdigit(*av[i]))
        {
            checkInput(av[i], av[i + 1]);
            dec.push_back(std::make_pair(std::atof(av[i]), std::atof(av[i + 1])));
        }
    }
    std::list<unsigned int> dec_a, dec_b;
    algo(ac, av, dec, dec_a, dec_b, 'd');
}

