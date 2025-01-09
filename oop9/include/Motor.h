#ifndef MOTOR_H
#define MOTOR_H
#include "Vozilo.h"
#include <iostream>

class Motor: public Vozilo
{
    public:
        Motor(std::string,float,int);
        Motor(float,int);
        virtual ~Motor();

        float Get1to100() const { return to100; }
        void Set1to100(float);
        int Getpower() const { return power; }
        void Setpower(int);
        std::string Getname() const {return name;};
        void Setname(std::string name){this->name = name;};

        char sufix() const override;
        void print() const override;
        Vozilo* kopija() const override;

        friend Motor operator+(Motor,Motor);
        friend std::ostream& operator<<(std::ostream&,Motor);


    protected:

    private:
        float to100;
        int power;
        std::string name;
};

#endif // MOTOR_H
