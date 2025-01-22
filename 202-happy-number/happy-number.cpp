class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;

        while (true) {
            int ans = 0;
            while (n != 0) {
                int x = n % 10;
                n = n / 10;
                ans += (x * x);
            }
            if (ans == 1)
                break;

            if (st.find(ans) != st.end())
                return false;
            st.insert(ans);
            n = ans;
        }
        return true;
    }
};