class Solution {
public:
    struct Car {
        int distance;
        int speed;
        float time = 0;
    };

    static bool cmp(Car a, Car b) {
        return a.distance < b.distance;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // phase 1
        int n = position.size();
        vector<Car> cars(n);
        for (int x = 0; x < n; x++) {
            cars[x] = {target - position[x], speed[x], (float)(target - position[x])/(float)(speed[x])};
        }

        sort(cars.begin(), cars.end(), cmp);
        stack<float> st;
        float first = cars[0].time;
        st.push(first);
        for (int x = 1; x < n; x++) {
            float top = st.top();
            float curr = cars[x].time;
            if (curr > top) {
                st.push(curr);
            }
        }

        return st.size();
    }
};
