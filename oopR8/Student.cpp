#include "Student.h"
#include <iostream>
Student::Student()
{
    this->id=0;
    this->prosjek=0;
}

Student::Student(const Student& s){
    this->Setprosjek(s.Getprosjek());
    this->Setid(s.Getid());
}

void Student::Setid(int val){
    if(val < 0){
        std::cout<<"Invalid arg"<<std::endl;
        exit(1);
    }
    this->id = val;
}


void Student::Setprosjek(float val){
    if(val < 0){
        std::cout<<"Invalid arg"<<std::endl;
        exit(2);
    }
    this->prosjek = val;
}

void Student::print() const{
    std::cout<<this->Getid() <<" "<<this->Getprosjek()<<std::endl;
}

int Student::compareTo(const Student& s){
    if(s.Getprosjek() == this->Getprosjek())
        return 0;
    if(s.Getprosjek() < this->Getprosjek())
        return 1;
    return -1;

}

Student::~Student()
{
    //dtor
}
