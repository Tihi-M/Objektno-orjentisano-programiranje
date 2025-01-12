#ifndef STUDENT_H
#define STUDENT_H

#include "Ocjena.h"
#include <iostream>

class Student
{
    public:
        Student(int,int);
        virtual ~Student();
        Student& operator+=(const Ocjena&);
        Student& operator-=(const Ocjena&);
        Student& operator=(const Student&);
        friend std::ostream& operator<<(std::ostream&,const Student&);
        friend bool operator<=(const Student&,const Student&);
        friend bool operator>=(const Student&,const Student&);
        void print();

    protected:
        int brInd;
        Ocjena* ocjene;
        int kapacitet;

    private:
};

#endif // STUDENT_H
