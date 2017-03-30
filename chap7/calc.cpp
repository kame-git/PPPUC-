
//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
	This file is known as calculator02buggy.cpp

	I have inserted 5 errors that should cause this not to compile
	I have inserted 3 logic errors that should cause the program to give wrong results

	First try to find an remove the bugs without looking in the book.
	If that gets tedious, compare the code to that in the book (or posted source code)

	Happy hunting!

*/

#include "std_lib_facilities.h"

const char number = '8';    // t.kind==numberはtが数字のトークンであることを意味する。
const char quit = 'q';      // t.kind==quitはtが終了のトークンであることを意味する。
const char print = ';';     // t.kind==printはtが出力のトークンであることを意味する。
const string prompt = "> ";
const string result = "= "; // これに結果が続くことを示す。

const char name = 'a';      // 名前トークン
const char let = 'L';       // 宣言トークン
const string declkey = "let";   // 宣言キーワード

//------------------------------------------------------------------------------
class Variable {
public:
    string name;
    double value;
    Variable (string n, double v) : name(n), value(v) {}
};

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    string name;
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
    Token(char ch, string n) 
        : kind(ch), name(n) {}
};

//------------------------------------------------------------------------------

class Token_stream {
public: 
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c);    // cまでの(cを含む)文字を破棄する
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    } 

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case ';':    // for "print"
    case 'q':    // for "quit"
    case '(': 
    case ')': 
    case '+': 
    case '-': 
    case '*': 
    case '/': 
    case '%':
    case '=':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8' : case '9':
    {    
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token(number,val);   // let '8' represent "a number"
    }
    default:
        if (isalpha(ch)) {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
            cin.putback(ch);
            if (s == declkey) return Token(let);
            return Token(name, s);
        }
        error("Bad token");
    }
}

//------------------------------------------------------------------------------
void Token_stream::ignore(char c)
{
    if (full && c ==buffer.kind) {
        full = false;
        return;
    }
    full = false;

    char ch = 0;
    while (cin >> ch)
        if (ch == c) return;
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------
vector<Variable> var_table;

//------------------------------------------------------------------------------

double get_value(string s)
{
    for (size_t i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s) return var_table[i].value;
    error("get: undefined variable ", s);
}

//------------------------------------------------------------------------------
void set_value(string s, double d)
{
    for (size_t i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s) {
            var_table[i].value = d;
            return;
        }
    error("set: undefined variable ", s);
}

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

bool is_declared(string var)
{
    for (size_t i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == var) return true;
    return false;
}

double define_name(string var, double val)
{
    if (is_declared(var)) error(var, " declared twice");
    var_table.push_back(Variable(var, val));
    return val;
}

double declaration()
{
    Token t = ts.get();
    if (t.kind != name) error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", var_name);

    double d = expression();
    define_name(var_name, d);
    return d;
}

//------------------------------------------------------------------------------
double statement()
{
    Token t = ts.get();
    switch (t.kind) {
    case let:
        return declaration();
    default:
        ts.putback(t);
        return expression();
    }
}

//------------------------------------------------------------------------------
// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {    
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case name:
        return get_value(t.name);
    case number:     
        return t.value;  // return the number's value
    case '-':
        return - primary();
    case '+':
        return + primary();
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {    
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d; 
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = primary();
            int i1 = int(left);
            if (i1 != left)
                error("left-hand operand of % not int");
            int i2 = int(d);
            if (i2 != d)
                error("right-hand operand of % not int");
            if (i2 == 0)
                error("%: divide by zero");
            left = i1 % i2;
            t = ts.get();
            break;
        }
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------
void clean_up_mess()
{
    ts.ignore(print);
}

//------------------------------------------------------------------------------

void calculate()    // 式評価ループ
{
    while (cin) 
    try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print)
            t = ts.get();
        if (t.kind == quit)
            return;
        ts.putback(t);
        cout << result << statement() << endl;
    }
    catch (exception& e) {
        cerr << e.what() << endl;
        clean_up_mess();
    }
}

//------------------------------------------------------------------------------

int main()
{
    try
    {
        define_name("pi", 3.1415926535);
        define_name("e", 2.7182818284);

        calculate();

        keep_window_open();
        return 0;
    }
    catch (exception& e) {
        cerr << e.what() << e.what() << endl; 
            keep_window_open("~~");
        return 1;
    }
    catch (...) {
        cerr << "exception \n"; 
        keep_window_open("~~");
        return 2;
    }
}
//------------------------------------------------------------------------------
