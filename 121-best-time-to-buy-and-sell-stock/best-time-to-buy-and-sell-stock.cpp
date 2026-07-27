class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_pro = 0, min_price = prices[0];

        for (int i = 0; i < prices.size(); i++) {
            int curr_pro = 0;
            if (min_price > prices[i]) {
                min_price = prices[i];
            }

            curr_pro = prices[i] - min_price;

            max_pro = max(max_pro, curr_pro);
        }
        return max_pro;
    }
};