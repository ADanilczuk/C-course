#ifndef CLASSES_HPP_INCLUDED
#define CLASSES_HPP_INCLUDED

#include <iostream>
#include <cmath>
#include <string>
#include <exception>
#include <cstdlib>
#include <sstream>

using namespace std;

namespace obliczenia
{
    class Wyjatek_Wymierny :  public exception
    {
    protected:
        string napis;
    public:
        Wyjatek_Wymierny(string);
        Wyjatek_Wymierny();
        const string what();
    };

    class dzielenie_przez_0 : public Wyjatek_Wymierny
    {
    public:
        dzielenie_przez_0();
    };

    class przekroczony_zakres : public Wyjatek_Wymierny
    {
    public:
        przekroczony_zakres();
    };



    class Wymierne
    {
    protected:
        int Licznik, Mianownik;
    public:
        int licznik() const;
        int mianownik() const;

        Wymierne(int l, int m) throw (dzielenie_przez_0, przekroczony_zakres);
        Wymierne(const int);
        Wymierne(const Wymierne &) = default;
        Wymierne & operator=(const Wymierne &) = default;

        Wymierne operator*(const Wymierne&) const throw (przekroczony_zakres);
        Wymierne operator/(const Wymierne&) const throw (dzielenie_przez_0, przekroczony_zakres);
        Wymierne operator+(const Wymierne&) const throw (przekroczony_zakres);
        Wymierne operator-(const Wymierne&) const throw (przekroczony_zakres);

        explicit operator int() const;
        operator double() const;

        Wymierne  operator!() const throw (dzielenie_przez_0);
        Wymierne  operator-() const;
        friend ostream& operator<<(ostream&,const Wymierne&);

        bool Test(string*, int[], int) const;
        string Okresowy() const;
        string IntToString (int) const;
    };
    ostream& operator<<(ostream&,const Wymierne&);
}

#endif // CLASSES_HPP_INCLUDED
