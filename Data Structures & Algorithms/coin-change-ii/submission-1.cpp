class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        dp[0]=1;

        for(int coin:coins){
            for(int i=coin;i<=amount;i++){
                dp[i]+=dp[i-coin];
            }
        }

        return dp[amount];
    }

   
};
/*
Initial Setup

We declare a dp array of size amount + 1:

ini
Copy
Edit
dp = [1, 0, 0, 0, 0, 0]  // dp[0] = 1, others = 0
dp[i] = number of ways to make amount i.

Outer Loop: coin = 1

We update dp[i] from i = 1 to 5:

ini
Copy
Edit
i = 1 → dp[1] += dp[0] → 0 + 1 = 1   → dp = [1, 1, 0, 0, 0, 0]
i = 2 → dp[2] += dp[1] → 0 + 1 = 1   → dp = [1, 1, 1, 0, 0, 0]
i = 3 → dp[3] += dp[2] → 0 + 1 = 1   → dp = [1, 1, 1, 1, 0, 0]
i = 4 → dp[4] += dp[3] → 0 + 1 = 1   → dp = [1, 1, 1, 1, 1, 0]
i = 5 → dp[5] += dp[4] → 0 + 1 = 1   → dp = [1, 1, 1, 1, 1, 1]
We now have 1 way to make each amount using only coin 1.

Next: coin = 2

We update dp[i] from i = 2 to 5:

ini
Copy
Edit
i = 2 → dp[2] += dp[0] → 1 + 1 = 2   → dp = [1, 1, 2, 1, 1, 1]
i = 3 → dp[3] += dp[1] → 1 + 1 = 2   → dp = [1, 1, 2, 2, 1, 1]
i = 4 → dp[4] += dp[2] → 1 + 2 = 3   → dp = [1, 1, 2, 2, 3, 1]
i = 5 → dp[5] += dp[3] → 1 + 2 = 3   → dp = [1, 1, 2, 2, 3, 3]
Now we account for combinations using coins 1 and 2.

Final: coin = 5

We update only i = 5:

ini
Copy
Edit
i = 5 → dp[5] += dp[0] → 3 + 1 = 4   → dp = [1, 1, 2, 2, 3, 4]
Final Result: dp[5] = 4

There are 4 combinations to make amount 5 using coins [1, 2, 5]:

1+1+1+1+1

1+1+1+2

1+2+2

5
*/
