#include "Motor.h"
#include <iostream>
Motor::Motor(std::string name,float ac,int pwr):Vozilo('M')
{
    Setname(name);
    Set1to100(ac);
    Setpower(pwr);
}

Motor::Motor(float acc,int pwr):Vozilo('M'){
    Setname(" ");
    Set1to100(acc);
    Setpower(pwr);
}

void Motor::Set1to100(float acc){
    if(acc < 0){
        std::cout<<"Invalid arg"<<std::endl;
        exit(1);
    }
    this->to100 = acc;
}

void Motor::Setpower(int pwr){
    if(pwr < 0){
        std::cout<<"Invalid power"<<std::endl;
        exit(2);
    }
    this->power = pwr;
}

char Motor::sufix() const{
    return 'M';
}

Vozilo* Motor::kopija() const{
    return new Motor(name,to100,power);
}

Motor operator+(Motor m1,Motor m2){
    Motor m = Motor((m1.Get1to100()+m2.Get1to100())/2,m1.Getpower()+m2.Getpower());
    return m;
}

void Motor::print() const{
    std::cout<<this->Getname()<<" "<<this->id<<" ("<<this->Get1to100()<<" s, "<<this->Getpower()<<" HP)"<<std::endl;
}

std::ostream& operator<<(std::ostream& os,Motor m1){
    os<<m1.name<<" "<<m1.id<<" ("<<m1.Get1to100()<<" s, "<<m1.Getpower()<<" HP)"<<std::endl;
    return os;
}



Motor::~Motor()
{
    //dtor
}
