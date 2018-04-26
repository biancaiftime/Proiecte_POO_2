#ifndef COADA_H_INCLUDED
#define COADA_H_INCLUDED
#include <iostream>
#include "nod.h"
using namespace std;
template <class T>
class coada
{
    public:
        coada();
        coada(const T value);
        coada(const coada<T>&);
        virtual ~coada();
        virtual void push_b(const T value);
        virtual void pop();
        T top();
        virtual coada<T> &operator+(const coada<T>&)const;
        coada<T> &operator=(const coada<T>&);
        coada<T> &operator-(const coada<T>&)const;
        bool operator ==(const coada<T>&)const;
        bool operator !=(const coada<T>&)const;
        bool operator <(const coada<T>&)const;
        template <class U>
        friend istream &operator>>(istream &,coada<U>&);
        template <class U>
        friend ostream &operator<<(ostream &,coada<U>&);
        int GetDim();
        nod<T>*Adress();
    protected:
        nod<T> *prim;
        nod<T> *ultim;
        int dim_max;

};
#include "coada.tpp"
#endif // COADA_H_INCLUDED
