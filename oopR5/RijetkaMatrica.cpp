#include "RijetkaMatrica.h"
#ifndef RIJETKAMATRICA_CPP
#define RIJETKAMATRICA_CPP
template <class T>

RijetkaMatrica<T>::RijetkaMatrica(int n,int m)
{
    this->brElem=0;
    this->m =m;
    this->n =n;
}
template <class T>
void RijetkaMatrica<T>::dodaj(int r,int c,T elem){
    this->brElem++;
    for(int i =0 ;i < 100;i++){
        if(this->row[i] == 0){
            this->row[i] = r;
            return;
        }

        if(this->col[i] == 0){
            this->col[i] = c;
            return;
        }

        if(this->data[i] == 0){
            this->data[i] = elem;
            return;
        }
    }
}
template <class T>
T RijetkaMatrica<T>::operator()(int i,int j){
    int temp_i = 0;
    int temp_j = 0;
    bool found_i = false;
    bool found_j = false;

    for(int k = 0;k < 100;k++){
        if(this->row[k]== i){
            temp_i=k;
            found_i = true;

        }

        if(this->coll[k] == j){
            temp_j = k;
            found_j = true;
        }

    }
    if(temp_i == temp_j && found_i && found_j){
        return this->data[temp_i];
    }
    if(!found_i || !found_j) throw NevalidniIndeksi();
    return 0;
}
template <class T>
int RijetkaMatrica<T>::sumaVrste(int row){
    int sum = 0;
    //??????????????????????????
    for(int i = 0; i < 100 ;i++){
        if(this->row[i] == row){
            sum+=this->data[i];
        }
    }
    return sum;
}


template <class T>
RijetkaMatrica<T>::~RijetkaMatrica()
{
    //dtor
}
#endif // RIJETKAMATRICA_CPP
