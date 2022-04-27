#include <iostream>
#include <stack>
#include <string>
#include <queue>

template<typename T>
class MyQueue {
public:
    Queue() {
        queue = new T[0];
		front = 0;
        rear = 0;
    }
    ~Queue() {}
	
private:
    T* queue;
	int front;
	int rear;
	
public:
	void Enqueue(T data) {
		
	}

	T Dequeue() {
		
	}
};

template<typename T>
class CircleQueue : public Queue<T> {
	
};

int main() {
	
    return HomeWork::TeachersCode::main();
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