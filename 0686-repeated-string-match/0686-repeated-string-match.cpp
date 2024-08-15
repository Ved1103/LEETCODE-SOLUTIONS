class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s = a;
        int ans = 1;
        int n = b.size() / a.size();
        for (int i = 0; i <= n + 1; i++) {
            if (s.find(b) != string::npos)
                return ans;
            s += a;
            ans++;
        }
        return -1;
    }
};