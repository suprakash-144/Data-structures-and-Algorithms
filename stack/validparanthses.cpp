#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;
bool check(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' or s[i] == '(' or s[i] == '[')
        {
            st.push(s[i]);
        }
        else if ((st.empty()) or (st.top() == '[' and s[i] != ']') or
                 (st.top() == '{' and s[i] != '}') or (st.top() == '(' and s[i] != ')'))
        {
            return false;
        }
        else
        {
            st.pop();
        }
    }

    return st.empty() ? true : false;
}
int main()
{
    string s;
    cout << "Enter pranthases: ";
    cin >> s;
    if (check(s))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    return 0;
}