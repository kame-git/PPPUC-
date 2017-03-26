#include "std_lib_facilities.h"

class Name_Value
{
public: 
    Name_Value(string s) : name(s), value(0) {}
    Name_Value(string s, int v) : name(s), value(v) {}
    string name;
    int value;
};

class Data_Stream
{
public:
    Name_Value get();
};

Name_Value Data_Stream::get()
{
    string name;
    int value; 
    cin >> name >> value;

    return Name_Value(name, value);
}

void print(vector<Name_Value> s)
{
    for (size_t i = 0; i < s.size(); ++i) {
        cout << s[i].name << ' ' << s[i].value << endl;
    }
}

void check_duplication(vector<Name_Value> s, Name_Value nv)
{
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i].name == nv.name) 
            error("Name duplicated!");    
    }
}

int main()
{
    vector<Name_Value> scores;

    Data_Stream ds;

    while (cin) {
        Name_Value nv = ds.get();
        if (nv.name == "NoName" && nv.value == 0)
            break;
        if (nv.name == "print")
            print(scores);
        else { 
            check_duplication(scores, nv);
            scores.push_back(nv);
        }
    }

    return 0;
}

