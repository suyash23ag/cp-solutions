// Problem  : Container With Most Water
// Difficulty: Medium
// Tags     : Array, Two Pointers, Greedy
// URL      : https://leetcode.com/problems/container-with-most-water/
// Solved on: 2026-04-08 01:58
// ──────────────────────────────────────────────────

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int h = min(height[left], height[right]);
            int width = right - left;
            int area = h * width;

            maxWater = max(maxWater, area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};
