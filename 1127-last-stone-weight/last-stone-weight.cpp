class Solution {
public:

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> maxHeap;

    for (int stone : stones) {
        maxHeap.push(stone);
    }

    while (maxHeap.size() > 1) {
        int stone1 = maxHeap.top();
        maxHeap.pop();
        int stone2 = maxHeap.top();
        maxHeap.pop();

        int remainingWeight = stone1 - stone2;

        if (remainingWeight > 0) {
            maxHeap.push(remainingWeight);
        }
    }

    return maxHeap.empty() ? 0 : maxHeap.top();
}


};