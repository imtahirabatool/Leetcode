class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> countMap;
        vector<int> res;

        // Count the occurrences of each element in nums1
        for(int num : nums1) {
            countMap[num]++;
        }

        // Iterate through nums2 and build the result vector
        for(int num : nums2) {
            if(countMap[num] > 0) {
                res.push_back(num);
                countMap[num]--;
            }
        }

        return res;
    }
};
