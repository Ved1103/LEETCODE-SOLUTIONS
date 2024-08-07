class Solution {
public:
    int helper(vector<int>& vec, vector<int>& cookies, int n, int k, int ind, int unfairness) {
        if (ind == n) {
            int currentUnfairness = *max_element(vec.begin(), vec.end());
            return min(unfairness, currentUnfairness);
        }

        int minUnfairness = unfairness;
        for (int i = 0; i < k; ++i) {
            vec[i] += cookies[ind];
            minUnfairness = min(minUnfairness, helper(vec, cookies, n, k, ind + 1, minUnfairness));
            vec[i] -= cookies[ind];
            if (vec[i] == 0) {
                break;
            }
        }
        return minUnfairness;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> vec(k, 0);
        return helper(vec, cookies, n, k, 0, INT_MAX);
    }
};
