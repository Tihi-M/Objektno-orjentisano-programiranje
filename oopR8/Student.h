#ifndef STUDENT_H
#define STUDENT_H


class Student
{
    public:
        Student();
        Student(int id,float prosjek):id(id),prosjek(prosjek){};
        Student(const Student& s);
        virtual ~Student();

        int Getid()const { return id; }
        void Setid(int);
        float Getprosjek()const { return prosjek; }
        void Setprosjek(float);

        int compareTo(const Student&);
        void print() const;


    protected:
        int id;
        float prosjek;
};

#endif // STUDENT_H
