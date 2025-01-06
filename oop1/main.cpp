#include <iostream>
#include "Skup.h"

void fillArr(int *arr,int len){
    if(len ==0)
        return;
    std::cin>>*arr;
    fillArr(arr+1,len-1);
}


void printArr(int *arr, int len){
    if(len == 0){
        std::cout<<std::endl;
        return;
    }
    std::cout<<*arr<< " ";
    printArr(arr+1,len-1);

}

int main()
{
    std::cout<<"Prvi skup: "<<std::endl;
    int n;
    std::cin>>n;

    int *arr = new int[n];
    fillArr(arr,n);

    Skup s2(arr,n);
    s2.print();

    std::cout<<"Drugi skup: "<<std::endl;
    int n2;
    std::cin>>n2;

    int *arr2 = new int[n2];
    fillArr(arr2,n2);

    Skup s3(arr2,n2);
    s3.print();

    //Skup s4 = s2.presjek(s3);
    //s4.print();

    //s4.delEl(5);
    //s4.print();

    s2.razlika(s3);
    s2.print();

    return 0;
}
