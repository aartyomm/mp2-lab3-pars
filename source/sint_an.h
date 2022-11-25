#pragma once
#include<iostream>
#include<queue>
#include<string>
#include"lex.h"
#include"mystack.h"

using namespace std;

class sint_an {
public:
	void check(queue<Lexema> qlexa) {
		int pos = 0, open = 0, close = 0, first_op = -1;
		string prev_t, prev_s;
		while (!qlexa.empty()) {
			string w = qlexa.front().getStr();
			if (w == "(") {
				if (first_op == -1)
					first_op = pos;
				open++;
			}
			if (w == ")")
				close++;
			if (close > open) {
				cout << pos << endl;
				throw "too_much_)";
			}
			if (prev_t == "2" && qlexa.front().getType() == Operation && w != "(" && w != ")" && prev_s != "(" && prev_s != ")") {
				cout << pos << endl;
				throw string("two_operations");
			}
			pos++;
			if (qlexa.front().getType() == Operation)
				prev_t = "2";
			else
				prev_t = "1";
			prev_s = qlexa.front().getStr();
			qlexa.pop();
		}
		if (open > close) {
			cout << first_op << endl;
			throw "too_much_(";
		}
	}
	queue<Lexema> obr(queue<Lexema> qlexa) {
		queue<Lexema> res;
		//stack<Lexema> s;
		mystack<Lexema> s;
		string prior = "-/(+*)";
		while (!qlexa.empty()) {
			if (qlexa.front().getType() == Value) {
				res.push(qlexa.front());
			}
			else {
				if (qlexa.front().getStr() == "(") {
					s.push(qlexa.front());
				}
				if (qlexa.front().getStr() == ")") {
					while (s.top().getStr() != "(") {
						res.push(s.top());
						s.pop();
					}
					s.pop();
				}
				else {
					while (!s.empty() && ((prior.find(qlexa.front().getStr()) + 1) % 3 <= (prior.find(s.top().getStr()) + 1) % 3) && (s.top().getStr() != "(")) {
						res.push(s.top());
						s.pop();
					}
					s.push(qlexa.front());
				}
			}
			qlexa.pop();
		}
		while (!s.empty()) {
			if (s.top().getStr() != "(" && s.top().getStr() != ")")
				res.push(s.top());
			s.pop();
		}
		return res;
	}
};