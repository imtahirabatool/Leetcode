class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle = abs(30 * hour + 0.5 * minutes - 6 * minutes);

        return angle < 180 ? angle : 360 - angle;
    }
};