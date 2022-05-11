#include "CircleQueue.h"

template<typename T>
void CircleQueue<T>::InitQueue(int size)
{
    buf = new T[size];
    qsize = size;
    front = rear = 0;
}

template<typename T>
int CircleQueue<T>::IsFull()
{
    return (rear + 1) % qsize == front;
}

template<typename T>
bool CircleQueue<T>::IsEmpty()
{
    return front == rear;
}

template<typename T>
void CircleQueue<T>::Enqueue(int data)
{
    if (IsFull()) {
        cout << "Å¥°¡ ²Ë Ã¡À½" << endl;
        return;
    }
    rear = (rear + 1) % qsize;
    buf[this->rear] = data;
}

template<typename T>
void CircleQueue<T>::print_queue()
{
    {
        CircleQueue q = *this;
        cout << "front=" << q.front << " rear = " << q.rear;
        if (!q.IsEmpty()) {
            int i = q.front;
            do {
                i = (i + 1) % q.qsize;
                cout << " | " << q.buf[i];
                if (i == q.rear) {
                    cout << " | ";
                    break;
                }
            } while (i != q.front);
        }
        cout << endl;
    }
}

template<typename T>
int CircleQueue<T>::get_count()
{
    return (rear - front + qsize) % qsize;
}
