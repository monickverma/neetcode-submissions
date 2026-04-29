class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> graph;

        for(auto preq:prerequisites)
            graph[preq[0]].push_back(preq[1]);
        
        vector<int> states(numCourses,0);

        for(int i=0;i<numCourses;i++)
            if(!dfs(i,graph,states))
                return false;
        return true;
        
    }
    bool dfs(int node, unordered_map<int,vector<int>>& graph, vector<int>& states){
        if(states[node]==1)return false;
        if(states[node]==2) return true;

        states[node]=1;

        for(auto nei: graph[node])
            if(!dfs(nei,graph,states))
                return false;
        states[node]=2;
        return true;
    }
};
