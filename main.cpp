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
	T* Database;
	int Capacity;
	int Size;
	int Front;
	int Back;

public:
	Queue(int NewCapacity = 10)
	{
		Capacity = NewCapacity;
		Database = new T[Capacity];
		Size = 0;
		Front = 0;
		Back = 0;
	};
	
	virtual ~Queue()
	{
		delete[] Database;
	};

	bool queue(T A)
	{
		if (Size > Capacity)
		{
			return false;
		}

		Database[Back++] = A;

		Back = Back % Capacity;
		Size++;

		return true;
	}

	T deque()
	{
		if (Size < 0)
		{
			return -1;
		}
		T Target = Database[Front++];

		Front = Front % Capacity;
		Size--;

		return Target;
	}

	// accessor
	int GetSize() { return Size; }
	int GetCapacity() { return Capacity; }

};

template <typename T>
class ChildQueue : public Queue<T>
{
public:
	void Clear()
	{
		Queue::Size = 0;
	}
};

int main()
{
	Queue<int> IntQueue(10000);

	for (int i = 0; i < IntQueue.GetCapacity(); ++i)
	{
		IntQueue.queue(i);
	}

	for (int i = 0; i < IntQueue.GetCapacity(); ++i)
	{
		cout << IntQueue.deque() << endl;
	}

	return 0;
}