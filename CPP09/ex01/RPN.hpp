#ifndef RPN_HPP_
#define RPN_HPP_

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>

class RPN{
    public:
        RPN();
        ~RPN();
        RPN(RPN const &other);
        RPN &operator=(RPN const &other);
};

#endif
