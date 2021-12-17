//	Hesham Mohamed Mohamed
//	Created Date: 21 Aug, 2021
#include <iostream>
#include <cassert>
using namespace std;

class queue
{
private:
	struct node
	{
		int item;
		node *next;
	};
	node *frontPtr;
	node *rearPtr;
	int count;
	int length;

public:
	queue(int size)
	{
		frontPtr = rearPtr = NULL;
		count = 0;
		length = size;
	}
	bool isFull()
	{
		return count == length;
	}
	bool isEmpty()
	{
		return count == 0;
	}
	void inqueue(int element)
	{
		node *newPtr = new node;
		newPtr->item = element;
		newPtr->next = NULL;
		if (isEmpty())
			frontPtr = rearPtr = newPtr;
		else
		{
			rearPtr->next = newPtr;
			rearPtr = newPtr;
		}
		count++;
	}
	void dequeue()
	{
		if (isEmpty())
			cout << "The Queue is Empty\n";
		else if (frontPtr == rearPtr)
		{
			frontPtr = rearPtr = NULL;
			count = 0;
		}
		else 
		{
			node *tempPtr = frontPtr;
			frontPtr = frontPtr->next;
			tempPtr->next = NULL;
			delete tempPtr;
			count--;
		}
	}
	int getFront()
	{
		assert(!isEmpty());
		return frontPtr->item;
	}
	int getRear()
	{
		assert(!isEmpty());
		return rearPtr->item;
	}
	void clear()
	{
		node *current;
		while (frontPtr != NULL)
		{
			current = frontPtr;
			frontPtr = frontPtr->next;
			current->next = NULL;
			delete current;
			count--;
		}
		rearPtr = NULL;
	}

	void print()
	{
		if (isEmpty())
			cout << "The Queue is EMPTY\n";
		else
		{
			node *cur = frontPtr;
			cout << "The Queue Contains...\n";
			while (cur != NULL)
			{
				cout << cur->item << " ";
				cur = cur->next;
			}
			cout << endl;
		}
	}
	int getSize()
	{
		return count;
	}
};
int main()
{
	queue q1(10);
	q1.inqueue(5);
	q1.inqueue(25);
	q1.inqueue(30);
	q1.inqueue(40);
	q1.print();
	cout << "\nBreak \n\n";
	q1.dequeue();
	q1.print();
	cout << "\nBreak \n\n";
	cout << q1.getFront() << endl;
	cout << q1.getRear() << endl;
	cout << "\nBreak \n\n";
	q1.clear();
	q1.print();

}