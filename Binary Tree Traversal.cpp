#include <iostream>
#include <queue>
using namespace std;

class BinaryTree
{
	struct node
	{
		int item;
		node* left = NULL;
		node* right = NULL;
	};
	int children = 0;
public:
	void preOrder(node* p)
	{
		if (p != NULL)
		{
			cout << p->item << " ";
			preOrder(p->left);
			preOrder(p->right);
		}
	}
	void inOrder(node* p)
	{
		if (p != NULL)
		{
			inOrder(p->left);
			cout << p->item << " ";
			inOrder(p->right);
		}
	}
	void postOrder(node* p)
	{
		if (p != NULL)
		{
			postOrder(p->left);
			postOrder(p->right);
			cout << p->item << " ";
		}
	}
	void levelOrder(node* root)
	{
		if (root == NULL)
			return;
		queue<node*>Q;
		Q.push(root);
		while (!Q.empty())
		{
			node* curr = Q.front;
			cout << curr->item << " ";
			if (curr->left != NULL)
				Q.push(curr->left);
			if (curr->right != NULL)
				Q.push(curr->right);
			Q.pop();
		}
	}
};
int main()
{
  cout << "Hello World!\n";
}
