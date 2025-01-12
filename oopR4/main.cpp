#include <iostream>
#include "Valuta.h"
#include "KolicinaNovca.h"
int main()
{
    KolicinaNovca k1("eur",1,100);
    KolicinaNovca k2("dol",0.8,100);

    KolicinaNovca k3 = k1+k2;
    std::cout<<k3;
    return 0;
}
