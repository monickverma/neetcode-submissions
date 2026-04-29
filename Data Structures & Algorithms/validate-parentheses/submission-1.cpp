class Solution {
public:
    
    bool isValid(string s) {
stack<char> open;
unordered_map<char,char> parens={{')','('},{'}','{'},{']','['}};
for(char c:s){
if(parens.find(c)!=parens.end())//this just means ki close bracket is present
{
if(open.empty()) return false;
if(open.top()!= parens[c]) return false;
open.pop();
}
else{
open.push(c);
}
}
return open.empty(); }
};
