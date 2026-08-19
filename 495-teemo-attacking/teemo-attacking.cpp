class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int timePoisened = 0;
        int totalTime = 0;
        int n = timeSeries.size();
        for (int i = 0; i + 1 < n; i++) {
            if (timeSeries[i] == timeSeries[i + 1])
                continue;
            timePoisened = timeSeries[i] + duration - 1;
            if (timePoisened >= timeSeries[i + 1])
                timePoisened = timeSeries[i + 1] - 1;
            totalTime += timePoisened - timeSeries[i] + 1;
        }
        totalTime += duration;
        return totalTime;
    }
};