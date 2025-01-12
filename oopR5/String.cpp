#include "String.h"
#include <string.h>

String::String(){
    this->data=nullptr;
    this->cap = 0;
}
String::String(char* str)
{
    this->cap = strlen(str)+1;
    this->data = new char[strlen(str)];

    for(int i = 0; i  < this->cap; i++)
        this->data[i] = str[i];

    this->data[this->cap] = '\0';
}

String::String(const String& str){
    this->cap = str.getCap();
    this->data = new char[this->cap];
    for(int i = 0; i < this->cap;i++)
        this->data[i] = str.data[i];
}

void String::setData(char* str){
    this->data = new char[this->cap];
    for(int i = 0; i < this->cap;i++)
        this->data[i] = str[i];
}

String operator+(const String& str1, const String& str2){
    int cap = str1.getCap()+str2.getCap()-1;
    char *data_ = new char[cap];
    int j = 0;
    for(int i = 0; i < str1.getCap()-1;i++){
        data_[j]=str1.data[i];
        j++;
    }
    for(int i = 0; i < str2.getCap()-1;i++){
        data_[j] = str2.data[i];
        j++;
    }
    data_[j] = '\0';
    String res(data_);
    return res;
}

String& String::operator+=(char c){
    this->cap= this->cap+1;
    char *ext = new char[this->cap];
    int i = 0;
    while(i < this->cap-2){
        ext[i] = this->data[i];
        i++;
    }
    ext[i] = c;
    i++;
    ext[i] = '\0';
    this->setData(ext);
    return *this;
}

String& String::operator=(const String& str){
    delete[] this->data;
    this->data = new char[str.cap];
    this->cap = str.cap;
    this->setData(str.data);
    return * this;
}

bool operator==(String& str1,String& str2){
    if(str1.cap != str2.cap)
        return false;

    for(int i = 0; i < str1.cap;i++)
        if(str1.data[i] != str2.data[i])
            return false;
    return true;
}

std::ostream& operator<<(std::ostream& os,const String& s){
    for(int i = 0; i < s.cap;i++)
        os<<s.data[i];
    return os;
}
String::~String()
{
    //dtor
}
