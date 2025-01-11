#include "FudbalskaEkipa.h"

FudbalskaEkipa::FudbalskaEkipa(double b,int n,char* name,int* igraci):Ekipa(b,n,name)
{
    this->brojevi_igraca = new int[n];
    for(int i = 0; i < n;i++)
        this->brojevi_igraca[i] = igraci[i];
}

std::ostream& operator<<(std::ostream& os, const FudbalskaEkipa& fb){
    os<<(Ekipa&)fb;
    for(int i = 0; i < fb.brIgraca;i++)
        os<<fb.brojevi_igraca[i]<<" ";
    return os;
}

FudbalskaEkipa::~FudbalskaEkipa()
{
    //dtor
}
