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
protected:
	int Capacity;
	int CurrentSize;
	T* Database;

public:
	Queue(int NewCapacity = 10)
	{
		Capacity = NewCapacity;
		Database = new T[Capacity];
		CurrentSize = 0;
	};
	
	virtual ~Queue()
	{
		delete[] Database;
		Database = nullptr;
	};

	bool queue(T A)
	{
		if (CurrentSize > Capacity)
		{
			return false;
		}

		Database[CurrentSize++] = A;
	
		return true;
	}

	T deque()
	{
		if (CurrentSize < 0)
		{
			return -1;
		}
		T Target = Database[0];

		for (int i = 0; i < CurrentSize - 1; i++)
		{
			Database[i] = Database[i + 1];
		}
		CurrentSize--;

		return Target;
	}

	int GetSize() { return CurrentSize; }
};

int main()
{
	Queue<int> IntQueue;

	for (int i = 1; i <= 10; ++i)
	{
		IntQueue.queue(i);
	}

	for (int i = 1; i <= 10; ++i)
	{
		cout << IntQueue.deque() << endl;
	}

	return 0;
}