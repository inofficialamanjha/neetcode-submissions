class Twitter {
public:
    unordered_map<int, set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int timestamp;

    struct Tweet {
        int userId;
        int tweetId;
        int time;
        int index;
    };

    struct Compare {
        bool operator()(const Tweet& a, Tweet& b) {
            return a.time < b.time; // min heap by time
        }
    };

    Twitter() {
       timestamp = 0; 
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp, tweetId});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet, vector<Tweet>, Compare> pq;

        if (!tweets[userId].empty()) {
            int i = tweets[userId].size();
            pq.push({
                userId,
                tweets[userId][i-1].second,
                tweets[userId][i-1].first,
                i-1
            });
        }

        for(auto follower: followers[userId]) {
            if (!tweets[follower].empty()) {
                int i = tweets[follower].size();
                pq.push({
                    follower,
                    tweets[follower][i-1].second,
                    tweets[follower][i-1].first,
                    i-1
                });
            }
        }

        vector<int> ans;

        for(int i=0; i<10; i++) {
            if (pq.empty()) {
                break;
            }

            Tweet top = pq.top();
            pq.pop();

            if (top.index>0) {
                pq.push({
                    top.userId,
                    tweets[top.userId][top.index - 1].second,
                    tweets[top.userId][top.index - 1].first,
                    top.index - 1
                });
            }

            ans.push_back(top.tweetId);
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
