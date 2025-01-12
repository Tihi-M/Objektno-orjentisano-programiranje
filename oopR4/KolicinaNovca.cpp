#include "KolicinaNovca.h"
#include "Valuta.h"
KolicinaNovca::KolicinaNovca(char* name,double iznos,double kolicina):Valuta(name,iznos)
{
    this->kolicina = kolicina;
}

void KolicinaNovca::konvertuj(const Valuta& v){
    double k = (this->Getkolicina() / this->Getiznos())*v.Getiznos();
    this->Setkolicina(k);
    this->Setiznos(v.Getiznos());
    this->Setnaziv(v.Getnaziv());
}

KolicinaNovca operator+(KolicinaNovca k1,KolicinaNovca k2){
    Valuta v(k1.Getnaziv(),k1.Getiznos());
    k2.konvertuj(v);
    std::cout<<k2.Getkolicina();
    return KolicinaNovca(k1.Getnaziv(),k1.Getiznos(),k1.Getkolicina()+k2.Getkolicina());
}

bool operator==(KolicinaNovca k1,KolicinaNovca k2){
    Valuta v(k1.Getnaziv(),k1.Getiznos());
    k2.konvertuj(v);

    if(k1.Getkolicina() == k2.Getkolicina())
        return true;
    return false;
}

KolicinaNovca::operator double(){
    double g = this->kolicina / this->iznos;
    return g;
}

std::ostream& operator<<(std::ostream& os,const KolicinaNovca& k){
    os<<(Valuta&)k;
    os<<" "<<k.Getkolicina();
    return os;
}



KolicinaNovca::~KolicinaNovca()
{
    //dtor
}
