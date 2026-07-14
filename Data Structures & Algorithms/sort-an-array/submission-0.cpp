class Solution {
public:
    void sortTwo(vector<int>& A, pair<int, int> p1, pair<int, int> p2) {
        int l1 = p1.first, r1 = p1.second;
        int l2 = p2.first, r2 = p2.second;
        vector<int> bucket((r1 - l1 + 1) + (r2 - l2 + 1));
        int k = 0;
        while (l1 <= r1 && l2 <= r2) {
            if (A[l1] > A[l2]) {
                bucket[k] = A[l2];
                l2++;
            } else {
                bucket[k] = A[l1];
                l1++;
            }

            k++;
        }

        while (l1 <= r1) {
            bucket[k] = A[l1];
            l1++;
            k++;
        }

        while (l2 <= r2) {
            bucket[k] = A[l2];
            l2++;
            k++;
        }

        k = 0;
        for (int x = p1.first; x <= p2.second; x++) {
            A[x] = bucket[k];
            k++;
        }
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }

        int m = (l + r) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        sortTwo(nums, {l, m}, {m + 1, r});
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};