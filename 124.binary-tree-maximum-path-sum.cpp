/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0, max_ans = INT_MIN;

    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }
        int l = max(dfs(root->left), 0);
        int r = max(dfs(root->right), 0);
        ans = root->val + l + r;
        max_ans = max(ans, max_ans);
        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_ans;
    }
};
// @lc code=end

