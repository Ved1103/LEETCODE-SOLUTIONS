class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans=0;
        long long n=skill.size();

        if(n==3){
            long in = skill[0]*skill[1];
            return in;
        }
        sort(skill.begin(),skill.end());
        long long i=0;
        long long j=n-1;
        vector<long long> v;
        while (i <= j)
        {
            v.push_back(skill[i] + skill[j]); 
            ans += skill[i++] * skill[j--];
        }
        for (int t = 1; t < v.size(); t++){
            if (v[t - 1] != v[t])
                return -1; 
        } 
        if (v.size() == n/ 2)
            return ans;  
        return -1;
    }
};