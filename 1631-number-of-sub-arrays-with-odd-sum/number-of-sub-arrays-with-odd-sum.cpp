class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        int n = nums.size(), ans = 0, MOD = 1e9 + 7;
        unordered_map<int, int> count;
        count[0] = 1;

        int sum = 0;
        for (int num : nums) {
            sum += num;
            int parity = sum % 2;

            ans = (ans + count[1 - parity]) % MOD;

            count[parity]++;
        }
        return ans;
    }
};