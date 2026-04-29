class Solution {
    int cycleStart;
    vector<bool> visit;
    vector<vector<int>> graph;
    unordered_set<int> cycle;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
         int n=edges.size();
          graph.resize(n + 1);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        visit.resize(n+1,false);
        cycleStart=-1;
        dfs(1,-1);
        
        for(int i=edges.size()-1;i>=0;i--){
            if(cycle.count(edges[i][0])&&cycle.count(edges[i][1]))
                return {edges[i][0],edges[i][1]};
        }
        
        return {};
    }
    
    bool dfs(int node,int par) {
       
       if(visit[node]){
        cycleStart=node;
        return true;
       }
        visit[node]=true;
        for (int nei : graph[node]) {
            if(nei==par) continue;
            if(dfs(nei,node)){
            if(cycleStart!=-1) cycle.insert(node);
            if(node==cycleStart) cycleStart=-1;
            return true;}
        }
        
        return false;
    }
};
