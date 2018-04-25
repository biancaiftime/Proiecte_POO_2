#include "nod.h"
#include <iostream>
using namespace std;
template <class T>
nod<T>::nod()
{
    next=NULL;
}
template <class T>
nod<T>::nod(T value)
{
    info=value;
    next=NULL;
}
template <class T>
nod<T>::nod(const nod<T> &value)
{
    info=value.info;
    next=value.next;
}
template <class T>
nod<T> &nod<T>::operator=(const nod<T> &value)
{
    info=value.info;
    next=value.next;
    return *this;
}
template <class T>
bool nod<T>::operator==(const nod<T> &value)const
{
    return info==value.info;
}
template <class T>
bool nod<T>::operator!=(const nod<T> &value)const
{
    return info!=value.info;
}
template <class T>
bool nod<T>::operator<(const nod<T> &value)const
{
    return info<value.info;
}
template <class T>
T nod<T>::getter()
{
    return info;
}
template <class T>
istream &operator>>(istream& in,nod <T>& value)
{
    in>>value.info;
    value.next=NULL;
    return in;
}
template <class T>
ostream &operator<<(ostream &out,const nod<T>& value)
{
    out<<value.info;
    return out;
}
