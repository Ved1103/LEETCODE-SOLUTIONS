class Solution {
public:
    int getLucky(string s, int k) {
        string temp = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char ch = s[i] - 'a' + 1;
            temp += to_string(ch);
        }
        int ans = 0;
        while (k > 0) {
            int var = 0;
            for (char ch : temp) {
                var += ch - '0';
            }
            temp = to_string(var);
            ans = var;
            k--;
        }
        return ans;
    }
};