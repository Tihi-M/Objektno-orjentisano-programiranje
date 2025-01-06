#include <iostream>
#include "Temperatura.h"
int main()
{
    Temperatura t1(55,'+','F');
    t1.print();
    //t1.convertToFarenheit();
    //t1.print();

    Temperatura t2(15,'+','C');
    t2.print();
    std::cout<<t1.compareTo(t2)<<std::endl;
    return 0;
}
