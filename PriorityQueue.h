#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED
template <class T>
class PriorityQueue:public coada<T>
{
public:
    PriorityQueue():coada<T>(){};
    PriorityQueue(const T value):coada<T>(value){};
    PriorityQueue(const PriorityQueue<T>&p):coada<T>((coada<T>&)p){};
    void push_b(const T value);
    void pop();
};

#include "PriorityQueue.tpp"
#endif // PRIORITYQUEUE_H_INCLUDED
