/*
 * フィル名: token_stream.cpp
 * 標準入力からデータを読み込み、トークンに分割する。
 * 作成日：2017.4.16
 */

#include "token.h"

Token_stream::Token_stream()
    : full(false), buffer(0)
{

}

void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;
    full = true;
}

Token Token_stream::get()
{
    if (full) {
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;
    switch(ch) {
        case ';':
        case 'q':
        case '(': case ')': case '!': case '~': case '^':
        case '&': case '|':
            return Token(ch);
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            {
                cin.putback(ch);
                string s;
                cin >> s;
                return Token(NUMBER, atoi(s.c_str()));
            }
        default:
            error("Bad token");
    }
    return Token('q');  // 到達不能
}

