class Solution {
public:

    unordered_map<int,int> memo;
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        if(amount<0)  return -1;

        if (memo.count(amount)) return memo[amount];
        int minCoins = INT_MAX;
        for (int coin : coins) {
            int res = coinChange(coins, amount - coin);
            if (res != -1) minCoins = min(minCoins, res + 1);
        }
        memo[amount]=minCoins==INT_MAX?-1:minCoins;
        return memo[amount];
        
    }
};