/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    unordered_map<int, int> m;
    TreeNode* construct(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie){
        if(ps > pe or is > ie){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[ps]);
        int index = m[preorder[ps]];
        int count = index - is;
        root->left = construct(preorder, ps + 1, ps + count, inorder, is, index - 1);
        root->right = construct(preorder, ps + count + 1, pe, inorder, index + 1, ie);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            m[inorder[i]] = i;
        }
        return construct(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
// @lc code=end

