#include <iostream>
#include "Datum.h"

int main()
{
    Datum d1(2,5,2004);
    Datum d2(3,7,2024);
    Datum d3(21,7,2024);

    d1.print();
    std::cout<<d2;

    d1--;
    d1--;
    std::cout<<d1;
    return 0;
}
