#include "../../std_lib_facilities.h"

int main()
{

    int val1, val2;

    cout << "Enter two value: ";
    cin >> val1 >> val2;
    
    int max = val1;
    if (max < val2)
        max = val2;
    cout << "MAX is " << max << "." << endl;

    int min = val1;
    if (min > val2)
        min = val2;
    cout << "MIN is " << min << "." << endl;

    cout << "SUM is " << val1 + val2 << endl;

    cout << "Sub is " << val1 - val2 << endl;

    cout << "Mul is " << val1 * val2 << endl;

    cout << "Ratio is " << val1 / val2 << endl;

    return 0;
}

