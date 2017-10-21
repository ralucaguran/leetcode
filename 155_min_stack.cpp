#include <stack>
#include <iostream>

using namespace std;


class MinStack {

    private:
        stack<int> theStack;
        stack<int> theMinStack;

    public:
        MinStack() {
        }

        void push(int x) {
            if (theStack.empty()) {
                theMinStack.push(x);
            }
            else {
                theMinStack.push(min(x, theMinStack.top()));
            }
            theStack.push(x);
        }

        void pop() {
            theStack.pop();
            theMinStack.pop();
        }

        int top() {
            return theStack.top();
        }

        int getMin() {
            return theMinStack.top();
        }
};


int main() {
    MinStack obj;
    obj.push(-1);
    obj.push(2);
    obj.push(-5);
    obj.push(-9);
    obj.push(3);
    obj.push(-9);
    obj.pop();
    obj.pop();
    obj.pop();
    cout << obj.top() << endl;
    cout << obj.getMin() << endl;
    return 0;
}

