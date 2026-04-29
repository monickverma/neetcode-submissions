class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest=0;
        int l=0;
        int maxFreq=0;
        vector<int> counts(26);
        for(int r=0;r<s.size();r++){
            counts[s[r]-'A']++;
            maxFreq = max(maxFreq, counts[s[r] - 'A']);
            while((r-l+1)-maxFreq>k){
                counts[s[l]-'A']--;
                l++;
            }
            longest=max(longest,r-l+1);
        }
        return longest;
    }
};