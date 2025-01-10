#include <iostream>
#include "Red.h"
int main()
{
    Red<int> arr1;
    Red<double> arr2;

    Red<int> arr4 = arr1;
    arr4 = arr4;

    arr1 += 5;
    arr1 += 7;

    for(int i=0;i<2;i++)
        std::cout << arr1[i] << " " ;

    std::cout << std::endl;

    arr4 = arr1;
    for(int i=0;i<2;i++)
        std::cout << arr4[i] << " " ;
    return 0;
}
