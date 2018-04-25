#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED
#include "coada.h"
template <class T>
class DEQUE:public coada<T>
{
public:
    DEQUE():coada<T>(){};
    DEQUE(const T value):coada<T>(value){};
    DEQUE(const DEQUE<T>&d):coada<T>((coada<T>&)d){};
    void push_f(const T value);
    void pop_b();
    T top_b();
};
#include "DEQUE.tpp"
#endif // DEQUE_H_INCLUDED
