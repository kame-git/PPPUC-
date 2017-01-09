#include "../../std_lib_facilities.h"

int main()
{
    vector<double> values;
    double value;

    while (cin >> value)
        values.push_back(value);

    sort(values.begin(), values.end());
    
    int i = values.size();

    if (i > 1) {
        if (i % 2 == 0) {
           cout << "Median : " << (values[i/2-1] + values[i/2])/2  << endl; 
        } else {
           cout << "Median : " << values[i/2] << endl;
        }
    } else if (i == 1) {
       cout << "Median : " << values[0] << endl;
    }

    return 0;
}

