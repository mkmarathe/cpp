
/* Design a system to limit the rate at which users or clients can perform
 * actions (e.g., API requests) to prevent abuse and ensure fair resource usage.
 * The rate limiter should enforce rules like "no more than X requests per
 * second per user."
 */
#include <cassert>
#include <chrono>
#include <ctime>
#include <iostream>
#include <queue>
#include <thread>
#include <unordered_map>

using namespace std;
using namespace std::chrono;
class rateLimiter {

    struct rule {
        int maxRequests;
        int windowSeconds;
        // rule() {};
        rule(int maxreq, int winSec)
            : maxRequests(maxreq), windowSeconds(winSec) {}
    };
    unordered_map<string, rule> rules;
    unordered_map<string, queue<time_t>> requestLogs;

  public:
    rateLimiter() {}
    void setConfig(string userId, int maxreq, int winsize) {
        rules.emplace(userId, rule(maxreq, winsize));
        swap(requestLogs["user_id"], queue<time_t>());
    }
    bool isAllowed(string userId) {
        /* make thread safe */
        // see if user id exists , if not its return true
        auto it = rules.find(userId);
        if (it == rules.end())
            return true; // no restrinctions for the user

        auto rule = it->second;
        // trim requestlogs to have only for last winsize seconds
        // requestLogs[userId].push(time(nullptr));
        auto &log = requestLogs[userId];
        auto now = time(nullptr);
        while (!log.empty() && (now - log.front()) > rule.windowSeconds) {
            log.pop();
        }
        // check how many requests registered in the given window
        if (log.size() < rule.maxRequests) {
            log.push(now);
            return true;
        }
        return false;
    }
};

int main() {
    rateLimiter limit;
    limit.setConfig("one", 3, 10);
    assert(limit.isAllowed("one") && "Must be allowed");
    assert(limit.isAllowed("one") && "Must be allowed");
    assert(limit.isAllowed("one") && "Must be allowed");
    assert(!limit.isAllowed("one") && "Must not be allowed");
    cout << "waiting 9 sec" << endl;
    this_thread::sleep_for(chrono::seconds(9));
    assert(!limit.isAllowed("one") && "Must not be allowed");
    cout << "waiting 2 sec" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    assert(limit.isAllowed("one") && "Must be allowed");
    cout << "All Tests passed !!!" << endl;
}
