class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l=1, h=(position.back()- position[0])/(m-1),ans=1;

        while(l<=h){
            int mid=l+(h-l)/2;
            if(canWePlace(position, mid, m)){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
    private:
    bool canWePlace(const vector<int>&arr, int dist, int balls){
        int countBalls=1;
        int lastPlaced=arr[0];
        for(int i=1; i<arr.size(); i++){
            if(arr[i]-lastPlaced>=dist){
                countBalls++;
                lastPlaced=arr[i];
            }
            if(countBalls>=balls){
                return true;
            }
        }
        return false;
    }
};