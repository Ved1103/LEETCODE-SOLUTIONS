class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        int n = expression.size();
        int i = 0;

        while (i < n) {
            char temp = expression[i];
            if (temp == '|' || temp == '(' || temp == 't' || temp == '&' || temp == '!' || temp == 'f') {
                st.push(temp);
            } 
            else if (temp == ')') {
                vector<char> curr;
                while (st.top() != '(') {
                    curr.push_back(st.top());
                    st.pop();
                }
                st.pop(); // popping the first occurrence of '('

                char top = st.top();
                st.pop();

                if (top == '|') {
                    bool result = false;
                    for (char ch : curr) {
                        if (ch == 't') {
                            result = true;
                            break;
                        }
                    }
                    st.push(result ? 't' : 'f');
                } 


                else if (top == '&') {
                    bool result = true;
                    for (char ch : curr) {
                        if (ch == 'f') {
                            result = false;
                            break;
                        }
                    }
                    st.push(result ? 't' : 'f');
                } 



                else if (top == '!') {
                    st.push(curr[0] == 't' ? 'f' : 't');
                }
            }

            i++;
        }

        return st.top() == 't'; // checking whether ans in true or false
    }
};
