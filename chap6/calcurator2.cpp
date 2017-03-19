#include "../std_lib_facilities.h"

int main()
{
    cout << "Please enter expression (we can handle +, -, *, and /): ";
    cout << "add an x to end expression (e.g., 1+2*3;): ";

    int lval = 0;
    int rval;
    char op;
    cin >> lval;
    if (!cin) 
        error("no first operand");

    while (cin >> op) {
        cin >> rval;
        if (!cin)
            /* error("no second operand"); */
            ;
        switch(op) {
            case '+':
                lval += rval;
                break;
            case '-':
                lval -= rval;
                break;
            case '*':
                lval *= rval;
                break;
            case '/':
                lval /= rval;
                break;
            default:
                cout << "Result: " << lval << '\n';
                keep_window_open();
                return 0;
        }
    }
    error("bad expression");
}


