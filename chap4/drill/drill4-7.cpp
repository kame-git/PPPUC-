#include "../../std_lib_facilities.h"

int main()
{
    double value;
    string unit;

    while (cin >> value >> unit) {
        cout << "value = " << value << endl;
        cout << "unit  = " << unit << endl;
    }

    return 0;
}

