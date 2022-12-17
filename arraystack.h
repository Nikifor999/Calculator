
#define STACK_H

template <class T>
class stack 
{
private: 
	T* data;
	int top;
	int size;
	void reSize();
	bool needToResize();
public:
	stack() {
		size = 5;
		data = new T[size];
		top = 0;
	}
	void push(T item);
	T top();
	T pop();
	bool isEmpty();
};

#include"arraystack.cpp"