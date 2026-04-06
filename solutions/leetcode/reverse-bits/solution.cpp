// Problem  : Reverse Bits
// Difficulty: Easy
// Tags     : Divide and Conquer, Bit Manipulation
// URL      : https://leetcode.com/problems/reverse-bits/
// Solved on: 2026-04-07 01:55
// ──────────────────────────────────────────────────

class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            int lastBit = n & 1;     // last bit nikaalo
            ans = ans << 1;         // ans ko left shift karo
            ans = ans | lastBit;    // bit add karo
            n = n >> 1;             // n ko right shift karo
        }

        return ans;
    }
};

