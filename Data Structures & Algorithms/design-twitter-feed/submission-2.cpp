class Twitter {
public:

    unordered_map<int,vector<pair<int,int>>> tmap;
    unordered_map<int, unordered_set<int>> fmap;
    int count=0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tmap[userId].push_back({count++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> maxHeap;
        for(auto tweet:tmap[userId])
            maxHeap.push(tweet);

        for(auto followeeId:fmap[userId]){
            if(followeeId==userId)continue;
            for(auto tweet:tmap[followeeId])
            maxHeap.push(tweet);
        }

        vector<int> feed;

        for(int i=0;i<10 && !maxHeap.empty();i++){
            feed.push_back(maxHeap.top().second);
            maxHeap.pop();

        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        fmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fmap[followerId].erase(followeeId);
    }
};
