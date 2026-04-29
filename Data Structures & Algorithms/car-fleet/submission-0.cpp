class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
vector<pair<int,double>> pair;
for(int i=0;i<position.size();i++)
pair.push_back({position[i],(double)(target-position[i])/speed[i]});
sort(pair.rbegin(),pair.rend());
stack<double>stack;
int fleet=0;
for(int i=0;i<pair.size();i++){
double time=pair[i].second;
if(stack.empty()|| time>stack.top()){
fleet++;
stack.push(time);
}

}
return fleet;
}

};
