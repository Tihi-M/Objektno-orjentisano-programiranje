#ifndef DATUMVRIJEME_H
#define DATUMVRIJEME_H
#include "Datum.h"
class DatumVrijeme: public Datum {
    public:
        DatumVrijeme();
        DatumVrijeme(const Datum& d);
        DatumVrijeme(int,int,int,int,int);

        void print() const;

    private:
        int hh;
        int mm;


};

#endif // DATUMVRIJEME_H
