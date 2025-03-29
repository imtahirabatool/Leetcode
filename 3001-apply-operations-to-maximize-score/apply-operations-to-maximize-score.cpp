class Solution {
public:
    const int MOD = 1e9 + 7;

    // Function to count distinct prime factors of a number
    int countPrimeFactors(int x) {
        int count = 0;
        for (int p = 2; p * p <= x; p++) {
            if (x % p == 0) {
                count++;
                while (x % p == 0)
                    x /= p;
            }
        }
        return count + (x > 1);
    }

    // Function for modular exponentiation
    long long modPow(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int maximumScore(vector<int>& a, int k) {
        int n = a.size(), res = 1;
        vector<int> primeCount(n), left(n, -1), right(n, n);

        // Step 1: Compute distinct prime factor counts
        for (int i = 0; i < n; i++) {
            primeCount[i] = countPrimeFactors(a[i]);
        }

        // Step 2: Compute Left and Right Boundaries
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && primeCount[st.top()] < primeCount[i])
                st.pop();
            if (!st.empty())
                left[i] = st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && primeCount[st.top()] <= primeCount[i])
                st.pop();
            if (!st.empty())
                right[i] = st.top();
            st.push(i);
        }

        // Step 3: Sort indices by values in descending order
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] > a[j]; });

        // Step 4: Calculate maximum score
        for (int i : idx) {
            long long range = (long long)(i - left[i]) * (right[i] - i);
            long long exponent = min((long long)k, range);
            res = (res * modPow(a[i], exponent, MOD)) % MOD;
            k -= range;
            if (k <= 0)
                break;
        }

        return res;
    }
};