#include "PmergeMe.hpp"


bool flag = false;
unsigned int tmp;

void checkInput(char **av, int ac)
{
    int j;
    for (int i = 1; i < ac; i++)
    {
        j = 0;
        while(av[i][j])
        {
            if(!isdigit(av[i][j]))
            {
                std::cerr<<"invalid input \n";
                exit(0);
            }
            j++;
        }
        if (std::atof(av[i]) < 0 || std::atof(av[i]) > std::numeric_limits<int>::max())
        {
            std::cerr << "Invalid Input: the number is out of the positive  integers range \n";
            exit(0);
        }
    } 
}

void algo_list(int ac, char *av[])
{
    clock_t start, end;
    double diff;
    (void)av;
    start = clock();
    
    std::list<std::pair<unsigned int, unsigned int> > lst;
    checkInput(av, ac);
    if (ac%2==0)
    {
        flag = true;
        tmp = std::atof(av[ac - 1]);
    }
    for (int i = 1; i < ac - 1; i += 2)
            lst.push_back(std::make_pair(std::atof(av[i]), std::atof(av[i + 1])));

    for (std::list<std::pair<unsigned int, unsigned int> >::iterator it = lst.begin(); it != lst.end(); ++it)
    {
        if ((*it).first > (*it).second)
            std::swap((*it).first, (*it).second);
    }

    std::list<unsigned int> lst_a, lst_b;
    for (std::list<std::pair<unsigned int, unsigned int> >::iterator it = lst.begin(); it != lst.end(); ++it)
        lst_a.push_back((*it).first);

    for (std::list<std::pair<unsigned int, unsigned int> >::iterator it = lst.begin(); it != lst.end(); ++it)
        lst_b.push_back((*it).second);

    lst_a.sort();

    for (std::list<unsigned int>::iterator it = lst_b.begin(); it != lst_b.end(); ++it)
        lst_a.insert(std::lower_bound(lst_a.begin(), lst_a.end(), *it), *it);
    
    if (flag)
        lst_a.insert(std::lower_bound(lst_a.begin(), lst_a.end(), tmp), tmp);
    
    end = clock();
    std::cout << "\nBefore : ";
    for(int j = 1;j < ac ;j++)
        std::cout << av[j] << " ";
    std::cout << "\nAfter  : ";
    for (std::list<unsigned int>::iterator it = lst_a.begin(); it != lst_a.end(); ++it)
        std::cout << *it << " ";

    diff = (double)(end - start);
    std::cout << "\nTime to process a range of " << ac - 1 << " elements with std::list : " << diff << " us" << "\n";
}

void algo_vector(int ac, char *av[])
{
    clock_t start, end;
    double diff;
    (void)av;
    start = clock();

    std::vector<std::pair<unsigned int, unsigned int> > vec;
    checkInput(av, ac);
    if (ac%2==0)
    {
        flag = true;
        tmp = std::atof(av[ac - 1]);
    }
    for (int i = 1; i < ac - 1; i += 2)
        vec.push_back(std::make_pair(std::atof(av[i]), std::atof(av[i + 1])));

    for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if ((*it).first > (*it).second)
            std::swap((*it).first, (*it).second);
    }
    std::vector<unsigned int> vec_a, vec_b;
    for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = vec.begin(); it != vec.end(); ++it)
        vec_a.push_back((*it).first);
    for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = vec.begin(); it != vec.end(); ++it)
        vec_b.push_back((*it).second);
    std::sort(vec_a.begin(), vec_a.end());
    for (std::vector<unsigned int>::iterator it = vec_b.begin(); it != vec_b.end(); ++it)
        vec_a.insert(std::lower_bound(vec_a.begin(), vec_a.end(), *it), *it);
    if (flag)
        vec_a.insert(std::lower_bound(vec_a.begin(), vec_a.end(), tmp), tmp);
    std::cout << "\nBefore : ";
    for(int j = 1;j < ac;j++)
        std::cout << av[j] << " ";
    std::cout << "\nAfter  : ";
    for (std::vector<unsigned int>::iterator it = vec_a.begin(); it != vec_a.end(); ++it)
        std::cout << *it << " ";
    end = clock();
    diff = (double)(end - start);
    std::cout << "\nTime to process a range of " << ac - 1 << " elements with std::vector : " << diff<< " us" << "\n";
}

int main(int ac, char *av[])
{
    std::string input;
    if (ac < 3)
    {
        std::cerr << "Invalid Input: Less Than 2 arguments\n";
        exit(0);
    }
    else
    {
        for (int i = 1; i < ac; i++)
        {
            input = av[i];
            if (input.empty())
            {
                std::cout<< "invalid input: empty input  "<<std::endl;
                return 1;
            }
        }
        
        algo_list(ac, av);
        algo_vector(ac, av);
    }
    return 0;
}

