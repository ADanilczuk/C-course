#ifndef z1
#define z1

class Data
{
protected:
    int day;
    int month;
    int year;


public:

    Data();
    Data(int , int , int );

    int get_day();
    int get_month();
    int get_year();

    bool operator<(Data&);

    int how_many_days(Data&);
    int operator-(Data&);
    void operator++();
    void operator--();

    void operator+=(int days);
    void operator-=(int days);


protected:
    bool test_if_leap(Data& d);
    bool test_if_correct(Data& d);

    static int dniwmiesiacach[2][13];
    static int dniodpoczroku[2][13];
};

class Godzina : public Data
{
protected:
    int hour;
    int minute;
    int second;


public:

    Godzina();
    Godzina(int, int, int);
    Godzina(int , int , int, int, int, int );

    int get_hour();
    int get_minute();
    int get_second();

    int how_many_seconds(Godzina&);

    int operator-(Godzina&);
    void operator++();
    void operator--();

    void operator+=(int);
    void operator-=(int);

    bool operator<(Godzina&);
    bool operator==(Godzina&);

};

//Data& operator++(Data& d);

#endif // z1.hpp
