// LeetCode 3: Longest Substring Without Repeating Characters
// Solution using Sliding Window with a map
// Time Complexity: O(n)

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm> // For max()

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        
        // Map to store the last seen index of each character
        unordered_map<char, int> charMap;
        
        // 'left' is the start of the current window
        for (int right = 0, left = 0; right < n; ++right) {
            char char_right = s[right];
            
            // Check if we have seen this character before
            if (charMap.count(char_right)) {
                // If the char is in the map, it's a repeat.
                // Move the left pointer to the right of the *last*
                // occurrence of this char, but only if it's
                // inside our current window (i.e., >= left).
                left = max(left, charMap[char_right] + 1);
            }
            
            // Update the last seen index of the current char
            charMap[char_right] = right;
            
            // Update the max length
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};

// Main function to test
int main() {
    Solution sol;
    
    cout << "Test 1 (abcabcbb): " << sol.lengthOfLongestSubstring("abcabcbb") << endl; // Expected: 3
    cout << "Test 2 (bbbbb): " << sol.lengthOfLongestSubstring("bbbbb") << endl;    // Expected: 1
    cout << "Test 3 (pwwkew): " << sol.lengthOfLongestSubstring("pwwkew") << endl;    // Expected: 3
    cout << "Test 4 (empty): " << sol.lengthOfLongestSubstring("") << endl;        // Expected: 0
    cout << "Test 5 (a): " << sol.lengthOfLongestSubstring("a") << endl;          // Expected: 1

    return 0;
}
