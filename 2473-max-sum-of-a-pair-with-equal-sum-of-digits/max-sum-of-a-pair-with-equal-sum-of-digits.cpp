class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> maxNum;
        int maxSum = -1;

        for (int num : nums) {
            int sumDigits = digitSum(num);
            
            if (maxNum.count(sumDigits)) {
                maxSum = max(maxSum, num + maxNum[sumDigits]);
                maxNum[sumDigits] = max(maxNum[sumDigits], num);
            } else {
                maxNum[sumDigits] = num;
            }
        }
        return maxSum;
    }
};