#ifndef DATUM_H
#define DATUM_H

class Datum{
    private:
        int d;
        int m;
        int g;
        bool prestupna(int) const;
        int monthLength(int,int) const;
    public:
        void setD(int);
        void setM(int);
        void setG(int);
        int getD() const;
        int getM() const;
        int getG() const;
        Datum();
        Datum(int,int,int);
        void print() const;
        int prosloDana() const;
        int doKrajaGod() const;
        Datum prethodniDan() const;
        Datum naredniDan() const;
        int compareTo(const Datum&) const;
};

#endif // DATUM_H
