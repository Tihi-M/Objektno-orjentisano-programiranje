#ifndef FUDBALSKAEKIPA_H
#define FUDBALSKAEKIPA_H

#include "Ekipa.h"


class FudbalskaEkipa : public Ekipa
{
    public:
        FudbalskaEkipa(double,int,char*,int*);
        virtual ~FudbalskaEkipa();

        int* Getbrojevi_igraca() { return brojevi_igraca; }
        void Setbrojevi_igraca(int*);
        friend bool operator==(const FudbalskaEkipa&, const FudbalskaEkipa&);
        friend std::ostream& operator<<(std::ostream&,const FudbalskaEkipa&);
    protected:
        int* brojevi_igraca;
};

#endif // FUDBALSKAEKIPA_H
