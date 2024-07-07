class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        int minEnergy = *min_element(enemyEnergies.begin(), enemyEnergies.end());
        long long ans = 0;
        if (minEnergy > currentEnergy) {
            return 0;
        }
        for (auto it : enemyEnergies) {
            ans += it;
        }
        ans -= minEnergy;
        ans += currentEnergy;

        return ans / minEnergy;
    }
};