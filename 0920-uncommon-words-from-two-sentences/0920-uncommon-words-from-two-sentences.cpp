class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        istringstream iss(s1 + " " + s2);
        string word;
        while (iss >> word) {
            freq[word]++;
        }
        
        vector<string> result;
        for (auto it : freq) {
            if (it.second == 1) {
                result.push_back(it.first);
            }
        }
        
        return result;
    }
};
