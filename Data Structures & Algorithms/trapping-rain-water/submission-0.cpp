class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int res=0;
        for(int i=0;i<n;i++){
            int left_max=height[i];
            int right_max=height[i];
            for(int j=0;j<i;j++) left_max=max(height[j],left_max);
            for(int j=i+1;j<n;j++) right_max=max(height[j],right_max);
            res+= min(left_max,right_max)-height[i];
        }
        return res;
        
    }
};
