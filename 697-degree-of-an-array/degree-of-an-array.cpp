
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq, firstIdx, lastIdx;
        int maxFreq = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (freq.find(num) == freq.end()) {
                firstIdx[num] = i;
            }
            lastIdx[num] = i;
            maxFreq = max(maxFreq, ++freq[num]);
        }

        int minLength = nums.size(); 
        
        for (auto& entry : freq) {
            if (entry.second == maxFreq) {
                int num = entry.first;
                minLength = min(minLength, lastIdx[num] - firstIdx[num] + 1);
            }
        }

        return minLength;
    }
};