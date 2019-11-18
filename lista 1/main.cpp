#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;


bool pierwszosc(int64_t n)
{
    if (n==0 || n==1) return false;
    if (n==2) return true;
    if (n%2==0) return false;
    int64_t a=3;
    while (a<=static_cast<int>(sqrt(n)))
    {
        if (n%a==0) return false;
        a=a+2;
    }
    return true;
}

int64_t charnaint (string liczba)
{
    int64_t i=0, l=0;
   int64_t czy_ujemna=false;
    if (liczba[0]=='-')
    {
        czy_ujemna=true;
        i++;
    }

    for(;i<liczba.length();i++)
    {
        if (liczba[i]>='0'&&liczba[i]<='9')
                l=l*10+liczba[i]-'0';
        else
            throw invalid_argument("To nie jest liczba");
    }
    if (czy_ujemna) l*=(-1);
    return l;
}

void wypisz(int64_t a)
{
    cout<<a<<"*";
}

vector<int64_t> rozklad(int64_t n)
{
    vector<int64_t> po_roz;
    int64_t a=2,pierw;
    if (n==1||n==-1||n==0)
    {
        po_roz.push_back(n);
        return po_roz;
    }
    if (n==-9223372036854775808LL)
    {
        po_roz.push_back(-1);
        for (a=0;a<63;a++)
            po_roz.push_back(2);
        return po_roz;
    }
    if (n<-1)
    {
        po_roz.push_back(-1);
        n*=-1;
    }
    if (pierwszosc(n))
    {
        po_roz.push_back(n);
        return po_roz;
    }
    while (n>1)
    {
        if(n%a==0)
        {
            po_roz.push_back(a);
            n/=a;
            if (pierwszosc(n))
            {
                po_roz.push_back(n);
                return po_roz;
            }
        }
        else a++;
    }
    return po_roz;
}


int main(int ilosc, char* ag[])
{
    if(ilosc<2)
    {
        cout<<"Wpisz liczbe jako parametr programu"<<endl;
        return 1;
    }

    vector<int64_t> liczba;
    for(int i=1;i<ilosc;i++)
    {
        try
        {   liczba.push_back(charnaint(ag[i])); }
        catch (invalid_argument& blad)
        {   cerr<<"Blad: "<<blad.what()<<endl;  }
    }
    vector<int64_t> proz;
    for(int64_t i:liczba)
    {
        cout<<i<<"= ";
        proz = rozklad(i);
        for_each(proz.begin(),proz.end()-1,wypisz);
        cout<<proz.back()<<endl;
    }
    return 0;

}


