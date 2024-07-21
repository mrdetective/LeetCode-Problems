class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ranges;
        map<int,int>mp;
        for(int i = 0; i < n / 2; i++){
            int maxi = max(nums[n - 1 - i], nums[i]);
            int mini = min(nums[n - 1 - i], nums[i]);
            ranges.push_back(max(maxi, k - mini));
            mp[abs(nums[n - 1 - i] - nums[i])]++;
        }
        sort(ranges.begin(), ranges.end());
        int ans = INT_MAX;
        for(auto it: mp){
          int more = lower_bound(ranges.begin(), ranges.end(), it.first) - ranges.begin();      
          int rem = ranges.size() - more - it.second;

          if(more == 0){
            ans = min(ans, rem);
          }else{
            ans = min(ans, rem + 2*more);
          }
        }
        return ans;
    }
};