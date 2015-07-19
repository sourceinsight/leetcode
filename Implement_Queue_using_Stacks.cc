/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, 
and is empty operations are valid.
Depending on your language, stack may not be supported natively. 
You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

class Queue 
{
public:
    // Push element x to the back of queue.
    void push(int x) 
    {
        s1_.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) 
    {
        helper(s1_, s2_);
        s2_.pop();
        helper(s2_, s1_);
    }

    // Get the front element.
    int peek(void) 
    {
        helper(s1_, s2_); 
        int ret = s2_.top();
        helper(s2_, s1_);
        return ret;
    }

    // Return whether the queue is empty.
    bool empty(void) 
    {
        return s1_.empty();    
    }
private:
    void helper(stack<int>& lhs, stack<int>& rhs)
    {
        while (!lhs.empty())
        {
            rhs.push(lhs.top());
            lhs.pop();
        }
    }
    stack<int> s1_;
    stack<int> s2_;
};
