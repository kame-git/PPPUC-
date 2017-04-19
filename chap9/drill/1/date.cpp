#include "std_lib_facilities.h"

struct Date {
    int y;
    int m;
    int d;
};

void init_day(Date& dd, int y, int m, int d)
{
    // y,m,dが有効な日付か確認する
    if (y < 1970 || y > 2050) error("Year is over.");
    if (m < 1 || m > 12) error("Month is over.");
    if (d < 1 || d > 31) error("Day is over.");
    // そうである場合は、ddを初期化する
    dd.y = y;
    dd.m = m;
    dd.d = d;
}

void add_day(Date& dd, int n)
{
    // ddをn日増やす
    dd.d += n;
    if (dd.d > 31) error("Day is over.");
}

int main()
{
    Date today;
    init_day(today, 1978, 6, 25);
    Date tommorow = today;
    add_day(tommorow, 1);

    cout << tommorow.y << '/' << tommorow.m << '/' << tommorow.d << '.'
        << endl;

    return 0;
}


