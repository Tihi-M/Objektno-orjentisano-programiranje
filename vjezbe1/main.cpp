#include <iostream>
#include <string.h>

class Student{
private:
    char ime[20];
    char prezime[20];
    int br_ind;
    int god_upisa;
public:
    Student(char *ime,char *prezime,int br_ind, int god_upisa){
        strcpy(this->ime,ime);
        strcpy(this->prezime,prezime);
        this->br_ind = br_ind;
        this->god_upisa = god_upisa;
    }
    void print(){
        std::cout << ime << " " <<
        prezime << " " << br_ind << "/" <<
        god_upisa << std::endl;
    }
};


int main()
{
    Student s1("Tihomir","Miladinovic",40,23);
    s1.print();

    return 0;
}
