#include <iostream>
#include "Datum.h"

bool Datum::prestupna(int g)const{
    if((g%4==0 && g%100!=0)||(g%400 == 0))
        return true;
    return false;
}

int Datum::monthLength(int m,int g) const{
    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        return 31;
    else if(m == 4 || m == 6 || m == 9 || m == 11)
        return 30;
    else if(prestupna(g))
        return 29;
    return 28;
}

void Datum::setD(int d){
    if(d<1 || d>monthLength(this->m,this->g))
    {
        std::cout<<"Invalid day"<<std::endl;
        exit(1);
    }
    this->d = d;
}

void Datum::setM(int m){
    if(m<1 || m>12)
    {
        std::cout<<"Invalid month"<<std::endl;
        exit(1);
    }
    this->m = m;
}

void Datum::setG(int g){
    this->g = g;
}

int Datum::getD() const{
    return this->d;
}

int Datum::getM() const{
    return this->m;
}

int Datum::getG() const{
    return this->g;
}

Datum::Datum(){
     this->setG(1);
    this->setM(1);
    this->setD(1);
}

Datum::Datum(int d,int m,int g){
    this->setG(g);
    std::cout<<m<<std::endl;
    this->setM(m);
    this->setD(d);


}

void Datum::print() const{
    std::cout<< this->getD() << "." <<
    this->getM() << "." << this->getG()
    << "." << std::endl;
}

int Datum::prosloDana() const{
    int mj = this->m;
    int sum = 0;
    sum += this->d;
    mj--;
    while(mj > 0){
        sum+=monthLength(mj,this->getG());
        mj--;
    }
    return sum;
}

int Datum::doKrajaGod() const{
    if(prestupna(g))
        return 366 - this->prosloDana();
    return 365 - this->prosloDana();
}

Datum Datum::prethodniDan() const{

    Datum juce;
    if(this->getD()-1 >= 1){
        juce.setG(this->getG());
        juce.setM(this->getM());
        juce.setD(this->getD() - 1);

        return juce;
    }
    else if (this->getM() - 1 >= 1){
        juce.setG(this->getG());
        juce.setM(this->getM()-1);
        juce.setD(monthLength(this->getM()-1,this->getG()));

        return juce;
    }
    else{
        juce.setG(this->getG()-1);
        juce.setM(12);
        juce.setD(31);

        return juce;
    }
}

Datum Datum::naredniDan() const{
    Datum sj;
    if(this->d+1 <= monthLength(this->m,this->g)){
        sj.setG(this->g);
        sj.setM(this->m);
        sj.setD(this->d +1);

        return sj;
    }
    else if (this->m + 1<= 12){
        sj.setG(this->g);
        sj.setM(this->m+1);
        sj.setD(1);

        return sj;
    }
    else{
        sj.setG(this->g+1);
        sj.setM(1);
        sj.setD(1);

        return sj;
    }
}

int Datum::compareTo(const Datum& dt) const{
    if(this->getG() > dt.getG())
        return 1;
    else if(this->getG() == dt.getG()){
        if(this->getM() > dt.getM())
            return 1;
        else if(this->getM() == dt.getM()){
            if(this->getD() > dt.getD())
                return 1;
            else if(this->getD() == dt.getD())
                return 0;
            else return -1;
        }
        else return -1;
    }
    else return -1;
}
