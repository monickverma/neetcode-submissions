class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int max_area=0;
        for(int i=0;i<n;i++){
            int height=heights[i];
            int right_most=i+1;
            while(right_most<n && heights[right_most]>=height) right_most++;
            int left_most=i;
            while(left_most>=0 && heights[left_most]>=height) left_most--;
            right_most--;left_most++;
            max_area=max(max_area,height*(right_most-left_most+1));
        }
        return max_area;

    }
};