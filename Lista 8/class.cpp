#include "classes.hpp"

using namespace obliczenia;
using namespace std;

// Wyjątki

Wyjatek_Wymierny::Wyjatek_Wymierny() : napis("") {}
Wyjatek_Wymierny::Wyjatek_Wymierny(string s) : napis(s) {}

const string Wyjatek_Wymierny::what()
{
    return napis;
}

dzielenie_przez_0::dzielenie_przez_0()  : Wyjatek_Wymierny("Dzielenie przez 0") {}


przekroczony_zakres::przekroczony_zakres() : Wyjatek_Wymierny("Przekroczono zakres") {}


// Klasa Wymierne
Wymierne::Wymierne(int l, int m)
throw (dzielenie_przez_0, przekroczony_zakres)
{
    int i=2;
    if (m == 0)
        throw dzielenie_przez_0();
    if (m<0)
    {
        if (m == INT_MIN) throw przekroczony_zakres();
        m= m * (-1);
        l= l * (-1);
    }
    while (i<l || i<m)
    {
        if (l%i == 0 && m%i ==0)
        {
            l = l/i;
            m = m/i;
            i=1;
        }
        i++;
    }
    Licznik = l;
    Mianownik = m;
}

int Wymierne::licznik() const
{
    return Licznik;
}

int Wymierne::mianownik() const
{
    return Mianownik;
}

Wymierne::Wymierne(const int l) : Licznik(l), Mianownik(1) {}

Wymierne Wymierne::operator*(const Wymierne &b) const
throw (przekroczony_zakres)
{
    int l,m;

    if (INT_MAX/b.licznik() < this->Licznik)
        throw przekroczony_zakres();
    if (INT_MAX/b.mianownik() < this->Mianownik)
        throw przekroczony_zakres();

    l= this->Licznik * b.licznik();
    m= this->Mianownik * b.mianownik();
    return Wymierne(l,m);
}

Wymierne Wymierne::operator/(const Wymierne &b) const
throw (dzielenie_przez_0, przekroczony_zakres)
{
    int l,m;

    if (INT_MAX/b.licznik() < this->Mianownik)
        throw przekroczony_zakres();
    if (INT_MAX/b.mianownik() < this->Licznik)
        throw przekroczony_zakres();
    if (b.licznik() == 0)
         throw dzielenie_przez_0();

    l= this->Licznik * b.mianownik();
    m= this->Mianownik *  b.licznik();
    return Wymierne(l,m);
}

Wymierne Wymierne::operator+(const Wymierne &b) const
throw (przekroczony_zakres)
{
    int l,m;
    int la= this->Licznik;
    int lb= b.licznik();
    int ma= this->Mianownik;
    int mb= b.mianownik();
    if (ma > mb && (ma % mb)==0)
    {
        int old_mb=mb;
        mb= mb * (ma/mb);
        lb= lb * (ma/old_mb);
    }
    else
    {
        if (ma < mb && mb % ma==0)
        {
            int old_ma=ma;
            ma= ma * (mb/ma);
            la= la * (mb/old_ma);
        }
        else
        {
            if (ma!=mb)
            {
                int old_ma=ma;
                ma = ma*mb;
                la = la*mb;
                mb = mb*ma;
                lb = lb*old_ma;
            }
        }
    }

    if (INT_MAX - lb < la)
        throw przekroczony_zakres();
    l = la+lb;
    m = ma;
    return Wymierne(l,m);
}

Wymierne Wymierne::operator-(const Wymierne &b) const
throw (przekroczony_zakres)
{
    int l,m;
    int la= this->Licznik;
    int lb= b.licznik();
    int ma= this->Mianownik;
    int mb= b.mianownik();
    if (ma > mb && (ma % mb)==0)
    {
        int old_mb=mb;
        mb= mb * (ma/old_mb);
        lb= lb * (ma/old_mb);
    }
    else
    {
        if (ma < mb && mb % ma==0)
        {
            int old_ma=ma;
            ma= ma * (mb/old_ma);
            la= la * (mb/old_ma);
        }
        else
        {
            if (ma!=mb)
            {
                int old_ma=ma;
                ma = ma*mb;
                la = la*mb;
                mb = mb*ma;
                lb = lb*old_ma;
            }
        }
    }
    if (INT_MIN + lb>la)
        throw przekroczony_zakres();
    l = la-lb;
    m = ma;
    return Wymierne(l,m);
}

Wymierne  Wymierne::operator-() const
{
    int l= (-1) * this->Licznik;
    int m= this->Mianownik;
    return Wymierne(l,m);
}

Wymierne  Wymierne::operator!() const
throw (dzielenie_przez_0)
{
    int l,m;

    if (this->Licznik == 0)
        throw dzielenie_przez_0();

    if (this->Licznik < 0)
        l = this->Mianownik * (-1);
    else l = this->Mianownik;
    m = this->Licznik;
    return Wymierne(l,m);
}

Wymierne::operator int() const
{
    return (this->Licznik /  this->Mianownik);
}

Wymierne::operator double() const
{
    return (static_cast<double>(this->Licznik) /  this->Mianownik);
}

string Wymierne::IntToString(int a) const
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}

bool Wymierne::Test(string *n_ans, int reszty[], int ostatnia) const
{
    int i=0;
    if (reszty[ostatnia]== 0) return true;
    if (i==ostatnia) return false;
    while (i<ostatnia)
    {
        if (reszty[i]==reszty[ostatnia])
        {
            &n_ans->insert(i,"(");
            &n_ans->insert(ostatnia+1,")");
            &n_ans->erase(ostatnia+2);
            return true;
        }
        i++;
    } return false;
}

string Wymierne::Okresowy() const
{
    int l=this->Licznik;
    int m=this->Mianownik;
    int r=0;
    int reszty[1000];

    int temp =l/m;
    string ans ="", n_ans="";
    ans= ans + IntToString(temp) + ".";

    l= l - (temp*m);
    bool test = false;

    while (!test)
    {
        if (l>m)
        {
            temp = l/m;
            n_ans= n_ans + IntToString(temp);
            l=l-(temp*m);
        }
        l= l*10;
        reszty[r]=l;
        test= Test(&n_ans,reszty,r-1);
        r++;
    }
    return ans + n_ans;
}


ostream& obliczenia::operator<<(ostream &wyj, const Wymierne &w)
{
   string x = w.Okresowy();
    wyj << x;
    return wyj;
}
