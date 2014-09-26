class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(a.length() == 0)
        {
            return b;
        }
        else if(b.length() == 0)
        {
            return a;
        }
        if(a.length() > b.length())
        {
            int times = a.length() - b.length();
            while(times > 0)
            {
                string temp0 = "0";
                b = temp0+b;
                times --;
            }
        }
        else if(a.length() < b.length())
        {
            int times = b.length() - a.length();
            while(times > 0)
            {
                string temp0 = "0";
                a = temp0+a;
                times --;
            }
        }
        string::reverse_iterator i = a.rbegin();
        string::reverse_iterator j = b.rbegin();
        int next =0;
        string s;
        string digit;
        for ( ;i != a.rend() && j!=b.rend(); ++i,++j)
        {
            int num = *i-'0'+*j -'0'+next;
            if(num >= 2)
            {
                num = num -2;
                next = 1;
            }
            else
            {
                next =0;
            }
            digit = string(1,num+'0');
            s = digit+s;

        }
        if(next != 0)
        {
            digit = string(1,next+'0');
            s = digit+s;
        }
        return s;
        
    }
};