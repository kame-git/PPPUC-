#include "../../std_lib_facilities.h"

/* TODO */
/* 数値だけの入力をエラーにすることはできない。*/

int main()
{
    double value, max, min, sum;
    int count = 0;
    string unit = "";

    while (cin >> value >> unit) {
        if (unit == "cm" || unit == "in"
                || unit == "ft" || unit == "m") {
            if (count == 0) {
                min = max = value;
            } else {
                min = value < min ? value : min;
                max = value > max ? value : max;
            }
            count++;
            sum += value;
            /* cout << "value = " << value << endl; */
            /* cout << "unit  = " << unit << endl; */
        } else {
            cout << "Ignore unit." << endl;
        }
    }

    cout << "min : " << min << endl;
    cout << "max : " << max << endl;
    cout << "number : " << count << endl;
    cout << "sum : " << sum << endl;

    return 0;
}

