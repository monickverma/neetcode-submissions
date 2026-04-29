class Solution {
public:
    unordered_map<int,int> memo;
    int tribonacci(int n) {

        if(memo.count(n))return memo[n];
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        memo[n]= tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
        return memo[n];

    }
};