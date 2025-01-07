#include <iostream>
#include "Student.h"
#include "StudentLista.h"
int main()
{
    Student s1("Tiho","Miladinovic",40,2023,"PMF",6.8);
    Student s2("Tihomir","Miladinovic",43,2023,"PMF",8.8);
    Student s3("Marko","Markovic",41,2023,"PMF",6.5);
    Student s4("Janko","jankoic",42,2023,"PMF",7.4);

    StudentLista l1;
    l1.addFirst(s1);
    l1.addLast(s2);
    l1.addFirst(s3);
    l1.addLast(s4);

    l1.print();
    l1.sort();
    l1.print();
    return 0;
}
