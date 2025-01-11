#include "Datum.h"
#include <iostream>

Datum::Datum()
{
    this->Setg(2000);
    this->Setm(1);
    this->Setd(1);
}

Datum::Datum(int d,int m,int g)
{
    this->Setg(g);
    this->Setm(m);
    this->Setd(d);
}

void Datum::Setd(int d){
    if(d < 1 || d > monthLength(this->m,this->g))
    {
        std::cout<<"Invalid day"<<std::endl;
        exit(1);
    }
    this->d = d;
}

void Datum::Setm(int m){
    if(m < 1 || m > 12){
        std::cout<<"Invalid month"<<std::endl;
        exit(2);
    }
    this->m = m;
}

void Datum::Setg(int g){
    if(g < 0){
        std::cout<<"Invalid yead"<<std::endl;
        exit(3);
    }
    this->g = g;
}

bool Datum::parna(int g) const {
    if((g%4 == 0 && g%100 != 0) || (g%400==0))
        return true;
    return false;
}

int Datum::monthLength(int m,int g) const{
    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        return 31;
    if(m == 4 || m == 6 || m == 9 || m == 11)
        return 30;
    if(parna(g))
        return 29;
    return 28;
}

void Datum::print() const{
    std::cout<<this->d<<"."<<this->m<<"."<<this->g<<"."<<std::endl;
}

int Datum::prosloDana() const{
    int sum = 0;
    sum+=this->Getd();
    int mj = this->Getm()-1;
    while(mj > 0){
        sum+=this->monthLength(mj,this->Getg());
        mj--;
    }
    return sum;
}

int Datum::doKrajaGod() const{
    if(parna(this->Getg()))
        return 366-this->prosloDana();
    return 365-this->prosloDana();
}

int Datum::compareTo(const Datum& d){
    if(this->Getg() > d.Getg())
        return 1;
    else if(this->Getg() < d.Getg())
        return -1;
    else if(this->Getm() > d.Getm())
        return 1;
    else if(this->Getm() < d.Getm())
        return -1;
    else if(this->Getd() > d.Getd())
        return 1;
    else if(this->Getd() < d.Getd())
        return -1;
    else return 0;
}

bool operator>(const Datum& d1,const Datum& d2){
    if(d1.Getg() > d2.Getg())
        return true;
    else if(d1.Getg() < d2.Getg())
        return false;
    else if(d1.Getm() > d2.Getm())
        return true;
    else if(d1.Getm() < d2.Getm())
        return false;
    else if(d1.Getd() > d2.Getd())
        return true;
    else if(d1.Getd() < d2.Getd())
        return false;
    else return false;
}

bool operator<(const Datum& d1,const Datum& d2){
    if(d1.Getg() > d2.Getg())
        return false;
    else if(d1.Getg() < d2.Getg())
        return true;
    else if(d1.Getm() > d2.Getm())
        return false;
    else if(d1.Getm() < d2.Getm())
        return true;
    else if(d1.Getd() > d2.Getd())
        return false;
    else if(d1.Getd() < d2.Getd())
        return true;
    else return false;
}

bool operator==(const Datum& d1, const Datum& d2){
    if(d1.Getg() == d2.Getg() && d1.Getd() == d2.Getd() && d1.Getm() == d2.Getm())
        return true;
    return false;
}

bool operator<=(const Datum& d1, const Datum& d2){
    if(d1 < d2 || d1==d2)
        return true;
    return false;
}

bool operator>=(const Datum& d1, const Datum& d2){
    if(d1 > d2 || d1==d2)
        return true;
    return false;
}

Datum& Datum::operator++(int k){
    if(this->Getd() + 1 <= this->monthLength(this->Getm(),this->Getg()))
    {
        this->Setd(this->d+1);
        return *this;
    }
    else if(this->Getm() + 1 <= 12){
        this->Setd(1);
        this->Setm(this->m+1);
        return *this;
    }
    else{
        this->Setd(1);
        this->Setm(1);
        this->Setg(this->g+1);
        return *this;
    }
}

Datum& Datum::operator--(int k){
    if(this->Getd() - 1 >= 1)
    {
        this->Setd(this->d-1);
        return *this;
    }
    else if(this->Getm() -1 >= 1){
        this->Setd(this->monthLength(this->m-1,this->g));
        this->Setm(this->m-1);
        return *this;
    }
    else{
        this->Setd(31);
        this->Setm(12);
        this->Setg(this->g-1);
        return *this;
    }
}

std::ostream& operator<<(std::ostream& os,const Datum& d){
    os<<d.Getd()<<"."<<d.Getm()<<"."<<d.Getg()<<".\n";
    return os;
}
Datum::~Datum()
{
    //dtor
}
