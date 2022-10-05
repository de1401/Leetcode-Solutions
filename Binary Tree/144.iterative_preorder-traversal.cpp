/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;

        if(!root){
            return {};
        }
        while(root != NULL or s.empty() == false){
            while(root != NULL){
                ans.push_back(root->val);
                if(root->right){
                    s.push(root->right);
                }
                root = root->left;
            }
            if(s.empty() == false){
                root = s.top();
                s.pop();
            } 
        }
        return ans;
    }
};
// @lc code=end

