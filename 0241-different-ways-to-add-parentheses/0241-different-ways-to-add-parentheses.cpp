class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        int n = expression.size();
        
        for (int i = 0; i < n; i++) {
            char ch = expression[i];
            if (ch == '+' || ch == '-' || ch == '*') {
                vector<int> leftans = diffWaysToCompute(expression.substr(0, i));
                vector<int> rightans = diffWaysToCompute(expression.substr(i + 1));
                
                for (int left : leftans) {
                    for (int right : rightans) {
                        if (ch == '+') {
                            ans.push_back(left + right);
                        } else if (ch == '-') {
                            ans.push_back(left - right);
                        } else if (ch == '*') {
                            ans.push_back(left * right);
                        }
                    }
                }
            }
        }
        
        if (ans.empty()) {
            ans.push_back(stoi(expression));
        }  
        return ans;
    }
};
