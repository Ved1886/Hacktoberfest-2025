// LeetCode 226: Invert Binary Tree
// Solution using recursion (DFS)
// Time Complexity: O(n)

#include <iostream>
#include <queue> // For printing

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Base case
        if (root == nullptr) {
            return nullptr;
        }

        // Swap the children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recursively invert the children
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

// Helper function to print tree (Level Order)
void printTree(TreeNode* root) {
    if (root == nullptr) {
        std::cout << "[empty]" << std::endl;
        return;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node != nullptr) {
            std::cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            std::cout << "null ";
        }
    }
    std::cout << std::endl;
}

// Main function to test
int main() {
    Solution sol;
    
    // Create a tree: 4 / [2, 7] / [1, 3, 6, 9]
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    std::cout << "Original tree: ";
    printTree(root); // Expected: 4 2 7 1 3 6 9 ...
    
    sol.invertTree(root);
    
    std::cout << "Inverted tree: ";
    printTree(root); // Expected: 4 7 2 9 6 3 1 ...

    return 0;
}
