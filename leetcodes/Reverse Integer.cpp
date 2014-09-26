class Solution {
public:
    int reverse(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        bool positive = true;
        int xx = x;
        if(x < 0)
        {
            positive = false;
            xx = 0 - xx;
        }
        int d = 0;
        
        while(xx > 0)
        {
            d = d*10;
            int lastD = xx%10;
            d += lastD;
            xx = xx/10;
        }
        if(positive == true)
        {
            return d;
        }
        else
        {
            return 0-d;
        }
        
    }
};