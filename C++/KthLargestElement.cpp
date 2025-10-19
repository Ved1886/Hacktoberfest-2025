// LeetCode 215: Kth Largest Element in an Array
// Solution using a min-heap (priority_queue)
// Time Complexity: O(N log k)

#include <iostream>
#include <vector>
#include <queue> // For priority_queue

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Create a min-heap
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (size_t i = 0; i < nums.size(); ++i) {
            minHeap.push(nums[i]);
            
            // If the heap size exceeds k, remove the smallest element
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // The root of the min-heap is the k-th largest element
        return minHeap.top();
    }
};

// Main function to test
int main() {
    Solution sol;

    // Test 1
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    cout << "Test 1 (k=2): " << sol.findKthLargest(nums1, k1) << endl; // Expected: 5

    // Test 2
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    cout << "Test 2 (k=4): " << sol.findKthLargest(nums2, k2) << endl; // Expected: 4

    return 0;
}
