class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> current;
        vector<vector<int>> res;
        dfs(candidates, target,0,current,res);
        return res;
    }

    void dfs(vector<int>& candidates, int target, int index, vector<int>& current, vector<vector<int>>& res){
        if(target==0){
            res.push_back(current);
            return;
        }
        if(target<0) return;

        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1])continue;

            if(candidates[i]>target) break;

            current.push_back(candidates[i]);
            dfs(candidates, target-candidates[i],i+1,current,res);
            current.pop_back();
            
        }

    }
};
