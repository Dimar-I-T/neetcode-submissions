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
    void balik(TreeNode* t){
        if (t == NULL) {
            return;
        }
        
        TreeNode* tempKiri = t->left;
        TreeNode* tempKanan = t->right;
        t->left = tempKanan;
        t->right = tempKiri;
        if (t->left != NULL){
            balik(t->left);
        }

        if (t->right != NULL){
            balik(t->right);
        }
    }

    TreeNode* invertTree(TreeNode* root) {
        balik(root);
        return root;
    }
};
