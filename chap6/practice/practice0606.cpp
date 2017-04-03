/*
 * 第6章　練習問題6
 * 6.4.1の「英語」の文法に基づいて、文が正しいかどうかをチェックする
 * プログラムを記述せよ。すべての文がホワイトスペースで囲まれたピリ
 * オド(.)で終了することを前提とする。たとえば、「birds fly but the 
 * fish swim . 」は文だが、「birds fly but the fish swim.」(ドットの
 * 前にスペースがない) は文ではない。プログラムでは、入力された文ご
 * とに「OK」または「not OK」のどちらかを返すこと。
 */

/*
 * テキストでは最後にピリオド(.)がない場合も「not OK」を表示するこ
 * とになっているが、cin >> を使用する場合は改行文字の判別ができな
 * いため難しいかも？
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

// 読込んだ文字列をcinに戻す
void putback_string(string& s)
{
    for (size_t i = s.size(); i > 0; --i) {
        cin.putback(s[i-1]);
    }
}

// 冠詞
bool art()
{
    string s;
    cin >> s;

    // TODO: 英単語はvectorなどに保存すること!
    if (s == "the")
        return true;
    else
        putback_string(s);

    return false;
}

// 名詞句
bool pro()
{
    if (art()) {
        if (noum())
            return true;
        else
            return false;
    }

    if (noum())
        return true;
    else 
        return false;

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

bool sentence()
{
    while (true) {
        /* if (noum() && verb()) { */
        if (pro() && verb()) {
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
            return sentence();
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

        if (sentence())
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
    /* cout << "Enter string: "; */
    /* string s; */
    /* cin >> s; */
    /* cout << "Input string : " << s << endl; */
    /* putback_string(s); */
    /* cin >> s; */
    /* cout << "After putback :" << s << endl; */

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

