#include "RPN.hpp"

// bool isOperator(std::string str){
//     if (str == "+" || str == "-" || str == "*" || str == "/" || str == "%")
//         return true;
//     return false;
// }

// bool isNumber(std::string str){
//     int dout = 0;
//     for (size_t i = 0; i < str.length(); i++){
//         if (i == 0 && (str[i] == '-' || str[i] == '+' ))
//             continue;
//         if (str[i] == '.')
//             dout++;
//         if (dout > 1)
//             return false;
//         if (str[i] != '.' &&  (str[i] < '0' || str[i] > '9'))
//             return false;
//     }
//     return true;
// }

// bool isBrackets(std::string str){
//     if (str == "(" || str == ")")
//         return true;
//     return false;
// }

// bool isSpace(std::string str){
//     if (str == " ")
//         return true;
//     return false;
// }
// int calculate(int a, int b, std::string op){
//     if (op == "+")
//         return a + b;
//     if (op == "-")
//         return a - b;
//     if (op == "*")
//         return a * b;
//     if (op == "/")
//         return a / b;
//     if (op == "%")
//         return a % b;
//     return 0;
// }

// int RPN(std::string str){
//     std::stack<int> stack;
//     std::stringstream ss(str);
//     std::string token;
//     while (ss >> token){
//         if (isNumber(token))
//             stack.push(std::atof(token.c_str()));
//         else if (isOperator(token)){
//             if (stack.size() < 2)
//                 return 0;
//             int a = stack.top();
//             stack.pop();
//             int b = stack.top();
//             stack.pop();
//             stack.push(calculate(b, a, token));
//         }
//         else if (isBrackets(token))
//             return 0;
//         else if (!isSpace(token))
//             return 0;
//     }
//     if (stack.size() != 1)
//         return 0;
//     return stack.top();
// }
// void check_stack(std::stack<double> calc_stack)
// {
//     int count = 0;
//     int b; 
//     if (calc_stack.size() < 2)
//     {
//         std::cout << "Error: bad input" << std::endl;
//         exit(1);
//     }
//     else
//     {
//         while (calc_stack.size() > 0)
//         {
//             b = calc_stack.top();
//             calc_stack.pop();
//             count++;
//             if (!isdigit(b) && count % 2 ==0)
//             {
//                 std::cout << "Error: bad input" << std::endl;
//                 exit(1);
//             }
//         }
//         if (count != 1)
//         {
//             std::cout << "Error: bad input" << std::endl;
//             exit(1);
//         }
//     }
// }
std::stack<char> reverseStack(const std::stack<char> &originalStack) {
    std::stack<char> reversedStack;

    std::stack<char> copyStack = originalStack; // Create a copy of the original stack

    while (!copyStack.empty()) {
        reversedStack.push(copyStack.top());
        copyStack.pop();
    }

    return reversedStack;
}
bool isOperator(char str)
{
    if (str == '+' || str == '-' || str == '*' || str == '/')
        return true;
    return false;
}

int calculate(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
    {
        if (b == 0)
        {
            std::cout << "Error: division by zero" << std::endl;
            exit(1);
        }
        return a / b;
    }
    return 0;
}

std::stack<int> preformOperation(std::stack<char> &calc_stack)
{
    int a, b;
    char op;
    std::stack<int> intStack;
    std::stack<char> opStack;
    while (calc_stack.size())
    {
        a = calc_stack.top() - '0';
        intStack.push(a);
        calc_stack.pop();
         b = calc_stack.top() - '0';
        intStack.push(b);
        calc_stack.pop();
        op = calc_stack.top();
        opStack.push(op);
        calc_stack.pop();
    }
    while (opStack.size())
    {
        a = intStack.top();
        intStack.pop();
        b = intStack.top();
        intStack.pop();
        op = opStack.top();
        opStack.pop();
        intStack.push(calculate(a, b, op));

    }
    return intStack;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: bad input" << std::endl;
        return 0;
    }
    std::stack<char> calc_stack;
    std::stringstream ss(av[1]);
    std::string input;
    int count = 0;
    char num;
    int i = 0;
    while (getline(ss, input, ' '))
    {
        while (input[i] && input[i] == ' ')
            i++;
        if (input[i] == '\0')
            continue;
        num =input[i];
        if (num)
        {
            if (isdigit(num))
            {
                if (count%2 ==0 && count!=0)
                {
                    std::cout<<num<<std::endl;
                    std::cout << "Error: bad input 1" << std::endl;
                    return 0;
                }
                else
                    calc_stack.push(num);
                count++;
            }
            else if (isOperator(num))
            {
                if (count%2!=0 )
                {
                    std::cout << "Error: bad input 3" << std::endl;
                    return 0;
                }
                calc_stack.push(num);
            }
            else
            {
                std::cout << "Error: bad input 4" << std::endl;
                return 0;
            }
        }
        // else if (isOperator(num) && count%2 ==0)
        //     calc_stack.push(input[0]);
        else
            std::cout << "Error: bad input 3" << std::endl;
    }
     calc_stack = reverseStack(calc_stack);
    //print the calc_stack
    // while (calc_stack.size())
    // {
    //     std::cout << calc_stack.top() << std::endl;
    //     calc_stack.pop();
    // }

    std::cout<<preformOperation(calc_stack).top()<<std::endl;
    return 0;
}