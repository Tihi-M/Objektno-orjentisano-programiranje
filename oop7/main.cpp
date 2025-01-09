#include <iostream>
#include "Ugao.h"
#include "UgaoLista.h"

int main()
{

    Ugao u1(67,40,23);
    Ugao u2(57,19,37);
    Ugao u4(75,21,22);

    Ugao u3 = u1 + u2;

    UgaoLista l1;
    l1.addFirst(u1);
    l1.addLast(u2);
    l1.addLast(u3);
    l1.addLast(u4);
    l1.print();
    l1.sort();
    l1.print();
    l1.prosijecnaVrijednost();
    return 0;
}
