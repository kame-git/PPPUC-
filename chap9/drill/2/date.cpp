#include "std_lib_facilities.h"

struct Date {
    int y, m, d;
    Date(int y, int m, int d);
    void add_day(int n);
};

Date::Date(int y, int m, int d)
    : y(y), m(m), d(d)
{
}

void Date::add_day(int n)
{
    if (d + n > 31) error("Day is over.");
    d += n;
}

ostream& operator<<(ostream& os, const Date& d) 
{
    return os << '(' << d.y<< ',' << d.m
        << ',' << d.d << ')';
}

int main()
{
    Date today(1978,6,25);
    Date tommorow = today;
    tommorow.add_day(1);

    cout << tommorow << endl;

    return 0;
}

