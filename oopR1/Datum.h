#ifndef DATUM_H
#define DATUM_H
#include <iostream>

class Datum
{
    public:
        Datum();
        Datum(int,int,int);
        virtual ~Datum();

        int Getd() const { return d; }
        void Setd(int);
        int Getm() const { return m; }
        void Setm(int);
        int Getg() const { return g; }
        void Setg(int);

        void print() const;
        int doKrajaGod() const;
        int prosloDana() const;
        int compareTo(const Datum&);
        friend bool operator>(const Datum&,const Datum&);
        friend bool operator>(const Datum&,const Datum&);
        friend bool operator==(const Datum&,const Datum&);
        friend bool operator<=(const Datum&,const Datum&);
        friend bool operator>=(const Datum&,const Datum&);
        Datum& operator++(int);
        Datum& operator--(int);

        friend std::ostream& operator<<(std::ostream&,const Datum&);

    private:
        int d;
        int m;
        int g;
        bool parna(int) const;
        int monthLength(int,int) const;

};

#endif // DATUM_H
