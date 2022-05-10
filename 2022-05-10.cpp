#include <iostream>
#include <queue>
#include <random>

using namespace std;

typedef struct linked {
    int data;
    struct linked* next; // 자기 참조 포인터
}node;
node* head = NULL; // 자료의 시작 위치
node* tail = NULL; // 자료의 마지막 위치
void Init();
void Insert(node* ptr);
void PrintList(node* ptr);
void Modify(node* ptr);
void InsertData(node* ptr);
void Delete(node* ptr);

int main() {
    int menu = 0;
    Init();
    while (1) {
        cout << "1. 입력 2. 출력 3. 수정 4. 삽입 5. 삭제 6. 종료" << endl;
        cout << "input menu : ";
        cin >> menu;
        switch (menu) {
        case 1:
            Insert(tail);
            break;
        case 2:
            PrintList(head);
            break;
        case 3:
            Modify(head);
            break;
        case 4:
            InsertData(head);
            break;
        case 5:
            Delete(head);
            break;
        case 6:
            break;
        default:
            cout << "select menu error.." << endl;
        }
        if (menu == 6) break;
    }
    return 0;
}

void Init() {
    head = new node;
    head->data = 0;
    head->next = NULL;
    tail = head; // 초기에는 tail과 head가 같은 위치
    return;
}

void Insert(node* ptr) { // 리스트의 맨 끝에 삽입됨
    node* newnode = new node;
    int num = 0;
    cout << "input number : ";
    cin >> num;
    newnode->data = num; // newnode에 num 삽입
    newnode->next = NULL; // newnode의 자료는 NULL이 됨
    ptr->next = newnode; // ptr next는 newnode를 바라봄
    tail = newnode;
    return;
}

void PrintList(node* ptr) {
    node* view = ptr->next; // head의 next가 view에 삽입
    while (1) {
        cout << view->data << " -> "; // view가 갖고 있는 자료 출력
        view = view->next; // view에 다음 값 삽입
        if (view == NULL) {
            cout << "NULL";
            break;
        }
    }
    cout << endl;
    return;
}

void Modify(node* ptr) { // 입력한 인덱스의 값을 수정함  
    int index = 0;
    int num = 0;
    int i;
    cout << "input modify index : ";
    cin >> index;
    cout << "input modify data :";
    cin >> num;
    for (i = 0; i < index; i++) {
        ptr = ptr->next;
    }
    ptr->data = num;
    return;
}

void InsertData(node* ptr) { // 입력한 인덱스 뒤에 삽입됨
    node* newnode = new node;
    int index = 0, num = 0;
    int i;
    cout << "input InsertData index : "; // 어디에 삽입할 것인가?
    cin >> index;
    cout << "input data : "; // 어느 값을 삽입할 것인가?
    cin >> num;
    for (i = 0; i < index; i++) // 입력된 위치 찾기
        ptr = ptr->next;
    newnode->data = num; // newnode 자료에 값을 삽입
    newnode->next = NULL; // newnode 다음은 NULL
    if (ptr->next == NULL) {
        ptr->next = newnode; // ptr의 다음 노드를 newnode로 지정
        tail = newnode; // tail을 newnode로 이동
    }
    else {
        newnode->next = ptr->next; // newnode의 다음을 ptr의 다음으로 지정
		ptr->next = newnode; // ptr의 다음을 newnode로 지정
    }
    return;
}

void Delete(node* ptr) {
    node* temp = 0;
    int i;
    int index;
    if (head == tail) {
        cout << "not found data" << endl;
        return;
    }
    cout << "input delete index :";
    cin >> index;
    for (i = 0; i < index ; i++) {
        ptr = ptr->next;
    }

    temp = ptr->next;
    if (temp->next == NULL) {
        ptr->next = NULL;
            tail = ptr;
    }
    else {
        ptr->next = temp->next;
    }
    delete(temp);
    return;
}

// 미완
namespace P3{
	int main() {
		enum Macaroon
		{

		};
	
		const int cheese_Del(12);
		const int milk_Del = 15;
		const int choco_Del = 24;

		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(0, 2);

		queue<char> q;
		return 0;
	}
}