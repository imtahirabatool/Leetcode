class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>numStr;
        for(int num:nums){
            numStr.push_back(to_string(num));
        }
        sort(numStr.begin(), numStr.end(), [](const string& a, const string& b){
            return a+b>b+a;
        });
        if(numStr[0]=="0"){
            return "0";
        }
        stringstream ss;
        for(const auto& numsStr:numStr){
            ss<<numsStr;
        }

        return ss.str();
    }
};