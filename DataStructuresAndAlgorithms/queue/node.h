/* node template definition for linked list node with elememnt T*/
#ifndef NODE_H
#define NODE_H
//#include "./queue.h"
template <typename T>
class Node
{
    Node<T> *next;
    T data;

public:
    Node() = delete;
    Node(const T &d, Node<T> *n = nullptr) : data{d}, next{n} {};
    ~Node() { data.~T(); }; //  needed if a non trivial T needs to be destroyed properly;
    Node<T>* & getNext(){return next;}
    T& getData(){ return data;}
};

#endif //NODE_H