#include <stack>
#include <string>
#include "CircleQueue.h"

using namespace std;

template<typename T>
class MyQueue {
public:
    MyQueue(int qsize = 0) {
        InitQueue(qsize);
    }
	
protected:
    T* queue;
    int qsize;
	int front;
	int rear;
    int count;
	
public:
    void InitQueue(int qsize) {
		queue = new T[qsize];
        this->qsize = qsize;
        front = rear = count = 0;
    }
	
	virtual void Enqueue(T data) {
        if (qsize <= count)
        {
			std::cout << "큐가 꽉 찼음" << std::endl;
			return;
        }
        rear++;
		queue[rear] = data;
        count++;
	}

	T Dequeue() {
        if (count == 0) {
            return queue[front];
        }
		front++;
        count--;
        return queue[front];
	}

    virtual int IsFull() {
		return qsize == count;
    }

	virtual int IsEmpty() {
		return count == 0;
	}
};

int LinearQueue(void) {
    int i;
    MyQueue<int> q1;
    q1.InitQueue(10); // 큐 초기화
	for(i=1;i<=11;i++){ // 1~5까지 큐에 보관
        cout << i << " 입력" << endl;
        q1.Enqueue(i);
    }

    cout << endl;

    while (!q1.IsEmpty()) { // 큐가 비어있지 않다면 반복
        cout << q1.Dequeue() << " 출력\n"; // 큐에서 꺼내 온 값 출력
    }
    cout << endl;
    return 0;
}

int main() {
    //LinearQueue();
    CircleQueue<int> q;
    q.InitQueue(4); 
    for (int i = 1; i < 5; i++) {
        q.Enqueue(i);
        q.print_queue();
    }
	
    for (int i = 1; i < 5; i++) {
        q.Dequeue();
        q.print_queue();
    }
	
    for (int i = 1; i < 5; i++) {
        q.Enqueue(i);
        q.print_queue();
    }
	
	return 0;
}

namespace HomeWork
{
    namespace TeachersCode {
        using namespace std;

        int prec(char op);
        string inToPost(string a);

        int main() {
            while (1) {
                string a;
                cout << "중위표기 수식 : ";
                cin >> a;
                cout << "후위표기 수식 : " << inToPost(a) << endl;
            }
            return 0;
        }

        int prec(char op) {
            switch (op) {
            case'(':case')': return 0;
            case'+':case'-': return 2;
            case'*':case'/': return 1;
            }
        }

        string inToPost(string a) {
            stack<int> s;
            string postfix = "";
            char ch;
            for (int i = 0; i < a.size(); i++) {
                ch = a[i];
                switch (ch) {
                case'+':case'-':case'*':case'/':
                    while (!s.empty() && prec(ch) <= prec(s.top())) {
                        postfix += s.top();
                        s.pop();
                    }
                    s.push(ch);
                    break;
                case'(':
                    s.push(ch);
                    break;
                case')':
                    while (s.top() != '(') {
                        postfix += s.top();
                        s.pop();
                    }
                    s.pop();
                    break;
                default:
                    postfix += ch;
                    break;
                }
            }
            while (!s.empty()) {
                postfix += s.top();
                s.pop();
            }
            return postfix;
        }
    }

    namespace NotComplete
    {
#define MAX_LENGTH 100

        using namespace std;

        int main()
        {
            stack<char> st;
            stack<int> st2;

            string str;
            cout << "중위표기식 입력 : ";
            getline(cin, str);

            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] >= '0' && str[i] <= '9')
                {
                    cout << str[i];
                }
                else
                {
                    st.push(str[i]);
                    int weight = 0;
                    switch (st.top())
                    {
                    case '+':
                        weight = 1;
                        break;
                    case '-':
                        weight = 1;
                        break;
                    case '*':
                        weight = 2;
                        break;
                    case '/':
                        weight = 2;
                        break;
                    default:
                        break;
                    }

                    st2.push(weight);

                    if (st2.top() < weight)
                    {
                        st2.push(weight);
                    }
                    else
                    {
                        while (!st2.empty() && st2.top() >= weight)
                        {
                            st.pop();
                            st2.pop();
                        }
                        st2.push(weight);
                    }
                }
            }

            while (!st.empty())
            {
                cout << st.top();
                st.pop();
            }

            return 0;
        }
    }
}