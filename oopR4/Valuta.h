#ifndef VALUTA_H
#define VALUTA_H
#include <iostream>

class Valuta
{
    public:
        Valuta(char*,double);
        virtual ~Valuta();

        char* Getnaziv() const { return naziv; }
        void Setnaziv(char*);
        double Getiznos() const { return iznos; }
        void Setiznos(double);

        friend std::ostream& operator<<(std::ostream&,const Valuta&);
    protected:
        char* naziv;
        double iznos;

    private:
};

#endif // VALUTA_H
