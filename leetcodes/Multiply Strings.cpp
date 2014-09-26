class Solution {
public:
    string multiply(string num1, string num2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = num1.size();
        int n = num2.size();
        if(m == 0 || n == 0)
        {
            return "";
        }
        string res(m+n+1,'0');
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int i;
        int j;
        int carry;
        for(i = 0; i < num1.size(); i++)
        {
            int digit1 = num1[i]-'0';
            //carry = 0;
            if(digit1 != 0)
            {
                for(j = 0; j < num2.size(); j++)
                {
                    int digit2 = num2[j]-'0';
                    int result = digit1 * digit2;
                    res[i+j] += result%10;
                    res[i+j+1] += result/10;
                    if(res[i+j] > '9')
                    {
                        res[i+j+1] += (res[i+j] - '0')/10;
                        res[i+j] = (res[i+j]-'0')%10+'0';
                    }
                }
            }
        }
        i = m+n-1;
        while(i <= m+n)
        {
            res[i+1] += (res[i] - '0')/10;
            res[i] = (res[i]-'0')%10+'0';
            i++;
        }
        reverse(res.begin(),res.end());
        i = 0;
        int k = res.size();
        while(res[i] == '0' && i < k)
        {
            i++;
        }
        if(i == k)
        {
            return "0";
        }
        else
        {
            return res.substr(i,k-i);
        }
    }
};