#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template <typename T>
class Stack
{
public:
	Stack() {};
	virtual ~Stack() {};

	T Database[10];

	int Cursor = -1;

	void Push(T A)
	{
		Cursor++;
		Database[Cursor] = A;
	}

	T Top()
	{
		return Database[Cursor--];
	}

	void Pop()
	{
		Cursor--;
	}
};

template <typename T>
class Queue
{
public:
	Queue() {};
	virtual ~Queue() {};

	T Database[10];

	int Cursor1 = -1;
	int Cursor2 = 0;

	void PushBack(T A)
	{
		Database[++Cursor1] = A;
	}

	void Pop()
	{
		Cursor2++;
	}

	T Deque()
	{
		return Database[Cursor2];
	}
};

int main()
{
	//Stack<int> IntStack;
	//IntStack.Push(10);
	//IntStack.Push(30);
	//IntStack.Push(22);
	//IntStack.Push(37);

	//cout << IntStack.Top() << endl;
	//cout << IntStack.Top() << endl;
	//cout << IntStack.Top() << endl;

	//stack<float> floatstack;
	//floatstack.push(30.732);
	//cout << floatstack.top() << endl;
	//floatstack.pop();
	//cout << floatstack.size() << endl;

	Queue<int> IntQueue;
	IntQueue.PushBack(10);
	IntQueue.PushBack(20);
	IntQueue.PushBack(30);
	IntQueue.PushBack(50);

	cout << IntQueue.Deque() << endl;
	IntQueue.Pop();
	cout << IntQueue.Deque() << endl;
	IntQueue.Pop();
	cout << IntQueue.Deque() << endl;
	IntQueue.Pop();
	cout << IntQueue.Deque() << endl;

	return 0;
}