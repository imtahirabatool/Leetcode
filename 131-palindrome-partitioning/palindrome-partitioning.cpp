class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>current;
        partitionHelper(s, 0, current, res);
        return res;
    }
    void partitionHelper(const string& s, int start, vector<string>& current, vector<vector<string>>& res){
        if(start==s.length()){
            res.push_back(current);
            return;
        }
        for(int i=start; i<s.length(); ++i){
            if(isPalindrome(s, start, i)){
                current.push_back(s.substr(start, i-start+1));
                partitionHelper(s, i+1, current, res);
                current.pop_back();
            }
        }
    }
    bool isPalindrome(const string& s, int start, int end){
        while(start<end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
};