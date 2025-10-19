// LeetCode 21: Merge Two Sorted Lists
// Solution using a dummy head node
// Time Complexity: O(n + m)

#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the start of the new list
        ListNode dummyHead(0);
        ListNode* current = &dummyHead;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // At least one list is now empty. Append the other list.
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        // The merged list starts *after* the dummy head
        return dummyHead.next;
    }
};

// Helper functions for testing
ListNode* createList(const std::vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Main function to test
int main() {
    Solution sol;
    
    // Test 1
    ListNode* l1 = createList({1, 2, 4});
    ListNode* l2 = createList({1, 3, 4});
    std::cout << "Test 1:" << std::endl;
    printList(sol.mergeTwoLists(l1, l2)); // Expected: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> nullptr

    // Test 2: One empty list
    ListNode* l3 = createList({});
    ListNode* l4 = createList({0});
    std::cout << "\nTest 2:" << std::endl;
    printList(sol.mergeTwoLists(l3, l4)); // Expected: 0 -> nullptr
    
    return 0;
}
