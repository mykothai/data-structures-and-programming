// This code not written by me: priority_queue code found at link below
// std::priority_queue
// https://en.cppreference.com/w/cpp/container/priority_queue

#include <queue>
using namespace std;

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
}
