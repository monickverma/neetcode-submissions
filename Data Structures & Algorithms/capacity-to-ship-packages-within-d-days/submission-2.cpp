class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int r=accumulate(weights.begin(),weights.end(),0);
        int res=r;
        while(l<=r){
            int mid= (l+r)/2;
            if(canShip(weights,days,mid)){
                res=min(res,mid);
                r=mid-1;
            }
            else l=mid+1;
        }
        return res;
    }
private:
    bool canShip(vector<int>& weights, int days,int cap){
        int currCap=cap,ships=1;

        for(int w:weights){
            if(currCap- w<0){
                ships++;
                if(ships>days) return false;
                currCap=cap;
            }
            currCap-=w;
        }
        return true;
    }
};