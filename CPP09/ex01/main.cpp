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
bool isOperator(std::string &str)
{
    if (str == "+" || str == "-" || str == "*" || str == "/")
        return true;
    return false;
}

void preformOperation(std::string &input, std::stack<double> &calc_stack)
{
    double a = calc_stack.top();
    calc_stack.pop();
    double b = calc_stack.top();
    calc_stack.pop();
    if (input == "+")
        calc_stack.push(a + b);
    else if (input == "-")
        calc_stack.push(a - b);
    else if (input == "*")
        calc_stack.push(a * b);
    else if (input == "/")
        calc_stack.push(a / b);
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: bad input" << std::endl;
        return 0;
    }
    std::stack<double> calc_stack;
    std::stringstream ss(av[1]);
    std::string input;
    double num;
    while (getline(ss, input, ' '))
    {
        if (std::istringstream(input) >>num )
        {
            if (num > 10 || num < 0)
            {
                std::cout << "Error: bad input" << std::endl;
                return 0;
            }
        }
        else if (isOperator(input))
        {
            preformOperation(input, calc_stack);
        }
        else
            std::cout << "Error: bad input" << std::endl;
    }
    std::cout<<calc_stack.top()<<std::endl;
    return 0;
}