class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int>v(n+1,0);
        for(int i=0;i<shifts.size();i++){
            int l=shifts[i][0],r=shifts[i][1];
            int c=shifts[i][2];
            v[l]+=(2*c-1);
            v[r+1]-=(2*c-1);
        }
        int a=0;
        for(int i=0;i<n;i++){
            a=a+v[i];
            int p=(s[i]-'a'+a%26+26)%26;
            s[i]=char('a'+p);
        }
        return s;
    }
};