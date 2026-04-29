class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> lastIndex;

        for(int i=0;i<s.size();i++){
            lastIndex[s[i]]=i;
        }

        int end=0,start=0;
        vector<int> res;

        for(int i=0;i<s.size();i++){
            start++;
            end=max(end,lastIndex[s[i]]);

            if(i==end){
                res.push_back(start);
                start=0;
            }
        }
        return res;
        
    }
};
