#include <bits/stdc++.h>

void solve(stack<int> &myStack, int x)
{
    // Write your code here.
    // base case
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();

    // recursive call
    solve(myStack, x);

    myStack.push(num);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    solve(myStack, x);

    return myStack;
}
