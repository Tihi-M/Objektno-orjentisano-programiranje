#include <iostream>
#include "Datum.h"
#include "DatumVrijeme.h"
DatumVrijeme::DatumVrijeme(){
    this->hh = 0;
    this->mm = 0;
}

DatumVrijeme::DatumVrijeme(const Datum& d): Datum(d.getDay(),d.getMonth(),d.getYear()){

    this->hh = 0;
    this->mm = 0;
}

DatumVrijeme::DatumVrijeme(int d,int m,int g,int hh,int mm):Datum(d,m,g){

    if(hh<0 || hh>23)
    {
        std::cout<<"Invalid hour"<<std::endl;
        exit(1);
    }

    this->hh = hh;

    if(mm<0 || mm >59){
        std::cout<<"Invalid min"<<std::endl;
        exit(1);
    }

    this->mm = mm;
}

void DatumVrijeme::print() const{
    Datum::print();
    std::cout<< this->hh<<":"<<this->mm<<std::endl;
}
