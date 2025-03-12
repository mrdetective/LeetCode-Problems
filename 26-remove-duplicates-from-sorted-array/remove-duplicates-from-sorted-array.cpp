class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique_elements = 0, n = nums.size(), c = 0;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] != nums[i + 1]){
                nums[c] = nums[i];
                unique_elements++;
                c++;
            }
        }
        nums[c] = nums[n - 1];
        unique_elements++;
    
        return unique_elements;
    }
};