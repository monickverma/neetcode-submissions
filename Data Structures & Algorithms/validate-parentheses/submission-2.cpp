class Solution {
public:
    bool isValid(string s) {
        
        stack<int> open;
        unordered_map<char,char> parens={{')','('},{']','['},{'}','{'}};

        for(char c:s){
            if(parens.find(c)!=parens.end()){
                if(open.empty()) return false;

                if(open.top()!=parens[c]) return false;

                open.pop();
            }
            else
            open.push(c);
        }
        return open.empty();
    }
};
