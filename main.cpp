#include <iostream>
#include "coada.h"
#include "DEQUE.h"
#include "PriorityQueue.h"
using namespace std;

int main()
{
    PriorityQueue<char>p;
    coada<char>c;
    cin>>p;
    cin>>c;
    PriorityQueue<char>a=p+c;
    cout<<a;
    return 0;
}
