class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, bool>map;
        int n=nums.size();

        for(int i:nums){
            map[i]=true;
        }
        for(int i=0; i<=n; ++i){
            if(map.find(i) == map.end()){
                return i;
            }
        }

        return -1;
    }
};