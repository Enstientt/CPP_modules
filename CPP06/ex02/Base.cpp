#include "Base.hpp"

Base::~Base(){}

Base * Base::generate(void){
    Base *ret;
    srand((unsigned) time(NULL));
    int i = rand();
    if (i%3 == 0)
        ret = new C;
    else if (i%4 == 0)
         ret = new B;
    else
         ret = new A;
    return ret;
}

void Base::identify(Base *p){

    A *ptra;
    B *ptrb;
    C *ptrc; 

    ptra = dynamic_cast<A*>(p);
    ptrb = dynamic_cast<B*>(p);
    ptrc = dynamic_cast<C*>(p);
    if ( ptra)
        std::cout<<"Type A"<<std::endl;
    if ( ptrb)
        std::cout<<"Type B"<<std::endl;
    if ( ptrc)
        std::cout<<"Type C"<<std::endl;
}

