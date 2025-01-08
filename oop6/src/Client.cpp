#include "Client.h"

Client::Client(){
    this->Setime("/");
    this->Setprezime("/");
    this->Sethh(12);
    this->Setmm(0);
}

Client::Client(std::string ime,std::string prezime,int hh,int mm){
    this->Setime(ime);
    this->Setprezime(prezime);
    this->Sethh(hh);
    this->Setmm(mm);

    if(this->compareTo(7,0) == -1 || this->compareTo(15,0) == 1)
    {
        std::cout << "Radno vrijeme pocinje u 7, zavrsava u 15 h"<<std::endl;
        exit(123);
    }
}

Client::~Client()
{
    //dtor
}

void Client::Sethh(int hh){
    if(hh < 0 || hh > 23)
    {
        std::cout<<"Invalid hour"<<std::endl;
        exit(1);
    }
    this->hh = hh;
}

void Client::Setmm(int mm){
    if(mm < 0 || mm >59)
    {
        std::cout<<"Invalid minute"<<std::endl;
        exit(2);
    }
    this->mm = mm;
}

float Client::vrijemeCekanja(int hh,int mm) const{
    if(hh < this->hh  || (hh == this->hh && mm < this->mm))
    {
        std::cout<<"Unijeto je proslo vrijeme..."<<std::endl;
        exit(3);
    }

    if(mm - this->mm >= 0){
        this->printTime(hh-this->hh,mm-this->mm);
        std::cout<<std::endl;
        return (hh-this->hh)*60+mm-this->mm;
    }
    else{
        hh-=1;
        mm +=60;
        this->printTime(hh-this->hh,mm-this->mm);
        std::cout<<std::endl;
        return (hh-this->hh)*60+mm-this->mm;
    }
}

int Client::compareTo(int hh,int mm) {
    if(this->Gethh() > hh)
        return 1;
    else if(this->Gethh() < hh)
        return -1;
    else if(this->Getmm() > mm)
        return 1;
    else if(this->Getmm() < mm)
        return -1;
    else return 0;
}

void Client::printTime(int h,int m) const{
    if(m != 0)
        std::cout<<h<<":"<<m;
    else
        std::cout<<h<<":"<<m<<"0";
}

void Client::print() const{
    std::cout<<this->ime <<" "<< this->prezime <<" ";
    this->printTime(this->hh,this->mm);
    std::cout<<std::endl;
}



