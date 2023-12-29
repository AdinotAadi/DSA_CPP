#include <bits/stdc++.h>
#define MAX 10

class Queue
{
public:
	int arr[MAX];
	int head, tail;

	Queue() { head = tail = -1; }

	bool isFull()
	{
		if (tail == MAX - 1)
			return true;
		return false;
	}

	bool isEmpty()
	{
		if (head == -1)
			return true;
		return false;
	}

	void enqueue(int val)
	{
		if (head == -1 && tail == -1)
		{
			arr[++head] = val;
			tail = head;
			return;
		}
		if (!isFull())
		{
			arr[++tail] = val;
		}
		return;
	}

	void dequeue()
	{
		if (!isEmpty())
		{
			std::cout << "Dequeued value: " << arr[head++] << std::endl;
			return;
		}
		std::cout << "The queue is empty." << std::endl;
		return;
	}

	void display()
	{
		if (isEmpty())
		{
			std::cout << "The queue is empty." << std::endl;
			return;
		}
		std::cout << "Head ->";
		for (int i = head; i <= tail; i++)
		{
			std::cout << "\t" << arr[i] << "\t";
		}
		std::cout << "<- Tail" << std::endl;
	}
};

int main()
{
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.display();
	q.dequeue();
	q.display();
	q.dequeue();
	q.display();
	q.dequeue();
	q.display();
	q.enqueue(100);
	q.display();
	return 0;
}
