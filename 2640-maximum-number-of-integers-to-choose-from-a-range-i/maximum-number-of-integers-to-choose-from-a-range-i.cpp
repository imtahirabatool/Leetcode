class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> ans(banned.begin(), banned.end());
        int count, sum = 0, i = 1;

        while (i <= n && sum + i <= maxSum) {
            if (ans.find(i) == ans.end()) {
                cout << i << endl;
                count++;
                sum += i;
            }
            i++;
        }
        return count;
    }
};