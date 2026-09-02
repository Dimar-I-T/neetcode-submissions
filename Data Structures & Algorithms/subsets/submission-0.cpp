class Solution {
public:
    void isi(vector<int> kiri, vector<int> kanan, vector<vector<int>>& hasil) {
        hasil.push_back(kiri);
        if (kanan.empty()) {
            return;
        }

        int nKiri = kiri.size();
        int nKanan = kanan.size();
        // kanan isi ke kiri
        bool kosong = kiri.empty();
        for (int x = 0; x < nKanan; x++) {
            vector<int> kiriNext = kiri;
            vector<int> kananNext;
            for (int y = 0; y < nKanan; y++) {
                if (x == y) {
                    continue;
                }

                kananNext.push_back(kanan[y]);
            }

            if (!kosong) {
                if (kiriNext[nKiri - 1] < kanan[x]) {
                    kiriNext.push_back(kanan[x]);
                } else {
                    continue;
                }
            } else {
                kiriNext.push_back(kanan[x]);
            }

            isi(kiriNext, kananNext, hasil);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> hasil;
        isi({}, nums, hasil);
        return hasil;
    }
};
