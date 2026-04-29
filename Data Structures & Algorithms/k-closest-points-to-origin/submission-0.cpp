class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> heap;

        for(auto point: points) {
            int x = point[0], y = point[1];
            int distance = pow(x, 2) + pow(y, 2);
            heap.push({distance, {x, y}});
        }

        vector<vector<int>> result;
        while (k-- > 0 && !heap.empty()) {
            auto top = heap.top().second;
            result.push_back({top.first, top.second});
            heap.pop();
        }

        return result;
    }
};
