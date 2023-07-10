#include "Base.hpp"

int main()
{
    C a;
    Base *ptr = a.generate();
    C &ref = a;
    ptr->identify(ptr);
    ptr->identify(ref);
}