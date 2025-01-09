#include <iostream>
#include "Vozilo.h"
#include "Motor.h"
#include "Kamion.h"
int main()
{
    Motor m1("Suzuki",3.2,489);
    Motor m2("Ducati",2.9,350);
    m1.print();
    std::cout<<m2;
    Motor m3 = m1+m2;
    m3.Setname("Kawasaki");
    std::cout<<m3;

    Kamion k1("Mercedes",500,5);
    Kamion k2("Iveco",300,1);

    k1.print();
    std::cout<<k2;

    Kamion k3 = k1 + k2;
    k3.Setname("random");
    std::cout<<k3;
        return 0;
}
