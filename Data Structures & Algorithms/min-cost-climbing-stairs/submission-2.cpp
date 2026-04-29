class Solution {
public:
    unordered_map<int,int> memo;
    int minCostClimbingStairs(vector<int>& cost) {
        return min(dfs(cost,0,cost[0]),dfs(cost,1,cost[1]));
    }

    int dfs(vector<int>&cost,int n,int price){
        if(n>cost.size()) return price;
        memo[n]=min(dfs(cost,n+1, price+cost[n+1]),dfs(cost,n+2,price+cost[n+2]));
        return memo[n];
    }
};
