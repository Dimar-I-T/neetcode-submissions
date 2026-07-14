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
    unordered_map<TreeNode*, int> b;
    int banyak(TreeNode* t){
        if (t == NULL || (t->left == NULL && t->right == NULL)){
            return 0;
        }

        b[t] = 1 + max(banyak(t->left), banyak(t->right));
        return b[t];
    }

    int maks = 0;
    void hitung(TreeNode* t){
        if (t == NULL){
            return;
        }

        int penambah = 0;
        if (t->left != NULL){
            penambah++;
        }

        if (t->right != NULL){
            penambah++;
        }

        maks = max(maks, penambah + b[t->left] + b[t->right]);
        hitung(t->left);
        hitung(t->right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        TreeNode* temp = root;
        int bb = banyak(temp);
        hitung(root);
        return maks;
    }
};
