#ifndef INTERVAL_H
#define INTERVAL_H

#include "Vrijeme.h"


class Interval : public Vrijeme
{
    public:
        Interval(int,int,int);
        void Setlen(int);
        int Getlen() const {return trajanje; };
        virtual ~Interval();

        friend std::ostream& operator<<(std::ostream&,const Interval&);

        Interval& operator+=(int);
        Vrijeme kraj() const;
        friend bool operator>(const Interval&,const Interval&);
    protected:
        int trajanje;
};

#endif // INTERVAL_H
