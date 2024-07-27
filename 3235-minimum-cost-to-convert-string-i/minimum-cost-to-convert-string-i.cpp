class Solution {
public:

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<pair<int,int>>adj[26];
        int n = original.size();
        for(int i = 0; i < n; i++){
            adj[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }
        vector<vector<long long int>>all_distances(26);
        for(int i = 0; i < 26; i++){
            if(adj[i].size()){
                vector<long long int>min_distances(26, LLONG_MAX);
                queue<int>q;
                q.push(i);
                min_distances[i] = 0;
                while(q.size()){
                    int top = q.front();
                    q.pop();
                    // cout << top << endl;
                    for(auto it: adj[top]){
                        if(min_distances[it.first] > min_distances[top] + it.second){
                            min_distances[it.first] = min_distances[top] + it.second;
                            q.push(it.first);
                        }
                    }     
                }
                all_distances[i] = min_distances;
            }
        }
        long long m = source.size(), ans = 0;

        for(int i = 0; i < m; i++){
            if(all_distances[source[i] - 'a'].size()){
                if(all_distances[source[i] - 'a'][target[i] - 'a'] == LLONG_MAX) return -1;
                ans += all_distances[source[i] - 'a'][target[i] - 'a'];
            }else if(source[i] != target[i]){
                return -1;
            }
        }
        return ans;
    }
};