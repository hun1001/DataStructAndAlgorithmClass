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

    T Dequeue();

    void print_queue();

    int get_count();
};
