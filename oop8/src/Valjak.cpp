#include "Valjak.h"
#include <iostream>
#include <math.h>
Valjak::Valjak(double r, double h): Tijelo('V')
{
    Seth(h);
    Setr(r);
}

void Valjak::Seth(double h){
    if(h < 0){
        std::cout<<"Invalid height"<<std::endl;
        exit(1);
    }

    this->h = h;
}

void Valjak::Setr(double r){
    if(r < 0){
        std::cout<<"Invalid radius"<<std::endl;
        exit(2);
    }
    this->r = r;
}

char Valjak::vrsta() const{
    return 'V';
}

double Valjak::zapremina() const{
    return r*r*M_PI*h;
}

Tijelo* Valjak::kopija() const{
    return new Valjak(r,h);
}

void Valjak::pisi() const{
    std::cout<<this->idTijela<<"("<<this->r<<", "<<this->h<<")"<<std::endl;
}

std::ostream& operator<<(std::ostream& os,Valjak v){
    os<<v.idTijela<<"("<<v.r<<", "<<v.h<<")";
    return os;
}

Valjak operator+(Valjak v1, Valjak v2){
    Valjak v3 = Valjak(v1.Getr() + v2.Getr(),v1.Geth()+v2.Geth());
    return v3;
}

Valjak::~Valjak()
{
    //dtor
}
