class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;  
        int n = heights.size();
        
        for (int i = 0; i < n; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (heights[j] < heights[minIndex]) {
                    minIndex = j;
                }
            }
            if (i != minIndex) {
                swap(heights[i], heights[minIndex]);
            }
        }
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (heights[i] != expected[i]) {
                count++;
            }
        }
        return count;
    }
};
