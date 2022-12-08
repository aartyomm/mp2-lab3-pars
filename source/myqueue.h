#pragma once

template<typename T>
class queue {
	int t;
	size_t mems;
	T* pmem;
public:
	queue() : t(-1), mems(1), pmem(new T[mems]) {}
	~queue() { delete[] pmem; }
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
	void pop() {
		for (int i = 0; i < t; i++) {
			pmem[i] = pmem[i + 1];
		}
		t--;
	}
	T front() { return pmem[0]; }
};