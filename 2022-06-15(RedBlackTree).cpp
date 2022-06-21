/*
* C++ �̿��Ͽ� Red Black Tree �����ϱ�
*
* ���� : Red Black Tree ���� �ϱ� ���� �ۼ�������,
*       C++ �̿��Ͽ� �ۼ��Ͻô� �е鿡�� ������ �ǰ��� �ߴ�.
*
* ���� : key ���� int�� ���� �ϸ� �ߺ� key�� ��� x
*       ���� ���� ����Ʈ�� ����
*       Red / Black�� �ĺ��ϱ� ���� enum�̿� ������, bool �̿�� ������ ũ�� ����
*
*       class RBTree
*
*       ���� :   root node => root���� �׻� black
*               leaf node => ���� �ش��ϴ� ������ leaf node���� ������ �ִ�.
*                            leaf node��� �͸� �˸� �Ǳ� ������ ���ο� ��� ���� ������ leaf node�� ���� ���� �ʿ����
*                            ��� ���� ������ �� leaf node�� ����Ű�� ������ ����
*                            leaf node�� �׻� black
*
*       ������ : RBTREE =>  node ����ü ������
*                          ���� black �ʱ�ȭ
*                          ��� �ڽ��� nullptr�� �ʱ�ȭ.
*
*       �Լ� :   IsKey => key���� �ִ��� �˻��ϴ� �Լ�
*               Insert => ���� �Լ�
*               InsertFixUp => ���� �� ��Ģ ������ �� ������ �Լ�
*               Delete => ���� �Լ�
*               DeleteFixUp => ���� �� ��Ģ ������ �� ������ �Լ�
*               Transplant => ���� �� �̿��ϸ�, ������ ����� �ڽ� ��带 �θ��忡 �������ִ� �Լ�
*               RotateRight(x) => x���� ���������� ȸ��
*               RotateLeft(x) => x���� �������� ȸ��
*
*               Inorder,Preorder,Postorder => ��ȸ �Լ�
*               tree_minimum(x), tree_maximum(x) => ��� x �������� ���� ����, ������ return �Լ�
*
*               DisplayMenu, SelectMenu => �ʱ� Menu�� print �Լ�
*               Insert_helper,Delete_helper,order_helper,print_helper => ���� ����� �Է¹ް� ���� ���� ó�� ���� �Լ� �� tree print ���ִ� �Լ�
*
*       InsertFixUp�� DeleteFixUp���� �� case�� ���� ������ github�� ���� ���Ҵ�.
*
* �ۼ��� : gowoonsori
* github : https://github.com/gowoonsori/my-tech/tree/master/dataStructure/Tree
* �ش� source gist : https://gist.github.com/gowoonsori/a725e29ef1880f0592fe5760f4908c6b
*/

/*
*   �������� : 
*   Ű ���� string���� �ܾ �޴´�
*   �Է½� Word�� Mean�� �Է¹���
*/

#include <iostream>
#include <vector>
using namespace std;

enum Color
{
    RED,
    BLACK
};

class Key
{
public:
    Key() : word(""), mean("")
    {
        order.resize(0);
    }

    void SetWord(string word)
    {
        this->word = word;
        OrderSetting();
    }

    void SetMean(string mean)
    {
        this->mean = mean;
    }

    string GetWord()
    {
        return this->word;
    }

    string GetMean()
    {
        return this->mean;
    }

    bool IsFrontThan(Key comparisonTarget)
    {
        bool returnVal = this->order.size() < comparisonTarget.order.size();
        int length = returnVal ? this->order.size() : comparisonTarget.order.size();
        for (int i = 0; i < length; ++i)
        {
            if (this->order.at(i) < comparisonTarget.order.at(i))
            {
                return true;
            }
            else if (this->order.at(i) > comparisonTarget.order.at(i))
            {

                return false;
            }
        }
        return returnVal;
    }

    bool IsFrontThan(string comparisonString)
    {
        bool returnVal = this->order.size() < comparisonString.length();
        int length = returnVal ? this->order.size() : comparisonString.length();
        for (int i = 0; i < length; ++i)
        {
            if (this->order.at(i) < comparisonString[i])
            {
                return true;
            }
            else if (this->order.at(i) > comparisonString[i])
            {

                return false;
            }
        }
        return returnVal;
    }

private:
    string word;
    string mean;
    vector<int> order;

    void OrderSetting()
    {
        if (word == "")
        {
            exit(-1);
            return;
        }

        for (int i = 0; i < word.length(); ++i)
        {
            order.push_back(word[i]);
        }
    }
};

struct node
{
    Key key;
    node* left = nullptr;
    node* right = nullptr;
    node* parent = nullptr;
    Color color = BLACK;
};

typedef node* NodePtr;

class RBTREE
{
private:
    NodePtr root;     //��Ʈ ���
    NodePtr leafNode; //�ܸ����

    //key���� �ִ��� ������ �˻� ������ pointer ��, ������ nullptr
    NodePtr IsKey(string item)
    {
        NodePtr t = root;
        NodePtr parent = NULL;

        /*key���� ã�ų� ���ٸ� break*/
        while (t != NULL && t->key.GetWord() != item)
        {
            parent = t;
            t = !(parent->key.IsFrontThan(item)) ? parent->left : parent->right;
        }
        return t;
    }

    void Insert(string item, string itemMean)
    {
        // x : ������ �� ã������ ������ | y : ������ ���� �θ���
        NodePtr x = this->root, y = nullptr;
        NodePtr z = new node();
        z->key.SetWord(item);
        z->key.SetMean(itemMean);
        z->color = RED;
        z->parent = nullptr;
        z->left = leafNode;
        z->right = leafNode;

        /*BST�� �Ϲ� ���� ����*/
        while (x != leafNode)
        {
            y = x;
            if (x->key.IsFrontThan(item))
                x = x->right;
            else
                x = x->left;
        }

        z->parent = y;

        if (y == nullptr)
            root = z;
        else if (y->key.IsFrontThan(z->key))
            y->right = z;
        else
            y->left = z;

        //z�� root�����
        if (z->parent == nullptr)
        {
            z->color = BLACK;
            return;
        }
        // z�� �θ��尡 root����� Fix Up �ʿ���� red�÷��� �ٿ��ָ� �ȴ�.
        if (z->parent->parent == nullptr)
        {
            return;
        }
        InsertFixUp(z);

        return;
    }

    void InsertFixUp(NodePtr z)
    {
        /*root ��尡 �ƴϰ� �θ� ���� red���*/
        while (z != root && z->parent->color == RED)
        {
            NodePtr grandparent = z->parent->parent;
            NodePtr uncle = (z->parent == grandparent->left) ? grandparent->right : grandparent->left;
            bool side = (z->parent == grandparent->left) ? true : false; //if p[z]�� p[p[z]]�� ���� �ڽ��̸� 1 / �������̸� 0

            /*case 1*/
            if (uncle && uncle->color == RED)
            {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                z = grandparent;
            }

            /*case 2
                side == true ) p[z]�� p[p[z]]�� ���� �ڽ� �� ����̴�.
                side == false ) p[z]�� p[p[z]]�� ������ �ڽ� �� ����̴�. */
            else
            {
                /*case 2-1*/
                if (z == (side ? z->parent->right : z->parent->left))
                {
                    z = z->parent;
                    side ? RotateLeft(z) : RotateRight(z);
                }
                /*case 2-2*/
                z->parent->color = BLACK;
                grandparent->color = RED;
                side ? RotateRight(grandparent) : RotateLeft(grandparent);
            }
        }
        root->color = BLACK;
    }

    bool Delete(string item)
    {
        NodePtr z = IsKey(item);
        if (!z)
            return false;
        else
        {
            NodePtr x, y;
            Color OriginalColor = z->color;

            /*�ڽ��� ���ų� 1���� ���
                    ������ ���(z)�� ���̸� doulbe red�̹Ƿ� fix*/
            if (z->left == leafNode)
            {
                x = z->right;
                Transplant(z, z->right);
            }
            else if (z->right == leafNode)
            {
                x = z->left;
                Transplant(z, z->left);
            }
            else
            {
                y = tree_minimum(z->right);
                OriginalColor = y->color;
                x = y->right; //y�� ���� �ڽ��� ����.

                if (y->parent == z)
                {                  //z�� ������ �ڽ��� ���� ���� key
                    x->parent = y; // x�� leafnode�� ��, fix�ϰ� �� �� ���
                }
                else
                {
                    Transplant(y, y->right);
                    y->right = z->right;
                    y->right->parent = y;
                }
                Transplant(z, y);
                y->left = z->left;
                y->left->parent = y;
                y->color = z->color;
            }
            delete z;
            if (OriginalColor == BLACK)
            {
                DelteFixUp(x);
            }
        }
        return true;
    }

    void DelteFixUp(NodePtr x)
    {
        NodePtr s; //������� s

        //root�̰ų� double black �� ������ ����
        while (x != root && x->color == BLACK)
        {
            /* x�� p[x]�� �����ڽ��� ��� */
            if (x == x->parent->left)
            {
                s = x->parent->right;
                // case 1
                if (s->color == RED)
                {
                    s->color = BLACK;
                    x->parent->color = RED;
                    RotateLeft(x->parent);
                    s = x->parent->right;
                }

                // case 2
                if (s->left->color == BLACK && s->right->color == BLACK)
                {
                    s->color = RED;
                    x = x->parent;
                }
                else
                {
                    // case 3
                    if (s->right->color == BLACK)
                    {
                        s->left->color = BLACK;
                        s->color = RED;
                        RotateRight(s);
                        s = x->parent->right;
                    }

                    // case 4
                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->right->color = BLACK;
                    RotateLeft(x->parent);
                    x = root;
                }
            }

            /*x�� p[x]�� ������ �ڽ��� ���*/
            else
            {
                s = x->parent->left;
                // case 1
                if (s->color == RED)
                {
                    s->color = BLACK;
                    x->parent->color = RED;
                    RotateRight(x->parent);
                    s = x->parent->left;
                }

                // case 2
                if (s->left->color == BLACK && s->right->color == BLACK)
                {
                    s->color = RED;
                    x = x->parent;
                }
                else
                {
                    // case 3
                    if (s->left->color == BLACK)
                    {
                        s->right->color = BLACK;
                        s->color = RED;
                        RotateLeft(s);
                        s = x->parent->left;
                    }
                    // case 4
                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->left->color = BLACK;
                    RotateRight(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
        root->color = BLACK;
    }

    /* u�� ��ġ�� v�� �̽� */
    void Transplant(NodePtr u, NodePtr v)
    {
        if (u->parent == nullptr)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;

        v->parent = u->parent;
    }
    /*x�� �߽����� �������� ȸ��*/
    void RotateLeft(NodePtr x)
    {
        NodePtr y;

        y = x->right;
        x->right = y->left;
        if (y->left != leafNode)
        {
            y->left->parent = x;
        }
        y->parent = x->parent;

        if (!x->parent)
        {
            root = y;
        }
        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }
        x->parent = y;
        y->left = x;
    }
    /*x�� �߽����� ���������� ȸ��*/
    void RotateRight(NodePtr y)
    {
        NodePtr x;

        x = y->left;
        y->left = x->right;
        if (x->right != leafNode)
        {
            x->right->parent = y;
        }
        x->parent = y->parent;

        if (!y->parent)
        {
            root = x;
        }
        else if (y == y->parent->left)
        {
            y->parent->left = x;
        }
        else
        {
            y->parent->right = x;
        }
        y->parent = x;
        x->right = y;
    }

    /*show tree*/
    void print_helper(NodePtr root, std::string indent, bool last)
    {
        // print the tree structure on the screen
        if (root != leafNode)
        {
            std::cout << indent;
            if (last)
            {
                std::cout << "R----";
                indent += "     ";
            }
            else
            {
                std::cout << "L----";
                indent += "|    ";
            }

            std::string sColor = (root->color == RED) ? "RED" : "BLACK";
            std::cout << root->key.GetWord() << " : " << root->key.GetMean() << "(" << sColor << ")" << std::endl;
            print_helper(root->left, indent, false);
            print_helper(root->right, indent, true);
        }
    }

    /*������ȸ*/
    void Inorder(NodePtr target)
    {
        if (target == leafNode)
            return;
        Inorder(target->left);
        std::cout << target->key.GetWord() << " : " << target->key.GetMean() << " ";
        Inorder(target->right);
    }
    /*������ȸ*/
    void Postorder(NodePtr target)
    {
        if (target == leafNode)
            return;
        Postorder(target->left);
        Postorder(target->right);
        std::cout << target->key.GetWord() << " : " << target->key.GetMean() << " ";
    }
    /*������ȸ*/
    void Preorder(NodePtr target)
    {
        if (target == leafNode)
            return;
        std::cout << target->key.GetWord() << " : " << target->key.GetMean() << " ";
        Preorder(target->left);
        Preorder(target->right);
    }

public:
    RBTREE()
    {
        leafNode = new node;
        leafNode->color = BLACK;
        leafNode->left = nullptr;
        leafNode->right = nullptr;
        leafNode->parent = nullptr;
        root = leafNode;
    }
    //�ּڰ� ã��
    NodePtr tree_minimum(NodePtr x)
    {
        while (x->left != leafNode)
        {
            x = x->left;
        }
        return x;
    }
    //�ִ� ã��
    NodePtr tree_maximum(NodePtr x)
    {
        while (x->right != leafNode)
        {
            x = x->right;
        }
        return x;
    }

    void DisplayMenuBoard()
    {
        std::cout << "               Menu " << std::endl;
        std::cout << "          1. Insert Key     " << std::endl;
        std::cout << "          2. Delete Key     " << std::endl;
        std::cout << "          3. Show Tree      " << std::endl;
        std::cout << "          4. choose order   " << std::endl;
        std::cout << "          5. show Menu      " << std::endl;
        std::cout << "          6. clear Display  " << std::endl;
        std::cout << "          7. exit           " << std::endl;
        std::cout << std::endl;
    }
    void SelectMenu()
    {
        DisplayMenuBoard();
        int i = -1;

        while (true)
        {
            std::cout << "--> select   :   ";
            std::cin >> i;
            switch (i)
            {
            case 1:
                Insert_helper();
                break;
            case 2:
                Delete_helper();
                break;
            case 3:
                print_helper(root, "", true);
                break;
            case 4:
                Order_helper();
                break;
            case 5:
                DisplayMenuBoard();
                break;
            case 6:
                system("cls");
                DisplayMenuBoard();
                break;
            case 7:
                return;
            default:
                std::cout << " !!! Wrong entered !!!\n"
                    << std::endl;

            }
        }
    }

    void Insert_helper()
    {
        string item, mean;
        std::cout << "Word to insert  :  ";
        std::cin >> item;
        std::cout << "Mean to insert  :  ";
        std::cin >> mean;
        if (IsKey(item))
        {
            std::cout << "!!! " << item << " is already exists !!!\n";
            return;
        }
        Insert(item, mean);
    }
    void Delete_helper()
    {
        string item;
        std::cout << "Key to delete  :  ";
        std::cin >> item;
        if (!Delete(item))
        {
            std::cout << "!!! " << item << " is not exists !!!\n";
            return;
        }
        return;
    }
    void Order_helper()
    {
        int i;
        std::cout << "         == Order Menu ==" << std::endl;
        std::cout << "          1. PreOrder" << std::endl;
        std::cout << "          2. InOrder" << std::endl;
        std::cout << "          3. PostOrder" << std::endl;
        std::cout << "          4. exit" << std::endl;
        std::cout << " --> select  :  ";

        std::cin >> i;
        switch (i)
        {
        case 1:
            Preorder(this->root);
            std::cout << std::endl;
            break;
        case 2:
            Inorder(this->root);
            std::cout << std::endl;
            break;
        case 3:
            Postorder(this->root);
            std::cout << std::endl;
            break;
        case 4:
            return;
        default:
            std::cout << " !!! Wrong enter !!!\n"
                << std::endl;
            break;
        }
        return;
    }
};

int main()
{
    RBTREE tree;
    tree.SelectMenu();

    return 0;
}