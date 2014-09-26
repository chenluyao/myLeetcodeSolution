class Solution {
public:
    string simplifyPath(string path) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = path.size();
        if(m == 0)
        {
            return "/";
        }
        stack<string> stk;
        int i;
        int left = 0;
        int right = -1;
        for(i = 0; i < m; ++i)
        {
            if(path[i] == '/' && i+1 < m && path[i+1] != '/')
            {
                left = i+1;
            }
            else if(path[i] != '/' && (i == m-1 || path[i+1] == '/'))
            {
                right = i;
                string s = path.substr(left,right-left+1);
                if(s == ".")
                {}
                else if(s == "..")
                {
                    if(!stk.empty())
                    {
                        stk.pop();
                    }
                }
                else
                {
                    stk.push(s);
                }
            }
        }
        string re="";
        if(stk.empty())
        {
            return "/";
        }
        while(!stk.empty())
        {
            string temp = "/";
            temp.append(stk.top());
            stk.pop();
            temp.append(re);
            re = temp;
        }
        return re;
    }
};