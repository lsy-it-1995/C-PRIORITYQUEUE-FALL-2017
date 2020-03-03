#ifndef PQUEUECLASS_H
#define PQUEUECLASS_H

#include <iostream>
#include <fstream>
#include "../../../Documents/CS8(assignment)/Heapclass/heap.h"

using namespace std;

template <typename T>
struct info
{
    T item;
    int priority;

    info()
    {
        item = NULL;
        priority = 0;
    }

    info(T i, int p)
    {
        item = i;
        priority = p;
    }

    friend ostream& operator <<(ostream& outs, const info<T>& print_me)
    {
        outs<<"[P]:" <<print_me.priority<<" [T]:" <<print_me.item<<endl;
        return outs;
    }

    friend bool operator >(const info<T>& lhs, const info<T>& rhs)
    {
        return rhs.priority<lhs.priority;
    }
    friend bool operator <(const info<T>& lhs, const info<T>& rhs)
    {
        return rhs.priority>lhs.priority;
    }
};

template <typename T>
class PQueue
{
public:
    PQueue(){}
    bool insert(const T& value, int p);
    T Pop();

    bool is_empty() const;

    int size() const;

    void print_tree() const
    {
        cout<<heap;
    }

    friend ostream& operator <<(ostream& outs, const PQueue<T>& print_me)
    {
        print_me.print_tree();
        return outs;
    }
    void print_tree_debug()
    {
        while(!is_empty())
        {
            cout<<heap.Pop()<<endl;
        }
    }

private:
    Heap<info<T> > heap;
};

template <typename T>
bool PQueue<T>::is_empty() const
{
    return heap.is_empty();
}

template <typename T>
bool PQueue<T>::insert(const T &value, int p)
{
    int size = heap.size();
    info<T> V(value,p);
    heap.insert(V);
    return heap.size()>size;
}

template <typename T>
T PQueue<T>::Pop()
{
    return heap.Pop().item;
}
template<typename T>
int PQueue<T>::size() const
{
    return heap.size();
}
#endif // PQUEUECLASS_H
