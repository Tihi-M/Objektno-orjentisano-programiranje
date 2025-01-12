#include "Ocjena.h"
#include <iostream>

Ocjena::Ocjena()
{
     this->SetidPredmeta(0);
     this->Setvrijednost(0);
}

Ocjena::Ocjena(int id,int val)
{
     this->SetidPredmeta(id);
     this->Setvrijednost(val);
}

void Ocjena::SetidPredmeta(int val){
    if(val < 0){
        std::cout<<"Invalid arg"<<std::endl;
        exit(1);
    }
    this->idPredmeta = val;
}

void Ocjena::Setvrijednost(int val){
    if(val < 0){
        std::cout<<"Invalid arg"<<std::endl;
        exit(2);
    }
    this->vrijednost = val;
}

Ocjena::~Ocjena()
{
    //dtor
}
