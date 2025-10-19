// LeetCode 141: Linked List Cycle
// Solution using Floyd's Tortoise and Hare (Two Pointers)
// Time Complexity: O(n)

#include <iostream>
#include <vector>

// (ListNode definition is the same as problem 1)
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};

// Main function to test
int main() {
    Solution sol;

    // Test 1: Cycle
    ListNode* head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = head1->next; // Cycle back to node 2
    std::cout << "Test 1 (has cycle): " << (sol.hasCycle(head1) ? "true" : "false") << std::endl; // Expected: true

    // Test 2: No cycle
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    std::cout << "Test 2 (no cycle): " << (sol.hasCycle(head2) ? "true" : "false") << std::endl; // Expected: false

    // Test 3: Empty list
    std::cout << "Test 3 (empty): " << (sol.hasCycle(nullptr) ? "true" : "false") << std::endl; // Expected: false

    return 0;
}
