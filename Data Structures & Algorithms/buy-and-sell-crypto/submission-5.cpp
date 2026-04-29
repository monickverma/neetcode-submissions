class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp=0,maxp=1;
        int max_diff=0;
            
        while(maxp<prices.size()){
            
            if(prices[minp]<prices[maxp])
                max_diff=max(max_diff,prices[maxp]-prices[minp]);
            else minp=maxp;

            maxp++;
        }
        return max_diff;

        
    }
};
