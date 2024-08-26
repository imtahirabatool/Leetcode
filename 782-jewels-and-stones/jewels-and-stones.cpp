class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, bool>mp;

        for(char jewel:jewels){
            mp[jewel]=true;
        }
        int count=0;

        for(char stone :stones){
            if(mp.find(stone)!=mp.end()){
                count++;
            }
        }

        return count;
    }
};