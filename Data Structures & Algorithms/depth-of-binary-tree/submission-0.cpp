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
    int maks = 0;
    void banyak(TreeNode* t, int b){
        if (t == NULL){
            maks = max(maks, b);
            return;
        }

        banyak(t->left, b + 1);
        banyak(t->right, b + 1);
    }

    int maxDepth(TreeNode* root) {
        banyak(root, 0);
        return maks;
    }
};
