class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int l = 0, r = 0, n = nums.size();
        int mini = 0, maxi = 0, ans = 1;

        while(r<n){

            if(l == r){
                r++;
                continue;
            }

            if(nums[r] <= nums[mini]){
                mini = r;
            }
            if(nums[r] >= nums[maxi]){
                maxi = r;
            }

            if(nums[maxi]-nums[mini] <= limit){
                r++;
            }
            else{
                ans = max(ans,r-l);
                l = min(mini,maxi)+1;
                mini = l;
                maxi = l;
                r = l+1;
            }
        }
        ans = max(ans,r-l);
        return ans;
    }
};