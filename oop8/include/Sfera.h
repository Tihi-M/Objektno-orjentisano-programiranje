#ifndef SFERA_H
#define SFERA_H
#include "Tijelo.h"

class Sfera:public Tijelo{
    public:
        Sfera(double);
        virtual ~Sfera();

        virtual char vrsta() const;
        virtual double zapremina() const;
        virtual void pisi() const;
        virtual Tijelo* kopija() const;

        friend Sfera operator+(Sfera,Sfera);
    protected:

    private:
        double r;
};

#endif // SFERA_H
