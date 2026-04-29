class Solution {
public:
    string decodeString(string s) {

        stack<pair<string,int>> stk;

        int num=0;
        string curr="";

        for(char c:s){

            if(isdigit(c)){
                num=num*10 + (c-'0');
            }
             else if (c == '[') {
                stk.push({curr, num});
                curr = "";
                num = 0;
            }
            else if(c==']'){
                auto [prev,repeat]=stk.top();
                stk.pop();
                string temp = "";
                while (repeat--) temp += curr;

                curr = prev + temp;


            }
            else{
                curr+=c;
            }
        }
        return curr;
        
    }
};