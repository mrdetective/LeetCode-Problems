class Solution {
public:
    // 11010
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.size(), zeros = 0, ones = 0, left = 0;
        vector<long long>ans;
        vector<long long>valid_arr(n), left_valid_ind(n);
        for(int i = 0; i < n; i++){
            if(s[i] == '0') zeros++;
            else ones++;
            while(zeros > k && ones > k){
                if(s[left] == '0') zeros--;
                else ones--;
                left++;
            }
            left_valid_ind[i] = left;
            valid_arr[i] = i - left + 1;
            if(i) valid_arr[i] += valid_arr[i - 1];
        }
        for(int i = 0; i < queries.size(); i++){
            int l = queries[i][0], r = queries[i][1];
            int left = l, right = r, pos = r + 1;
            while(left <= right){
                int mid = left + (right - left)/2;
                if(left_valid_ind[mid] < l){
                    left = mid + 1;
                }else{
                    pos = mid;
                    right = mid - 1;
                }
            }
            long long res = 0;
            if(pos <= r){
                res += valid_arr[r];
                if(pos) res -= valid_arr[pos - 1];
            }
            long long diff = pos - l;
            res += ((diff * (diff + 1)) / 2);
            ans.push_back(res);

        }   
        return ans;
    }
};