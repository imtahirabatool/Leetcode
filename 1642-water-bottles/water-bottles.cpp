class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count=numBottles;

        while (numBottles >= numExchange) {
            int newBottles = numBottles / numExchange;
            int remainingBottles = numBottles % numExchange;
            count += newBottles;
            numBottles = newBottles + remainingBottles;
        }
        
        return count;
    }
};