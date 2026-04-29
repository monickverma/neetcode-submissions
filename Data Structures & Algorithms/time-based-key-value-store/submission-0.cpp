class TimeMap
{
public:
    TimeMap()
    {
    }

    unordered_map<string, vector<pair<int, string>>> mp;
    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        if (mp.find(key) == mp.end())
            return "";

        vector<pair<int, string>> &ans = mp[key];

        // binary search the timestamp
        int l = 0;
        int r = ans.size()-1;
        int mid;
        string result="";
        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if (ans[mid].first <= timestamp)
            {
                result = ans[mid].second; 
                l = mid + 1;              
            }
            else
            {
                r = mid - 1; 
            }
        }

        return result; 
    }
};