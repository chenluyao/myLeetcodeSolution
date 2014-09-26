class Solution {
public:
    bool containSameChar(string s1, string s2)
    {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return (s1==s2);
    }
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //null string
        if(s1.size()!= s2.size())
        {
            return false;
        }
        if(s1.size() == 1)
        {
            return (s1[0] == s2[0]);
        }
        //>=1 string
        for(int i = 0;i < s1.size()-1;i++)
        {
            
            //try to find a partition
            string s1_part1 = s1.substr(0,i+1);
            string s1_part2 = s1.substr(i+1);
            bool result = false;
            if(containSameChar(s2.substr(0,i+1),s1_part1) && containSameChar(s2.substr(i+1),s1_part2))
            {
                 result = (isScramble(s2.substr(0,i+1),s1_part1) && isScramble(s2.substr(i+1),s1_part2));
                 if(result == true)
                 {
                     return true;
                 }
            }
            else if(containSameChar(s2.substr(s2.size()-1-i,i+1),s1_part1) && containSameChar(s2.substr(0,s2.size()-1-i),s1_part2))
            {
                result = (isScramble(s2.substr(s2.size()-1-i,i+1),s1_part1) && isScramble(s2.substr(0,s2.size()-1-i),s1_part2));
                if(result == true)
                {
                    return true;
                }
            }
        }
        return false;
            
        
    }
};