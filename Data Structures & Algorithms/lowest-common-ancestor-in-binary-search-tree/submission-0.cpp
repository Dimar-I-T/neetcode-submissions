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
    struct DepthNode {
        int depth;
        TreeNode* node;
    };

    vector<DepthNode> walkArr;
    unordered_map<int, int> indAtWalkArr;
    unordered_map<int, bool> visited;

    void dfs(TreeNode* root, int d) {
        if (visited[root->val]) {
            return;
        }

        visited[root->val] = 1;
        indAtWalkArr[root->val] = walkArr.size();
        walkArr.push_back({d, root});
        if (root->left != NULL) {
            dfs(root->left, d + 1);
            walkArr.push_back({d, root});
        }

        if (root->right != NULL) {
            dfs(root->right, d + 1);
            walkArr.push_back({d, root});
        }
    }

    DepthNode combine(DepthNode a, DepthNode b) {
        if (a.depth < b.depth) {
            return a;
        } else {
            return b;
        }
    }

    void buildSparseTable(const vector<DepthNode>& arr, vector<vector<DepthNode>>& st) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }
        
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = combine(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    DepthNode querySparseTable(int L, int R, vector<vector<DepthNode>>& st) {
        int j = __lg(R - L + 1); 
        return combine(st[L][j], st[R - (1 << j) + 1][j]);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int MAXN = 2*1e5;
        int LOG = 18;
        indAtWalkArr.reserve(MAXN);
        visited.reserve(MAXN);
        vector<vector<DepthNode>> st(MAXN, vector<DepthNode>(LOG));
        dfs(root, 0);
        buildSparseTable(walkArr, st);
        int l = min(indAtWalkArr[p->val], indAtWalkArr[q->val]);
        int r = max(indAtWalkArr[p->val], indAtWalkArr[q->val]);
        return querySparseTable(l, r, st).node;
    }
};