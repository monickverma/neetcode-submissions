class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> freq;

        for(char c:s)
            freq[c]++;
        
        priority_queue<pair<int,char>> pq;

        for( auto it:freq)
            pq.push({it.second,it.first});
        
        string res="";
        pair<int,char> prev={0,'#'};
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();

            res+=curr.second;

            curr.first--;
            if(prev.first>0)pq.push(prev);
            prev=curr;
        }

        if(res.length()!=s.length()) return "";
        return res;
    }
};