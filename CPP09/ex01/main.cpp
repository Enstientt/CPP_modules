#include "RPN.hpp"

int calculate(int operand1, int operand2, char op)
{
    if (op == '+')
        return (operand1 + operand2);
    else if (op == '-')
        return (operand1 - operand2);
    else if (op == '*')
        return (operand2 * operand1);
    else if (op == '/')
        return (operand1 / operand2);
    return (0);
}


std::stack<int> rpn( char *av)
{
    std::stack<int> stack;
    int i = 0;
    int operand1;
    int operand2;
    while (av[i])
    {
        while(av[i]==' ')
            i++;
        if (av[i] == '\0')
        {
            std::cout << "Invalid Input" << std::endl;
            exit(1);
        }
        if (isdigit(av[i]))
            stack.push(av[i] - '0');
        else if (av[i] == '+' || av[i] == '-' || av[i] == '*' || av[i] == '/' )
        {
            if (stack.size() < 2)
            {
                std::cout << "Invalid Input" << std::endl;
                exit(1);
            }

            operand2 = stack.top();
            stack.pop();
            operand1 = stack.top();
            stack.pop();
            if (av[i] == '/' && operand2== 0)
            {
                std::cout << "division on zero" << std::endl;
                exit(1);
            }
            stack.push(calculate(operand1, operand2, av[i]));
        }
        i++;
    }
    return stack;
}

int main(int ac , char **av)
{
    std::string ipt;
    if (ac != 2)
    {
        std::cout << "Usage: ./RPN [file]" << std::endl;
        return 1;
    }
    std::string input = av[1];
    if (input.empty())
    {
        std::cout << "Invalid Input" << std::endl;
        return 1;
    }
    if (input.find_first_not_of("+-*/0123456789 ") != std::string::npos)
    {
        std::cout << "Invalid Input" << std::endl;
        return 1;
    }
    std::stack<int> stack = rpn(av[1]);
    std::cout<<stack.top()<<std::endl;
    return 0;
}