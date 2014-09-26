class Solution {
public:
    bool isPalindrome(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(x < 0)
        {
            return false;
        }
        if(x < 10)
        {
            return true;
        }
        int y =0;
        int z = x;
        int d;
        while(z > 0)
        {
            y = y *10;
            d = z%10;
            y += d;
            z = z/10;
        }
        return (y == x);
    }
};