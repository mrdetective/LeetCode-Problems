class Solution {
public:

    int mod = 1e9 + 7;
    
    int binpow(long long a, long long b, long long m){
        a %= m;
        long long res = 1;
        while(b > 0){
            if(b % 2){
                res = (res * a) % m;
            }
            a = (a * a) % m;
            b /= 2;
        }
        return res;
    }

    long long calc(vector<int> &nums, vector<long long>&fact, vector<long long>&inv_fact){
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        vector<int>right, left;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[0]){
                right.push_back(nums[i]);
            }
            else{
                left.push_back(nums[i]);
            }
        }

        int m1 = right.size(), m2 = left.size();
        long long ans = (((fact[m1 + m2] * inv_fact[m1]) % mod) * inv_fact[m2]) % mod;
        if(right.size()){
            ans = (ans * calc(right, fact, inv_fact)) % mod;
        } 
        if(left.size()){
            ans = (ans * calc(left, fact, inv_fact)) % mod;
        }

        return ans;

    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        vector<long long>fact(n + 1), inv_fact(n + 1);
        fact[0] = inv_fact[0] = 1;
        for(int i = 1; i <= n; i++){
            fact[i] = (fact[i - 1] * i) % mod;
           
        }
        inv_fact[n] = binpow(fact[n], mod - 2, mod); 
        for(int i = n - 1; i >= 1; i--){
            inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
        }
        
        return calc(nums, fact, inv_fact) - 1;
    }
};