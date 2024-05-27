class Solution {
public:
    bool buddyStrings(string s, string t) {
        int n=s.size(),m=t.size();
        if(m-n) return 0;
        if(s==t) {
            map<int,int> mp;
            for(auto x:s) mp[x]++;
            for(auto x:mp) if(x.second>1) return 1;
            return 0;
        }
        int dif=0;
        string s1,t1;
        for(auto i=0;i<n;i++) if(s[i]-t[i]) {
            dif++; s1+=s[i], t1+=t[i];
        }
        if(dif!=2) return 0;
        sort(s1.begin(),s1.end());
        sort(t1.begin(),t1.end());
        if(s1==t1) return 1;
        return 0;
    }
};