class Solution {
public:
    bool check(vector<vector<int>> &graph, int start, vector<int> &colors){
        int n = graph.size();
        colors[start] = 1;
        queue<int>q;
        q.push(start);
        while(q.size()){
            int node = q.front();
            q.pop();
            for(auto it: graph[node]){
                if(colors[it] == -1){
                    q.push(it);
                    colors[it] = !colors[node];
                }
                else if(colors[node] == colors[it]){
                    return 0;
                }
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>colors(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++){
            if(colors[i] == -1 && check(graph,i,colors) == false){
                return false;
            }            
        }      
        return true;
    }
};