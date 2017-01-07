#include "../../std_lib_facilities.h"

/* TODO */
/* 数値だけの入力をエラーにすることはできない。*/

double ToMeter(double value, string unit);

int main()
{
    double value, max, min, sum;
    vector<double> values;
    int count = 0;
    string unit = "";

    while (cin >> value >> unit) {
        if (unit == "cm" || unit == "in"
                || unit == "ft" || unit == "m") {

            value = ToMeter(value, unit);
            values.push_back(value);

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

    cout << "input values: ";
    for (int i = 0; i < values.size(); i++) {
        cout << values[i] ;
        if (i != values.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}

double ToMeter(double value, string unit)
{
    double result = 0;

    if (unit == "cm") {
       result = value / 100;
    } else if (unit == "in") {
       result = value * 2.54 / 100;
    } else if (unit == "ft") {
       result = value * 12 * 2.54 / 100; 
    } else if (unit == "m") {
        result = value;
    }

    return result;
}

