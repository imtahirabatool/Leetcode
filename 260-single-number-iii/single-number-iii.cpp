class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int>map;
        vector<int>res;

        for(int num:nums){
            map[num]++;
        }
        for(auto& pair:map){
            if(pair.second==1){
                res.push_back(pair.first);
            }
        }
        return res;
    }
};