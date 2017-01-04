#include "../../std_lib_facilities.h"

int main()
{
    double a, b;

    while (cin >> a >> b) {
        double sub = a - b;
        if (sub < 0) {
            sub *= -1;
        }
        cout << sub << endl;
        cout << "1/10000000=" << 1.0/10000000 << endl;

        if (sub < 1.0/10000000) {
            if (a > b) {
                cout << "the larger value is : " << a << endl;
                cout << "the smaller value is : " << b << endl;
            } else {
                cout << "the larger value is : " << b << endl;
                cout << "the smaller value is : " << a << endl;
            } 

            cout << "the numbers are almost equal\n";
        }
    }

    return 0;
}

