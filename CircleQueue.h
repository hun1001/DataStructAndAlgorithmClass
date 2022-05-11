#pragma once
#include <iostream>

using namespace std;

template<typename T>
class CircleQueue {
public:
    int front;
    int rear;
    T* buf;
    int qsize;

    void InitQueue(int size);

    int IsFull();

    bool IsEmpty();

    void Enqueue(int data);

    T Dequeue()
    {
        T num = NULL;
        if (IsEmpty()) {
            cout << "큐가 비었음\n";
            return -1;
        }
        front = (front + 1) % qsize;
        num = buf[front];
        return num;
    }

    void print_queue();

    int get_count();
};
