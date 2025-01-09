#include "Kamion.h"
#include "Vozilo.h"
#include <iostream>
Kamion::Kamion(std::string name,int power,int teret):Vozilo('K')
{
    Setname(name);
    Setpower(power);
    Setteret(teret);
}

Kamion::Kamion(int power,int teret):Vozilo('K'){
    Setname(" ");
    Setpower(power);
    Setteret(teret);
}

void Kamion::Setname(std::string name){
    this->name = name;
}

void Kamion::Setpower(int power){
    if(power < 0){
        std::cout<<"invalid power"<<std::endl;
        exit(3);
    }
    this->power = power;
}


void Kamion::Setteret(int teret){
    if(teret < 0){
        std::cout<<"invalid teret"<<std::endl;
        exit(4);
    }
    this->teret = teret;
}

char Kamion::sufix() const{
    return 'K';
}

Vozilo* Kamion::kopija() const{
    return new Kamion(name,power,teret);
}

Kamion operator+(Kamion k1,Kamion k2){
    Kamion k = Kamion(k1.Getpower()+k2.Getpower(),(k1.Getteret()+k2.Getteret())*0.7);
    return k;
}

void Kamion::print()const{
    std::cout<<this->name<<" "<<this->id<<" ("<<this->power<<" HP, "<<this->teret<<" t )"<<std::endl;
}

std::ostream& operator<<(std::ostream& os,Kamion k){
    os<<k.Getname() <<" "<<k.id<<" ("<<k.Getpower() << " HP, "<<k.Getteret() << " t )"<<std::endl;
    return os;
}
Kamion::~Kamion()
{
    //dtor
}
