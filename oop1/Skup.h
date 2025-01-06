#ifndef SKUP_H
#define SKUP_H

class Skup{
    public:
        Skup();
        Skup(int x);
        Skup(int *data,int len);
        virtual ~Skup();

        Skup unija(const Skup&) const;
        Skup presjek(const Skup&) const;
        Skup& razlika(const Skup&);
        void print() const;
        int setSize() const;
        void setData(int *data);
        void setCap(int x);
        void setPop(int x);
        void delEl(int x);
    private:
            int *data;
            int cap;
            int pop;
            void bubbleSort(int* data, int pop);
            int findPos(int x) const;
};

#endif // SKUP_H
