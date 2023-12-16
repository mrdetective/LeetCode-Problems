class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dis(n + 1, INT_MAX);
        vector<pair<int,int>>adj[n + 1];
        for(int i = 0; i < times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({k, 0});
        dis[k] = 0;
        while(q.size()){
            int node = q.top().first;
            int d = q.top().second;
            q.pop();
            for(int i = 0; i < adj[node].size(); i++){
                if(d + adj[node][i].second < dis[adj[node][i].first]){
                    dis[adj[node][i].first] = d + adj[node][i].second;
                    q.push({adj[node][i].first, dis[adj[node][i].first]});
                }
            }
        }
        int ans = -1;
        for(int i = 1; i < n + 1; i++){
            if(dis[i] == INT_MAX) return -1;
            ans = max(ans, dis[i]);
        }
        return ans;
    }

};