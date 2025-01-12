#include "Valuta.h"
#include <string.h>

Valuta::Valuta(char* name,double x)
{
    this->Setnaziv(name);
    this->Setiznos(x);
}

void Valuta::Setnaziv(char* name){
    this->naziv = new char[strlen(name)];
    strcpy(this->naziv,name);
}

void Valuta::Setiznos(double iznos){
    if(iznos < 0){
        std::cout<<"Invalid arg"<<std::endl;
        exit(1);
    }
    this->iznos=iznos;
}

std::ostream& operator<<(std::ostream& os,const Valuta& d){
    os<<d.Getiznos()<<" "<<d.Getnaziv();
    return os;
}

Valuta::~Valuta()
{
    //dtor
}
