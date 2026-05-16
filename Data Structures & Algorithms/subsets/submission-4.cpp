class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> currentSubset;
        vector<vector<int>> result;
        backtrack(nums,0,currentSubset,result);
        return result;
        
    }

    void backtrack(vector<int> &nums, int start, vector<int>& currentSubset, vector<vector<int>>& result){
        result.push_back(currentSubset);

        for(int i=start;i<nums.size();i++){
            currentSubset.push_back(nums[i]);
            backtrack(nums,i+1,currentSubset,result);
            currentSubset.pop_back();
        }
    }
    
};
/*
always make trees!
[]
├── [1]
│   ├── [1,2]
│   │   └── [1,2,3]
│   └── [1,3]
├── [2]
│   └── [2,3]
└── [3]
treat each problem as a sub-problem
identitfy what you are doing, 

you naturally first do 1,2,3
then you go beneath 1,2 and 1,3 
you see what you have to do there?
rercursion and pop back to the original 1 then go to 3

Add choice
Explore future
Undo choice
*/
