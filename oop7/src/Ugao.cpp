#include "Ugao.h"
#include <iostream>
Ugao::Ugao()
{
    this->Setstep(0);
    this->Setmin(0);
    this->Setsec(0);
}

Ugao::Ugao(int step,int minn,int sec){
     this->Setstep(step);
    this->Setmin(minn);
    this->Setsec(sec);
}

Ugao::~Ugao()
{
    //dtor
}

void Ugao::Setstep(int val) {
    if(val< 0 ){
        while(val < 0)
            val+=360;
        this->step = val;
        return;
    }
    if(val > 359){
        while(val > 359)
            val-=360;
        this->step = val;
        return;
    }
    this->step = val;
}

void Ugao::Setmin(int val){
    if(val < 0 || val > 59)
    {
        std::cout<<"Invalid min"<<std::endl;
        exit(1);
    }
    this->minn = val;
}

void Ugao::Setsec(int val){
    if(val < 0 || val > 59)
    {
        std::cout<<"Invalid sec"<<std::endl;
        exit(2);
    }
    this->sec = val;
}

int Ugao::compareTo(const Ugao& u){
    if(this->Getstep() > u.Getstep())
        return 1;
    else if(this->Getstep() < u.Getstep())
        return -1;
    else if(this->Getmin() > u.Getmin())
        return 1;
    else if(this->Getmin() < u.Getmin())
        return -1;
    else if(this->Getsec() > u.Getsec())
        return 1;
    else if(this->Getsec() < u.Getsec())
        return -1;
    else return 0;
}

Ugao Ugao::operator+(const Ugao& u2){
    Ugao res;
    res.Setsec((this->Getsec()+u2.Getsec())%60);
    res.Setmin(((this->Getsec()+u2.Getsec())/60+this->Getmin()+u2.Getmin())%60);
    res.Setstep(((this->Getsec()+u2.Getsec())/60+this->Getmin()+u2.Getmin())/60+this->Getstep()+u2.Getstep());
    return res;
}

void Ugao::print() const{
    std::cout<<this->step<<" "<< this->minn << " " << this->sec <<std::endl;
}
