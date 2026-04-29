class Solution {
public:
bool isValid(string s){
    stack<char> stack;
    for(char a:s){
        if(a=='0'){
            if(stack.empty()) return false;
            if(stack.top()!='1') return false;
            stack.pop();
        }
        else
        stack.push(a);

    }
    return stack.empty();

}
    vector<string> generateParenthesis(int n)
{
    vector<string> res;
    int ns=n*2;
    int totalComninations = 1 << (ns);
    for (int i = 0; i < totalComninations; i++)
    {
        bitset<30> paren(i);
        string parens=paren.to_string().substr(30-ns);
        if(isValid(parens)){
            string s="";
            for(char x:parens)
                if(x=='0')
                s+=')';
                else
                s+='(';
        res.push_back(s);

        }
    }
    return res;
    
}
};
