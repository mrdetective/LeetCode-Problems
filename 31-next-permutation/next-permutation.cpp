class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                ind = i;
                break;
            }
        }
        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        int ind2 = -1, mini = INT_MAX;
        for(int i = ind + 1; i < n; i++){
            if(nums[i] > nums[ind] && nums[i] < mini){
                mini = nums[i];
                ind2 = i;
            }
        }
        swap(nums[ind], nums[ind2]);
        sort(nums.begin() + ind + 1, nums.end());
    }
};