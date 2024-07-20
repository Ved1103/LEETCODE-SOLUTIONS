
class Solution {
public:
    int maxProduct(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() > b.size();
        });

        int maxProd = 0;
        vector<unordered_set<char>> charSets(words.size());

        for (int i = 0; i < words.size(); ++i) {
            for (char ch : words[i]) {
                charSets[i].insert(ch);
            }
        }

        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                bool hasCommon = false;
                for (char ch : charSets[j]) {
                    if (charSets[i].count(ch) > 0) {
                        hasCommon = true;
                        break;
                    }
                }
                if (!hasCommon) {
                    int prod = words[i].size() * words[j].size();
                    maxProd = max(maxProd, prod);
                }
            }
        }
        return maxProd;
    }
};