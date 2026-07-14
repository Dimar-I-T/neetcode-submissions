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
    bool sama = 1;
    void cek(TreeNode* p, TreeNode* q){
        if (p == NULL && q == NULL){
            return;
        }

        if ((p == NULL && q != NULL) || (p != NULL && q == NULL)){
            sama = 0;
            return;
        }

        if (p->val != q->val){
            sama = 0;
            return;
        }

        cek(p->left, q->left);
        cek(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        cek(p, q);
        return sama;
    }
};
