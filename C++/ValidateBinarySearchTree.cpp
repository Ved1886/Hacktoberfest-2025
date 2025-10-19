// LeetCode 98: Validate Binary Search Tree
// Solution using recursion with min/max bounds
// Time Complexity: O(n)

#include <iostream>
#include <limits> // For LONG_MIN and LONG_MAX

// (TreeNode definition is the same as problem 3)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    // Helper function with valid range
    bool isValidBSTHelper(TreeNode* node, long minVal, long maxVal) {
        // An empty node is a valid BST
        if (node == nullptr) {
            return true;
        }

        // Check if the current node's value is within bounds
        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }

        // Recursively check the left and right subtrees
        // Left child's max value becomes the current node's value
        // Right child's min value becomes the current node's value
        return isValidBSTHelper(node->left, minVal, node->val) &&
               isValidBSTHelper(node->right, node->val, maxVal);
    }

public:
    bool isValidBST(TreeNode* root) {
        // Use long long to handle edge cases like INT_MIN/INT_MAX
        long long minVal = std::numeric_limits<long long>::min();
        long long maxVal = std::numeric_limits<long long>::max();
        return isValidBSTHelper(root, minVal, maxVal);
    }
};

// Main function to test
int main() {
    Solution sol;
    
    // Test 1: Valid BST
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    std::cout << "Test 1 (Valid): " << (sol.isValidBST(root1) ? "true" : "false") << std::endl; // Expected: true

    // Test 2: Invalid BST
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);
    std::cout << "Test 2 (Invalid): " << (sol.isValidBST(root2) ? "true" : "false") << std::endl; // Expected: false

    return 0;
}
