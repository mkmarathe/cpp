/* stack template */
#ifndef STACK_H
#define STACK_H
#include <iostream>

template <typename T>
class Stack
{
private:
    T *stack;
    int capacity;
    int top;
    // bool isFull();
    // bool isEmpty();

public:
    Stack(int capacity = 100);
    ~Stack();
    bool push(const T &in);
    bool pop(T &out);
    bool peek(T &out) const;
    void print(void) const;
};

template <typename T>
Stack<T>::Stack(int cap)
{
    capacity = cap;
    stack = new T[capacity];
    top = -1;
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] stack;
    stack = nullptr;
    top = -1;
}

template <typename T>
bool Stack<T>::push(const T &in)
{
    bool success = false;
    if ((top + 1) < capacity)
    {
        top++;
        stack[top] = in;
        success = true;
    }
    return success;
}

template <typename T>
bool Stack<T>::pop(T &out)
{
    bool success = false;
    if (top >= 0)
    {
        out = stack[top];
        top--;
        success = true;
        return success;
    }
}

template <typename T>
bool Stack<T>::peek(T &out) const
{
    if (top < 0)
        return false;
    out = stack[top];
    return true;
}

template <typename T>
void Stack<T>::print(void) const
{
    for (int i = top; i >= 0; i--)
    {
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;
}

#endif // STACK_H