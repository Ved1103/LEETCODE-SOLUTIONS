class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int num:asteroids){
            if(num>0 ||st.empty()){
                st.push(num);
            }
            else{
                while(!st.empty() and st.top()>0 and st.top()<abs(num)){
                    st.pop();
                }
                if(st.empty() or st.top()<0){
                    st.push(num);
                }
                else if(st.top()==abs(num)){
                    st.pop();
                }
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};