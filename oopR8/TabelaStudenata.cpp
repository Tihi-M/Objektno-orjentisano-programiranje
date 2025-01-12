#include "TabelaStudenata.h"

TabelaStudenata::TabelaStudenata()
{
    this->brElem =0 ;
    for(int i = 0; i < 10;i++){
        this->data[i].Setid(0);
        this->data[i].Setprosjek(0);
    }
}

bool TabelaStudenata::postoji(Student* s){
    for(int i =0; i < this->brElem;i++){
        if(this->data[i].Getid() == s->Getid())
            return true;
    }
    return false;
}

void TabelaStudenata::dodaj(Student s){
    if(this->brElem == 10){
        std::cout<<"Niz je pun"<<std::endl;
        return;
    }

    for(int i =0 ;i < this->brElem;i++){
        if(this->data[i].Getid() == s.Getid()){
            std::cout<<"Student postoji"<<std::endl;
            return;
        }
    }
    this->brElem++;
    this->data[brElem-1].Setid(s->Getid());
    this->data[brElem-1].Setprosjek(s->Getprosjek());
}

void TabelaStudenata::ukloni(int id){
    if(id > this->brElem)
        return;

    for(int i = 0; i < this->brElem;i++){
        if(this->data[i].Getid() == id){
            this->data[i].Setid(0);
            this->data[i].Setprosjek(0);
        }
    }
}

void TabelaStudenata::postavi(Student s,int pos){
    this->data[pos] = s;
    this->brElem++;
}

void TabelaStudenata::print(Student s){
    for(int i =0;i < this->brElem;i++){
        if(this->data[i].Getprosjek() > s.Getprosjek())
            this->data[i].print();
    }
}

TabelaStudenata::~TabelaStudenata()
{
    //dtor
}
