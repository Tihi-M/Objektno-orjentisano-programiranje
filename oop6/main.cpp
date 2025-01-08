#include <iostream>
#include "Client.h"
#include "ClientQueue.h"

int main()
{
    Client c1("Tihomir","Miladinovic",7,30);
    Client c2("Marko","Markovic",8,30);
    Client c3("Janko","Jankovic",14,30);
    Client c4("Petar","Petrovic",7,30);

    ClientQueue q1;
    q1.push(c1);
    q1.push(c2);
    q1.push(c3);
    q1.push(c4);


    q1.print();
    float vrijeme= q1.average(16,0);
    std::cout<<vrijeme<< " sati"<<std::endl;

    q1.sort();
    q1.print();
    return 0;
}
