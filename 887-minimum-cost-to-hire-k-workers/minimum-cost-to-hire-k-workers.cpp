class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;
        
        for (int i = 0; i < n; ++i) {
            workers.push_back({(double)wage[i] / quality[i], quality[i]});
        }
        
        sort(workers.begin(), workers.end());
        
        priority_queue<int> maxHeap;
        int totalQuality = 0;
        double minCost = numeric_limits<double>::max();
        
        for (auto [ratio, qual] : workers) {
            totalQuality += qual;
            maxHeap.push(qual);
            
            if (maxHeap.size() > k) {
                totalQuality -= maxHeap.top();
                maxHeap.pop();
            }
            
            if (maxHeap.size() == k) {
                minCost = min(minCost, ratio * totalQuality);
            }
        }
        
        return minCost;
    }
};