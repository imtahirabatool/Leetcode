class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i = 0, j = 1, k = 2;
        int n = arr.size();
        while (k < n) {
             if (arr[i] % 2 != 0 && arr[j] % 2 != 0 && arr[k] % 2 != 0) {
                return true;
            }
             i++, j++, k++;
        }
        return false;
    }
};