class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> bs;
        if(tokens.size()==0) return 0;
        for(string a:tokens){
            if(a=="+"){
                int var=bs.top();
                bs.pop();
                var+=bs.top();
                bs.pop();
                bs.push(var);
            }
            else if(a=="-"){
                int var=bs.top();
                bs.pop();
                var=bs.top()-var;
                bs.pop();
                bs.push(var);
            }
            else if(a=="*"){
                int var=bs.top();
                bs.pop();
                var*=bs.top();
                bs.pop();
                bs.push(var);
            }
            else if(a=="/"){
                int var=bs.top();
                bs.pop();
                int temp=bs.top();
                var=temp/var;
                bs.pop();
                bs.push(var);
            }
            else bs.push(stoi(a));
            
            
        }
        return bs.top();

    }
};
