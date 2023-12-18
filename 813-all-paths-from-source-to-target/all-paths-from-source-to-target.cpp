class Solution {
public:
    vector<stack<int>>paths;
    void dfs(int node, vector<vector<int>> &graph, stack<int> &s){
        s.push(node);
        if(node == graph.size() - 1){
            paths.push_back(s);
            s.pop();
            return;
        }
        for(auto it: graph[node]){
            dfs(it, graph, s);
        }
        s.pop();      
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {               
        int n = graph.size();
        stack<int>s;
        dfs(0,graph,s);
        vector<vector<int>>ans(paths.size());
        for(int i = 0 ; i < paths.size(); i++){
            while(paths[i].size()){
                ans[i].push_back(paths[i].top());
                paths[i].pop();
            }
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};