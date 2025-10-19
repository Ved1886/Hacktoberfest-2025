// LeetCode 11: Container With Most Water
// Solution using Two Pointers
// Time Complexity: O(n)

#include <iostream>
#include <vector>
#include <algorithm> // For max() and min()

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        size_t left = 0;
        size_t right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            // Area is limited by the shorter line
            int h = min(height[left], height[right]);
            // Width is the distance between pointers
            int w = right - left;
            int area = h * w;
            
            max_area = max(max_area, area);

            // Move the pointer of the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_area;
    }
};

// Main function to test
int main() {
    Solution sol;

    // Test 1
    vector<int> h1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Test 1: " << sol.maxArea(h1) << endl; // Expected: 49

    // Test 2
    vector<int> h2 = {1, 1};
    cout << "Test 2: " << sol.maxArea(h2) << endl; // Expected: 1

    return 0;
}
