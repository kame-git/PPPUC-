#include "../../std_lib_facilities.h"

int main()
{
    char letter = 'a';

    while (letter < 'z'+1) {
        cout << letter << "\t" << (int)letter << endl; 
        letter++;
    }

    return 0;
}

