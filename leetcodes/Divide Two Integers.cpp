class Solution {
public:
    int divide(int dividend, int divisor) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(dividend == 0 && divisor != 0)
        {
            return 0;
        }
        bool positive = true;
        if(dividend < 0)
        {
            positive = !positive;
        }
        if(divisor < 0)
        {
            positive = !positive;
        }
        //int maxInt = 0x7fffffff;
        long long  dvd = dividend;
        dvd = dvd< 0? 0-dvd:dvd;
        long long dvs = divisor;
        dvs = dvs < 0? 0-dvs:dvs;
        long long  saveDvs = dvs;
        int r = 0;
        while(dvs <= dvd )//&& (maxInt >> 1) > dvs 
        {
            dvs  = dvs << 1;
        }
        if(dvs > dvd)
        {
            dvs = dvs >> 1;
        }
        int d;
        while(dvs >= saveDvs)
        {
            d = dvd >= dvs ? 1:0;
            if(d == 1)
            {
                dvd -= dvs;
            }
            r = (r<<1) + d;
            dvs  = dvs >> 1;
        }
        return positive?r:0-r;
    }
};