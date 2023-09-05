class Solution {
public:
    vector<pair<char,int>>adj[100005];
    vector<int>xorval;
    void dfs(int node, int par, int xr){
        xorval[node] = xr;
        for(auto it: adj[node]){
            if(it.second != par){
                dfs(it.second, node, xr ^ (1 << (it.first - 'a')));
            }
        }
    }
    int toggleKthBit(int n, int k)
    {
        return (n ^ (1 << (k-1)));
    }
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        xorval.resize(n);
        for(int i = 1; i < n; i++){
            adj[parent[i]].push_back({s[i], i});
            adj[i].push_back({s[i], parent[i]});
        }
        dfs(0, -1, 0);
        unordered_map<int,int>mp;
        long long ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans += mp[xorval[i]];
            for(int j = 0; j < 26; j++){
                ans += mp[toggleKthBit(xorval[i],j + 1)];
            }
            mp[xorval[i]]++;
        }
        return ans;
    }   
};