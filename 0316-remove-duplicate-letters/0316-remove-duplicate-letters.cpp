// Approach 1 : T.C = O(N) S.C = O(N)
// class Solution {
// public:
//     string removeDuplicateLetters(string s) {
//         int n = s.size();
//         unordered_map<char, int> mp;  
//         unordered_set<char> seen;    

//         stack<char> st;              

//         for (char ch : s) {
//             mp[ch]++;
//         }

//         for (int i = 0; i < n; ++i) {
//             char temp = s[i];
//             mp[temp]--;
//             if (seen.find(temp) != seen.end()) {
//                 continue;
//             }
            
//             while (!st.empty() and st.top() > temp and mp[st.top()] > 0) {
//                 char top = st.top();
//                 st.pop();
//                 seen.erase(top);
//             }
            
//             st.push(temp);
//             seen.insert(temp);
//         }

//         string result;
//         while (!st.empty()) {
//             result = st.top() + result;
//             st.pop();
//         }

//         return result;
//     }
// };

// APPROACH 2 T.C = O(N) S.C = O(1) AS HERE IM USING CONSTANT SPACE OF ARRAYS OF SIZE 26
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        int count[26] = {0};
        bool visited[26] = {false};
        string result = "";
        for (char ch : s) {
            count[ch - 'a']++;
        }

        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            count[ch - 'a']--;

            if (visited[ch - 'a']) {
                continue;
            }
            while (!result.empty() && result.back() > ch && count[result.back() - 'a'] > 0) {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }

            result += ch;
            visited[ch - 'a'] = true;
        }

        return result;
    }
};