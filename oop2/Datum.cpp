#include <iostream>
#include "Datum.h"

int Datum::getDay() const{
    return this->dan;
}

int Datum::getMonth() const{
    return this->mjesec;
}

int Datum::getYear() const{
    return this->godina;
}

void Datum::setDay(int d) {
    if(d<1 || d>monthLength(this->mjesec,this->godina)){
        std::cout<<"Invalid day"<<std::endl;
        exit(1);
    }
    this->dan = d;
}

void Datum::setMonth(int m) {
    if(m < 1 || m > 12)
    {
        std::cout<<"Invalid month"<<std::endl;
        exit(1);
    }

    this->mjesec = m;
}

void Datum::setYear(int g) {
    if(g < 0)
    {
        std::cout<<"Invalid year"<<std::endl;
        exit(1);
    }

    this->godina = g;
}

Datum::Datum(){
    this->dan = 1;
    this->mjesec = 1;
    this->godina = 1;
}

void Datum::print() const{
    std::cout<<this->dan<<"."<<this->mjesec<<"."<<this->godina<<"."<<std::endl;
}

bool Datum::prestupna(int g) const{
    if((g%4 == 0 && g%100 != 0)||(g%400 == 0))
        return true;
    return false;
}


int Datum::monthLength(int m, int g) const{
    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        return 31;
    if(m == 4 || m == 6 || m == 9 || m == 11)
        return 30;
    if(prestupna(g))
        return 29;
    return 28;
}
///provjeriti zasto je trebalo biti static
bool Datum::validan(int d,int m,int g) {
    if(g < 0)
        return false;

    if(m < 0 || m > 12)
        return false;

    if(d<1 || d > monthLength(m,g))
        return false;

    return true;
}

Datum::Datum(int d,int m,int g){
    setYear(g);
    setMonth(m);
    setDay(d);
}

Datum Datum::sljedeci() const {
    Datum sj;
    if(this->dan + 1 <= monthLength(this->mjesec,this->godina)){
        sj.setYear(this->godina);
        sj.setMonth(this->mjesec);
        sj.setDay(this->dan+1);
        return sj;
    }
    else if(this->mjesec + 1 <= 12){
        sj.setYear(this->godina);
        sj.setMonth(this->mjesec+1);
        sj.setDay(1);
        return sj;
    }
    else{
        sj.setYear(this->godina+1);
        sj.setMonth(1);
        sj.setDay(1);
        return sj;
    }
}

Datum Datum::prethodni() const {
    Datum juce;
    if(this->dan - 1 >= 1){
        juce.setYear(this->godina);
        juce.setMonth(this->mjesec);
        juce.setDay(this->dan-1);
        return juce;
    }
    else if(this->mjesec - 1 >= 1){
        juce.setYear(this->godina);
        juce.setMonth(this->mjesec-1);
        juce.setDay(monthLength(this->mjesec-1,this->godina));
        return juce;
    }
    else{
        juce.setYear(this->godina-1);
        juce.setMonth(12);
        juce.setDay(31);
        return juce;
    }
}

int Datum::brojDanaOdPocetkaGod() const{
    int sum = 0;
    sum+=this->dan;
    int mj = this->mjesec;
    mj--;
    while(mj > 0){
        sum+=monthLength(mj,this->godina);
        mj--;
    }
    return sum;
}
