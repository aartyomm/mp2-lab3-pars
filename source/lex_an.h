#pragma once
#include<iostream>
#include<string>
#include <queue>
//#include "myqueue.h"
#include"lex.h"

using namespace std;

class lex_an {
public:
	queue<Lexema> lexa(string input) {
		queue<Lexema> res;
		input += ' ';
		int i = 0;
		string tmp = "";
		string op = "+-*/()";
		string sep = " \n\t";
		int state = 0;
		for (i = 0; i < input.size(); i++) {
			char c = input[i];
			int fres;
			switch (state) {
			case 0: // ��������
				if (c >= '0' && c <= '9') {
					tmp = c;
					state = 1;
					break;
				}
				fres = op.find(c);
				if (fres >= 0) {
					tmp = c;
					Lexema l(tmp, Operation);
					res.push(l);
					state = 0;
					break;
				}
				break;
			case 1: // �����
				if (c >= '0' && c <= '9') {
					tmp += c;
					state = 1;
					break;
				}
				fres = op.find(c);
				if (fres >= 0) {
					Lexema l1(tmp, Value);
					res.push(l1);
					tmp = c;
					Lexema l2(tmp, Operation);
					res.push(l2);
					state = 0;
					break;
				}
				fres = sep.find(c);
				if (fres >= 0) {
					Lexema l(tmp, Value);
					res.push(l);
					state = 0;
					break;
				}
				break;
			}
		}
		return res;
	}

	void print(queue<Lexema> t) {
		while (!t.empty()) {
			cout << t.front() << endl;
			t.pop();
		}
	}
};