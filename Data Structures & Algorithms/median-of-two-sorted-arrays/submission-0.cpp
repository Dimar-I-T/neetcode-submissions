class Solution {
public:
    // dimar's solution
    int cariMedianDuaSortedArray(vector<int>& nums1, vector<int>& nums2, int t) {
        int n1 = nums1.size(), n2 = nums2.size(), l1 = 0, r1 = n1 - 1, l2 = 0, r2 = n2 - 1;
        int median = nums1[0], batasKiri = -INT_MAX, batasKanan = INT_MAX, i = 1;
        while (l1 <= r1 || l2 <= r2) {
            int m1 = (l1 + r1) / 2, m2 = (l2 + r2) / 2, a = nums1[m1], b = nums2[m2], k = m1 + m2 + 1;
            if ((l2 > r2 && i == 1 && (t == batasKiri + 1 || t == batasKanan)) 
            || (l1 > r1 && i == 2 && (t == batasKiri + 1 || t == batasKanan)) 
            || (batasKanan == batasKiri + 1)) {
                break;
            }
            if (a >= b) {
                batasKanan = k; batasKiri = k;
                if (t <= k) {
                    median = b; i = 2; batasKanan = k; r1 = m1 - 1;
                    if (r1 < 0) { r2 = m2 - 1; }
                } else {
                    median = a; i = 1; batasKiri = k; l2 = m2 + 1;
                    if (l2 > r2) { l1 = m1 + 1; }
                }
            } else {
                batasKanan = k; batasKiri = k;
                if (t <= k) {
                    median = a; i = 1; batasKanan = k; r2 = m2 - 1;
                    if (r2 < 0) { r1 = m1 - 1; }
                }
                else {
                    median = b; i = 2; batasKiri = k; l1 = m1 + 1;
                    if (l1 > r1) { l2 = m2 + 1; }
                }
            }
        }
        return median;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int t = 0;
        double med = 0;
        if (n1 == 0) {
            if (n2 % 2 == 0) {
                med = (double) (((double) (nums2[n2 / 2 - 1] + nums2[n2 / 2])) / 2);
            } else {
                med = nums2[n2 / 2];
            }
        } else if (n2 == 0) {
            if (n1 % 2 == 0) {
                med = (double) (((double) (nums1[n1 / 2 - 1] + nums1[n1 / 2])) / 2);
            } else {
                med = nums1[n1 / 2];
            }
        } else {
            if ((n1 + n2) % 2 == 1) {
                t = (n1 + n2 + 1) / 2;
                med = (double)cariMedianDuaSortedArray(nums1, nums2, t);
            } else {
                t = (n1 + n2) / 2;
                double kiri = cariMedianDuaSortedArray(nums1, nums2, t);
                double kanan = cariMedianDuaSortedArray(nums1, nums2, t + 1);
                med = (double) ((kiri + kanan) / 2);
            }
        }

        return med;
    }
};
