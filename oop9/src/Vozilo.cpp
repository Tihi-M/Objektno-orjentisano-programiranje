#include "Vozilo.h"
#include <iostream>
Vozilo::Vozilo(char p)
{
    sprintf(id,"%c%d",p,++cnt);
}

int Vozilo::cnt = 0;

Vozilo::~Vozilo()
{
    //dtor
}
