#include <iostream>
#include "Vrijeme.h"
#include "Interval.h"
int main()
{
    Vrijeme v1(0,59);
    std::cout<<v1<<std::endl;
    ++v1;
    std::cout<<v1<<std::endl;

    Interval i1(23,20,30);
    Interval i2(23,21,20);
    if(i1 > i2)
        std::cout<<1;
    else
        std::cout<<2;
    return 0;
}
