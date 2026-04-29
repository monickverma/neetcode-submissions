class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(hand.size()%groupSize!=0)return false;
        int nog=hand.size()/groupSize;
        vector<vector<int>> grps;
        sort(hand.begin(),hand.end());
        for(int i=0;i<n;i++){
            bool flag=false;
            for(auto& grp:grps){
                if(grp.size()==groupSize) continue;
                if(grp.empty()) {flag=true;grp.push_back(hand[i]);break;}
                else if(grp.back()+1==hand[i]) {flag=true;grp.push_back(hand[i]);break; }

            }
            if(!flag) grps.push_back({hand[i]});
        }

        for(auto &grp:grps){
            if(grp.size()!=groupSize)return false;
        }
        return true;
    }
};
