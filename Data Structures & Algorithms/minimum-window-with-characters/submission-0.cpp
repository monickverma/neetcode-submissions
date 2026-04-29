class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return "";

        // Character frequency maps for t and the current window in s
        vector<int> tcount(128, 0), window(128, 0);
        
        // Populate tcount with the frequency of each character in t
        for (char c : t) {
            tcount[c]++;
        }

        int l = 0, minLen = INT_MAX, start = 0;
        int required = 0; // Total characters to match
        for (int i = 0; i < 128; i++) {
            if (tcount[i] > 0) required++;
        }

        int formed = 0; // Tracks how many characters in the current window match the frequency in tcount

        for (int r = 0; r < s.size(); r++) {
            // Add current character to the window
            window[s[r]]++;

            // If the current character matches its frequency in tcount
            if (window[s[r]] == tcount[s[r]]) {
                formed++;
            }

            // Try to shrink the window from the left
            while (formed == required) {
                // Update the minimum window
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                // Remove the leftmost character
                window[s[l]]--;
                if (window[s[l]] < tcount[s[l]]) {
                    formed--;
                }
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
