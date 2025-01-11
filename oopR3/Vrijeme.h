#ifndef VRIJEME_H
#define VRIJEME_H
#include <iostream>

class Vrijeme
{
    public:
        Vrijeme();
        Vrijeme(int,int);
        virtual ~Vrijeme();

        int Getsat() const { return sat; }
        void Setsat(int val);
        int Getmin() const { return minn; }
        void Setmin(int val);

        Vrijeme& operator++();
        friend std::ostream& operator<<(std::ostream&,const Vrijeme&);
    protected:

        int sat;
        int minn;
        static int obj;
};

#endif // VRIJEME_H
