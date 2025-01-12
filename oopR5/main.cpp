#include <iostream>
#include "String.h"

int main()
{
    char *ime = new char[10];
    std::cin>>ime;
    String s1(ime);
    std::cout<<s1<<std::endl;

    char *prezime = new char[20];
    std::cin>>prezime;
    String s2(prezime);

    String s3 = s1;

    if(s3 == s1)
        std::cout<<"jednaki"<<std::endl;

    s3+=' ';

    String s4 = s3 + s2;
    std::cout<<s4;
    return 0;
}
