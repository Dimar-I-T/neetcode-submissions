class TimeMap {
public:
    struct TS {
        int timestamp;
        string value;
    };

    const int NUL = INT_MIN;
    const int MAXN = 2 * 1e5;
    unordered_map<string, vector<TS>> um;

    TS getTS(vector<TS>& ts, int t) {
        int n = ts.size();
        int l = 0, r = n - 1;
        TS res = {NUL, ""};
        while (l <= r) {
            int m = (l + r) / 2;
            TS curr = ts[m];
            int currTimestamp = curr.timestamp;
            if (currTimestamp == t) {
                res = curr;
                break;
            } else {
                if (currTimestamp < t) {
                    res = curr;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }

        return res;
    }

    TimeMap() {
        um.reserve(MAXN);
    }
    
    void set(string key, string value, int timestamp) {
        um[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        TS res = getTS(um[key], timestamp);
        return res.value;
    }
};
