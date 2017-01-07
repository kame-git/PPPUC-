#include "../../std_lib_facilities.h"

int main()
{
    double b;
    double min, max;

    cin >> min;
    max = min;

    while (cin >> b) {
        if (b < min) {
            cout << "the smallest so far\n";
            min = b;
        } else if (b > max) {
            cout << "the largest so far\n";
            max = b;
        }
    }

    return 0;
}

