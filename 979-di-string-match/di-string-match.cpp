class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> prem;
        int low = 0, high = s.length();

        for (char c : s) {
            if (c == 'I') {
                prem.push_back(low++);
            } else {
                prem.push_back(high--);
            }
        }
        prem.push_back(low);

        return prem;
    }
};