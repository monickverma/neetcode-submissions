class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26),freq2(26);
        for(char c:s1)
            freq1[c-'a']++;
        
        for(int r=0;r<s1.size();r++)
            freq2[s2[r]-'a']++;
        
        if(freq1==freq2) return true;
        
        for(int r=s1.size();r<s2.size();r++){
            freq2[s2[r]-'a']++;
            freq2[s2[r-s1.size()]-'a']--;
            
        if(freq1==freq2) return true;
        }
        return false;
            
            
    }
};