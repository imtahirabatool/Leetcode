class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); i++) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        sort(jobs.begin(), jobs.end());

        sort(worker.begin(), worker.end());

        int maxProfit = 0, jobIndex = 0, bestProfit = 0;
        for (int i = 0; i < worker.size(); i++) {
            while (jobIndex < jobs.size() &&
                   jobs[jobIndex].first <= worker[i]) {
                bestProfit = max(bestProfit, jobs[jobIndex].second);
                jobIndex++;
            }
            maxProfit += bestProfit;
        }
        return maxProfit;
    }
};