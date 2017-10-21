#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

typedef int UID;

class Twitter {
    public:
        class Post {
            private:
                UID _id;
                UID _userId;
                unsigned _time;

            public:
                Post(UID tweetId, UID userId, unsigned time):
                    _id(tweetId),
                    _userId(userId),
                    _time(time) {
                }

                UID getId() const {
                    return _id;
                }

                bool operator>(const Post& post) const {
                    return this->_time > post._time;
                }
        };

        class User {
            private:
                UID _id;
                std::unordered_set<User*> _followees;
                std::list<Post*> _newsfeed;
                unsigned _newsfeedCapacity;

            public:
                User(UID id, unsigned newsfeedCapacity=10):
                    _id(id),
                    _newsfeedCapacity(newsfeedCapacity) {
                }

                void post(Post* post) {
                    _newsfeed.push_front(post);
                    this->cleanupNewsfeed();
                }

                void cleanupNewsfeed() {
                    if (_newsfeed.size() > _newsfeedCapacity) {
                        _newsfeed.pop_back();
                    }
                }

                void addFollowee(User* followee) {
                    _followees.insert(followee);
                }

                void removeFollowee(User* followee) {
                    _followees.erase(followee); 
                }

                std::vector<UID> getNewsFeed() const {
                    auto comp = [](const Post* left, const Post* right) { 
                        return *left > *right;
                    }; 

                    std::priority_queue<Post*, std::vector<Post*>, decltype(comp)> 
                        newsfeedMinPQ{comp};
                    for (auto post:_newsfeed) {
                        newsfeedMinPQ.push(post);
                    }
                    for (auto followee:_followees) {
                        for (auto post:followee->_newsfeed) {
                            newsfeedMinPQ.push(post);
                            if (newsfeedMinPQ.size() > _newsfeedCapacity) {
                                newsfeedMinPQ.pop();
                            }
                        }
                    }

                    std::vector<int> news{};
                    while (!newsfeedMinPQ.empty()) {
                        news.push_back(newsfeedMinPQ.top()->getId());
                        newsfeedMinPQ.pop();
                    }
                    std::reverse(news.begin(), news.end());

                    return news;
                }
        };

        /** Initialize your data structure here. */
        Twitter() {

        }

        User* getUser(int userId) {
            User* user = nullptr;
            auto userIt = users.find(userId);
            if (userIt == users.end()) {
                user = new User(userId);
                users[userId] = user;
            }
            else {
                user = userIt->second;
            }
            return user;
        }

        /** Compose a new tweet. */
        void postTweet(int userId, int tweetId) {
            User* user = getUser(userId);
            Post* post = new Post{tweetId, userId, currentTime++};
            user->post(post);
        }

        /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
        vector<int> getNewsFeed(int userId) {
            return getUser(userId)->getNewsFeed();
        }

        /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
        void follow(int followerId, int followeeId) {
            if (followerId == followeeId) return;
            User* follower = getUser(followerId);
            User* followee = getUser(followeeId);
            follower->addFollowee(followee);
        }

        /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
        void unfollow(int followerId, int followeeId) {
            if (followerId == followeeId) return;
            User* follower = getUser(followerId);
            User* followee = getUser(followeeId);
            follower->removeFollowee(followee);
        }

    private:
        std::unordered_map<UID, User*> users;
        unsigned currentTime = 0;
};

int main() {
    Twitter twitter = Twitter();

    // User 1 posts a new tweet (id = 5).
    twitter.postTweet(1, 5);

    // User 1's news feed should return a list with 1 tweet id -> [5].
    twitter.getNewsFeed(1);

    // User 1 follows user 2.
    twitter.follow(1, 2);
    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    twitter.getNewsFeed(1);

    // User 2 posts a new tweet (id = 6).
    twitter.postTweet(2, 6);

    // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
    // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
    twitter.getNewsFeed(1);
    twitter.getNewsFeed(2);

    // User 1 unfollows user 2.
//    twitter.unfollow(1, 2);
    twitter.unfollow(2, 1);
    twitter.getNewsFeed(1);
    twitter.getNewsFeed(2);

    twitter.unfollow(1, 2);
    // User 1's news feed should return a list with 1 tweet id -> [5],
    // since user 1 is no longer following user 2.
    twitter.getNewsFeed(1);
    twitter.getNewsFeed(2);

    return 0;
}

