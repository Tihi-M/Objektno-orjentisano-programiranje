#ifndef STRING_H
#define STRING_H

#include <iostream>
class String
{
    public:
        String(char*);
        String();
        String(const String&);
        virtual ~String();

        int getCap()const {return this->cap;};
        char* getData(){return this->data;};
        void setData(char*);

        friend String operator+(const String&,const String&);
        String& operator+=(char);
        String& operator=(const String&);
        friend bool operator==(String&, String&);
        friend std::ostream& operator<<(std::ostream&, const String&);

    protected:
        char* data;
        int cap;

    private:
};

#endif // STRING_H
