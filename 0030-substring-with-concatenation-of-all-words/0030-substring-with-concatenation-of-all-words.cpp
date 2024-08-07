class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.size(), m = words.size();
        if (n == 0 || m == 0)
            return res;

        int wl = words[0].size();
        int sl = wl * m;
        if (n < sl)
            return res;

        unordered_map<string, int> wordCount;
        for (string w : words) {
            wordCount[w]++;
        }

        for (int i = 0; i < wl; i++) {
            unordered_map<string, int> seen;
            int count = 0;
            int left = i;
            for (int j = i; j <= n - wl; j += wl) {
                string word = s.substr(j, wl);
                if (wordCount.find(word) != wordCount.end()) {
                    seen[word]++;
                    count++;

                    while (seen[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wl);
                        seen[leftWord]--;
                        count--;
                        left += wl;
                    }

                    if (count == m) {
                        res.push_back(left);
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = j + wl;
                }
            }
        }

        return res;
    }
};
