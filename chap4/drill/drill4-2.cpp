#include "../../std_lib_facilities.h"

int main()
{
    int a, b;

    while (cin >> a >> b) {
        if (a > b) {
            cout << "the smaller value is : " << b << endl;
            cout << "the larger value is : " << a << endl;
        } else {
            cout << "the smaller value is : " << a << endl;
            cout << "the larger value is : " << b << endl;
        }
    }

    return 0;
}

