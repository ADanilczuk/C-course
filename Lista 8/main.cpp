#include <iostream>
#include "classes.hpp"

using namespace std;
using namespace obliczenia;

int main()
{

    try
    {

    Wymierne a(1,3);
    cout<<"a= "<<a<<"\n";
    Wymierne b(7,4);
    cout<<"b= "<<b<<"\n";
    Wymierne d(-1,4);
    cout<<"d= "<<d<<"\n";

    Wymierne e(4,12);
    cout<<"e= "<<e<<"\n";

    cout<<endl<<"a*b= "<<a*b<<"\n";
    cout<<"a+b= "<<a+b<<"\n";
    cout<<"a-b= "<<a-b<<"\n";
    cout<<"a/b= "<<a/b<<"\n";

    cout<<endl<<"b+d= "<<d+b<<"\n";

    double dub=b;
    int in=static_cast<int>(b);
    cout<<"double "<<dub<<endl<<"int "<<in<<endl;

    int i= INT_MIN;
    Wymierne k(1,i);
    cout<<k;

    Wymierne c(2,0);
    cout<<"c="<<c;

    }
    catch (Wyjatek_Wymierny e)
    {
        cout<<e.what();
    }

    return 0;

}
