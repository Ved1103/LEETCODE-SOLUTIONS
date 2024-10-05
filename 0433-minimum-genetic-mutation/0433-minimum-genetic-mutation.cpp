class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankset;
        for (auto it : bank) {
            bankset.insert(it);
        }
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        visited.insert(startGene);
        vector<char> genes = {'A', 'C', 'G', 'T'};
        
        while (!q.empty()) {
            auto it = q.front();
            string temp = it.first;
            int level = it.second;
            q.pop();
            if(temp == endGene) {
                return level;
            }
            for (int i = 0; i < temp.size(); i++) {
                char original = temp[i];
                for (char ch : genes) {
                    if (ch != original) {
                        temp[i] = ch;
                        if (bankset.count(temp) && !visited.count(temp)) {
                            q.push({temp, level + 1});
                            visited.insert(temp);
                        }
                    }
                }
                temp[i] = original;
            }
        }
        return -1;
    }
};
