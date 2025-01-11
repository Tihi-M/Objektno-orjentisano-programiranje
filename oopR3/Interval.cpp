#include "Interval.h"
#include "Vrijeme.h"
#include <iostream>
Interval::Interval(int h,int m,int t):Vrijeme(h,m)
{
    this->Setlen(t);
}

void Interval::Setlen(int t){
    if(t < 0){
        std::cout << "Invalid len" << std::endl;
        exit(1);
    }
    this->trajanje = t;
}

Interval& Interval::operator+=(int minut){
    this->Setlen(this->trajanje+minut);
    while(minut > 59){
        if(this->sat + 1 > 23)
            this->Setsat(0);
        else
            this->Setsat(this->sat+1);
        minut-=60;
    }
    if(minut > 0){
        if(this->minn + minut > 59){
            if(this->sat + 1 > 23){
                this->Setsat(0);
                this->Setmin(this->minn+minut-60);
                return *this;
            }
            else{
                this->Setsat(this->sat+1);
                this->Setmin(this->minn+minut-60);
                return *this;
            }
        }
        else{
            this->Setmin(this->minn+minut);
            return *this;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Interval& in){
    os<<(Vrijeme&)in;
    os<<" "<<in.Getlen();
    return os;
}

Vrijeme Interval::kraj() const{
    Interval i1(0,this->minn,this->trajanje);
    i1+=this->trajanje;
    Vrijeme v2(i1.Getsat(),i1.Getmin());
    return v2;
}

bool operator>(const Interval& i1,const Interval& i2){
    Vrijeme kraj1 = i1.kraj();
    Vrijeme kraj2 = i2.kraj();

    if(i1.Getsat() <= i2.Getsat() && i1.Getmin() < i2.Getmin() && kraj1.Getsat() >= kraj2.Getsat() && kraj1.Getmin() > kraj2.Getmin())
        return 1;
    return 0;
 }

Interval::~Interval()
{
    //dtor
}
