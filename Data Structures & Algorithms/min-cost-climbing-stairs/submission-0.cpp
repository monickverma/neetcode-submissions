class Solution {
public:

    unordered_map<int,int> memo;
    int dfs(vector<int>& cost, int n){
        if(memo.count(n))return memo[n];
        if(n>=cost.size()) return cost[n];
      memo[n]=cost[n]+ min(dfs(cost,n+1),dfs(cost,n+2));
        return memo[n];

    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(dfs(cost,0),dfs(cost,1));
    }
};