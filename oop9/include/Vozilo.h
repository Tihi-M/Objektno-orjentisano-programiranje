#ifndef VOZILO_H
#define VOZILO_H
#include <iostream>

class Vozilo
{
    public:
        Vozilo(char p);
        virtual ~Vozilo();

        virtual char sufix() const = 0;
        virtual void print() const{std::cout<<"vozilo"<<std::endl;};
        virtual Vozilo* kopija() const = 0;
    protected:
        char id[10];
        static int cnt;
};

#endif // VOZILO_H
