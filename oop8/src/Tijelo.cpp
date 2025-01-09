#include "Tijelo.h"
#include <iostream>
//#include <stdio.h>
Tijelo::Tijelo(char p)
{
    sprintf(idTijela,"%c%d",p,++cntTijela);
}

int Tijelo::cntTijela=0;

Tijelo::~Tijelo()
{
    //dtor
}
