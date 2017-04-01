/*
 * 第6章　練習問題6
 * 6.4.1の「英語」の文法に基づいて、文が正しいかどうかをチェックする
 * プログラムを記述せよ。すべての文がホワイトスペースで囲まれたピリ
 * オド(.)で終了することを前提とする。たとえば、「birds fly but the 
 * fish swim . 」は文だが、「birds fly but the fish swim.」(ドットの
 * 前にスペースがない) は文ではない。プログラムでは、入力された文ご
 * とに「OK」または「not OK」のどちらかを返すこと。
 */

#include "std_lib_facilities.h"

bool noum()
{
    string s;
    cin >> s;

    // TODO: 英単語はvectorなどに保存すること!
    if (s == "birds" || s == "fish" || s == "C++")
        return true;

    return false;
}

bool verb()
{
    string s;
    cin >> s;

    // TODO: 英単語はvectorなどに保存すること!
    if (s == "rules" || s == "fly" || s == "swim")
        return true;

    return false;
}

bool conj()
{
    string s;
    cin >> s;

    // TODO: 英単語はvectorなどに保存すること!
    if (s == "and" || s == "or" || s == "but")
        return true;

    return false;
}

bool finish()
{
    return false;
}

bool scentence()
{
    while (true) {
        if (noum() && verb()) {
            char c;
            cin >> c;
            if (c == '.') {
                return true;
            }
            else {
                cin.putback(c);
            }
        }
        else
            return false;

        if (conj())
            return scentence();
        else 
            return false;
    }

    return false;
}

void check_sentence()
{
    while (cin)
    {
        char c; 
        cin >> c;
        if (c == '.')   // .の入力で終了
            return;
        cin.putback(c);

        if (scentence())
            cout << "OK" << endl;
        else {
            // TODO: 残りのデータを全て読み飛ばして、再入力可能
            // にすべき!
            string s;
            getline(cin, s);
            cout << "not OK" << endl;
        }
    }
}

int main()
{
    try
    {
        check_sentence();
        keep_window_open();
        return 0;
    }
    catch (exception& e) {
        cerr << e.what() << endl;
        keep_window_open("~~");
        return 1;
    }
    catch (...) {
        cerr << "exception \n";
        keep_window_open("~~");
        return 2;
    }
}

