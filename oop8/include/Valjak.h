#ifndef VALJAK_H
#define VALJAK_H
#include "Tijelo.h"
#include <iostream>

class Valjak: public Tijelo
{
    public:
        Valjak(double,double);
        virtual ~Valjak();

        double Getr() { return r; }
        void Setr(double);
        double Geth() { return h; }
        void Seth(double);

        char vrsta() const override;
        double zapremina() const override;
        Tijelo* kopija() const override;
        void pisi() const override;

        friend Valjak operator+(Valjak,Valjak);
        friend std::ostream& operator<<(std::ostream&,Valjak);

    protected:

    private:
        double r;
        double h;
};

#endif // VALJAK_H
