class Solution {
public:
    long long coloredCells(int n) {
        long long res = 1;
        int i = 4;

        while (n > 1) {
            res += i;
            i += 4;
            n--;
        }
        return res;
    }
};