class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int m= *max_element(piles.begin(),piles.end());

        int low=1; int high=m,res=m;

        while(low<=high){
            int mid= (high - low)/2 + low;

            int totalhours=0;

            for(int i=0;i<n;i++){
                totalhours+=ceil(static_cast<double>(piles[i])/mid);
            }

            if(totalhours<=h){ // a valid may occur being also
                res=mid;
                high=mid-1;
            }
            else{ // rate was too small (totalhours exceeded) look for a faster rate
                low=mid+1;
            }


            
        }
        return res;
        
    }
};