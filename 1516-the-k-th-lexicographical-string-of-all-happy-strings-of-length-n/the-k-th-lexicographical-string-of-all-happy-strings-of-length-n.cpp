class Solution {
public:
    bool backtracking(int ind,char prev,string &temp,int &n,int &k)
    {
        if(ind==n)
        {
            k--;
            if(k==0) return true;
            else return false;
        }

        bool ans=false;

        for(char ch='a';ch<='c';ch++)
        {
            if(ch!=prev)
            {
                temp.push_back(ch);
                ans|=backtracking(ind+1,ch,temp,n,k);
                if(ans==true) return true;
                temp.pop_back();
            }
        }
        return ans;
    }
    string getHappyString(int n, int k) {
        string temp="";
        backtracking(0,'d',temp,n,k);
        return temp;
    }
};