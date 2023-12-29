bool isValidParenthesis(string st)
{
    stack<char> s;
    // Write your code here.
    int n = st.length();
    for (int i = 0; i < n; i++)
    {
        char ch = st[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else
        {
            if (s.empty())
                return false;
            else
            {
                char top = s.top();
                if ((ch == ')' && top == '(') || (ch == ']' && top == '[') ||
                    (ch == '}' && top == '{'))
                    s.pop();
                else
                    return false;
            }
        }
    }

    if (s.empty())
        return true;
    else
        return false;
}
