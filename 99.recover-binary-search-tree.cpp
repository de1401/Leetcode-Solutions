/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    void traversal(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& second){
        if(!root){
            return;
        }
        traversal(root->left, prev, first, second);
        if(prev){
            if(root->val < prev->val){
                if(!first){
                    first = prev;
                }
                second = root;
            }
        }
        prev = root;
        traversal(root->right, prev, first, second);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode *prev = NULL, *first = NULL, *second = NULL;
        traversal(root, prev, first, second);
        swap(first->val, second->val);
        return;
    }
};
// @lc code=end

