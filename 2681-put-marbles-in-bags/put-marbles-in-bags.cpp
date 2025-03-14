class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(n == k || k == 1){
            return 0;
        }
        vector<long long>candidates;
        for(int i = 0; i < n - 1; i++){
            candidates.push_back(weights[i] + weights[i + 1]);
        }
        sort(candidates.begin(), candidates.end());
        long long maxi = weights[0] + weights[n - 1], mini = weights[0] + weights[n - 1];
        for(int i = n - 2; i > n - 1 - k; i--){
            maxi += candidates[i];
        }
        for(int i = 0; i < k - 1; i++){
            mini += candidates[i]; 
        }
        cout << maxi << endl;
        return maxi - mini;
    }

    // 0 1 2 3 4 5 6 7 .... n - 1
    
};

// 