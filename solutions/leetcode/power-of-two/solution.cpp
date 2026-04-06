// Problem  : Power of Two
// Difficulty: Easy
// Tags     : Math, Bit Manipulation, Recursion
// URL      : https://leetcode.com/problems/power-of-two/
// Solved on: 2026-04-07 01:55
// ──────────────────────────────────────────────────

class Solution {
public:
bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
}

    
};
