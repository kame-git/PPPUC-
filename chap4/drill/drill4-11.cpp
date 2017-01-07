#include "../../std_lib_facilities.h"

/* TODO */
/* 数値だけの入力をエラーにすることはできない。*/

double ToMeter(double value, string unit);

int main()
{
    double value, sum = 0;
    vector<double> values;
    int count = 0;
    string unit = "";

    while (cin >> value >> unit) {
        if (unit == "cm" || unit == "in"
                || unit == "ft" || unit == "m") {

            value = ToMeter(value, unit);
            values.push_back(value);

            sum += value;
        } else {
            cout << "Ignore unit." << endl;
        }
    }

    cout << "input values: ";
    sort(values.begin(), values.end());
    for (int i = 0; i < values.size(); i++) {
        cout << values[i] ;
        if (i != values.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    cout << "min : " << values[0] << endl;
    cout << "max : " << values[values.size()-1] << endl;
    cout << "number : " << values.size() << endl;
    cout << "sum : " << sum << endl;
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

