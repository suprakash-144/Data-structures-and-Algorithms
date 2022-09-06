#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <stack>

using namespace std;
int prex(char c)
{
    switch (c)
    {
    case '^':
        return 3;
        break;
    case '-' or '+':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;

    default:
        return -1;
        break;
    }
}
string infixtoprefix(string s)
{
    reverse(s.begin(), s.end());
    stack<char> st;
    string res;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a') and (s[i] <= 'z') or (s[i] >= 'A') and (s[i] <= 'Z'))
        {
            res += s[i];
        }
        else if (s[i] == ')')
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            while (st.top() != ')')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() and (prex(st.top()) >= prex(s[i])))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

int main()
{
    cout << "infex to prefix" << endl;
    string s = "(a+b/c)-(d*b+c)";
    cout << s << endl;
    s = infixtoprefix(s);
    cout << s;
    return 0;
}
