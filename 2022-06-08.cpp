#include <iostream>
#include <stack>

using namespace std;

struct BTreeNode
{
	int data;
	struct BTreeNode* left;
	struct BTreeNode* right;
};

void PreorderTraverse(BTreeNode* bt);

void InorderTraverse(BTreeNode* bt);

void PostorderTraverse(BTreeNode* bt);

BTreeNode* MakeBTreeNode(void);
void DeleteBTreeNode(BTreeNode* bt);
int GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, int data);
BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);
BTreeNode* MakeExpTree(string exp);

int EvaluateExpTree(BTreeNode* bt);

int prec(char op);
string infixToPostfix(string infix);

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* bt = (BTreeNode*)malloc(sizeof(BTreeNode));
	bt->left = nullptr;
	bt->right = nullptr;
	return bt;
}

void DeleteBTreeNode(BTreeNode* bt) {
	free(bt);
}

int GetData(BTreeNode* bt) {
	return bt->data;
}

void SetData(BTreeNode* bt, int data) {
	bt->data = data;
}
BTreeNode* GetLeftSubTree(BTreeNode* bt) {
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt) {
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->left != nullptr) {
		DeleteBTreeNode(main->left);
	}
	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->right != nullptr) {
		DeleteBTreeNode(main->right);
	}
	main->right = sub;
}

void PreorderTraverse(BTreeNode* bt)
{
	if (bt != nullptr) {
		cout << bt->data << " ";
		PreorderTraverse(bt->left);
		PreorderTraverse(bt->right);
	}
}
void InorderTraverse(BTreeNode* bt)
{
	if (bt != nullptr) {
		InorderTraverse(bt->left);
		cout << bt->data << " ";
		InorderTraverse(bt->right);
	}
}

void PostorderTraverse(BTreeNode* bt)
{
	if (bt != nullptr) {
		PostorderTraverse(bt->left);
		PostorderTraverse(bt->right);
		cout << bt->data << " ";
	}
}

BTreeNode* MakeExpTree(string exp)
{
	stack<BTreeNode*> stack;
	BTreeNode* pnode{};
	for (int i = 0; i < exp.length(); ++i)
	{
		pnode = MakeBTreeNode();
		if ((exp[i] - '0') >= 0 && (exp[i] - '0') <= 9)
		{
			SetData(pnode, exp[i] - '0');
		}
		else
		{
			SetData(pnode, exp[i]);
			MakeRightSubTree(pnode, stack.top());
			stack.pop();
			MakeLeftSubTree(pnode, stack.top());
			stack.pop();
		}
		stack.push(pnode);
	}
	return pnode;
}

int EvaluateExpTree(BTreeNode* bt)
{
	if (bt == nullptr)
	{
		return 0;
	}
	if (GetData(bt) - '0' >= 0 && GetData(bt) - '0' <= 9)
	{
		return GetData(bt) - '0';
	}
	else
	{
		int left = EvaluateExpTree(GetLeftSubTree(bt));
		int right = EvaluateExpTree(GetRightSubTree(bt));
		switch (GetData(bt))
		{
		case '+':
			return left + right;
		case '-':
			return left - right;
		case '*':
			return left * right;
		case '/':
			return left / right;
		}
	}
}

int prec(char op) {
	switch (op) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	}
}

string infixToPostfix(string infix) {
	string postfix;
	stack<char> stack;
	for (int i = 0; i < infix.length(); ++i)
	{
		if ((infix[i] - '0') >= 0 && (infix[i] - '0') <= 9)
		{
			postfix += infix[i];
		}
		else
		{
			if (stack.empty() || prec(infix[i]) > prec(stack.top()))
			{
				stack.push(infix[i]);
			}
			else
			{
				while (!stack.empty() && prec(infix[i]) <= prec(stack.top()))
				{
					postfix += stack.top();
					stack.pop();
				}
				stack.push(infix[i]);
			}
		}
	}
	while (!stack.empty())
	{
		postfix += stack.top();
		stack.pop();
	}
	return postfix;
}

namespace Traverse {
	int main()
	{
		BTreeNode* bt1 = MakeBTreeNode();
		BTreeNode* bt2 = MakeBTreeNode();
		BTreeNode* bt3 = MakeBTreeNode();
		BTreeNode* bt4 = MakeBTreeNode();
		BTreeNode* bt5 = MakeBTreeNode();
		BTreeNode* bt6 = MakeBTreeNode();
		SetData(bt1, 1);
		SetData(bt2, 2);
		SetData(bt3, 3);
		SetData(bt4, 4);
		SetData(bt5, 5);
		SetData(bt6, 6);
		MakeLeftSubTree(bt1, bt2);
		MakeRightSubTree(bt1, bt3);
		MakeLeftSubTree(bt2, bt4);
		MakeRightSubTree(bt2, bt5);
		MakeRightSubTree(bt3, bt6);

		PreorderTraverse(bt1);
		cout << endl;
		InorderTraverse(bt1);
		cout << endl;
		PostorderTraverse(bt1);
		cout << endl;
		return 0;
	}
}

int main()
{
	string infix;
	cout << "중위표기수식 : ";
	cin >> infix;
	BTreeNode* eTree = MakeExpTree(infixToPostfix(infix));
	double res = EvaluateExpTree(eTree);
	cout << res;
	return 0;
}