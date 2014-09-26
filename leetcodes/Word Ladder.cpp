class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(start.size()!=end.size())
        {
            return 0;
        }
        if(start.size() == 0 && end.size() == 0)
        {
            return 1;
        }
        queue<string> readQ;
        queue<string> writeQ;
        int i;
        int j;
        readQ.push(start);
        int distance = 1;
        while(!readQ.empty() &&dict.size() > 0)
        {
            while(!readQ.empty())
            {
                string str = readQ.front();
                readQ.pop();
                string saveS = str;
                for(i = 0; i < str.size(); i++)
                {
                    char c = str[i];
                    for(j = 'a'; j <= 'z'; j++)
                    {
                        if(j!=c)
                        {
                            str[i] = j;
                            if(str == end)
                            {
                                return distance+1;//
                            }
                            if(dict.find(str) != dict.end())
                            {
                                writeQ.push(str);
                                dict.erase(str);
                                
                            }
                            
                        }
                    }
                    str = saveS;
                }
            }
            readQ.swap(writeQ);
            distance ++;
        }
        return 0;
    }
};