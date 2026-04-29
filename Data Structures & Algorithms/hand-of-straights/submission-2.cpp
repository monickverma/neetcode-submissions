class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        unordered_map<int,int> count;

        for(int hnd:hand){
            count[hnd]++;
        }


        sort(hand.begin(),hand.end());
        for(int hnd:hand){
            if(count[hnd]>0){
                for(int i=hnd;i<hnd+groupSize;i++){
                    if(count[i]==0) return false;
                    count[i]--;
                }
            }
        }
        return true;
    }
};
