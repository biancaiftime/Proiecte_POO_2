#ifndef NOD_H_INCLUDED
#define NOD_H_INCLUDED
#include <iostream>
using namespace std;
template <class T>
class coada;
template <class T>
class nod
{
    public:
       nod();
       nod(T value);
       nod(const nod<T>&);
       T getter();
       nod<T> &operator=(const nod<T>&);
       bool operator==(const nod<T>&)const;
       bool operator!=(const nod<T>&)const;
       bool operator<(const nod<T>&)const;
       template <class U>
       friend istream &operator>>(istream &,nod<U>&);
       template <class U>
       friend ostream &operator<<(ostream &,const nod<U>&);
    protected:
        T info;
        nod *next;
    template <class U>
    friend class coada;
    template <class U>
    friend class DEQUE;
    template <class U>
    friend class PriorityQueue;
};
#include "nod.tpp"
#endif // NOD_H_INCLUDED
