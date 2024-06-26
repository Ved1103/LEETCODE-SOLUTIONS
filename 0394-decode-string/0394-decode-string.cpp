class Solution {
public:
    string decodeString(const string& s) {
        stack<int> numStk;
        stack<string> strStk;
        int num = 0;
        string curr = "";

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                numStk.push(num);
                strStk.push(curr);
                num = 0;
                curr = "";
            } else if (c == ']') {
                string temp = strStk.top();
                strStk.pop();
                int count = numStk.top();
                numStk.pop();
                for (int i = 0; i < count; ++i) {
                    temp += curr;
                }
                curr = temp;
            } else {
                curr += c;
            }
        }
        
        return curr;
    }
};