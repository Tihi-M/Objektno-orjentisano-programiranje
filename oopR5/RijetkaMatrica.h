#ifndef RIJETKAMATRICA_H
#define RIJETKAMATRICA_H

class RijetkaMatricaEx
{
public:
    const char* what() const noexcept{
        return "Greska(rijetka matrica)";
    }

};

class NevalidniIndeksi : public RijetkaMatricaEx{
public:
    const char* what() const noexcept
    {
        return "indeksi nisu validno zadati";
    }
};

template <class T>
class RijetkaMatrica
{
    public:
        RijetkaMatrica(int n,int m);
        void dodaj(int r,int c, T elem);
        T operator()(int i,int j);
        int sumaVrste(int row);
        RijetkaMatrica<T> operator+(RijetkaMatrica<T>& r);

        virtual ~RijetkaMatrica();

    private:
        int n;
        int m;
        int brElem;
        int row[100];
        int coll[100];
};
#include "RijetkaMatrica.cpp"
#endif // RIJETKAMATRICA_H
