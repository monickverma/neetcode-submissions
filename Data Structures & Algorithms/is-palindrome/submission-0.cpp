class Solution {
public:
    bool isPalindrome(string s) {
   bool flag = true;
    string filtered = "";
    for (int i = 0; i < s.length(); i++)
        if (isalnum(s[i]))
            filtered += tolower(s[i]);
        
    

    for (int i = 0; i < filtered.length() / 2; i++)
        if (filtered[i] != filtered[filtered.length() - 1 - i])
        {
            flag = false;
            break;
        }

    return flag; 
    }
};
