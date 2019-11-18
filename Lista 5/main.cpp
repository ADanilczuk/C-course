#include <iostream>
#include "classes.hpp"

using namespace std;

int main()
{
    Data a=Data(15,2,2018);
    cout<<a.get_day();
    cout<<" "<<a.get_month()<<" "<<a.get_year()<<endl;
    ++a;
    cout<<a.get_day();
    cout<<" "<<a.get_month()<<" "<<a.get_year()<<endl;
    a+=4;
    cout<<a.get_day();
    cout<<" "<<a.get_month()<<" "<<a.get_year()<<endl;
    a-=4;
    cout<<a.get_day();
    cout<<" "<<a.get_month()<<" "<<a.get_year()<<endl;
    Data b=Data();
    cout<<b.get_day();
    cout<<" "<<b.get_month()<<" "<<b.get_year()<<endl;
    Godzina c=Godzina(15,10,20);
    cout<<c.get_hour()<<" "<<c.get_minute()<<" "<<c.get_second()<<endl;
    cout<<c.get_day()<<" "<<c.get_month()<<" "<<c.get_year()<<endl;
    /*++c;
    cout<<c.get_hour()<<" "<<c.get_minute()<<" "<<c.get_second()<<endl;
    c+=1600;
    cout<<c.get_hour()<<" "<<c.get_minute()<<" "<<c.get_second()<<endl;
    cout<<endl;
    */
    cout<<endl;
    c+=90000;
    cout<<c.get_hour()<<" "<<c.get_minute()<<" "<<c.get_second()<<endl;
    cout<<endl;
    Godzina d=Godzina();
    cout<<d.get_hour()<<" "<<d.get_minute()<<" "<<d.get_second()<<endl;
    cout<<d.get_day()<<" "<<d.get_month()<<" "<<d.get_year()<<endl;
    Data z;
    Data x(15,10,1582);
    cout<<z-x;


    return 0;
}
