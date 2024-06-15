class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size(), r=0;
        map<int, int > m; 

        for (int i = 0; i < 40001; ++i){
            while (!m.empty() && (m.begin()->first <= i || m.begin()->second == 0) ) m.erase(m.begin());
            if(i<n && apples[i]>0) m[i+days[i]] += apples[i];                                           
            if (!m.empty() && m.begin()->second > 0) m.begin()->second--, r++;                           

            if (i > n && m.empty()) break;
        }
        return r;
    }
};