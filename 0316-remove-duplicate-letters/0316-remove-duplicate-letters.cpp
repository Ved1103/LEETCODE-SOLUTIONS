class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        unordered_map<char, int> mp;  
        unordered_set<char> seen;    

        stack<char> st;              

        for (char ch : s) {
            mp[ch]++;
        }

        for (int i = 0; i < n; ++i) {
            char temp = s[i];
            mp[temp]--;
            if (seen.find(temp) != seen.end()) {
                continue;
            }
            
            while (!st.empty() and st.top() > temp and mp[st.top()] > 0) {
                char top = st.top();
                st.pop();
                seen.erase(top);
            }
            
            st.push(temp);
            seen.insert(temp);
        }

        string result;
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};