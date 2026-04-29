class Solution {
public:
    vector<string> generateParenthesis(int n)
{
    vector<string> res;
    backtrack(n,0,0,"",res);
    return res;
    
}

void backtrack(int n, int openN,int closeN,string current, vector<string> & res){
    if(openN==n && closeN==n){
        res.push_back(current);
        return;
    }
    if(openN<n)
    backtrack(n,openN+1,closeN,current+"(",res);
    if(closeN<openN)
    backtrack(n,openN,closeN+1,current+")",res);
}
};
