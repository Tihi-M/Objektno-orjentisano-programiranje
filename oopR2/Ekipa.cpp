#include "Ekipa.h"
#include <iostream>
#include <string.h>

double Ekipa::maxbudzet = 0.0;
Ekipa* Ekipa::naj = nullptr;

Ekipa::Ekipa(double b,int n, char* name)
{
    this->Setbudzet(b);
    this->SetbrIgraca(n);
    this->Setnaziv(name);

    if(this->budzet > maxbudzet){
        maxbudzet=this->budzet;
        naj = this;
    }
}

void Ekipa::Setbudzet(double b){
    if(b < 0)
    {
        std::cout<<"Invalid arg"<<std::endl;
        exit(1);
    }
    this->budzet = b;
}


void Ekipa::SetbrIgraca(int n){
    if(n < 0)
    {
        std::cout<<"Invalid arg"<<std::endl;
        exit(1);
    }
    this->brIgraca = n;
}


void Ekipa::Setnaziv(char* name){
    this->naziv = new char[strlen(name)];
    strcpy(this->naziv,name);
}

Ekipa& Ekipa::operator++(){
    this->SetbrIgraca(++this->brIgraca);
    return *this;
}

Ekipa& Ekipa::operator++(int k){
    this->SetbrIgraca(this->brIgraca++);
    return *this;
}

void Ekipa::print(){
    std::cout<<this->Getnaziv()<<" "<<this->GetbrIgraca()<<" "<<this->Getbudzet()<<"$"<<std::endl;
}

std::ostream& operator<<(std::ostream& os, const Ekipa& e){
    os<<e.Getnaziv()<<" "<<e.GetbrIgraca()<<" "<<e.Getbudzet()<<"$"<<std::endl;
    return os;
}
bool operator<(const Ekipa& e1, const Ekipa& e2){
    return e1.Getbudzet() < e2.Getbudzet();
}

bool operator>(const Ekipa& e1, const Ekipa& e2){
    return e1.Getbudzet() > e2.Getbudzet();
}
/*
bool operator==(const Ekipa& e1, const Ekipa& e2){
    return e1.Getbudzet() == e2.Getbudzet();
}
*/
bool operator>=(const Ekipa& e1, const Ekipa& e2){
    return e1.Getbudzet() == e2.Getbudzet();
}

bool operator<=(const Ekipa& e1, const Ekipa& e2){
    return e1.Getbudzet() == e2.Getbudzet();
}

Ekipa::~Ekipa()
{
    //dtor
}
