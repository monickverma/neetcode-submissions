class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

       unordered_map<int,int> counts(nums.size());

        for(int num:nums){
            counts[num]++;
        }

        vector<int> result;
        for(auto count:counts){
            if(count.second>(nums.size()/3))
            result.push_back(count.first);
        }
        return result;
        
    }
};