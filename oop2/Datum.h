#ifndef DATUM_H
#define DATUM_H

class Datum{
    public:
        Datum();
        Datum(int,int,int);

        bool validan(int,int,int);
        void print() const;

        int getDay() const;
        int getMonth() const;
        int getYear() const;

        void setDay(int);
        void setMonth(int);
        void setYear(int);

        int danNed() const;
        Datum sljedeci() const;
        Datum prethodni() const;
        int brojDanaOdPocetkaGod() const;
        int razlika(const Datum&) const;

    private:

        bool prestupna(int) const;
        int monthLength(int,int) const;
    protected:
        int dan;
        int mjesec;
        int godina;
};



#endif // DATUM_H
