class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), totalSum = 0;

        for (int x : cardPoints) {
            totalSum += x; //total sum
        }

        int windowSize = n - k, windowSum = 0;
        
        // calculate sum of first window
        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }

        int maxSum = totalSum - windowSum;

        // Slide the window and compute maxSum
        for (int i = windowSize; i < n; i++) {
            windowSum += cardPoints[i] - cardPoints[i - windowSize];
            maxSum = max(maxSum, totalSum - windowSum);
        }

        return maxSum;
    }
};