//	Hesham Mohamed Mohamed
//	Created Date: 28 Aug, 2021
#include <iostream>

using namespace std;

class linkedList
{
	struct node
	{
		int item;
		node* next;
	};
	node* head;
	node* tail;
	int length;
public:
	linkedList()
	{
		head = tail = NULL;
		length = 0;
	}
	bool isEmpty()
	{
		return length == 0;
	}
	void insertFirst(int element)
	{
		node* newNode = new node;
		newNode->item = element;
		if (isEmpty())
		{
			head = tail = newNode;
			newNode->next = NULL;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
		length++;
	}
	void insertLast(int element)
	{
		node* newNode = new node;
		newNode->item = element;
		if (isEmpty())
		{
			head = tail = newNode;
			newNode->next = NULL;
		}
		else
		{
			tail->next = newNode;
			newNode->next = NULL;
			tail = newNode;
		}
		length++;
	}
	void insertAtPos(int pos, int element) 
	{
		node* newNode = new node;
		newNode->item = element;
		if (pos == 0)
			insertFirst(element);
		else if (pos == length)
			insertLast(element);
		else
		{
			node* cur = head;
			for (int i = 1; i < pos; i++)
				cur = cur->next;
			newNode->next = cur->next;
			cur->next = newNode;
			length++;
		}
	}
	void deleteAtFirst()
	{
		if (length == 0)
			return;
		else if (length == 1)
		{
			head = tail = NULL;
			delete head;
			length--;
		}
		else
		{
			node* temp = head;
			head = head->next;
			delete temp;
			length--;
		}
	}
	void deleteAtLast()
	{
		if (length == 0)
			return;
		else if (length == 1)
		{
			head = tail = NULL;
			delete head;
			length--;
		}
		else
		{
										// first try
			/*
			node* cur = head;
			node* temp = tail;
			for (int i = 0; i < length-2 ; i++)
				cur = cur->next;
			tail = cur;
			tail->next = NULL;
			delete temp;
			temp = NULL;
			length--;*/
										//Second try
			node* cur = head->next;
			node* prev = head;
			while (cur != tail)
			{
				prev = cur;
				cur = cur->next;
			}
			delete cur;
			tail = prev;
			tail->next = NULL;
			length--;
		}
	}
	void deleteElement(int element)
	{
		if (head->item == element)
			deleteAtFirst();
		else if (tail->item == element)
			deleteAtLast();
		else
		{
			node* cur = head->next;
			node* prev = head;
			while (cur != NULL && cur->item != element)
			{
				prev = cur;
				cur = cur->next;
			}
			if (cur == NULL)
				cout << "This Element is not found\n";
			else
			{
				prev->next = cur->next;
				if (cur == tail)
					tail = prev;
				delete cur;
				length--;
			}
		}

	}
	void deleteAtPos(int pos)
	{
		if (pos == 0)
			deleteAtFirst();
		else if (pos == length)
			deleteAtLast();
		else
		{
			node* cur = head->next;
			node* prev = head;
			
			for (int i = 1; i < pos; i++)
			{
				prev = cur;
				cur = cur->next;
			}
			if (cur == NULL)
				cout << "This Element is not found\n";
			else
			{
				prev->next = cur->next;
				if (cur == tail)
					tail = prev;
				delete cur;
				length--;
			}
		}
	}
	void reverse()
	{
		node* cur = head;
		node* prev = NULL;
		node* next = cur->next;
		while (cur != NULL || next != NULL)
		{
			next = cur->next;

			cur->next = prev;
			prev = cur;
			cur = next;
		}
		head = prev;
	}
	int search(int element)
	{
		node* temp = head;
		int pos = 0;
		while (temp != NULL)
		{
			if (temp->item == element)
				return pos;
			temp = temp->next;
			pos++;
		}
		return -1;
	}
	void print()
	{
		node* cur = head;
		cout << "The List Contains [   ";
		while (cur != NULL)
		{
			cout << cur->item << "  ";
			cur = cur->next;
		}
		cout << " ]\n";
		cout << length << endl;
	}
	
};

int main()
{
	linkedList li;
	li.insertFirst(10);
	li.insertFirst(5);
	li.insertLast(15);
	li.insertLast(20);
	li.insertAtPos(2, 12);
	li.insertFirst(0);
	li.insertLast(100);
	li.deleteAtLast();
	li.deleteAtFirst();	
	li.deleteElement(12);
	li.insertLast(30);
	li.deleteAtPos(2);
	li.reverse();
	li.print();
	cout << "==== " << li.search(10);
}
