class Solution {
public:
    bool check(int mid, vector<int> &nums, int maxOperations) {
        int n=nums.size();
        for(auto &num:nums){
            maxOperations-=(num+mid-1)/mid-1;
        }
        return maxOperations>=0;
        
    }
    int minimumSize(vector<int>& nums, int maxOperations){
        int n=nums.size(), l=1, r=1e9, ans=1e9;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid, nums, maxOperations)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};