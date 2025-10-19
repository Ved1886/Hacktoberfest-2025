// LeetCode 70: Climbing Stairs
// Solution using optimized Dynamic Programming (Fibonacci)
// Time Complexity: O(n), Space Complexity: O(1)

#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;

        // We only need to store the last two steps
        int one_step_back = 2; // Ways to reach step 2
        int two_steps_back = 1; // Ways to reach step 1
        int current_ways = 0;

        // Start from step 3
        for (int i = 3; i <= n; ++i) {
            // Ways to reach step 'i' is the sum of ways to reach (i-1) and (i-2)
            current_ways = one_step_back + two_steps_back;
            
            // Update the pointers
            two_steps_back = one_step_back;
            one_step_back = current_ways;
        }

        return one_step_back; // This holds the result for n >= 3
    }
};

// Main function to test
int main() {
    Solution sol;

    std::cout << "Ways to climb 2 stairs: " << sol.climbStairs(2) << std::endl; // Expected: 2
    std::cout << "Ways to climb 3 stairs: " << sol.climbStairs(3) << std::endl; // Expected: 3
    std::cout << "Ways to climb 5 stairs: " << sol.climbStairs(5) << std::endl; // Expected: 8

    return 0;
}
