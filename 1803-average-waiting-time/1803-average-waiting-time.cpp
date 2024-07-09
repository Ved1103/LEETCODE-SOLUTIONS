class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long int currentTime = 0;
        long long int totaltime = 0;
        int n = customers.size();

        for (auto it : customers) {
            int arrival = it[0];
            int time = it[1];

            if (currentTime < arrival) {
                currentTime = arrival;
            }
            currentTime += time;
            totaltime += (currentTime - arrival);
        }
        return totaltime / (double)n;
    }
};