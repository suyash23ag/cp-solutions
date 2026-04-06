// Problem  : Excel Sheet Column Number
// Difficulty: Easy
// Tags     : Math, String
// URL      : https://leetcode.com/problems/excel-sheet-column-number/
// Solved on: 2026-04-07 01:55
// ──────────────────────────────────────────────────

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
for(char ch: columnTitle){
     result = result * 26 + (ch - 'A' + 1); 
}
           return result;
     
    }
};
