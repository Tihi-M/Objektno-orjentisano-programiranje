#ifndef TABELASTUDENATA_H
#define TABELASTUDENATA_H
#include "Student.h"

class TabelaStudenata:public Student
{
    public:
        TabelaStudenata();
        bool postoji(Student* a);
        void dodaj(Student s);
        void ukloni(int id);
        void postavi(Student s,int pos);
        void print(Student s);
        virtual ~TabelaStudenata();

    protected:

    private:
        Student data[10];
        int brElem;
};

#endif // TABELASTUDENATA_H
