#include <stack>
#include <iostream>
#include <climits>

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
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    std::cout << q.peek() << std::endl;
    q.pop();
    std::cout << q.peek() << std::endl;
    q.push(7);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.peek();
    q.pop();
    return 0;
}

