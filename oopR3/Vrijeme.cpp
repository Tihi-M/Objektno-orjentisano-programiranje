#include "Vrijeme.h"
#include <iostream>
int Vrijeme::obj = 0;
Vrijeme::Vrijeme()
{
    this->Setmin(0);
    this->Setsat(0);
    obj+=1;
}

Vrijeme::Vrijeme(int h,int m){
    obj+=1;
    this->Setsat(h);
    this->Setmin(m);
}

void Vrijeme::Setmin(int val){
    if(val < 0 || val > 59)
    {
        std::cout<<"Invalid min"<<std::endl;
        exit(1);
    }
    this->minn = val;
}


void Vrijeme::Setsat(int val){
    if(val < 0 || val > 23)
    {
        std::cout<<"Invalid h"<<std::endl;
        exit(2);
    }
    this->sat = val;
}

Vrijeme& Vrijeme::operator++(){
    if(this->Getmin()+1<=59){
        this->Setmin(++this->minn);
        return *this;
    }
    else if(this->Getsat()+1<=23){
        this->Setmin(0);
        this->Setsat(++this->sat);
        return *this;
    }
    else{
        this->Setmin(0);
        this->Setsat(0);
        return *this;

    }
}

std::ostream& operator<<(std::ostream& os,const Vrijeme& v){
    if(v.sat<10){
        if(v.minn < 10){
            os<<"0"<<v.sat<<":0"<<v.minn;
            return os;
        }
        else{
            os<<"0"<<v.sat<<":"<<v.minn;
            return os;
        }
    }
    else{
        if(v.minn < 10){
            os<<v.sat<<":0"<<v.minn;
            return os;
        }
        else{
            os<<v.sat<<":"<<v.minn;
            return os;
        }
    }
}

Vrijeme::~Vrijeme()
{
    //dtor
}
