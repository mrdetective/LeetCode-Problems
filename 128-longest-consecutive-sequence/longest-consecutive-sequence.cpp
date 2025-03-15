class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if(arr.size() == 0){
            return 0;
        }
        sort(arr.begin(), arr.end());
        int len = 1, ans = 1, n = arr.size();
        for(int i = 1; i < n; i++){
            if(arr[i] - 1 == arr[i - 1]){
                len++;
            }
            else if(arr[i] == arr[i - 1]){
                continue;
            }
            else{
                ans = max(len, ans);
                len = 1;
            }
        }
        ans = max(len, ans);
        return ans;
    }
};