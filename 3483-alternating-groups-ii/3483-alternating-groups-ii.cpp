class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int max_len = 1; // window size che aa jyare alternating hase to size waddhti rehse and jevi rite k kato k krta vadhare thai jase em ans++ thai jase 
        int ans = 0;
        int n = colors.size();

        for (int i = 1; i <= n - 1 + k - 1; i++) {
            if (colors[i % n] == colors[(i - 1 + n) % n]) {
                max_len = 1;
            } else {
                max_len++;
            }

            if (max_len >= k) {
                ans++;
            }
        }

        return ans;
    }
};