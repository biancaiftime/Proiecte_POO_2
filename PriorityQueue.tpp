#include "PriorityQueue.h"
#include "coada.h"
template <class T>
void PriorityQueue<T>::push_b(const T value)
{
    if(this->dim_max>0&&this->prim->info<value)
    {
        coada<T>::push_b(this->prim->info);
        this->prim->info=value;
    }
    else coada<T>::push_b(value);
}
template <class T>
void PriorityQueue<T>::pop()
{
    coada<T>::pop();
    if(this->dim_max>1)
    {
        T max_value=this->prim->info;
        nod<T>*p;
        nod<T>*max_adress=this->prim;
        for(p=this->prim->next;p!=NULL;p=p->next)
            if(p->info>max_value)
        {
            max_value=p->info;
            max_adress=p;
        }
        max_adress->info=this->prim->info;
        this->prim->info=max_value;
    }
}
template <class T>
PriorityQueue<T> PriorityQueue<T>::operator +(coada<T>&c)const
{
    PriorityQueue<T>p;
    p=(*this);
    nod<T>*q;
    for(q=c.Adress();q!=NULL;q=q->next)p.push_b(q->info);
    return p;
}
