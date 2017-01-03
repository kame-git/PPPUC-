#include "../../std_lib_facilities.h"

int main()
{
    for (char letter = 'a'; letter < 'z'+1; letter++) {
        cout << letter << "\t" << (int)letter << endl; 
    }

    for (char letter = 'A'; letter < 'Z'+1; letter++) {
        cout << letter << "\t" << (int)letter << endl; 
    }

    for (char letter = '0'; letter < '9'+1; letter++) {
        cout << letter << "\t" << (int)letter << endl; 
    }

    return 0;
}

