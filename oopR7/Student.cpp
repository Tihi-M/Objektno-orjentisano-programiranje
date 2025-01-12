#include "Student.h"
#include "Ocjena.h"
Student::Student(int brInd,int cap)
{
    this->brInd = brInd;
    this->kapacitet = cap;
    this->ocjene = new Ocjena[cap];
    for(int i = 0; i < cap;i++){
        this->ocjene[i].Setvrijednost(0);
        this->ocjene[i].SetidPredmeta(0);
    }

}

Student& Student::operator+=(const Ocjena& o){
    for(int i = 0; i  < this->kapacitet ;i++){
        if(this->ocjene[i].Getvrijednost() == 0){
            this->ocjene[i] = o;
            return *this;
        }
    }

    throw 123;
}

Student& Student::operator-=(const Ocjena& o){
    for(int i = 0; i < this->kapacitet;i++){
        if(this->ocjene[i].Getvrijednost() == o.Getvrijednost()){
            Ocjena* nova = new Ocjena(0,0);
            this->ocjene[i] = *nova;
            return *this;
        }
    }
}

Student& Student::operator=(const Student& s){
    delete this->ocjene;
    this->brInd = s.brInd;
    this->kapacitet = s.kapacitet;
    this->ocjene = new Ocjena[this->kapacitet];
    for(int i = 0;i < this->kapacitet;i++)
        this->ocjene[i] = s.ocjene[i];

    return *this;
}

bool operator<=(const Student& s1,const Student& s2){
    int sum1 = 0;

    for(int i = 0; i < s1.kapacitet;i++)
        sum1+=s1.ocjene[i].Getvrijednost();

    double prosjek1 = sum1/s1.kapacitet;

    int sum2 = 0;

    for(int i = 0; i < s2.kapacitet;i++)
        sum2+=s2.ocjene[i].Getvrijednost();

    double prosjek2 = sum2/s2.kapacitet;

    return sum1 <= sum2;
}

bool operator>=(const Student& s1,const Student& s2){
    int sum1 = 0;

    for(int i = 0; i < s1.kapacitet;i++)
        sum1+=s1.ocjene[i].Getvrijednost();

    double prosjek1 = sum1/s1.kapacitet;

    int sum2 = 0;

    for(int i = 0; i < s2.kapacitet;i++)
        sum2+=s2.ocjene[i].Getvrijednost();

    double prosjek2 = sum2/s2.kapacitet;

    return sum1 >= sum2;
}

void Student::print(){
    std::cout<<this->brInd<<std::endl;
    for(int i =0; i < this->kapacitet;i++)
        std::cout << this->ocjene[i].Getvrijednost()<< " ";
    std::cout<<std::endl;
}

Student::~Student()
{
    //dtor
}
