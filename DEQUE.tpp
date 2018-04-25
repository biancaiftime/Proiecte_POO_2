#include "DEQUE.h"
#include "coada.h"
template <class T>
void DEQUE<T>::push_f(const T value)
{
    nod<T>*p=new nod<T>;
    p->info=value;
    p->next=this->prim;
    this->prim=p;
    ++this->dim_max;
}
template <class T>
void DEQUE<T>::pop_b()
{
    if(this->dim_max!=0)
    {
        nod<T>*q=this->ultim;
        nod<T>*p;
        for(p=this->prim;p!=this->ultim;p=p->next);
        this->ultim=p;
        delete q;
    }
    else throw("coada vida");
}
template <class T>
T DEQUE<T>::top_b()
{
    if(this->dim_max!=0) return (this->ultim)->info;
    else throw("coada vida");
}
