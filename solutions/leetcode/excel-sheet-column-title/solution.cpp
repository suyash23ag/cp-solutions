// Problem  : Excel Sheet Column Title
// Difficulty: Easy
// Tags     : Math, String
// URL      : https://leetcode.com/problems/excel-sheet-column-title/
// Solved on: 2026-04-07 01:55
// ──────────────────────────────────────────────────

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans= "";
        while (columnNumber > 0) {
         columnNumber--;
         int rem =columnNumber  %26;
         ans.push_back('A' + rem);
         columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
 
};
