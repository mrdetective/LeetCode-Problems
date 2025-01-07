class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<map<long long,int>>mp(n);
        for(int i = 1; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                long long diff = ((long long)nums[i] - (long long)nums[j]);
                mp[i][diff]++;
                if(mp[j].count(diff))
                    mp[i][diff] += mp[j][diff];
                    ans += mp[j][diff];
            }   
        }
        return ans;
    }
};