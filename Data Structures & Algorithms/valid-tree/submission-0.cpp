class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false; // Tree must have exactly n - 1 edges

        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> states(n, 0); // 0: UNVISITED, 1: VISITING, 2: VISITED

        if (!dfs(0, -1, graph, states)) return false; // If there's a cycle, return false

        // Non-Independency Check: All nodes must be visited
        for (int state : states) {
            if (state == 0) return false; // Found a disconnected node
        }
        
        return true;
    }

private:
    bool dfs(int node, int parent, unordered_map<int, vector<int>>& graph, vector<int>& states) {
        if (states[node] == 1) return false; // Cycle detected
        if (states[node] == 2) return true;  // Already visited

        states[node] = 1; // Mark as visiting

        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue; // Don't go back to the parent node
            if (!dfs(neighbor, node, graph, states)) return false;
        }

        states[node] = 2; // Mark as visited
        return true;
    }
};
