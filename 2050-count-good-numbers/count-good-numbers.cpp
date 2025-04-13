class Solution {
public:
    int mod = 1e9 + 7;
    long long get_ans(long long n, long long num) {
        if (n == 0)
            return 1;
        if (n == 1)
            return num;
        long long ans = get_ans(n / 2, num);
        ans = (ans * ans) % mod;
        if (n & 1)
            ans = (num * ans) % mod;
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long ans = (get_ans((n + 1) / 2, 5) * get_ans(n / 2, 4)) % mod;
        return ans;
    }
};