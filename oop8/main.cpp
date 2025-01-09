#include <iostream>
#include "Tijelo.h"
#include "Sfera.h"
#include "Valjak.h"

int main()
{
    Sfera s1(4),s2(3);
    s1.pisi();
    s2.pisi();
    Valjak v1(2,5),v2(4,7);
    v1.pisi();
    v2.pisi();

    Valjak v3 = v1+v1;
    std::cout<<v1<<"+"<<v1<<"="<<v3;
    return 0;
}
