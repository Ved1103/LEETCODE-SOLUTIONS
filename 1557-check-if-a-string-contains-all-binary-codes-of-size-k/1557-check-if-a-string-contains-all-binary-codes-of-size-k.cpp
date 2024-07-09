class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int total = 1 << k;  
        int n = s.size();
        if (n < k) {
            return false;
        }
        
        unordered_set<string> st;
        for (int i = 0; i <= n - k; i++) {
            string temp = s.substr(i, k);
            if (!st.count(temp)) { 
                st.insert(temp);
            }
        }
        
        return st.size() == total;  
    }
};
