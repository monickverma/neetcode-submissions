class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> edges;
        for (auto& time : times) {
            edges[time[0]].emplace_back(time[1], time[2]);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, k});

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while (!minHeap.empty()) {
            auto [time, node] = minHeap.top(); minHeap.pop();
            if (dist[node] < time) continue;

            for (auto [nei, w] : edges[node]) {
                if (time + w < dist[nei]) {
                    dist[nei] = time + w;
                    minHeap.push({dist[nei], nei});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};
