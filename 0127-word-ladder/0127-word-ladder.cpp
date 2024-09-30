class Solution {
public:
    int ladderLength(string beginWord, string endWord,vector<string>& wordList) {
        unordered_set<string> st;
        for (string str : wordList)
            st.insert(str);

        if (!st.count(endWord))
            return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto it = q.front();
            string temp = it.first;
            int level = it.second;
            q.pop();

            if (temp == endWord)
                return level;

            for (int i = 0; i < temp.size(); i++) {
                char original = temp[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;
                    if (st.count(temp)) {
                        st.erase(temp);
                        q.push({temp, level + 1});
                    }
                }
                temp[i] = original;
            }
        }
        return 0;
    }
};
