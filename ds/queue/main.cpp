#include <iostream>
#include "./queue.h"
using namespace std;
int main()
{
    Queue<int> q;
    int out;

    for (int i = 0; i < 10; i++)
    {
        q.enque(i);
    }
    q.printAll();

    cout << "deque " << endl;
    q.deque(out);

    q.peekFront(out);
    cout << "peekFront " << out << endl;

    q.peekBack(out);
    cout << "peekBack " << out << endl;

    for (int out = 0; q.deque(out);)
    {
        cout << out << " ";
    }
    cout << endl;
}