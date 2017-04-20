#include "std_lib_facilities.h"

class Date {
    int y, m, d;
public:
    class Invalid {};
    Date(int y, int m, int d);
    void add_day(int n);
    int month() { return m; }
    int day() { return d; }
    int year() { return y; }
private:
    bool check();
};

Date::Date(int yy, int mm, int dd)
    :y(yy), m(mm), d(dd)
{
    if (!check()) throw Invalid();
}

bool Date::check()
{
    if (m < 1 || 12 < m) return false;
    if (d < 1 || 31 < d) return  false;
    if (y < 1970 || 2050 < y) return false;

    return true;
}

void Date::add_day(int n)
{
    d += n;
    if (!check()) 
        error("add_day() is error.");
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year() << ',' << d.month() << ','
        << d.day() << ')';
}

void f(int x, int y)
try {
    Date dxy(2004, x, y);
    cout << dxy << '\n';
    dxy.add_day(2);
}
catch (Date::Invalid) {
    error ("invalid date");
}


int main()
{
    Date today(1978, 6, 25);
    Date tomorrow =today;
    tomorrow.add_day(1);
    cout << "today is " << today << endl;
    cout << "tomorrow is " << tomorrow << endl;
    return 0;
}

