class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;

        

        for(int a:asteroids){

            bool destroyed = false;

            while(!stk.empty()&& stk.top()>0 && a<0){
                if(abs(stk.top())==abs(a)){
                    stk.pop();
                    destroyed=true;
                    break;
                }
                else if(abs(stk.top())>abs(a))
                {
                    destroyed=true;
                    break;
                }
                else{
                    stk.pop();
                }


            }
            if(!destroyed)stk.push(a);
        }

         vector<int> ans(stk.size());
        for (int i = stk.size() - 1; i >= 0; i--) {
            ans[i] = stk.top();
            stk.pop();
        }
        return ans;
    }
};