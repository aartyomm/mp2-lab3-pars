#pragma once

template<typename T>
class mystack {
	int t;
	size_t mems;
	T* pmem;
public:
	mystack() : t(-1), mems(1), pmem(new T[mems]) {}
	~mystack() { delete[] pmem; }
	size_t size() const { return t + 1; }
	bool empty() const { return t == -1; }
	void push(const T& val) {
		if (t == mems - 1) {
			T* tmpmem = new T[mems * 2];
			std::copy(pmem, pmem + mems, tmpmem);
			delete[] pmem;
			pmem = tmpmem;
			mems *= 2;
		}
		pmem[++t] = val;
	}
	void pop() { t--; }
	T top() { return pmem[t]; }
};

//#include<vector>
//
//using namespace std;
//
//template <typename T>
//class mystack {
//	int t;
//	vector<T> mem;
//public:
//	mystack() : t(-1) {}
//	size_t size() const { return t + 1; };
//	bool empty() const { return t == -1; };
//	void push(const T& val) {
//		mem.push_back(val);
//		t++;
//	}
//	void pop() {
//		mem.pop_back();
//		t--;
//	}
//	T top() {
//		return mem[t];
//	}
//};
