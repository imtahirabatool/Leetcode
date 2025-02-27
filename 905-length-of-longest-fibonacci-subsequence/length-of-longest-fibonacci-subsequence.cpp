class Solution {
public:
    bool binary_search(vector<int>& arr, int target) {
        int i = 0, n = arr.size(), j = n - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (arr[mid] == target)
                return true;
            else if (arr[mid] > target)
                j = mid - 1;
            else
                i = mid + 1;
        }
        return false;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), max_val = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x = arr[i], y = arr[j], s = x + y, l = arr[n - 1], cnt = 2;
                while (binary_search(arr, s)) {
                    x = y;
                    y = s;
                    s = x + y;
                    cnt++;
                }
                if (cnt == 2)
                    cnt = 0;
                max_val = max(max_val, cnt);
            }
        }
        return max_val;
    }
};