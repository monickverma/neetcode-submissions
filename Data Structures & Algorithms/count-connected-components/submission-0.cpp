class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> graph;

        for(auto edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> states(n,0);

        int concomp=0;
        for(int i=0;i<n;i++){
            if(states[i]==0){
                dfs(i,graph,states);
                concomp++;
            }
        }
        return concomp;
    }

    void dfs(int node, unordered_map<int,vector<int>> & graph,vector<int>& states){
        if(states[node]) return;

        states[node]=1;

        for(auto nei: graph[node]){
            if(states[nei]==0)
                dfs(nei,graph,states);
        }
    }
};
