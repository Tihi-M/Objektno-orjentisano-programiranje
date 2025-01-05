#include "Ugao.h"

void Ugao::setRad(double val){
    this->val = val;
    this->normalize();
}

double Ugao::getRad() const{
    return  this->val;
}

void Ugao::set_step(int s,int m,int d){
    double tmp = s+m/60.0+d/3600.0;
    this->val = tmp/180*M_PI;
    normalize();
}

Ugao Ugao::plus(const Ugao &u2) const{//vraca ugao
    Ugao ret;
    ret.setRad(val+u2.val);
    return ret;
}

void Ugao::normalize(){
    while(this->val < 0)
        this->val += 2 * M_PI;

    while(this->val > 2*M_PI)
        this->val -= 2 * M_PI;


}
