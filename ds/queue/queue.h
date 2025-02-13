/* Template for queue using list of nodes that containe T as element. */
#ifndef QUEUE_H
#define QUEUE_H
#include "./node.h"

template <typename T>
class Queue
{
    int size;       // number of elements in the que
    Node<T> *front; // where we deque
    Node<T> *back;  // where we enque
public:
    Queue()
    {
        size = 0;
        front = back = nullptr;
    }
    ~Queue();
    bool enque(const T &dataIn);
    bool deque(T &dataOut);
    bool peekBack(T &out);
    bool peekFront(T &out);
    void printAll();
};

template <typename T>
Queue<T>::~Queue()
{
    Node<T> *cur = front;
    while (cur)
    {
        Node<T> *tmp = (*cur).getNext();
        delete cur;
        cur = tmp;
    }
}

template <typename T>
bool Queue<T>::enque(const T &in)
{
    Node<T> *item = new Node<T>(in);

    if (front == nullptr)
    {
        front = item;
        
    } else {
        (*back).getNext() = item;
    }
    back = item;
  

    size++;
    return true;
}

template <typename T>
bool Queue<T>::deque(T &out)
{
    if (size == 0)
        return false;
    out = front->getData();
    front = front->getNext();
    size--;
    return true;
}

template <typename T>
bool Queue<T>::peekBack(T &out)
{
    if (back != nullptr)
    {
        out = back->getData();
        return true;
    }
    return false;
}

template <typename T>
bool Queue<T>::peekFront(T &out)
{
    if (front != nullptr)
    {
        out = front->getData();
        return true;
    }
    return false;
}

template <typename T>
void Queue<T>::printAll()
{
    if (front == nullptr)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    Node<T> *t = front;
    while (t)
    {
        cout << t->getData() << " ";
        t = t->getNext();
    }
    cout << endl;
}

#endif // QUEUE_H
