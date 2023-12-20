
void insertAtBottom(stack<int> &stack, int num)
{
    if (stack.empty())
    {
        stack.push(num);
        return;
    }
    int ele = stack.top();
    stack.pop();

    insertAtBottom(stack, num);

    stack.push(ele);
}

void reverseStack(stack<int> &stack)
{
    // Write your code here
    if (stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();
    // recuscive call for reversing stack of n-1 except top element
    reverseStack(stack);
    // insert top element at the bottom of stack
    insertAtBottom(stack, num);
}