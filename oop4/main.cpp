#include <iostream>
#include "Temperatura.h"
#include "TemperaturaLista.h"
int main()
{
    Temperatura t1(32,'+','F');
    //t1.convertToFarenheit();
    //t1.print();
    Temperatura t2(87,'+','C');
    Temperatura t3(123,'-','F');
    Temperatura t4(156,'+','F');
    Temperatura t5(24,'-','C');
    Temperatura t6(51,'+','C');

    TemperaturaLista l1;
    l1.addFirst(t1);
    l1.addLast(t2);
    l1.addFirst(t3);
    l1.addLast(t4);
    l1.addFirst(t5);
    l1.addLast(t6);

    l1.print();
    l1.sort();
    l1.print();

    return 0;
}
