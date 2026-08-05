class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> container(n + m);
        int l1 = 0, l2 = 0, k = 0;
        while (l1 < m && l2 < n) {
            int n1 = nums1[l1];
            int n2 = nums2[l2];
            if (n1 <= n2) {
                container[k] = n1;
                l1++;
            } else {
                container[k] = n2;
                l2++;
            }

            k++;
        }

        while (l1 < m) {
            container[k] = nums1[l1];
            l1++;
            k++;
        }

        while (l2 < n) {
            container[k] = nums2[l2];
            l2++;
            k++;
        }

        for (int x = 0; x < k; x++) {
            nums1[x] = container[x];
        }
    }
};