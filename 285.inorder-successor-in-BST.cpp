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
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode* ans = NULL;
    
    TreeNode* findP(TreeNode* root, TreeNode* p){
        if(!root){
            return NULL;
        }
        if(root->val == p->val){
            return root;
        }
        if(root->val < p->val){
            findP(root->right, p);
        }
        if(root->val > p->val){
            ans = root;
            findP(root->left, p);
        }
        return NULL;
    }

    TreeNode* MaxofRight(TreeNode* root){
        if(root->left == NULL){
            return root;
        }
        return MaxofRight(root->left);
    }

    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        // write your code here
        if(!root){
            return NULL;
        }
        if(p->right == NULL){
            findP(root, p);
            return ans;
        }
        return MaxofRight(p->right);
    }
};