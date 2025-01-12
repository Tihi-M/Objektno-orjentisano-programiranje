#include <iostream>
#include "Student.h"
#include "StudentPostdiplomac.h"


int main()
{
    Student s1(1,7.6);
    Student s2(2,9.6);
    if(s1.compareTo(s2) == -1)
        std::cout<<"Manji"<<std::endl;

    StudentPostdiplomac s3(3,8.4,10);
    s3.print();
    return 0;
}
