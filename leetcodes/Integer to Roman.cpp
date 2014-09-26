class Solution {
public:
    string intToRoman(int num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        string result = "";
        int temp = num;
        int n;
        int scale = 100;
        char digit[7] = {'M', 'D', 'C', 'L','X','V','I'};
        if(temp >= 1000 && temp < 4000)
        {
            n = temp/1000;
            result.append(n,'M');
            temp = temp - n*1000;
        }
        int i;
        for(i = 2; i <= 6; i+=2)//IMPORTANT
        {
            if(temp/scale >= 9 && temp/scale < 10 )
            {
                result.append(1,digit[i]);
                result.append(1,digit[i-2]);
                temp = temp - 9*scale;
            }
            if(temp/scale >=5 && temp/scale < 9)
            {
                result.append(1,digit[i-1]);
                temp = temp - 5*scale;
            }
            if(temp/scale >= 4 && temp/scale < 5)
            {
                result.append(1,digit[i]);
                result.append(1,digit[i-1]);
                temp = temp - 4*scale;
            }
            if(temp/scale >= 1 && temp/scale < 4)
            {
                n = temp/scale;
                result.append(n,digit[i]);
                temp = temp - n*scale;
            }
            scale = scale/10;
        }
       
        return result;
    }
};