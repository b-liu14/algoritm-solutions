/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (39.67%)
 * Likes:    2661
 * Dislikes: 275
 * Total Accepted:    417.2K
 * Total Submissions: 1M
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 * 
 * 
 */

#include <stack>
using namespace std;

// @lc code=start
class MinStack {
private:
    long long min;
    stack<long long> s;

public:
    /** initialize your data structure here. */
    MinStack() {
        min = 0;
    }

    void push(int x) {
        if (s.empty()) {
            min = x;
            s.push(0);
        } else {
            s.push(x - min);
            if (x < min) {
                min = x;
            }
        }
    }

    void pop() {
        long long top = s.top();
        s.pop();
        if (top < 0) {
            min = min - top;
        }
    }

    int top() {
        long long top = s.top();
        if (top >= 0) {
            return top + min;
        } else {
            return min;
        }
    }

    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
