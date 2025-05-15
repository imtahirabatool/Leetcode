class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int index = 0;
        for (int i = 1; i < n; i++) {
            int ans = prices[i] - prices[index];
            if (ans > profit) {
                profit = ans;
            }
            if (ans <= 0) {
                index = i;
            }
        }
        return profit;
    }
};