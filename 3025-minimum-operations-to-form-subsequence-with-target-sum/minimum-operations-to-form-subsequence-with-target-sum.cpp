class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        if(accumulate(nums.begin(), nums.end(), 0LL) < target){
            return -1;
        }
        int n = nums.size(),ans = 0;
        vector<int>bits(32);
        for(int i = 0; i < n ; i++){
            bits[log2(nums[i])]++;
        }
        for(int i = 0; i < 31;){
            if((1 << i) & target){
                if(bits[i]){
                    bits[i]--;
                }
                else{
                    while(i < 31 && bits[i] == 0){
                        ans++;
                        i++;
                    }
                    bits[i]--;
                    continue;
                }
            }
            bits[i + 1] += (bits[i] / 2);
            i++;
        }
        return ans;
    }
};