class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalCost=0;
        int n=colors.size();
        for(int i=0; i<n; i++){
            char currChar=colors[i];
            int maxCost=neededTime[i];
            int sum=neededTime[i];

        while(i+1<n && colors[i+1]==currChar){
            maxCost =max(maxCost, neededTime[i+1]);
            sum+=neededTime[i+1];
            i++;
        }
        totalCost+=sum-maxCost;
        }
        return totalCost;
    }
};
