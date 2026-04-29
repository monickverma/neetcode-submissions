class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26);
        for(char c:s1)
            freq1[c-'a']++;
        
        
        int l=0;
        for(int r=0;r<s2.size();r++){
            if (r-l+1>s1.size()) l++;
             vector<int> freq2(26);
        for(char c:s2.substr(l,r-l+1))
            freq2[c-'a']++;
            if(freq1==freq2) return true;
        }
        return false;
            
            
    }
};