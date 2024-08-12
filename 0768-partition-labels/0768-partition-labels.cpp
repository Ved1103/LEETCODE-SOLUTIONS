class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        vector<int> v(26, 0);
        
        for (int i = 0; i < s.size(); i++) {
            v[s[i] - 'a'] = i;
        }
        
        int i = 0, j = 0, last = 0;
        int n = s.size();
        
        while (j < n) {
            last = max(last, v[s[j] - 'a']);
            if (j == last) {
                result.push_back(j - i + 1);
                i = j + 1;
            }
            j++;
        }
        
        return result;
    }
};
