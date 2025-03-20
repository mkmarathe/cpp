#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode **fast = &head;
    ListNode **slow = &head;
    /*  sz is no of nodes, n is guaranteed to be  1 <= n <= sz */
    while (*fast && n > 0) {
        fast = &((*fast)->next);
        n--;
    }

    while (*fast) {
        fast = &((*fast)->next);
        slow = &((*slow)->next);
    }
    // ListNode *markFree = *slow;
    (*slow) = (*slow)->next;
    // delete markFree; //depending on how is it allocated
    return head;
}

void printList(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    {
        ListNode e(5), d(4, &e), c(3, &d), b(2, &c), a(1, &b);
        printList(&a);
        printList(removeNthFromEnd(&a, 1));
    }
    {
        ListNode e(5), d(4, &e), c(3, &d), b(2, &c), a(1, &b);
        printList(&a);
        printList(removeNthFromEnd(&a, 3));
    }
    {
        ListNode e(5), d(4, &e), c(3, &d), b(2, &c), a(1, &b);
        printList(&a);
        printList(removeNthFromEnd(&a, 5));
    }
}
