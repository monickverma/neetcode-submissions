class Solution {
public:
    int climbStairs(int n) {

        /*
        n=1->1
        n=5, 2 step or 1 steps

        n=2 return me 2
        
        n=0
        */
    if(n==1) return 1;
    if(n==2) return 2;

    return climbStairs(n-1)+climbStairs(n-2);
        
    }
};
