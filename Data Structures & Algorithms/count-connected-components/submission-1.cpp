class Solution {
   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;

        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int concomp = 0;
        vector<bool> states(n, false);

        for (int i = 0; i < n; i++) {
            
            if (states[i] == 0) {
                dfs(edges, graph, states, i);
                concomp++;
            }
        }

        return concomp;
    }

    void dfs(vector<vector<int>>& edges, unordered_map<int, vector<int>>& graph,
             vector<bool> & states, int i) {

                if(states[i]) return;

                states[i] = true;  
                for(auto& nei:graph[i]){
                    if(!states[nei]) dfs(edges,graph, states,nei);
                }
             }
};
