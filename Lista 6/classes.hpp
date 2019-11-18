#include <cmath>
#include <iostream>
#include <string>
#include <sstream> //to_string
#include <vector>

using namespace std;

class Wyrazenie
{
protected:
    Wyrazenie(std::string);
public:
    const std::string typ;
    virtual double oblicz() const =0;
    virtual string opis() const =0;
};

class Zmienna : public Wyrazenie
{
    const std::string nazwa;
public:
    static std::vector<std::pair<std::string,double> > zmienne;
    Zmienna(std::string);
    static void wstaw(std::string,double);
    static void zmien(std::string,double);
    double oblicz() const;
    std::string opis() const;
};

class Liczba: public Wyrazenie
{
    const double wartosc;
public:
    Liczba(double);
    double oblicz()  const;
    std::string opis() const;
};


class Stala: public Wyrazenie
{
public:
    Stala();
    virtual double oblicz() = 0;
    virtual std::string opis() = 0;
};

class pi: public Stala
{
public:
    const double wartosc;
    pi();
    double oblicz() const;
    std::string opis() const;

};

class e: public Stala
{
public:
    const double wartosc;
    e();
    double oblicz() const;
    std::string opis() const;
};

class fi: public Stala
{
public:
    const double wartosc;
    fi();
    double oblicz() const;
    std::string opis() const;
};

class Operator1: public Wyrazenie
{
public:
    Wyrazenie *w1;
    Operator1(Wyrazenie*,std::string);
};

class Operator2: public Operator1
{
public:
    Wyrazenie *w2;
    Operator2(Wyrazenie*, Wyrazenie*, std::string);
};


class Dodawanie: public Operator2
{
public:
    Dodawanie(Wyrazenie*, Wyrazenie*);
    double oblicz() const;
    std::string opis() const;
};

class Odejmowanie: public Operator2
{
public:
    Odejmowanie(Wyrazenie*, Wyrazenie*);
    double oblicz() const;
    std::string opis() const;
};

class Mnozenie: public Operator2
{
public:
    Mnozenie(Wyrazenie*, Wyrazenie*);
    double oblicz() const;
    std::string opis() const;
};


class Dzielenie: public Operator2
{
public:
    Dzielenie(Wyrazenie*, Wyrazenie*);
    double oblicz() const;
    std::string opis() const;
};

class Logarytm: public Operator2
{
public:
    Logarytm(Wyrazenie*, Wyrazenie*);
    double oblicz() const;
    std::string opis() const;
};

class Modulo: public Operator2
{
public:
    Modulo(Wyrazenie*, Wyrazenie*);
    double oblicz() const;
    std::string opis() const;
};


class Potega: public Operator2
{
public:
    Potega(Wyrazenie*, Wyrazenie*);
    double oblicz() const;
    std::string opis() const;
};



//Jednoargumentowe
class Sinus: public Operator1
{
public:
    Sinus(Wyrazenie*);
    double oblicz() const;
    std::string opis() const;
};

class Cosinus: public Operator1
{
public:
    Cosinus(Wyrazenie*);
    double oblicz() const;
    std::string opis() const;
};


class Ln: public Operator1
{
public:
    Ln(Wyrazenie*);
    double oblicz() const;
    std::string opis() const;
};

class Bezw: public Operator1
{
public:
    Bezw(Wyrazenie*);
    double oblicz() const;
    std::string opis() const;
};

class Przeciw: public Operator1
{
public:
    Przeciw(Wyrazenie*);
    double oblicz() const;
    std::string opis() const;
};

class Odwr: public Operator1
{
public:
    Odwr(Wyrazenie*);
    double oblicz() const;
    std::string opis() const;
};


