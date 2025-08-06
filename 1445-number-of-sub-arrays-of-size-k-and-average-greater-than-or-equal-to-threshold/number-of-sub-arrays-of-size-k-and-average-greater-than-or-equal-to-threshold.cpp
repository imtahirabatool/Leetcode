class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0, sum = 0, avg = 0;

        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        avg = sum / k;
        if (avg >= threshold)
            count++;

        for (int i = k; i < arr.size(); ++i) {
            sum += arr[i] - arr[i - k];
            avg = sum / k;
            if (avg >= threshold)
                count++;
        }

        return count;
    }
};