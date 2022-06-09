#include <iostream>
using namespace std;

struct BTreeNode
{
	int data;
	struct BTreeNode* left;
	struct BTreeNode* right;
};

BTreeNode* MakeBTreeNode(void);
void DeleteBTreeNode(BTreeNode* bt);
int GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, int data);
BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

BTreeNode* MakeBTreeNode(void)
{
	//make binary tree
	//initialize
	//return pointer
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
	// if there is a node in left link, delete it
	// put sub in left link of main
	if(main->left != nullptr) {
		DeleteBTreeNode(main->left);
	}
	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) {
	// if there is a node in right link, delete it
	// put sub in right link of main
	if(main->right != nullptr) {
		DeleteBTreeNode(main->right);
	}
	main->right = sub;
}


int main() {
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();
	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	cout << GetData(GetLeftSubTree(bt1)) << endl;
	cout << GetData(GetLeftSubTree(GetLeftSubTree(bt1))) << endl;
	DeleteBTreeNode(bt1);
	DeleteBTreeNode(bt2);
	DeleteBTreeNode(bt3);
	DeleteBTreeNode(bt4);
}