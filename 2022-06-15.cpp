#include <iostream>
#include <windows.h>
#include <stack>
#include <queue>

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

class BST {
public:
	BTreeNode* root = NULL;
	void Insert(BTreeNode* node);
	void Delete(int key);
	void Print(BTreeNode* node, int x, int y);
	void Levelorder();
private:
	void InsertRecur(BTreeNode* root, BTreeNode* node);
	void Delete(BTreeNode* parent, BTreeNode* node);
	void SetCursorPosition(int x, int y);
};

void BST::Levelorder()
{
	queue<BTreeNode*> q;
	BTreeNode* currentNode = root;
	while (currentNode)
	{
		cout << currentNode->data << endl;
		if(currentNode->left!=nullptr)
			q.push(currentNode->left);
		if (currentNode->right != nullptr)
			q.push(currentNode->right);
		if (q.empty())
			return;
		currentNode = q.front();
		q.pop();
	}
}

void BST::SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	SetConsoleCursorPosition(output, pos);
}

void BST::Print(BTreeNode* node, int x, int y)
{
	if (node == nullptr)
		return;

	SetCursorPosition(x, y);

	cout << node->data;
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);
}

void BST::Insert(BTreeNode* node) {//��� n�� ���� Ž�� Ʈ���� ������. ���� Ʈ���̸� n�� ��Ʈ�� �ϰ�, �׷��� ������ insertRecur�� ȣ���ؼ� ��带 ����
	if (root == NULL) root = node;
	else InsertRecur(root, node);
}

void BST::InsertRecur(BTreeNode* root, BTreeNode* node)
{
	if (GetData(node) == GetData(root))
		return;
	else if (GetData(node) < GetData(root)) {
		if (GetLeftSubTree(root) == NULL)
			MakeLeftSubTree(root, node);
		else
			InsertRecur(GetLeftSubTree(root), node);
	}
	else {
		if (GetRightSubTree(root) == NULL)
			MakeRightSubTree(root, node);
		else
			InsertRecur(GetRightSubTree(root), node);
	}
}

void BST::Delete(int key) {
	if (root == NULL) return;
	BTreeNode* parent = NULL; // ���� ����� �θ�
	BTreeNode* node = root; // ���ٳ��
	while (node != NULL && GetData(node) != key) {
		parent = node;
		node = (key < GetData(node)) ? GetLeftSubTree(node) : GetRightSubTree(node);
	}
	if (node == NULL) {//���� ��尡 Ʈ���� ����
		cout << "key is not in the tree" << endl;
		return;
	}
	else Delete(parent, node);
}

void BST::Delete(BTreeNode* parent, BTreeNode* node) {
	//1. �����Ϸ��� ��尡 �ܸ� ����� ���
	if (GetLeftSubTree(node) == NULL && GetRightSubTree(node) == NULL) {
		if (parent == NULL) // �����Ϸ��� ��尡 �ٳ���� ��
			root = NULL;
		else {
			if (GetLeftSubTree(parent) == node)
				MakeLeftSubTree(parent, NULL);
			else
				MakeRightSubTree(parent, NULL);
		}
	}
	//2. �����Ϸ��� ��尡 �ڽ� 1���� ���
	else if (GetLeftSubTree(node) == NULL || GetRightSubTree(node) == NULL) {
		//child�� ������ ����� ������ �ڽ�
		BTreeNode* child = (GetLeftSubTree(node) != NULL) ? GetLeftSubTree(node) : GetRightSubTree(node);
		//������ ��尡 ��Ʈ�̸� child�� ���ο� ��Ʈ�� ��
		if (node == root) root = child;
		//�ƴϸ� �θ����� �ڽ����� child�� ����
		else {
			if (GetLeftSubTree(parent) == node)
				MakeLeftSubTree(parent, child);
			else
				MakeRightSubTree(parent, child);
		}
	}
	//3. �����Ϸ��� ��尡 �ڽ� 2���� ���
	else {
		//�����Ϸ��� ����� ������ ����Ʈ������ ���� ���� ���(�İ� ���,succession)�� Ž��
		// s:�İ��� sp:�İ����� �θ���
		BTreeNode* sp = node;
		BTreeNode* s = GetRightSubTree(node);
		while (GetLeftSubTree(s) != NULL) {
			sp = s;
			s = GetLeftSubTree(s);
		}
		if (GetLeftSubTree(sp) == s)    // �İ� ����� �θ�� �İ� ����� ������ �ڽ��� ���� ����
			MakeLeftSubTree(sp, GetRightSubTree(s));
		else // �İ� ��尡 ������ ����� �ٷ� ������ �ڽ��� ���
			MakeRightSubTree(sp, GetRightSubTree(s));
		//�İ� ��� ������ ������ ��忡 ����
		SetData(node, GetData(s));
		delete s;
	}
}

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

int main() {
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();
	BTreeNode* bt5 = MakeBTreeNode();

	BST bst;
	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	bst.Insert(bt3);
	bst.Insert(bt2);
	bst.Insert(bt1);
	bst.Insert(bt4);
	bst.Insert(bt5);
	bst.Delete(2);
	bst.Print(bst.root, 10, 0);
	bst.Levelorder();
}