class Solution {
public:
    double pow(double x, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // n = 0
        // n > 0
        // n < 0
        // x > 0
        // x = 0
        // x < 0
        // |x| = 1 
        if(n == 0 && x != 0 || x == 1)
        {
            return 1;
        }
        if(x == 0)
        {
            return 0;
        }
        if(x < 0)
        {
            if(n%2)
            {
                return 0-pow(0-x,n);
            }
            else
            {
                return pow(0-x,n);
            }
        }
        if(n < 0)
        {
            return 1.0/pow(x,0-n);
        }
        double m;
        if(n % 2)
        {
            m = pow(x,n/2);
            return m*m*x;
        }
        else
        {
            m = pow(x,n/2);
            return m*m;
        }
        
    }
};