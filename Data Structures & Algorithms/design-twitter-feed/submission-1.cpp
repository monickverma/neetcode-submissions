class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>> tmap;
    //        user id, (time, tweeId)
    unordered_map<int, unordered_set<int>> fmap;
    //            userID, followee ID

    int count=0;
    Twitter() {
        
    }
    void postTweet(int userId, int tweetId) {
        tmap[userId].push_back({count++,tweetId});
        
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> maxheap;

        //get the users tweets
        for(auto tweet:tmap[userId]){
            maxheap.push({tweet.first,tweet.second});
        }

        for(auto followeeId:fmap[userId]){
            if (followeeId == userId) continue; 
            for(auto tweet: tmap[followeeId])
            maxheap.push(tweet);
        }

        vector<int> feed;

        for(int i=0;i<10 && !maxheap.empty();i++){
            feed.push_back(maxheap.top().second);
            maxheap.pop();
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
