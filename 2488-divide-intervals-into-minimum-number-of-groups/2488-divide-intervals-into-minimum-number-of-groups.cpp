class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>>pq; // storing ending point so that i can access smallest ending point 
        for(auto it:intervals){
            int starting_point = it[0];
            int ending_point = it[1];
            // if(pq.empty()){
            //     pq.push(ending_point);
            // }
            if(!pq.empty() && starting_point>pq.top()){
                pq.pop();
            }
            pq.push(ending_point);

        }
        return pq.size();

    }
};