class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size(), count = 0;
        for (int i = 0; i < n; i++) {
            int tens = details[i][11] - '0';
            int ones = details[i][12] - '0';
            int age = tens * 10 + ones;

            if (age > 60) {
                count++;
            }
        }
        return count;
    }
};