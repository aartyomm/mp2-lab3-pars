#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include "mystack.h"
#include "lex.h"
#include "lex_an.h"
#include "sint_an.h"
#include "calculate.h"

using namespace std;

int main() {
	lex_an la;
	sint_an sa;
	calculate cl;
	//string str = "( 123 -10)/ 50 *	\t	30 \n";
	//string str = "(123+10*2-1)/20";
	string str = "(123+10*+2-1)/20";
	//string str = "(10+2*3)/(3*4+5)";
	cout << str << endl;
	queue<Lexema> lexa_res;

	try {
		lexa_res = la.lexa(str);
		la.print(lexa_res);

		sa.check(lexa_res);

		lexa_res = sa.obr(lexa_res);
		la.print(lexa_res);
		cout << cl.calc(lexa_res);
	}
	catch (string s) {
		cout << s << endl;
	}
	return 0;
}

//stack, queue, pos