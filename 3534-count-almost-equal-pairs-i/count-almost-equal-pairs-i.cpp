class Solution {
public:
    vector<int> getDigits(int num){
        vector<int>digits;
        while(num){
            digits.push_back(num % 10);
            num /= 10;
        }
        return digits;
    }
    int countPairs(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] == nums[j]){
                    ans++;
                    continue;
                }
                vector<int>nums2 = getDigits(nums[j]);
                reverse(nums2.begin(), nums2.end()); 
                int f = 0;
                for(int k = 0; k < nums2.size(); k++){
                    for(int l = k + 1; l < nums2.size(); l++){ 
                        swap(nums2[l], nums2[k]);
                        int new_val = 0;
                        for(int m = 0; m < nums2.size(); m++){
                            new_val = new_val * 10 + nums2[m];
                            // cout << nums2[m] << endl;  
                        }
                        // cout <<  new_val << endl; 
                        if(new_val == nums[i]){
                            f = 1;
                            break;
                        }
                        swap(nums2[l], nums2[k]);
                    }
                    if(f) break;
                }
                if(f) ans++;
            }
        }
        return ans;   
    }
};