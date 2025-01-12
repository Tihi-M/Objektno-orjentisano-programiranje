#ifndef VEKTOR_H
#define VEKTOR_H

template<class T>
class Vektor
{
    public:
        Vektor();
        virtual ~Vektor();

        void dodaj(T);
        void rotirajZaK(int);
        Vektor defragmentKopija();
        void ukloni(int);
        void rotiraj(T*);
        void print();
    protected:

    private:
        T data[10];
        bool zauzet[10];
};

#include "Vektor.cpp"
#endif // VEKTOR_H
