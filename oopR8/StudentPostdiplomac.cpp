#include "StudentPostdiplomac.h"
#include "Student.h"
#include <iostream>

StudentPostdiplomac::StudentPostdiplomac(int id,float prosjek,int brProjekata):Student(id,prosjek)
{
    this->brProjekata = brProjekata;
}

StudentPostdiplomac::StudentPostdiplomac(const StudentPostdiplomac& s){
    this->brProjekata=s.brProjekata;
    this->id = s.id;
    this->prosjek = s.prosjek;
}

void StudentPostdiplomac::print(){
    Student::print();
    std::cout<<"Broj projekata: "<<this->brProjekata<<std::endl;
}

StudentPostdiplomac::~StudentPostdiplomac()
{
    //dtor
}
