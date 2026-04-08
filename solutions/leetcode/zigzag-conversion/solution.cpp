// Problem  : Zigzag Conversion
// Difficulty: Medium
// Tags     : String
// URL      : https://leetcode.com/problems/zigzag-conversion/
// Solved on: 2026-04-09 02:42
// ──────────────────────────────────────────────────

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;

            // direction change
            if (currentRow == 0 || currentRow == numRows - 1)
                goingDown = !goingDown;

            currentRow += goingDown ? 1 : -1;
        }

        // final result
        string result;
        for (string row : rows) {
            result += row;
        }

        return result;
    }
};

