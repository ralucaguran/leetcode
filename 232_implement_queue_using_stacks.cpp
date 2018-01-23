#include <stack>
#include <climits>
#include <assert.h>

class MyQueue {
    private:
        std::stack<int> revStack;

    public:
        /** Initialize your data structure here. */
        MyQueue() {
            
        }

        /** Push element x to the back of queue. */
        void push(int x) {
            std::stack<int> heyStack;
            while (!revStack.empty()) {
                heyStack.push(revStack.top());
                revStack.pop();
            }
            heyStack.push(x);
            while (!heyStack.empty()) {
                revStack.push(heyStack.top());
                heyStack.pop();
            } 
        }

        /** Removes the element from in front of queue and returns that element. */
        int pop() {
            if (!revStack.empty()) {
                int top = revStack.top();
                revStack.pop();
                return top;
            }
            return INT_MIN;
        }

        /** Get the front element. */
        int peek() {
            if (!revStack.empty()) {
                return revStack.top();
            }
            return INT_MIN;
        }

        /** Returns whether the queue is empty. */
        bool empty() {
            return revStack.empty();
        }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

int main() {
    MyQueue q = MyQueue();
    for (int i = 1; i < 6; i++) {
        q.push(i);
    }
    q.pop();
    assert(q.peek() == 2);
    q.pop();
    assert(q.peek() == 3);
    assert(!q.empty());
    q.push(7);
    for (int i = 0; i < 7; i++) {
        q.pop();
    }
    assert(q.peek() == INT_MIN);
    assert(q.empty());
    return 0;
}

