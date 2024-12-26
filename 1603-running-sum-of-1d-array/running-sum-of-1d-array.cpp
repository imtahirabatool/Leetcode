class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>res; //array initize
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum=sum+nums[i]; //sum=0===> 0+1=1, 1+2==3 3+3=6 6+4=10
            res.push_back(sum); 
        }
        return res;
    }
};
