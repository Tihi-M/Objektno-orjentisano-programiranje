#include "Sfera.h"
#include <iostream>
#include <math.h>

Sfera::Sfera(double r):Tijelo('S')
{
    if(r <= 0){
        std::cout<<"Invalid radius"<<std::endl;
    }

    this->r = r;
}

char Sfera::vrsta() const{
    return 'S';
}

double Sfera::zapremina() const{
    return r*r*r*M_PI * 4/3;
}

void Sfera::pisi() const{
    std::cout<<idTijela<<"("<<r<<")"<<std::endl;
}

Tijelo* Sfera::kopija() const{
    return new Sfera(r);
}

Sfera operator+(Sfera s1,Sfera s2){
    return Sfera(s1.r+s2.r);
}

Sfera::~Sfera()
{
    //dtor
}
