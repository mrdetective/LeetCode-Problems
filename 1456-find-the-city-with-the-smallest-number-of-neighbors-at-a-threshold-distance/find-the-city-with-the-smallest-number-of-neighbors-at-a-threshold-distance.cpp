class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<pair<int,int>>adj[n];
        vector<long long>all_distances[n];
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        for(int i = 0; i < n; i++){
            if(adj[i].size()){
                vector<long long>min_distances(n, LLONG_MAX);
                queue<int>q;
                q.push(i);
                min_distances[i] = 0;
                while(q.size()){
                    int top = q.front();
                    q.pop();
                    for(auto it: adj[top]){
                        if(min_distances[it.first] > it.second + min_distances[top]){
                            min_distances[it.first] = it.second + min_distances[top];
                            q.push(it.first);
                        }
                    }
                }
                all_distances[i] = min_distances;
            }
        }
        long long mini = LLONG_MAX, ans;
        for(int i = 0; i < n; i++){
            if(all_distances[i].size()){
                int val = 0;
                for(int j = 0; j < n; j++){
                    if(i != j && all_distances[i][j] <= threshold){
                        val++;
                    }
                } 
                if(val <= mini){
                    mini = val;
                    ans = i; 
                }
            }else{
                mini = 0;
                ans = i;
            }
        }
        return ans;    
    }
};