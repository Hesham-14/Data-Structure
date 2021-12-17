//	Hesham Mohamed Mohamed
//	Created Date: 7 Sep, 2021
#include <iostream>
using namespace std;

struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* getNewNode(int element)
{
	BstNode* newNode = new BstNode();
	newNode->data = element;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BstNode* insert(BstNode* rootPtr, int element)
{
	if (rootPtr == NULL)
		rootPtr = getNewNode(element);
	else if (rootPtr->data >= element)
		rootPtr->left = insert(rootPtr->left, element);
	else
		rootPtr->right = insert(rootPtr->right, element);
	return rootPtr;
}

bool search(BstNode* rootPtr, int element)
{
	if (rootPtr == NULL)
		return false;
	else if (rootPtr->data == element)
		return true;
	else if (rootPtr->data >= element)
		return search(rootPtr->left, element);
	else if (rootPtr->data < element)
		return search(rootPtr->right, element);
}

BstNode* rsearch(BstNode* rootPtr, int element)
{
	if (rootPtr == NULL)
		return NULL;
	else if (rootPtr->data == element)
		return rootPtr;
	else if (rootPtr->data >= element)
		return rsearch(rootPtr->left, element);
	else if (rootPtr->data < element)
		return rsearch(rootPtr->right, element);
}
BstNode* remove(BstNode* rootPtr, int element)
{
	if (rootPtr == NULL)
		return rootPtr;
	else if (element <= rootPtr->data)
		rootPtr->left = remove(rootPtr->left, element);
	else if (element > rootPtr->data)
		rootPtr->right = remove(rootPtr->right, element);
	else
	{
		if (rootPtr->left == NULL && rootPtr->right == NULL)
		{
			delete rootPtr;
			rootPtr = NULL;
		}
		else if (rootPtr->left == NULL)
		{
			BstNode* temp = rootPtr;
			rootPtr = rootPtr->right;
			delete temp;
		}
		else if (rootPtr->right == NULL)
		{
			BstNode* temp = rootPtr;
			rootPtr = rootPtr->left;
			delete temp;
		}
		else
		{
			BstNode* temp;
		}
		return rootPtr;
	}

	/*

	BstNode* curr = rsearch(rootPtr, element);
	BstNode* temp;
	
	if (curr->left == NULL && curr->right == NULL)
		delete curr;
	else
		remove()

	else if (curr->right != NULL)
	{
		temp = curr;
		curr = curr->right;
		delete temp;
	}
	else if (curr->right == NULL && curr->left != NULL)
	{

	}*/

}

int main()
{
	BstNode* rootPtr = NULL;
	rootPtr = insert(rootPtr, 20);
	rootPtr = insert(rootPtr, 8);
	rootPtr = insert(rootPtr, 22);
	rootPtr = insert(rootPtr, 12);
	rootPtr = insert(rootPtr, 4);
	rootPtr = insert(rootPtr, 10);
	rootPtr = insert(rootPtr, 14);
	int number = 0;
	cout << "Please Enter The Number you Want: \t";
	cin >> number;
	if (search(rootPtr, number))
		cout << "Found\n";
	else
		cout << "Not Found\n";

}
