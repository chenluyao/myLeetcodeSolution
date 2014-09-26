class Solution {
public:
    string minWindow(string S, string T) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(T.size() == 0||S.size() == 0)
        {
            return "";
        }
        int * expect = new int[256];
        int * appear = new int[256];
        int i;
        int m = S.size();//.size() is unsigned, can't use for compare directly
        int n = T.size();
        memset(expect, 0 ,256*sizeof(int));
        memset(appear, 0, 256*sizeof(int));
        int expectTotal = 0;
        for(i = 0; i < n; i++)
        {
            expect[T[i]]++;
            expectTotal++;
        }
        string result = "";
        int start = 0;
        int end = -1;

        while(true)
        {
            while(start < m && expect[S[start]] == 0 )
            {
                appear[S[start]] --;
                start++;
            }
            if(end < start)
            {
                end = start -1;
            }
            if(start == m)
            {
                break;
            }
            while(end < m-1 && expectTotal > 0)
            {
                end++;
                appear[S[end]] ++;
                if(expect[S[end]] > 0 && expect[S[end]] >= appear[S[end]])// >0 is important
                {
                    expectTotal--;
                }
            }
            if(expectTotal == 0)
            {
                string sub = S.substr(start, end-start+1);
                if(result == "" || sub.size() < result.size())
                {
                    result = sub;
                }
            }
            /*if(end == m-1)
            {
                break;
            }*///can set end as a end condition
            
            appear[S[start]]--;
            if(appear[S[start]] < expect[S[start]])
            {
                expectTotal++;
            }
            
            start++;
        }
        return result;
        
        
    }
};