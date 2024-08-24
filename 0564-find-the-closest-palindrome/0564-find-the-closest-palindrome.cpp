class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        if (len == 1) return to_string(stoi(n) - 1);

        set<long long> candidates;

        long long selfNumber = stoll(n);
        long long highBound = pow(10, len) + 1;
        long long lowBound = pow(10, len - 1) - 1;
        candidates.insert(highBound);
        candidates.insert(lowBound);

        string prefix = n.substr(0, (len + 1) / 2);
        long long prefixNumber = stoll(prefix);

        for (int i = -1; i <= 1; ++i) {
            string newPrefix = to_string(prefixNumber + i);
            string candidate = newPrefix + string(newPrefix.rbegin() + (len % 2), newPrefix.rend());
            candidates.insert(stoll(candidate));
        }

        candidates.erase(selfNumber);

        long long nearest = -1;
        for (long long candidate : candidates) {
            if (nearest == -1 || abs(candidate - selfNumber) < abs(nearest - selfNumber) ||
                (abs(candidate - selfNumber) == abs(nearest - selfNumber) && candidate < nearest)) {
                nearest = candidate;
            }
        }

        return to_string(nearest);
    }
};
