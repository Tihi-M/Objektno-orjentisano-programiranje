#ifndef TIJELO_H
#define TIJELO_H
#include <iostream>

class Tijelo
{
    public:
        Tijelo(char);
        virtual ~Tijelo();

        virtual char vrsta() const = 0;
        virtual double zapremina() const = 0;
        virtual Tijelo* kopija() const = 0;
        virtual void pisi() const {std::cout<<"Tijelo"<<std::endl;};

    protected:
        char idTijela[10];
        static int cntTijela;
};

#endif // TIJELO_H
