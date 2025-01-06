#include <iostream>
#include "Datum.h"
#include "DatumStack.h"
int main()
{
    int d,m,g;
    std::cin>>d>>m>>g;
    Datum d1(d,m,g);
    //d1.print();
    //2 std::cout<<d1.prosloDana();
    Datum d2 = d1.prethodniDan();
    //d2.print();

    Datum d3 = d1.naredniDan();
    //d3.print();

    //std::cout<<d3.compareTo(d2)<<std::endl;

    DatumStack st1;
    st1.push(d1);
    st1.push(d2);
    st1.push(d3);
    st1.print();
    std::cout<<st1.stackSize()<<std::endl;

    st1.pop();
    std::cout<<"After pop: "<<std::endl;
    st1.print();
    //std::cout<<st1.stackSize()<<std::endl;
    return 0;
}
