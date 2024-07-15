class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        int n = s.size();
        if (n < 3)
            return 0;
        for (int i = 0; i < n - 2; i++) {
            string temp = s.substr(i, 3);
            unordered_set<char> st(temp.begin(), temp.end()); 
            if (st.size() == 3) {
                count++;
            }
        }
        return count;
    }
};
