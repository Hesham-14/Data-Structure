//	Hesham Mohamed Mohamed
//	Created Date: 27 Aug, 2021
#include <iostream>

using namespace std;

class array_list
{
	int *arr;
	int maxSize;
	int length;
public:
	array_list(int size)
	{
		if (size < 0)
			maxSize = 10;
		else
			maxSize = size;
		arr = new int[size];
		length = -1;
	}
	bool isEmpty()
	{
		return length == -1;
	}
	bool isFull()
	{
		return length == maxSize;
	}
	int getSize()
	{
		return maxSize;
	}
	void insert(int element)
	{
		if (isFull())
			cout << "The Array is FULL\n";
		else if (isEmpty() || !duplicate(element))
		{
			arr[length + 1] = element;
			length++;
		}
		else
			cout << "This element is Duplicated.. Try another one\n";
		
	}
	void insertAtPos(int pos, int element)
	{
		if (isFull())
			cout << "The Array is FULL\n";
		else if (duplicate(element))
			cout << "This element is Duplicated.. Try another one\n";
		else
		{
			if (pos < 0 || pos > maxSize)
				cout << "The Position is out of RANGE\n";
			else
			{
				for (int i = length + 1; i > pos; i--)
					arr[i] = arr[i - 1];
				arr[pos] = element;
				length++;
			}
		}
	}
	void removeAtPos(int pos)
	{
		if (isEmpty())
			cout << "The Array is EMPTY\n";
		else
		{
			for (int i = pos; i <= length; i++)
				arr[i] = arr[i + 1];
			length--;
		}
	}
	bool duplicate(int element)
	{
		for (int i = 0; i <= length; i++)
			if (arr[i] == element)
			{
				return true;
				break;
			}
			else
				return false;
	}
	void getPos(int element)
	{
		if (isEmpty())
			cout << "The Array is EMPTY\n";
		else
		{
			for (int i = 0; i <= length; i++)
				if (arr[i] == element)
				{
					cout << "The position of element: " << element << " is\t" << i << endl;
					break;
				}
		}
	}
	void getElement(int pos)
	{
		if (isEmpty())
			cout << "The Array is EMPTY\n";
		else
		{
			for (int i = 0; i <= length; i++)
				if (i == pos)
				{
					cout << "The element of position : " << pos << " is\t" << arr[i] << endl;
					break;
				}

		}
	}
	void update(int pos, int newElement)
	{
		if (isEmpty())
			cout << "The Array is EMPTY\n";
		else
		{
			for (int i = 0; i <= length; i++)
				if (i == pos)
				{
					arr[i] = newElement;
					break;
				}

		}
	}
	void print() 
	{
		if (isEmpty())
			cout << "The Array is EMPTY\n";
		else
		{
			cout << "The Array Contains [ ";
			for (int i = 0; i <= length; i++)
				cout << arr[i] << " ";
			cout << "]\n";
		}
	}

	~array_list()
	{
		delete[]arr;
	}
	void clear()
	{
		length = -1;
	}
};

int main()
{
	array_list arr(20);
	arr.insert(4);
	arr.insert(9);
	arr.insert(13);
	arr.insert(66);
	arr.print();
	arr.insertAtPos(2, 44);
	arr.print();
	arr.removeAtPos(2);
	arr.print(); 
	arr.update(2, 27);
	arr.print();
	arr.clear();
}
