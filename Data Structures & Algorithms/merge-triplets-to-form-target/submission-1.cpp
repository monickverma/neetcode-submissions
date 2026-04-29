class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        vector<int> maxtriplet= triplets[0];

        for(int i=1;i<triplets.size();i++){
            if(triplets[i][0]>target[0] || triplets[i][1]>target[1] || triplets[i][2]>target[2]) continue;
            maxtriplet[0]= max(triplets[i][0],maxtriplet[0]);
            maxtriplet[1]= max(triplets[i][1],maxtriplet[1]);
            maxtriplet[2]= max(triplets[i][2],maxtriplet[2]);

        }

        if(maxtriplet==target) return true;
        return false;
        
    }
};
