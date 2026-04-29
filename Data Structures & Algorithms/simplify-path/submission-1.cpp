class Solution {
public:
    string simplifyPath(string path) {
        

        stack<string> stk;

        string curr="";

        for(int i=0;i<=path.size();i++){

            if(i==path.size() || path[i]=='/' ){
                if(curr=="" || curr=="."){
                    //do nothing
                }
                else if(curr==".." ){
                    if(!stk.empty())
                    stk.pop();
                }
                else{
                    stk.push(curr);
                }
                curr="";
            }
            else{
                curr+=path[i];
            }
        }

        string res = "";
        while (!stk.empty()) {
            res = "/" + stk.top() + res;
            stk.pop();
        }

        return res.empty() ? "/" : res;
    }
};