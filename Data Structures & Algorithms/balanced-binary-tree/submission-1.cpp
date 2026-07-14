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

        return b[t] = 1 + max(banyak(t->left), banyak(t->right));
    }

    bool balanced = 1;
    void cek(TreeNode* t){
        if (t == NULL){
            return;
        }

        int kiri = 0, kanan = 0;
        if (t->left != NULL){
            kiri++;
        }

        if (t->right != NULL){
            kanan++;
        }

        if (abs((b[t->left] + kiri) - (b[t->right] + kanan)) > 1){
            balanced = 0;
            return;
        }

        cek(t->left);
        cek(t->right);
    }

    bool isBalanced(TreeNode* root) {
        TreeNode* temp = root;
        int bb = banyak(temp);
        cek(root);
        return balanced;
    }
};
