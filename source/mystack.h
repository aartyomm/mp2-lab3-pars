#pragma once
#include<vector>

using namespace std;

template <typename T>
class mystack {
	int t;
	vector<T> mem;
public:
	mystack() : t(-1) {}
	size_t size() const { return t + 1; };
	bool empty() const { return t == -1; };
	void push(const T& val) {
		mem.push_back(val);
		t++;
	}
	void pop() {
		mem.pop_back();
		t--;
	}
	T top() {
		return mem[t];
	}
};