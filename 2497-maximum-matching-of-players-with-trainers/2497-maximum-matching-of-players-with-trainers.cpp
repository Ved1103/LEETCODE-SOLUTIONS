class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();
        int ans = 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (players[i] <= trainers[j]) {
                ans++;
                i++;
            }
            j++;
        }
        return ans;
    }
};
