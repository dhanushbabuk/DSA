#include <bits/stdc++.h>
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '*' || ch == '-' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            // meaning close bracket or small case letters

            if (ch == ')')
            {
                bool isredunant = true;

                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '*' || top == '-' || top == '/')
                        isredunant = false;
                    //  operator is poped
                    st.pop();
                }
                // open bracket is poped

                if (isredunant == true)
                    return true;
                st.pop();
            }
        }
    }
    return false;
}
