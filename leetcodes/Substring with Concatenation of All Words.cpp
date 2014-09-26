class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> result;
        int m = L.size();
        if(m == 0)
        {
            return result;
        }
        map<string, int> expect;
        map<string, int> appear;
        int i;
        int j;
        int wordCount = 0;
        for(i = 0; i < m; i++)
        {
            expect[L[i]]++;
            wordCount++;
        }
        int len = S.size();
        int wordLen = L[0].size();
        //how to deal with S="", L = [""]?
        
        for(i = 0; i <= len-wordLen*wordCount; i++)
        {
            appear.clear();
            for(j = 0; j < wordCount; j++)
            {
                string temp = S.substr(i+j*wordLen,wordLen);
                appear[temp]++;
                if(expect[temp] <= 0 || appear[temp] > expect[temp])//can't find or have more than once
                {
                    break;
                }
            }
            if(j == wordCount)//successful
            {
                result.push_back(i);
            }
        }
        return result;
    }
};