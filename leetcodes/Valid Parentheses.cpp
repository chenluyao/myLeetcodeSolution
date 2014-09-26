class Solution {
public:
    char reverse(char c)
    {
        if(c == '(')
        {
            return ')';
        }
        if(c == '[')
        {
            return ']';
        }
        if(c == '{')
        {
            return '}';
        }
    }
    bool isValid(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = s.size();
        if(m == 0)
        {
            return true;
        }
        stack<char> st;
        int i;
        for(i = 0; i < m; ++i)
        {
            if(s[i] == '('|| s[i] == '['||s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty() || reverse(st.top()) != s[i])
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
        }
        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};