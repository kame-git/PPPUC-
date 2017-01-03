#include "../../std_lib_facilities.h"

int main()
{
    vector<string> words;
    string word;
    /* string disliked = "Broccoli"; */
    vector<string> disliked;

    disliked.push_back("Broccoli");
    disliked.push_back("Tomato");

    while (cin >> word) {
        words.push_back(word);
    }

    /* sort(words.begin(), words.end()); */
    for (int i = 0; i < words.size(); i++) {
        int j;
        for (j = 0; j < disliked.size(); j++) {
            if (words[i] == disliked[j]) {
                cout << "BLEEP" << endl;
                break;
            }
        }
        if (j == disliked.size())
            cout << words[i] << endl;
    }

    return 0;
}

