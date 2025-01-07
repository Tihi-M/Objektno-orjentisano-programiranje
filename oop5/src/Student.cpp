#include <iostream>
#include "Student.h"


void Student::setIme(std::string ime){
    this->ime = ime;
}

void Student::setPrezime(std::string prezime){
    this->prezime = prezime;
}

void Student::setImeFaksa(std::string ime){
    this->faks = ime;
}

void Student::setInd(int ind){
    this->brInd = ind;
}

void Student::setGodina(int g){
    this->godina = g;
}

void Student::setOcjena(float ocj){
    if(ocj < 0 || ocj > 10){
        std::cout<<"Invalid grade"<<std::endl;
        exit(1);
    }
    this->prosjecnaOcjena = ocj;
}

std::string Student::getIme() const{
    return this->ime;
}

std::string Student::getPrezime() const{
    return this->prezime;
}

std::string Student::getImeFaksa() const{
    return this->faks;
}

int Student::getInd() const{
    return this->brInd;
}

int Student::getGodina() const{
    return this->godina;
}

float Student::getOcjena() const{
    return this->prosjecnaOcjena;
}

void Student::print() const{
    std::cout<<this->getIme() <<" "<<this->getPrezime() <<" "<<this->getImeFaksa() <<" "<<this->getInd() <<"/"<<this->getGodina()%100<<" "<<this->getOcjena() <<std::endl;
}

Student::Student(){
    this->setIme("");
    this->setPrezime("");
    this->setImeFaksa("nepoznato");
    this->setInd(0);
    this->setGodina(2024);
    this->setOcjena(0);
}

Student::Student(std::string ime, std::string prezime,int ind,int god,std::string faks, float ocjena){
    this->setIme(ime);
    this->setPrezime(prezime);
    this->setImeFaksa(faks);
    this->setInd(ind);
    this->setGodina(god);
    this->setOcjena(ocjena);
}

void Student::povecajProsjek(float x){
    if(this->getOcjena() + x > 10 || this->getOcjena() + x < 1)
    {
        std::cout<<"Invalid arg"<<std::endl;
        exit(1);
    }
    this->setOcjena(this->getOcjena()+x);
}

char Student::getProsjek() const{
    if(this->getOcjena() < 6)
        return 'F';
    else if(this->getOcjena() >= 6 && this->getOcjena() < 7)
        return 'D';
    else if(this->getOcjena() >= 7 && this->getOcjena() < 8)
        return 'C';
    else if(this->getOcjena() >= 8 && this->getOcjena() < 9)
        return 'B';
    else if(this->getOcjena() >= 9 && this->getOcjena() <= 10)
        return 'A';
    else return '/';
}
