class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>p;
        for(int i = 0; i < n; i++){
            p.push_back({nums[i], i});
        }
        sort(p.begin(), p.end());
        int i = 0, j = n - 1;
        while(i < j){
            if(p[i][0] + p[j][0] < target){
                i++;
            }
            else if(p[i][0] + p[j][0] > target){
                j--;
            }
            else{
                return {p[i][1], p[j][1]}; 
            }
        }
        return {};

    }
};