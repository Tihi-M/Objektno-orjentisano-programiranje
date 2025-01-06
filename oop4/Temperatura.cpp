#include <iostream>
#include "Temperatura.h"


int Temperatura::trueVal() const{
    int val = this->getS();
    if(this->getZ() == '-')
        val *= -1;
    return val;
}

void Temperatura::print() const{
    std::cout<<this->getZ()<<this->getS()<<" "<<this->getJ()<<std::endl;
}

void Temperatura::setS(int s){
    if(s < 0){
        std::cout<<"Stepen mora biti veci od 0"<<std::endl;
        exit(1);
    }
    this->stepen = s;
}

void Temperatura::setZ(char c){
    if(c != '+' && c != '-')
    {
        std::cout<<"Znak mora biti + ili -"<<std::endl;
        exit(1);
    }
    this->znak = c;
}

void Temperatura::setJ(char j){
    if(j != 'C' && j != 'F')
    {
        std::cout<<"Jedinica mora biti C ili F"<<std::endl;
        exit(1);
    }
    this->jedinica = j;
}

int Temperatura::getS() const{
    return this->stepen;
}

char Temperatura::getZ() const{
    return this->znak;
}

char Temperatura::getJ() const{
    return this->jedinica;
}

Temperatura::Temperatura(){
    this->setS(0);
    this->setZ('+');
    this->setJ('C');
}

Temperatura::Temperatura(int s,char z, char j){
    this->setJ(j);
    this->setS(s);
    this->setZ(z);
}

void Temperatura::convertToFarenheit() {
    if(this->getZ() == 'F')
        return;

    int st = this->trueVal();
    st=st*1.8+32;
    this->setJ('F');
    if(st > 0)
        this->setZ('+');
    else
        this->setZ('-');
    this->setS(st);
}

void Temperatura::convertToCelsius() {
    if(this->getZ() == 'C')
        return;

    int st = this->trueVal();
    st=(st-32)/1.8;
    this->setJ('C');
    if(st > 0)
        this->setZ('+');
    else
        this->setZ('-');
    this->setS(st);
}

int Temperatura::compareTo(const Temperatura& t2){
    if(this->getJ() == t2.getJ()){
        int val1 = this->trueVal();
        int val2 = t2.trueVal();
        if(val1 > val2)
            return 1;
        else if(val1 < val2)
            return -1;
        else return 0;
    }
    else if(this->getJ() == 'C')
        this->convertToFarenheit();
    else this->convertToCelsius();

    int val1 = this->trueVal();
    int val2 = t2.trueVal();

    if(val1 > val2)
        return 1;
    else if(val1 < val2)
        return -1;
    else return 0;
}
