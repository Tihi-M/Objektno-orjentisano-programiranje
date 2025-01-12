#ifndef KOLICINANOVCA_H
#define KOLICINANOVCA_H

#include "Valuta.h"


class KolicinaNovca : public Valuta
{
    public:
        KolicinaNovca(char*,double,double);
        virtual ~KolicinaNovca();

        double Getkolicina() const { return kolicina; }
        void Setkolicina(double val) { kolicina = val; }

        friend KolicinaNovca operator+(KolicinaNovca,KolicinaNovca);
        KolicinaNovca& operator-=(KolicinaNovca);
        friend bool operator==(KolicinaNovca,KolicinaNovca);
        operator double();
        void konvertuj(const Valuta&);
        friend std::ostream& operator<<(std::ostream&,const KolicinaNovca&);
    protected:
        double kolicina;

    private:
};

#endif // KOLICINANOVCA_H
