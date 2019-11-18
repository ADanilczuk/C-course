#include <cstdlib>
#include <iomanip>
#include <string>
#include <iostream>

inline std::istream& clearline( std::istream& os)
{
    char a;
    a= os.get();
    while (a != '\n' && os)
    {
        a= os.get();
    }
    return os;
}

class ignore
{
    int x;
    friend std::istream& operator >> (std::istream &os, const ignore &in)
    {
        int i=0;
        char a= ' ';
        while ((i <= in.x && os) || a == '\n')
        {
            a= os.get();
            i++;
        }
        return os;
    }

public:
    ignore(int iks): x(iks) {}
};

inline std::ostream& comma (std::ostream &os)
{
    return os << ", ";
}

inline std::ostream& colon (std::ostream &os)
{
    return os << ": ";
}

class index
{
    int x;
    int w;
    friend std::ostream& operator << (std::ostream &os, const index &in)
    {
        int o, x_f;
        x_f = in.x;
        for (o=1; x_f>9; o++)
        {
            x_f = x_f/10;
        }
        int i = in.w - o;
        os << "[";
        while (i>0)
        {
            os << " ";
            i--;
        }

        os << in.x << "]";
        return os;
    }

public:
    index(int x2, int w2): x(x2), w(w2) {}
};




