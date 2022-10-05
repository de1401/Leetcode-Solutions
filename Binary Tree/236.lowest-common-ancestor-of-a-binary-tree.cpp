/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }
        if(root->val == p->val or root->val == q->val){
            return root;
        }
        TreeNode* lca_left = lowestCommonAncestor(root->left, p, q);
        TreeNode* lca_right = lowestCommonAncestor(root->right, p, q);

        if(lca_left and lca_right){
            return root;
        }
        return lca_left != NULL ? lca_left : lca_right;
    }
};
// @lc code=end

