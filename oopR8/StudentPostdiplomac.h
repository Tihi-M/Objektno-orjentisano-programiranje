#ifndef STUDENTPOSTDIPLOMAC_H
#define STUDENTPOSTDIPLOMAC_H

#include "Student.h"


class StudentPostdiplomac : public Student
{
    public:
        StudentPostdiplomac(int,float,int);
        StudentPostdiplomac(const StudentPostdiplomac&);
        void print();
        virtual ~StudentPostdiplomac();

    protected:

    private:
        int brProjekata;
};

#endif // STUDENTPOSTDIPLOMAC_H
