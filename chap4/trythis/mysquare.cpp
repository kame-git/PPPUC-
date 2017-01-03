#include "../../std_lib_facilities.h"

int square(int d);

int main()
{
    int value = 0;

    cout << "Enter value : ";
    cin >> value;

    cout << "squared " << value << " is " << square(value) << ".\n";

    return 0;
}

int square(int d)
{
    int result = 0;

    for (int i = 0; i < d; i++) {
        result += d;
    }

    return result;
}

