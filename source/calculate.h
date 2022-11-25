#pragma once
#include<iostream>
#include<string>
#include<queue>
#include"lex.h"
#include"lex_an.h"
#include"mystack.h"

using namespace std;

class calculate {
	int sti(string s) {
		int r = 0, t = 1;
		for (int i = s.size() - 1; i >= 0; i--) {
			r += (s[i] - 48) * t;
			t *= 10;
		}
		return r;
	}
public:
	int calc(queue<Lexema> qlexa) {
		int res = 0;
		//stack<int> s;
		mystack<int> s;
		string op = "+-*/";
		while (!qlexa.empty()) {
			if (qlexa.front().getType() == Value) {
				s.push(sti(qlexa.front().getStr()));
				qlexa.pop();
			}
			if (!qlexa.empty() && qlexa.front().getType() == Operation) {
				int a = s.top();
				s.pop();
				int b = s.top();
				s.pop();
				int o = op.find(qlexa.front().getStr());
				switch (o)
				{
				case 0:
					s.push(b + a);
					cout << b << op[0] << a << endl;
					break;
				case 1:
					s.push(b - a);
					cout << b << op[1] << a << endl;
					break;
				case 2:
					s.push(b * a);
					cout << b << op[2] << a << endl;
					break;
				case 3:
					s.push(b / a);
					cout << b << op[3] << a << endl;
					break;
				}
				qlexa.pop();
			}
		}
		res = s.top();
		return res;
	}
};
