class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> result;
        string s;
        
        int n = words.size();
        int sum = -1;//!!!can't be 0,may have ""
        int start = -1;
        int end = -1;
        int k;
        int i;
        for(i = 0; i < n; i++)
        {
            if(sum == -1)//first
            {
                sum = words[i].size();
                start = i;
            }
            else// no need to judge because last round has checked
            {
                sum = sum + words[i].size() + 1;
            }
            if(i+1 < n && sum + (int)words[i+1].size() + 1 > L)// have checked;if end, will break soon
            {
                //make a line
                end = i;
                if(end == start)
                {
                    //line with one word
                    s = "";
                    s.append(words[start]);
                    int len = words[start].size();
                    s.append(L-len,' ');
                    result.push_back(s);
                }
                else
                {
                    //base 1 space;
                    int * spaceSlot = new int[end-start];
                    int delta = L-sum;
                    for(i = 0; i < end-start; i++)
                    {
                        spaceSlot[i] = 1 + delta/(end-start);
                    }
                    delta = delta % (end - start);
                    for(i = 0; i < end-start; i++)
                    {
                        if(delta == 0)
                        {
                            break;
                        }
                        spaceSlot[i]++;
                        delta --;
                    }
                    s = "";
                    for(i = start; i < end; i++)
                    {
                        s.append(words[i]);
                        s.append(spaceSlot[i-start],' ');
                    }
                    s.append(words[end]);
                    result.push_back(s);
                    
                }
                sum = -1;
            }
            else if(i == n-1)//last line!!IMPORTANT
            {
                end = i; //!!!
                s = "";
                int len = 0;
                for(i = start; i < end; i++)
                {
                    s.append(words[i]);
                    s.append(1,' ');
                    len = len + words[i].size()+1;
                }
                s.append(words[end]);
                len = len + words[end].size();
                s.append(L-len,' ');
                result.push_back(s);
                sum = -1;
            }
                //

        
        }
        return result;
        
    }
};