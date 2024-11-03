class Solution {
public:
    bool rotateString(string s, string goal) {
        int s_l = s.length(), goal_l = goal.length();
        if (s_l != goal_l) {
            return false;
        }
        string doubled = s + s;
        return doubled.find(goal) != string::npos;
    }
};