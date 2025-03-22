#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
    struct Less {
        bool operator()(const ListNode *l, const ListNode *r) const {
            return l->val > r->val;
        }
    };
    priority_queue<ListNode *, vector<ListNode *>, Less> pq;

    for (int i = 0; i < lists.size(); i++) {
        if (lists[i])
            pq.push(lists[i]);
    }
    ListNode *head = NULL;
    ListNode **curr = &head;
    while (!pq.empty()) {
        ListNode *min = pq.top();
        *curr = min;
        curr = &(min->next);
        pq.pop();
        if (min->next)
            pq.push(min->next);
    }
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
        ListNode *one =
            new ListNode(1, new ListNode(2, new ListNode(3, nullptr)));
        ListNode *two =
            new ListNode(2, new ListNode(6, new ListNode(7, nullptr)));
        printList(one);
        printList(two);
        vector<ListNode *> klist{one, two};
        printList(mergeKLists(klist));
        // free the list.
    }
    {
        ListNode *one = new ListNode(7, new ListNode(9, nullptr));
        ListNode *two = new ListNode(2, new ListNode(6, nullptr));
        ListNode *three = nullptr;
        printList(one);
        printList(two);
        vector<ListNode *> klist{one, two, three};
        printList(mergeKLists(klist));
        // free the list.
    }
}
