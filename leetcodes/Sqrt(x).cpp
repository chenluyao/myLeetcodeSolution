class Solution {
public:
    int sqrt(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(x == 0)
        {
            return 0;
        }
        double last = (double)x;
        
        while(true)
        {
            double temp = 0.5 * (last + (double)(x)/last);
            if(temp - last < 0.00001 && last - temp < 0.00001)
            {
                break;
            }
            last = temp;
        }
        return (int)last;
    }
};