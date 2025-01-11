#ifndef EKIPA_H
#define EKIPA_H
#include <iostream>

class Ekipa
{
    public:
        Ekipa(double b = 0.0,int n = 0,char* name = "");
        virtual ~Ekipa();

        double Getbudzet() const { return budzet; }
        void Setbudzet(double);
        int GetbrIgraca() const { return brIgraca; }
        void SetbrIgraca(int);
        char* Getnaziv() const { return naziv; }
        void Setnaziv(char*);

        static Ekipa* najveciBudzet(){return naj;};

        void print();
        Ekipa& operator++(int k);
        friend std::ostream& operator<<(std::ostream&,const Ekipa&);
        Ekipa& operator++();
        friend bool operator<(const Ekipa&, const Ekipa&);
        friend bool operator>(const Ekipa&, const Ekipa&);
        //friend bool operator==(const Ekipa&, const Ekipa&);
        friend bool operator>=(const Ekipa&, const Ekipa&);
        friend bool operator<=(const Ekipa&, const Ekipa&);
    protected:
        double budzet;
        int brIgraca;
        char* naziv;
        static double maxbudzet;
        static Ekipa* naj;
};

#endif // EKIPA_H
