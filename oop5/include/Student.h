#ifndef STUDENT_H
#define STUDENT_H
#include <string>
class Student{
    private:
        std::string ime;
        std::string prezime;
        int brInd;
        int godina;
        std::string faks;
        float prosjecnaOcjena;
    public:
        Student();
        Student(std::string,std::string,int,int,std::string,float);
        void setIme(std::string);
        void setPrezime(std::string);
        void setInd(int);
        void setGodina(int);
        void setImeFaksa(std::string);
        void setOcjena(float);
        std::string getIme() const;
        std::string getPrezime() const;
        int getInd() const;
        int getGodina() const;
        std::string getImeFaksa() const;
        float getOcjena() const;
        void print() const;
        void povecajProsjek(float);
        char getProsjek() const;
};

#endif // STUDENT_H
