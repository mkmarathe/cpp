#include ".\stack.h"
#include <complex>

int main()
{
    /* stack of ints*/  
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(11);
    intStack.push(12);
    intStack.print();

    /* stack of strings*/
    Stack<std::string> sStack(4);
    sStack.push("you?");
    sStack.push("are");
    sStack.push("How");
    sStack.push("Hi,");
    sStack.print();

    /*stack of complexs*/
    Stack<std::complex<int>> s(7);
    s.push(std::complex<int>(1, 2));
    s.push(std::complex<int>(3, 4));
    s.push(std::complex<int>(4, 4));
    s.print();

    return 0;
}