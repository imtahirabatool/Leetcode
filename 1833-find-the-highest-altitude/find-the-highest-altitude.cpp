class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currSum=0,  maxGain=0;
        for(int i=0; i<gain.size(); i++){
            currSum=currSum+gain[i]; 
            maxGain=max(maxGain, currSum);
        }
        return maxGain;
    }
};