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

void Base::identify(Base &ref)
{
    try{
        A &refa =dynamic_cast<A &>(ref);
        (void)refa;
        std::cout<<"Type A"<<std::endl;
        return;
    }
    catch(const std::exception & e){
    }
        try{
        B &refb =dynamic_cast<B &>(ref); 
        (void)refb;
         std::cout<<"Type B"<<std::endl;
         return;
    }
    catch(const std::exception & e){
    }
        try{
        C &refc =dynamic_cast<C &>(ref); 
        (void)refc;
         std::cout<<"Type C"<<std::endl;
        return;
    }
    catch(const std::exception & e){
    }
}
