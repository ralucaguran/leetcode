#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}

    void print() {
        ListNode *head = this;
        while (head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

class Solution {
public:
    // 206. Reverse Linked List
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
    	ListNode* revList = head;
        head = head->next;
        revList->next = nullptr;
		while (head != nullptr) {
            ListNode* aux = revList;
            revList = head;
            head = head->next;
            revList->next = aux;
        }        
        return revList;
    }

    // 237.  Delete Node in a Linked List
    void deleteNode(ListNode* node) {
        if (node == nullptr) {
           return;
        }
        node->val = node->next->val;
        ListNode* aux = node->next;
        node->next = node->next->next;
        delete aux;
    }

    // 203. Remove Linked List Elements
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* aux = nullptr;
         while (cur != nullptr) {
            if (cur->val == val) {
                aux = cur;
                if (prev == nullptr) {
                    head = head->next;
                }
                else {
                    prev->next = cur->next;
                }
                cur = cur->next;
                delete aux;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }

    // 19. Remove Nth Node From End of List, two-pass
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;
        ListNode* curNode = head;
        unsigned count = 0;
        while (curNode != nullptr) {
            curNode = curNode->next;
            ++count;
        }
        count -= n;
        curNode = head;
        ListNode* prevNode = nullptr;
        while (count > 0) {
            prevNode = curNode;
            curNode = curNode->next;
            --count;
        }
        if (prevNode == nullptr) {
            head = curNode->next;
        }
        else {
            prevNode->next = curNode->next;
        }
        //delete curNode;
        return head;
    }

    // 19. Remove Nth Node From End of List, one-pass
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        if (head == nullptr) return nullptr;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p2 != nullptr && n > 0) {
            p2 = p2->next;
            --n;
        }
        if (p2 == nullptr) return p1->next;
        while (p2->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return head;
    }

    // 141. Linked List Cycle
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1 == p2) {
                return true;
            }
            p1 = p1->next;
            if (p2->next == nullptr) {
                return false;
            }
            p2 = p2->next->next;
        }
        return false;
    }

    // 147. Insertion Sort List
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* curNode = head->next;
        ListNode* prevNode = head;
        while (curNode != nullptr) {
            ListNode* cmpNode = head;
            ListNode* prevCmpNode = nullptr;
            while ((cmpNode != curNode) && (curNode->val > cmpNode->val)) {
                prevCmpNode = cmpNode;
                cmpNode = cmpNode->next;
            }
            if (cmpNode != curNode) {
                prevNode->next = curNode->next;
                curNode->next = cmpNode;
                if (cmpNode == head) {
                    head = curNode;
                }
                else {
                    prevCmpNode->next = curNode;
                }
            }
            else {
                prevNode = curNode;
            }
            curNode = prevNode->next;
        }
        return head;
    }

    // 83. Remove Duplicates from Sorted List
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while (true) {
            while (p2 != nullptr && p2->val == p1->val) {
                p2 = p2->next;
            }
            if (p1->next != p2) {
                p1->next = p2;
            }
            if (p2 == nullptr) break;
            p1 = p1->next;
            p2 = p2->next;
        }
        return head;
    }

    // 234. Palindrome Linked List
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode* aux = head;
        int numElems = 0;
        while (aux != nullptr) {
            ++numElems;
            aux = aux->next;
        }
        aux = head;
        ListNode* prev = nullptr;
        for (int i = 0; i < numElems/2; i++) {
            prev = aux;
            aux = aux->next;
        }
        ListNode* right = aux;
        if (numElems%2) {
            right = right->next;
        }
        prev->next = nullptr;
        ListNode* left = head;
        left = reverseList(left);
        while (left != nullptr) {
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }

    // 21. Merge Two Sorted Lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == l2) return l1;
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode* iter = nullptr;
        if (l1->val <= l2->val) {
            iter = l1;
            l1 = l1->next;
        }
        else {
            iter = l2;
            l2 = l2->next;
        }
        ListNode* res = iter;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                iter->next = l1;
                l1 = l1->next;
            }
            else {
                iter->next = l2;
                l2 = l2->next;
            }
            iter = iter->next;
        }
        if (l1 == nullptr) iter->next = l2;
        if (l2 == nullptr) iter->next = l1;
        return res;
    }
};


int main() {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(3);
    ListNode* l5 = new ListNode(3);
    ListNode* l6 = new ListNode(2);
    ListNode* l7 = new ListNode(1);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    l7->next = nullptr;
    Solution sol;
//    cout << sol.hasCycle(l6) << endl;
/*    ListNode* revList = sol.reverseList(l1);
    ListNode* l9 = revList;
    revList->print();
    //sol.deleteNode(l3);
    cout << "-------" << endl;
    ListNode* l = sol.removeElements(l9, 5);
    l->print();*/
    l1->print();
    //l1 = sol.removeNthFromEnd2(l1, 6);
//    l1 = sol.insertionSortList(l1);
//    l1 = sol.deleteDuplicates(l3);
    l1->print();
    cout << sol.isPalindrome(l1) << endl;
    ListNode* first = new ListNode(1);
    first->next = new ListNode(3);
    first->next->next = new ListNode(5);
    first->next->next->next = new ListNode(7);
    first->next->next->next->next = new ListNode(9);
    first->next->next->next->next->next = nullptr;
    ListNode* second = new ListNode(2);
    second->next = new ListNode(4);
    second->next->next = new ListNode(6);
    second->next->next->next = nullptr;
    sol.mergeTwoLists(second, first)->print();
    return 0;
}

