/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack 
{
public:
    void push(int x) 
    {
        stack_.push(x);
        if (x <= getMin())
        {
            minStack_.push(x);
        }
    }

    void pop() 
    {
        if (!stack_.empty())
        {
            if (stack_.top() == minStack_.top())
            {
                minStack_.pop();
            }
            stack_.pop();
        }
    }

    int top() 
    {
        return stack_.top();
    }

    int getMin() 
    {
        if (!minStack_.empty())
        {
            return minStack_.top();
        }
        return INT_MAX;
    }
private:
    stack<int> stack_;
    stack<int> minStack_;
};
