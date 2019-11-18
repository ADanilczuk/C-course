#include "classes.hpp"
#include <ctime>

Godzina::Godzina(int h,int m,int s,int y, int mo,int d)
{
    hour=h;
    minute=m;
    second=s;
    year=y;
    month=mo;
    day=d;
}


Godzina::Godzina(int h,int m,int s)
{
    hour=h;
    minute=m;
    second=s;
    Data temp;
    year=temp.get_year();
    month=temp.get_month();
    day=temp.get_day();
}

int Godzina::get_hour()
{
    return this->hour;
}

int Godzina::get_minute()
{
    return this->minute;
}

int Godzina::get_second()
{
    return this->second;
}



Godzina::Godzina()
{
    time_t rawtime;
    struct tm* timeinfo;
    time( &rawtime );// chrono
    timeinfo = localtime( &rawtime );

  second=timeinfo->tm_sec;
  minute=timeinfo->tm_min;
  hour=timeinfo->tm_hour;
}

int Godzina::how_many_seconds( Godzina& g1)
{
    int s=g1.get_second()+g1.get_minute()*60+g1.get_hour();
    return s;
}

int Godzina::operator-( Godzina& g2)
{
    int s1=how_many_seconds(*this);
    int s2=how_many_seconds(g2);
    if (s1>s2) return s1-s2;
    return s2-s1;
}


void Godzina::operator--()
{
    int h=this->get_hour();
    int m=this->get_minute();
    int s=this->get_second();
    if (s==0)
    {
        s=59;
        if (m==0)
        {
            m=59;
            if (h==0)
            {
                h=23;
                Data temp=Data(this->get_day(), this->get_month(), this->get_year());
                ++temp;
                this->day=temp.get_day();
                this->month=temp.get_month();
                this->year=temp.get_year();
            }
            else h--;
        }
        else m--;
    }
    else s--;
    this->second=s;
    this->minute=m;
    this->hour=h;
}

void Godzina::operator++()
{
    int h=this->get_hour();
    int m=this->get_minute();
    int s=this->get_second();
    if (s==59)
    {
        s=0;
        if (m==59)
        {
            m=0;
            if (h==23)
            {
                h=0;
                if (test_if_leap(*this))
                {
                    if (this->get_day()==(dniwmiesiacach[1][this->get_month()]))
                    {
                       if (this->get_month()==12)
                       {
                           this->day=1;
                           this->month=1;
                           this->year=this->get_year()+1;
                       }
                       else
                       {
                           this->day=1;
                           this->month=this->get_month()+1;
                       }
                    }
                    else
                    {
                        this->day=this->get_day()+1;
                    }
                }
                else
                {
                    if (this->get_day()==(dniwmiesiacach[0][this->get_month()]))
                    {
                       if (this->get_month()==12)
                       {
                           this->day=1;
                           this->month=1;
                           this->year=this->get_year()+1;
                       }
                       else
                       {
                           this->day=1;
                           this->month=this->get_month()+1;
                       }
                    }
                    else
                    {
                        this->day=this->get_day()+1;
                    }
                }
            }
            else h++;
        }
        else m++;
    }
    else s++;
    this->second=s;
    this->minute=m;
    this->hour=h;
}

void Godzina::operator+=(int sec)
{

    int h=this->get_hour();
    int m=this->get_minute();
    int s=this->get_second();
    while (s+sec>59)
    {
        s=0;
        sec=sec-(59-s);
        if (m==59)
        {
            m=0;
            if (h==23) h=0;
            else h++;
        }
        else m++;
    }
    s=s+sec;

    this->second=s;
    this->minute=m;
    this->hour=h;
}

void Godzina::operator-=(int sec)
{
    int h=this->get_hour();
    int m=this->get_minute();
    int s=this->get_second();
    while (s-sec<0)
    {
        s=59;
        sec=sec-s;
        if (m==0)
        {
            m=59;
            if (h==0) h=23;
            else h--;
        }
        else m--;
    }
    s=s-sec;
    this->second=s;
    this->minute=m;
    this->hour=h;
}

bool Godzina::operator<(Godzina& g2 )
{
    if (this->get_hour()>g2.get_hour()) return false;
    if (this->get_hour()<g2.get_hour()) return true;
    if (this->get_minute()>g2.get_minute()) return false;
    if (this->get_minute()<g2.get_minute()) return true;
    if (this->get_second()>g2.get_second()) return false;
    if (this->get_second()<g2.get_second()) return true;
    return false;
}

bool Godzina::operator==(Godzina& g2 )
{
    if ((this->get_hour()==g2.get_hour()) &&
        (this->get_minute()==g2.get_minute()) &&
        (this->get_second()==g2.get_second())) return true;
    else return false;
}


