#include <iostream>
#include "pqueueclass.h"
#include <time.h>

using namespace std;
int Random(int i, int j);
int main()
{
    srand(time(NULL));
    PQueue<int> pq;
    for (int i = 0; i<10; i++)
    {
        pq.insert(Random(1,100),Random(1,15));
    }
    cout<<pq<<endl;
//    cout<<"pq.pop"<<pq.Pop()<<endl;
//    cout<<"pq.pop"<<pq.Pop()<<endl;
//    cout<<"pq.pop"<<pq.Pop()<<endl;
//    cout<<"pq.pop"<<pq.Pop()<<endl;
//    cout<<"pq.pop"<<pq.Pop()<<endl;

    pq.print_tree_debug();
    cout << "Hello World!" << endl;
    return 0;
}
int Random(int i, int j)
{
    int k=0;
    k = rand()%j+i;
    return k;
}
