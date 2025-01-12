#include "Vektor.h"
#include <iostream>
#ifndef VEKTOR_CPP
#define VEKTOR_CPP

template<class T>
Vektor<T>::Vektor()
{
    for(int i = 0 ; i < 10;i++)
        this->zauzet[i] = false;
}

template<class T>
void Vektor<T>::dodaj(T elem){
    for(int i = 0;i < 10;i++){
        if(this->zauzet[i] == false){
            this->zauzet[i] = true;
            this->data[i] = elem;
            return;
        }
    }
    throw 1;
}

template<class T>
void Vektor<T>::ukloni(int i){
    this->zauzet[i] = false;
}

template<class T>
void Vektor<T>::rotiraj(T* data){
    T poslednji = this->data[9];
    bool posl = this->zauzet[9];
    for(int i = 9;i > 0;i--){
        this->data[i] = this->data[i-1];
        this->zauzet[i] = this->zauzet[i-1];
    }

    this->data[0] = poslednji;
    this->zauzet[0] = posl;
}

template<class T>
void Vektor<T>::rotirajZaK(int k){
    for(int i = 0; i < k;i++)
        rotiraj(this->data);
}

template<class T>
Vektor<T> Vektor<T>::defragmentKopija(){
    Vektor<T> kopija;
    int j = 0;
    for(int i = 0; i < 10;i++){
        if(this->zauzet[i] == true){
            kopija.data[j] = this->data[i];
            j++;
        }
    }

    for(int i = 0; i < 10;i++){
        if(this->zauzet[i] == false){
            kopija.data[j] = this->data[i];
            j++;

        }
    }
    return kopija;
}

template<class T>
void Vektor<T>::print(){
    for(int i =0 ; i < 10;i++)
        std::cout<<this->data[i]<<" ";
    std::cout<<std::endl;
}

template<class T>
Vektor<T>::~Vektor()
{
    delete[] this->data;
    delete[] this->zauzet;
}

#endif // VEKTOR_CPP
