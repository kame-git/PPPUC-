#ifndef _TOKEN_H_
#define _TOKEN_H_

#include "std_lib_facilities.h"
#include <cstdlib>

const char NUMBER = '9';

class Token {
public:
    char kind;
    double value;
    Token(char ch) : kind(ch), value(0) {}
    Token(char ch, double val) : kind(ch), value(val) {}
};

class Token_stream {
public:
    Token_stream();     // cinを読み取るToken_streamを作成
    Token get();        // Tokenを取得
    void putback(Token t); // Tokenを戻す
private:
    bool full;          // Tokenバッファの状況
    Token buffer;       // 1つのTokenを保存
};

#endif

