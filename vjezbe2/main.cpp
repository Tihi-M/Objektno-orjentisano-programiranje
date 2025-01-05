#include <iostream>
#include "Ugao.h"
/**
Ugao - cuva ugao u radijanima
    //ako ugao nije u oopsegu 0-2pi izvrsiti noramalizaciju
    //set_rad
    //set step
    //get_rad
    //stampaj
    //dodaj
    //oduzme
    //plus
*/

int main()
{
    Ugao u1;
    u1.setRad(10);
    std::cout<<u1.getRad()<<std::endl;

    Ugao u2;
    u2.setRad(2);
    std::cout<<u2.getRad()<<std::endl;

    Ugao u3 = u1.plus(u2);
    std::cout<<u3.getRad()<<std::endl;
    return 0;
}
