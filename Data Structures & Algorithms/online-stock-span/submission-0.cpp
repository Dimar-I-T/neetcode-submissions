class StockSpanner {
public:
    stack<pair<int, int>> st;
    int idx = 0;
    StockSpanner() {
        
    }

    int getSpan() {
        if (idx == 1) {
            return 1;
        }

        pair<int, int> topPrice = st.top();
        int topPriceVal = topPrice.first;
        int topPriceInd = topPrice.second;
        int idxLater = 0;
        st.pop();

        pair<int, int> prevPrice = st.top();
        int prevPriceVal = prevPrice.first;
        int prevPriceInd = prevPrice.second;

        if (topPriceVal < prevPriceVal) {
            st.push(topPrice);
            return 1;
        }

        int res = 0;
        while (!st.empty()) {
            pair<int, int> bottomPrice = st.top();
            int bottomPriceVal = bottomPrice.first;
            int bottomPriceInd = bottomPrice.second;
            if (bottomPriceVal > topPriceVal) {
                break;
            }
            
            idxLater = bottomPriceInd;
            res = topPriceInd - bottomPriceInd + 1;
            st.pop();
        }

        st.push({topPriceVal, idxLater});
        return res;
    }
    
    int next(int price) {
        idx++;
        st.push({price, idx});
        return getSpan();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */