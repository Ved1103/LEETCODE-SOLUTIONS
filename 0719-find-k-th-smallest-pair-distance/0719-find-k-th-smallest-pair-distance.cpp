class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // brute force:
        // int n = nums.size();
        // vector<int> temp;
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         temp.push_back(abs(nums[i]-nums[j]));
        //     }
        // }
        // sort(temp.begin(),temp.end());
        // return temp[k-1];

        //optimise soln:
        int n = nums.size();
        int maxEl = *max_element(begin(nums), end(nums));
        vector<int> vec(maxEl + 1, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int d = abs(nums[i] - nums[j]);
                vec[d]++;
            }
        }


        for (int d = 0; d <= maxEl; d++) {
            k -= vec[d];
            if (k <= 0) {
                return d; 
            }
        }
        return -1;
        
    }
};