#ifndef UGAO_H
#define UGAO_H

#include <math.h>
#include <iostream>

class Ugao{
    double val;
    const double PI = 3.14;
    public:
        void setRad(double);
        double getRad() const;//samo provjerava vrijednost

        void set_step(int s,int m,int d);
        Ugao plus(const Ugao &u2) const;
    private:
        void normalize();
};


#endif // UGAO_H
