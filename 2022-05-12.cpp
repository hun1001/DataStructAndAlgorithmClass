// ppt�� ������ ������� �ؼ� ���ȭ���̶� �Ȱ��� ������ ������ �ڵ带 ��ġ��!!
// �ϴ� int s_count ���� ���� ����!!
#include <iostream>
using namespace std;
typedef struct NODE
{
    NODE* next;
    int data;
};
void enQueue(int _data);
int deQueue();
void printData();
bool isEmpty();
void Menu();
NODE* s_front;
NODE* s_rear;
int main()
{
    int data, nKey = 0;
	s_front = NULL;
	s_rear = NULL;
    while (true)
    {
        Menu();
        cin >> nKey;
        switch (nKey)
        {
        case 1:
            cout << "Enqueue: ";
            cin >> data;
            enQueue(data);
            break;
        case 2:
            cout << "Dequeue: " << deQueue() << endl;
            break;
        case 3:
            printData();
            break;
        default:
            cout << "�Է� ����" << endl;
            break;
        }
        cout << "\n";
    }
    return 0;
}
void enQueue(int _data)
{
    NODE* newNode = new NODE;
	newNode->data = _data;
	newNode->next = NULL;
    if (s_front == NULL)
    {
        s_front = newNode;
        s_rear = newNode;
    }
    else
    {
        s_rear->next = newNode;
        s_rear = newNode;
    }
}
int deQueue()
{
    int data = s_front->data;
	NODE* temp = s_front;
	s_front = s_front->next;
	delete temp;
	return data;
}

void printData()
{
    if (isEmpty())
    {
        cout << "\nQueue is Empty\n\n";
        return;
    }
    NODE* temp = s_front;
	while (temp != NULL)
	{
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

bool isEmpty() { return s_front == s_rear && s_front == NULL; }
    
void Menu()
{
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Show Queue" << endl;
    cout << "INPUT : ";
}