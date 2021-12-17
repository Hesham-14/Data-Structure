//	Hesham Mohamed Mohamed
//	Created Date: 5 Sep, 2021
#include <iostream>

using namespace std;

class doublyLinkedList
{
	struct node
	{
		int item;
		node* next;
		node* prev;
	};
	node* head;
	node* tail;
	int count;
public:
	doublyLinkedList()
	{
		head = tail = NULL;
		count = 0;
	}

	bool isEmpty()
	{
		return count == 0;
	}

	void insertFirst(int element)
	{
		node* newNode = new node;
		newNode->item = element;
		if (isEmpty())
		{
			head = tail = newNode;
			newNode->next = newNode->prev = NULL;
		}
		else
		{
			newNode->next = head;
			newNode->prev = NULL;
			head->prev = newNode;
			head = newNode;
		}
		count++;
	}

	void insertLast(int element)
	{
		node* newNode = new node;
		newNode->item = element;
		if (isEmpty())
		{
			head = tail = newNode;
			newNode->next = newNode->prev = NULL;
		}
		else
		{
			newNode->prev = tail;
			newNode->next = NULL;
			tail->next = newNode;
			tail = newNode;
		}
		count++;
	}

	void insertAtPos(int pos, int element)
	{
		if (pos == 0)
			insertFirst(element);
		else if (pos == count)
			insertLast(element);
		else if (pos > count)
			cout << "\n\t\t*********OUT OF RANGE*************\n";
		else
		{

			node* newNode = new node;
			newNode->item = element;
			node* curr = head;
			for (int i = 1; i < pos; i++)
				curr = curr->next;
			newNode->next = curr->next;
			newNode->prev = curr;
			curr->next->prev = newNode;
			curr->next = newNode;
			count++;
		}


	}

	void deleteByPos(int pos)
	{
		if (count == 0)
			cout << "\t\t*******LIST IS EMPTY\n";
		else if (count == 1)
		{
			delete head;
			head = tail = NULL;
		}
		else if (pos == 0)
		{
			node* temp = head;
			head->next->prev = NULL;
			head = head->next;
			delete temp;
		}
		else if (pos == count-1)
		{
			node* temp = tail;
			tail->prev->next = NULL;
			tail = tail->prev;
			delete temp;
		}
		else
		{
			node* curr = head;
			for (int i = 1; i < pos; i++)
				curr = curr->next;
			node* temp = curr->next;
			curr->next->next->prev = curr;
			curr->next = curr->next->next;
			delete temp;
		}
		count--;
	}

	void printFirst()
	{
		cout << "\nThe List contains: \n\t[ ";
		node* point = head;
		while (point != NULL)
		{
			cout << point->item << " ";
			point = point->next;
		}
		cout << "]\n";
	}

	~doublyLinkedList()
	{
		node* temp;
		while (head != NULL)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
		tail = NULL;
		count = 0;
	}
};

int main()
{
	doublyLinkedList dl;
	dl.insertFirst(5);
	dl.insertFirst(4);
	dl.insertFirst(3);
	dl.insertFirst(2);
	dl.insertLast(7);
	dl.insertAtPos(4, 6);
	dl.insertAtPos(0, 1);
	dl.insertFirst(0);
	dl.deleteByPos(7);
	dl.printFirst();

	cout << "\n\t\tHello World!\n";
}
