class Solution {
public:   
// 2 3
// 8 
    long long mulmod(long long a, long long b, long long mod) 
    { 
        long long res = 0; 
        a %= mod; 
        while (b) { 
            if (b & 1) 
                res = (res + a) % mod; 
            a = (2 * a) % mod; 
            b >>= 1; 
        } 
        return res; 
    }   
    long long binpow(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        long long m = 1e9 + 7;
        if(multiplier == 1){
            return nums;
        }
        long long n = nums.size(), maxi = 0, ind;
        priority_queue<pair<long long,long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>q;
        for(long long i = 0; i < n; i++){
            q.push({nums[i], i});
            if(nums[i] > maxi){
                maxi = nums[i];
                ind = i;
            }
        }
        long long c = 0;
        while(c < k){
            long long num = q.top().first, i = q.top().second;
            q.pop();
            long long val = num * multiplier;
            q.push({val, i}); 
            c++;
            if(i == ind) break;
        }
        k -= c;
        long long times = k / n;
        vector<pair<long long,long long>>res;
        for(long long i = 0; i < n; i++){
            long long num = q.top().first, j = q.top().second;
            q.pop();
            long long val = mulmod(binpow(multiplier, times, m), num, m);
            res.push_back({val, j});
        }
        for(long long i = 0; i < k % n; i++){
            res[i].first = mulmod(multiplier, res[i].first, m);
        }
        for(long long i = 0; i < n; i++){
            nums[res[i].second] = (res[i].first % m);
        }
        return nums;
    }
};  