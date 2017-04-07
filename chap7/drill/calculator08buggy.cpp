
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "std_lib_facilities.h"

/*
 * トークンを保存
 */
struct Token {
	char kind;      // トークンの種類
	double value;   // トークンの値
	string name;    // 変数名
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
        Token(char ch, string s) :kind(ch), name(s) {}
};

/*
 * トークンを取り出すストリーム
 */
class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer=t; full=true; }

	void ignore(char);
};

const char let = 'L';       // 変数
const char sq = 'S';        // 平方根
const char quit = 'Q';      // 終了
const char print = ';';     // 計算結果表示
const char number = '8';    // 数値
const char name = 'a';      // 変数名
const char pw = 'p';     // 階乗

/*
 * トークンを取得
 */
Token Token_stream::get()
{
	if (full) { full=false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
		double val;
		cin >> val;
		return Token(number,val);
	}
	default:
                // 変数の読み込み
		if (isalpha(ch)) {
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;
			cin.unget();    // 上のループを抜けるために読み込んだ1文字をストリームに返却
			if (s == "let") return Token(let);	
                        if (s == "sqrt") return Token(sq);
                        if (s == "pow") return Token(pw);
                        // find bus under line. changed "name" to "quit"
			if (s == "quit") return Token(quit);
			return Token(name,s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin>>ch)
		if (ch==c) return;
}

/*
 * 変数
 */
struct Variable {
	string name;    // 変数名
	double value;   // 値
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;	    // 変数情報

// 変数名から値を取得
double get_value(string s)
{
	for (size_t i = 0; i<names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ",s);
}

// 変数を設定
void set_value(string s, double d)
{
	for (size_t i = 0; i<=names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ",s);
}

// 変数名の宣言確認
bool is_declared(string s)
{
	for (size_t i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

// 変数をテーブルに追加
double define_name(string var, double val)
{
    if (is_declared(var)) error(var, " declared twice");
    names.push_back(Variable(var, val));
    return val;
}

Token_stream ts;

double expression();
double square_root();
double power();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
		t = ts.get();
		if (t.kind != ')') error("'(' expected");
                return d;
	}
        // 論理バグ発見! +数字に対応する。
        case '+':
                return + primary();
	case '-':
		return - primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
        case sq:
                return square_root();
        case pw:
                return power();
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
        Token t = ts.get();

	while(true) {
		switch(t.kind) {
		case '*':
			left *= primary();
                        t = ts.get();
			break;
		case '/':
		{	double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
                        t = ts.get();
			break;
		}
                // 論理バグ発見! %記号に対応する。
                case '%':
                {
                    double d = primary();
                    int i1 = int(left);
                    if (i1 != left) error("left-hand operand of % not int");
                    int i2 = int(d);
                    if (i2 != d) error("right-hand operand of % not int");
                    if (i2 == 0) error("%d: divide bye zero");
                    left = i1 % i2;
                    t = ts.get();
                    break;
                }
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error ("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,name);
	double d = expression();
	names.push_back(Variable(name,d));
	return d;
}

/*
 * 平方根を計算
 */

double square_root()
{
    Token t = ts.get();
    if (t.kind != '(') error ("'(' expected");
    double d = expression();
    if (d < 0) error ("negative number isn't use sqrt.");
    d = sqrt(d);
    t = ts.get();
    if (t.kind != ')') error ("')' expected");
    return d;
}

/*
 * 階乗計算
 */
double power()
{
    Token t = ts.get();
    if (t.kind != '(') error ("'(' expected");
    double d;
    double r;
    char c;
    if (cin >> d >> c >> r) {
        int i = int(r);
        if (i != r || i < 0) error ("arg 1 of sqrt error");
        d = pow(d, r);
    }
    else {
        error ("arguments of sqrt error");
    }
    t = ts.get();
    if (t.kind != ')') error ("')' expected");
    return d;
}

double statement()
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while(true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

	try {
            define_name("pi", 3.1415926535);
            define_name("e", 2.7182818284);
            define_name("k", 1000);

            calculate();
            return 0;
	}
	catch (exception& e) {
            cerr << "exception: " << e.what() << endl;
            char c;
            while (cin >>c&& c!=';') ;
            return 1;
	}
	catch (...) {
            cerr << "exception\n";
            char c;
            while (cin>>c && c!=';');
            return 2;
	}
