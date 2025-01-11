#include <iostream>
#include "Ekipa.h"
#include "FudbalskaEkipa.h"
int main()
{
    Ekipa e1(140000,11,"Barcelona");
    Ekipa e2(150000,11,"Madrid");
    Ekipa e3(100000,11,"Sevilla");
    Ekipa* e4 = Ekipa::najveciBudzet();
    std::cout<<*e4;

    int *arr = new int[11];
    for(int i = 0; i<11;i++)
        arr[i] = i;

    FudbalskaEkipa fb(170000,11,"Fc Barcelona",arr);
    std::cout<<fb;
    return 0;
}
