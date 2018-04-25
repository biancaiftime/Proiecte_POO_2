#include "coada.h"
#include <iostream>
using namespace std;
template <class T>
coada<T>::coada()
{
    prim=ultim=NULL;
    dim_max=0;
}
template <class T>
coada<T>::coada(const T value)
{
    push_b(value);
}
template <class T>
coada<T>::coada(const coada<T>&c)
{
    dim_max=0;
    nod<T> *p;
    for(p=c.prim;p!=NULL;p=p->next)
        this->push_b(p->info);
}
template <class T>
coada<T>::~coada()
{
    while(dim_max>0)pop();
}
template <class T>
void coada<T>::push_b(const T value)
{
    nod<T>*a=new nod<T>;
    a->info=value;
    a->next=NULL;
    if(dim_max==0)prim=ultim=a;
    else
    {
        ultim->next=a;
        ultim=a;
    }
    ++dim_max;
}
template <class T>
void coada<T>::pop()
{
    if(dim_max!=0)
    {
        nod<T>*a=prim;
        prim=prim->next;
        delete a;
        --dim_max;
    }
    else throw("coada vida");
}
template <class T>
T coada<T>::top()
{
    if(dim_max==0)throw("coada vida");
    else return prim->info;
}
template <class T>
istream &operator>>(istream &in,coada<T>&c)
{
    T val;
    int i,nr;
    in>>nr;
    for(i=0;i<nr;++i)
   {
       in>>val;
       c.push_b(val);
   }
    return in;
}
template <class T>
ostream &operator<<(ostream &out,coada<T>&c)
{
    while(c.dim_max)
    {
        out<<c.top()<<" ";
        c.pop();
    }
    return out;
}
template <class T>
coada<T> &coada<T>::operator=(const coada<T>&c)
{
    if(this==&c)return *this;
    while(dim_max>0)(*this).pop();
    nod<T> *p;
    for(p=c.prim;p!=NULL;p=p->next)
        (*this).push_b(p->info);
    return *this;
}
template <class T>
coada<T> &coada<T>::operator +(const coada<T>&c)const
{
    coada<T>*s=new coada<T>;
    (*s)=*this;
    nod<T> *p;
    for(p=c.prim;p!=NULL;p=p->next) s->push_b(p->info);
    return *s;
}
template <class T>
coada<T> &coada<T>::operator -(const coada<T>&c)const
{
    coada<T>*d=new coada<T>;
    nod<T>*p,*q;
    p=prim;
    q=c.prim;
    while(p!=NULL&&q!=NULL&&p->info==q->info)
    {
        p=p->next;
        q=q->next;
    }
    while(p!=NULL)
    {
        d->push_b(p->info);
        p=p->next;
    }
    return *d;
}
template <class T>
int coada<T>::GetDim()
{
    return dim_max;
}
template <class T>
bool coada<T>::operator ==(const coada<T>&c)const
{
    if(dim_max!=c.dim_max)return 0;
    nod<T>*p,*q;
    for(p=prim,q=c.prim;p!=NULL;p=p->next,q=q->next)
        if(p->info!=q->info)return 0;
    return 1;
}
template <class T>
bool coada<T>::operator !=(const coada<T>&c)const
{
    return !(*this==c);
}
template <class T>
bool coada<T>::operator<(const coada<T>&c)const
{
    if(dim_max>c.dim_max)return 0;
    if(dim_max<c.dim_max)return 1;
    nod<T>*p,*q;
    for(p=prim,q=c.prim;p!=NULL;p=p->next,q=q->next)
        if(p->info>q->info)return 0;
    return 1;
}
