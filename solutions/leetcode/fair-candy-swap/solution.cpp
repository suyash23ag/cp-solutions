// Problem  : Fair Candy Swap
// Difficulty: Easy
// Tags     : Array, Hash Table, Binary Search, Sorting
// URL      : https://leetcode.com/problems/fair-candy-swap/
// Solved on: 2026-04-11 03:22
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0, sumB = 0;

        for (int x : aliceSizes) sumA += x;
        for (int y : bobSizes) sumB += y;

        int diff = (sumA - sumB) / 2;

        unordered_set<int> s(aliceSizes.begin(), aliceSizes.end());

        for (int y : bobSizes) {
            if (s.count(y + diff)) {
                return {y + diff, y};
            }
        }

        return {};
    }
};
