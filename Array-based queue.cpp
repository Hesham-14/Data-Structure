//	Hesham Mohamed Mohamed
//	Created Date: 23 Aug, 2021
#include <iostream>
#include <cassert>
using namespace std;

template<class t>
class queue
{
	int front;
	int rear;
	int length;
	int count;
	t *arr;

public:
	queue(int size)
	{
		length = size;
		arr = new t[length];
		front = 0;
		rear = length - 1;
		count = 0;
	}
	bool isFull()
	{
		return count == length;
	}
	bool isEmpty()
	{
		return count == 0;
	}
	void enqueue(int element)
	{
		if (isFull())
			cout << "The Queue is Full.. We cannot add this element!!\n";
		else
		{
			rear = (rear + 1) % length;
			arr[rear] = element;
			count++;
		}
	}
	void dequeue()
	{
		if (isEmpty())
			cout << "The Queue is Empty\n";
		else
		{
			front = (front + 1) % length;
			--count;
		}
	}
	t frontQueue()
	{
		assert(!isEmpty());
		return arr[front];
	}
	t rearQueue()
	{
		assert(!isEmpty());
		return arr[rear];
	}

	void printQueue()
	{
		if (isEmpty())
			cout << "Queue is EMPTY\n";
		else
		{
			for (int i = front; i != rear; i = (i + 1) % length)
				cout << arr[i] << " ";
			cout << arr[rear];
			cout << endl;
		}
	}
};

int main()
{
	queue<int> q1(5);

	q1.printQueue();
	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);
	q1.enqueue(40);
	q1.enqueue(50);
	q1.dequeue();
	q1.dequeue();
	q1.printQueue();
	cout << q1.rearQueue() << endl;
	system("pause");
	return 0;
}