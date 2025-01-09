#ifndef KAMION_H
#define KAMION_H
#include <iostream>
#include "Vozilo.h"
class Kamion:public Vozilo
{
    public:
        Kamion(std::string name,int,int);
        Kamion(int,int);
        virtual ~Kamion();

        int Getteret() const { return teret; };
        void Setteret(int);
        int Getpower() const { return power; };
        void Setpower(int);
        std::string Getname()const {return name;};
        void Setname(std::string);

        char sufix() const override;
        void print() const override;
        Vozilo* kopija() const override;

        friend Kamion operator+(Kamion,Kamion);
        friend std::ostream& operator<<(std::ostream&,Kamion);

    protected:

    private:
        int teret;
        int power;
        std::string name;
};

#endif // KAMION_H
