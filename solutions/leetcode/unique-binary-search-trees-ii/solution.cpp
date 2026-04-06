// Problem  : Unique Binary Search Trees II
// Difficulty: Medium
// Tags     : Dynamic Programming, Backtracking, Tree, Binary Search Tree, Binary Tree
// URL      : https://leetcode.com/problems/unique-binary-search-trees-ii/
// Solved on: 2026-04-07 01:55
// ──────────────────────────────────────────────────

class Solution {
public:

    vector<TreeNode*> build(int start, int end){
        vector<TreeNode*> trees;

        if(start > end){
            trees.push_back(NULL);
            return trees;
        }

        for(int i = start; i <= end; i++){
            
            // all left subtree
            vector<TreeNode*> left = build(start, i-1);

            // all right subtree
            vector<TreeNode*> right = build(i+1, end);

            // combine
            for(auto l : left){
                for(auto r : right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return build(1, n);
    }
};
