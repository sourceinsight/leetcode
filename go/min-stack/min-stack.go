package min_stack

/*
Design a stack that supports push, pop, top,
and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

type MinStack struct {
    stack []int
    minst []int // 保存最小值的栈
}

/** initialize your stack structure here. */
func Constructor() MinStack {
    return MinStack{
        stack: []int{},
        minst: []int{},
    }
}

func (this *MinStack) Push(x int) {
    if len(this.minst) == 0 {
        this.minst = append(this.minst, x)
    } else if x <= this.GetMin() { // 等号必须有
        this.minst = append(this.minst, x)
    }

    this.stack = append(this.stack, x)
}

func (this *MinStack) Pop() {
    if len(this.stack) > 0 {
        if this.Top() == this.GetMin() {
            this.minst = this.minst[:len(this.minst)-1]
        }
        this.stack = this.stack[:len(this.stack)-1]
    }
}

func (this *MinStack) Top() int {
    return this.stack[len(this.stack)-1]
}

func (this *MinStack) GetMin() int {
    return this.minst[len(this.minst)-1]
}
