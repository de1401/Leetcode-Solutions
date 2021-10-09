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
        vector<int> ans;
        if(!root){
            return {};
        }
        while(root){
            if(root->left == NULL){
                ans.push_back(root->val);
                root = root->right;
            }
            else{
                TreeNode* pre = root->left;
                while(pre->right != NULL && pre->right != root){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    ans.push_back(root->val);
                    pre->right = root;
                    root = root->left;
                }
                else{ //pre->right = root
                    pre->right = NULL;
                    root = root->right;
                }
            }
        }
        return ans;   
    }
};
// @lc code=end

