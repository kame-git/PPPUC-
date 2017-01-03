#include "../../std_lib_facilities.h"

int main()
{
    const double yen_per_dollar = 120;
    const double eur_per_dollar = 1.05;
    double length = 1;
    string unit = "";
    cout << "Please enter a length followed by a unit (YEN or EUR):\n";
    cin >> length >> unit;

    if (unit == "YEN")
        cout << "\\" << length << " == $" << 
            length / yen_per_dollar << endl;
    else if (unit == "EUR")
        cout << "EUR" << length << " == $" << 
            length / eur_per_dollar << endl;
    else
        cout << "Sorry, I don't know a unit called '" << unit << "'\n";
}

        
