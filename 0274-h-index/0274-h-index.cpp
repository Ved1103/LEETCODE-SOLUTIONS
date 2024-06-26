class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int h = n - i;
            if (citations[i] >= h) {
                ans = h;
                break;
            }
        }
        return ans;
    }
};
