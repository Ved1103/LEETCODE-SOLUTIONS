class Solution {
public:
    void backtrack(vector<string>& result, unordered_map<char, vector<char>>& mp, string& temp, int index, string& digits) {
        if (index == digits.size()) {
            result.push_back(temp);
            return;
        }
        char digit = digits[index];
        for (char letter : mp[digit]) {
            temp.push_back(letter);
            backtrack(result, mp, temp, index + 1, digits);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        unordered_map<char, vector<char>> mp;
        mp['2'] = {'a','b','c'};
        mp['3'] = {'d','e','f'};
        mp['4'] = {'g','h','i'};
        mp['5'] = {'j','k','l'};
        mp['6'] = {'m','n','o'};
        mp['7'] = {'p','q','r','s'};
        mp['8'] = {'t','u','v'};
        mp['9'] = {'w','x','y','z'};

        vector<string> result;
        string temp = "";
        backtrack(result, mp, temp, 0, digits);
        return result;
    }
};