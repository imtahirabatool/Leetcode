class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int>freq;
        for(char c:s){
            freq[c]++;
        }

        int deletion=0;
        unordered_map<int, bool>usedFreq;

        for(auto& pair:freq){
            int count=pair.second;

            while(usedFreq[count]){
                count--;
                deletion++;
            }
            if(count>0){
                usedFreq[count]=true;
            }
        }
        return deletion;
    }
};