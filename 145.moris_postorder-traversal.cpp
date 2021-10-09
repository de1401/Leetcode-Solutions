/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return {};
        }
        while(root){
            if(root->right == NULL){
                ans.push_back(root->val);
                root = root->left;
            }
            else{
                TreeNode* pre = root->right;
                while(pre->left != NULL && pre->left != root){
                    pre = pre->left;
                }
                if(pre->left == NULL){
                    ans.push_back(root->val);
                    pre->left = root;
                    root = root->right;
                }
                else{ //pre->left = root
                    pre->left = NULL;
                    root = root->left;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

