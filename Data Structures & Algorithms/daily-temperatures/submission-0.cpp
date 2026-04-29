class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
stack<pair<int,int>> stack;
vector<int> res(temp.size(),0);
for(int i=0;i<temp.size();i++){
int t=temp[i];
while(!stack.empty() && t>stack.top().first){
auto pair=stack.top();
stack.pop();
res[pair.second]=i-pair.second;
}
stack.push({t,i});

}
return res;

}
};
