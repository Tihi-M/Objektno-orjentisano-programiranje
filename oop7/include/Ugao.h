#ifndef UGAO_H
#define UGAO_H


class Ugao
{
    public:
        Ugao();
        Ugao(int,int,int);
        virtual ~Ugao();

        int Getstep() const { return step; };
        void Setstep(int);
        int Getmin() const { return minn; };
        void Setmin(int);
        int Getsec() const { return sec; };
        void Setsec(int);

        int compareTo(const Ugao&);
        void print() const;
        Ugao operator+(const Ugao&);

    protected:

    private:
        int step;
        int minn;
        int sec;
};

#endif // UGAO_H
