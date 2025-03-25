#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head, ListNode *tail) {

    if (head == nullptr || head->next == tail)
        return head;
    ListNode *rhead = reverseList(head->next, tail);
    head->next->next = head;
    head->next = tail;
    return rhead;
}

ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *tail = head;
    ListNode *rhead;
    for (int i = 1; i < k; i++) {
        if (tail == nullptr) // list is smaller than k group
            break;
        tail = tail->next;
    }
    if (tail == nullptr) {
        return head; // no reversal needed.
    } else {
        ListNode *newHead = tail->next; // tail changes now so save tail->next
        rhead = reverseList(head, tail->next); // reverse between given range.
        ListNode *tmp = reverseKGroup(newHead, k);
        head->next = tmp; // make sure new tail points to new upcoming head.
    }
    return rhead;
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
        ListNode g(7), f(6, &g), e(5, &f), d(4, &e), c(3, &d), b(2, &c),
            a(1, &b);
        printList(&a);
        printList(reverseKGroup(&a, 3));
    }
}