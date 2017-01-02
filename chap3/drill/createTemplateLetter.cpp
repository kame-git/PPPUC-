#include "../../std_lib_facilities.h"

int main()
{
    string first_name;
    string friend_name;
    char friend_gender = 0;
    int age;

    cout << "Enter the name of the person you want to write to ";
    cin >> first_name;

    cout << "Enter your friend name: ";
    cin >> friend_name;

    cout << "sex (m or f) : ";
    cin >> friend_gender;

    cout << "Enter age of the recipient: ";
    cin >> age;

    if (age <= 0 || age >= 110) {
        simple_error("you're kidding!");
    }

    cout << "Dear, " << first_name << endl;
    cout << "How are you? I am fine. I miss you." << endl;
    cout << "Have you seen " << friend_name << " lately?" << endl;
    
    if (friend_gender == 'm') {
        cout << "If you see " << friend_name << " please ask him to call me" << endl;
    } else if (friend_gender == 'f') {
        cout << "If you see " << friend_name << " please ask her to call me" << endl;
    }

    cout << "I hear you just had a birthday and you are " << age << " years old." << endl;

    if (age < 12) {
        cout << "Next year you will be " << age+1 << endl;
    } else if (age == 17) {
        cout << " Next year you will be able to vote" << endl;
    } else if (age >= 70) {
        cout << "I hope you are enjoing retirement" << endl;
    }

    return 0;
}

